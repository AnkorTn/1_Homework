#include<bits/stdc++.h>
using namespace std;
int tot=0;
struct ListNode{
	int val;
	ListNode *next;
};
ListNode *head = new ListNode;
ListNode *temp = new ListNode;
ListNode *front,*w1,*w2,*w3,*w4,*w5,*w0;
ListNode *reverseList(ListNode *head);
int main(){
	front = head;
	w0 = w1 = w2 = w3 = w4 = w5 = head;
	head->val=1;head->next=new ListNode;head = head->next;
	head->val=2;head->next=new ListNode;head = head->next;
	head->val=3;head->next=new ListNode;head = head->next;
	head->val=4;head->next=new ListNode;head = head->next;
	head->val=5;head->next=NULL;
	temp = reverseList(front);
	while(temp){
		cout<<temp->val<<"->";
		temp = temp->next;
	}
	return 0;
}
ListNode *reverseList(ListNode *head){
	if(head==NULL||head->next==NULL)	return head;
	ListNode *tmp=reverseList(head->next);
	head->next->next=head;
	head->next=NULL;
	ListNode *tmmp = new ListNode;
	ListNode *ttp = new ListNode;
	ttp = tmp;
	switch(tot){
		case 0:
			tmmp = w0;break;
		case 1:
			tmmp = w1;break;
		case 2:
			tmmp = w2;break;
		case 3:
			tmmp = w3;break;
		case 4:
			tmmp = w4;break;
		case 5:
			tmmp = w5;break;
		default:
			break;
	}
	while(tmmp){
		cout<<tmmp->val<<"->";
		tmmp = tmmp->next;
	}
	cout<<"ttp="<<endl;
	while(ttp){
		cout<<ttp->val<<"->";
		ttp = ttp->next;
	}
	cout<<endl;
	tot++;
	return tmp;
}
