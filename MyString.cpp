#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <string>
#include <iostream>

int MyString::size() const {
    return _size;
}

int MyString::capacity() const {
    return _capacity;
}

bool MyString::empty() const
{
    return _isEmpty;
}

MyString::MyString()
    : _data(nullptr), _size(0), _capacity(0),
    _isNull(true), _isEmpty(true)
{
}

const char* MyString::c_str() const{
    if (_isNull)
        return "";
    return _data;
}

MyString::MyString(const char* str, int len)
{
    if (len < 0) len = strlen(str);
    _data = new char[len + 1];
    strncpy(_data, str, len);
    _data[len] = '\0';
    _size = len;
    _capacity = len + 1;
    _isNull = false;
    _isEmpty = (len == 0);
}
MyString::MyString(std::string& str, int len) 
    : MyString(str.c_str(), len)
{
}

MyString::MyString(MyString& str, int len)
    : MyString(str.c_str(), len)
{
}
MyString::MyString(int count, char ch)
{
    if (count < 0) count = 0;
    _data = new char[count + 1];
    for (int i = 0; i < count; i++) _data[i] = ch;
    _data[count] = '\0';
    _size = count;
    _capacity = count + 1;
    _isNull = false;
    _isEmpty = (count == 0);
}
MyString::~MyString() {
    delete[] _data;
}

std::ostream& operator<<(std::ostream& os, MyString& str)
{
    return os << str.c_str();
}

void MyString::clear() {
    if (_data) _data[0] = '\0';
    _size = 0;
    _isEmpty = true;
    _isNull = false;
}

void MyString::shrink_to_fit() 
{
    if (_size + 1 < _capacity) 
    {
        char* newData = new char[_size + 1];
        if (_data)
        {
            strncpy(newData, _data, _size);
            newData[_size] = '\0';
            delete[] _data;
        }
        _data = newData;
        _capacity = _size + 1;
    }
}

MyString& MyString::operator=(const char* str)
{
    delete[] _data;
    if (!str)
    {
        _data = nullptr;
        _size = 0;
        _capacity = 0;
        _isNull = true;
        _isEmpty = true;
        return *this;
    }
    _size = strlen(str);
    _capacity = _size + 1;
    _data = new char[_capacity];
    _data = strcpy(_data, str);
    _data[_size] = '\0';
    _isNull = false;
    _isEmpty = (_size == 0);
    return *this;
}
MyString& MyString::operator=(std::string& str)
{
    *this = str.c_str();
    return *this;
}
MyString& MyString::operator=(MyString& str)
{
    *this = str.c_str();
    return *this;
}
MyString& MyString::operator=(char ch)
{
    delete[] _data;
    _size = 1;
    _capacity = 2;
    _data = new char[_capacity];
    _data[0] = ch;
    _data[1] = '\0';
    _isNull = false;
    _isEmpty = false;
    return *this;
}

void MyString::insert(int index, int count, char ch)
{
    if (count <= 0) return;
    char* newStr = new char[count+1];
    for (int i = 0; i < count; i++) newStr[i] = ch;
    newStr[count] = '\0';
    insert(index, newStr);
    delete[] newStr;
}
void MyString::insert(int index, const char* str, int s_index, int len)
{
    if (!str) return;
    int strLen = strlen(str);
    if (s_index < 0) s_index = 0;
    if (s_index > strLen) s_index = strLen;
    if (len < 0 || s_index + len > strLen) len = strLen - s_index;
    if (len <= 0) return;
    if (index < 0) index = 0;
    if (index > _size) index = _size;
    int newSize = _size + len;
    if (newSize + 1 > _capacity) 
    {
        char* newData = new char[newSize + 1];
        if (_data && index > 0) strncpy(newData, _data, index);
        strncpy(newData + index, str + s_index, len);
        if (_data && _size - index > 0) strncpy(newData + index + len, _data + index, _size - index);
        newData[newSize] = '\0';
        delete[] _data;
        _data = newData;
        _capacity = newSize + 1;
    }
    else 
    {
        for (int i = _size - 1; i >= index; --i) {
            _data[i + len] = _data[i];
        }
        strncpy(_data + index, str + s_index, len);
        _data[newSize] = '\0';
    }
    _size = newSize;
    _isEmpty = (_size == 0);
    _isNull = false;
}
void MyString::insert(int index, std::string& str, int s_index, int len)
{
    insert(index, str.c_str(), s_index, len);
}
void MyString::insert(int index, MyString& str, int s_index, int len)
{
    insert(index, str.c_str(), s_index, len);
}
void MyString::insert(int index, const char* str, int len)
{
    insert(index, str, 0, len);
}
void MyString::insert(int index, std::string& str, int len)
{
    insert(index, str.c_str(), 0, len);
}
void MyString::insert(int index, MyString& str, int len)
{
    insert(index, str.c_str(), 0, len);
}

void MyString::append(int count, char ch)
{
    insert(_size, count, ch);
}
void MyString::append(const char* str, int len)
{
    insert(_size, str, 0, len);
}
void MyString::append(std::string& str, int len)
{
    insert(_size, str.c_str(), 0, len);
}
void MyString::append(MyString& str, int len)
{
    insert(_size, str.c_str(), len);
}
void MyString::append(const char* str, int s_index, int len)
{
    insert(_size, str, s_index, len);
}
void MyString::append(std::string& str, int s_index, int len)
{
    insert(_size, str.c_str(), s_index, len);
}
void MyString::append(MyString& str, int s_index, int len)
{
    insert(_size, str.c_str(), s_index, len);
}
