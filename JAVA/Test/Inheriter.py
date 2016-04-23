class MaxSizeList(object):
    
    def __init__(self, value):
        self.list=[]
        try :
            val=int(value)
        except ValueError :
            val=0
        self.len=val
    
    def push(self,arguement):
        length=len(self.list)
        if (length==self.len) :
            self.list.append(arguement)
            self.list.pop(0)
        else :
            self.list.append(arguement)
    
    def get_list(self): 
        print self.list
            
        
        
    