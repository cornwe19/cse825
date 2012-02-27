bof: bof.c
	gcc bof.c -g -fno-stack-protector -o bof

shelloverflow: shelloverflow.c
	gcc shelloverflow.c -g -fno-stack-protector -o shelloverflow

shellasm: shellspawn.s
	as -g -o shellspawn.o shellspawn.s
	ld -o shellspawn shellspawn.o

shellspawn: shellspawn.c
	gcc shellspawn.c -static -ggdb -fno-stack-protector -o shellspawn

bof-asm: bof.c
	gcc bof.c -fno-stack-protector -S -o bof.s -masm=intel

test: test.c
	gcc -g -fno-stack-protector -o test test.c
	execstack -s test

clean:
	rm -f bof.s bof test shelloverflow shellasm shellspawn vulnerable
