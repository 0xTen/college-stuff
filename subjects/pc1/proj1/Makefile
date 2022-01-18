OBJ = main.o control.o mem.o read.o logic.o out.o math.o
main: $(OBJ)
	cc -Wall $(OBJ) -o proj

main.o: main.c
	cc -c -Wall main.c

control.o: control.c control.h
	cc -c -Wall control.c

mem.o: mem.c mem.h
	cc -c -Wall mem.c

read.o: read.c read.h
	cc -c -Wall read.c

logic.o: logic.c logic.h
	cc -c -Wall logic.c

out.o: out.c out.h
	cc -c -Wall out.c

math.o: math.c math.h
	cc -c -Wall math.c

clean:
	rm proj *.o
