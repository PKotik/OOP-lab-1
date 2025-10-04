#include "MyString.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::string s_str = "hello_str";
	MyString str1;
	cout << str1.empty() << endl;
	str1 = "hello";
	cout << str1.empty() << endl;
	cout << str1 << endl;
	str1.insert(2, 10, '*');
	cout << str1 << endl;
	str1.insert(5, "123456789", 3,5);
	cout << str1 << endl;
	str1.insert(7, s_str, 5);
	cout << str1 << endl;
	str1 = s_str;
	cout << str1 << endl;
	MyString str2;
	str2 = str1;
	cout << str2 << endl;
	str2 = '!';
	cout << str2 << endl;
	str2.append(10, '#');
	cout << str2 << endl;
	str2.append("zapa");
	cout << str2 << endl;
	str2.append("zapa",2);
	cout << str2 << endl;
	str2.append("zapa", 2,2);
	cout << str2 << endl;
}