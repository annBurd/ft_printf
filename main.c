#include "./inc/ft_printf.h"
#include "../testing/color.h"
#include <sys/types.h>
#include <limits.h>
#include <locale.h>

#define MAX_OF(type) \
    (((type)(~0LLU) > (type)((1LLU<<((sizeof(type)<<3)-1))-1LLU)) ?	\
    (long long unsigned int)(type)(~0LLU) :	\
    (long long unsigned int)(type)((1LLU<<((sizeof(type)<<3)-1))-1LLU))
#define MIN_OF(type) \
    (((type)(1LLU<<((sizeof(type)<<3)-1)) < (type)1) ? \
    (long long int)((~0LLU)-((1LLU<<((sizeof(type)<<3)-1))-1LLU)) : 0LL)

//	*format -- "Some simple text with %d & %s. It's one big string"
//	%[flags][width][.precision][length]specifier
//	int i = va_arg(aq, int);

// prefixes are ignored with unsigned
// flag '#' is ignored when u, U
// flag '#' %o[0...], %x[0x...], %X[0X...]

// flag ' ' is ignored when flag '+' is present
// flag '0' is ignored when flag '-' is present
// flag '#' results in undefined behavior with 'd' conversion specifier
// precision used with 'S' conversion specifier, resulting in undefined behavior

// sS
// PREC - максимальное число символов, которые будут выведены для типа s;
// WIDTH - минимальная ширина поля
// wchar_t* - prec - ignored
//	except - prec = 0

// cC
// prec - ignored

// якщо немає відповідної вставки до маркера,
// 	вивід вібдудеться ДО нього

// якщо хоч один специфікатор не відповідає типу аргумента,
// 	вивід НЕ вібдудеться
// 						exit() ?

// Если поле Buffer аргумента, который соответствует %Z,
// или аргумент, который соответствует %s или %S,
// 		является указателем NULL,
// 			отображается значение "(null)"

// D = ld //signed decimal
// O = io //unsigned octal
// U = lu //unsigned decimal
// These conversion characters are deprecated, and will eventually disappear.
// sS dD pi oO uU xX cC %(in flags) //eE fF aA gG nb k...

//	Запятой (,) разделяются классы (у нас — полупробелы),
//		а десятичная часть — точкой.
// **************************************************************************

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	setlocale(LC_CTYPE, "");
//	setlocale(LC_ALL, "en_US.UTF-8");


//	HERE WE HAVE SOME TESTS
//	****************************************************
//	PERCENT: %
//	ft_printf("\n> PERCENT: %%\n");
//	ft_printf("[%%]\n");
//	ft_printf("[%.%]\n");
//	ft_printf("[%.4%]\n");
//	ft_printf("[%4%]\n");
//	ft_printf("[%4.2%]\n");
//	ft_printf("[%04.2%]\n");

////	CHAR: %c, %s
//	char c = '$';
//	char *s = "Do some trash test for my lovely ft_printf()";
//	ft_printf("\n> CHAR %%c, %%s\n");
//	printf("%%c = %c ____[%-*.*s] 0R!G\n", c, 30, 13, s);
//	ft_printf("%%c = %c ____[%-*.*s]\n", c, 30, 13, s);

//	UNSIGNED: # with %oO, %xX
//	unsigned int ui = 1234567;
//	ft_printf("\n> HASH #\n");
//	printf("[%#o]\t[%#x]\t[%#X] 0R!G\n", ui, ui, ui);
//	ft_printf("[%#o]\t[%#x]\t[%#X]\n", ui, ui, ui);
//
////	BONUS BINARY: %b
//	int i = 56;
//	ft_printf("\n> BINARY: %%b\n");
//	ft_printf("[%b]\n", i);
//
////	 BONUS APOST (`) with %i, %d, %D
////	 BONUS STAR (*)
//	int i = -1234567;
//	int w = 20;
//	int p = 11;
//	ft_printf("\n> APOST && STAR\n");
//	ft_printf("\t\t[%`d]\n", i);
//	ft_printf(" 2\t\t[%` 2d]\n", i);
//	ft_printf("-%d.%d\t[%`-*.*d]\n", w, p, w, p, i);
//	ft_printf("%d\t\t[%`*d]\n", w, w, i);
//	ft_printf("%d.%d\t[%`*.*d]\n", w, p, w, p, i);
//	ft_printf("+%d.%d\t[%`+*.*d]\n", w, p, w, p, i);
//	ft_printf(".%d\t\t[%`.*d]\n", w, w, i);
//	ft_printf("0%d\t\t[%`0*d]\n", w, w, i);
//
////	unsigned  ui = 12345;
//	ft_printf("\n> APOST && STAR && uU\n");
//	printf("-10\t\t[%-10u]ui 0R!G\n", ui);
//	ft_printf("`-10\t[%`-10lu]ui\n", ui);
//	printf("010\t\t[%010u]ui 0R!G\n", ui);
//	ft_printf("`010\t[%`010lu]ui\n", ui);
//	printf("7.9\t\t[%7.9u]ui 0R!G\n", ui);
//	ft_printf("`7.9\t[%`7.9lu]ui\n", ui);
//	ft_printf("`7.9\t[%`7.9x]ui - x\n", ui);
//	****************************************************


//	POINTER: %p
//	****************************************************
//	short p = 6667;
//	printf("\t\t[%p] 0R!G\n", &p);
//	ft_printf("\t\t[%p]\n", &p);
//	printf(".\t\t[%.p] 0R!G\n", &p);
//	ft_printf(".\t\t[%.p]\n", &p);
//	ft_printf(".20\t\t[%.20p]\n", &p);
//	printf("20\t\t[%20p] 0R!G\n", &p);
//	ft_printf("20\t\t[%20p]\n", &p);
//	printf("-20\t\t[%-20p] 0R!G\n", &p);
//	ft_printf("-20\t\t[%-20p]\n", &p);


//	char z1 = (char)208, z2 = (char)135;
//	write(1, &z1, 1);
//	write(1, &z2, 1);
//	write(1, "\n", 1);
//	printf("%c%c\n", z1, z2);


//	WCHAR_T
//	****************************************************
//	wchar_t wc = L'Ї';
//	wchar_t wc = L'ꚩ';
//	wchar_t wc = L'ᚫ';
//		ft_printf("> WCHAR_T\n");
//	printf("\t\t[%C]%u\n", wc, wc);
//	ft_printf("\t\t[%C]\n", wc, wc);
//	printf("1\t\t[%1C]\n", wc);
//	ft_printf("1\t\t[%1C]\n", wc);
//	printf("2\t\t[%2C]\n", wc);
//	ft_printf("2\t\t[%2C]\n", wc);
//	printf("3\t\t[%3C]\n", wc);
//	ft_printf("3\t\t[%3C]\n", wc);
//	printf("4\t\t[%4C]\n", wc);
//	ft_printf("4\t\t[%4C]\n", wc);
//	printf("7\t\t[%7C]\n", wc);
//	ft_printf("7\t\t[%7C]\n", wc);
//	printf(".\t\t[%.C]\n", wc);
//	ft_printf(".\t\t[%.C]\n", wc);
//	printf("-7\t\t[%-7C]\n", wc);
//	ft_printf("-7\t\t[%-7C]\n", wc);


//int size = 0;
//	size = printf("\t\t[%C]%u\n", 199, 199);
//	ft_putnbr(size);
//	size = ft_printf("\t\t[%C]%u\n", 199, 199);
//	ft_putnbr(size);
//	size = printf("\t\t[%C]%u\n", 3333, 3333);
//	ft_putnbr(size);
//	size = ft_printf("\t\t[%C]%u\n", 3333, 3333);
//	ft_putnbr(size);
//	size = printf("\t\t[%C]%u\n", 33338, 33338);
//	ft_putnbr(size);
//	size = ft_printf("\t\t[%C]%u\n", 33338, 33338);
//	ft_putnbr(size);
//	size = printf("\t\t[%C]%u\n", L'ꚩ', L'ꚩ');
//	ft_putnbr(size);
//	size = ft_printf("\t\t[%C]%u\n", L'ꚩ', L'ꚩ');
//	ft_putnbr(size);
//	size = printf("\t\t[%C]%u\n", L'ᚫ', L'ᚫ');
//	ft_putnbr(size);
//	size = ft_printf("\t\t[%C]%u\n", L'ᚫ', L'ᚫ');
//	ft_putnbr(size);
//	size = printf("\t\t[%C]%u\n", 5004, 5004);
//	ft_putnbr(size);
//	size = ft_printf("\t\t[%C]%u\n", 5004, 5004);
//	ft_putnbr(size);
//	size = printf("\t\t[%C]%u\n", 5604, 5604);
//	ft_putnbr(size);
//	size = ft_printf("\t\t[%C]%u\n", 5604, 5604);
//	ft_putnbr(size);
//	size = printf("\t\t[%C]%u\n", L'Ẅ', L'Ẅ');
//	ft_putnbr(size);
//	size = ft_printf("\t\t[%C]%u\n", L'Ẅ', L'Ẅ');
//	ft_putnbr(size);




	//	WCHAR_T *
//	****************************************************
//	wchar_t *ww = L"ΛᚫᨖẄꚩ";
//		ft_printf("> WCHAR_T *\n");
//	printf("\t\t[%S]\n", ww);
//	ft_printf("\t\t[%S]\n", ww);
//	printf("20\t\t[%20S]\n", ww);
//	ft_printf("20\t\t[%20S]\n", ww);
////	printf(".\t\t[%.S]\n", ww);
////	ft_printf(".\t\t[%.S]\n", ww);
//	printf("-20\t\t[%-20S]\n", ww);
//	ft_printf("-20\t\t[%-20S]\n", ww);
////	printf("-20.\t[%-20.S]\n", ww);
////	ft_printf("-20.\t[%-20.S]\n", ww);


//	CHAR
//	****************************************************
//	char c = '$';
//		ft_printf("> CHAR\n");
//	printf("\t\t[%c]\n", c);
//	ft_printf("\t\t[%c]\n", c);
//	printf("1\t\t[%1c]\n", c);
//	ft_printf("1\t\t[%1c]\n", c);
//	printf("2\t\t[%2c]\n", c);
//	ft_printf("2\t\t[%2c]\n", c);
//	printf("7\t\t[%7c]\n", c);
//	ft_printf("7\t\t[%7c]\n", c);
//	printf(".\t\t[%.c]\n", c);
//	ft_printf(".\t\t[%.c]\n", c);
//	printf("-7\t\t[%-7c]\n", c);
//	ft_printf("-7\t\t[%-7c]\n", c);



//	CHAR *
//	****************************************************
//	char *c = "text";
//		ft_printf("> CHAR *\n");
//	printf("\t\t[%s]\n", c);
//	ft_printf("\t\t[%s]\n", c);
//	printf("1\t\t[%1s]\n", c);
//	ft_printf("1\t\t[%1s]\n", c);
//	printf("2\t\t[%2s]\n", c);
//	ft_printf("2\t\t[%2s]\n", c);
//	printf("7\t\t[%7s]\n", c);
//	ft_printf("7\t\t[%7s]\n", c);
//	printf(".\t\t[%.s]\n", c);
//	ft_printf(".\t\t[%.s]\n", c);
//	printf(".2\t\t[%.2s]\n", c);
//	ft_printf(".2\t\t[%.2s]\n", c);
//	printf("7.2\t\t[%7.2s]\n", c);
//	ft_printf("7.2\t\t[%7.2s]\n", c);
//	printf(".7\t\t[%.7s]\n", c);
//	ft_printf(".7\t\t[%.7s]\n", c);
//	printf("2.7\t\t[%2.7s]\n", c);
//	ft_printf("2.7\t\t[%2.7s]\n", c);
//	printf("-7\t\t[%-7s]\n", c);
//	ft_printf("-7\t\t[%-7s]\n", c);
//	printf("-7.\t\t[%-7.s]\n", c);
//	ft_printf("-7.\t\t[%-7.s]\n", c);
//	printf("-7.1\t[%-7.1s]\n", c);
//	ft_printf("-7.1\t[%-7.1s]\n", c);

//	UNSIGNED: o, O
//	****************************************************
//	unsigned int ui = ft_atoi(argv[1]);
	unsigned int ui = 0;

		ft_printf("________[o, O] minus & width\n");
//	printf("-4.7\t[%-4.7o]\n", ui);
//	ft_printf("-4.7\t[%-4.7o]\n", ui);
//	printf("-7.7\t[%-7.7o]\n", ui);
//	ft_printf("-7.7\t[%-7.7o]\n", ui);
//	printf("-#7.7\t[%-#7.7o]\n", ui);
//	ft_printf("-#7.7\t[%-#7.7o]\n", ui);
//	printf("-7.4\t[%-7.4o]\n", ui);
//	ft_printf("-7.4\t[%-7.4o]\n", ui);
//	printf("-#7.4\t[%-#7.4o]\n", ui);
//	ft_printf("-#7.4\t[%-#7.4o]\n", ui);
	printf("-7.\t\t[%#-7.o]\n", ui);
	ft_printf("-7.\t\t[%#-7.o]\n", ui);
	printf("#-7.\t[%#-7.o]\n", ui);
	ft_printf("#-7.\t[%#-7.o]\n", ui);
	printf("-7\t\t[%-7o]\n", ui);
	ft_printf("-7\t\t[%-7o]\n", ui);
		ft_printf("________[o, O] minus & !width\n");
	printf("-\t\t[%-o]\n", ui);
	ft_printf("-\t\t[%-o]\n", ui);
	printf("-#\t\t[%-#o]\n", ui);
	ft_printf("-#\t\t[%-#o]\n", ui);
	printf("-.\t\t[%-.o]\n", ui);
	ft_printf("-.\t\t[%-.o]\n", ui);
	printf("-#.\t\t[%-#.o]\n", ui);
	ft_printf("-#.\t\t[%-#.o]\n", ui);
	printf("-.7\t\t[%-.7o]\n", ui);
	ft_printf("-.7\t\t[%-.7o]\n", ui);
	printf("-#.7\t[%-#.7o]\n", ui);
	ft_printf("-#.7\t[%-#.7o]\n", ui);
		ft_printf("________[o, O] !minus & width\n");
	printf("7\t\t[%7o]\n", ui);
	ft_printf("7\t\t[%7o]\n", ui);
	printf("07\t\t[%07o]\n", ui);
	ft_printf("07\t\t[%07o]\n", ui);
	printf("7.\t\t[%7.o]\n", ui);
	ft_printf("7.\t\t[%7.o]\n", ui);
	printf("7.4\t\t[%7.4o]\n", ui);
	ft_printf("7.4\t\t[%7.4o]\n", ui);
	printf("#7.4\t[%#7.4o]\n", ui);
	ft_printf("#7.4\t[%#7.4o]\n", ui);
	printf("07.4\t[%07.4o]\n", ui);
	ft_printf("07.4\t[%07.4o]\n", ui);
	printf("7.7\t\t[%7.7o]\n", ui);
	ft_printf("7.7\t\t[%7.7o]\n", ui);
	printf("7.9\t\t[%7.9o]\n", ui);
	ft_printf("7.9\t\t[%7.9o]\n", ui);
	printf("#7.9\t[%#7.9o]\n", ui);
	ft_printf("#7.9\t[%#7.9o]\n", ui);
		ft_printf("________[o, O] !minus & !width\n");
	printf("\t\t[%o]\n", ui);
	ft_printf("\t\t[%o]\n", ui);
	printf(".\t\t[%.o]\n", ui);
	ft_printf(".\t\t[%.o]\n", ui);
	printf("#\t\t[%#o]\n", ui);
	ft_printf("#\t\t[%#o]\n", ui);
	printf(".7\t\t[%.7o]\n", ui);
	ft_printf(".7\t\t[%.7o]\n", ui);
	printf("#.7\t\t[%#.7o]\n", ui);
	ft_printf("#.7\t\t[%#.7o]\n", ui);


//	UNSIGNED: x, X
//	****************************************************
//	unsigned int ui = ft_atoi(argv[1]);
//	unsigned int ui = 77;

		ft_printf("________[x, X] minus & width\n");
//	printf("-4.7\t[%-4.7x]\n", ui);
//	ft_printf("-4.7\t[%-4.7x]\n", ui);
//	printf("-7.7\t[%-7.7x]\n", ui);
//	ft_printf("-7.7\t[%-7.7x]\n", ui);
//	printf("-#7.7\t[%-#7.7x]\n", ui);
//	ft_printf("-#7.7\t[%-#7.7x]\n", ui);
	printf("-7.4\t[%-7.4x]\n", ui);
	ft_printf("-7.4\t[%-7.4x]\n", ui);
	printf("-#7.4\t[%-#7.4x]\n", ui);
	ft_printf("-#7.4\t[%-#7.4x]\n", ui);
	printf("-7.\t\t[%-7.x]\n", ui);
	ft_printf("-7.\t\t[%-7.x]\n", ui);
	printf("#-7.\t[%#-7.x]\n", ui);
	ft_printf("#-7.\t[%#-7.x]\n", ui);
	printf("-7\t\t[%-7x]\n", ui);
	ft_printf("-7\t\t[%-7x]\n", ui);
//		ft_printf("________[x, X] minus & !width\n");
//	printf("-\t\t[%-x]\n", ui);
//	ft_printf("-\t\t[%-x]\n", ui);
//	printf("-#\t\t[%-#x]\n", ui);
//	ft_printf("-#\t\t[%-#x]\n", ui);
//	printf("-.\t\t[%-.x]\n", ui);
//	ft_printf("-.\t\t[%-.x]\n", ui);
//	printf("-#.\t\t[%-#.x]\n", ui);
//	ft_printf("-#.\t\t[%-#.x]\n", ui);
//	printf("-.7\t\t[%-.7x]\n", ui);
//	ft_printf("-.7\t\t[%-.7x]\n", ui);
//	printf("-#.7\t[%-#.7x]\n", ui);
//	ft_printf("-#.7\t[%-#.7x]\n", ui);
		ft_printf("________[x, X] !minus & width\n");
	printf("7\t\t[%7x]\n", ui);
	ft_printf("7\t\t[%7x]\n", ui);
	printf("07\t\t[%07x]\n", ui);
	ft_printf("07\t\t[%07x]\n", ui);
	printf("7.\t\t[%7.x]\n", ui);
	ft_printf("7.\t\t[%7.x]\n", ui);
	printf("7.4\t\t[%7.4x]\n", ui);
	ft_printf("7.4\t\t[%7.4x]\n", ui);
	printf("#7.4\t[%#7.4x]\n", ui);
	ft_printf("#7.4\t[%#7.4x]\n", ui);
	printf("07.4\t[%07.4x]\n", ui);
	ft_printf("07.4\t[%07.4x]\n", ui);
	printf("7.7\t\t[%7.7x]\n", ui);
	ft_printf("7.7\t\t[%7.7x]\n", ui);
	printf("7.9\t\t[%7.9x]\n", ui);
	ft_printf("7.9\t\t[%7.9x]\n", ui);
	printf("#7.9\t[%#7.9x]\n", ui);
	ft_printf("#7.9\t[%#7.9x]\n", ui);
		ft_printf("________[x, X] !minus & !width\n");
	printf("\t\t[%x]\n", ui);
	ft_printf("\t\t[%x]\n", ui);
	printf(".\t\t[%.x]\n", ui);
	ft_printf(".\t\t[%.x]\n", ui);
	printf("#\t\t[%#x]\n", ui);
	ft_printf("#\t\t[%#x]\n", ui);
	printf(".7\t\t[%.7x]\n", ui);
	ft_printf(".7\t\t[%.7x]\n", ui);
	printf("#.7\t\t[%#.7x]\n", ui);
	ft_printf("#.7\t\t[%#.7x]\n", ui);


//	UNSIGNED: u, U
//	****************************************************
//	unsigned int ui = ft_atoi(argv[1]);
//	unsigned int ui = 125;
//
//		ft_printf("________[u, U] minus & width\n");
//	printf("-4.7\t[%-4.7u]\n", ui);
//	ft_printf("-4.7\t[%-4.7u]\n", ui);
//	printf("-7.7\t[%-7.7u]\n", ui);
//	ft_printf("-7.7\t[%-7.7u]\n", ui);
//	printf("-7.4\t[%-7.4u]\n", ui);
//	ft_printf("-7.4\t[%-7.4u]\n", ui);
//	printf("-7\t\t[%-7u]\n", ui);
//	ft_printf("-7\t\t[%-7u]\n", ui);
//		ft_printf("________[u, U] minus & !width\n");
//	printf("-\t\t[%-u]\n", ui);
//	ft_printf("-\t\t[%-u]\n", ui);
//	printf("-.\t\t[%-.u]\n", ui);
//	ft_printf("-.\t\t[%-.u]\n", ui);
//	printf("-.7\t\t[%-.7u]\n", ui);
//	ft_printf("-.7\t\t[%-.7u]\n", ui);
//		ft_printf("________[u, U] !minus & width\n");
//	printf("7\t\t[%7u]\n", ui);
//	ft_printf("7\t\t[%7u]\n", ui);
//	printf("07\t\t[%07u]\n", ui);
//	ft_printf("07\t\t[%07u]\n", ui);
//	printf("7.\t\t[%7.u]\n", ui);
//	ft_printf("7.\t\t[%7.u]\n", ui);
//	printf("7.4\t\t[%7.4u]\n", ui);
//	ft_printf("7.4\t\t[%7.4u]\n", ui);
//	printf("07.4\t[%07.4u]\n", ui);
//	ft_printf("07.4\t[%07.4u]\n", ui);
//	printf("7.7\t\t[%7.7u]\n", ui);
//	ft_printf("7.7\t\t[%7.7u]\n", ui);
//	printf("7.9\t\t[%7.9u]\n", ui);
//	ft_printf("7.9\t\t[%7.9u]\n", ui);
//		ft_printf("________[u, U] !minus & !width\n");
//	printf("\t\t[%u]\n", ui);
//	ft_printf("\t\t[%u]\n", ui);
//	printf(".\t\t[%.u]\n", ui);
//	ft_printf(".\t\t[%.u]\n", ui);
//	printf(".7\t\t[%.7u]\n", ui);
//	ft_printf(".7\t\t[%.7u]\n", ui);



//	 SIGNED: flags, %i, %d, %D
//	****************************************************
//	 int i = ft_atoi(argv[1]);
//	 int i = 1234567;
////
//	 ft_printf("________[_______] minus & width\n");
//	 printf("-	\t[%-d]\n", i);
//	 ft_printf("-	\t[%-d]\n", i);
//	 printf("-4.7	[%-4.7d]\n", i);
//	 ft_printf("-4.7	[%-4.7d]\n", i);
//	 printf("-7.7	[%-7.7d]\n", i);
//	 ft_printf("-7.7	[%-7.7d]\n", i);
//	 printf("-+7.4	[%+-7.4d]\n", i);
//	 ft_printf("-+7.4	[%+-7.4d]\n", i);
//	 printf("- 7.4	[% -7.4d]\n", i);
//	 ft_printf("- 7.4	[% -7.4d]\n", i);
//	 printf("-7.4	[%-7.4d]\n", i);
//	 ft_printf("-7.4	[%-7.4d]\n", i);
//	 printf("-7	\t[%-7d]\n", i);
//	 ft_printf("-7	\t[%-7d]\n", i);
//
//	 ft_printf("________[_______] minus & !width\n");
//	 printf("- .7	[%- .7d]\n", i);
//	 ft_printf("- .7	[%- .7d]\n", i);
//	 printf("-+.7	[%-+.7d]\n", i);
//	 ft_printf("-+.7	[%-+.7d]\n", i);
//	 printf("-+.1	[%-+.1d]\n", i);
//	 ft_printf("-+.1	[%-+.1d]\n", i);
//	 printf("- .0	[%- .0d]\n", i);
//	 ft_printf("- .0	[%- .0d]\n", i);
//	 printf("-+.0	[%-+.0d]\n", i);
//	 ft_printf("-+.0	[%-+.0d]\n", i);
//	 printf("-.7	\t[%-.7d]\n", i);
//	 ft_printf("-.7	\t[%-.7d]\n", i);
//	 printf("-.0	\t[%-.d]\n", i);
//	 ft_printf("-.0	\t[%-.d]\n", i);
//	 printf("-	\t[%-d]\n", i);
//	 ft_printf("-	\t[%-d]\n", i);
//
//	 ft_printf("________[_______] !minus & width\n");
//	 printf("4.7	\t[%4.7d]\n", i);
//	 ft_printf("4.7	\t[%4.7d]\n", i);
//	 printf("7.7	\t[%7.7d]\n", i);
//	 ft_printf("7.7	\t[%7.7d]\n", i);
//	 printf("7.6	\t[%7.6d]\n", i);
//	 ft_printf("7.6	\t[%7.6d]\n", i);
//	 printf(" 7.6	[% 7.6d]\n", i);
//	 ft_printf(" 7.6	[% 7.6d]\n", i);
//	 printf("+7.6	[%+7.6d]\n", i);
//	 ft_printf("+7.6	[%+7.6d]\n", i);
//	 printf("+07	\t[%+07d]\n", i);
//	 ft_printf("+07	\t[%+07d]\n", i);
//	 printf("07	\t[%07d]\n", i);
//	 ft_printf("07	\t[%07d]\n", i);
//	 printf("7.4	\t[%7.4d]\n", i);
//	 ft_printf("7.4	\t[%7.4d]\n", i);
//	 printf(" 7.4	[% 7.4d]\n", i);
//	 ft_printf(" 7.4	[% 7.4d]\n", i);
//	 printf("0 7.4	[%0 7.4d]\n", i);
//	 ft_printf("0 7.4	[%0 7.4d]\n", i);
//	 printf("+7.4	[%+7.4d]\n", i);
//	 ft_printf("+7.4	[%+7.4d]\n", i);
//	 printf("+07.4	[%+07.4d]\n", i);
//	 ft_printf("+07.4	[%+07.4d]\n", i);
//	 printf("+07.	[%+07.d]\n", i);
//	 ft_printf("+07.	[%+07.d]\n", i);
//	 printf("07.	\t[%07.d]\n", i);
//	 ft_printf("07.	\t[%07.d]\n", i);
//	 printf("07.3	[%07.3d]\n", i);
//	 ft_printf("07.3	[%07.3d]\n", i);
//	 printf("7	\t[%7d]\n", i);
//	 ft_printf("7	\t[%7d]\n", i);
//	 printf("+7	\t[%+7d]\n", i);
//	 ft_printf("+7	\t[%+7d]\n", i);
//
//
////	int size;
////	int i = 0;
//	ft_printf("________[_______] !minus & !width\n");
//	printf(" .7	[% .7d]\n", i);
//	ft_printf(" .7	[% .7d]\n", i);
//	printf("+.7	[%+.7d]\n", i);
//	ft_printf("+.7	[%+.7d]\n", i);
//	printf("+.4	[%+.4d]\n", i);
//	ft_printf("+.4	[%+.4d]\n", i);
//	printf("+.1	[%+.1d]\n", i);
//	ft_printf("+.1	[%+.1d]\n", i);
//	printf(".7	[%.7d]\n", i);
//	ft_printf(".7	[%.7d]\n", i);
//	printf("+.0	[%+.0d]\n", i);
//	ft_printf("+.0	[%+.0d]\n", i);
//	printf(" .0	[% .0d]\n", i);
//	ft_printf(" .0	[% .0d]\n", i);
//	printf(".0	[%.d]\n", i);
//	ft_printf(".0	[%.d]\n", i);
//	printf("+	[%+d]\n", i);
//	ft_printf("+	[%+d]\n", i);
//	printf("	[%d]\n", i);
//	ft_printf("	[%d]\n", i);


	// MIN & MAX values of types
	//****************************************************
	// printf("size_t MIN = %lld\n", MIN_OF(size_t));
	// printf("size_t MAX = %llu\n", MAX_OF(size_t));
	// printf("ull int MIN = %lld\n", MIN_OF(unsigned long long int));
	// printf("ull int MAX = %llu\n", MAX_OF(unsigned long long int));
//	 printf("uintmax_t MIN = %lld\n", MIN_OF(uintmax_t));
//	 printf("uintmax_t MAX = %llu, len = %zu\n", MAX_OF(uintmax_t),
//	 		ft_nbrulen(MAX_OF(uintmax_t), 10));
//	 printf("intmax_t MIN = %lld\n", LLONG_MIN);
//	 printf("intmax_t MAX = %llu\n", LLONG_MAX);

//	 printf("char MIN = %lld\n", MIN_OF(char));
//	 printf("char MAX = %llu\n", MAX_OF(char));
//	 printf("wchar_t MIN = %lld\n", MIN_OF(wchar_t));
//	 printf("wchar_t MAX = %llu\n", MAX_OF(wchar_t));
//	 printf("int MIN = %lld\n", MIN_OF(int));
//	 printf("int MAX = %llu\n", MAX_OF(int));
//	 printf("ssize_t MIN = %lld\n", MIN_OF(ssize_t));
//	 printf("ssize_t MAX = %llu\n", MAX_OF(ssize_t));
//	 printf("short MIN = %lld\n", MIN_OF(short));
//	 printf("short MAX = %llu\n", MAX_OF(short));

	// ENUM
	//****************************************************
//	typedef enum ee	{none, h, l, j, z} t_ee;
//
//	 t_ee first = 0;
//	 char c = 'j';
//	 if (c == 'z'){
//	 	printf("true\n");
//	 	first = c;
//	 }
//	 if (first == none)
//	 	printf("none\n");
//	 printf("%d\n", first);

	// Specification
	//****************************************************
	// test_specification(argv[2], i);

	// LEAKS
	//****************************************************
	// printf(YELLOW "______________________________________________\n");
//	system("leaks _ft_printf");
//	156 nodes malloced for 118 KB
	return (0);
}


//else if (sp < 0 || (MINUS && WIDTH) /*|| (SPC && (sp == (short)-SIZE))*/)
//sp = 0;