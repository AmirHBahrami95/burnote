#include "../include/libs.h"
#include "../include/utils.h"

static int errno_cpy=0;

void print_errno(){
	errno_cpy=errno; // man errno - NOTES
	perror(strerror(errno_cpy));
}

void print_help(){
	puts("burnote\t:watch your file burn digitally then get deleted");
	puts("\tusage\t:burnote <path_to_file> [-h] [-w/--wait INT] [-b/--buff INT] [-x/--hex]");
	puts("\t-w INT\t:wait INT seconds before the next peiece of file is burnt");
	puts("\t-b INT\t:burn INT bytes each time the file is burnt");
	puts("\t-x\t:print burnt pieces in hex");
	puts("\t-h\t:print help");
}

void print_hex(const char *s){
	for(;*s;++s) printf("%2hx",*s);
	putchar('\n');
}

// 1 -> true, not otherwise :|
int is_numeric(const char *s){
	for(;*s;++s) if(!isdigit(*s)) return 0;
	return 1;
}
