import math
def is_prime(n):
    if n % 2 == 0 and n > 2: 
        return False
    return all(n % i for i in range(3, int(math.sqrt(n)) + 1, 2))

t=input()
count=0
while t>0 :
    t-=1
    count+=1
    val=int(raw_input())
    level=0
    while is_prime(val) == False and val>2:
        i=2
        while is_prime(val-i)==True and (val-i)>2 :
            i+=1
        if (val-i)>0 :
            val-=i
            level+=1
    print 'Case #{}: {}'.format(count,level)
        
    
