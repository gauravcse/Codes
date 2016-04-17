import math
def is_prime(n):
    if n % 2 == 0 and n > 2: 
        return False
    return all(n % i for i in range(3, int(math.sqrt(n)) + 1, 2))
primes=[]
for i in range(2,10000009) :
    if is_prime(i) :
        primes.append(i)
t=int(raw_input())
while t>0 :
    t-=1
    n=int(input())
    pri=dict()
    for element in primes :
        if is_prime(n) :
            pri[n]=pri.get(n,0)+1
            n=1
            break
        while n%element == 0 :
            n/=element
            pri[element]=pri.get(element,0)+1
        if n==1 :
            break
    even=odd=0
    #print pri
    for key in pri :
        if pri[key]%2==0 :
            even+=1
        else :
            odd+=1
    if even>odd :
        print "Psycho Number"
    else :
        print "Ordinary Number"

