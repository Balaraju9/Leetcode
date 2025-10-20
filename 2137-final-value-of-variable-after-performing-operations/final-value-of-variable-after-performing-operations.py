class Solution(object):
    def finalValueAfterOperations(self, o):
        j=0
        for i in range(0,len(o)):
            if o[i]=="X++" or o[i]=="++X":
                j=j+1
            else:
                j=j-1
        return j
        """
        :type operations: List[str]
        :rtype: int
        """
        