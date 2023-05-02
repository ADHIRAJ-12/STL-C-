class Solution {
public:


    void dfs(int i,int j,vector<vector<int>>& image,int initialColor,int newColor){
        int n=image.size(),m=image[0].size();
        if(i<0 ||j<0 )return;
        if(i>=n ||j>=m )return;
        if(image[i][j]!=initialColor)return;

        image[i][j]=newColor;
        dfs(i+1,j,image,initialColor,newColor);
        dfs(i,j+1,image,initialColor,newColor);
        dfs(i-1,j,image,initialColor,newColor);
        dfs(i,j-1,image,initialColor,newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            int initialColor=image[sr][sc];
        if(initialColor!=newColor)dfs(sr,sc,image,initialColor,newColor);
        return image;

    }
};
