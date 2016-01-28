/**
 * Nine degree problem 1078: binary tree traversal.
 * Construct tree from given preorder and inorder traversals, output postorder sequences.
 *
 * STEPS:
 *    1, In a preorder sequence, leftmost element is the root of the tree, we name it A.
 *    2, By searching A in inorder sequence, we can find out all elements on left side of A are in left subtree and elements on right are in right subtree.
 *    3, Recurse child subtree and right subtree. 
 *
 *
 * hellfire (asyncloading#163.com)
 * Jan 28th, 2016
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* A binary tree node. */
typedef struct node
{
  char data;
  struct node* left;
  struct node* right;
} Node;

/* Create a new tree node. */
Node* new_node(char data);

/* Define binary tree related functions. */
Node* build_tree(char pre[], char in[], int inStart, int inEnd);

/* Search index. */
int search(char arr[], int start, int end, char value);

/* Print postorder. */
void postorder(Node* node);

static int pre_index = 0;

int main(int argc, char **argv)
{
  char pre[26];
  char in[26];
  while (gets(pre) != NULL && gets(in) != NULL)
  {
    pre_index = 0;
    int len = strlen(in);
    Node *root = build_tree(pre, in, 0, len - 1);
    postorder(root);
    free(root);
    printf("\n");
  }
}

Node* new_node(char data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}

int search(char arr[], int start, int end, char value)
{
  int i;
  for (i = start; i <= end; i ++)
  {
    if (arr[i] == value)
    {
      return i;
    }
  }
  return -1;
}

Node* build_tree(char pre[], char in[], int in_start, int in_end)
{
  if (in_start > in_end)
  {
    return NULL;
  }

  Node* node = new_node(pre[pre_index ++]);

  if (in_start == in_end)
  {
    return node;
  }  
 
  int in_index = search(in, in_start, in_end, node -> data);
  node -> left = build_tree(pre, in, in_start, in_index - 1);
  node -> right = build_tree(pre, in, in_index + 1, in_end);
  
  return node;
}

void postorder(Node* node)
{
  if (node == NULL)
  {
    return;
  }
  postorder(node -> left);
  postorder(node -> right);
  printf("%c", node -> data);
}
