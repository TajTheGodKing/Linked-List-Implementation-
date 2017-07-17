/*################################################################################
Justin Cooke  7/8/2107 Taj Co.*************Linked List Implementation***********
##################################################################################*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class LL {
private:
	typedef struct Node{
		int data;//Holds the data that is placed inside of the linked list 
		Node*  next;// pointer that points to the nth 

	}*NodePtr;// makeing a defenition of the struct class 

	NodePtr head;// head pointer which always points to the beginning of the linked list 
	NodePtr curr;//points to current 
	NodePtr temp;//points to the temporary head of the linked list.

public:
	LL();//constructor 
/*Prototypes*/
	void Add(int AddData);//adding items to the linked list

	void deleteNode(int deleteData);//deletes items from linked list
	void print();//printing linked list;


};

LL::LL(){
	head = NULL;
	curr = NULL;
	temp = NULL;
};
void LL::Add(int AddData) {
	NodePtr n = new Node;//Creating a new node that points to data and pointers

	n->next = NULL;//if the list is empty this points to nothing 
	n->data = AddData;//puts data in the node

	if (head != NULL) {//checks to see if the linked list has any items 
		curr = head;// make current pointer point to the front
		while (curr->next != NULL) {
			curr = curr->next; // if the current pointer pointing to next is null make the next element the new current 
		}
		curr->next = n;//creates the next node
	}
	else {
		head = n; // if head is null create a new node and set it to head
	}
}
	void LL::deleteNode(int deleteData) {
		NodePtr delPtr = NULL;
		temp = head;
		curr = head;
		while (curr != NULL && curr->data !=deleteData) {
			temp = curr;
			curr = curr->next;
		}
		if (curr == NULL) {
			cout << "Data was never placed in the list" << endl;
			delete delPtr;
			// deletes ptr so we wont have a delPtr floating around 
		}
		else {
			delPtr = curr;
			curr = curr->next;//Makes sure there arent any gaps inside of our linked list
			temp->next = curr;
			delete delPtr;
			cout << "The Value" << deleteData << "has been deleted \n";
		}
	}
	void LL::print() {
		curr = head;
		while (curr != NULL) {///traverses through loop until curr-> data is equal to Null;
			cout << curr->data;
			curr = curr -> next;
		}
	}
}
int main(){
LL obj;
	obj.Add(5);
	obj.Add(3);
	obj.Add(2);
	
	obj.print();
	
	obj.deleteNode(5);
	obj.deleteNode(7);
	obj.print(2);

}
