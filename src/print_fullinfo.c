#include "ft_ls.h"

//*Начало того что мы будем класть в другие файлы

static size_t	count_len(const t_filename *beg)
{
	size_t	len_string;

	len_string = 0;
	//10 + space
}

static size_t	def_full_l_len(const t_filename *beg)
{
	size_t	len_str;
	size_t	full_len;

	full_len = 0;
	while (beg)
	{
		len_str = count_len(beg)
		full_len += len_str;
		beg = beg->next;
	}
}

//*До этого мы положим все ф-ии в другие файлы

static size_t	def_full_len(const t_filename *beg, const t_ubyte *flags)
{
	size_t		full_len;

	full_len = 0;
	if (flags[FIND_FLAG('l')])
	{
		full_len = def_full_l_len(beg);
	}
	else if (flags[FIND_FLAG('g')])
	{
		full_len = def_full_g_len(beg);
	}
	return (full_len);
}

static void		push_fullinfo(const t_filename *beg, const t_ubyte *flags)
{
//пушим все дело
}

void	print_fullinfo(const t_filename *beg, const t_ubyte *flags)
{
	char *buf;
	size_t	full_len;
	int zero;

	zero = 0;
	full_len = def_full_len(beg, flags);
	buf = (char *)ft_memalloc(sizeof(char) * full_len + zero)//будет содержать 0 или нет?
	push_fullinfo(buf, flags);
	printf("%s", buf);// \n подумать ставить или нет
	//Проверить флаги
}
