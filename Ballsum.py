from fractions import gcd
from math import ceil
while True :
    n,k=map(int,raw_input().split())
    if(n==-1 and k==-1) :
        break
    else :
        r=ceil((float(k)/2.0))
        #print 'R value is {}'.format(r)
        r=int(r)
        r-=1
        numerator=int(2*((r*k)-(r*(r+1))))
        #print '{} is Numerator'.format(numerator)
        denominator=int(n*(n-1))
        g=gcd(numerator,denominator)
        if numerator==denominator :
            print "1"
        elif numerator==0 :
            print "0"
        else :
            print '{}/{}'.format(numerator/g,denominator/g)
