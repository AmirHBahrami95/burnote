#include "../include/libs.h"
#include "../include/burnote.h"
#include "../include/utils.h"

// TODO write null bytes or 'X' to file at the same time as it's being burnt, 
// so it feels good!
int main(int argc,char **argv){
	
	int wait=3,buff=32,hex=0;

	if( argc<2) {
		fprintf(stderr,"gimme a path, bro. pass -h for help\n");
		return 1;
	}
	
	for(int i=0;i<argc;i++){
		if(0==strcmp(argv[i],"-w") || 0==strcmp(argv[i],"--wait")) {
			if(!argv[i+1] || !is_numeric(argv[i+1])) {
				fprintf(stderr,"invalid --wait option\n");
				return 1;
			}
			wait=atoi(argv[i+1]);
			continue;
		}

		else if(0==strcmp(argv[i],"-b") || 0==strcmp(argv[i],"--buff")) {
			if(!argv[i+1] || !is_numeric(argv[i+1])){
				fprintf(stderr,"invalid --buff option\n");
				return 1;
			}
			buff=atoi(argv[i+1]);
			continue;
		}

		else if(0==strcmp(argv[i],"-x") || 0==strcmp(argv[i],"--hex")) {
			hex=1;
			continue;
		}

		else if(0==strcmp(argv[i],"-h") || 0==strcmp(argv[i],"--help")) {
			print_help();
			return 1;
		}

	}

	// printf("-w %d -b %d\n",wait,buff);
	// note you can also call these directly in the loop
	// but this is more concise + who gives a fuck
	set_burn_buff(buff);
	set_burn_wait(wait);
	set_hex(hex);

	if(burn_file(argv[1])) puts("FIN.");
	return 0;
}

