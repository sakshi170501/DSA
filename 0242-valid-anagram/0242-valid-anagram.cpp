class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[1000]={0};
        for(int i=0;i<s.length();i++){
            int ch=s[i];
            arr[ch]++;
        }
        for(int i=0;i<t.length();i++){
            int ch=t[i];
            arr[ch]--;
        }
        for(int i=0;i<1000;i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
        
    }
};