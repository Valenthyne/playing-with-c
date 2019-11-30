struct treeNode {
    struct treeNode * leftPtr;
    int data;
    struct treeNode * rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode * TreeNodePtr;

void inOrder(TreeNodePtr treePtr);
void insertTNode(TreeNodePtr * treePtr, int value);
TreeNodePtr * binaryTreeSearch(TreeNodePtr rootPtr, int key);

void inOrder(TreeNodePtr treePtr) {

    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf(" %d ", treePtr->data);
        inOrder(treePtr->rightPtr);
    }

}

void insertTNode(TreeNodePtr * treePtr, int value) {

    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TreeNode));

        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            printf("\nNot enough memory available to insert node!\n");
        }
    } else {
        if (value < (*treePtr)->data) {
            insertTNode(&((*treePtr)->leftPtr), value);
        } else if (value > (*treePtr)->data) {
            insertTNode(&((*treePtr)->rightPtr), value);
        } else {
            printf("\n%s", "Duplicate variable!");
        }
    }
}

TreeNodePtr * binaryTreeSearch(TreeNodePtr rootPtr, int key) {

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
    printf("Current value: %d", cur->data);
    return cur;
}
