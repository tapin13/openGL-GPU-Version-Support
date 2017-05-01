LDLIBS=-lglut  -lGLEW -lGL
all: main
clean:
	rm -f *.o main
.PHONY: all clean