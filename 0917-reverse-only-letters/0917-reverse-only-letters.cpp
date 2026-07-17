class Solution {
public:
    bool isletter(char ch) {
        return (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z');
    }

    string reverseOnlyLetters(string& s) {
    
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(!isletter(s[i])){
                i++;
            }
            else if(!isletter(s[j])){
                j--;

            }
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
           
        }
        return s;
        // Implement logic to reverse only the letters in `s`
    }
};