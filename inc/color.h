#ifndef COLOR_H
# define COLOR_H

/*
** 	RED //червоний
**	GREEN //зелений
**	YELLOW //жовтий
**	BLUE //синій
**	MAGENTA //пурпурний
**	CYAN //блакитний
**	WHITE //білий
**	BRIGHT //яскравий
**	DIM //тьмяний
*/

#define RESET	"\x1B[0m"

#define RED	"\x1B[31m"
#define GRN	"\x1B[32m" 
#define YLW	"\x1B[33m"
#define BLU	"\x1B[34m"
#define MAG	"\x1B[35m"
#define CYA	"\x1B[36m"
#define WHT	"\x1B[37m"

#define BR_RED	"\x1B[91m"
#define BR_GRN	"\x1B[92m"
#define BR_YLW	"\x1B[93m"
#define BR_BLU	"\x1B[94m"
#define BR_MAG	"\x1B[95m"
#define BR_CYA	"\x1B[96m"
#define BR_WHT	"\x1B[97m"

#define DIM_RED	"\x1B[2;31m"
#define DIM_GRN	"\x1B[2;32m"
#define DIM_YLW	"\x1B[2;33m"
#define DIM_BLU	"\x1B[2;34m"
#define DIM_MAG	"\x1B[2;35m"
#define DIM_CYA	"\x1B[2;36m"
#define DIM_WHT	"\x1B[2;37m"

#endif
