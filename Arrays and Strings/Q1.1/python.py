class Solution:
    def UniqueChar(self, string):
        if string == '':
            return true
    
        string = sorted (string)
        prev = string[0]
        for char in string[1:]:
            if char == prev :
                return false

            prev = char

        return true
