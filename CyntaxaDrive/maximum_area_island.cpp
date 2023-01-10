#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,1,-1};

bool valid(int i, int j, vector<vector<int>> &grid){
    if (i < 0 || i >= grid.size()) return false;
    if (j < 0 || j >= grid[0].size()) return false;
    if (grid[i][j] != 1) return false;
    return true;
}

void dfs(vector<vector<int>> &grid, int i, int j, int &t) {
    grid[i][j] = 2;
    t++;
    for(int k = 0; k < 4; k++)
        if ( valid(i + dx[k],j + dy[k],grid) ) 
            dfs(grid, i + dx[k], j + dy[k], t); 
}


int main() {
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    int ans = INT_MIN;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if (grid[i][j] == 1){
                int t = 0;
                dfs(grid, i, j, t);
                ans = max(ans, t);
            }
        }
    }
    if (ans == INT_MIN) cout << 0 << endl;
    else
        cout << ans << endl;
    return 0;
}