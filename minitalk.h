#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void client(pid_t pid, char *txt);
int ft_atoi(const char *str);
void ft_putnbr(int n);
void ft_putchar(char c);

#endif