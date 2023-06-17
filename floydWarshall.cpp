//sample question codeforces grey and graph
#include <bits/stdc++.h>
using namespace std;

const int INF=1e9+10;
const int N=510;
long long dist[N][N];



int  main()
{

int n;
cin>>n;
 for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cin>>dist[i][j];
    }
 }

    vector<int>del(n);
    for(int i=0;i<n;i++)cin>>del[i];
    reverse(del.begin(), del.end());
    vector<long long>ans;
    for(int k=0;k<n;k++){
        int del_v=del[k];
        for(int i=1;i<=n;i++){
             for(int j=1;j<=n;j++){
            long long newd =dist[i][del_v]+dist[del_v][j];
            dist[i][j]=min(dist[i][j],newd);
             }
           }
           long long sum=0;
           for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
            sum+=dist[del[i]][del[j]];
            }
           }
           ans.push_back(sum);

        }
    reverse(ans.begin(),ans.end());

    for(auto value:ans)cout<<value<<endl;

}
        
