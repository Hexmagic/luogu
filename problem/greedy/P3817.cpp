#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    //n = 3, x = 3;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //arr = {2,2};
    int i = 0, j = 1;
    int E = 0;
    int A;
    while (j < n)
    {
        A = arr[i] + arr[j];
        if (A > x)
        {
            E += A - x;
            arr[j] = max(0,arr[j]-(A - x));
        }
        j++;
        i++;
    }
    cout << E << endl;
    return 0;
}