#include <bits/stdc++.h>
using namespace std;

//  Write a program to reverse the given string while preserving the position of spaces

void solve(string &a) {
    int i = 0;
    int n = a.size();
    for(int j = 0; j < n; j++){
        if (a[j] == ' ') {
            reverse(a.begin()+i, a.begin()+j);
            while(j < n && a[j]==' ') j++;
            i=j;
        }
    }
    if (a[n-1] == ' ') return;
    reverse(a.begin()+i, a.end());
}

int main () {
    string a = "hello     world   wf ";
    solve(a);
    cout << a << endl;
}