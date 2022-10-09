class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int i=0;
        while(i<N&&k>0){
            if(nums[i]<=0){
                nums[i]=-nums[i];
                k--;
                i++;
            }else{
                if(i>0&&nums[i-1]<nums[i]){                                        
                    i--;
                }
                nums[i]=k%2==1?-nums[i]:nums[i];
                break;
            }
        }
        if(k>0)
            nums[N-1]=k%2==1?-nums[N-1]:nums[N-1]
        return accumulate(nums.begin(), nums.end(),0);

    }
};