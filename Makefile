# Makefile

build: src/lab2-4.c
	gcc src/lab2-4.c -o executable

clean:
	del $(wildcard *.exe)

run:
	./executable 1
