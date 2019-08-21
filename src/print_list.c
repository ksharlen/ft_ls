#include "ft_ls.h"

static size_t	def_len_all_filename(t_filename *beg)
{
	size_t	all_len;
	t_ubyte two_spaces;

	all_len = 0;
	two_spaces = 2; //Будет динамическое выравнивание
	while (beg)
	{
		all_len += ft_strlen(beg->filename);
		all_len += two_spaces;
		beg = beg->next;
	}
	return (all_len);
}

static void		push_filename_to_buf(t_filename *beg, t_ubyte *buf)
{
	while (beg)
	{
		ft_strcat((char *)buf, (char *)beg->filename);
		ft_strcat((char *)buf, "  ");
		beg = beg->next;
	}
}

static t_ubyte	*generate_buf_for_print(t_filename *beg)
{
	size_t		size_buf;
	t_ubyte		*buf;

	size_buf = def_len_all_filename(beg);
	buf = (t_ubyte *)ft_memalloc(sizeof(t_ubyte) * size_buf + 1); //1 - '\0'
	buf[size_buf] = '\0';
	push_filename_to_buf(beg, buf);
	return (buf);
}

static void simple_print_lists(t_filename *beg)
{
	t_ubyte		*buf;

	//Простой вывод
	buf = generate_buf_for_print(beg);
	printf("%s\n", buf);
	//!free(buf);
}

void	print_list(t_filename *beg, t_ubyte *flags)
{
	if (chk_flags_for_print_fullinfo(flags) == TRUE)
	{
		print_fullinfo(beg, flags);
		//print_fullinfo(beg, flags);
		//Нужно обработать флаги для полного вывода
	}
	else
	{
		//Вывод простого списка
		simple_print_lists(beg);
	}
}
