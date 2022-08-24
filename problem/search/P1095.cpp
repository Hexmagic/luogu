#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int m,s,t;   
    cin>>m>>s>>t;
    //m=39,s=200,t=4;
    int dp[2][m+1];
    memset(dp,0,sizeof(dp));
    int maxL=0;      
    for(int i=1;i<=t;i++){     
        int cur = i&1;
        int last = (i-1)&1;    
        for(int j=m;j>=0;j--){
            dp[cur][j]=dp[last][j]+17;
            if(j>=4)
                dp[cur][j]=max(dp[cur][j],dp[last][j-4]);
            if(j<=m-10)
                dp[cur][j]=max(dp[cur][j],dp[last][j+10]+60);
            maxL=max(maxL,dp[cur][j]);
        }
        if(maxL>s){
            cout<<"Yes"<<endl;
            cout<<i<<endl;
            return 0;
        }             
    }
    cout<<"No"<<endl;
    cout<<maxL<<endl;
    return 0;
}