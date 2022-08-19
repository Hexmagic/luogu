#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int ops[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};

int bfs(vector<string>&roadmap,int x1,int y1,int x2,int y2){
    queue<pair<int,int>> q;
    int M = roadmap.size();
    q.push({x1,y1});
    bool visited[M][M];
    memset(visited,0,sizeof(visited));
    visited[x1][y1] = true;
    int step=0;
    while(!q.empty()){
        int N = q.size();
        for(int i=0;i<N;i++){
            auto f = q.front();
            if(f.first==x2&&f.second==y2){
                return step;
            }
            q.pop();
            for(auto&op:ops){
                int x=op[0]+f.first;
                int y=op[1]+f.second;
                if(x<0||y<0||x>=M||y>=M||visited[x][y]||roadmap[x][y]=='1')
                    continue;
                visited[x][y] = true;
                q.push({x,y});
            }
        }
        step++;
    }
    return -1;
}

int main(){
    int n;
    //cin>>n;
    n=3;
    vector<string> roadmap(n);
    // for(int i=0;i<n;i++){
    //     cin>>roadmap[i];
    // }
    roadmap = {
        "001",
        "101",
        "100"
    };
    int x1,y1,x2,y2;
    //cin>>x1>>y1>>x2>>y2;
    x1 = 1,y1=1,x2=3,y2=3;
    cout<<bfs(roadmap,x1-1,y1-1,x2-1,y2-1);
    return 0;
}