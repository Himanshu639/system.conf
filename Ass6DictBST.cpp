#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class node
{
	public:
		string word,mean;
		node *left;
		node *right;
		node()
		{
			left=NULL;
			right=NULL;
			
		}

};
class bstree
{
	 public:
	 	node *root;
	 	bstree()
	 	{
	 	root=NULL;
	 	}
	 	void create();
	 	void insert();
	 	void preorder(node *);
	 	void search(string,node *);
	 	void update(string,string ,node *);
};
void bstree::create()
{
	if(root==NULL)
	{	root=new(node);
		cout<<"\nEnter the word and mean:";
		cin>>root->word>>root->mean;
		return ;
	}
}
void bstree::insert()
{	
	node *temp,*p;
	if(root==NULL)
	{	
		create();
		return;
	}
	p=new(node);
	cout<<"\nEnter the word and mean:";
	cin>>p->word>>p->mean;
	
	temp=root;
	while(temp!=NULL)
	{
		if(p->word<temp->word)
		{
			if(temp->left==NULL)
			{temp->left=p;
			break;
			}
			else
			{
				temp=temp->left;
			}
		
		}
		else if(p->word>temp->word)
		{
			if(temp->right==NULL)
			{temp->right=p;
			break;
			}
			else
			{
			temp=temp->right;
			}
		
		}
		else
		{cout<<"\nAlready inserted";
		break;
		}
	
	}
	
}
void bstree::preorder(node *root)
{	
	if (root!=NULL)
	{
		cout<<root->word<<"--"<<root->mean<<" ";
		preorder(root->left);
		preorder(root->right);
	}
	else
	{return;}
}
void bstree::search(string value,node *root)
{
	node *temp=root;
	int count=0;
	if(temp==NULL)
	{cout<<"\nEmpty binarry search tree";}
	while(temp!=NULL)
	{
		if(temp->word==value)
		{	cout<<"\nWord found \n";
			cout<<temp->word<<"--"<<temp->mean<<" ";
			break;
		}
		else if(value<temp->word)
		{
			temp=temp->left;
			
 		}
		else
		{
			temp=temp->right;

		}
		count++;
	}

	if(temp==NULL)
	{
		cout<<"\nWord not found";
	}

}
void bstree::update(string value,string newmean,node *root)
{
	node *temp=root;
	int count=0;
	if(temp==NULL)
	{cout<<"\nEmpty binarry search tree";}
	while(temp!=NULL)
	{
		if(temp->word==value)
		{	temp->mean=newmean;
			cout<<temp->word<<"--"<<temp->mean<<" ";
			break;
		}
		else if(value<temp->word)
		{
			temp=temp->left;
			
 		}
		else
		{
			temp=temp->right;

		}
		count++;
	}
	if(temp==NULL)
	{
		cout<<"\nWord not found";
	}
	
}
int main()
{
	string findme,newmean,wordchg;
	bstree bs1;
	int n;
	cout<<"\nEnter number of entries:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		bs1.insert();
	}
	cout<<"\nTree representation:";
	bs1.preorder(bs1.root);
	cout<<"\nEnter word to be search:";
	cin>>findme;
	bs1.search(findme,bs1.root);
	cout<<"\nEnter word and its new meaning";
	cin>>wordchg>>newmean;
	bs1.update(wordchg,newmean,bs1.root);
	cout<<"\nNew Tree representation:";
	bs1.preorder(bs1.root);
	return 0;
	
	
}


