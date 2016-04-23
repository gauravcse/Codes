t=int(raw_input(""))
while (t>0):
    t-=1
	n=int(raw_input())
    sum=0.0
    for i in range(1,n+1) :
        sum+=1/float(i)
    sum*=n
    print sum
	print