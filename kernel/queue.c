// #include "proc.h"
// #include "defs.h"

// void popfront(deque **a)
// {
//     if ((*a)->next->next == 0)
//     {
//         return;
//     }
//     deque *temp = (*a)->next->next->next;
//     free((*a)->next->next);
//     (*a)->next->next = temp;
//     temp->last = (*a)->next;
//     return;
// }
// void popback(deque **a)
// {
//     if ((*a)->last->last == 0)
//     {
//         return;
//     }
//     deque *temp = (*a)->last->last->last;
//     free((*a)->last->last);
//     (*a)->last->last = temp;
//     temp->next = (*a)->last;
//     return;
// }
// void pushfront(deque **a, struct proc *x)
// {
//     if ((*a) == 0)
//     {
//         (*a) = (deque *)malloc(sizeof(deque));
//         (*a)->last = (deque *)malloc(sizeof(deque));
//         (*a)->next = (deque *)malloc(sizeof(deque));
//         (*a)->next->next = (deque *)malloc(sizeof(deque));
//         (*a)->last->last = (*a)->next->next;
//         (*a)->next->next->n = x;
//         (*a)->next->next->next = (*a)->last;
//         (*a)->next->next->last = (*a)->next;
//         return;
//     }
//     deque *temp = (deque *)malloc(sizeof(deque));
//     temp->n = x;
//     temp->next = (*a)->next->next;
//     temp->last = (*a)->next;
//     (*a)->next->next->last = temp;
//     (*a)->next->next = temp;
//     return;
// }
// void pushback(deque **a, struct proc *x)
// {
//     if ((*a) == 0)
//     {
//         (*a) = (deque *)malloc(sizeof(deque));
//         (*a)->last = (deque *)malloc(sizeof(deque));
//         (*a)->next = (deque *)malloc(sizeof(deque));
//         (*a)->next->next = (deque *)malloc(sizeof(deque));
//         (*a)->last->last = (*a)->next->next;
//         (*a)->next->next->n = x;
//         (*a)->next->next->next = (*a)->last;
//         (*a)->next->next->last = (*a)->next;
//         return;
//     }
//     deque *temp = (deque *)malloc(sizeof(deque));
//     temp->n = x;
//     temp->last = (*a)->last->last;
//     temp->next = (*a)->last;
//     (*a)->last->last->next = temp;
//     (*a)->last->last = temp;
//     return;
// }
// struct proc *front(deque *a)
// {
//     return a->next->next->n;
// }
// struct proc *back(deque *a)
// {
//     return a->last->last->n;
// }
// int isempty(deque *a)
// {
//     if (a == 0 || a->next->next == a->last)
//     {
//         return 1;
//     }
//     return 0;
// }
// int size(deque *a)
// {
//     if (a == 0 || a->next->next == a->last)
//     {
//         return 0;
//     }
//     deque *temp = a->next;
//     int count = 0;
//     while (temp->next != a->last)
//     {
//         temp = temp->next;
//         count++;
//     }
//     return count;
// }