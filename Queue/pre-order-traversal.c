#include <stdio.h>

typedef struct node Node;
struct node
{
    int data;
    Node *left_node;
    Node *right_node;
};

Node *create_tree_node(int item);
void add_left_child(Node *root, Node *child);
void add_right_child(Node *root, Node *child);
Node *create_tree();
void pre_order(Node *root);

int main(void)
{
    Node *root;

    root = create_tree();
    printf("Root data: %d\n", root->data);

    pre_order(root);

    return 0;
}

// create tree node
Node *create_tree_node(int item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if(new_node == NULL)
    {
        printf("Error! Could not create a new tree node.");
        exit(1);
    }

    new_node->data = item;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
}

// add left child
void add_left_child(Node *root, Node *child)
{
    root->left_node = child;
}

// add right child
void add_right_child(Node *root, Node *child)
{
    root->right_node = child;
}

// create tree
Node *create_tree()
{
    Node *two = create_tree_node(2);
    Node *seven = create_tree_node(7);
    Node *nine = create_tree_node(9);
    add_left_child(two, seven);
    add_right_child(two, nine);

    Node *one = create_tree_node(1);
    Node *six = create_tree_node(6);
    add_left_child(seven, one);
    add_right_child(seven, six);

    Node *five = create_tree_node(5);
    Node *ten = create_tree_node(10);
    add_left_child(six, five);
    add_right_child(six, ten);

    Node *eight = create_tree_node(8);
    add_right_child(nine, eight);

    Node *three = create_tree_node(3);
    Node *four = create_tree_node(4);
    add_left_child(eight, three);
    add_right_child(eight, four);

    return two;
}

// Pre-order Traversal
void pre_order(Node *root)
{
    printf("%d ", root->data);

    if(root->left_node != NULL)
        pre_order(root->left_node);

    if(root->right_node != NULL)
        pre_order(root->right_node);
}
