#include <bits/stdc++.h>
#define N 2
using namespace std;

int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

bool isSafe(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < N);
}

class Node {
public:

	Node* parent;
	int mat[N][N];
	int cost, level;
	int x,y;

	Node(int mat[N][N], int x, int y, int nx, int ny, int level, Node* parent) {
		memcpy(this->mat, mat, sizeof(this->mat));
		this->parent = parent;
		swap(this->mat[x][y], this->mat[nx][ny]);
		cost = INT_MAX;
		this->level = level;
		this->x = nx, this->y = ny;
	}
	void print_mat() {
		for(int i = 0; i < N; i++){
			for (int j = 0; j < N; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}
	}
	void calc_cost(int final[N][N]) {
		cost = 0;
		for(int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (mat[i][j] && mat[i][j] != final[i][j]) cost++;
	}
};
struct comp {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};
void printPath(Node* root) {
    if (root == nullptr)
        return;
    printPath(root->parent);
    root->print_mat();
    cout << endl;
}
void solve(int initial[N][N], int final[N][N], int x, int y) {

	priority_queue<Node*, vector<Node*>, comp> pq;
	Node* root = new Node(initial, x, y, x, y, 0, nullptr);
	root->calc_cost(final);
	pq.push(root);
	while(!pq.empty()) {
		Node* min = pq.top(); pq.pop();
		if (min->cost == 0) {
			printPath(min);
			return;
		}
		for (int i = 0; i < 4; i++) {
			if (isSafe(min->x + row[i], min->y + col[i])) {
				Node* child = new Node(min->mat, min->x, min->y, min->x + row[i], min->y + col[i], min->level+1, min);
				child->calc_cost(final);
				pq.push(child);
			}
		}
	}
}
int main() {
	int initial[N][N] = {
		{0,3},
		{2,1},
	};
	// int initial2[N][N] = {
	// 	{6,7,1},
	// 	{3,2,9},
	// 	{4,5,0}
	// };
	int final[N][N] = {
		{1,2},
		{3,0}
	};
	solve(initial, final, 0, 0);
	cout << endl;
}