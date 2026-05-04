class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st=0,end=numbers.size()-1;
        int currSum=0;
        vector<int>result;
        while(st<end)
        {
            currSum=numbers[st]+numbers[end];
            if(currSum==target)
            {
                result.push_back(st+1);
                result.push_back(end+1);
                return result;
            }
            else if(currSum>target)
            {
                end--;
            }
            else{
                st++;
            }
        }
        return {};
    }
};