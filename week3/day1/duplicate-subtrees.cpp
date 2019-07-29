/*
I was not able to solve this problem.

This is the approach I thought of:
First you create an unordered set which takes in a vector and a node pointer.

Then you start on the root node. You  call a function on the root node called "getNodeVector". This funciton will recursively go down each node below your current node and add the node's value to a vector as it goes down. At the end it will recurively return and at your current node, which again for us at the moment is root, you have a vector representing the entire tree and it's entries as an array. You add this vector and a pointer to your current node to the unordered map.

You then call this same function on the left tree and right tree and and essentially for every single node. At the end, you should be able to tell which vector-pointer entries are doubles based on their vector's matching or not.

The problem:
I do not think a vector representing the tree for a particular node is a good key. This was my issue, how would a map function be able to use a vector as a key? And even if it could, each comparison would take linear time.

I was unable to program this assignment.
*/