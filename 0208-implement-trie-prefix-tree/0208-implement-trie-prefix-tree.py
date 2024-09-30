class Trie:

    def __init__(self):
        # self.next = [None for _ in range(26)]
        self.next = [None]*26
        self.end = False
        

    def insert(self, word: str) -> None:
        curr = self
        for c in word:
            index = ord(c) - ord('a')
            if not curr.next[index]:
                node = Trie()
                curr.next[index] = node
            curr = curr.next[index]
        curr.end = True

    def search(self, word: str) -> bool:
        curr = self
        for c in word:
            index = ord(c) - ord('a')
            if not curr.next[index]:
                return False
            curr = curr.next[index]
        return curr.end
        

    def startsWith(self, prefix: str) -> bool:
        curr = self
        for c in prefix:
            index = ord(c) - ord('a')
            if not curr.next[index]:
                return False
            curr = curr.next[index]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)