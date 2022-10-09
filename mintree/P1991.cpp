#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <string.h>
using namespace std;

const int MAXN =502;
const int MAXM =125250;

struct edge{
    int pos;
    int next;
    double dis;    
};
edge edges[MAXM];
int head[MAXN],v[MAXN],ans[MaxN];
int ind;
void add_edge(int u,int v,int d){
    ind++;
    edges[ind].pos = v;
    edges[ind].dis = d;
    edges[ind].next = head[u];
    head[u] = ind;
}

inline double distance(vector<int>&a,vector<int>&b){
    int x=a[0]-b[0];
    int y=a[1]-b[1];
    return sqrt(x*x+y*y);
}
struct node{
    int pos;
    double dis;
};
int main(){
    ind = 0;
    int S,P;
    cin >> S>>P;
    memset(head,0,sizeof(head));
    memset(v,0,sizeof(v));
    vector<vector<int>> arr;
    int X,Y;
    for(int i=0;i<P;i++){
        cin>>X>>Y;
        arr.push_back({X,Y});
    }
    for(int i=1;i<=P;i++){
        for(int j=i+1;j<=P;j++){
            double dis = distance(arr[i],arr[j]);
            add_edge(i,j,dis);
            add_edge(j,i,dis);
        }
    }
    priority_queue<node> q;
    int cnt=0;
    vector<int> branches;
    

}