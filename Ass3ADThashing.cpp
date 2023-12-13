/*Implement all the functions of a dictionary (ADT) using hashing and handle collisions
using chaining with / without replacement.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)*/
#include<iostream>
using namespace std;
#include<string.h>
struct node
{
	char data[20];
	node *next;
};
class chash
{
	node *a[26];
	public:
	void insert(char[]);
	void display();
	void search(char[]);
	void del(char[]);
	chash()
	{
		for(int i=0;i<26;i++)
		{
			a[i]=NULL;
		}
	}
};
void chash::insert(char w[])
{
	int key =int(w[0])-97;
	cout<<"\nkey"<<key;
	struct node *t,*temp;
	t=new node;
	strcpy(t->data,w);
	t->next=NULL;
	if(a[key]==NULL)
	{
		a[key]=t;
	}
	else
	{
		temp=a[key];
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=t;
	}
	cout<<"inserted";
}
void chash::display()
{
	char arr[26];int j=0;
	for(char i='a';i<='z';i++)
	{
		arr[j]=i;
		j++;
	}
	for(int i=0;i<26;i++)
	{
		node *temp;
		temp=a[i];
		cout<<"\n"<<arr[i];
		if(temp==NULL)
			cout<<"->no element";
		else
		{
			while(temp!=NULL)
			{
				cout<<"->"<<temp->data;
				temp=temp->next;
			}
			j=j+1;
		}
	}
}
void chash::search(char w[])
{
	
	cout<<"\n"<<w;
	int flag=0;
	int key =int(w[0])-97;
	if(a[key]==NULL)
	{
		cout<<"\nthis is empty";
		return;
	}
	if(strcmp(a[key]->data,w)==0)
	{
		cout<<"found";
		flag=1;
	}
	else
	{
		node *temp;
		
		 temp=a[key];
		while(temp!=NULL)
		{
			if(strcmp(temp->data,w)==0)
			{
				cout<<"found";
				flag=1;
			}
			temp=temp->next;	
		}	
	}	
	if(flag==0)
		cout<<"no element";
}
void chash::del(char w[])
{
	//cout<<"\n"<<w;
	node *temp;
	int flag=0;
	int key =int(w[0])-97;
	if(a[key]==NULL)
	{
		cout<<"\nthis is empty";
		return;
	}
	if(strcmp(a[key]->data,w)==0)
	{
		temp =a[key];
		a[key]=a[key]->next;
		delete temp;
		flag=1;
	}
	else
	{
	//	node *temp;
		
		 temp=a[key];
		while(temp!=NULL)
		{
			if(strcmp(temp->data,w)==0)
			{
				temp =a[key];
				a[key]=a[key]->next;
				delete temp;	
				flag=1;
				break;
			}
			temp=temp->next;	
		}	
	}	
	if(flag==0)
		cout<<"no element";
}
int main()
{
	char word[20];
	int a,ch;
	chash h1;
	do
	{
		cout<<"\npress 1:Insert"<<"\npress2: display"<<"\npress 3: search"<<"\npress 4: delete";
		cout<<("\nEnter your choice");
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\nEnter the word only in lowercase:";
			cin>>word; 
			h1.insert(word);
			break;
		case 2:
			h1.display();
			break;
		case 3:
			cout<<("\nEnter the word only in lowercase for search:");
			cin>>word;
			h1.search(word);
			break;
		case 4:
			cout<<("\nEnter the word for deletion");
			cin>>word;
			h1.del(word);
			break;
		}
		cout<<"\npress 1 if you want to continue";
		cin>>a;
	}while(a==1);
	return 0;
}
