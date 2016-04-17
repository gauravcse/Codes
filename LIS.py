l=list()
dp=list()
for i in range(9):
    t=int(input())
    l.append(t)
    dp.append(1)
for i in range(1,len(l)) :
    m=0
    for j in range(i):
        if(l[i]>l[j] and m<(dp[j]+1)) :
            m=dp[j]+1
    dp[i]=m
print dp
    
            
        
                   
