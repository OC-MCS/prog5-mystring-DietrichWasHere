// test driver code goes here
#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

// test MyString class
int main()
{
	MyString s1; // test string 1
	cout << "String 1:" << s1 << endl;
	char cs1[11] = "aaaaaaaaaa"; // teste cstring 1
	MyString s2(cs1); // test string 2
	cout << s2;
}