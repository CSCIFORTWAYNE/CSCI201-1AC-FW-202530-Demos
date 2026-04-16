all: main clock twelveHrClock twentyFourHrClock
main: main.cpp clock twelveHrClock twentyFourHrClock
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp clock twelveHrClock twentyFourHrClock -o main
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c clock.cpp -o clock
twelveHrClock: twelveHrClock.cpp twelveHrClock.h clock
	g++ -pedantic-errors -g -fdiagnostics-color=always -c twelveHrClock.cpp -o twelveHrClock
twentyFourHrClock: twentyFourHrClock.cpp twentyFourHrClock.h clock
	g++ -pedantic-errors -g -fdiagnostics-color=always -c twentyFourHrClock.cpp -o twentyFourHrClock

clean:
	rm clock
	rm twelveHrClock
	rm twentyFourHrClock
	rm main