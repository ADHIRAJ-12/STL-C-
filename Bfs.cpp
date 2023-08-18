
vector < vector < int > > nearest(vector < vector < int >> & mat, int n, int m) {
    // Write your code here.

    vector < vector < int > >vis(n,vector<int>(m,0));
    vector < vector < int > >dist(n,vector<int>(m,0));

    queue<pair<int,int>>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    vector<int>dx={-1,0,1,0};
    vector<int>dy={0,-1,0,1};


    while(!q.empty()){

        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        vis[row][col]=1;
        
        for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]&& mat[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                mat[nrow][ncol]=1;
                dist[nrow][ncol]=dist[row][col]+1;
                q.push({nrow,ncol});
            }

        }


    }
        return dist;


}











// queue<int> q;

// vector<bool> used(n);

// vector<int> d(n), p(n);

// q.push(s);

// used[s] = true;

// p[s] = -1;

// while (!q.empty()) {

//     int v = q.front();

//     q.pop();

//     for (int u : adj[v]) {

//         if (!used[u]) {

//             used[u] = true;

//             q.push(u);

//             d[u] = d[v] + 1;

//             p[u] = v;

//         }

//     }

// }

// ```
