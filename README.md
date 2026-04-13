# A11: Tree [Allowed Submissions: 3]

* Please note that this assignment allows **maximum 3 submissions**, and the most recent submission will be used. The code that is not compiled, even due to a missing semicolon, will receive zero points. The code that is correct locally but has error on the autograder will be considered for proportionate points.

In this assignment, you will

	* linked_binary_tree.hpp
	* tree_traversal.hpp

The required functions and inner classes have been declared. Some of the functions have been discussed in class and are for self-practice, which you should write and match with the slides in case of error.

The following are the new functions that you will implement:

```cpp
int count_left_leaves() const{
    // ToDo (use recursion)
    //count nodes that are leaves in a binary tree and that are the left child of their respective parent. The root is not counted.
}

int count_left_leaves_bfs() const {
    // ToDo (use breadth first search)
    //count nodes that are leaves in a binary tree and that are the left child of their respective parent. The root is not counted.
}
```



## Submissions:

* Submit linked_binary_tree.hpp and tree_traversal.hpp with complete implementation.
* Submit test.cpp that has at least one test case for the positions function of the tree. 
  * The positions functions should call inorder traversal and return all positions.


## Rubrics:

* Autograder: 8 Points
* -2 points for build/exe uploads
* Manual Grading: 7 Points
# ProjA11
