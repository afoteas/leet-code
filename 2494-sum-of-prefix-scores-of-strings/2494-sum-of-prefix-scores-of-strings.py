class TrieNode:
    def __init__(self):
        self.count = 0
        self.child = [None] * 26


class Solution:
    @cache
    def calcPrefix(self, word: str, words: tuple) -> int:
        count=0
        for w in words:
            if(w.startswith(word)):
                count+=1
        return count

    def sumPrefixScoresSlow(self, words: List[str]) -> List[int]:
        ret=[]
        tuple_world = tuple(words)
        for word in words:
            r=0
            tmp=""
            for c in word:
                tmp+=c
                rr = self.calcPrefix(tmp, tuple_world)
                r+= rr
                if rr == 1:
                    r+=len(word)-len(tmp)
                    break
            ret.append(r)
        return ret

    def sumPrefixScores(self, words: List[str]) -> List[int]:
        def insert_key(root:TrieNode, key:str):
            curr = root
            for c in key:
                index = ord(c) - ord('a')
                if curr.child[index] is None:
                    new_node = TrieNode()
                    new_node.count = 1
                    curr.child[index] = new_node
                else:
                    curr.child[index].count += 1
                curr = curr.child[index]
        @cache
        def find_score(root:TrieNode, key:str) -> int:
            curr = root
            ret = 0
            for c in key:
                index = ord(c) - ord('a')
                ret+=curr.count
                if curr.child[index] is None:
                    return ret
                curr = curr.child[index]
            ret += curr.count
            return ret

        ret=[]
        root = TrieNode()
        for w in words:
            insert_key(root, w)
        print(root.count)
        for w in words:
            ret.append(find_score(root,w))
        return ret


        