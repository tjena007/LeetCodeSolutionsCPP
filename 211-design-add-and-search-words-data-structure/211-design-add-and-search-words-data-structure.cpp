class WordDictionary {
public:
    map<int,vector<string>> m;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        m[word.size()].push_back(word);
    }
    
    bool match(string s1,string s2){
        for(int i=0;i<s1.size();i++){
            if(s1[i] == '.') continue;
            
            else if(s1[i]!=s2[i]) return false;
        }
        
        return true;
    }
    
    bool search(string word) {
        int size = word.size();
        // if(!m.find(size)) return false;
        
        for(auto i: m[size]){
            if(match(word,i)) return true;
            
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */