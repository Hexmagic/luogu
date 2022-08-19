#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<int>&arr,int start,int end){
    int n = arr.size();
    vector<bool> v(n+1);
    queue<int> q;
    q.push(start);
    v[start]=true;
    int step = 0;
    while(!q.empty()){
        int N = q.size();
        for(int i=0;i<N;i++){
            auto f = q.front();
            if(f==end)
                return step;
            q.pop();
            int down = f-arr[f-1];
            if(down>=1&&down<=n&&!v[down]){
                v[down]=true;
                q.push(down);
            }
            int up = f+arr[f-1];
            if(up>=1&&up<=n&&!v[up]){
                v[up]=true;
                q.push(up);
            }
        }
        step++;
    }
    return -1;
}
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<< bfs(arr,a,b);
    return 0;
}