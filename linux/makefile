bof: bof.c
	gcc bof.c -g -fno-stack-protector -o bof

shellasm: shellspawn.s
	as -g -o shellspawn.o shellspawn.s
	ld -o shellspawn shellspawn.o

exit: exit.s
	as -g -o exit.o exit.s
	ld -o exit.out exit.o

shellspawn: shellspawn.c
	gcc shellspawn.c -static -ggdb -fno-stack-protector -o shellspawn

test: test.c
	gcc -g -fno-stack-protector -o test test.c
	execstack -s test

clean:
	rm -f bof test shellspawn 
