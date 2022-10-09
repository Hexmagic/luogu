#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN = 5005;
const int MAXM = 400005;
struct edge
{
    int to;
    int dis;
    int next;
};

edge edges[MAXM];
int head[MAXN], dis[MAXN],ind;
bool v[MAXN];

void add_edge(int u, int v, int d)
{
    ind++;
    edges[ind].to = v;
    edges[ind].dis = d;
    edges[ind].next = head[u];
    head[u] = ind;
}

struct node
{
    int pos;
    int dis;
    bool operator<(const node &other) const
    {
        return other.dis < dis;
    }
};

int main()
{
    ind = 0;
    int N, M;
    cin >> N >> M;
    //N=50,M=2386;
    memset(head,0,sizeof(head));
    memset(dis,0,sizeof(dis));
    memset(v,0,sizeof(v));
    for (int i = 1; i <= N; i++)
    {
        dis[i] = 0x7fffffff;
    }    

    for (int i = 0; i < M; i++)
    {
        int from, to, dis;
        cin >> from >> to >> dis;                
        if(from==to)
            continue;
        add_edge(from, to, dis);
        add_edge(to, from, dis);
    }
    int ans=0,cnt=0;
    priority_queue<node> q;
    dis[1]=0;
    q.push({1,0});
    while(!q.empty()&&cnt<N){
        node tp = q.top();
        q.pop();
        int x = tp.pos;        
        if(v[x])
            continue;
        v[x]=true;
        ans+=tp.dis;
        cnt++;
        for(int i=head[x];i;i=edges[i].next){
            int y = edges[i].to;
            if(dis[y]>edges[i].dis){
                dis[y]=edges[i].dis;
                q.push((node){y,dis[y]});
            }                
        }
    }
    if(cnt==N)
        cout << ans << endl;
    else
        cout<< "orz" <<endl;
    return 0;
}