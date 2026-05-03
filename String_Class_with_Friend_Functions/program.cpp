


#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char str[100];
public:
    MyString() { str[0] = '\0'; }
    MyString(const char* s) { strcpy(str, s); }

    // Public accessor (optional)
    const char* getStr() const { return str; }

    // Overload << for printing
    friend ostream& operator<<(ostream& out, const MyString& s) {
        out << s.str;
        return out;
    }

    // Friend functions
    friend int strcmp(MyString s1, MyString s2) {
        return ::strcmp(s1.str, s2.str);
    }
    friend MyString strcat(MyString s1, MyString s2) {
        MyString temp;
        strcpy(temp.str, s1.str);
        ::strcat(temp.str, s2.str);
        return temp;
    }
    friend int strlen(MyString s) {
        return ::strlen(s.str);
    }
    friend MyString strcpy(MyString s1, MyString s2) {
        MyString temp;
        ::strcpy(temp.str, s2.str);
        return temp;
    }
    friend MyString strncpy(MyString s1, MyString s2) {
        MyString temp;
        ::strncpy(temp.str, s2.str, sizeof(temp.str));
        return temp;
    }
    friend void strrev(MyString s) {
        int n = ::strlen(s.str);
        for(int i=0; i<n/2; i++) {
            char t = s.str[i];
            s.str[i] = s.str[n-i-1];
            s.str[n-i-1] = t;
        }
        cout << s.str << endl;
    }
    friend void strupr(MyString s) {
        for(int i=0; s.str[i]; i++)
            s.str[i] = toupper(s.str[i]);
        cout << s.str << endl;
    }
    friend void strlwr(MyString s) {
        for(int i=0; s.str[i]; i++)
            s.str[i] = tolower(s.str[i]);
        cout << s.str << endl;
    }
    friend char* strchr(MyString s, char ch) {
        return ::strchr(s.str, ch);
    }
    friend char* strrchr(MyString s, char ch) {
        return ::strrchr(s.str, ch);
    }
    friend char* strstr(MyString s1, MyString s2) {
        return ::strstr(s1.str, s2.str);
    }
    friend char* strtok(MyString s, const char* delim) {
        return ::strtok(s.str, delim);
    }
};

int main() {
        MyString s1("Hello"), s2("World");
        cout << "strcmp: " << strcmp(s1, s2) << endl;
        cout << "strcat: " << strcat(s1, s2) << endl;   // uses operator<<
        cout << "strlen: " << strlen(s1) << endl;
        cout << "strcpy: " << strcpy(s1, s2) << endl;   // uses operator<<
        cout << "strncpy: " << strncpy(s1, s2) << endl; // uses operator<<
        cout << "strrev: "; strrev(s1);
        cout << "strupr: "; strupr(s1);
        cout << "strlwr: "; strlwr(s1);
        cout << "strchr: " << strchr(s1, 'e') << endl;
        cout << "strrchr: " << strrchr(s1, 'l') << endl;
        //    cout << "strstr: " << strstr(s1, s2) << endl;
        //    cout << "strtok: " << strtok(s1, "l") << endl;

        char* res = strstr(s1, s2);
        if(res != NULL)
                cout << "strstr: " << res << endl;
        else
                cout << "strstr: substring not found" << endl;

        char* tok = strtok(s1, "l");
        if(tok != NULL)
                cout << "strtok: " << tok << endl;
        else
                cout << "strtok: no token found" << endl;


        return 0;
}

