#User function Template for python3

class Solution:
    def leftRotate(self, arr, d):
        # code here
        part=arr[:d]
        del arr[:d]
        arr.extend(part)
        return(arr)