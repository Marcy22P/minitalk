/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:02:19 by mpisani           #+#    #+#             */
/*   Updated: 2025/02/22 20:02:45 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int g_ack = 0;

static void handle_ack(int sig)
{
    (void)sig;
        g_ack = 1;
}

static void set_ack(void)
{
    struct sigaction sa;
    
    sa.sa_handler = handle_ack;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}

static void send_char(pid_t pid, unsigned char c)
{
    int i;
    int total;
    
    i = 0;
    total = 8;
    while (i < total)
    {
        g_ack = 0;
        if ((c & 128) != 0)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        c = c << 1;
        while (!g_ack)
            pause();
        i++;
    }
}

static void send_string(pid_t pid, char *str)
{
    int idx;
    
    idx = 0;
    while (str[idx])
    {
        send_char(pid, (unsigned char)str[idx]);
        idx++;
    }
    send_char(pid, 0);
}

int main(int argc, char **argv)
{
    pid_t pid;
    
    if (argc != 3)
    {
        ft_printf("Format: %s <PID> <STRING>\n", argv[0]);
        return (1);
    }
    pid = (pid_t)ft_atoi(argv[1]);
    set_ack();
    send_string(pid, argv[2]);
    return (0);
}