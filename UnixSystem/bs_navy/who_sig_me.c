/*
** EPITECH PROJECT, 2021
** bs_navy
** File description:
** who_sig_me
*/

#define _XOPEN_SOURCE 700
#include "my.h"
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGKILL)
        printf("received SIGKILL\n");
}

void handler(int sig, siginfo_t *si, void *reza_approved)//le void* j'ai pas compris à quoi ça correspondait mais c'était dans le man et ça faisait une erreur sans rien
{
    if (sig == SIGUSR1) //si le numéro du sig (signal) est le même que SIGUSR1 (donc 10)
        my_printf("Signal User defined signal 1 received from %i\n", si->si_pid); //si_pid c'est le numéro dans le terminal bash qu'on a (fais ps dans ton terminal pour mieux comprendre) (ça varie pas comme dans le sujet donc weird mais j'ai pas trouvé autre chose)
    if (sig == SIGUSR2)
        my_printf("Signal User defined signal 2 received from %i\n", si->si_pid);
}

int main(int ac, char **av)
{
    //struct siginfo_t *si; //structure pour les informations du signal qu'on a reçu
    struct sigaction sa; //structure pour catch les signaux (si on a un signal ou pas)

    sa.sa_sigaction = handler; //envoie dans la fonction dédier (ça vient du man elle sert à faire des actions en fonction du signal donné)
    sa.sa_flags = SA_SIGINFO; //récupérer les infos du signal qu'on reçoit
    sigaction(my_getnbr(av[1]), &sa, NULL); //catch les infos du signal donné (par ex: 9 -> KILL)
    sigaction(my_getnbr(av[2]), &sa, NULL);
    if (signal(SIGKILL, sig_handler) == SIG_ERR)
        my_printf("Unable to handle Killed signal\n");

    while (1) {
        sleep(1);
    }
    return (0);
}
