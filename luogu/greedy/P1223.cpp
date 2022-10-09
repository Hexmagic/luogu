#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;    
    vector<pair<int,int>> v;
    int all_time=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v.push_back({t,i+1});
        all_time+=t;
    }
    auto cmp = [](pair<int,int> &a, pair<int,int> &b){
        if(a.first<b.first){
            return true;
        }else if(a.first>b.first){
            return false;
        }else if(a.first==b.first){
            return a.second<b.second;
        }
    };
    sort(v.begin(),v.end(),cmp);
    float acc=0;
    float sum=0;
    for(auto&ele:v){
        cout<<ele.second<<" ";
        acc+=ele.first;
        sum+=acc;
    }
    sum-=all_time;
    cout<<endl;    
    printf("%.2f\n",sum/n);
    return 0;
}
