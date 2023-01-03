#include <bits/stdc++.h>
using namespace std;

// NOTES:
// Dutch National Flag 0,1,2
// low = 0, mid = 0, high = n-1;
// if mid == 0 , mid++, low++ swap(mid, low)
// if mid == 1 , mid++
// else mid == 2, high-- swap(mid, high); 

void dnf(vector<int> &p) {
    int low = 0, high = p.size() - 1, mid = 0;
    while(mid <= high) {
        if (p[mid] == 0) swap(p[mid++], p[low++]);
        else if (p[mid] == 2) swap(p[mid], p[high--]);
        else mid++;
    }
}

int fact(int n) {
    if (n <= 1) return n;
    return n*fact(n-1);
}

int main () {
    vector<int> p = {2,2,2,2,0,1,1,0,0};
    dnf(p);
    for(int k: p) cout << k << " ";
        cout << endl;

}