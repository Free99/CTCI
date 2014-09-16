#include <iostream>
#include <stack>
using namespace std;

void hanoi_recursion(int n, char src, char bri, char dst) {
    if (n == 1) {
        cout << "Move disk " << n << " from " 
             << src << " to " << dst << endl; 
    } else {
        hanoi_recursion(n-1, src, dst, bri);
        cout << "Move disk " << n << " from "
             << src << " to " << dst << endl;
        hanoi_recursion(n-1, bri, src, dst);
    }
}

struct op {
    int begin, end;
    char src, bri, dst;
    op() {
    }
    op(int pbegin, int pend, int psrc, int pbri, int pdst):
    begin(pbegin), end(pend), src(psrc), bri(pbri), dst(pdst) {
    }
};

void hanoi(int n, char src, char bri, char dst) {
    stack<op> st;
    op tmp;
    st.push(op(1, n, src, bri, dst));
    while(!st.empty()) {
        tmp = st.top();
        st.pop();
        if (tmp.begin != tmp.end) {
            st.push(op(tmp.begin, tmp.end-1, tmp.bri, tmp.src, tmp.dst));
            st.push(op(tmp.end, tmp.end, tmp.src, tmp.bri, tmp.dst));
            st.push(op(tmp.begin, tmp.end-1, tmp.src, tmp.dst, tmp.bri));
        } else {
            cout << "Move disk " << tmp.begin << " from " 
                 << tmp.src << " to " << tmp.dst << endl;
        }
    }
}

int main() {
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
