from functools import reduce

n = int(input())

print("First" if reduce(lambda x, y: x^y, map(int, input().split())) else "Second")