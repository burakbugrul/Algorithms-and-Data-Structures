"""
    Burak Bugrul
    Problem link: https://www.hackerrank.com/challenges/string-similarity/problem
"""

for _ in range(int(input())):
    
    s = input()
    z = [0]*len(s)

    res, l, r = 0, 0, 0

    for i in range(1, len(s)):

        z[i] = max(0, min(r - i + 1, z[i - l]))

        while i + z[i] < len(s) and s[i + z[i]] == s[z[i]]:
            z[i] += 1
        
        if i + z[i] - 1 > r:
            l, r = i, i + z[i] - 1
    
    for number in z:
        res += number
    
    print(res + len(s))
