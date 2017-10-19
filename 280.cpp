//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Vertex : 280 : Brayzen
//
//Data structure required : Vectors, queue
//
//Tricks of the trade :
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int nodes;
	//insert nodes into adjacency list
	while (cin >> nodes && nodes != 0){
		vector<vector<int> > adj(nodes + 1);
		int num = 1;
		int vertex;
		while (cin >> vertex && vertex != 0){
			while (cin >> num && num != 0){
				adj[vertex].push_back(num);
			}
		}
		cin >> num;
		for (int i = 0; i < num; i++){
			int vertex;
			cin >> vertex;
			//Use BFS from green book to find unreachable nodes
			//0 is unvisited (white)
			vector<int> d(nodes + 1, 0);
			queue<int> q;
			int u;
			q.push(vertex);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int j = 0; j < (int)adj[u].size(); j++) {
					int v = adj[u][j];
					//set to 1 (black) when visited
					if (d[v] == 0) {
						d[v] = 1;
						//push adj nodes to bfs
						q.push(v);
					}
				}
			}
			//use vector to count number of unreachables
			vector<int> unreachables;
			for (int j = 1; j < nodes + 1; j++) {
				if (d[j] == 0) {
					unreachables.push_back(j);
				}
			}
			//output
			cout << unreachables.size();
			for (int j = 0; j < unreachables.size(); j++) {
				cout << " " << unreachables[j];
			}
			cout << "\n";
		}
	}
	return 0;
}