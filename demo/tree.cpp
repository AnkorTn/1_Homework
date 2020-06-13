#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TreeNode{    //结构体用来储存树结点，包括节点的值data，分别指向左孩子右孩子的指针；
    int data;
    struct TreeNode *left, *right;
};
void SetTree(struct TreeNode **root, int val){//建树函数，传参为根节点的地址，新增数；
    struct TreeNode *t;                      //储存新结点；
    t=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    t->data=val;
    t->left=NULL;
    t->right=NULL;
    if((*root)==NULL){            //if根结点为空，把新增节点设为根结点；
        (*root)=t;
        return;
    }
    if((*root)->data>val) SetTree(&((*root)->left), val);//新增值小于该结点的值，放到左孩子，递归；
    else SetTree(&((*root)->right), val);//大于，右孩子，递归；
}
int main(){
    int N;
    int val;
    struct TreeNode *root;
    root=NULL;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&val);
        SetTree(&root, val);
    }
    ShowTree(root);
    return 0;
}
