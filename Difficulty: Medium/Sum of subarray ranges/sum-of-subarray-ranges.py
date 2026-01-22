from math import inf
class Solution:
    def subarrayRanges(self, arr):
        def span(arr):
            S = []
            res = 0
            for i in range(len(arr)):
                while S and arr[S[-1]] <= arr[i]:
                    j = S.pop()
                    res += arr[j] * (i - j) * (j - (S[-1] if S else -1))
                S.append(i)
            return res

        return span(arr + [inf]) + span(list(map(lambda x: -x, arr)) + [inf])
