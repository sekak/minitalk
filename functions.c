#include "minitalk.h"

void p_putchar(char c)
{
	write(1,&c,1);
}

void		my_putnbr(int nb)
{
	if(nb >= 10)
	{
		my_putnbr(nb / 10);
		my_putnbr(nb % 10);
	}
	else 
	{
		p_putchar(nb + '0');
	}
}