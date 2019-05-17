BUILDDIR=build/
SRCDIR=src/

E101AVC: main.o camera.o logger.o motors.o
	g++ -Wall -o E101AVC $(BUILDDIR)main.o $(BUILDDIR)camera.o $(BUILDDIR)logger.o $(BUILDDIR)motors.o -le101

main.o: main.cpp
	g++ -Wall -c $(SRCDIR)main.cpp

camera.o: camera.cpp camera.h
	g++ -Wall -c $(SRCDIR)camera.cpp

logger.o: logger.cpp logger.h
	g++ -Wall -c $(SRCDIR)logger.cpp

motors.o: motors.cpp motors.h
	g++ -Wall -c $(SRCDIR)motors.cpp

.PHONY: clean
clean:
	rm $(BUILDDIR)*.o