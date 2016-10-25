import pprint
import collections


adjList = {k: [] for k in range(1, 875715)}
adjListRev = {k: [] for k in range(1, 875715)}
edgeList = {}

with open("sccInput.txt", 'r') as fd:
    for line in fd:
        line = line.split(' ')
        line = line[:-1]
        line[0] = int(line[0])
        line[1] = int(line[1])

        adjList[line[0]].append(line[1])
        adjListRev[line[1]].append(line[0])
        edgeList[line[0]] = line[1]

pp = pprint.PrettyPrinter(indent=4)

#pp.pprint(edgeList)
#pp.pprint(adjListRev)
#pp.pprint(adjList)

t = 0
leader = {}
count = {}
def DFS1(G, v, fofV):
    """
    vis.append(v)
    for ver in G[v]:
        if ver not in vis:
            DFS1(G, ver, fofV)
    global t
    t += 1
    fofV[t] = v

    """
    #print v
    S = []
    S.append(v)
    global t
    while S != [] :
        v = S.pop()
        x = []
        for y in G[v]:
            if y not in vis:
                x.append(y)
        if v not in vis:
            vis.add(v)
            #print vis

            S.extend(x)
            #print S
        if x == [] :
            t += 1
            fofV[t] = v



def DFSloop1(G, vis, t, fofV):
    for i in range(1,875715):
        if i not in vis:
            DFS1(G, i, fofV)
            #print "Hi done with " + "i " + " in dfsloop1"

def DFS2(G, v, sV):
    """
    vis.append(v)

    leader[v] = sV
    for ver in adjList[v]:
        if ver not in vis:
            DFS2(G, ver, sV)


        #leader[ver] = v
    """
    S = []
    S.append(v)

    while S != [] :
        v = S.pop()
        leader[v] = sV
        if v not in vis:
            vis.add(v)
            #print vis
            for x in G[v]:
                if x not in vis:
                    S.append(x)
            #print S



def DFSloop2(G, vis, fofV):
    #print fofV.values()
    for i in fofV.values():
        if i not in vis:
            #print i
            DFS2(G, i, i)
            #print "Hi done with " + "i " + " in dfsloop2"






fofV = {}
volofscc = []
vis = set()

print "entering dfsloop1...."
DFSloop1(adjListRev, vis, t, fofV )
print "came outta dfsloop1 and entering sorting fofV"
fofV = collections.OrderedDict(sorted(fofV.items(), reverse = True))
print "came out of sort and entering dfsloop2"
#pp.pprint(fofV)
#pp.pprint(adjListRev)


vis = set()
DFSloop2(adjList, vis, fofV)
#pp.pprint(leader)
print "dfsloop2 done now counting nodes in SCCs"

for c in leader.values():
    if c not in count:
        count[c] = 1
    else:
        count[c] += 1

print "sorting :)"
print sorted(count.values(), reverse = True)[:5]
