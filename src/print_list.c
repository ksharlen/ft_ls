#include "ft_ls.h"

#if __linux__
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
	ft_printf("%s\n", buf);
	//!free(buf);
}

#endif

#if __APPLE__

static const char *insert_color_filename(const char *filename, const char *color)
{
	char *color_filename;
	char *free_string;

	color_filename = ft_strjoin(color, filename);
	CHECK_ALLOC(color_filename);
	free_string = color_filename;
	color_filename = ft_strjoin(color_filename, DEFAULT_STYLE);
	CHECK_ALLOC(color_filename);
	ft_strdel(&free_string);
	return (color_filename);
}

static t_len	large_filename(t_filename *beg)
{
	t_len	len_filename;
	t_len	large_filename;

	len_filename = 0;
	large_filename = 0;
	while (beg)
	{
		if ((len_filename = ft_strlen(beg->filename)) > large_filename)
			large_filename = len_filename;
		beg = beg->next;
	}
	return (large_filename);
}

// static size_t	def_buf_size(t_filename *beg, const t_len *const lmf)
// {
// 	size_t	size_buf;
// 	t_ubyte space;

// 	size_buf = 0;
// 	space = 1;
// 	while (beg)
// 	{
// 		size_buf += *lmf + space;
// 		beg = beg->next;
// 	}
// 	return (size_buf);
// }

// static const char *push_filenames(t_filename *beg, size_t size_buf, const t_len *const lmf)
// {
// 	char *buf;

// 	buf = (char *)ft_strnew(sizeof(char) * size_buf);
// 	if (!buf)
// 		sys_errors();
// 	while (beg)
// 	{
// 		//ft_strcat(buf, color);
// 		ft_strcat(buf, beg->filename);
// 		//ft_strcat(buf, color_default);
// 		if (beg->next)
// 			ft_setncat(buf, ' ', *lmf - ft_strlen(beg->filename) + 1);
// 		else
// 			ft_strcat(buf, "\n");
// 		beg = beg->next;
// 	}
// 	return (buf);
// }

static void 	simple_print_lists(t_filename *beg, const char *ls_color)
{
	int			len_max_filename;
	const char	*color;
	const char	*color_filename;

	len_max_filename = large_filename(beg) + (11 * 2);//?Магическое число
	while (beg)
	{
		color = push_color(beg->buf->st_mode, ls_color);
		color_filename = insert_color_filename(beg->filename, color);
		ft_strdel((char **)color);
		//color_filename = ft_strjoin(color, beg->filename);
		//color_filename = ft_strjoin(color_filename, DEFAULT_STYLE);
		ft_printf("%-*s ", len_max_filename, color_filename);
		//ft_printf("\033[1;31m");
		//ft_printf("%-*s ", len_max_filename, beg->filename);
		//ft_printf("%s%-*s ", color, len_max_filename, beg->filename);
		//ft_printf("%s", DEFAULT_STYLE);
		//ft_strdel((char **)&color);
		beg = beg->next;
	}
	ft_printf("%v%s", 1, "\n");
	//ft_printf("%v\n", 1);
	//ft_printf("%s", DEFAULT_STYLE);
	//ft_printf("%s", "\n");
}

#endif

void			print_list(t_filename *beg, t_ubyte *flags)
{
	const char *ls_color;

	ls_color = getenv("LSCOLORS");
	if (chk_flags_for_print_fullinfo(flags) == TRUE)
	{
		print_fullinfo(beg, flags, ls_color);
		//print_fullinfo(beg, flags);
		//Нужно обработать флаги для полного вывода
	}
	else
	{
		//Вывод простого списка
		simple_print_lists(beg, ls_color);
	}
}
