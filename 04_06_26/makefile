all: main 
main: main.cpp person employee twelveHrClock twentyFourHrClock clock
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp person employee twelveHrClock twentyFourHrClock clock  -o main
person: person.h person.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g person.cpp -o person
employee: employee.h employee.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g employee.cpp -o employee
clock: clock.h clock.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g clock.cpp -o clock
twelveHrClock: twelveHrClock.h twelveHrClock.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g twelveHrClock.cpp -o twelveHrClock
twentyFourHrClock: twentyFourHrClock.h twentyFourHrClock.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g twentyFourHrClock.cpp -o twentyFourHrClock


