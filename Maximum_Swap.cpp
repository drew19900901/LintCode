
class Solution {
public:
    /**
     * @param num: a non-negative intege
     * @return: the maximum valued number
     */
    int maximumSwap(int num) {
        int result = num;
        string temp=to_string(num);
        int MaxIndex = temp.length()-1;
        for(int i=MaxIndex-1;i>0;i--){
            if(temp[i]>temp[MaxIndex]){
                MaxIndex=i;
            }
            if(temp[i-1]<temp[MaxIndex]){
                swap(temp[i-1],temp[MaxIndex]);
                int max=std::stoi(temp);
                if(result<max){
                    result=max;
                }
                swap(temp[MaxIndex],temp[i-1]);
            }
        }
        return result;
        
    }
};