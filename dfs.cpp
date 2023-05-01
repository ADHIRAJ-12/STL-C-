//o[v+e]
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
bool vis[N];
vector<int>g[N];

void dfs(int vertex){
//take action on vertex before entering the vertex
  
if(vis[vertex])return;
vis[vertex]=true;
for(int child:g[vertex]){
  //take action on child before entering the child node
	dfs(child); 
   //take action on child after exiting the child node
 }
   //take action on vertex after exiting the child
}


/// eg connected components count
int main() {
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

int count=0;
for(int i=1;i<=n;i++){
	if(vis[i])continue;
	dfs(i);
	count++;

}

cout<<count;

}
