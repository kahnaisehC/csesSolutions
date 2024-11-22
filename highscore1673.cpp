#include<iostream>
#include<vector>
using namespace std;
struct edge{
	int from;
	int to;
	int weight;
};
const long long INF = 1e18+7;
int main (){
	int n, m;
	cin >> n;
	cin >> m;
	vector<edge> edges;
	for(int i = 0; i < m; i++){
		edge e;
		cin >> e.from;
		cin >> e.to;
		cin >> e.weight;
		edges.push_back(e);
	}
	vector<long long> dist(n+1, -INF);
	vector<long long> distToN(n+1, -INF);
	dist[1] = 0;


	for(int i = 1; i <= n; i++){
		for(edge e: edges){
			if(dist[e.from] != -INF){
					dist[e.to] = max(dist[e.to], dist[e.from] + e.weight);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(edge e: edges){
			if(dist[e.from] != -INF){
				if(dist[e.to] == INF || dist[e.from]+e.weight > dist[e.to]){
					dist[e.to] = INF;
				}
			}
		}
	}
	if(dist[n] == INF){
		cout << -1;
	}else{
		cout << dist[n];
	}
	
	return 0;
}
