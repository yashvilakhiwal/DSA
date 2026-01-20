class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,0,board,word))
                    return true;
            }
        }
        return false;
    }
    bool dfs(int i,int j,int index,vector<vector<char>>&board,string&word){
        if(index==word.size()){
            return true;
        }
        if(i<0||i>=m||j<0||j>=n||board[i][j]!=word[index])
            return false;
        char temp=board[i][j];
        board[i][j]='#';
        bool found=dfs(i+1,j,index+1,board,word)||
                   dfs(i-1,j,index+1,board,word)||
                   dfs(i,j+1,index+1,board,word)||
                   dfs(i,j-1,index+1,board,word);
        board[i][j]=temp;
        return found;
    }
};