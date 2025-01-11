CC=gcc
PROGNAME=burnote
run_args=hello world
                                   
.PHONY: link_all make_bin clean run

link_all : main $(PROGNAME)
	$(CC) -o bin/$(PROGNAME) bin/*.o

run: link_all
	./bin/$(PROGNAME)

main : make_bin src/main.c $(PROGNAME)
	$(CC) -c src/main.c -o bin/main.o

$(PROGNAME) : utils src/$(PROGNAME).c include/$(PROGNAME).h include/libs.h
	gcc -c src/$(PROGNAME).c -o bin/$(PROGNAME).o

utils: make_bin src/utils.c include/utils.h include/libs.h
	gcc -c src/utils.c -o bin/utils.o

make_bin:
	mkdir -p bin

clean:
	rm -rf bin/
	echo 'cleaned'

