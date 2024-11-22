#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<memory>
using namespace std;

struct trie{
	shared_ptr<trie> father;
	unsigned field : 2;
	trie(int field) : field(field), father(NULL) { }
	trie(int field, trie father) : field(field), father(make_shared<trie>(father)) { }
};
struct monster{
	int i;
	int j;

};
struct adv{
	int i; 
	int j;
	shared_ptr<trie> path;
};

int main(){
	int n, m;
	cin >> n;
	cin >> m;
	shared_ptr<trie> path = nullptr;
	bool thereis = false;
	queue<adv> advs;
	queue<monster> monsters;
	vector<vector<bool>> map(n, vector<bool>(m, false));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			if(c == '#')
				map[i][j] = true;
			if(c == 'M'){
				map[i][j] = true;
				monsters.push({i, j});
			}
			if(c == 'A'){
				map[i][j] = true;
				advs.push({i, j, nullptr});
			}
		}
	}
	while(!advs.empty()){
		int monstersize = monsters.size();
		while(monstersize != 0){
			monstersize--;
			monster top = monsters.front(); monsters.pop();
			int &i = top.i;
			int& j = top.j;
			if(i != 0 && !map[i-1][j]){
				map[i-1][j] = true;
				monsters.push({i-1, j});
			}
			if(j != 0 && !map[i][j-1]){
				map[i][j-1] = true;
				monsters.push({i, j-1});
			}
			if(j < m-1 && !map[i][j+1]){
				map[i][j+1] = true;
				monsters.push({i, j+1});
			}
			if(i < n-1 && !map[i+1][j]){
				map[i+1][j] = true;
				monsters.push({i+1, j});
			}
		}
		monstersize = advs.size();
		while(monstersize != 0){
			monstersize--;
			adv top = advs.front(); advs.pop();
			int& i = top.i;
			int& j = top.j;
			if(i == 0
					|| j == 0
					|| i == n-1
					|| j == m-1){
				path = top.path;
				thereis = true;
				break;
			}

			if(!map[i-1][j]){
				adv next = {i-1, j, make_shared<trie>(3)};

				next.path->father = top.path;
				advs.push(next);
				map[i-1][j] = true;
			}
			if(!map[i][j-1]){
				adv next = {i, j-1, make_shared<trie>(0)};
				next.path->father = top.path;
				advs.push(next);
				map[i][j-1] = true;
			}
			if(!map[i+1][j]){
				adv next = {i+1, j, make_shared<trie>(1)};
				next.path->father = top.path;
				advs.push(next);
				map[i+1][j] = true;
			}
			if(!map[i][j+1]){
				adv next = {i, j+1, make_shared<trie>(2)};
				next.path->father = top.path;
				advs.push(next);
				map[i][j+1] = true;
			}
		}
	}
	if(thereis){
		printf("YES\n");
		stack<char>st;
		while(path != nullptr){
			switch(path->field){
				case 0:
					st.push('L');
					break;
				case 1:
					st.push('D');
					break;
				case 2:
					st.push('R');
					break;
				case 3:
					st.push('U');
					break;
			}
			path = path->father;
		}
		printf("%lu\n", st.size());
		while(!st.empty()){
			printf("%c", st.top());
			st.pop();
		}
	}
	else{
		printf("NO");
	}

	return 0;
}
