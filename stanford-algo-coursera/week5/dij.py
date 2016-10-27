verG = {}
distG = {}

def length(verN, ver):
    x = verG[ver].index(verN)
    y = distG[ver][x]
    
    return int(y)
    

with open("finalInput.txt", 'r') as fd:
    for line in fd:
        line = line.split("\t")
        #print line
        key = line[0]
        line = line[1:-1]
        verG[key] = list()
        distG[key] = list()
        #print type(verG[key])
        #print type(distG[key])
        for x in line:
            x = x.split(',')
            verG[key].append(x[0])
            distG[key].append(x[1])

#print verG
#print distG
distV = {}
prevV = {}
unVis = []

for ver in verG.keys():
    distV[ver] = 1000000
    prevV[ver] = None
    unVis.append(ver)
    
#print unVis

distV['1'] = 0

#print min(distV.values())

while unVis != []:
    unvD = []
    for x in unVis:
        unvD.append(distV[x])
    minD = min(unvD)
    for key, value in distV.iteritems():
        if value == minD and key in unVis:
            ver = key
            
    #print unVis
    #print ver
    unVis.remove(ver)
    #print ver
    
    for verN in verG[ver]:
        alt = distV[ver] + length(verN, ver)
        if alt < distV[verN]:
            print [alt, distV[verN]]
             
            distV[verN] = alt
            prevV[verN] = ver
        else:
            print [alt, distV[verN]]
            
toF = ['7','37','59','82','99','115','133','165','188','197']
ans = list()

for x in toF:
    ans.append(distV[x])
    
print ans