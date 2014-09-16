#include <iostream>
#include <cstring>
using namespace std;

bool isUnique1(string s) {
    bool a[256];
    memset(a, 0, sizeof(a));
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        int v = (int) s[i];
        if (a[v]) return false;
        a[v] = true;
    }
    return true;
}

// For ASCII, we need 256 bit to store the info. 
// So that a int array with length 8 will be good.
// To map the character to the right number.
// For example, 'b' has the code 98.
// We use 98 / 32 to get the suffix of the array.
// We use 98 % 32 to get the place where we should set to 1.

bool isUnique2(string s) {
    int a[8];
    memset(a, 0, sizeof(a));
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        int v = (int) s[i];
        int idx = v / 32, shift = v % 32;
        if (a[idx] & (1 << shift)) return false;
        a[idx] |= (1 << shift);
    }
}


