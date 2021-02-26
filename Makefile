_DEBUG = $(if $(DEBUG),-D DEBUG,)
_OPT = $(if $(OPT),-O3 -flto,)
CC = gcc
CFLAGS = -g -std=c99 -Wall $(_OPT) -I./include $(_DEBUG)

.PHONY: clean clean-all clean-img doc check-syntax all compile-all naive naive-compile-all launch-tests video
.DEFAULT_GOAL:= all


# Generate doxygen documentation
doc:
	doxygen conf/doxygen.conf

# Remove output files and executables
clean:
	rm -f *.o

# Remove output files
clean-all:
	rm -f *.o
	find . -executable -type f -delete
	rm -rf doc

# Remove output images and videos
clean-img:
	rm out/*.ppm video.mp4


# Generic compilation recipes
%.o: ./src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

%.o: ./tests/%.c
	$(CC) $(CFLAGS) -o $@ -c $^


# Syntax check (put all .o files as prerequisites here)
check-syntax: naive_universe.o test-naive-universe.o

# Application building rules
app-naive-loader: naive-app-loader.o naive_universe.o naive_loader.o naive_ppm_writer.o naive_conway.o
	$(CC) $(CFLAGS) -o app-naive-loader naive-app-conway.o naive_universe.o naive_loader.o naive_ppm_writer.o naive_conway.o
app-naive-conway: app-naive-conway.o naive_universe.o naive_loader.o naive_ppm_writer.o naive_conway.o
	$(CC) $(CFLAGS) -o app-naive-conway app-naive-conway.o naive_universe.o naive_loader.o naive_ppm_writer.o naive_conway.o
test-naive-universe: test-naive-universe.o naive_universe.o
	$(CC) $(CFLAGS) -o test-naive-universe test-naive-universe.o naive_universe.o
test-naive-loader: test-naive-loader.o naive_universe.o naive_loader.o
	$(CC) $(CFLAGS) -o test-naive-loader test-naive-loader.o naive_universe.o naive_loader.o


# USER RULES
all: doc test-naive-universe clean

compile-all: app-naive-loader app-naive-conway test-naive-universe

naive: app-naive-conway clean

compile-naive-all: app-naive-conway test-naive-universe


# TESTS
ALL_TESTS = test-naive-universe test-naive-loader

launch-tests: $(ALL_TESTS)
	for x in $(ALL_TESTS); do ./$$x --all; done


# VIDEO
WIDTH=1024
HEIGHT=768

video: out
	mogrify -format png -background white -extent $(WIDTH)X$(HEIGHT) -gravity center out/*.p*m
	ffmpeg -framerate 5 -i out/img-%03d.png -vcodec libx264 -vf format=yuv420p video.mp4
	rm -f out/*.png
