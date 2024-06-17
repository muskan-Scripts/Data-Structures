//the vector vect contains nodes in inorder traversal of a tree. you have to convert this bst into balanced bst
Node* makebst(Node* &root, vector<Node*> &vect, int start, int end){
    if(start>end){
        return NULL;
    }
    root=vect[((start+end)/2)+1];
    root->left=makebst(root->left, vect, start, (start+end)/2);
    
    root->right=makebst(root->left, vect, ((start+end)/2)+2, end);
    return root;
}
//the above code doesnt work because of the reason provided below
When start and end are equal, the expression ((start+end)/2)+1 will return end+1, which is outside of the start..end (inclusive) range.

That is a two-fold problem:

when end is the last valid index of the vector, this access in vect leads to undefined behaviour, which can be a segmentation error. This scenario happens when the vector has a size of 1.

when end is not the last valid index of the vector this leads to a recursive call that has the same values for start and end, leading to infinite recursion and eventually a stack limit overrun.

The corrected code uses an expression for mid that is guaranteed to stay within the limits of start and end.

A second issue (unrelated to your question) is that your code never does anything with root->right.

//the correct code is 
Node* makebst(Node* &root, vector<Node*>& vect, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    root = vect[mid];
    root->left = makebst(root->left, vect, start, mid - 1);
    root->right = makebst(root->right, vect, mid + 1, end);
    return root;
}