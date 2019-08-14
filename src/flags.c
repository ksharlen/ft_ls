#include "ft_ls.h"

static void	flag_error(t_ubyte sym)
{
	ft_printf("%vls: illegal option -- %c\n%s", 2, sym, EFLAGS);
	exit(EXIT_SUCCESS);
	//Подумать над выводом флагов которые действительно есть
}

void	valid_flags(const t_ubyte *flags)
{
	register size_t	i;
	t_ubyte sym;

	i = 1;
	while (i < NUM_FLAGS)
	{
		if (flags[i])
			if (!ft_strchr(FLAGS, sym = (i + (i >= 27 ? 38 : 'a' - 1))))
				flag_error(sym);
		++i;
	}
}

int		get_options(const char *options, t_ubyte *flags)
{
	++options;
	while (*options)
	{
		if (FLAG_VALID(*options))
			flags[(FLAG_LOW_REG(*options) ? (*options - 'a') + 1 : (*options - 38))] = FLAG_ON;
		else
			flag_error(*(t_ubyte *)options);
		++options;
	}
	return (SUCCESSFUL_COMPLETION);
}
