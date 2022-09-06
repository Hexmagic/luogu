#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int L;
    cin >> L;
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int Min=0;
    int Max=0;
    for(int i = 0; i < N; i++){
        int L = arr[i]-0;
        int R = N+1-arr[i];
        Min = max(Min,min(L,R));
        Max = max(Max,max(L,R));
    }
    cout<<Min<<" "<<Max<<endl;
    return 0;
}