class Solution {
public:
    void helper(int ind,int sum,int n,vector<vector<int>>&ans,vector<int>&ds,int k){
        if(sum==n&&k==0){
            ans.push_back(ds);
            return ;
        }
        if(sum>n){
            return;
        }
        for(int i=ind;i<=9;i++){
            if(i>n){
                break;
            }
            ds.push_back(i);
            helper(i+1,sum+i,n,ans,ds,k-1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(1,0,n,ans,ds,k);
        return ans;

    }
};