#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int heads[n];
    for(int i = 0; i <n;i++){
        cin >> heads[i];
    }
    int cans[m];
    for(int i = 0;i < m;i++){
        cin >>cans[i];
    }
    sort(heads,heads+n);
    sort(cans,cans+m);
    int i=0;
    int Ans=0;
    for(int j=0;j<m;j++){
        if(i<n&&cans[j]>=heads[i]){
            Ans+=cans[j];
            i++;
        }
    }
    if(i!=n)
        cout<<"you died!";
    else
        cout<<Ans;
    return 0;
}