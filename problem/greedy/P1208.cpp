#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v(m);
    for(int i = 0; i <m;i++){
        int p,c;
        cin >> p >> c;
        v[i]={p,c};
    }
    auto cmp = [](pair<int,int> &a, pair<int,int> &b){
        return a.first < b.first;
    };
    sort(v.begin(),v.end(),cmp);
    long long Ans = 0;
    for(int i = 0; i <m;i++){
        if(n>=v[i].second){
            Ans+=v[i].first*v[i].second;
            n-=v[i].second;
        }else{
            Ans+=v[i].first*n;
            n=0;
        }
    }
    cout << Ans << endl;
    return 0;
}