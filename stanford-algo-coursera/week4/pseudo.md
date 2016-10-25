### Size of maximum Strongly Connected Components

##### DFS of a graph
```
adjList{}
stack st[]
visited vis[]
DFS(G, v)
    vis.append(v)
    connectedV = adjList[v]
    for ver in connectedV
        if ver not in visited
            stack.push(ver)
            DFS(ver)
            stack.pop()
            
    return

```

##### BFS of a graph
```
adjList{}
queue qu[]
visited vis[]
BFS(G, v)
    vis.append(v)
    connectedV = adjList[v]
    for ver in connectedV
        if ver not in visited
            qu.enque(ver)
            
    BFS(qu.dequqe())
            
    return

```
##### DFS loop
```
for each unvisited vextex in G
    DFS(G, v)

```


##### KosaRaju's Algo for SCC
```
GRev = edge reversed graph of G

visited[]
fofV{}
volofscc[]
DFSloop(GRev) ->remember the finish time of each V and store in fofV
                loop goes acc to vextex numbering
refresh visited[]

DFSloop(G)  ->loop goes acc to fofV order from lar to small
            ->assign leaders of each scc in leaders[]

```