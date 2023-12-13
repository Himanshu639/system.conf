/*Beginning with an empty binary search tree, Construct binary search tree by inserting the 
values in the order given. After constructing a binary tree -
i. Insert new node 
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree 
iv. Change a tree so that the roles of the left and right pointers are swapped at every 
node 
v. Search a value		
*/

#include<iostream>
#include<string>
using namespace std;
class node
{
public: int data;
        node *left,*right;
};

class binary_search_tree
{
    public:
            node *root;
            binary_search_tree()           //Constructor
            {
                root=NULL;
            }
            void create();
            void insert();
            //void preorder(node*);
            void inorder(node *);
            //void postorder(node *);
            int get_height(node *T);
            void get_min();
            void get_max();
            node* swap(node *);
            void search();
};

void binary_search_tree::create()
{
    root=new node;
    cout<<"\nEnter the root node:";
    cin>>root->data;
    root->left=NULL;
    root->right=NULL;
}

void binary_search_tree::insert()
{
    int x;
    //char ch;
    node *p,*q;
    if(root==NULL)
    {
        create();
    }
    cout<<"\nEnter the data:";
    cin>>x;
    p=new node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    q=new node;
    q=root;
    while(q!=NULL)
    {   //cout<<"Do you want to add new node to the left/right of ";
	//cout<<q->data;
        //cin>>ch;
        if((p->data)<(q->data))
        {
            if(q->left==NULL)
            {
                q->left=p;
                return;
            }
            else
            {
                q=q->left;
            }
        }//end of if
        else if((p->data)>(q->data))
        {
            if(q->right==NULL)
            {
                q->right=p;
                return;
            }
            else
            {
                q=q->right;
            }
        }//else of else..if
    }//end of while
}

void binary_search_tree::inorder(node *r)
{
	if(r!=NULL)
	{

		inorder(r->left);

		cout<<"\t"<<r->data;
		inorder(r->right);
	}
}


//Search
void binary_search_tree::search()
{
    node *temp;
	//temp=new node;
	temp=root;
    int key,flag=0;
	cout<<"\nEnter the Key to search:\t";
	cin>>key;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			flag=1;
			break;
		}
		else if(key>temp->data)
		{
			temp=temp->right;
		}
		else
		{
			temp=temp->left;

		}
	}
	if(flag==1)
	{
		cout<<"\nKey is found...!!!";
		cout<<"\n Search Successful..";
	}
	else
	{
		cout<<"\n Key not found";
	}
}

//Height
int binary_search_tree::get_height(node *T)
{
    int hl=0,hr=0;
    if(T==NULL)
    {
        return 0;
    }
    if(T->left==NULL && T->right==NULL)
        return 0;
    hl=get_height(T->left);
    hr=get_height(T->right);
    if(hl<hr)
        return hr+1;
    else
        return hl+1;
}



//Minimum
void binary_search_tree::get_min()
{
	node *temp;
//	temp=new node;
	temp=root;
	//cout<<temp->data;
	int min;
	while(temp->left!=NULL)
	{
		temp=temp->left;

	}
	min=temp->data;

	cout<<"Minimum value is:"<<min;

}

//Minimum
void binary_search_tree::get_max()
{
	node *temp;
	temp=new node;
	temp=root;
	//cout<<temp->data;
	int max;
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	max=temp->data;

	cout<<"Maximum value is:"<<max;

}
//Swap
node* binary_search_tree::swap(node *T)
{
	node *temp;

	if(T==NULL)
	{
		return NULL;
	}
	else
	{
		temp=T->left;
		T->left=swap(T->right);
		T->right=swap(temp);
		return T;
	}
}


int main()
{
    int ch;
    char choice;
    binary_search_tree obj;
    cout<<"-----------------------Create a Tree First----------------------------";
    obj.create();
    do
    {
        cout<<"Want to add more nodes to tree((Y/N):";
        cin>>choice;
        if(choice=='y'||choice=='Y')
        {
            obj.insert();
        }
        else
            goto label;
    }while(choice!='n');
label:
    do
    {
        cout<<"\n----------------------------------Menu----------------------------------";
        cout<<"\n1.Inorder Traversal \t2.Display Height \t3. Minimum value \t4. Maximum Value \t5. Swap Siblings \t 6. Search element \t7. Exit";
        cout<<"\nEnter the choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
                cout<<"\nInorder Travesal:\n";
                obj.inorder(obj.root);
                break;
        case 2:
                cout<<"\nHeight of Tree="<<obj.get_height(obj.root);
                break;
        case 3:
                obj.get_min();
                break;
        case 4:
                obj.get_max();
                break;
        case 5:
                obj.swap(obj.root);
                cout<<"\n\nSiblings Swapped";
                cout<<"\nNOTE: You can not search element and also Minimum and Maximum Value as Siblings are Swapped\n\n\n";
                break;
        case 6:
                obj.search();
                break;
        case 7:
		cout<<"\n----------------------------Program Terminated-------------------------";
		return 0;
        default: cout<<"Invalid Choice";
        }
    }while(ch!=7);
}
/*
Output:
akshay_chavan@kkw-HP-Pro-3330-MT:~/Desktop$ g++ BST.cpp
akshay_chavan@kkw-HP-Pro-3330-MT:~/Desktop$ ./a.out
-----------------------Create a Tree First----------------------------
Enter the root node:50
Want to add more nodes to tree((Y/N):y

Enter the data:30
Want to add more nodes to tree((Y/N):y

Enter the data:70
Want to add more nodes to tree((Y/N):y

Enter the data:25
Want to add more nodes to tree((Y/N):y

Enter the data:35
Want to add more nodes to tree((Y/N):y

Enter the data:65
Want to add more nodes to tree((Y/N):y

Enter the data:75
Want to add more nodes to tree((Y/N):n

Menu:
1.Display Height 	2. Minimum value 	3. Maximum Value 	4. Swap Siblings 	 5. Search element 	6. Exit
Enter the choice:1
Height of Tree is:3
Menu:
1.Display Height 	2. Minimum value 	3. Maximum Value 	4. Swap Siblings 	 5. Search element 	6. Exit
Enter the choice:2
Minimum value is:25
Menu:
1.Display Height 	2. Minimum value 	3. Maximum Value 	4. Swap Siblings 	 5. Search element 	6. Exit
Enter the choice:3
Minimum value is:75
Menu:
1.Display Height 	2. Minimum value 	3. Maximum Value 	4. Swap Siblings 	 5. Search element 	6. Exit
Enter the choice:4

Menu:
1.Display Height 	2. Minimum value 	3. Maximum Value 	4. Swap Siblings 	 5. Search element 	6. Exit
Enter the choice:2
Minimum value is:75
Menu:
1.Display Height 	2. Minimum value 	3. Maximum Value 	4. Swap Siblings 	 5. Search element 	6. Exit
Enter the choice:5

Enter the Key to search:	75

 Key not found
Menu:
1.Display Height 	2. Minimum value 	3. Maximum Value 	4. Swap Siblings 	 5. Search element 	6. Exit
Enter the choice:6

----------------------------Program Terminated-------------------------

*/

