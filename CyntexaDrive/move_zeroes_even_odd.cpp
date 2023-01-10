#include <bits/stdc++.h>
using namespace std;

// Write a program to move all the zeros at the end and odd numbers at the start of the
// array and also arrange the even number in descending order.

void solve(vector<int> &p) {
    int n = p.size();
    int low = 0, high = n - 1, mid = 0;
    while(mid <= high) {
        if (p[mid]&1) swap(p[mid++], p[low++]);
        else if (p[mid] == 0) swap(p[mid], p[high--]);
        else mid++;
    }
    sort(p.begin()+low, p.begin()+mid, greater<int>());
}


int main () {
    vector<int> p = {0,3,4,0,5,6,2,1,9,0,8,7};
    solve(p);
    for (int k: p) cout << k << " ";
    cout << endl;
}