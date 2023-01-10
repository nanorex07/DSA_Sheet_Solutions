#include <bits/stdc++.h>
using namespace std;

// Get Leap Years from array

vector<int> solve(vector<int> &years) {
    vector<int> ans;
    for(int year: years) 
        if ((year%4==0 && year%100 != 0) || (year%4==0 && year%100==0 && year%400==0)) 
            ans.push_back(year);
    return ans;
}

int main () {
    vector<int> years = {2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012};
    for (int year: solve(years))
        cout << "[+] " << year << endl;
}