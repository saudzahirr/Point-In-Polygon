all:
	g++ main.cpp -o main

ifeq ($(OS), Windows_NT)
	main.exe
else
	./main
endif
