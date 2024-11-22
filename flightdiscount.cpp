#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct edge{
	int b, cost;
};

struct curr{
	long long currDist;
	int maxDist;
	int node;
};

const long long INF = 1e18;
class Compare{
	public:
		bool operator() (const curr& a, const curr& b){
			long long val1 = a.currDist - a.maxDist/2 - (a.maxDist&1);
			long long val2 = b.currDist - b.maxDist/2 - (b.maxDist&1);
			if(val1 != val2)
				return val1 > val2;
			return a.maxDist > b.maxDist;
	}
};
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<edge>> adj(n+1);
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;
		adj[a].push_back({b, c});
	}
	vector<long long> dist(n+1, INF);
	priority_queue<curr, vector<curr>, Compare> pq;
	pq.push({0, 0, 1});
	while(!pq.empty()){
		curr top = pq.top();
		pq.pop();
		cout << top.node << " ";
		printf("%llu - %d - %d = %llu\n", top.currDist, top.maxDist/2, top.maxDist&1, top.currDist-top.maxDist/2-top.maxDist&1);
		if(dist[top.node] < top.currDist - top.maxDist/2 - (top.maxDist&1)){
				continue;
		}

		dist[top.node] = top.currDist - top.maxDist/2 - (top.maxDist&1);
		for(auto neigh: adj[top.node]){
			long long cDist = top.currDist + neigh.cost;
			int mx = max(neigh.cost, top.maxDist);
			pq.push({cDist, mx, neigh.b});
		}
	}
	 cout << "distancias" << endl;
	for(auto x: dist){
		cout << x << endl;
	}
	cout << dist[n];
	return 0;
}
