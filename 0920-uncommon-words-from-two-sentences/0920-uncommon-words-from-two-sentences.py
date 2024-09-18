class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        commonSet = set()
        uncommonList = []
        for word in s1.split(" "):
            if word in uncommonList:
                uncommonList.remove(word)
                commonSet.add(word)
            elif word not in commonSet:
                uncommonList.append(word)
        for word in s2.split(" "):
            if word in uncommonList:
                uncommonList.remove(word)
                commonSet.add(word)
            elif word not in commonSet:
                uncommonList.append(word)
        return uncommonList   



        