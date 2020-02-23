class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxNum =INT_MIN;
        int minSumArray=0;
        int currentSum =0;
        if(nums.size()==0){
            return 0;
        }
        // scan from started currentSum - minSumArray will get one potential maximum sum .
        
        for(auto i:nums){
            currentSum +=i;
            maxNum = std::max(maxNum,currentSum-minSumArray);
            minSumArray = std::min(minSumArray,currentSum);
            
        }
        return maxNum;
        
    }
};