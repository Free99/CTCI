#include <iostream>
#include <cstring>
using namespace std;

void zero(int **a, int m, int n){
    bool row[m], col[n];    
    memset(row, false, sizeof(int) * m);
    memset(col, false, sizeof(int) * n); 
    
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            if( *((int*)a + n*i + j) == 0){
                row[i] = true;
                col[j] = true;
            }

    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            if(row[i] || col[j])
                *((int*)a + n*i + j) = 0;
}

int main() {
    int a[4][4] = {
        {1, 2, 3, 4},
        {5, 0, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    int m = 4, n = 4;
    zero((int**)a, m, n);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}

