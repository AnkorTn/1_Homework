#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TreeNode{    //�ṹ��������������㣬�����ڵ��ֵdata���ֱ�ָ�������Һ��ӵ�ָ�룻
    int data;
    struct TreeNode *left, *right;
};
void SetTree(struct TreeNode **root, int val){//��������������Ϊ���ڵ�ĵ�ַ����������
    struct TreeNode *t;                      //�����½�㣻
    t=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    t->data=val;
    t->left=NULL;
    t->right=NULL;
    if((*root)==NULL){            //if�����Ϊ�գ��������ڵ���Ϊ����㣻
        (*root)=t;
        return;
    }
    if((*root)->data>val) SetTree(&((*root)->left), val);//����ֵС�ڸý���ֵ���ŵ����ӣ��ݹ飻
    else SetTree(&((*root)->right), val);//���ڣ��Һ��ӣ��ݹ飻
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
