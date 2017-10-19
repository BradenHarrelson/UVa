//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Ordering Tasks : 10305 : Brayzen
//
//Data structure required : Vector
//
//Tricks of the trade : topilogical sort with DFS
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
vi ts;
vi dfs_num;
//DFS algorithm from green book
void dfs(int u, vector<vi> adj){
	dfs_num[u] = 1;
	for (int j = 0; j < (int)adj[u].size(); j++){
		int v = adj[u][j];
		if (dfs_num[v] == -1) dfs(v, adj);
	}
	ts.push_back(u);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k, j;
	//fill adj list
	while (cin >> n >> m && n != 0){
		vector<vi> adj(n + 1);
		for (int i = 0; i < m; i++){
			cin >> k >> j;
			adj[k].push_back(j);
		}
		ts.clear();
		dfs_num.clear();
		dfs_num.resize(n + 1, -1);
		//call DFS and fill ts vector with the order
		for (int i = 1; i < n + 1; i++) {
			if (dfs_num[i] == -1) {
				dfs(i, adj);
			}
		}
		//output in reverse
		cout << ts[ts.size() - 1];
		for (int i = (int)ts.size() - 2; i >= 0; i--) {
			cout << " " << ts[i];
		}
		cout << "\n";
	}
	return 0;
}