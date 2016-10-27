### Dijkstra's Shortest path algo

```
G(V, E)

# typical object { vertex : [ [neighbour vertex, distance ], ....]}

dist, prev, unvis

for vextex in G:
    dist[v] = maxDist
    prev[v] = null
    add v to unvis
    
dist(source) = 0

while unvis not empty:
    ver = smallest dist
    remove ver from unvis
    
    for verN of ver:
        alt = dist[ver] + G[ver]
        if alt < dist[verN]:
            dist[verN] = alt
            prev[verN] = ver
    
    

```