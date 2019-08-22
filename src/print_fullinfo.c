#include "ft_ls.h"

void	print_fullinfo(const t_filename *beg, const t_ubyte *flags)
{
	struct s_print	print_info;
	struct s_num	align;

	P_UNUSED(print_info);
	P_UNUSED(align);
	P_UNUSED(flags);
	//тут будет определение выравнивания
	//max_len_elem(beg, &align);
	while (beg)
	{
		printf("pw_name: %s\ngr_name: %s\n", beg->pw_name, beg->gr_name);
		//fill_print_info(beg, flags);
		//printf("")
		beg = beg->next;
	}
}
