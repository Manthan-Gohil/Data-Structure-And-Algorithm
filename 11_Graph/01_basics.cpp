// graph ->
// graph is a type of data structure which has combination of nodes and edges

// type of graph
// 1. undirected graph (0->1 && 1->0) both are possible and true
// 2. directed graph (0->1 || 1->0) only one is true

// node-> entitiy to store data
// edge-> connection layer for nodes
// degree-> how many edges connected to node

// in directed graph, there is two degrees (indegrees and outdegrees)
// indegree -> how many edges coming in to nodes
// outdegree -> how many edges coming out to nodes

// weighted graph-> edges have some weights/values

// path-> sequence of nodes coming and only one node is coming one time in path

// cyclic graph -> directed graph in which end node reach to starting node

// graph representation
// 1. adjacency matrix (rows and colm are node values and in matrix when two nodes are connected, its value is 1 and no connected value is 0)
// 2. adjacency list (each node is value stored in map key and all the connected neighbour nodes are in list as value in map)