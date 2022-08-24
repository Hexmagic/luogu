#include <iostream>
#include <queue>


using namespace std;
struct Cmp{
    bool operator()(double a,double b){
        return a>b;
    }
};
int main(){
    int n;
    cin>>n;    
    //n=3;
    priority_queue<double,vector<double>,Cmp> q;
    for(int i=0;i<n;i++){
        double m;
        cin>>m;
        q.push(m);
    }
    int L=0;
    while(q.size()>1){
        double a = q.top();
        q.pop();
        double b = q.top();
        q.pop();
        q.push(a+b);
        L+=a+b;
    }
    cout<<L<<endl;
    return 0;
}
