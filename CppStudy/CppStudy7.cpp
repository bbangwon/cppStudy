#include <iostream>
#include <string>

class string {
	char *str;
	int len;

public:
	string(char c, int n);	//문자 c가 n개 있는 문자열로 정의
	string(const char *s);
	string(const string &s);
	~string();

	void add_string(const string &s);	//str 뒤에 s를 붙인다.
	void copy_string(const string &s);	//str 에 s를 복사한다.
	int strlen();

	void print_string() {
		std::cout << str << std::endl;
	}
};

string::string(char c, int n)
{
	str = new char[n + 1];
	memset(str, 0x00, n + 1);
	memset(str, c, n);
	len = n;
}

string::string(const char *s)
{
	len = ::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len +1, s);
}

string::string(const string &s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
}

string::~string()
{
	if (str) delete [] str;
}

void string::add_string(const string &s)
{
	int newLen = len + s.len;
	char *newStr = new char[newLen + 1];
	memset(newStr, 0x00, newLen + 1);

	memcpy(newStr,str, len);
	memcpy(newStr + len, s.str, s.len);

	if (str) delete[] str;
	str = newStr;
	len = newLen;
}

void string::copy_string(const string &s)
{
	if (str) delete[] str;

	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
}

int string::strlen()
{
	return len;
}

int main()
{
	string s1("안녕하세요");
	string s2('a', 20);
	string s3{ s1 };

	s1.print_string();
	s2.print_string();
	s3.print_string();

	s2.add_string(s1);

	s1.print_string();
	s2.print_string();
	s3.print_string();

	s3.copy_string(s2);

	s1.print_string();
	s2.print_string();
	s3.print_string();
}