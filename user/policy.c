#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void set_dynamic_policy(int policy)
{
    if (set_policy(policy) == 0)
        printf("policy set successfully to %d", policy);
    else
        printf("policy set unsuccessful");
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int policy = atoi(argv[1]);
        set_dynamic_policy(policy);
        exit(0, "");
    }
    exit(0, "No policy specified");
}