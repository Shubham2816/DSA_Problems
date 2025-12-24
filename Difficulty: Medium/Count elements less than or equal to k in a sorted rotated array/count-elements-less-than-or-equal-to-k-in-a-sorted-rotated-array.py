class Solution:
    def countLessEqual(self, arr, x):
         #code here
        a=0
        arr.sort()
        for i in range(len(arr)):
            if arr[i]<=x:
                a+=1
        return a

        