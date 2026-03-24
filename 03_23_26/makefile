all: person employee main drink product donut
main: main.cpp person employee drink product donut
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp person employee drink product donut -o main
person: person.h person.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g person.cpp -o person
employee: employee.h employee.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g employee.cpp -o employee
drink: drink.h drink.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g drink.cpp -o drink
product: product.h product.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g product.cpp -o product
donut: donut.h donut.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g donut.cpp -o donut


