#include <bits/stdc++.h>
using namespace std;

//  Write a program to reverse the given string while preserving the position of spaces

string solve(vector<string> &arr) {
    sort(arr.begin(), arr.end());
    string pref = "";
    int i = 0, j = 0;
    while(i < arr[0].size() && j < arr.back().size() && arr[0][i] == arr.back()[j]){
        pref.push_back(arr[0][i]);
        i++;
        j++;
    }
    return pref;
}

int main () {
    vector<string> arr = {"flower","flow","flight"};
    cout << solve(arr) << endl;
    
}