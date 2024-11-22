#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<bool>>& hotel, int i, int j){
	if(	i < 0 ||
		j < 0 ||
		i >= hotel.size() ||
		j >= hotel[0].size() ||
		hotel[i][j])
		return;
	hotel[i][j] = true;
	dfs(hotel, i-1, j);
	dfs(hotel, i, j-1);
	dfs(hotel, i+1, j);
	dfs(hotel, i, j+1);
	return;
}
int main(){
	int n, m;
	cin >> n;
	cin >> m;
	vector<vector<bool>> hotel(n, vector<bool>(m, false));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			if(c == '#')
				hotel[i][j] = true;
		}
	}
	int count = 0;
	for(int i = 0; i < hotel.size(); i++){
		for(int j = 0; j < hotel[0].size(); j++){
			if(!hotel[i][j]){
				count++;
				dfs(hotel, i, j);
			}

		}
	}
	cout << count;
}
