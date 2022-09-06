#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100010, MaxM = 500010;

struct edge
{
    int to, dis, next;
};

edge e[MaxM];
int head[MaxN], ans[MaxN], cnt;
int n, m, s;

inline void add_edge( int u, int v, int d )
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
struct node
{
    int dis;
    int pos;
    bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};

int main(){
    int n,m,s;
    cin >> n >> m >> s;    
    //n=4,m=6,s=1;
    unordered_map<int,vector<node>> adj;
    for(int i = 0; i <m;i++){ 
        int start,end,dis;   
        cin >> start >> end >> dis;                
        add_edge(start,end,dis);
    }
    priority_queue<node> q;    
    for(int i = 1; i <= n; ++i)ans[i] = 0x7fffffff;
    ans[s]=0;
    q.push({0,s});

    while(!q.empty()){
        auto tp = q.top();        
        q.pop();
        if(ans[tp.pos]!=tp.dis)
            continue;
        int x = tp.pos;
        for( int i = head[x]; i; i = e[i].next )
        {
            int y = e[i].to;
            if( ans[y] > ans[x] + e[i].dis )
            {
                ans[y] = ans[x] + e[i].dis;
                q.push({ans[y], y});
            }
        }   
    }    
    for(int i = 1; i <=n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}