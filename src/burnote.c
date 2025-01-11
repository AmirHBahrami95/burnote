#include "../include/libs.h"
#include "../include/burnote.h"
#include "../include/utils.h"

// i like to see my shit burn slowly
static int burn_wait=3;
static int burn_buff=32;
static int hex=0; // hex output for more fun

static void print_fire(){
	for(int i=0;i<3;i++){
		puts("\t(  (   (");
		puts("\t )   )    )");
	}
}

void set_burn_buff(int bb){burn_buff=bb;}
void set_burn_wait(int bw){burn_wait=bw;}
void set_hex(int h){hex=h;}

int burn_file(const char *path){
	char buff[burn_buff];
	int nb_read=0,fd;

	fd=open(path,O_RDWR,0);
	if(fd==-1){
		print_errno();
		return 0; // abort
	}
	
	// i am born to program (in c/++)
	while((nb_read=read(fd,buff,burn_buff))>0){
		print_fire();
		if(hex) print_hex(buff);
		else puts(buff);
		sleep(burn_wait);
	}
	
	// getting rid of the guy
	if(nb_read==-1 || unlink(path)==-1 || close(fd)==-1){
		print_errno();
		return 0;
	}

	return 1;

}
