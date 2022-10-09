#include <iostream>
#include <string.h>
using namespace std;
bool CONNECTED[20][20];
int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    memset(CONNECTED, 0, sizeof(CONNECTED));
    for(int i=0;i<N-1;i++){
        for(int j=i;j<N;j++) {
            int M;
            cin>>M;
            if(M==1)
                CONNECTED[i][j+1]=true;
        }
    }
    return 0;
}