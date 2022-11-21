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

int char_to_int(char *s)
{
	int i = 0;
	int res = 0;
	if(s[0] =='-')
	{
		i++;
	}
	if(s[0] =='+')
	{
		i++;
	}
	while(s[i])
	{
		res = (res * 10) + s[i] - '0';
		i++;
	}
	return(res);
}

char *int_to_char(int c)
{
    char *str;
    char rev[13];
    int j=0;
    str = malloc(sizeof(char)*(sizeof(c)));
    int i=0;
    
    while(c > 0)
    {
        rev[i] = (c % 10) + 48;
        c /= 10;
        i++;
    }
    // i--;
    while(i-- > 0)
    {
        str[j++] = rev[i];
    }
    
    return(str);
}

 char *ft_atoi_base(int c)
{
	char str[9];
	static char rev[9];
	char *base = "01";

	memset(str, 0, 9);
	memset(rev, 0, 9);
	int i;
	i = 0;
	int j = 0;
	while (i < 8)
	{
		str[i] = base[c % 2];
		c /= 2;
		i++;
	}
	i--;
	while (j < 8)
	{
		rev[j] = str[i];
		j++;
		i--;
	}
	return (rev);
}
void take_string(char *s, int pid)
{
	int i;
	char *str;
	i = 0;
	int j = 0;
	while (s[i])
	{
		str = ft_atoi_base(s[i]);
		printf("%s\n",str);
		i++;
		j=0;
		while (str[j])
		{
			if (str[j] == '0')
				kill(pid, SIGUSR1);
			else if (str[j] == '1')
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
	}
	j = 0; 
	while(j < 8)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		j++;
	}
}


void push_pid(char *PID, int pid)
{	
	// ft_atoi_base(PID);
	int i=0;
	char *str;
	int j;
	 while(PID[i] > 0)
	 {
		str = ft_atoi_base(PID[i]);
		printf("str : %s\n",str);
		j=0;
		while (str[j])
		{
			printf("str :");
			if (str[j] == '0')
				kill(pid, SIGUSR1);
			else if (str[j] == '1')
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
		i++;
	 }
	 
}

int main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	int pid;
	pid = char_to_int(av[1]);
	take_string(av[2], pid);
	int PID = getpid();
	push_pid(int_to_char(PID),pid);
	printf("%d",PID);
	return (0);
}