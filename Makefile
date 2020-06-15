
# Example Makefile 
CC=g++ -Wall 
CLIB=-lgps -lpthread

dcgps: dcgps.o gps-utils.o gpsprint.o
	$(CC) -o dcgps dcgps.o gps-utils.o gpsprint.o $(CLIB)

clean:
	rm -f *.o core.* dcgps
dcgps.o:
	$(CC) -c dcgps.cpp
gps-utils.o: 
	$(CC) -c gps-utils.cpp
gpsprint.o:
	$(CC) -c gpsprint.cpp
