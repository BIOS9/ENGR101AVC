BD=build/
SD=src/

E101AVC: main.o camera.o logger.o motors.o
	g++ -Wall -o E101AVC $(BD)main.o $(BD)camera.o $(BD)logger.o $(BD)motors.o -le101

main.o: $(SD)main.cpp
	g++ -Wall -c $(SD)main.cpp

camera.o: $(SD)SD.cpp $(SD)camera.h
	g++ -Wall -c $(SD)camera.cpp

logger.o:$(SD)logger.cpp $(SD)logger.h
	g++ -Wall -c $(SD)logger.cpp

motors.o: $(SD)motors.cpp $(SD)motors.h
	g++ -Wall -c $(SD)motors.cpp

.PHONY: clean
clean:
	rm $(BD)*.o