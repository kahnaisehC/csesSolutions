#include<iostream>
#include<vector>

using namespace std;

const int INF = 1e18+7;
struct tunnel{
  int b;
  int x;
};
struct node{
  int id;
  int dist;
}

map<int, long long> recorr;
bool dfs(vector<vector<tunnel>> adj, int root, int dist = 0){
  recorr[root] = dist;
  for(auto [b, x]: adj[root]){
    if(dist.count(b) != 0){
      if(-dist[b] + dist + x > 0){
        return true;
      }
    }
    else if(dfs(adj, root, dist+x)){
      return true;
    }
  }
  recorr.erase(root);
  return false;

}

int main (int argc, char *argv[]) {
  int n, m;
  cin >> n;
  cin >> m;
  vector<vector<tunnel>> adj(n+1, vector<tunnel>(n+1));

  for(int i = 0; i < m; i++){
    int a;
    tunnel t;
    cin >> a;
    cin >> t.b;
    cin >> t.x;
    adj[a].push_back(t);
  }
  if(dfs(adj, 1)){
    cout << -1;
    return 0;
  }
  queue<node> q;
  q.push({1, 0});
  int ret = -INF;
  vector<bool> vis(n+1, false);
  while(!q.empty()){
    node top = q.top();
    q.pop();
    for(auto [next, dist]: adj[top.node]){
      if(n == next){
        ret = max(top.dist, ret);
      }
    }
  }
  

  




  
  return 0;
}
