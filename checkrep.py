'''     CREATED BY GAURAV MITRA         '''

'''     SINCE OUT REQUIRED RESULT CAN TAKE TWO DESIRED VALUES
        1. REPETITION
        2. NO REPETITION
        WE DESIGN AN ALGORITHM WHICH MAKES USE OF THE BINARY NATURE OF THE OUTPUT
        LET REPETITION MEANS -1 AND NO REPETITION MEANS +1
        IN CASE OF REPETITION WE CHECK THE INDEX OF THE ARRAY AT THAT PARTICULAR VALUE
        IF IT IS NEGATIVE WE SAY THERE IS REPETITION ELSE WE MAKE THAT VALUE NEGATIVE AND
        PROCEED TO THE NEXT ELEMENT
'''
def find_duplicate(arr,n) :
    for i in xrange(n) :
        if(arr[arr[i]-1] < 0) :
            print '{} {}'.format(str(abs(arr[i-1]))," IS REPEATED")
        else :
            arr[arr[i]-1]=-1*arr[arr[i]-1]

if __name__=='__main__' :
    arr=list()
    n=int(raw_input("Enter the Value of N : "))
    k=int(raw_input("Enter the Number of Repetitions : "))
    print '{}{}{}'.format("ENTER THE ",str(n+k),"ELEMENTS")
    for i in xrange(n+k) :
        element=int(input())
        assert (element >0 and element <= n)
        arr.append(element)
    find_duplicate(arr,n+k)
