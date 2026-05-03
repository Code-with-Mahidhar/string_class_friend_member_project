


#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char* str;
public:
    // Default constructor
    MyString() {
        str = new char[1];
        str[0] = '\0';
    }

    // Parameterized constructor
    MyString(const char* s) {
        str = new char[strlen(s)+1];
        strcpy(str, s);
    }

    // Copy constructor
    MyString(const MyString& s) {
        str = new char[strlen(s.str)+1];
        strcpy(str, s.str);
    }

    // Assignment operator
    MyString& operator=(const MyString& s) {
        if(this != &s) {
            delete[] str;
            str = new char[strlen(s.str)+1];
            strcpy(str, s.str);
        }
        return *this;
    }

    // + operator
    MyString operator+(const MyString& s) {
        MyString temp;
        delete[] temp.str;
        temp.str = new char[strlen(str)+strlen(s.str)+1];
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    // Comparison operators
    bool operator==(const MyString& s) { return strcmp(str, s.str)==0; }
    bool operator!=(const MyString& s) { return strcmp(str, s.str)!=0; }
    bool operator<(const MyString& s)  { return strcmp(str, s.str)<0; }
    bool operator>(const MyString& s)  { return strcmp(str, s.str)>0; }
    bool operator<=(const MyString& s) { return strcmp(str, s.str)<=0; }
    bool operator>=(const MyString& s) { return strcmp(str, s.str)>=0; }

    // Friend I/O operators
    friend ostream& operator<<(ostream& out, const MyString& s) {
        out << s.str;
        return out;
    }
    friend istream& operator>>(istream& in, MyString& s) {
        char buffer[100];
        in >> buffer;
        delete[] s.str;
        s.str = new char[strlen(buffer)+1];
        strcpy(s.str, buffer);
        return in;
    }

    ~MyString() { delete[] str; }
};

int main() {
    MyString s1("Hello"), s2("World");
    MyString s3 = s1 + s2;
    cout << "Concatenation: " << s3 << endl;

    cout << "Comparison == : " << (s1==s2) << endl;
    cout << "Comparison != : " << (s1!=s2) << endl;
    cout << "Comparison <  : " << (s1<s2) << endl;
    cout << "Comparison >  : " << (s1>s2) << endl;

    MyString s4;
    cout << "Enter a string: ";
    cin >> s4;
    cout << "You entered: " << s4 << endl;

    return 0;
}


