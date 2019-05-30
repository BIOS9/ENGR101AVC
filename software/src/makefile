main: main.o logger.o motors.o network.o camera.o 
	c++ -o main main.o camera.o logger.o motors.o network.o -le101
main.o: main.cpp
	c++ -c main.cpp
logger.o: logger.cpp
	c++ -c logger.cpp 
camera.o: camera.cpp
	c++ -c camera.cpp
motors.o: motors.cpp
	c++ -c motors.cpp
network.o: network.cpp
	c++ -c network.cpp
clean:
	rm *.o
