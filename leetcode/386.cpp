#include <vector>
#include <string.h>
#include <iostream>

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
        while(help[0]<=min(n,9)&&level>=0){
            help[level+1]=help[level]*10;
            if(help[level+1]<=n){                
                ans.push_back(help[level++]);
            }else{
                if(level==0){
                    ans.push_back(help[level]++);                    
                }else{
                    int last_level_num = help[level-1];
                    int end = (last_level_num+1)*10-1;
                    end = min(end,n);
                    while(help[level]<=end){
                        ans.push_back(help[level]++);                    
                    }
                    level--;
                    if(level>=0){
                        int last_end = (help[level-1]+1)*10;
                        if(help[level]<last_end-1){
                            help[level]++;  
                        }  else{
                            level--;
                            help[level]++;
                        }

                    }else if(level==0){
                         help[level]++;
                    }
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    s.lexicalOrder(234);
}