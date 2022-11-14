#include <stdio.h>

typedef struct node Tree_Node;
struct node
{
    int root;
    Tree_Node *left;
    Tree_Node *right;
} ;

Tree_Node *create_tree_node(int item);
void add_left_child(Tree_Node *root_child, Tree_Node *child);
void add_right_child(Tree_Node *root_child, Tree_Node *child);
Tree_Node *create_tree();

int main(void)
{
    Tree_Node *root = create_tree();

    printf("%d\n", root->root);

    return 0;
}

// Create Tree Node
Tree_Node *create_tree_node(int item)
{
    Tree_Node *new_node = (Tree_Node *)malloc(sizeof(Tree_Node));

    if(new_node == NULL)
    {
        printf("Error! Could not create a Tree new node.\n");
        exit(1);
    }

    new_node->root = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// add left child
void add_left_child(Tree_Node *root_child, Tree_Node *child)
{
    root_child->left = child;
}

// add right child
void add_right_child(Tree_Node *root_child, Tree_Node *child)
{
    root_child->right = child;
}

// Create Tree
Tree_Node *create_tree()
{
    Tree_Node *two = create_tree_node(2); // Root
    Tree_Node *seven = create_tree_node(7);
    Tree_Node *nine = create_tree_node(9);
    add_left_child(two, seven);
    add_right_child(two, nine);

    Tree_Node *one = create_tree_node(1);
    Tree_Node *six = create_tree_node(6);
    add_left_child(seven, one);
    add_right_child(seven, six);

    Tree_Node *five = create_tree_node(5);
    Tree_Node *ten = create_tree_node(10);
    add_left_child(six, five);
    add_right_child(six, ten);

    Tree_Node *eight = create_tree_node(8);
    add_right_child(nine, eight);

    Tree_Node *three = create_tree_node(3);
    Tree_Node *four = create_tree_node(4);
    add_left_child(eight, three);
    add_right_child(eight, four);

    // two is root node this tree;
    return two;
}

