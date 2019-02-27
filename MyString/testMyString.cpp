// test driver code goes here
#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

void test1(MyString);
MyString test2();

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
	s3 = "eeeeeeeee";
	cout << s2 << endl;
	cout << s3 << endl;
	s1 = s2 + s3;
	cout << s1 << endl;
	s1 = s1;
	cout << s1 << endl;
	MyString s4; // test string 4
	s1 = s2 + s4;
	s2 = s4;
	cout << s1 << endl;
	cout << s2 << endl;
	s2 = "qqqqqqq";
	s1 = s4 = s2;
	s2 = "hhhhh";
	test1(s1);
	test1(s4);
	test1(s2);
	s2 = test2();
	test1(s2);
	// test nullptr protection
	MyString s5(nullptr);
	test1(s5);
	MyString s6(s5);
	test1(s6);
	MyString s7 = s6;
	test1(s7);
	s1 = s5 + s6;
	test1(s1);
	s1 = s2 + s5;
	test1(s1);
	s1 = s5 + s2;
	test1(s1);
}

// test for use of mystring as parameter
void test1(MyString str)
{
	cout << str << endl;
}
// test of mystring as return value
MyString test2()
{
	MyString nStr("yyyyyyyy");
	return nStr;
}