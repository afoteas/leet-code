class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        @cache
        def internal(s:str) -> bool:
            if len(s)==0:
                return True
            for i in range(0,len(s)):
                if s[0:i+1] in wordDict and internal(s[i+1:]):
                    return True
            return False
        return internal(s)
                    
                
        