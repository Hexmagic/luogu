#include <iostream>
#include <climits>
#include <queue>
#include <string.h>
using namespace std;
struct edge
{
    int to;
    int dis;
    int next;
};
const int MaxM = 500002, MaxN = 10002;
edge edges[MaxM];
int head[MaxN], dis[MaxN],cnt;
struct node
{
    int to;
    int dis;
    bool operator<(const node &other) const
    {
        return dis > other.dis;
    }
};
void add_edge(int u,int v,int d){
    cnt++;
    edges[cnt].to=v;
    edges[cnt].dis=d;
    edges[cnt].next=head[u];
    head[u] = cnt;
}
int main()
{
    cnt=0;
    memset(head,0,sizeof(head));
    int n, m, s;
    cin >> n >> m >> s;
    for(int i=1;i<=n;i++){
        dis[i]=INT_MAX;
    }
    for(int i=1;i<=m;i++){
        int u,v,d;
        cin >> u >> v >> d;
        add_edge(u,v,d);
    }
    priority_queue<node> q;
    q.push({s,0});
    int i=0;
    dis[s]=0;
    while(!q.empty()&&i<n){
        auto top = q.top();
        int x = top.to;
        q.pop();
        if(dis[x]!=top.dis)
            continue;
        i++;            
        for(int i=head[x];i;i=edges[i].next){
            int y = edges[i].to;
            if(dis[y]>dis[x]+edges[i].dis){
                dis[y]=dis[x]+edges[i].dis;
                q.push({y,dis[y]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}