#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int ops[4][2]={{-1,0,},{1,0},{0,1},{0,-1}};

int bfs(vector<string>&road,int x,int y){
    int m = road.size();
    int n = road[0].length();
    bool visited[m][n];
    memset(visited,0,sizeof(visited));
    visited[x][y] = true;
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    int step=0;
    while(!q.empty()){
        int N = q.size();
        for(int i=0;i<N;i++){
            auto f = q.front();
            if(road[f.first][f.second]=='d'){
                return step;
            }
            q.pop();
            for(auto&op:ops){
                int x = op[0]+f.first;
                int y = op[1]+f.second;
                if(x<0||x>=m||y<0||y>=n||visited[x][y]||road[x][y]=='#'){
                    continue;
                }
                visited[x][y] = true;
                q.push(make_pair(x,y));
            }
        }
        step++;
    }
    return -1;
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<string> road(m);
    int sx,sy;
    for(int i=0;i<m;i++){
        cin>>road[i];
        for(int j=0;j<n;j++){
            if(road[i][j]=='m'){
                sx=i,sy=j;
            }
        }
    }
    int step= bfs(road,sx,sy);
    if(step==-1)
        cout<<"No Way!";
    else
        cout<<step;
    return 0;
}
