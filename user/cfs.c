#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void cfs_scheduler_test(void)
{
    printf("starting cfs scheduler test (this may take a while...)\n");
    for (int i = 0; i < 9; i++)
    {
        sleep(5);
        int pid = fork();
        if (pid == 0)
        {
            if (i < 3)
                set_cfs_priority(2);
            else if (i >= 3 && i < 6)
                set_cfs_priority(1);
            else
                set_cfs_priority(0);

            for (int i = 0; i < 1000000; i++)
            {
                if (i % 100000 == 0)
                    sleep(10);
                for (int j = 0; j < 10000; j++) // elongate each child's runtime
                {
                }
            }
            int pid = getpid();
            int stats[4];
            get_cfs_stats(pid, stats);
            sleep(20);
            printf("PID: %d\t\tCFS_PRIORITY: %d\t\tRTIME: %d\tSTIME: %d\tRETIME: %d\n", pid, stats[0], stats[1], stats[2], stats[3]);
            exit(0, "");
        }
    }
    for (int i = 0; i < 9; i++) // wait for all children
        wait(0, "");
}

int main(void)
{
    cfs_scheduler_test();
    exit(0, "");
}