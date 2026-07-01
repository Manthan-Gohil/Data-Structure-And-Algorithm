// heap ->
// heap is the complete binary tree data structure that comes with a heap order property
// CBT ->
// CBT have two properties
// 1. every level is completly filled except the last level
// 2. nodes always added from the left

// two types of heap -> max heap and min heap

// max heap -> child nodes values are less than its parent node (p>c)
// min heap -> parent node values are less than its child node (p<c)

// insertion in heap (head are implemented using array)
// if node at ith index
// left child will be at 2*i index
// right child will be 2*i+1 index 
// parent = (i/2) index

// approach to insertion
// 1. add the new node to the end of array
// 2. take it to its correct position

// deletion in heap
// it means always delete the root node

// approach to delete a node 
// 1. place last node and put it to the root node (swap root node with last node)
// 2. remove the last node
// 3. propagate root node to its correct position

// heapify algorithm -> convert normal array into heap data structure(either max heap or min heap)
// ek node ko uthke usko uski sahi jagah pe le jana heapify function ka kaam h
// in CBT leaf node have index from (n/2+1) to nth index
// and leaf nodes are already in heap property(either max heap or min heap)

// take loop from n/2 to 1 reverse order from right node to left node

// as of now we are following 1 based indexing means formula for left and right will be
// left -> 2*i
// right -> 2*i+1

// for 0 based indexing
// left -> 2*i+1
// right -> 2*i+2