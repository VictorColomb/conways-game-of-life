_DEBUG = $(if $(DEBUG),-D DEBUG,)
_OPT = $(if $(OPT),-O3 -flto,)
CC = gcc
CFLAGS = -g -std=c99 -Wall $(_OPT) -I./include $(_DEBUG)

.PHONY: clean clean-img doc check-syntax compile-all launch-tests video

# rule to generate the doxygen documentation
doc:
	doxygen conf/doxygen.conf

# rule to remove all .o files and all executables
clean:
	- rm -f *.o
	- find . -executable -type f -delete

# rule to clean images and video
clean-img:
	- rm out/*.ppm video.mp4

# compile rules
%.o: ./src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

%.o: ./tests/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

# you should put all the .o files corresponding to your .c files as prerequisites of
# this rule (see examples)
# \ allows to go on the next line
check-syntax: example-main.o example-string.o read-file-formatted.o \
	      read-file-text.o write-fact.o test-dummy.o

# put all the rules to build your applications and tests here (see examples)
example-main: example-main.o
	$(CC) $(CFLAGS) -o example-main example-main.o

example-string: example-string.o
	$(CC) $(CFLAGS) -o example-string example-string.o

read-file-formatted: read-file-formatted.o
	$(CC) $(CFLAGS) -o read-file-formatted read-file-formatted.o

read-file-text: read-file-text.o
	$(CC) $(CFLAGS) -o read-file-text read-file-text.o

write-fact: write-fact.o
	$(CC) $(CFLAGS) -o write-fact write-fact.o

app-ex-loader: app-ex-loader.o
	$(CC) $(CFLAGS) -o app-ex-loader app-ex-loader.o

test-dummy: test-dummy.o
	$(CC) $(CFLAGS) -o test-dummy test-dummy.o

# put all your applications and tests executables as prerequisite of this rule
# \ allows to go to the next line
compile-all: example-main example-string read-file-formatted \
             read-file-text write-fact test-dummy \
	     app-ex-loader

# add all your test executables in the following variable. You should respect
# the order given in the project text
ALL_TESTS = test-dummy

launch-tests: $(ALL_TESTS)
	for x in $(ALL_TESTS); do ./$$x --all; done

# misc
WIDTH=1024
HEIGHT=768

video: out
	mogrify -format png -background white -extent $(WIDTH)X$(HEIGHT) -gravity center out/*.p*m
	ffmpeg -framerate 5 -i out/img-%03d.png -vcodec libx264 -vf format=yuv420p video.mp4
	rm -f out/*.png
