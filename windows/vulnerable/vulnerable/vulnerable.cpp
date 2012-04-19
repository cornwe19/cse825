// vulnerable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<cstdlib>
#include<iostream>
#include<stdio.h>

using namespace std;

int main(int argc, char *argv[])
{	
	char buffer[64];

	strcpy(buffer, argv[1]);
	
	cout << "Hello " << buffer << "!" << endl;

	return 0;
}

