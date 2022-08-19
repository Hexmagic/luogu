#include <string.h>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
struct Elem{
    int distance;
    int x, y;
    int step;
    Elem(int x, int y,int distance,int step):x(x),y(y),distance(distance),step(step){        
    }
};
int ops[12][2]= {
        {-2,-1},{-2,1},
        {-1,2},{1,2},
        {2,-1},{2,1},
        {-1,-2},{1,-2},
        {-2,-2},{2,2},
        {-2,2},{2,-2}
    };
int a_star(Elem&start){
    queue<Elem> q;
    q.push(start);
    int step=1;    
    unordered_map<int,unordered_map<int,bool>> v;
    v[start.x][start.y]=1;
    while(!q.empty()){
        int N = q.size();
        for(int i=0;i<N;i++){
            auto top =q.front();
            q.pop();
            if(top.x==1&&top.y==1)
                return top.step;
            for(auto&op:ops){
                int x = op[0]+top.x;
                int y = op[1]+top.y;
                if(x<1||y<1||x>25||y>25||v[x][y])
                    continue;
                v[x][y]=true;
                q.push(Elem(x,y,x+y-2,top.step+1));
            }
        }
    }
    return -1;
}
int main(){
    int x1,y1,x2,y2;
    //cin>>x1>>y1>>x2>>y2;
    x1=12,y1=16;
    x2=18,y2=10;
    Elem e1={x1,y1,x1+y1-2,0};
    Elem e2={x2,y2,x2+y2-2,0};
    int step1 = a_star(e1);
    int step2 = a_star(e2);
    cout<<step1<<endl;
    cout<<step2<<endl;
    return 0;
}