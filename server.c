#include "minitalk.h"

void p_putchar(char c)
{
	write(1, &c, 1);
}

void my_putnbr(int nb)
{
	if (nb >= 10)
	{
		my_putnbr(nb / 10);
		my_putnbr(nb % 10);
	}
	else
	{
		p_putchar(nb + '0');
	}
}

int poweroftwo(int pow, int num)
{
	int s;
	s = (7 - pow);
	if (s == 0)
	{
		return (1);
	}
	int n;
	n = 2;
	while (--s > 0)
	{
		n = num * n;
	}
	return (n);
}

int ft_itoa_base(char *s)
{
	int i = 0;
	int n = 0;

	while (i < 8)
	{
		n += ((s[i] - 48) * poweroftwo(i, 2));
		i++;
	}
	return(n);
}

int  doz(int i)
{
	static int counter = 0;
	static char num[9];
	static char pid[9];
	static int t = 0;

	if (i == SIGUSR1)
	{
		num[counter] = '0';
	}
	else if (i == SIGUSR2)
	{
		num[counter] = '1';
	}
	counter++;
	if (counter == 8)
	{
		ft_itoa_base(num);
		t++;
		counter = 0;
	}
}

void handle(int i)
{
	static int counter = 0;
	static char num[9];

	if (i == SIGUSR1)
	{
		num[counter] = '0';
	}
	else if (i == SIGUSR2)
	{
		num[counter] = '1';
	}
	counter++;

	if (counter == 8)
	{
		p_putchar(ft_itoa_base(num));
		if( ft_itoa_base(num) == '\0')
		{
			 doz(i);
		}
		counter = 0;
	}
	
}


int main(int ac, char **av)
{
	pid_t pid;
	pid = getpid();
	my_putnbr(pid);
	p_putchar('\n');
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);

	while (1)
		pause();

	(void)av;
	(void)ac;
	return (0);
}
