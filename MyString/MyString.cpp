#include "MyString.h"
#include <cstring>
using namespace std;
// MyString implementation file
// default constructor

MyString::MyString()
{
	str = nullptr;
}

// Constructor that recieves c-string (char array)
MyString::MyString(const char * nStr)
{
	if (nStr != nullptr)
	{
		str = new char[strlen(nStr) + 1];
		strcpy_s(str, strlen(nStr) + 1, nStr);
	}
	else nStr = nullptr;
}
// copy constructor
MyString::MyString(const MyString& oStr)
{
	if (oStr.str != nullptr)
	{
		str = new char[strlen(oStr.str) + 1];
		strcpy_s(str, strlen(oStr.str) + 1, oStr.str);
	}
	else str = nullptr;
}
// destructor
MyString::~MyString()
{
	delete[] str;
}
// set one MyString to the value of another
MyString MyString::operator = (const MyString &other)
{
	if ((this != &other) && (other.str != nullptr))
	{
		delete[] str;
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str) + 1, other.str);
	}
	else if (other.str == nullptr) str = nullptr;
	return other;
}
// concatenate two MyStrings, return the new MySttring
MyString MyString::operator + (const MyString & other)
{
	MyString nStr;
	if ((str != nullptr) && (other.str != nullptr))
	{
		nStr.str = new char[strlen(str) + strlen(other.str) + 1];
		strcpy_s(nStr.str, strlen(str) + 1, str);
		strcat_s(nStr.str, strlen(str) + strlen(other.str) + 1, other.str);
	}
	else if (other.str != nullptr)
	{
		nStr.str = new char[strlen(other.str) + 1];
		strcpy_s(nStr.str, strlen(other.str) + 1, other.str);
	}
	else if (str != nullptr)
	{
		nStr.str = new char[strlen(str) + 1];
		strcpy_s(nStr.str, strlen(str) + 1, str);
	}
	else nStr.str = nullptr;
	return nStr;
}
// test if two myStrigns are equal, return bool indicating truth of satement
bool MyString::operator == (const MyString & other)
{
	bool equal = false;
	if (strcmp(str, other.str)) equal = true;
	return equal;
}
// get the value of the c-string pointer, for overloaded << operator
char * MyString::c_str() const
{
	return str;
}
// use << operator to displat MyString's c-string
ostream & operator << (ostream &strm, const MyString &out)
{
	if (out.c_str() != nullptr) strm << out.c_str();
	return strm;
}