#include <bits/stdc++.h>
using namespace std;

// 1 1 1 1 1
// 2 2 1 1 1
// 3 3 3 1 1
// 4 4 4 4 1
// 5 5 5 5 5

void pattern(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            cout << i << " ";
        for(int j = 1; j <= n-i; j++)
            cout << 1 << " ";
        cout << endl;
    }
}

int main () {
    int n = 15;
    pattern(n);
}