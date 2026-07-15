class Solution:
    def firstUniqChar(self, s: str) -> int:
        char_count = {}

        # freq map
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
        
        # find the unique char & first show
        for index, char in enumerate(s):
            if char_count[char] == 1:
                return index
        
        return -1