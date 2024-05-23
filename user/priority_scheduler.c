#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void priority_scheduler(void)
{
    printf("starting priority scheduler test (this may take a while...)\n");
    for (int i = 0; i < 4; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            set_ps_priority((i + 1) * 2);     // priorities - 2, 4, 6, 8
            for (int i = 0; i < 1000000; i++) // elongate child's runtime
            {
                if (i % 100000 == 0)
                    sleep(10);
                for (int j = 0; j < 10000; j++)
                {
                }
            }
            sleep(20);
            printf("%d", i + 1);
            exit(0, "");
        }
    }
    for (int i = 0; i < 4; i++) // wait for all children
    {
        wait(0, "");
    }
}

int main(void)
{
    priority_scheduler();
    exit(0, "");
}