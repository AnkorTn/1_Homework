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
	public:
        myQueue(){
			head = new Node;
			front = head;
			flag = false;
		}
        ~myQueue(){
			makeEmpty();
			delete head;
		}
        void push(const T &tmp){
    		Node *p = new Node(tmp);
		    front -> next = p;
			front = p;
		}
		T pop(){
			T tmp;
			if(flag){
				tmp = head->data;
				Node *p = head;
				head = head->next;
				delete p;
			}				
			else{
				tmp = head->next->data;
				Node *p = head;
				head = head->next;
				delete p;
				Node *q = head;
				head = head->next;
				delete q;
				flag = true;
			}
			return tmp;
		}
		T first(){
			T tmp;
			if(flag)
				tmp = head->data;	
			else
				tmp = head->next->data;
			return tmp;
		}
};
template <class T>
ostream &operator<<(ostream &os, const myQueue<T> &obj){
    if(!obj.flag){
    	typename myQueue<T>::Node *q = obj.head -> next;
    	while (q != NULL){
			os << q -> data;
			if(q->next!=NULL)
				os<<' ';
			q = q -> next;
		}
	}	
	else{
		typename myQueue<T>::Node *q = obj.head;
		while (q != NULL){
			os << q -> data;
			if(q->next!=NULL)
				os<<' ';
			q = q -> next;
		}
	}
    //告诉编译器linkList<T>::Node是个类型
    //一般当某个依赖于模板参数的名称是一个类型时，就应使用typename
    return os;
}
int main(){
    myQueue<int> q;
    int num[]={1,2,3,4},i;
    for(i=0;i<=3;i++){
        q.push(num[i]);
    }
    cout <<q<<endl;;
    q.push(8);
    q.push(7);
    cout<<q<<endl;
    cout<<q.pop()<<endl;
    cout<<q<<endl;
    cout<<q.first()<<endl;
    cout<<q<<endl;
    return 0;
}
