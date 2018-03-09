class Solution(object):
    def findWords(self, words):
        line1 = set('qwertyuiopQWERTYUIOP')
        line2 = set('asdfghjklASDFGHJKL')
        line3 = set('zxcvbnmZXCVBNM')
        ans = []
        for word in words:
            w = set(word)
            if w <= line1 or w <= line2 or w <= line3:
                ans.append(word)
        return ans;
