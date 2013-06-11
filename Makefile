CC=mpicc
CFLAGS=-I.
DEPS = 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

broadcast: clean main.o 
	$(CC) -o  avg_var main.o -I.

clean:
	rm -rf *.o
