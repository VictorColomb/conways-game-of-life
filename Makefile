_DEBUG = $(if $(DEBUG),-D DEBUG,)
_OPT = $(if $(OPT),-O3 -flto,)
CC = gcc
CFLAGS = -g -std=c99 -Wall $(_OPT) -I./include $(_DEBUG)

.PHONY: clean clean-all clean-img doc check-syntax all compile-all naive naive-compile-all launch-tests video
.DEFAULT_GOAL:= all


# Generate doxygen documentation
doc:
	doxygen conf/doxygen.conf >/dev/null 2>&1

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
test-naive-universe: test-naive-universe.o naive_universe.o
	$(CC) $(CFLAGS) -o test-naive-universe test-naive-universe.o naive_universe.o
test-naive-loader: test-naive-loader.o naive_universe.o naive_loader.o
	$(CC) $(CFLAGS) -o test-naive-loader test-naive-loader.o naive_universe.o naive_loader.o
app-naive-loader: app-naive-loader.o naive_universe.o naive_loader.o
	$(CC) $(CFLAGS) -o app-naive-loader app-naive-loader.o naive_universe.o naive_loader.o


# USER RULES
all: doc app-naive-loader clean

compile-all: test-naive-universe test-naive-loader app-naive-loader

naive: app-naive-loader clean

compile-naive-all: test-naive-universe test-naive-loader app-naive-loader


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
