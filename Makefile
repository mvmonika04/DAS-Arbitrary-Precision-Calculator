
CC = gcc
CFLAGS = -Wall -Wextra

OBJ = main.o addition.o subttraction.o multiplication.o division.o validation.o calc_function.o  

calc.out: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c calc.h
	$(CC) $(CFLAGS) -c $< -o $@

addition.o: addition.c calc.h
	$(CC) $(CFLAGS) -c $< -o $@

subttraction.o: subttraction.c calc.h
	$(CC) $(CFLAGS) -c $< -o $@

multiplication.o: multiplication.c calc.h
	$(CC) $(CFLAGS) -c $< -o $@

division.o: division.c calc.h
	$(CC) $(CFLAGS) -c $< -o $@

validation.o: validation.c calc.h
	$(CC) $(CFLAGS) -c $< -o $@

calc_function.o: calc_function.c calc.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f *.o calc.out

.PHONY: clean

