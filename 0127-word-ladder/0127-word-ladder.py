class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        s = set()
        for word in wordList:
            s.add(word)

        if endWord not in s:
            return 0

        q = deque()
        q.append([beginWord,1])

        while q:
            for i in range(len(q)):
                word,seq = q.popleft()
                if word in s:
                    s.remove(word)

                for k in range(len(word)):
                    for ch in range(ord('a'), ord('z') + 1):
                        new_str = word[:k] + chr(ch) + word[k+1:]
                        if new_str in s:
                            q.append([new_str,seq+1])
                            if new_str == endWord:
                                return seq + 1
        
        return 0


