#include<iostream>
#include<stdlib.h>
using namespace std;
class SinglyLinkedList;
class Node
{
	private:
		int data;
		Node *next;
	public:
		Node(int d)
		{
			data=d;
			next=NULL;
		}
		friend class SinglyLinkedList;
};
class SinglyLinkedList
{
	private:
		Node *first;
	public:
		SinglyLinkedList()
		{
			first=NULL;
		}
		int insertAtFirst(Node *newNode)
		{
			if(isEmpty())
			{
				first=newNode;
			}
				
			else
			{
				newNode->next=first;
				first=newNode;
			}
			return 1;
		}
		int insertAtLast(Node *newNode)
		{
			if(isEmpty())
			{
				insertAtFirst(newNode);
			}
			else
			{
				Node *temp=first;
				while(temp->next!=NULL)
					temp=temp->next;
					
				temp->next=newNode;
				return 1;
			}
		}
		int insertByPosition(Node *newNode,int pos)
		{
			int i=1;
			if(pos==1)
				insertAtFirst(newNode);
			else
			{
				Node *temp=first;
				while(temp->next!=NULL)
				{
					temp=temp->next;
					i++;
				}
				if(pos>i+1)
				{
					cout<<"Invalid index !\n";
					return 0;
				}
				if(i+1==pos)
					insertAtLast(newNode);
				else
				{
					Node *temp=first;
					Node *prev=temp;
					int cur=1;
					while(temp->next!=NULL && cur!=pos)
					{
						prev=temp;
						temp=temp->next;
						cur++;
					}
					while(temp->next!=NULL && cur==pos)
					{
						prev->next=newNode;
						newNode->next=temp;
						return 1;
					}
					while(temp->next==NULL && cur==pos)
					{
						newNode->next=prev->next;
						prev->next=newNode;
						return 1;
					}
				}	
			}
		}
		int deleteAtFirst()
		{
			if(isEmpty())
				return 0;
			else
			{
				Node *temp=first;
				first=first->next;
				delete temp;
				return 1;
			}
		}
		int deleteAtLast()
		{
			if(isEmpty())
				return 0;
			else
			{
				Node *temp=first;
				Node *prev=first;
				while(temp->next!=NULL)
				{
					prev=temp;
					temp=temp->next;
				}
				prev->next=NULL;
				delete temp;
				return 1;
			}		
		}
		int deleteByPosition(int);
		void displayList()
		{
			Node *ptr=first;
			if(isEmpty())
			{
				cout<<"List empty";
			}
			while(ptr!=NULL)
			{
				cout<<ptr->data<<" ";
				ptr=ptr->next;
			}
			cout<<endl;
		}
		int isEmpty()
		{
			if(first==NULL)
				return 1;
			else
				return 0;
		}	
};
int main()
{
	int flag=0,ch,ch1,data;
	SinglyLinkedList l;
	while(1)
	{
		cout<<"Enter choice\n1. Insert\n2. Delete\n3. Display\n4. Exit\n\nEnter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter choice\n1. Insert At First\n2. Insert At Last\n3. Insert By Position\nEnter your choice\n";
				cin>>ch1;
				if(ch1==1)
				{
					cout<<"Enter data to be inserted\n";
					cin>>data;
					Node *n=new Node(data);
					flag=l.insertAtFirst(n);
					if(flag==1)
						cout<<"Insert Success\n";
					else
						cout<<"Insert Failed\n";
					break;
				}
				else if(ch1==2)
				{
					cout<<"Enter data to be inserted\n";
					cin>>data;
					Node *n=new Node(data);
					flag=l.insertAtLast(n);
					if(flag==1)
						cout<<"Insert Success\n";
					else
						cout<<"Insert Failed\n";
					break;
				}
				else if(ch1==3)
				{
					int pos;
					cout<<"Enter data to be inserted\n";
					cin>>data;
					cout<<"Enter position to be inserted\n";
					cin>>pos;
					Node *n=new Node(data);
					flag=l.insertByPosition(n,pos);
					if(flag==1)
						cout<<"Insert Success\n";
					else
						cout<<"Insert Failed\n";
					break;
				}
			}
			case 2:
			{
				cout<<"Enter choice\n1. Delete At First\n2. Delete At Last\n3. Delete By Position\nEnter your choice\n";
				cin>>ch1;
				if(ch1==1)
				{
					flag=l.deleteAtFirst();
					if(flag==1)
						cout<<"Delete Success\n";
					else
						cout<<"Delete Failed\n";
					break;
				}
				else if(ch1==2)
				{
					flag=l.deleteAtLast();
					if(flag==1)
						cout<<"Delete Success\n";
					else
						cout<<"Delete Failed\n";
					break;
				}
			}
			case 3:
			{
				l. displayList();
				break;
			}
			case 4:
			{
				exit(0);
			}
		}
	}
	return 0;
}
