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
	str = new char[strlen(nStr) + 1];
	strcpy_s(str, strlen(nStr) + 1, nStr);
}
// copy constructor
MyString::MyString(const MyString& oStr)
{
	str = new char[strlen(oStr.str) + 1];
	strcpy_s(str, strlen(oStr.str) + 1, oStr.str);
}
// destructor
MyString::~MyString()
{
	delete[] str;
}
// set one MyString to the value of another
void MyString::operator = (const MyString &other)
{
	if (this != &other)
	{
		delete[] str;
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str) + 1, other.str);
	}
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
	else if (str == nullptr)
	{
		nStr.str = new char[strlen(other.str) + 1];
		strcpy_s(nStr.str, strlen(other.str) + 1, other.str);
	}
	else
	{
		nStr.str = new char[strlen(str) + 1];
		strcpy_s(nStr.str, strlen(str) + 1, str);
	}
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
	strm << out.c_str();
	return strm;
}