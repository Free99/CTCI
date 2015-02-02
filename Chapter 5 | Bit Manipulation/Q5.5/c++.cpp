#include <iostream>
using namespace std;

int count_one(int x) {
    int num = 0;
    while(x) {
        x &= (x-1);
        num++;
    }
    return num;
}

int convert_num(int a, int b) {
    return count_one(a^b);
}

int main() {
    int a = 7, b = 14;
    cout << convert_num(a, b) << endl;
    return 0;
}
