#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int topo(int M, unordered_map<int, int> &inTab, unordered_map<int, vector<int>> &dag,unordered_map<int,bool>&isCame)
{
    queue<int> q;
    for (auto &elem : dag)
    {
        int k = elem.first;
        if (inTab[k] == 0)
        {
            q.push(k);
        }
    }
    while (!q.empty())
    {       
        int N = q.size();
        for (int i = 0; i < N; i++)
        {
            auto f = q.front();
            q.pop();
            if(isCame[f])
                M--;
            for (auto &con : dag[f])
            {               
                if((--inTab[con])==0)
                    q.push(con);                
            }
        }
    }
    return M;
}
int main()
{
    int n;
    cin >> n;
    int M = 0;
    unordered_map<int, vector<int>> dag;
    unordered_map<int, int> inTab;
    unordered_map<int,bool> isCame;
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        int m;
        cin >> m;
        M += m;
        int L;
        dag[key]={};
        isCame[key]=true;
        for (int j = 0; j < m; j++)
        {
            cin >> L;
            dag[key].push_back(L);
            inTab[L]++;
        }
    }
    // n=5;
    // inTab[2]=1;
    // inTab[1]=2;
    // inTab[7]=1;
    // dag ={
    //     {1,{2}},
    //     {2,{1}},
    //     {3,{7}},
    //     {4,{1}},
    //     {5,{}}
    // };
    // isCame={
    //     {1,true},
    //     {2,true},
    //     {3,true},
    //     {4,true},
    //     {5,true}
    // };
    int C = topo(n, inTab, dag,isCame);
    if(C==0)
        cout<<"YES"<<endl;
    else
        cout<<M<<endl;
    return 0;
}