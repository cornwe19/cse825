bof: bof.c
	gcc bof.c -g -fno-stack-protector -o bof

shelloverflow: shelloverflow.c
	gcc shelloverflow.c -g -fno-stack-protector -o shelloverflow

shellasm: shellasm.c
	gcc shellasm.c -g -fno-stack-protector -o shellasm

shellspawn: shellspawn.c
	gcc shellspawn.c -static -g -fno-stack-protector -o shellspawn

bof-asm: bof.c
	gcc bof.c -fno-stack-protector -S -o bof.s -masm=intel

clean:
	rm -f bof.s bof shelloverflow shellasm shellspawn
