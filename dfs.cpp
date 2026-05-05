class Solution {
public:
void dfs(int i,int j,vector<vector<char>> &board, vector<vector<int>> &visited,int n,int m,
int drow[],int dcol[])
{
    visited[i][j]=1;
    for(int k=0;k<4;k++)
    {
        int nrow=i+drow[k];
        int ncol=j+dcol[k];
        if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O')
        {
            dfs(nrow,ncol,board,visited,n,m,drow,dcol);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(!visited[0][i] && board[0][i]=='O')
            {
                dfs(0,i,board,visited,n,m,drow,dcol);
            }
            if(!visited[n-1][i] && board[n-1][i]=='O')
            {
                dfs(n-1,i,board,visited,n,m,drow,dcol);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i][0]&& board[i][0]=='O')
            {
                dfs(i,0,board,visited,n,m,drow,dcol);
            }
            if(!visited[i][m-1] && board[i][m-1]=='O')
            {
                dfs(i,m-1,board,visited,n,m,drow,dcol);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && board[i][j]=='O')
                {
                    
                    board[i][j]='X';
                }
            }
        }
    }
};
