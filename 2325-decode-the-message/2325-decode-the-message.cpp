class Solution {
public:
    void createmap(unordered_map<char,char>&mapping,string key){
        char start='a';
        for(int i=0;i<key.length();i++){
            char ch=key[i];
            if(mapping.find(ch)==mapping.end()){
                mapping[ch]=start;
                start++;
            }
        }
    }
    string useMapping(unordered_map<char,char>&mapping,string message){
        string s="";
        for(int i=0;i<message.length();i++){
            char ch=message[i];
            char mappedCharacter=mapping[ch];
            s.push_back(mappedCharacter);
        }
        return s;


    }
    string decodeMessage(string key, string message){
        unordered_map<char,char>mapping;
        char space=' ';
        mapping[space]=space;
        createmap(mapping,key);
        string ans=useMapping(mapping,message);
        return ans;
        
    }
};