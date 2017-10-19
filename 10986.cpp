//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Sending Email : 10986 : Brayzen
//
//Data structure required : Vector, priority_queue
//
//Tricks of the trade :
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <climits>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	typedef pair<int, int> ii;
	int cases, ct = 1;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int n, m, S, T, s1, s2, ping;
		cin >> n >> m >> S >> T;
		vector<vector<ii> > adj(n);
		//build bidirectional adjacency list
		for (int j = 0; j < m; j++) {
			cin >> s1 >> s2 >> ping;
			adj[s1].push_back(ii(s2, ping));
			adj[s2].push_back(ii(s1, ping));
		}
		//dijkstra's algorithm from green book to find shortest path
		vector<int> dist(adj.size(), INT_MAX); dist[S] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, S));
		while (!pq.empty()) {
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if (d > dist[u]) continue;
			for (int j = 0; j < (int)adj[u].size(); j++) {
				ii v = adj[u][j];
				if (dist[u] + v.second < dist[v.first]) {
					dist[v.first] = dist[u] + v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}
		//if the distance to T is INT_MAX, its unreachable
		if (dist[T] == INT_MAX) {
			cout << "Case #" << ct << ": unreachable\n";
		}
		else {
			cout << "Case #" << ct << ": " << dist[T] << "\n";
		}
		//use a counter to keep track of what case we are on
		ct++;
	}
	return 0;
}