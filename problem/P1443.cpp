#include <iostream>
#include <queue>
#include <climits>
#include <string.h>
using namespace std;
int main(){
    int m,n,x,y;
    //cin>>m>>n>>x>>y;
    vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
    bool v[m][n];
    memset(v,0,sizeof(v));
    queue<pair<int,int>> q;
    q.push({x,y});
    int ops[8][2] = {
        {-2,-1},{-2,1},
        {-1,2},{1,2},
        {2,-1},{2,1},
        {-1,-2},{1,-2},
    };
    int step=0;
    v[x][y]=1;
    while(!q.empty()){
        int N = q.size();
        for(int i=0;i<N;i++){
            auto f = q.front();
            dp[f.first][f.second]=step;
            q.pop();
            for(auto&op:ops){
                int nx = op[0]+f.first;
                int ny = op[1]+f.second;
                if(nx<0||nx>=m||ny<0||ny>=n||v[nx][ny])
                    continue;
                v[nx][ny]=true;                
                q.push({nx,ny});                    
            }        
        }
        step++;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]==INT_MAX)            
                dp[i][j]=-1;
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}