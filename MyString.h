#include <string>
#include <iostream>
class MyString
{
private:
	char* _data;
	int _size;
	size_t _capacity;
	bool _isNull;
	bool _isEmpty;
public:
	int size() const;
	int capacity() const;
	bool empty() const;
	MyString();
	MyString(const char* str, int len = -1);
	MyString(std::string& str, int len = -1);
	MyString(MyString& str, int len = -1);
	MyString(int count, char ch);
	~MyString();
	void clear();
	void shrink_to_fit();
	const char* c_str() const;
	friend std::ostream& operator<<(std::ostream& os, MyString& c);
	MyString& operator=(const char* str);
	MyString& operator=(std::string& str);
	MyString& operator=(MyString& str);
	MyString& operator=(char ch);
	void insert(int index, int count, char ch);
	void insert(int index, const char* str, int len = -1);
	void insert(int index, std::string& str, int len = -1);
	void insert(int index, MyString& str, int len = -1);
	void insert(int index, const char* str, int s_index, int len);
	void insert(int index, std::string& str, int s_index, int len);
	void insert(int index, MyString& str, int s_index, int len);
	void append(int count, char ch);
	void append(const char* str, int len = -1);
	void append(std::string& str, int len = -1);
	void append(MyString& str, int len = -1);
	void append(const char* str, int s_index, int len);
	void append(std::string& str, int s_index, int len);
	void append(MyString& str, int s_index, int len);
	//friend istream& operator<<(istream& is, MyString&, c);
};