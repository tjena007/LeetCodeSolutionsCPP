class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0

        q = deque()
        q.append((beginWord, 1))

        while q:
            word, length = q.popleft()
            if word == endWord:
                return length
            for i in range(len(word)):
                for c in range(ord('a'), ord('z') + 1):
                    newWord = word[:i] + chr(c) + word[i+1:]
                    if newWord in wordSet:
                        q.append((newWord, length + 1))
                        wordSet.remove(newWord)  # Remove as soon as it's added to queue

        return 0
