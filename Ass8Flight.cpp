/*There are flight paths between cities. If there is a flight between city A and city B then 
there is an edge between the cities. The cost of the edge can be the time that flight take 
to reach city B from A, or the amount of fuel used for the journey. Represent this as a 
graph. The node can be represented by airport name or name of the city. Use adjacency 
list representation of the graph or use adjacency matrix representation of the graph. 
Check whether the graph is connected or not. Justify the storage representation used.*/ 
#include<iostream>
using namespace std;
class flight
{
	int arr[20][20];
	int no;
	public:
		void getdata();
		void search();
		void display();
		void info();
};
void flight::getdata()
{
	
	cout<<"\nEnter the no. of cities:";
	cin>>no;
	cout<<"\nEnter the time duration of flight";
	for(int i=0;i<no;i++)
	{
		for(int j=0;j<no;j++)
		{
			cout<<"\nEnter the duration between "<<i<<" and "<<j;
			cin>>arr[i][j];
		}
	}
}
void flight::search()
{
	int s,d;
	cout<<"Enter the start and destination point:";
	cin>>s;
	cin>>d;
	if(arr[s][d]!=0)
	{
		cout<<"\nYour flight is present and its duration is "<<arr[s][d];
	}
	else
	{
		cout<<"\nDirect flight is not available";
	}
}
void flight::display()
{
	cout<<"\n";
	for(int i=0;i<no;i++)
	{
		for(int j=0;j<no;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void flight::info()
{
	int count,arr2[10],k=0;
	for(int i=0;i<no;i++)
	{
		for(int j=0;j<no;j++)
		{
			if(arr[i][j]!=0)
			{
				count=count+1;
				arr2[k]=j;
				k=k+1;
			}
		}
		cout<<"\n"<<i<<" is connected to "<<count<<" cities and that cities are ";
		for(int k=0;k<count;k++)
		{
			cout<<arr2[k];
		}
	}
}
int main()
{
	flight f;
	f.getdata();
	f.search();
	f.display();
	f.info();
	return 0;
}
