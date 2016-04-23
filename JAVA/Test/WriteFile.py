import datetime

class WriteFile(object):
    def __init__(self,files):
        self.filep=open(files,'w')
    def write(self,message) :
        self.filep.write(message)
        self.filep.close()
    
class LogFile(WriteFile):
    def __init__(self,fname):
        super(WriteFile,self).__init__(fname)
    
    def write(self,mess):
        current_dt=datetime.datetime.now().strftime('%Y-%m-%d %H:%M')
        strn=current_dt+" "+mess
        super(LogFile,self).write(strn)

class DelimFile(WriteFile):
    def __init__(self,listst,delim):
        super(WriteFile,self).__init__(listst)
        self.d=delim
    def write(self, message):
        l=len(message)
        for i in range(0,l) :
            self.filep.write(i)
            self.filep.write(self.d)
        super(WriteFile,self).write("")

log = LogFile('log.txt')
log.write("this is a long message")
log.write("this is amother long message")