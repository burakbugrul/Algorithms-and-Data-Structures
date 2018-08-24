"""
    Burak Bugrul
    Z-Function O(N)
"""

def z_function(s):

    z = [0]*len(s)
    l, r = 0, 0  # left and right boundaries of current prefix match

    for i in range(1, len(s)):

        z[i] = max(0, min(r - i + 1, z[i - l]))  # We can use previously calculated values for new z[i] value, but we can not go beyond right boundary without checking values

        while i + z[i] < len(s) and s[i + z[i]] == s[z[i]]:  # Checking values beyond right boundary in a simple way
            z[i] += 1
        
        if i + z[i] - 1 > r:
            l, r = i, i + z[i] - 1  # New boundaries are set
    
    return z

if __name__ == "__main__":
    print("Z array", z_function(input()), sep="\n")
