class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.result = []
        self.board = board
        root = self.buildTrie(words)
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.dfs(i, j, root)
        
        return self.result

    def buildTrie(self, words):
        root = TrieNode()
        for word in words:
            node = root
            for ch in word:
                if ch not in node.children:
                    node.children[ch] = TrieNode()
                node = node.children[ch]
            node.word = word
        return root

    def dfs(self, i, j, node):
        char = self.board[i][j]
        if char not in node.children:
            return

        next_node = node.children[char]

        if next_node.word:
            self.result.append(next_node.word)
            next_node.word = None  # Avoid duplicates

        self.board[i][j] = '#'  # Mark as visited

        for dx, dy in [(-1,0), (1,0), (0,-1), (0,1)]:
            ni, nj = i + dx, j + dy
            if 0 <= ni < len(self.board) and 0 <= nj < len(self.board[0]) and self.board[ni][nj] != '#':
                self.dfs(ni, nj, next_node)

        self.board[i][j] = char  # Restore original character
