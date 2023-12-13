/*A Dictionary stores keywords and its meanings. Provide facility for adding new
keywords, deleting keywords, updating values of any entry. Provide facility to display
whole data sorted in ascending/ Descending order. Also find how many maximum
comparisons may require for finding any keyword. Use Height balance tree and find the
complexity for finding a keyword*/
#include<iostream>
#include<string>
using namespace std;
struct node
{
	string data;
	string mean;
	node *left,*right;
}*root;
class avl
{
	public:
		node * insert(node *,string,string);
		int height(node*);
		int diff(node*);
		node *bal(node*);
		node *ll(node *);
		node *rr(node *);
		node *lr(node *);
		node *rl(node *);
		void inorder1(node *);
		void search(string);
};
node * avl::insert(node *root,string key,string val)
{
	
	if(root==NULL)
	{
		root=new node;
		root->data=key;
		root->mean=val;
		root->left=NULL;
		root->right=NULL;
		return root;	
	}
	else if(key<root->data)
	{
		root->left=insert(root->left,key,val);
		root=bal(root);
	}
	else if(key>=root->data)
	{
		root->right=insert(root->right,key,val);
		root=bal(root);
	}
	//cout<<root;
	return root;
}
int avl::height(node *temp)
{
	int h=0;
	if(temp!=NULL)
	{
		int l_hgt=height(temp->left);
		int r_hgt=height(temp->right);
		if(l_hgt<r_hgt)
			h=(r_hgt+1);
		else
			h=(l_hgt+1);
			return h;
	}
}
int avl::diff(node* temp)
{
	int l_fac=height(temp->left);
	int r_fac=height(temp->right);
	int d_fac=l_fac-r_fac;
	return(d_fac);
}
node *avl::bal(node *temp)
{
	int b_fact=diff(temp);
	if(b_fact>1)
	{
		if(diff(temp->left)>0)
			temp=ll(temp);
		else
		temp=lr(temp);
	}
	else if(b_fact< -1)
	{
		if(diff(temp->right)>0)
			temp=rl(temp);
		else
			temp=rr(temp);
	}
	return temp;
}
node *avl::ll(node *par)
{
	node *temp;
	temp=par->left;
	par->left=temp->right;
	temp->right=par;
	return(temp);
}
node *avl::rr(node *par)
{
	node *temp;
	temp=par->right;
	par->right=temp->left;
	temp->left=par;
	return(temp);
}
node *avl::lr(node *par)
{
	node *temp;
	temp=par->left;
	par->left=rr(temp);
	par=ll(par);
	return(par);
}
node *avl::rl(node *par)
{
	node *temp;
	temp=par->right;
	par->right=ll(temp);
	par=rr(par);
	return(par);
}
void avl::inorder1(node *T)
  {
	 if(T!=NULL)
		{
		  inorder1(T->left);
		  cout<<"\n"<<T->data<<"="<<T->mean;
		  inorder1(T->right);
		}

  }
void avl::search(string n)
{
	node *T;
	T=root;
	int flag=0,count=1;
	//cout<<"\nEnter the number for search:";
	//cin>>n;
	while(T!=NULL)
	{
		if(T->data==n)
		{
			cout<<"\nfound";
			 flag=1;
			cout<<"\ncomparison:"<<count;
			break;
		}
		else if(n>T->data)
		{
			count+=1;
			T=T->right;
		}
		else
		{
			count+=1;
			T=T->left;
		}
	}
	if(flag==0)
		cout<<"\nnot found";
}
  int main()
  {
  	char choice;
  	string val;
  	string key;
  	string srch;
  	int ch,op=1;
  	avl a1;
  	
  	while(op==1)
  	{
  		cout<<"\n1:Insertion"<<"\n2:display"<<"\n3:search"<<"\nEnter your choice:";
  		cin>>ch;
	  	switch(ch)
	  	{
		  	case 1:
			  	do
			  	{
			  		cout<<"\nEnter the keyword:";
			  		cin>>key;
			  		cout<<"\nEnter the value:";
			  		cin>>val;
					root=a1.insert(root,key,val);
					cout<<"If you want to continue press y/Y:";	
					cin>>choice;
				}while(choice=='y' || choice=='Y');
				break;
			case 2:
		  		a1.inorder1(root);
		  		break;
			case 3:
			  	cout<<"\nEnter the keyword:";
				cin>>srch;
				a1.search(srch);
				break;
		}
		cout<<"\nDo you want to continue 1:";
		cin>>op;
	}
  return 0;
}
