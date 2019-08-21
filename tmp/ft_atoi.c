#include <stdio.h>

static int	ftt_isdigit(char sym)
{
	return ((sym > 47 && sym < 58) ? 1 : 0);
}

static const char *ft_whitespace(const char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

int		ftt_atoi(const char *str)
{
	int 	num;
	short	sign;

	sign = 1;
	str = ft_whitespace(str);
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-' ? -1 : 1);
		str++;
	}
	if (ftt_isdigit(*str))
	{
		num = 0;
		while (ftt_isdigit(*str) && *str)
		{
			num = (num * 10) + (*str - '0');
			str++;
		}
		num *= sign;
	}
	else
		num = 0;
	return (num);
}

int     main(void)
{
    int ret_atoi;

    ret_atoi = ftt_atoi("-21474836482");
    printf("%d", ret_atoi);
}