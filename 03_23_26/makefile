all: person employee main drink
main: main.cpp person employee drink
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp person employee drink -o main
person: person.h person.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g person.cpp -o person
employee: employee.h employee.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g employee.cpp -o employee
drink: drink.h drink.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g drink.cpp -o drink

