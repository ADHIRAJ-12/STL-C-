// hacker earth codemonk

 
#include <bits/stdc++.h>
using namespace std;
 
const int N=1e5+10;
int parent[N];
int sizes[N];
multiset<int>ms;
  
void make(int v){
  parent [v]=v;
  sizes[v]=1;
  ms.insert(1);
}
 
int find(int v){
    if(v==parent[v])return v;
    return parent[v]=find(parent[v]);
}
 

void merge(int a ,int b){

ms.erase(ms.find(sizes[a]));
ms.erase(ms.find(sizes[b]));
 ms.insert(sizes[a]+sizes[b]);

}


void Union(int a,int b){
 
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sizes[a]<sizes[b])swap(a,b);
        parent[b]=a;
        merge(a,b);
        sizes[a]+=sizes[b];
    }
}
 
int main(){
    int n,k;
    cin>>n>>k;
 
    for(int i=1;i<=n;i++)make(i);
 
        while(k--){
 
            int u,v;
            cin>>u>>v;
            Union(u,v);
            if(ms.size()==1)cout<<0<<endl;
            else{
                int mn=*(ms.begin());
                int mx=*(--ms.end());
                cout<<mx-mn<<endl;

            }
        }
        
}

