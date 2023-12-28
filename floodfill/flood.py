# flood fill

def impr():
    global m
    for i in range(0,9):
        for j in range(0,9):
            print(str(m[i][j])+" ",end="")
        print()

def floodFill(x,y):
    global m
    if (m[x][y]==2):
        return
    if (m[x][y]==1):
        return
    m[x][y]=2
    print(str(x)+" : "+str(y))
    if (x<8):
        floodFill(x+1,y)
    if (x>0):
        floodFill(x-1,y)
    if (y<8):
        floodFill(x,y+1)
    if (y>0):
        floodFill(x,y-1)
    return

m=[[1,1,1,1,1,1,1,1,1],\
   [1,0,0,0,1,0,0,0,1],\
   [1,0,0,0,1,0,0,0,1],\
   [1,0,0,1,0,0,0,0,1],\
   [1,1,1,0,0,0,1,1,1],\
   [1,0,0,0,0,1,0,0,1],\
   [1,0,0,0,1,0,0,0,1],\
   [1,0,0,0,1,0,0,0,1],\
   [1,1,1,1,1,1,1,1,1]]\

print("-"*30)
impr()
print("-"*30)
floodFill(4,4)
print("-"*30)
impr()
print("-"*30)
