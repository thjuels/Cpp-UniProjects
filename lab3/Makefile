CPPFLAGS = -std=c++11

all: lab3.exe

lab3.exe: Aircraft.o Airport.o CargoAircraft.o Hangar.o PassengerAircraft.o main.cpp
	g++ -o $@ $(CPPFLAGS) Aircraft.o Airport.o CargoAircraft.o Hangar.o PassengerAircraft.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
