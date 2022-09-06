#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i <n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int L=0,R=v[n-1];
    int i=-1,j=n-1;
    bool r=true;
    long ans = 0;
    while(i<j){
        ans+=(R-L)*(R-L);
        if(r){            
            L=v[i+1];
            i+=1;
        }else{
            R=v[j-1];
            j--;
        }
        r=!r;
    }
    cout<<ans<<endl;
    return 0;
}   