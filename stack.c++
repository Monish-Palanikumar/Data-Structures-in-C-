#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
class Stack
{
	private:
		int top;
		int capacity;
		int *data;
	public:
		Stack(int c)
		{
			top=-1;
			capacity=c;
			data=new int[capacity];
			memset(data,-1,capacity*sizeof(int));
		}
		int isEmpty()
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
		int isFull()
		{
			if(top==capacity-1)
				return 1;
			else
				return 0;
		}
		int peek()
		{
			if(isEmpty())
			{
				cout<<"Stack Empty!"<<endl;
				return 0;
			}
			else
				return data[top];
		}
		void displayStackContents()
		{
			if(isEmpty())
			{
				cout<<"Stack is empty"<<endl;
			}
			else
			{
				cout<<"\nThe stack contents are"<<endl;
				for(int i=top;i>=0;i--)
				{
					cout<<data[i]<<endl;
				}
				cout<<endl;	
			}
		}
		int push(int newData)
		{
			if(!isFull())
			{
				++top;
				data[top]=newData;
				return 1;
			}
			else
			{
				cout<<"Stack full"<<endl;
				return 0;
			}
		}
		int pop()
		{
			int poppedElement;
			if(!isEmpty())
			{
				poppedElement=data[top];
				top--;
				return poppedElement;
			}
			else
			{
				cout<<"Stack Empty"<<endl;
				return 0;
			}
		}
};
int main()
{
	int ch,cap,flag=0;
	cout<<"Enter stack capacity\n";
	cin>>cap;
	Stack s(cap);
	while(1)
	{
		cout<<"1. Push\n2. Pop\n3. Peek\n4. Display stack contents\n5. Exit\nEnter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				int data;
				cout<<"Enter the data to be pushed\n";
				cin>>data;
				flag=s.push(data);
				if(flag==1)
					cout<<"Pushed Successfully\n";
				else
					cout<<"Push unsuccessful\n";
				break;
			}
			case 2:
			{
				flag=s.pop();
				if(flag)
					cout<<"Popped Successfully. Popped element: "<<flag<<endl;
				else
					cout<<"Pop unsuccessful\n";
				break;
			}
			case 3:
			{
				flag=s.peek();
				if(flag)
					cout<<"Peeked successfully. Stack top: "<<flag<<endl;
				else
					cout<<"Peek unsuccessful\n";
				break;
			}
			case 4:
			{
				s.displayStackContents();
				break;
			}
			case 5:
			{
				exit(0);
			}
			default:
				cout<<"Enter a valid option\n";
		}
	}
	return 0;
}
