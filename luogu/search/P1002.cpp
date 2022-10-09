#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int M, N, HM, HN;
    cin >> M >>N >> HM >> HN;
    M += 1;
    N += 1;
    vector<vector<int>> chess(M, vector<int>(N, 0));
    int ops[8][2] = {{-2, -1},
                     {-2, 1},
                     {-1, -2},
                     {-1, 2},
                     {1, -2},
                     {1, 2},
                     {2, -1},
                     {2, 1}};
    // if(HM<M&&HN<N)
    //     chess[HM][HN] = 1;
    for (int i = 0; i < 8; i++)
    {
        auto op = ops[i];
        auto x = HM + op[0];
        auto y = HN + op[1];
        if (x > 0 && x < M && y > 0 && y < N)
        {
            chess[x][y] = 1;
        }
    }
    vector<vector<int>> dp(M, vector<int>(N, 0));
    dp[0][0] = 1;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (chess[i][j] == 1)
            {
                break;
            }
            if (j > 0)
            {
                dp[i][j] += dp[i][j - 1];
            }
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j];
            }           
        }
    }
    cout << dp[M-1][N-1] << endl;
    return 0;
}
