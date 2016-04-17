from math import ceil
class Star() :
    def __init__(self,x,y) :
        self.x=x
        self.y=y
def check(x1,y1,x2,y2) :
    if(x1==x2) :
        temp=abs(y1-y2)
        if temp==1 :
            return 2
        else :
            return int(ceil(float(y1+y2)/2.0))
    elif (y1==y2) :
        temp=abs(x1-x2)
        if temp==1 :
            return 2
        else :
            return int(ceil(float(x1+x2)/2.0))
    elif(abs(x1-x2)==abs(y1-y2)) :
        if(abs(x1-x2)==1) :
            return 2
        else :
            return int(ceil(min(0,(x1+x2),(y1+y2))/2.0))
    else :
        temp1=abs(x1-x2)
        temp2=abs(y1-y2)
        return max(0,temp1,temp2)+1
    
t=int(input())
while t>0 :
    t-=1
    n,m=map(int,raw_input().split())
    stars=list()
    for i in range(n) :
        p=raw_input()
        for j in range(m) :
            if(p[j]=='*') :
                obj=Star(i+1,j+1)
                stars.append(obj)
    if(len(stars)==0) :
        print "0"
    elif(len(stars)==1) :
        print "1"
    else :
        mini=1000000000
        for i in range(len(stars)-1):
            maxi=0
            x1=stars[i].x
            y1=stars[i].y
            for j in range(i+1,len(stars)) :
                x2=stars[j].x
                y2=stars[j].y
                loc=check(x1,y1,x2,y2)
                if(loc>maxi) :
                    maxi=loc
            if(maxi<mini) :
                mini=maxi
        print mini
        
