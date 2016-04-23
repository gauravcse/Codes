
hash_map=[]
hash_map.extend(range(1,27))
prime=29
text=raw_input()
pattern=raw_input()
tlen=len(text)
plen=len(pattern)
thstatus=0
phstatus=0

def main():
    flag=True
    count=plen-1
    while(flag and count>=0) :
        hash_init_p(pattern,plen-count-1,count+1)
        for i in range(0,tlen-count+1) :
            hash_init_t(text,i,count+1)
            if(thstatus==phstatus) :
                if(pattern[plen-count-1:plen]==text[i:count+1+i]) :
                    flag=False
                    if(i>plen-count-1) :
                        print (plen-count-1)
                    else :
                        print i
                
        count+=1
            
def hash_init_t(txt,index,l):
    if(thstatus==0):
        sub=txt[index:index+l]
        for char in sub:
            character=int(char)-96
            thstatus+=character
        thstatus%=prime
    else :
        repla=txt[index-1]
        ad=txt[index+l]
        repla=int(repla)-96
        ad=int(ad)-96
        thstatus=(thstatus+ad-repla)%prime

def hash_init_p(txt,index,l):
    if(phstatus==0):
        sub=txt[index:index+l]
        for char in sub:
            character=int(char)-96
            phstatus+=character
        phstatus%=prime
    else :
        repla=txt[index-1]
        ad=txt[index+l]
        repla=int(repla)-96
        ad=int(ad)-96
        phstatus=(phstatus+ad-repla)%prime

            
                        