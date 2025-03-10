class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for word in strs:
            sorted_s = "".join(sorted(word))
            if sorted_s not in d:
                d[sorted_s] = [word]
            else:
                d[sorted_s].append(word)
        
        ans = []
        for val in d.values():
            ans.append(val)

        return ans
        