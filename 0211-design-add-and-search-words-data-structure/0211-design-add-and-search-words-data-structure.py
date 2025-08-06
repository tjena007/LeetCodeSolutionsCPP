class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEnd = False


class WordDictionary:
    def __init__(self):
        self.root = TrieNode()
        

    def addWord(self, word: str) -> None:
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.isEnd = True
        

    def search(self, word: str) -> bool:
        #use recursion
        node = self.root

        return self.dfs(word, 0, self.root)

    
    def dfs(self,word,index,node):
        if index == len(word):
            return node.isEnd
        
        if word[index] == '.':
            for ch in node.children:
                if self.dfs(word, index + 1, node.children[ch]):
                    return True
            return False
        elif word[index] not in node.children:
            return False
        return self.dfs(word,index + 1,node.children[word[index]])

        
# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)