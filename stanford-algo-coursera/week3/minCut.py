import random
import copy
hashMapP = {}
minCut = 200

with open("finalInput.txt", 'r') as fd:
    for line in fd:
        line = line.split('\t')
        hashMapP[line[0]] = line[1:-1]
        
#print hashMapP

def merge(A, B, adjList):
    # 1.add all values of B to A
    # 2.remove B
    # 3.replace B with A in all other lists
    # 4.remove self-loops
    
    # 1
    adjList[A].extend(adjList[B])
    
    #2
    del adjList[B]
    
    #3
    for key, valueList in adjList.items():
        for n, value in enumerate(valueList):
            if value == B:
                valueList[n] = A
                
    #4
    adjList[A] = [x for x in adjList[A] if x != A]
    
    
def contract(adjList):
    while len(adjList.keys()) > 2 :
        A = random.choice(adjList.keys())
        B = random.choice(adjList[A])
        
        
        merge(A, B, adjList)
    
    #print adjList
    #print "\n\n\n"
    return

i = 0
while (i < 40000 ):
    hashMap = copy.deepcopy(hashMapP)
    contract(hashMap)
    k = len(hashMap.values()[0])
    if minCut > k :
        minCut = k
    #print k
    i += 1


print minCut
            
        