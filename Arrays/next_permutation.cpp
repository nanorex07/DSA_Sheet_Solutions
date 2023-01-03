#include <bits/stdc++.h>
using namespace std;

// NOTES:
// next permutation
// s0: initialise i = -1
// s1: find right most i for which a[i] < a[i+1] if none 
// s2: from right find j for which a[j] > a[i], swap(j,i)
// s3: reverse i+1 to end

void next_perm(vector<int> &p) {
    int i = -1;
    int n = p.size();
    for(int x = n-2; x >= 0; x--){
        if (p[x] < p[x+1]){
            i = x;
            break;
        }
    }
    for(int x = n-1; x >= 0; x--){
        if(i != -1 && p[x] > p[i]){
            swap(p[i], p[x]);
            break;
        }
    }
    reverse(p.begin()+i+1, p.end());
}

int fact(int n) {
    if (n <= 1) return n;
    return n*fact(n-1);
}

int main () {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) p[i] = i+1;
    for(int i = 0; i < fact(n); i++) {
        for(int k: p) cout << k << " ";
        cout << endl;
        next_perm(p);
    }
}