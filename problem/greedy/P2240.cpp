#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int N,T;
    //cin>>N>>T;
    N = 4;
    T= 50;
    vector<pair<float,float>> arr(N);
    // for(int i=0;i<N;i++){
    //     int m,v;
    //     cin>>m>>v;
    //     arr[i]={m,v};
    // }
    arr = {
        {10,60},
        {20,100},
        {30,120},
        {15,45}
    };
    auto cmp = [](pair<float,float> a, pair<float,float> b){
        return (a.second/a.first)>(b.second/b.first);
    };
    sort(arr.begin(),arr.end(),cmp);
    float Ans = 0;
    for(int i=0;i<arr.size();i++){
        if(T==0)
            break;
        if(T>=arr[i].first){
            Ans+=arr[i].second;
            T-=arr[i].first;
        }else{
            Ans+=(arr[i].second/arr[i].first)*T;
            T=0;
        }
    }
    printf("%.2f",Ans);
    return 0;
}
