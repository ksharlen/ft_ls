#include "ft_ls.h"

static size_t	def_len_all_filename(t_filename *beg)
{
	size_t	all_len;
	t_ubyte two_spaces;

	all_len = 0;
	two_spaces = 2;
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
	t_ubyte		*buf;
	size_t		size_buf;

	P_UNUSED(buf);
	size_buf = def_len_all_filename(beg);
	buf = (t_ubyte *)ft_memalloc(sizeof(t_ubyte) * size_buf + 1); //1 - '\0'
	buf[size_buf] = '\0';
	push_filename_to_buf(beg, buf);
	//printf("size_buf: %ld\n", size_buf);
	//exit(EXIT_SUCCESS);
	return (buf);
}

static void simple_print_lists(t_filename *beg, t_ubyte *flags)
{
	t_ubyte		*buf;

	P_UNUSED(buf);
	if (flags[FIND_FLAG('a')] || flags[FIND_FLAG('f')])
	{
		//Вывод невидимых файлов
		buf = generate_buf_for_print(beg);
		//printf("buf:\n");
		printf("%s\n", buf);
		exit(EXIT_SUCCESS);
	}
	else
	{
		//Вывод только видемых файлов
	}
}

void	print_list(t_filename *beg, t_ubyte *flags)
{
	if (chk_flags_for_print_fullinfo(flags) == TRUE)
	{
	//printf("1\n");
		//Нужно обработать флаги для полного вывода
		
	}
	else
	{
		//Вывод простого списка
		//Нужно создать буфер
		//И вывести его
		simple_print_lists(beg, flags);
	}
}
