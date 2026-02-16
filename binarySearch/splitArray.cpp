class Solution {
public:
    int countStudents(vector<int>&nums,int pages){
        int students=1;
        long long pageStudent=0;
        for(int i=0;i<nums.size();i++){
            if(pageStudent + nums[i] <= pages){
                pageStudent += nums[i];
            }
            else{
                students += 1;
                pageStudent = nums[i];
            }
        }
        return students;
    }
    int findPages(vector<int>&nums,int n,int k)
    {
        if(k>n)
        {
            return -1;
        }
        int low= *max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int students=countStudents(nums,mid);
            if(students>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};