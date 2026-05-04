class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int len = str.length();
        int to = len/2;


        for(int i =0; i<to; i++ ) {
            if (str[i] != str[len-1-i]) return false;
        }
        return true;
    }
};
