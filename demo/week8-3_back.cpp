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
	//Node *c,*ans,*front;
	front = ans;
	//Make sure a is the highest order and we just add b to a;
	//cout<<a->order<<"   "<<a->nxt->order<<endl;
	//cout<<b->order<<"   "<<b->nxt->order<<endl;
	c = ans; 
	while(a!= NULL && b!=NULL){
		if(a->order>b->order){
			//cout<<"This is the first step"<<endl;
			ans->coeff=a->coeff;
			ans->order=a->order;
			a = a->nxt;	
		} 
		else if(a->order<b->order){
			//cout<<"This is the second step"<<endl;
			ans->coeff=b->coeff;
			ans->order=b->order;
			b = b->nxt;	
		} 
		else{//if their orders are the same
			//cout<<"This is the third step"<<endl;
			ans->coeff = a->coeff + b->coeff;
			ans->order = a->order;
			a = a->nxt;
			b = b->nxt;
		}
		/*if(ans->coeff==0&&(a!=NULL||b!=NULL)){
			front->nxt = ans->nxt;
		}
		else{
			ans->order = 0;
			front = ans;
		}*///等一下再考虑如果出现0的情况。 
		//cout<<ans->coeff<<"x^"<<ans->order<<endl;
		front = ans;
		ans->nxt = new Node;
		ans = ans->nxt;
		ans->nxt = NULL;
		//cout<<ans->coeff<<"x^"<<ans->order<<endl;
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
	Node *anx = new Node;
	a1 = new Node;a2 = new Node; b1 = new Node;	b2 = new Node;	b3 = new Node;
	a1->coeff=3;	a1->order=2;	a1->nxt=a2;
	a2->coeff=-1;	a2->order=0;	a2->nxt=NULL;
	b1->coeff=1;	b1->order=5;	b1->nxt=b2;
	b2->coeff=-3;	b2->order=2;	b2->nxt=b3;
	b3->coeff=-1;	b3->order=0;	b3->nxt=NULL;
	anx = add_poly(a1,b1);
	while(anx!=NULL){
		cout<<anx->coeff<<"x^"<<anx->order<<"+";
		anx = anx->nxt;
	}
	return 0;
}
