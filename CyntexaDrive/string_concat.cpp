#include <bits/stdc++.h>
using namespace std;

// hello
// world
// hweolrllod

string solve(string a, string b) {
    if (a.size() != b.size()) return "-1";
    int n = a.size();
    string res(2*n, ' ');
    for(int i = 0; i < 2*n; i+=2){
        res[i] = a[i/2];
        res[i+1] = b[i/2];
    }
    return res;
}

int main () {
    string a = "hello";
    string b = "world";
    string ans = solve(a, b);
    cout << ans << endl;
}