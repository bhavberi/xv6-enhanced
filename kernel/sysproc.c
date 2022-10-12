#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0; // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_waitx(void)
{
  uint64 addr, addr1, addr2;
  uint wtime, rtime;
  argaddr(0, &addr);
  argaddr(1, &addr1); // user virtual memory
  argaddr(2, &addr2);
  int ret = waitx(addr, &wtime, &rtime);
  struct proc *p = myproc();
  if (copyout(p->pagetable, addr1, (char *)&wtime, sizeof(int)) < 0)
    return -1;
  if (copyout(p->pagetable, addr2, (char *)&rtime, sizeof(int)) < 0)
    return -1;
  return ret;
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if (growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while (ticks - ticks0 < n)
  {
    if (killed(myproc()))
    {
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// system trace
uint64 sys_trace(void)
{
  int tmask;
  argint(0, &tmask);
  myproc()->tmask = tmask;
  return 0;
}

// system setticket
int sys_settickets(void)
{
  int number;
  argint(0, &number);
  acquire(&(myproc())->lock);
  myproc()->tickets = number;
  release(&(myproc())->lock);
  return 0;
}

// sigalarm
uint64 sys_sigalarm(void)
{
  int interval;
  uint64 fn;
  argint(0, &interval);
  argaddr(1, &fn);

  struct proc *p = myproc();

  p->sigalarm_status = 0;
  p->interval = interval;
  p->now_ticks = 0;
  p->handler = fn;

  return 0;
}

uint64 sys_sigreturn(void)
{
  struct proc *p = myproc();

  // Restore Kernel Values
  memmove(p->trapframe, p->alarm_trapframe, PGSIZE);
  kfree(p->alarm_trapframe);

  p->sigalarm_status = 0;
  p->alarm_trapframe = 0;
  p->now_ticks = 0;
  usertrapret();
  return 0;
}

uint64 sys_setpriority(void)
{
  int number, piid;
  argint(0, &number);
  argint(1, &piid);
  setpriority(number, piid);
  return 0;
}