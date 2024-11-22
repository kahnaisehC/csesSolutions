#include<iostream>
#include<vector>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& road, int root){
	if(vis[root]){
		road.push_back(root);
		return true;
	}
	road.push_back(root);
	vis[root] = true;
	for(auto neigh: adj[root]){
		if(road.size() >= 2 && road[road.size()-2] == neigh)
			continue;
		if(dfs(adj, vis, road, neigh))
				return true;
	}
	road.pop_back();
	return false;

}



int main(){
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	vector<pair<int, int>> roads;
	while(m--){
		pair<int, int> p;
		scanf("%d %d", &p.first, &p.second);
		roads.push_back(p);
	}
	vector<vector<int>> adj(n+1);
	for(auto p: roads){
		adj[p.first].push_back(p.second);
		adj[p.second].push_back(p.first);
	}

	vector<bool> vis(n+1, false);
	bool hasCycle = false;
	for(int i = 1; i <= n; i++){
		vector<int> road;
		if(vis[i])
			continue;
		if(dfs(adj, vis, road, i)){
			hasCycle = true;
			int i;
			for(i = 0; i < road.size(); i++){
				if(road[i] == road[road.size()-1])
						break;
			}
			cout << road.size()-i << endl;
			for(; i < road.size(); i++){
				cout << road[i] << " " ;
			}
			break;
		}
	}
	if(!hasCycle)
		cout << "IMPOSSIBLE";


	return 0;

}
