class Solution {
public:
    bool checkPalindrome(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;

    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                bool caseoneans=checkPalindrome(s,i,j-1);
                bool casetwoans=checkPalindrome(s,i+1,j);
                bool finalans=caseoneans||casetwoans;
                return finalans;

            }
        }
        return true;
        
    }
};