#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicate1(char s[]) {
    int len = strlen(s);
    if (len < 2) return;
    int p = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] != '\0') {
            s[p++] = s[i];
            for (int j = i + 1; j < len; ++j)
                if (s[j] == s[i])
                    s[j] = '\0';
        }
    }
    s[p] = '\0';
}

void removeDuplicate2(char s[]) {
    int len = strlen(s);
    if (len < 2) return;
    bool c[256];
    memset(c, 0, sizeof(c));
    int p = 0;
    for (int i = 0; i < len; ++i) {
        if (!c[s[i]]) {
            s[p++] = s[i];
            c[s[i]] = true;
        }
    }
    s[p] = '\0';
}

void removeDuplicate3(char s[]) {
    int len = strlen(s);
    if (len < 2) return;
    int check = 0, p = 0;
    for (int i = 0; i < len; ++i) {
        int v = (int) (s[i] - 'a');
        if ((check & (1 << v)) == 0 ) {
            s[p++] = s[i];
            check |= (1 << v);
        }
    }
    s[p] = '\0';
}

string removeDuplicate4(string s) {
    int len = s.length();
    if (len < 2) return s;
    string str = "";
    for (int i = 0; i < len; ++i) {
        if (s[i] != '\0') {
            str += s[i];
            for (int j = i + 1; j < len; ++j){
                if (s[j] == s[i]) s[j] = '\0';
            }
        }
    }
    return str;
}

string removeDuplicate5(string s) {
    int check = 0;
    int len = s.length();
    if (len < 2) return s;
    string str = "";
    for (int i = 0; i < len; ++i) {
        int v = (int)(s[i] - 'a');
        if ((check & (1 << v)) == 0) {
            str += s[i];
            check |= (1 << v);
        }
    }
    return str;
}

int main() {
    string s1 = "abcde";
    string s2 = "aaabbb";
    string s3 = "";
    string s4 = "abababac";
    string s5 = "ccccc";
    cout << removeDuplicate4(s1) << " " << removeDuplicate5(s1) << endl;
    cout << removeDuplicate4(s2) << " " << removeDuplicate5(s2) << endl;
    cout << removeDuplicate4(s3) << " " << removeDuplicate5(s3) << endl;
    cout << removeDuplicate4(s4) << " " << removeDuplicate5(s4) << endl;
    cout << removeDuplicate4(s5) << " " << removeDuplicate5(s5) << endl;

    char ss1[] = "abcde";
    char ss2[] = "aaabbb";
    char ss3[] = "";
    char ss4[] = "abababc";
    char ss5[] = "ccccc";
    removeDuplicate3(ss1);
    removeDuplicate3(ss2);
    removeDuplicate3(ss3);
    removeDuplicate3(ss4);
    removeDuplicate3(ss5);
    cout << ss1 << " " << ss2 << " " << ss3 << " " 
         << ss4 << " " << ss5 << endl;
    return 0;
}
