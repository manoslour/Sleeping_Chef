all: demo

demo: takeaway.o functions.o
	gcc -pthread takeaway.o functions.o -o demo

takeaway.o: takeaway.c functions.h
	gcc -c takeaway.c

functions.o: functions.c functions.h
	gcc -c functions.c

clean:
	rm *.o demo