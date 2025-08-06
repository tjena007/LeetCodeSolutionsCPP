class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        #build trie
        def buildTrie(words):
            root = TrieNode()
            for word in words:
                node = root
                for ch in word:
                    if ch not in node.children:
                        node.children[ch] = TrieNode()
                    node = node.children[ch]
                node.word = word
        
            return root

        result = []
        def dfs(i,j,node):
            char = board[i][j]
            if char not in node.children:
                return
            
            next_node = node.children[char]

            if next_node.word:
                result.append(next_node.word)
                next_node.word = None 
            
            board[i][j] = '#'

            for dx, dy in [(-1,0), (1,0), (0,-1), (0,1)]:
                ni, nj = i + dx, j + dy
                if 0 <= ni < len(board) and 0 <= nj < len(board[0]) and board[ni][nj] != '#':
                    dfs(ni, nj, next_node)

            board[i][j] = char  # Restore original character

        
        root = buildTrie(words)
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                dfs(i, j, root)
        return result

        