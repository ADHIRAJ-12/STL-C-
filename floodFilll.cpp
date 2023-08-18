vector<vector<int>> floodFill(vector<vector<int>> &image, int n, int m, int x, int y, int p) 
{
    // Write your code here.

     queue<pair<int,int>>q;
    vector<vector<int>>vis(n,vector<int>(m,0));
   vector<vector<int>> dir = {{0,1},{0,-1},{-1,-0},{1,0}};
   q.push({x,y});
   int color=image[x][y];
   image[x][y]=p;
   vis[x][y]=1;

  
     while(!q.empty()){
       int row=q.front().first;
       int col=q.front().second;
       q.pop();

        for(int d=0;d<dir.size();++d){
            
            int nrow=row+dir[d][0];
            int ncol=col+dir[d][1];
            
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && image[nrow][ncol]==color){
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=p;
                    q.push({nrow, ncol});
                }
          }
        }

    

        return image;
}
