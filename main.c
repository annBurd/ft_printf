#include "./inc/ft_printf.h"
#include <sys/types.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>

// #define NORMAL	"\x1B[0m"
// #define RED		"\x1B[31m"
// #define GREEN	"\x1B[32m"
// #define YELLOW	"\x1B[33m"
// #define BLUE		"\x1B[34m"
// #define MAGENTA	"\x1B[35m"
// #define CYAN		"\x1B[36m"
// #define WHITE	"\x1B[37m"

//# define EOC		"\e[0m"
//# define RED		"\e[91m"
//# define GREEN	"\e[92m"
//# define YELLOW	"\e[93m"
//# define BLUE		"\e[94m"
//# define PINK		"\e[95m"
//# define WHITE	"\e[97m"

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

//30 – 37: set foreground color 0 – 7 (black, red, green, yellow, blue, purple, cyan, white)
//90 – 97: set foreground color 8 – 15 (bright versions of 0 – 7; "bright black" is a dark gray)
//40 – 47: set background color 0 – 7 (ditto)
//100 – 107: set background color 8 – 15 (ditto)
//In your case, red text on a white background would be \e[31;47m.

//	0: Reset/remove all modifier, foreground and background attributes: echo -e "\e[0mNormal Text"
//	1: Bold/Bright: echo -e "Normal \e[1mBold"
//	2: Dim: echo -e "Normal \e[2mDim"
//	4: Underlined: echo -e "Normal \e[4mUnderlined"
//	5: Blink (doesn't work in most terminals except XTerm): echo -e "Normal \e[5mBlink"
//	7: Reverse/Invert: echo -e "Normal \e[7minverted"
//	8: Hidden (useful for sensitive info): echo -e "Normal \e[8mHidden Input"
//	21: Reset/Remove bold/bright: echo -e "Normal \e[1mBold \e[21mNormal"
//	22: Reset/Remove dim: echo -e "Normal \e[2mDim \e[22mNormal"
//	24: Reset/Remove underline: echo -e "Normal \e[4mUnderlined \e[24mNormal"
//	25: Reset/Remove blink: echo -e "Normal \e[5mBlink \e[25mNormal"
//	27: Reset/Remove reverse/invert: echo -e "Normal \e[7minverted \e[27mNormal"
//	28: Reset/Remove hidden: echo -e "Normal \e[8mHidden \e[28mNormal"
// **************************************************************************

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
//	setlocale(LC_CTYPE, "");
	setlocale(LC_ALL, "en_US.UTF-8");


//	HERE WE HAVE SOME TESTS
//	****************************************************
//	PERCENT: %
//	ft_printf("\n> PERCENT: %%\n");
//	printf("[%%]\n");
//	ft_printf("[%%]\n");
//	printf("[%.%]\n");
//	ft_printf("[%.%]\n");
//	printf("[%.4%]\n");
//	ft_printf("[%.4%]\n");
//	printf("[%4%]\n");
//	ft_printf("[%4%]\n");
//	printf("[%4.2%]\n");
//	ft_printf("[%4.2%]\n");
//	printf("[%04.2%]\n");
//	ft_printf("[%04.2%]\n");

////	CHAR: %c, %s
//	char c = '$';
//	char *s = "Do some trash test for my lovely ft_printf()";
//	ft_printf("\n> CHAR %%c, %%s\n");
//	printf("%%c = %c ____[%-*.*s] 0R!G\n", c, 30, 13, s);
//	ft_printf("%%c = %c ____[%-*.*s]\n", c, 30, 13, s);
//	ft_printf("%%c = %!fr!c ____[%-*.*s]\n", c, 30, 13, s);
//	ft_printf("Do some <!mb!trash test>! for my <!Fr!lovely>! ft_printf()\n");

//	printf("1 - \e[1;mBold\e[0m\n");
//	printf("2 - \e[2;mDim\e[0m\n");
//	printf("3 - \e[3;mItalic\e[0m\n");
//	printf("4 - \e[4;mUnderline\e[0m\n");
//	printf("7 - \e[7;mReverse\e[0m\n");

//	ft_printf("Test <!mu;fr!colors>!\n");

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
//	ft_printf("[%!mu;Fb!b]\n", i);
//	ft_printf("[%!118jb]\n", i);
//	ft_printf("[%!18j2b]\n", i);
//
////	 BONUS APOST (`) with %i, %d, %D
////	 BONUS STAR (*)
//	int i = -1234567;
//	int w = 20;
//	int p = 11;
//	ft_printf("\n> APOST && STAR\n");
//	ft_printf("\t\t[%'d]\n", i);
//	ft_printf(" 2\t\t[%\' 2d]\n", i);
//	ft_printf("-%d.%d\t[%'-*.*d]\n", w, p, w, p, i);
//	ft_printf("%d\t\t[%'*d]\n", w, w, i);
//	ft_printf("%d.%d\t[%'*.*d]\n", w, p, w, p, i);
//	ft_printf("+%d.%d\t[%'+*.*d]\n", w, p, w, p, i);
//	ft_printf(".%d\t\t[%'.*d]\n", w, w, i);
//	ft_printf("0%d\t\t[%'0*d]\n", w, w, i);

//		ft_printf("> BONUS STAR : failed tests\n");
//	printf("|% +.*d|\n", -8, -25);
//	ft_printf("|% +.*d|\n", -8, -25);
//	printf("|% +*d|\n", -8, -25);
//	ft_printf("|% +*d|\n", -8, -25);
//	printf("|% +*.*d|\n", -8, -1, -25);
//	ft_printf("|% +*.*d|\n", -8, -1, -25);
//	printf("|%0+#*.*i|\n", 5, -4, -25);
//	ft_printf("|%0+#*.*i|\n", 5, -4, -25);
//	printf("|%+#*.*i|\n", 5, -4, -25);
//	ft_printf("|%+#*.*i|\n", 5, -4, -25);
//	printf("|% 0+#*.*i|\n", 5, -4, -25);
//	ft_printf("|% 0+#*.*i|\n", 5, -4, -25);
//	printf("|%0-#*.*d|\n", 5, -4, -25);
//	ft_printf("|%0-#*.*d|\n", 5, -4, -25);
//	printf("|% +*.*d|\n", 15, 4, 1234567);
//	ft_printf("|% +*.*d|\n", 15, 4, 1234567);

//
//	unsigned  ui = 12345;
//	ft_printf("\n> APOST && STAR && uU\n");
//	printf("-10\t\t[%-10u]ui 0R!G\n", ui);
//	ft_printf("`-10\t[%`-10lu]ui\n", ui);
//	printf("010\t\t[%010u]ui 0R!G\n", ui);
//	ft_printf("`010\t[%`010lu]ui\n", ui);
//	printf("7.9\t\t[%7.9u]ui 0R!G\n", ui);
//	ft_printf("`7.9\t[%`7.9lu]ui\n", ui);
//	ft_printf("`7.9\t[%`7.9x]ui - x\n", ui);

////	BONUS COLOR
//		printf("\n> COLOR\n");

//	ft_printf("Do %!mb;fr;Bw!s test!\n", "trash");
//	ft_printf("Do <!Fb!%s test!\n", "trash");
//	ft_printf("Do %!mr;fy!s test!\n", "trash");
//	ft_printf("Do <!mu;mb;fp!trash<!Mu;fg! test!\n");
//	ft_printf("\t<<<<<<<<<<>!%!Fr!c>>>>>>>>>\n", '!');
//	ft_printf("<!mb;fy!zzZzZz<!Mb! <!Fp;BB![Bold]>!\n");
//	ft_printf("<!md;fy!zzZzZz<!Md! <!Fp;BB![Dim]>!\n");
//	ft_printf("<!mi;fy!zzZzZz<!Mi! <!Fp;BB![Italic]>!\n");
//	ft_printf("<!mr;fy!zzZzZz<!Mr! <!Fp;BB![Reverse]>!\n");
//	ft_printf("<!mu;fy!zzZzZz<!Mu! <!Fp;BB![Underline]>!\n");

//	****************************************************


//	WCHAR_T
//	****************************************************
//	wchar_t wc = L'Ї';
//	wchar_t wc = L'ꚩ';
//	wchar_t wc = L'ᚫ';
//	wchar_t wc = 65537;
//		ft_printf("> WCHAR_T\n");
//	printf("\t\t[%C]%u\n", wc, wc);
//	ft_printf("\t\t[%C]%u\n", wc, wc);
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


//		ft_printf("> WCHAR_T : failed tests\n");
//	printf("|% 0+2.C|\n", 129);
//	ft_printf("|% 0+2.C|\n", 129);
//	printf("|%2.lc|\n", 129);
//	ft_printf("|%2.lc|\n", 129);
//	printf("|% +2.lc|\n", 129);
//	ft_printf("|% +2.lc|\n", 129);
//	printf("|%+0.C|\n", L'V');
//	ft_printf("|%+0.C|\n", L'V');
//	printf("|%2C|\n", 129);
//	ft_printf("|%2C|\n", 129);
//	printf("|% 0+-C|\n", 0);
//	ft_printf("|% 0+-C|\n", 0);


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
//	printf(".\t\t[%.S]\n", ww);
//	ft_printf(".\t\t[%.S]\n", ww);
//	printf("-20\t\t[%-20S]\n", ww);
//	ft_printf("-20\t\t[%-20S]\n", ww);
//	printf("-20.\t[%-20.S]\n", ww);
//	ft_printf("-20.\t[%-20.S]\n", ww);

//		ft_printf("> WCHAR_T* : failed tests\n");
//	printf("%013.12ls|\n", L"casual string");
//	ft_printf("%013.12ls|\n", L"casual string");
//	printf("%.3ls|\n", NULL);
//	ft_printf("%.3ls|\n", NULL);


//	CHAR
//	****************************************************
//	char c = '#';
//	char c = 0;
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
//	printf(".2\t\t[%.2c]\n", c);
//	ft_printf(".2\t\t[%.2c]\n", c);
//	printf("-7\t\t[%-7c]\n", c);
//	ft_printf("-7\t\t[%-7c]\n", c);
//	printf("_\t\t[% c]\n", c);
//	ft_printf("_\t\t[% c]\n", c);


//	CHAR*
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

//		ft_printf("> CHAR* : failed tests\n");
//	printf("%5.2s is a string\n", "");
//	ft_printf("%5.2s is a string\n", "");
//	printf("%-5.2s is a string\n", "");
//	ft_printf("%-5.2s is a string\n", "");
//	printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");
//	ft_printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");
//	printf("%5.2s is a string\n", "this");
//	ft_printf("%5.2s is a string\n", "this");
//	printf("%10s is a string\n", "");
//	ft_printf("%10s is a string\n", "");
//	printf("%-5.2s is a string\n", "this");
//	ft_printf("%-5.2s is a string\n", "this");
//	printf("%-10s is a string\n", "");
//	ft_printf("%-10s is a string\n", "");
//	printf("%.2s is a string\n", "");
//	ft_printf("%.2s is a string\n", "");
//	printf("%-.2s is a string\n", "");
//	ft_printf("%-.2s is a string\n", "");
//	printf("%s\n", NULL);
//	ft_printf("%s\n", NULL);
//	printf("%s %s\n", NULL, "string");
//	ft_printf("%s %s\n", NULL, "string");
//	printf("%-30.20s|\n", L"casual string");
//	ft_printf("%-30.20s|\n", L"casual string");

//	UNSIGNED: o, O
//	****************************************************
//	unsigned int ui = ft_atoi(argv[1]);
//	unsigned int ui = 0;
//
//		ft_printf("________[o, O] minus & width\n");
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
//	printf("-7.\t\t[%-7.o]\n", ui);
//	ft_printf("-7.\t\t[%-7.o]\n", ui);
//	printf("#-7.\t[%#-7.o]\n", ui);
//	ft_printf("#-7.\t[%#-7.o]\n", ui);
//	printf("-7\t\t[%-7o]\n", ui);
//	ft_printf("-7\t\t[%-7o]\n", ui);
//		ft_printf("________[o, O] minus & !width\n");
//	printf("-\t\t[%-o]\n", ui);
//	ft_printf("-\t\t[%-o]\n", ui);
//	printf("-#\t\t[%-#o]\n", ui);
//	ft_printf("-#\t\t[%-#o]\n", ui);
//	printf("-.\t\t[%-.o]\n", ui);
//	ft_printf("-.\t\t[%-.o]\n", ui);//0
//	printf("-#.\t\t[%-#.o]\n", ui);
//	ft_printf("-#.\t\t[%-#.o]\n", ui);
//	printf("-.7\t\t[%-.7o]\n", ui);
//	ft_printf("-.7\t\t[%-.7o]\n", ui);
//	printf("-#.7\t[%-#.7o]\n", ui);
//	ft_printf("-#.7\t[%-#.7o]\n", ui);
//		ft_printf("________[o, O] !minus & width\n");
//	printf("7\t\t[%7o]\n", ui);
//	ft_printf("7\t\t[%7o]\n", ui);
//	printf("07\t\t[%07o]\n", ui);
//	ft_printf("07\t\t[%07o]\n", ui);
//	printf("7.\t\t[%7.o]\n", ui);
//	ft_printf("7.\t\t[%7.o]\n", ui);
//	printf("7.4\t\t[%7.4o]\n", ui);
//	ft_printf("7.4\t\t[%7.4o]\n", ui);
//	printf("#7.4\t[%#7.4o]\n", ui);
//	ft_printf("#7.4\t[%#7.4o]\n", ui);
//	printf("07.4\t[%07.4o]\n", ui);
//	ft_printf("07.4\t[%07.4o]\n", ui);
//	printf("7.7\t\t[%7.7o]\n", ui);
//	ft_printf("7.7\t\t[%7.7o]\n", ui);
//	printf("7.9\t\t[%7.9o]\n", ui);
//	ft_printf("7.9\t\t[%7.9o]\n", ui);
//	printf("#7.9\t[%#7.9o]\n", ui);
//	ft_printf("#7.9\t[%#7.9o]\n", ui);
//		ft_printf("________[o, O] !minus & !width\n");
//	printf("\t\t[%o]\n", ui);
//	ft_printf("\t\t[%o]\n", ui);
//	printf(".\t\t[%.o]\n", ui);
//	ft_printf(".\t\t[%.o]\n", ui);
//	printf("#\t\t[%#o]\n", ui);
//	ft_printf("#\t\t[%#o]\n", ui);
//	printf(".7\t\t[%.7o]\n", ui);
//	ft_printf(".7\t\t[%.7o]\n", ui);
//	printf("#.7\t\t[%#.7o]\n", ui);
//	ft_printf("#.7\t\t[%#.7o]\n", ui);

//		ft_printf("\n> OCTAL: failed tests\n");
//	printf("%-05o\n", 2500);
//	ft_printf("%-05o\n", 2500);
//	printf("%-5.10o\n", 2500);
//	ft_printf("%-5.10o\n", 2500);
//	printf("%-10.5o\n", 2500);
//	ft_printf("%-10.5o\n", 2500);
//	printf("% #5.4zU|\n", -25);
//	ft_printf("% #5.4zU|\n", -25);
//	printf("% 0-5u|\n", 0);
//	ft_printf("% 0-5u|\n", 0);
//	printf("%-5u|\n", 0);
//	ft_printf("%-5u|\n", 0);

//	unsigned long int ulo = 0;
//	printf("%0 +-#12.15lo|\n", ulo);
//	ft_printf("%0 +-#12.15lo|\n", ulo);
//	printf("%0 +-12.5lo|\n", ulo);
//	ft_printf("%0 +-12.5lo|\n", ulo);
//	printf("%0 +-.lo|\n", ulo);
//	ft_printf("%0 +-.lo|\n", ulo);
//	printf("% +#*lo|\n", 7, ulo);
//	ft_printf("% +#*lo|\n", 7, ulo);
//	printf("%0 +-#12.*lo|\n", -7, ulo);
//	ft_printf("%0 +-#12.*lo|\n", -7, ulo);


//	POINTER: %p
//	****************************************************
//	ft_printf("\n> POINTER\n");
//	short p = 6667;
//	printf("\t\t[%p] 0R!G\n", &p);
//	ft_printf("\t\t[%p]\n", &p);
//	printf(".\t\t[%.p] 0R!G\n", &p);
//	ft_printf(".\t\t[%.p]\n", &p);
//	printf("20\t\t[%20p] 0R!G\n", &p);
//	ft_printf("20\t\t[%20p]\n", &p);
//	printf("-20\t\t[%-20p] 0R!G\n", &p);
//	ft_printf("-20\t\t[%-20p]\n", &p);

//	ft_printf("\n> POINTER: failed tests\n");
//	printf("% 0+5p|\n", 0);
//	ft_printf("% 0+5p|\n", 0);
//	printf("% 0+p|\n", 0);
//	ft_printf("% 0+p|\n", 0);
//	printf("%+-5p|\n", 0);
//	ft_printf("%+-5p|\n", 0);
//
//
////	UNSIGNED: x, X
////	****************************************************
////	unsigned int ui = ft_atoi(argv[1]);
//	unsigned int ui = 0;
//
//		ft_printf("________[x, X] minus & width\n");
//	printf("-4.7\t[%-4.7x]\n", ui);
//	ft_printf("-4.7\t[%-4.7x]\n", ui);
//	printf("-7.7\t[%-7.7x]\n", ui);
//	ft_printf("-7.7\t[%-7.7x]\n", ui);
//	printf("-#7.7\t[%-#7.7x]\n", ui);
//	ft_printf("-#7.7\t[%-#7.7x]\n", ui);
//	printf("-7.4\t[%-7.4x]\n", ui);
//	ft_printf("-7.4\t[%-7.4x]\n", ui);
//	printf("-#7.4\t[%-#7.4x]\n", ui);
//	ft_printf("-#7.4\t[%-#7.4x]\n", ui);
//	printf("-7.\t\t[%-7.x]\n", ui);
//	ft_printf("-7.\t\t[%-7.x]\n", ui);
//	printf("#-7.\t[%#-7.x]\n", ui);
//	ft_printf("#-7.\t[%#-7.x]\n", ui);
//	printf("-7\t\t[%-7x]\n", ui);
//	ft_printf("-7\t\t[%-7x]\n", ui);
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
//		ft_printf("________[x, X] !minus & width\n");
//	printf("7\t\t[%7x]\n", ui);
//	ft_printf("7\t\t[%7x]\n", ui);
//	printf("07\t\t[%07x]\n", ui);
//	ft_printf("07\t\t[%07x]\n", ui);
//	printf("7.\t\t[%7.x]\n", ui);
//	ft_printf("7.\t\t[%7.x]\n", ui);
//	printf("7.4\t\t[%7.4x]\n", ui);
//	ft_printf("7.4\t\t[%7.4x]\n", ui);
//	printf("#7.4\t[%#7.4x]\n", ui);
//	ft_printf("#7.4\t[%#7.4x]\n", ui);
//	printf("07.4\t[%07.4x]\n", ui);
//	ft_printf("07.4\t[%07.4x]\n", ui);
//	printf("7.7\t\t[%7.7x]\n", ui);
//	ft_printf("7.7\t\t[%7.7x]\n", ui);
//	printf("7.9\t\t[%7.9x]\n", ui);
//	ft_printf("7.9\t\t[%7.9x]\n", ui);
//	printf("#7.9\t[%#7.9x]\n", ui);
//	ft_printf("#7.9\t[%#7.9x]\n", ui);
//		ft_printf("________[x, X] !minus & !width\n");
//	printf("\t\t[%x]\n", ui);
//	ft_printf("\t\t[%x]\n", ui);
//	printf(".\t\t[%.x]\n", ui);
//	ft_printf(".\t\t[%.x]\n", ui);
//	printf("#\t\t[%#x]\n", ui);
//	ft_printf("#\t\t[%#x]\n", ui);
//	printf(".7\t\t[%.7x]\n", ui);
//	ft_printf(".7\t\t[%.7x]\n", ui);
//	printf("#.7\t\t[%#.7x]\n", ui);
//	ft_printf("#.7\t\t[%#.7x]\n", ui);
//
//	ft_printf("\n> HEXADECIMAL: failed tests\n");
//	printf("%#x\n", 0);
//	ft_printf("%#x\n", 0);
//	printf("%#-08x|\n", 42);
//	ft_printf("%#-08x|\n", 42);
//	printf("%#.x| %#.0x|\n", 0, 0);
//	ft_printf("%#.x| %#.0x|\n", 0, 0);
//	printf("%.x| %.0x|\n", 0, 0);
//	ft_printf("%.x| %.0x|\n", 0, 0);
//	printf("%5.x| %5.0x|\n", 0, 0);
//	ft_printf("%5.x| %5.0x|\n", 0, 0);
//	printf("%010x\n", 542);
//	ft_printf("%010x\n", 542);
//	printf("%#08x\n", 42);
//	ft_printf("%#08x\n", 42);
//	printf("%-.4X|\n", 0);
//	ft_printf("%-.4X|\n", 0);
//	printf("%#5lx|\n", 0);
//	ft_printf("%#5lx|\n", 0);


//	UNSIGNED: u, U
//	****************************************************
//	unsigned int ui = ft_atoi(argv[1]);
//	unsigned int ui = 0;
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



//	 SIGNED: flags, %i, %d
//	****************************************************
//	 int i = ft_atoi(argv[1]);
//	 int i = 0;
//
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
////
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
////
////
//////	int size;
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
//
//		ft_printf("\n> DECIMAL: failed tests\n");
//	printf("%-05d\n", 42);
//	ft_printf("%-05d\n", 42);
//	printf("%-05d\n", -42);
//	ft_printf("%-05d\n", -42);
//	printf("%-10.5d|\n", 4242);
//	ft_printf("%-10.5d|\n", 4242);
//	printf("%-+10.5d|\n", 4242);
//	ft_printf("%-+10.5d|\n", 4242);
//	printf("%#5zd|\n", 0);
//	ft_printf("%#5zd|\n", 0);
//	printf("%'.0hhd|\n", 1024);
//	ft_printf("%'.0hhd|\n", 1024);

//		ft_printf("\n> DECIMAL: %%D\n");
//	long int li = 12;
//	printf("%12ld|\n", li);
//	ft_printf("%12D|\n", li);
//	printf("%4.13ld|\n", li);
//	ft_printf("%4.13ld|\n", li);
//	ft_printf("%4.13D|\n", li);



//		ft_printf("\n> ONE MORE TEST\n");
	// int	size = 0;
	// size = printf("|%-2.C|", 129);
	// printf("%d\n", size);
	// size = ft_printf("|%-2.C|", 129);
	// printf("%d\n", size);
	// printf("------------------\n");
	// printf("#o - |%#o|\n", 0);
	// ft_printf("#o - |%#o|\n", 0);
	// printf("------------------\n");
	// printf("#x - |%#x|\n", 0);
	// ft_printf("#x - |%#x|\n", 0);
	// printf("------------------\n");
	// printf(".0d - |%.0d|\n", 0);
	// ft_printf(".0d - |%.0d|\n", 0);
	// printf("------------------\n");
	// printf(".0o - |%.0o|\n", 0);
	// ft_printf(".0o - |%.0o|\n", 0);
	// printf("------------------\n");
	// printf(".0x - |%.0x|\n", 0);
	// ft_printf(".0x - |%.0x|\n", 0);
	// printf("------------------\n");
	// printf("#.0d - |%#.0d|\n", 0);
	// ft_printf("#.0d - |%#.0d|\n", 0);
	// printf("------------------\n");
	// printf("#.0o - |%#.0o|\n", 0);
	// ft_printf("#.0o - |%#.0o|\n", 0);
	// printf("------------------\n");
	// printf("#.0x - |%#.0x|\n", 0);
	// ft_printf("#.0x - |%#.0x|\n", 0);
	// printf("==================\n");
	// printf("#o - |%#o|\n", 1);
	// ft_printf("#o - |%#o|\n", 1);
	// printf("------------------\n");
	// printf("#x - |%#x|\n", 1);
	// ft_printf("#x - |%#x|\n", 1);
	// printf("------------------\n");
	// printf(".0d - |%.0d|\n", 1);
	// ft_printf(".0d - |%.0d|\n", 1);
	// printf("------------------\n");
	// printf(".0o - |%.0o|\n", 1);
	// ft_printf(".0o - |%.0o|\n", 1);
	// printf("------------------\n");
	// printf(".0x - |%.0x|\n", 1);
	// ft_printf(".0x - |%.0x|\n", 1);
	// printf("------------------\n");
	// printf("#.0d - |%#.0d|\n", 1);
	// ft_printf("#.0d - |%#.0d|\n", 1);
	// printf("------------------\n");
	// printf("#.0o - |%#.0o|\n", 1);
	// ft_printf("#.0o - |%#.0o|\n", 1);
	// printf("------------------\n");
	// printf("#.0x - |%#.0x|\n", 1);
	// ft_printf("#.0x - |%#.0x|\n", 1);
	// printf("==================\n");




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
//	 printf("void* MIN = %lld\n", MIN_OF(void*));
//	 printf("void* MAX = %llu\n", MAX_OF(void*));

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