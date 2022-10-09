#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string.h>
using namespace std;

struct node{
    int pos;
    int dis;
    bool operator<(const node&other)const{
        return dis>other.dis;
    }
};

int main(){
    int n,m;
    cin >> n>>m;
    unordered_map<int,vector<pair<int,int> > > adj;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    priority_queue<node> q;
    bool v[n+1];
    int dis[n+1];
    memset(v,0,sizeof(v));
    memset(dis,0x3f3f3f3f,sizeof(dis));
    q.push({1,0});
    dis[1]=0;
    int ac=0,edge=0;
    while(!q.empty()&&ac<n){
        auto f = q.top();
        q.pop();
        int x = f.pos;
        if(v[x])
            continue;
        ac++;
        v[x] = true;
        edge = max(edge,f.dis);
        for(int i=0;i<adj[x].size();i++){
            int y = adj[x][i].first;
            if(dis[y]>adj[x][i].second){
                dis[y]=adj[x][i].second;
                q.push({y,dis[y]});
            }
        }
    }
    cout<<n-1<<" "<<edge<<endl;
    return 0;
}