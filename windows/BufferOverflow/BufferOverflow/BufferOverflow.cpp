// BufferOverflow.cpp : Defines the entry point for the console application.
//
//
//#include "stdafx.h"
//
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

#include<iostream>
#include<fstream>

using namespace std;

/* THIS CODE WORKS

void function(int a, int b, int c) {
	char buffer[8];
	long *address_of_return;
	long *ebp;

	for(int i = 0; i < 8; i++)
	{
		buffer[i] = '\x88';
	}

	ebp = (long *)(buffer + 16);
	ebp += 16;
	cout << &buffer << endl;
	address_of_return = (long *)(buffer + 20); //20 bytes since it's in parens with a char
	cout << hex << *address_of_return << endl;
	*address_of_return += 35; //35 bytes since it's adding to the value of the address
	cout << hex << *address_of_return << endl;
	printf("entering function...\n");
	printf("leaving function\n");
}

int main() {
	int x;
	printf("entering main...\n");
	x = 0;
	printf("x = %d\n", x);
	function(1, 16, 16*16);
	printf("before x = 1...\n");
	x = 1;
	printf("after x = 1\n");
	printf("x = %d\n", x);
	printf("leaving main\n");

	return 0;
}*/

void GetInput(char *filename)
{
	char buffer[324];
	ifstream file(filename);
	cout << sizeof(filename) << endl;
	file >> buffer;
}

int main(int argc, char **argv)
{
	GetInput(argv[1]);

	cout << "Didn't break" << endl;

	return 0;
}