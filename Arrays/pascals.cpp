#include <bits/stdc++.h>
using namespace std;
// pascals triangle
//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1

vector<vector<int>> pascals(int n) {
    vector<vector<int>> ret(n);
    for(int i = 0; i < n; i++) {
        ret[i].resize(i+1);
        ret[i][0] = ret[i][i] = 1;
        for(int j = 1; j < i; j++) {
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        }
    }
    return ret;
}

int main () {
    int n;
    cin >> n;
    auto ans = pascals(n);
    for(auto k: ans){
        for (auto i: k) cout << i << " ";
        cout << endl;
    }
}