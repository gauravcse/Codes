class ComplexNum(object) :

    def __init__(self,a,b,c,d):
        self.x1=a;
        self.y1=b
        self.x2=c
        self.y2=d
    
    def add (self):
        self.sum=self.x1+self.x2
        self.ima=self.y1+self.y2
        if(self.sum==0.0) :
            print "%0.2fi"%(self.ima)
        else :
            if (self.ima < 0) :
                print "%0.2f - "%(self.sum),
                print "%0.2fi"%(-self.ima)
            elif (self.ima >0) :
                print "%0.2f + "%(self.sum),
                print "%0.2fi"%(self.ima)
            else :
                print "%0.2f"%(self.sum)
    
    def sub(self):
        self.sum=self.x1-self.x2
        self.ima=self.y1-self.y2
        if(self.sum==0.0) :
            print "%0.2fi"%(self.ima)
        else :
            if self.ima < 0 :
                print "%0.2f - "%(self.sum),
                print "%0.2fi"%(-self.ima)
            elif self.ima >0 :
                print "%0.2f + "%(self.sum),
                print "%0.2fi"%(self.ima)
            else :
                print "%0.2f"%(self.sum)
    
    def mul(self):
        self.sum=(self.x1*self.x2)-(self.y1*self.y2)
        self.ima=(self.x1*self.y2)+(self.y1*self.x2)
        if(self.sum==0.0) :
            print "%0.2fi"%(self.ima)
        else :
            if self.ima < 0 :
                print "%0.2f - "%(self.sum),
                print "%0.2fi"%(-self.ima)
            elif self.ima >0 :
                print "%0.2f + "%(self.sum),
                print "%0.2fi"%(self.ima)
            else :
                print "%0.2f"%(self.sum)
                    
    
    def div(self):
        self.deno=(self.x2)**2-(self.y2)**2
        self.sum=(self.x1*self.x2)+(self.y1*self.y2)
        self.ima=-(self.x1*self.y2)+(self.y1*self.x2)
        if(self.sum==0.0) :
            print "%0.2fi"%(self.ima)
        else :
            if self.ima < 0 :
                print "%0.2f - "%(self.sum),
                print "%0.2fi"%(-self.ima)
            elif self.ima >0 :
                print "%0.2f + "%(self.sum),
                print "%0.2fi"%(self.ima)
            else :
                print "%0.2f"%(self.sum)
    
    def mod(self): 
        self.mod1=((self.x1**2)+(self.y1)**2)**0.5
        print "%0.2f"%(self.mod1)
        self.mod2=((self.x2**2)+(self.y2)**2)**0.5
        print "%0.2f"%(self.mod2)

a,b=map(float,raw_input().split())
c,d=map(float,raw_input().split())
obj=ComplexNum(a,b,c,d)
obj.add()
obj.sub()
obj.mul()
obj.div()
obj.mod()
                
        
    