/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:02:22 by mpisani           #+#    #+#             */
/*   Updated: 2025/02/22 20:05:23 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void handle_signal(int sig, siginfo_t *info, void *ctx)
{
    static int           bits = 0;
    static unsigned char c = 0;
    
    (void)ctx;
    if (sig == SIGUSR2)
    {
        c = (c << 1) | 1;
    }
    else
    {
        c = c << 1;
    }
    bits++;
    if (bits == 8)
    {
        if (c == 0)
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        bits = 0;
        c = 0;
    }
    kill(info->si_pid, SIGUSR1);

}

static void set_signals(void)
{
    struct sigaction sa;
    
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}

static void print_pid(void)
{
    pid_t pid;
    
    pid = getpid();
    ft_printf("Server PID: %d\n", pid);
}

int main(void)
{
    print_pid();
    set_signals();
    while (1)
        pause();
    return (0);
}