#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    long long A, B;
    cin >> A >> B;
    long long cnt=0;
    while(B>0){
        B&=(B-1);
        cnt++;
    }
    return 0;
}