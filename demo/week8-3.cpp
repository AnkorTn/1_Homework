#include<bits/stdc++.h>
using namespace std;
struct Node {
	int order, coeff; // 次数 和 系数
	Node* nxt; // 指向后一项的指针
}*a1,*a2,*b1,*b2,*b3;
// IN: Node* a, Node* b, polynomials represented as linked lists
// RETURN: polynomial a+b represented as a linked list
Node* add_poly(Node* a, Node* b) {
	Node *c = new Node,*ans = new Node,*front = new Node;
	front = ans;
	c = ans; 
	while(a!= NULL && b!=NULL){
		if(a->order>b->order){
			ans->coeff=a->coeff;
			ans->order=a->order;
			a = a->nxt;	
		} 
		else if(a->order<b->order){
			ans->coeff=b->coeff;
			ans->order=b->order;
			b = b->nxt;	
		} 
		else{
			ans->coeff = a->coeff + b->coeff;
			ans->order = a->order;
			a = a->nxt;
			b = b->nxt;
		}
		ans->nxt = new Node;
		if(ans->coeff==0){
			ans->order=0;
			ans->nxt = NULL;		
		}
		else{
			front = ans;
			ans = ans->nxt;
			ans->nxt = NULL;
		}
	}
	while(a!=NULL){
		ans->coeff=a->coeff;
		ans->order=a->order;
		a = a->nxt;	
		front = ans;
		ans->nxt = new Node;
		ans = ans->nxt;
		ans->nxt = NULL;
	}
	while(b!=NULL){
		ans->coeff=b->coeff;
		ans->order=b->order;
		b = b->nxt;	
		front = ans;
		ans->nxt = new Node;
		ans = ans->nxt;
		ans->nxt = NULL;
	}
	front->nxt = NULL;
	return c;
}
int main(){
	int n;
	Node *anx = new Node;
	//a2 = new Node;a1 = a2; b2 = new Node;	b1 = b2;	b3 = new Node;
	a2 = new Node;a1 = a2; b2 = new Node;	b1 = b2;
	cin>>n;
	while(n>0){
		cin>>a2->coeff>>a2->order;
		a2->nxt = new Node;
		a2 = a2->nxt;
		a2->nxt = NULL;
		n--;
	}
	cin>>n;
	while(n>0){
		cin>>b2->coeff>>b2->order;
		b2->nxt = new Node;
		b2 = b2->nxt;
		b2->nxt = NULL;
		n--;
	}
	//a1->coeff=1;	a1->order=1;	a1->nxt=NULL;
	//b1->coeff=-1;	b1->order=1;	b1->nxt=NULL;
	/*
	a1->coeff=3;	a1->order=2;	a1->nxt=a2;
	a2->coeff=-1;	a2->order=0;	a2->nxt=NULL;
	b1->coeff=1;	b1->order=5;	b1->nxt=b2;
	b2->coeff=-3;	b2->order=2;	b2->nxt=b3;
	b3->coeff=-1;	b3->order=0;	b3->nxt=NULL;
	*/
	anx = add_poly(a1,b1);
	while(anx!=NULL){
		cout<<anx->coeff<<"x^"<<anx->order<<"+";
		anx = anx->nxt;
	}
	return 0;
}
