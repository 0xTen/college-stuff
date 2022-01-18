OBJ = main.o err.o validate.o in.o crack.o out.o
main: $(OBJ)
	$(CC) $(OBJ) -o proj

main.o: main.c
	$(CC) -c main.c

err.o: err.c err.h
	$(CC) -c err.c

validate.o: validate.c validate.h
	$(CC) -c validate.c

in.o: in.c in.h
	$(CC) -c in.c

crack.o: crack.c crack.h
	$(CC) -c crack.c

out.o: out.c out.h
	$(CC) -c out.c

clean:
	rm proj *.o