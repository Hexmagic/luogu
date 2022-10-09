#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class UnionFound{
    public:
        int M;
        vector<int> parent;
        UnionFound(int N):parent(N+1){
            M=N;
            for(int i=1;i<=N;i++){
                parent[i]=i;
            }
        }
        int find(int x){
            while(parent[x]!=x){
                x=parent[x];
                parent[x]=parent[parent[x]];
            }
            return x;
        }
        void join(int x, int y){      
            parent[x]=y;
            M--;        
        }
};
int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> arr;
    int start,end,dis;
    for(int i=0;i<M;i++){
        cin>>start>>end>>dis;
        arr.push_back({start,end,dis});
    }
    auto cmp = [](vector<int>& a, vector<int>& b){
        return a[2]<b[2];
    };
    sort(arr.begin(),arr.end(),cmp);
    int from,to;
    int ans=0;
    UnionFound ufo(N);
    for(int i=0;i<M;i++){
        auto ele = arr[i];
        from = ele[0];
        to = ele[1];
        dis =ele[2];
        int pa = ufo.find(from);
        int pb = ufo.find(to);
        if(pa!=pb){
            ufo.join(pa,pb);
            ans+=dis;
        }
    }
    if(ufo.M==1)
        cout<<ans<<endl;
    else
        cout<<"orz"<<endl;
    return 0;
}