TreeNodePtr binaryTreeSearch(TreeNodePtr * rootPtr, int key) {

    // If the tree is empty, return NULL
    if (rootPtr == NULL)
        return NULL;

    // Mark the current node
    TreeNodePtr cur = rootPtr;

    // While the key has not yet been found
    while (cur->data != key) {

        // If no children and not the key, return NULL
        if (cur->data != key && cur->leftPtr == NULL && cur->rightPtr == NULL) {
            return NULL;
        }

        // Store the value to be compared
        int val = cur->data;

        // Value is less and left child exists
        if (key < val && cur->leftPtr != NULL) {
            cur = cur->leftPtr;
        // Value is greater and right child exists
        } else if (key > val && cur->rightPtr != NULL) {
            cur = cur->rightPtr;
        // One of the above conditions are broken, must be NULL
        } else {
            return NULL;
        }
    }

    // Current value is equal to the key, return cur
    return cur;
}
