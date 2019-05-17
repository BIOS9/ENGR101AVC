E101AVC: main.o camera.o logger.o
	g++ -Wall -o E101AVC main.o camera.o logger.o

main.o: main.cpp
	g++ -Wall -c main.cpp

camera.o: camera.cpp camera.h
	g++ -Wall -c camera.cpp

logger.o: logger.cpp logger.h
	g++ -Wall -c logger.cpp

clean:
	rm *.0