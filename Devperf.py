class Star() :
    def __init__(self,x,y) :
        self.x=x
        self.y=y
t=int(input())
while t>0 :
    t-=1
    n,m=map(int,raw_input().split())    
    arr=[['.' for x in range(m)] for x in range(n)]
    stars=list()
    for i in range(n) :
        p=raw_input()
        for j in range(m) :
            arr[i][j]=p[j]
            if(arr[i][j]=='*') :
                obj=Star(i,j)
                stars.append(obj)
    low=100000000
    for i in range(n) :
        for j in range(m) :
            high=0
            for item in stars :
                x=int(item.x)
                y=int(item.y)
                temp=max(0,abs(x-i),abs(y-j))+1
                if(temp>high) :
                    high=temp
            if(high<low) :
                low=high
    print low
                
            
     


