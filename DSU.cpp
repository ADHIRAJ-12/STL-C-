//dsa
#include <bits/stdc++.h>
using namespace std;

class DisjointSet{

    vector<int>parent,rank,size;

public:
    //constructor
     DisjointSet(int n){

        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }


     }

    int findUltParent(int node){
        if(node==parent[node])return node;
        else return parent[node]=findUltParent(parent[node]);
    }


    void unionByRank(int u,int v){

        int ultU=findUltParent(u);
        int ultV=findUltParent(v);

        if(ultV==ultU)return;
        if(rank[ultV]<rank[ultU])parent[ultV]=ultU;
        else if(rank[ultU]<rank[ultV])parent[ultU]=ultV;
        else {
            parent[ultV]=ultU;
            rank[ultU]++;
        }
    }


    void unionBySize(int u,int v){

        int ultU=findUltParent(u);
        int ultV=findUltParent(v);

        if(ultV==ultU)return;
        if(size[ultV]<size[ultU]){
            parent[ultV]=ultU;
            size[ultU]+=size[ultV];
        }
        else{
             parent[ultU]=ultV;
            size[ultV]+=size[ultU];
        }
    }






} ;
int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2); 
    ds.unionByRank(2, 3); 
    ds.unionByRank(4, 5); 
    ds.unionByRank(6, 7); 
    ds.unionByRank(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUltParent(3) == ds.findUltParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionByRank(3, 7); 

    if(ds.findUltParent(3) == ds.findUltParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
};



// int kruskalMST(int n, vector<vector<int>> &edges)
// {
// 	// Write your code here.
// 	vector<pair<int,pair<int,int>>>adj;

//         for (auto i:edges) {
// 			int u=i[0];
// 			int v=i[1];
// 			int wt=i[2];
// 			adj.push_back({wt,{u,v}});
// 		}

// 		sort(adj.begin(),adj.end());
// 		DisjointSet ds(n);
// 		int ans=0;
// 		for(auto i:adj){
// 			int wt=i.first;
// 			int u=i.second.first;
// 			int v=i.second.second;
			
// 			if(ds.findUltParent(u)!=ds.findUltParent(v)){
// 				ans+=wt;
// 				ds.unionBySize(u,v);
// 			}


// 		}

// 		return ans;
// }



//cp
 
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

