#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        v[i]={s,e};
    }
    auto cmp = [](pair<int,int>&a, pair<int,int> &b){
        if(a.second <b.second){
            return true;
        }else if(a.second==b.second){
            return a.first < b.first;
        }else{
            return false;
        }
    };
    sort(v.begin(),v.end(),cmp);
    int cnt = 0;
    int last_end=-1;
    for(int i=0;i<n;i++){
        if(v[i].first>=last_end) {
            cnt++;
            last_end = v[i].second;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
