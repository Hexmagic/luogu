#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int N;
    N = 5;
    //cin >> N;
    int arr[] = {50,10,30,40,20};
    int Sum = 0;
    for (int i = 0; i < N; i++)
    {
        //cin >> arr[i];
        Sum += arr[i];
    }
    int Even = Sum / N;
    int Q = 0, M = 0, Move = 0;
    int index = -1;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < Even)
        {
            Q += Even - arr[i];
            if (index == -1)
            {
                index = i;
            }
        }
        else if (arr[i] > Even)
        {
            M += arr[i] - Even;
            if (Q > 0 && M >= Q)
            {
                Move += i - index;
                index = -1;
                M -= Q;
                Q = 0;
            }
            if (index==-1&&M > 0)
            {
                Move++;
                arr[i + 1] += M;
                M = 0;
            }
        }
    }
    cout<<Move << endl;
    return 0;
}