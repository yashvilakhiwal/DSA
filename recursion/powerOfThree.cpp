class Solution {
public:
    bool isPowerOfThree(int n) {
        //base condition
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        if(n%3!=0){
            return false;
        }
        //recursive call
        return isPowerOfThree(n/3);
    }
};