#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List
{
public:
	List();
	~List();
	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void pop_back();
	void insert(T data,int index);
	void remove(int index);
	void clear();
	int GetSize()
	{
		return size;
	}

	T& operator [](const int index);

private:
	//template <typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;

		Node(T data=T(),Node *pNext = nullptr)
		{
			this->data=data;
			this->pNext=pNext;
		}

	};

	Node *head;
	int size;
};

template<typename T>
List<T>::List()
{
	size=0;
	head=nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::clear()
{
	while(size)
		pop_front();


}

template<typename T>
void List<T>::pop_front()
{
	Node *temp=head;
	head=head->pNext;
	delete temp;
	size--;
}


template<typename T>
void List<T>::pop_back()
{
	remove(size-1);
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head==nullptr)
		head =new Node(data);
	else
	{		
		Node *curr=this->head;

		while (curr->pNext !=nullptr)
			curr=curr->pNext;

		curr->pNext=new Node(data);
	}
	size++;
}


template<typename T>
void List<T>::push_front(T data)
{
	head=new Node(data,head);
	size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if(index==0)
		push_front(data);
	else
	{
		Node *prev=this->head;
		
		for(int i=0;i<index-1;i++)
			prev=prev->pNext;

		Node *newNode=new Node(data,prev->pNext);
		prev->pNext=newNode;

		size++;
	}
	
}


template<typename T>
void List<T>::remove(int index)
{
	if(index==0)
		pop_front();
	else
	{
		Node *prev=this->head;
		
		for(int i=0;i<index-1;i++)
			prev=prev->pNext;

		Node *toDelete=prev->pNext;
		prev->pNext=toDelete->pNext;
		
		delete toDelete;
		size--;
	}
	
}

template <typename T>
T & List<T>::operator [](const int index)
{
	int counter=0;	
	Node *curr=this->head;
	while(curr!=nullptr)
	{	
		if(counter==index)
			return curr->data;
		curr=curr->pNext;
		counter++;	
	}
}

int main(void)
{
	List<int> lst;

	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(22);

	for (int i=0;i<lst.GetSize();i++)
		cout<<lst[i]<<endl;

	cout<<"The number of elements in list = "<<lst.GetSize()<<endl;
	cout<<"POP_FRONT"<<endl<<endl;

	//lst.pop_front();

	for (int i=0;i<lst.GetSize();i++)
		cout<<lst[i]<<endl;

	cout<<"The number of elements in list = "<<lst.GetSize()<<endl;


	cout<<"INSERT"<<endl;
	lst.insert(99,1);

	for (int i=0;i<lst.GetSize();i++)
		cout<<lst[i]<<endl;

	cout<<"The number of elements in list = "<<lst.GetSize()<<endl;

	cout<<"REMOVE"<<endl;
	
	lst.remove(1);

	for (int i=0;i<lst.GetSize();i++)
		cout<<lst[i]<<endl;

	cout<<"The number of elements in list = "<<lst.GetSize()<<endl;
	return 0;
}
