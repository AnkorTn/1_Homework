#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
};
ListNode* deleteDuplicates(ListNode* head) {
	ListNode *tmp;	tmp = head;
	while(head!=NULL){
		if(head->next!=NULL){
			if(head->next->val==head->val){
				ListNode *delPtr;
				delPtr = head->next;
				head->next = delPtr->next;
				delete delPtr;
			}
			else
				head = head->next;
		}
		else
			break;
	}
	return tmp;
	// Please fill this blank
  	/*
  	parameter: head, head pointer of linked list
  	the definition of ListNode is as follows.
  	struct ListNode{
	    int val;
	    ListNode *next;
  	};
  	return head pointer of linked list after delete duplicates
  	*/
}
int main(){
	return 0;
}
