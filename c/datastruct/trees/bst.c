#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node{
   int   val;
   struct node *left;
   struct node *right;
};

struct node* newNode(int val)
{
   struct node *nnode = (struct node*) malloc (sizeof (struct node));
   assert (nnode != NULL);
   
   nnode->val = val;
   nnode->left = nnode->right = NULL;
   return nnode;
}

struct node* insertNode(struct node* node, int val)
{
   if (node == NULL) return newNode(val);

   if (val < node->val)
      node->left = insertNode(node->left, val);
   else
      node->right = insertNode(node->right, val);
   return node;
}

void  inorder(struct node* node)
{
   if (node == NULL) return;
   inorder(node->left);
   printf("%d ", node->val);
   inorder(node->right);
}

int main()
{
   struct node* root = NULL;
   
   /* create following BST
            50
         /     \
        30      70
       /  \    /  \
     20   40  60   80
    */
   
   root = insertNode(root, 50);
   insertNode(root, 30);
   insertNode(root, 20);
   insertNode(root, 40);
   insertNode(root, 70);
   insertNode(root, 60);
   insertNode(root, 80);
   
   // print bst inorder
   inorder(root);
   return 0;
}
