#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int ops[4][2] = {
    {0,1},{0,-1},{1,0},{-1,0}
};
void dfs(vector<string>&arr,int i,int j,vector<vector<bool>>&v){
    v[i][j]=true;
    int m = arr.size();
    int n = arr[0].length();
    for(auto&op:ops){
        int x = op[0]+i;
        int y = op[1]+j;
        if(x<0 || y<0||x>=m || y>=n||v[x][y]||arr[x][y]=='0')
            continue;
        v[x][y]=true;
        dfs(arr,x,y,v);
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<string> arr(m);
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    vector<vector<bool>> v(m,vector<bool>(n));
    int cnt = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='0'||v[i][j]){
                continue;
            }
            dfs(arr,i,j,v);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}