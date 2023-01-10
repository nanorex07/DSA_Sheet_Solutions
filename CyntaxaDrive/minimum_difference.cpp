#include <bits/stdc++.h>
using namespace std;

// Given an unsorted array, find the minimum difference between any pair in the given
// array

int solve(vector<int> &p) {
    sort(p.begin(), p.end());
    int ans = INT_MAX;
    for(int i = 1; i < p.size(); i++)
        ans = min(ans, p[i]-p[i-1]);
    return ans==INT_MAX ? -1: ans;
}


int main () {
    vector<int> p = {30, 5, 20, 9};
    cout << solve(p) << endl;
}