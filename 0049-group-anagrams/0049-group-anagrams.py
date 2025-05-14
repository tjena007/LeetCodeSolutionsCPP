class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}

        for s in strs:
            sortStr = "".join(sorted(s))
            d[sortStr] = d.get(sortStr,[])
            d[sortStr].append(s)
        
        ans = []
        for val in d.values():
            ans.append(val)
        
        return ans