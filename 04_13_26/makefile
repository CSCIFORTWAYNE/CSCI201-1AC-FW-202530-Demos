all: main drink
main: drink main.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp drink -o main
drink: drink.h drink.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g drink.cpp -o drink
