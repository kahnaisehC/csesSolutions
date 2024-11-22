#include<iostream>
#include<vector>


using namespace std;

struct query{ int a; int b;};
struct road { int a; int b; int c; };

int main(){
	int n, m, q;
	cin >> n;
	cin >> m;
	cin >> q;
	vector<query> queries;
	vector<vector<long long>> d(n+1, vector<long long>(n+1, -1));
	for(int i = 0; i < m; i++){
		road r;
		cin >> r.a;
		cin >> r.b;
		cin >> r.c;
		if(d[r.a][r.b] == -1 || d[r.a][r.b] > r.c){
			d[r.a][r.b] = r.c;
			d[r.b][r.a] = r.c;
		}

	}
	for(int i = 0; i < q; i++){
		query qu;
		cin >> qu.a;
		cin >> qu.b;
		queries.push_back(qu);
	}
	for(int i = 1; i <= n; i++){
		d[i][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				
				if(d[j][i] != -1 && d[i][k] != -1){
					if(d[j][k] != -1){
						d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
					}else{
						d[j][k] = d[j][i] + d[i][k];
					}
				}


			}
		}
	}
	for(auto qu: queries){
		cout << d[qu.a][qu.b] << endl;
	}
	return 0;

}
