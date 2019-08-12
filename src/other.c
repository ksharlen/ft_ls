#include "ft_ls.h"

void	valid_flags(const t_ubyte *flags)
{
	register size_t	i;

	i = 1;
	while (i < NUM_FLAGS)
	{
		if (flags[i])
		{
			if (!ft_strchr(FLAGS, i + (i >= 27 ? 38 : 'a' - 1)))//тут надо понять что к чему
			{	//Ошибка валидности флага
				//printf("Ошибочный флаг\n");
				//printf("\ni: %d\nsym: %ld\n", i, i + (i >= 27 ? 38 : 'a' - 1));
			}
		}
		++i;
	}
}

int		get_options(const char *options, t_ubyte *flags)
{
	if (*(options + 1))
	{
		flags[0] = FLAG_ON;
		++options;
		while (*options)
		{
			if (FLAG_VALID(*options))
				flags[(FLAG_LOW_REG(*options) ? (*options - 'a') + 1 : (*options - 38))] = FLAG_ON;
			else
				;
			//Ошибка валидности выход из ls
			//valid_flags(flags);
			++options;
		}
	}
	else
	{
		//тут будет ошибка вроде: невозможно получить доступ к '-'
	}
	return (0);
}
