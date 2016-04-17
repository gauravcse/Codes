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
    if(is_prime(val)== True) :
        print 'Case #{}: {}'.format(count,0)
    else :
        if(val%2==0) :
            print 'Case #{}: {}'.format(count,(val/2)-1)
        else :
            print 'Case #{}: {}'.format(count,(val-3)/2)
        
        
