# this is the function called by our embedded program
# unlike previous we'll pass arguments here ;-)

def multiply(a, b):
    print "Got a=%d, b=%d"%(a, b)
    return a*b

