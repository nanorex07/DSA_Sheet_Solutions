#include <bits/stdc++.h>
using namespace std;

// Given an array arr[] consisting of N integers and an integer K, the task is to find the array
// element closest to K. If multiple closest values exist, then print the smallest one


int solve(vector<int> &p, int k) {

    int lo = 0, hi = p.size()-1, mid;
    int small = -1, big = -1;
    while(lo <= hi) {
        mid = (hi+lo) >> 1;
        if (p[mid] <= k){
            small = mid;
            lo = mid+1;
        } 
        else{
            big = mid;
            hi = mid-1;
        }
    }
    int S = small == -1 ? INT_MAX : k-p[small];
    int B = big == -1 ? INT_MAX : p[big] - k;
    if (S < B) return p[small];
    if (S == B) return min(p[small], p[big]);
    return p[big];
}

int main () {
    vector<int> p = {4, 2, 8, 11, 7};
    sort(p.begin(), p.end());
    cout << solve(p,3) << endl;
}