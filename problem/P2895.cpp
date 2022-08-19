#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
int ops[4][2]= {{0,-1},{0,1},{1,0},{-1,0}};
int bfs(vector<vector<int>>&nosafe){
    queue<pair<int,int>> q;
    q.push({0,0});
    unordered_map<int,unordered_map<int,bool>> v;
    v[0][0]=true;
    int step=0;
    while(!q.empty()){
        int N = q.size();
        for(int i=0;i<N;i++){
            auto f = q.front();
            q.pop();
            if(nosafe[f.first][f.second]>step){
                q.push(f);
            }
        }
        N = q.size();
        for(int i=0;i<N;i++){
            auto f = q.front();
            if(nosafe[f.first][f.second]==INT_MAX){
                return step;
            }
            q.pop();
            for(auto&op:ops){
                int x = f.first+op[0];
                int y = f.second+op[1];
                if(x<0||y<0||v[x][y])
                    continue;
                v[x][y]=true;
                q.push({x,y});
            }
        }
        step++;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    //n = 4;
    //vector<vector<int>> arr(n);
    vector<vector<int>> nosafe(310,vector<int>(310,INT_MAX));
    // arr={
    //     {0,0,2},
    //     {2,1,2},
    //     {1,1,2},
    //     {0,3,5}
    // };
    for(int i=0;i<n;i++){
        int x,y,t;   
        cin>>x>>y>>t;     
        // x = arr[i][0];
        // y = arr[i][1];
        // t = arr[i][2];
        nosafe[x][y]=min(nosafe[x][y],t);
        for(auto&op:ops){
            int nx = op[0]+x;
            int ny = op[1]+y;
            if(nx<0||ny<0)
                continue;
            nosafe[nx][ny]=min(nosafe[nx][ny],t);
        }
    }
    int step = bfs(nosafe);
    cout<<step;
    return 0;    
}
