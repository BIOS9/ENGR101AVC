OUT= E101AVC.a
ODIR= build
SDIR= src
CC= g++
CFLAGS= -Wall
_OBJS= main.o camera.o logger.o motors.o network.o

OBJS= $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS) -le101

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o
