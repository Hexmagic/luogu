#include <vector>
#include <string.h>
using namespace  std;
using namespace  std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int help[8];
        memset(help,0,sizeof(help));
        int start=1,level=0;
        help[0]=1;
        vector<int> ans;
        int j=0;
        while(help[0]<=9&&level>=0){
            help[level+1]=help[level]*10;
            if(help[level+1]<n){                
                ans.push_back(help[level++]);
            }else{
                int end = min((help[level-1]+1)*10-1,n);
                while(help[level]<=end){
                    ans.push_back(help[level]++);                    
                }
                level--;
                if(level>=0)
                    help[level]++;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    s.lexicalOrder(123);
}