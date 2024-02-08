import math
    
def integral(y,d):
    sum = 0
    x=1
    while x<y :
        sum+=((1/x)*d)
        x+=d
    return sum
    
def main():
    y = float(input("y = "))
    d = float(input("d = "))
    print("integral -> "+str(integral(y,d)))
    print("ln(x) -> "+str(math.log(y)))

if __name__=="__main__":
    main()