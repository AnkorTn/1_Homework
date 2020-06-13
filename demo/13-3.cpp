#include<bits/stdc++.h>
using namespace std;
template <class T> class myQueue;
template <class T> ostream &operator<<(ostream &os, const myQueue<T> &obj);
template <class T>
class myQueue{
    friend ostream &operator<<<>(ostream &os, const myQueue<T> &obj);
	protected:
	    void makeEmpty (){
	    	Node *p = head -> next, *q;
    		head -> next = NULL;
    		while (p != NULL) {q = p -> next; delete p; p = q;}
		} 
	    class Node{	
			public:           	
				T  data;
	            Node *next;
		    	Node(const T &x, Node  *N = NULL){
					data = x;
					next = N;
				}
		    	Node( ):next(NULL) {}
		    	~Node() {}
	    };
	    Node *head,*front;
	    bool flag;
	    T total;
	public:
        myQueue(){
			head = new Node;
			front = head;
			flag = false;
			total = 0;
		}
        ~myQueue(){
			makeEmpty();
			delete head;
		}
        void push(const T &tmp){
        	total+=tmp;
    		Node *p = new Node(tmp);
		    front -> next = p;
			front = p;
		}
		T gettotal(){
			return total;
		}
};
int main(){	
    int num[]={1,1,1,1,1,1,1,1,1,1};
    for(int j=0;j<=9;j++){
    	myQueue<int> q1;
		myQueue<int> q2;
		num[j] = 5;
		int i=0;
		while(i<10){
    		if(q1.gettotal()==q2.gettotal()){
	    		q1.push(num[i]);	cout<<num[i];	if(i<9)cout<<" ";	i++;
	    		if(i<10){q2.push(num[i]);	cout<<num[i];	if(i<9)cout<<" ";}		i++; 
			}
			else if(q1.gettotal()<q2.gettotal()){
				q1.push(num[i]);	cout<<num[i];	if(i<9)cout<<" ";	i++;
			}
			else{
				q2.push(num[i]);	cout<<num[i];	if(i<9)cout<<" ";	i++;
			}
		}
		cout<<endl;
		cout<<max(q1.gettotal(),q2.gettotal())<<endl;
		num[j] = 1;
	}
	return 0;
}
