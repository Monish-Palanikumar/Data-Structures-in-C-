#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
class CircularQueue
{
	private:
		int front;
		int rear;
		int capacity;
		int *data;
	public:
		CircularQueue(int c)
		{
			front=-1;
			rear=-1;
			capacity=c;
			data=new int[capacity];
			memset(data,-1,capacity*sizeof(int));
		}
		int isEmpty()
		{
			if((front==-1 && rear==-1))
				return 1;
			else
				return 0;
		}
		int isFull()
		{
			if(front==(rear+1)%capacity)
				return 1;
			else
				return 0;
		}
		int peek()
		{
			if(isEmpty())
			{
				cout<<"Queue Empty!"<<endl;
				return 0;
			}
			else
				return data[front];
		}
		void displayQueueContents()
		{
			if(isEmpty())
			{
				cout<<"Queue is empty"<<endl;
			}
			else
			{
				cout<<"\nThe queue contents are"<<endl;
				for(int i=front;i<rear+1;i++)
				{
					cout<<data[i]<<endl;
				}
				cout<<endl;	
			}
		}
		int enqueue(int newData)
		{
			//insertion in rear end
			if(isFull())
			{
				cout<<"Queue full"<<endl;
				return 0;
			}
			else if(isEmpty())
			{
				++front;
				++rear;
				data[rear]=newData;
				return 1;
			}
			else
			{	
				rear=(rear+1)%capacity;
				data[rear]=newData;
				return 1;
			}
		}
		int dequeue()
		{
			//deletion in front end
			int dequeuedElement;
			if(isEmpty())
			{
				cout<<"Queue empty"<<endl;
				return 0;	
			}
			else if(front==rear)
			{
				dequeuedElement=data[front];
				front=rear=-1;
			}
			else
			{
				dequeuedElement=data[front];
				front=(front+1)%capacity;
			}
			return dequeuedElement;
		}
};
int main()
{
	int ch,cap,flag=0;
	cout<<"Enter queue capacity\n";
	cin>>cap;
	CircularQueue q(cap);
	while(1)
	{
		cout<<"1. Enqueue\n2. Dequeue\n3. Peek\n4. Display queue contents\n5. Exit\nEnter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				int data;
				cout<<"Enter the data to be enqueued\n";
				cin>>data;
				flag=q.enqueue(data);
				if(flag==1)
					cout<<"Enqueued Successfully\n";
				else
					cout<<"Enqueue unsuccessful\n";
				break;
			}
			case 2:
			{
				flag=q.dequeue();
				if(flag)
					cout<<"Dequeued Successfully. dequeued element: "<<flag<<endl;
				else
					cout<<"Dequeue unsuccessful\n";
				break;
			}
			case 3:
			{
				flag=q.peek();
				if(flag)
					cout<<"Peeked successfully. Queue front: "<<flag<<endl;
				else
					cout<<"Peek unsuccessful\n";
				break;
			}
			case 4:
			{
				q.displayQueueContents();
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
