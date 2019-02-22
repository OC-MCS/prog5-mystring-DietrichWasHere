#include "MyString.h"
#include <cstring>
// MyString implementation file
// default constructor
MyString::MyString()
{
	str = nullptr;
}
// Constructo that recieves c-string (char array)
MyString::MyString(char *nStr)
{
	str = new char[strlen(nStr) + 1];
	strcpy_s(str, strlen(nStr), nStr);
}
// copy constructor
MyString::MyString(const MyString& nStr)
{
	str = new char[strlen(nStr.str) + 1];
	strcpy_s(str, strlen(nStr.str), nStr.str);
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
		strcpy_s(str, strlen(other.str), other.str);
	}
}
// concatenate two MyStrings, return the new MySttring
MyString MyString::operator + (const MyString & other)
{
	MyString nStr;
	nStr.str = new char[strlen(str) + strlen(other.str) + 1];
	strcpy_s(nStr.str, strlen(str) + strlen(other.str) + 1, str);
	strcpy_s(nStr.str, strlen(str) + strlen(other.str) + 1, other.str);
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
const char * MyString::c_str()
{
	return str;
}