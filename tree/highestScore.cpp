class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>>children(n);
        for(int i=1;i<n;i++){
            children[parents[i]].push_back(i);
        }
        long long maxScore=0;
        int count=0;
        dfs(0,n,children,maxScore,count);
        return count;
    }
    private:
        int dfs(int node,int n,vector<vector<int>>&children,long long &maxScore, int &count){
            int subtreeSize=1;
            long long score=1;
            for(int i=0;i<children[node].size();i++){
                int child=children[node][i];
                int childSize=dfs(child,n,children,maxScore,count);
                subtreeSize+=childSize;
                score*=childSize;
            }
            int remainingSize=n-subtreeSize;
            if(remainingSize>0){
                score*=remainingSize;

            }
            if(score>maxScore){
                maxScore=score;
                count=1;
            }
            else if(score==maxScore){
                count++;
            }
            return subtreeSize;
        }
};