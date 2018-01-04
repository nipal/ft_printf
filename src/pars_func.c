

#include "ft_printf.c"


/*
(char **prev_hard, char *now, t_fparam *p)

	e_flag_plus		= 1l << 8,
	e_flag_minus	= 1l << 9,
	e_flag_space	= 1l << 10,
	e_flag_zero		= 1l << 11,
	e_flag_lang_nb	= 1l << 12,
	e_flag_sparate	= 1l << 13,
	e_flag_hash		= 1l <<	14,
*/

char	*flag_add_plus(char **prev_hard, char *now, t_fparam *p)
{
	(void)prev_hard; (void)now; (void)p;
	return (now + 1);
}


char	*flag_add_minus(char **prev_hard, char *now, t_fparam *p)
{
	(void)prev_hard; (void)now; (void)p;
	return (now + 1);
}

char	*flag_add_space(char **prev_hard, char *now, t_fparam *p)
{
	(void)prev_hard; (void)now; (void)p;
	return (now + 1);
}

char	*flag_add_zero(char **prev_hard, char *now, t_fparam *p)
{
	(void)prev_hard; (void)now; (void)p;
	return (now + 1);
}

char	*flag_add_lang_nb(char **prev_hard, char *now, t_fparam *p)
{
	(void)prev_hard; (void)now; (void)p;
	return (now + 1);
}

char	*flag_add_separate(char **prev_hard, char *now, t_fparam *p)
{
	(void)prev_hard; (void)now; (void)p;
	return (now + 1);
}

char	*flag_add_hash(char **prev_hard, char *now, t_fparam *p)
{
	(void)prev_hard; (void)now; (void)p;
	return (now + 1);
}


