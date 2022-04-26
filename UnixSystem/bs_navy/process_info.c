/*
** EPITECH PROJECT, 2021
** bs_navy
** File description:
** Process info
*/

#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t pid = getpid();
    pid_t ppid = getppid();
    pid_t pgid = __getpgid(pid);

    printf("PID: %d\nPPID: %d\nPGID: %d\n", pid, ppid, pgid);
    return (0);
}
