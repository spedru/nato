#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <unistd.h>

const char *alpha[] = {
	"dash",
	"point",
	"",
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"niner",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"alpha",
	"bravo",
	"charile",
	"delta",
	"echo",
	"foxtrot",
	"golf",
	"hotel",
	"india",
	"juliett",
	"kilo",
	"lima",
	"mike",
	"november",
	"oscar",
	"papa",
	"quebec",
	"romeo",
	"sierra",
	"tango",
	"uniform",
	"victor",
	"xray",
	"yankee",
	"zulu"
};

int print(const char *s) {
	return printf("%s", s);
}
int Print(const char *s) {
	if (s) 
		putchar(toupper(*s));
	else
		return 0;
	return *s ? printf("%s", s + 1) + 1 : 1;
}
int PRINT(const char *s) {
	int i;
	for (i = 0; *s; i++) putchar(toupper(*s++));
	return i;
}
int main(int argc, char *argv[])
{
	int stop = 1;
	int (*printer)(const char *) = &print;
	for (int opt; (opt = getopt(argc, argv, "pcC")) != -1;) {
		switch (opt) {
		case 'p':
			stop = 0;
		case 'c':
			printer = &Print;
			break;
		case 'C':
			printer = &PRINT;
			break;
		}
	}
	for (int c, first = 1; (c = toupper(getchar())) != EOF;) {
		if (first)
			first = 0;
		else
			putchar(' ');
		(*printer)(c < '-' || c > 'Z' ? "" : alpha[c - '-']);
	}
	if (stop) (*printer)("stop");
	if (isatty(fileno(stdout))) putchar('\n');
	return 0;
}
