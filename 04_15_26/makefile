all: main clock twelveHrClock twentyFourHrClock clockExcept
main: main.cpp clock twelveHrClock twentyFourHrClock clockExcept
	g++ -pedantic-errors -g -fdiagnostics-color=always main.cpp clock twelveHrClock twentyFourHrClock clockExcept -o main
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -fdiagnostics-color=always -c clock.cpp -o clock
twelveHrClock: twelveHrClock.cpp twelveHrClock.h clock clockExcept
	g++ -pedantic-errors -g -fdiagnostics-color=always -c twelveHrClock.cpp -o twelveHrClock
twentyFourHrClock: twentyFourHrClock.cpp twentyFourHrClock.h clock clockExcept
	g++ -pedantic-errors -g -fdiagnostics-color=always -c twentyFourHrClock.cpp -o twentyFourHrClock
clockExcept: clockExcept.cpp clockExcept.h
	g++ -pedantic-errors -g -fdiagnostics-color=always -c clockExcept.cpp -o clockExcept


clean:
	rm clock
	rm twelveHrClock
	rm twentyFourHrClock
	rm main