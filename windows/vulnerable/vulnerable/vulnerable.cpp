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
	char buffer[720];
	int ebp;
	ebp = get_ebp();
	
	cout << "Before strcpy..." << endl << endl;

	strcpy(buffer, argv[1]);

	*((int *) (ebp + 4)) = (long) &buffer;

	//cout << "BuffAddr: " << hex << &buffer << endl;
	//cout << "EBPAddr: " << hex << &ebp << endl;
	//cout << "EBPSize: " << sizeof(ebp) << endl;
	//ebp = get_ebp();
	//cout << "EBP: " << hex << ebp << endl;

	cout << "After strcopy..." << endl;

	return 0;
}

