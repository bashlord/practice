import sys

def getMax(n, sizes):
    stack = []
    maxSize = 0
    top = 0
    toparea =0
    i = 0
    n = int(n)
    while i < n:
        #print( "i: " +str(i) + " n: " + str(n) )
        if( not stack or sizes[stack[len(stack)-1]] <= sizes[i]):
            #if(not not stack):
                #print( " sizes[stack[len(stack)-1]]: " + str(sizes[stack[len(stack)-1]]))
            #print("  sizes[i]: "+str(sizes[i])  )
            stack.append(i)
            i+=1
        else:
            top = stack[len(stack)-1]
            stack.pop()
            #print(" top: "+top)
            toparea = sizes[top] * (i if not stack else i-stack[len(stack)-1]-1  )
            #print("  toparea: "+toparea)
            if(maxSize < toparea):
                maxSize = toparea
                
    while(not not stack):
        top = stack[len(stack)-1]
        stack.pop()
        toparea = sizes[top] * (i if not stack else i-stack[len(stack)-1]-1  )
        
        if(maxSize < toparea):
            maxSize = toparea
     
    return maxSize

def main():
    N = input()
      
    sizes = input().split()
    sizes = [int(i) for i in sizes]
    #print(sizes)
    print(getMax(N,sizes))
      
  
if __name__ == '__main__':
    main()
