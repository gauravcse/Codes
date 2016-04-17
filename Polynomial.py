t=input()
count=0
while t>0 :
	count+=1
	t-=1
	n,p,u,r,s=map(int,raw_input().split())
	while n>0 :
		n-=1
		if((p+r)>u and (p-s)<=0) :
			break
		elif (p+r)<=u :
			p+=r
		elif (p-s)>=0 :
			p-=s
	print 'Case #{}: {}'.format(count,p)
