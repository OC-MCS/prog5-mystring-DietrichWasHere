// test driver code goes here
#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

// test MyString class
int main()
{
	MyString s1; // test string 1
	char cs1[11] = "aaaaaaaaaa"; // teste cstring 1
	cout << cs1 << endl;
	MyString s2(cs1); // test string 2
	cout << s2 << endl;
	MyString s3("rrrrrr");
	cout << s3 << endl;
	s2 = s3;
	cout << s2 << endl;
	s1 = s2 + s3;
	cout << s3 << endl;
	MyString s4;
	s1 = s2 + s4;
	cout << s1;
}