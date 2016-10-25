### Pseudo Code for Programming assignment 3

```
    hashMap, minValues
    
    open( <inputFile>, 'r')
    split lines
    split each line with '\t'
    store the values in dict 'hashMap'
    
    merge( vextex A, vertex B, map hashMap )
        add all edge-vertices of B to A
        remove the B-key from the map
        reorder the map by replacing all B-occurences with A
        remove any self-loops, if exist
        
    contract(map)
        while len(map.iterkeys()) > 2 :
            choose A from map.iterkeys() randomly
            choose B from map.iterkeys() randomly
            merge(A, B, hashMap)
        
        return
        
        
    while( i > testTimes )
        copy(parentMap, map)
        contract(map)
        minValues[i] = len(map.itervalues()[0])
        
    print min(minValues)
```