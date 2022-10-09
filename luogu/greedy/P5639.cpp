#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int arr[N];// = {1,0,1,1,0,1};
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }
    int step = 0;
    int flag = 0;
    int i=0;
    while(i<N){
        while(i<N&&arr[i]==flag){
            i++;
        }
        step++;
        flag^=1;
    }
    cout<<step<<endl;
    return 0;
}