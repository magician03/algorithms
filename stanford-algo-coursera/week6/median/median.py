A = list()
A.append(0)
median = list()
totalSum = 0
i = 0


def maxHeapify( A, i):
    l = left(A, i)
    r = right(A, i)
    if l <= len(A)-1 and A[l] > A[i]:
        largest = l
    else:
        largest = i
    if r <= len(A)-1 and A[r] > A[largest]:
        largest = r
    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        maxHeapify(A, largest)

    
    
def left(A, i):
    return 2*i
    
def right(A, i):
    return 2*i + 1
    
def parent(A, i):
    return i/2

with open("input.txt", 'r') as fd:
    for line in fd:
        num = int(line)
        A[0] = num
        A = [0] + A
        i += 1 
        if i < 10:
            print A
        #A.sort()
        maxHeapify(A, i)
        n = len(A)-1
        if n % 2 == 0:
            med = A[(n/2)]
        else:
            med = A[((n+ 1)/2)]
            
        totalSum += med
        
        if i < 10:
            print A
        
print totalSum
print ( totalSum % 10000 )
    
