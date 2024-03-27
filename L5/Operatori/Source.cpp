#include <string>
#include <iostream>
using namespace std;

#pragma warning (disable:4996)

class String {
    string data;
public:
    String();
    String(int nr);
    String(const char* data);
    String(const String& other);
    ~String();

    String operator+(const String& other);
    String operator+(const char* data);
    String operator+(int other);


    String operator*(const String& other);
    String operator*(const char* data);
    String operator*(int times);

    operator int();
    String operator()(int base);
    String operator()(int start, int size);
    char& operator [](int idx);

    friend ostream& operator<<(ostream& os, const String& param);
};

String::String()
{
    data = "";
}

String::String(int nr)
{
    data = to_string(nr);
}

String::String(const char* data) 
{
    this->data = data;
}

String::String(const String& other) 
{
    data = other.data;
}

String::~String(){
}

String String::operator+(const String& other)
{
    String new_one;
    new_one.data = this->data;
    new_one.data += other.data;
    return new_one;
}

String String::operator+(const char* other)
{
    String new_one;
    new_one.data = this->data;
    new_one.data += other;
    return new_one;
}

String String::operator+(int other)
{
    String new_one;
    new_one.data = this->data;
    this->data += to_string(other);
    return new_one;
}

String String::operator*(const String& other)
{
    String new_one;
    int times = atoi(other.data.c_str());
    for (int i = 0; i < times; i++)
        new_one.data += this->data;    
    return new_one;
}

String String::operator*(const char* other)
{
    String new_one;
    int times = atoi(other);
    for (int i = 0; i < times; i++)
        new_one.data += this->data;
    return new_one;
}

String String::operator*(int times)
{
    String new_one;
    for (int i = 0; i < times; i++)
        new_one.data += this->data;
    return new_one;
}

ostream& operator<<(ostream& os, const String& param)
{
    os << param.data;
    return os;
}

String::operator int(void)
{
    return atoi(data.c_str());
}

char& String::operator [](int idx){
    return data[idx];
}

String String::operator()(int base)
{
    String result;
    char buffer[100] = { 0 };

    for (int i = 0; i < this->data.size(); i++)
    {
        itoa((int)this->data[i], buffer, base);
        result = result + String(buffer) + " ";
    }

    return result;
}

String String::operator()(int start, int size)
{
    String result;
    result.data = this->data.substr(start, size);
    return result;
}

int main()
{
    String s1 = "He";
    String s2 = "l";
    String s3 = String(0) * 2;
    String s4 = "P";
    String s5 = s1 + s2 * 2 + s3 + " World of " + s4 + s3 + "!";
    int val = (int)s3;
    String s6;
    s6 = s1;
    s6 = s6 + s2 + s4 + "!";
    String s7 = s5(2);
    String s8 = s5(10);
    String s9 = s5(16);

    cout << s5 << endl;
    cout << s3 << " = " << val << endl;
    cout << s6 << endl;
    cout << s7 << endl;
    cout << s8 << endl;
    cout << s9 << endl;

    char c1 = s5[7];
    char c2 = s3[1];
    char c3 = s5[7];
    cout << c1 << c2 << c2 << c3 << endl;

    String s10 = s5(0, 10);
    s10[0] = s5[7];
    s10[4] = 32;
    s10[5] = 'd';
    s10[6] = s5[8];
    s10[7] = 'n';
    s10[8] = s5[1];
    s10[9] = s5[19];
    cout << s10 << endl;

    return 0;
}
