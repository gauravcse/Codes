def gcd(a,b) :
	if b==0:
		return a
	else :
		return gcd(b,a%b)

t=input()
while t>0 :
	t-=1
	n=raw_input()
	flag=0
	num=""
	den=""
	for i in n :
		if i=='.' :
			flag=1
			continue
		if flag==0 :
			num+=i
		else :
			den=den+i
	if den=="" :
		print ("1")
	else :
		l=len(den)
		d=int(den)
		nu=int(num)
		g=gcd(nu,d)
		print "%d"%(((10)**d)/g)
