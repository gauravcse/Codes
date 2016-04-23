import simplegui
def tick() :
    print "tick"
timer=simplegui.create_timer(2000,tick)
timer.start()