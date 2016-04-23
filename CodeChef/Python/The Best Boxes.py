
t=(int)(raw_input())
while t>0 :
    t-=1
	p,s=map(int,raw_input().split())
	c=float((p**2-24*s)**0.5)
	b=(float(p)-c)/12
	v=((s/2)-(float(p)*b/4)+(b*b))*b
	print "%0.2f"%v
	print
