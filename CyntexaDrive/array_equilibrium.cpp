#include <bits/stdc++.h>
using namespace std;

// Write a program to find the equilibrium index of an array. The equilibrium index of an
// array is an index such that the sum of elements at lower indexes is equal to sum of
// elements at higher index

int solve(vector<int> &p) {
    for(int i = 1; i < p.size(); i++)
        p[i] += p[i-1];
    for(int i = 1; i < p.size(); i++)
        if (p[i-1] == p.back() - p[i])
            return i;
    return -1;
}


int main () {
    vector<int> p = {-7, 1, 5, 2, -4, 3, 0};
    cout << solve(p) << endl;
}