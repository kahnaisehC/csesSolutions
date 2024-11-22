#include<iostream>
#include<queue>
#include<vector>
#include<typeinfo>
using namespace std;
struct trie{
	trie *father;
	int c;
};
struct monster{
	int i;
	int j;
};
struct adv{
	int i;
	int j;
	trie *path;
};

int main(){
	int n, m;
	cin >> n;
	cin >> m;
	vector<vector<bool>> map(n, vector<bool>(m, false));
	queue<monster> monsters;
	queue<adv> advs;
	trie* path = NULL;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			if(c == '#'){
				map[i][j] = true;
			}
			if(c == 'M'){
				map[i][j] = true;
				monsters.push({i, j});
			}
			if(c == 'A'){
				if(i == n-1 
						|| i == 0
						|| j == 0
						|| j ==m-1){
					printf("YES\n0");
					return 0;
				}
				map[i][j] = true;
				advs.push({i, j, nullptr});
			}
		}
	}

	// 0 = 'L'; 1 = 'D'; 2 = 'R'; 3 = 'U'
	while(!advs.empty()){
		int advsize = advs.size();
		int monstersize = monsters.size();
		while(monstersize){
			monstersize--;
			monster top = monsters.front();
			monsters.pop();
			int& i = top.i;
			int& j = top.j;
			if(i < n-1 && !map[i+1][j]){
				map[i+1][j] = 1;
				monster step = {i+1, j};
				monsters.push(step);
			}
			if(i != 0 && !map[i-1][j]){
				map[i-1][j] = 1;
				monster step = {i-1, j};
				monsters.push(step);
			}
			if(j != 0 && !map[i][j-1]){
				map[i][j-1] = 1;
				monster step = {i, j-1};
				monsters.push(step);
			}
			if(j < m-1 && !map[i][j+1]){
				map[i][j+1] = 1;
				monster step = {i, j+1};
				monsters.push(step);
			}

		}
		while(advsize--){
			adv top = advs.front();
			advs.pop();
			int &i = top.i;
			int &j = top.j;
			trie* father = top.path;

			if(i == n-1 
					|| i == 0
					|| j == 0
					|| j ==m-1){
				path = father;
				break;
			}
			if(!map[i+1][j]){
				map[i+1][j] = 1;
				trie pt = {NULL, 1};
				pt.father = father;
				adv step = {i+1, j, &pt};
				step.path->c = 1;
				advs.push(step);

			}
			if(!map[i][j+1]){
				map[i][j+1] = 1;
				trie pt = {NULL, 2};
				pt.father = father;
				adv step = {i, j+1, &pt};
				step.path->c = 2;
				advs.push(step);

			}
			if(!map[i][j-1]){
				map[i][j-1] = 1;
				trie pt = {NULL, 0};
				pt.father = father;
				adv step = {i, j-1, &pt};
				step.path->c = 0;
				advs.push(step);

			}
			if(!map[i-1][j]){
				map[i-1][j] = 1;
				trie pt = {NULL, 3};
				pt.father = father;
				adv step = {i-1, j, &pt};
				step.path->c = 3;
				advs.push(step);

			}

		}
		if(path!= NULL)
			break;
	}
	if(path != NULL){
		printf("YES\n");
		printf("%d", path->c);
		
		while(path != NULL ){
			switch(path->c){
				case 0:
					printf("L");
					break;
				case 1:
					printf("D");
					break;
				case 2:
					printf("R");
					break;
				case 3:
					printf("U");
					break;
			}
		}
	}
	else{
		printf("NO");
	}
}
