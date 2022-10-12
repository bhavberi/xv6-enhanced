#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char* argv[])
{
    int priority = atoi(argv[1]);
    int pid = atoi(argv[2]);

    setpriority(priority, pid);

    return 0;
}