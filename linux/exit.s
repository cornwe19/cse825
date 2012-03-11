######testshell.s#######
#assembly code for exit() system call, AT&T/Linux
 
.section .data
.section .text
 
.globl _start
 
_start:
   xor %eax, %eax
   or $1, %eax          #move 1 into %eax
   xor %ebx, %ebx       #move 0 into %ebx (xor to prevent null bytes)
   int $0x80            #interupt 0x80
