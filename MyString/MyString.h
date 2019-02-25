#pragma once
#include <iostream>
using namespace std;

// MyString class declaration goes here
// MyString; limited recreation of the string library class
// allows for relegation of c-string schenanigans to background

class MyString
{
	private:
		char * str;
	public:
		MyString();
		MyString(char * );
		MyString(const MyString&);
		~MyString();
		void operator = (const MyString &);
		MyString operator + (const MyString &);
		bool operator == (const MyString &);
		const char * c_str();
};

ostream & operator << (ostream &strm, MyString &out);