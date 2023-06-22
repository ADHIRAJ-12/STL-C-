const int N=25e2+10;
int dp[N];

class Solution {
public:
    
    int lis(int i,vector<int> &nums){
        int ans=1;
        if(dp[i]!=-1)return dp[i];
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                ans=max(ans,lis(j,nums)+1);
            }
        }
        return dp[i]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int  ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,lis(i,nums));
        }
        return ans;

    }
};

    //IMPORTANT CONCEPT OF N=BINARY SEARCH WITH DP
    
//     int solveBinary(int n,vector<int>& nums){
        
//         if(n==0) return 0;
        
//         vector<int>ans;
//         ans.push_back(nums[0]);
        
//         for(int i=1;i<n;i++){
//             if(nums[i]>ans.back()) ans.push_back(nums[i]);
            
//             else{
//                 //find index of just bda element
//                 int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
//                 ans[index]=nums[i];
//             }
//         }
//         return ans.size();
//     }
    
