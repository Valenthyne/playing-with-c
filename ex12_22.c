#include <stdio.h>
#include <stdlib.h>

// Basic constructs for a tree structure
struct treeNode {
    struct treeNode * leftPtr;
    int data;
    struct treeNode * rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode * TreeNodePtr;

// Function prototypes for tree operations

void insertNode(TreeNodePtr * treePtr, int value);
TreeNodePtr binaryTreeSearch(TreeNodePtr * rootPtr, int key);

int main(void) {

    TreeNodePtr root = NULL;

    printf("%s\n", "Time to build a tree!");

    while (1 == 1) {
        int v = 0;
        printf("\n%s\n", "Please enter a value (-1 to stop): ");
        scanf("%d", &v);
        if (v == -1)
            break;
        printf("\nInserting value... %d\n", v);
        insertNode(&root, v);
    }

    puts("\n");
    int k;
    printf("\n%s", "Please insert a value to search for: ");
    scanf(" %d", &k);

    TreeNodePtr src = binaryTreeSearch(&root, k);

    if (src == NULL) {
        printf("\n%s\n", "Value not found.");
    } else {
        printf("\n%d: %s\n", src->data, "Value found.");
    }

}

void insertNode(TreeNodePtr * treePtr, int value) {

    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TreeNode));

        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            printf("Memory allocation error.");
        }
    } else {
        if (value < (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr), value);
        } else if (value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr), value);
        } else {
            printf("\n%s", "Duplicate variable!");
        }
    }
}

TreeNodePtr binaryTreeSearch(TreeNodePtr * rootPtr, int key) {

    // If the tree is empty, return NULL
    if (rootPtr == NULL)
        return NULL;

    // Mark the current node
    TreeNodePtr cur = &rootPtr;

    printf("You get here, bud.");
    // While the key has not yet been found
    while (cur->data != key) {
        printf("Current value: %d", cur->data);

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
