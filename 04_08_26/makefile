all: main 
main: main.cpp twelveHrClock twentyFourHrClock clock
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp twelveHrClock twentyFourHrClock clock  -o main
clock: clock.h clock.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g clock.cpp -o clock
twelveHrClock: twelveHrClock.h twelveHrClock.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g twelveHrClock.cpp -o twelveHrClock
twentyFourHrClock: twentyFourHrClock.h twentyFourHrClock.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g twentyFourHrClock.cpp -o twentyFourHrClock


