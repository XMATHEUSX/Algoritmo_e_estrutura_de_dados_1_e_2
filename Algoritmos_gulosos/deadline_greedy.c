#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int id;
    int time_exe;
    int deadline;
} task;

task *allocate_vector_struct(int n)
{
    task *temp;
    temp = (task *)calloc(n, sizeof(task));
    return temp;
}

task *sort_tasks(task *tv, int n)
{
    int *lower;
    lower = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        lower[i] = (tv[i].time_exe - tv[i].deadline);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            task aux;
            if (lower[j - 1] > lower[j])
            {
                aux = tv[j];
                tv[j] = tv[j - 1];
                tv[j - 1] = aux;
            }
        }
        for (int i = 0; i < n; i++)
        {
            lower[i] = (tv[i].time_exe - tv[i].deadline);
        }
    }
    free(lower);
    return tv;
}

int best_seq(task *t, int n)
{
    int delay = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", t[i].id);
        delay += (t[i].time_exe - t[i].deadline);
    }
    if (delay < 0)
    {
        delay = 0;
    }
    return delay;
}

int main(int argc, char const *argv[])
{
    int n;
    task *t;
    scanf("%d", &n);
    t = allocate_vector_struct(n);
    for (int i = 0; i < n; i++)
    {
        t[i].id = i;
        scanf("%d", &t[i].time_exe);
        scanf("%d", &t[i].deadline);
    }
    t = sort_tasks(t, n);
    printf("\n%d", best_seq(t,
                            n));
    free(t);
    return 0;
}