# cook your dish here
from functools import lru_cache
t = int(input())
for _ in range(t):
    n = int(input())
    red = list(map(int,input().split()))
    blue = list(map(int,input().split()))
    ans=0
    
    @lru_cache(1000)
    def dp(i,r,b):
        global ans
        if i == n:
            ans = max(ans,min(r,b))
            return;
        dp(i+1,r+red[i],b)
        dp(i+1,r,b+blue[i])
        
    dp(0,0,0)
    print(ans)
        