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
    cin>>N>>M;
    vector<vector<int>> arr;
    int a,b,c;
    int ALL=0;
    for(int i=1;i<=M;i++){
        cin>>a>>b>>c;
        arr.push_back({a,b,c});
        ALL+=c;
    }
    auto cmp = [](vector<int>& a, vector<int>& b){
        return a[2]<b[2];
    };
    UnionFound ufo(N);
    int Ans=0;
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<M;i++){
        a=arr[i][0];
        b=arr[i][1];
        int pa = ufo.find(a);
        int pb = ufo.find(b);
        if(pa!=pb){
            ufo.join(pa,pb);
            Ans+=arr[i][2];
        }
    }
    cout<<ALL-Ans<<endl;
    return 0;
}