#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]) {
	long long x, n, res, sum = 0;
	cin>>x;
	
	for(long long i = 1; i<x; i++){
		cin>>n;
		sum+=n;
	}
	res = -sum + (x*(x+1))/2;
	cout << res;
}

