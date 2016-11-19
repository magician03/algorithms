arr = list()
with open("input-1.txt", 'r') as fd:
    for line in fd:
        line = line.split('\n')
        arr.append(int(line[0]))
        
        
#print arr

#making hashTable

hashT = {}

for x in range(0, 10000000):
    hashT[x] = set()
    
for x in arr:
    y = x % 1000000
    hashT[y].add(x)
    
#print hashT

count = 0

for t in range(-10000, 10001):
    print t
    for x in arr:
        y = t - x
        hashy = y % 1000000
        #print y
        if(y in hashT[hashy]):
            if y != x :
               # print count
                count += 1
                print count
                break
        
print count
         