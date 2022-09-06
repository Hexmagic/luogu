#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int Tab[100][100];
int ops[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};


int dfs(vector<vector<int> >&H,int i,int j,int R,int C){
    if(Tab[i][j]!=0){
        return Tab[i][j];
    }
    Tab[i][j]=1;
    for(auto&op:ops){
        int x = op[0]+i;
        int y = op[1]+j;
        if(x<0||y<0||x>=R||y>=C||H[x][y]<=H[i][j])
            continue;
        Tab[i][j]=max(Tab[i][j],1+dfs(H,x,y,R,C));
    }
    return Tab[i][j];
}

int main(){    
    int R,C;
    cin >> R>>C;
    vector<vector<int>> H(R,vector<int>(C));
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            cin>>H[i][j];
        }
    }    
    memset(Tab,0,sizeof(Tab));
    int Ans = 1;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            Ans =max(Ans, dfs(H,i,j,R,C));
        }
    }
    cout<<Ans<<endl;
    return 0;
}
