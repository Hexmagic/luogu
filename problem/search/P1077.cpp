#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int MOD =1e6+7;
    int dp[n+1][m+1];
    dp[0][0]=1;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        int c= arr[i];
        for(int k=0;k<=c;i++){
            dp[i][j+k]+=dp[i-1][j];
        }
        dp[i][j]%=MOD;
    }
    cout<<dp[n][m]<<endl;
    return 0;
}