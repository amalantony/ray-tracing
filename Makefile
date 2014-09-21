CFLAGS=$(shell pkg-config --cflags glfw3)
LDLIBS=$(shell pkg-config --static --libs glfw3)

.PHONY: debug
.PHONY: all
.PHONY: clean

debug: CFLAGS += -g
debug: all

all:
	@echo -n "Building the ray tracer..."
	@$(CC) ./src/* -std=c99 -Wall --pedantic $(CFLAGS) -o ./bin/raytracer $(LDLIBS)
	@echo " Success!"

clean:
	@echo -n "Cleaning the binaries..."
	@rm -rf ./bin/*
	@echo " Success!"
