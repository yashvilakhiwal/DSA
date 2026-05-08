class Solution {
public:

    void binString(int n, int lastPlace, string ans) {

        if(n == 0) {
            v.push_back(ans);
            return;
        }

        if(lastPlace != 0) {

            binString(n - 1, 0, ans + '0');
            binString(n - 1, 1, ans + '1');
        }
        else {

            binString(n - 1, 1, ans + '1');
        }
    }

    vector<string> v;

    vector<string> validStrings(int n) {

        binString(n, 1, "");

        return v;
    }
};