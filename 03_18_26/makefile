all: main clock
main: clock main.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp clock -o main
clock: clock.h clock.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g clock.cpp -o clock