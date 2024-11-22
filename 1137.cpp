#include<iostream>
#include<vector>



void build(){

}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    std::vector<int> values(n);
    for(auto& a: values){
        scanf("%d", &a);
    }
    std::vector<std::vector<int>> adj(n);
    
}