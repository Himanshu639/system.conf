
#include<iostream>
#include<fstream>
using namespace std;

struct student
{
	int roll;
	char name[20];
	char div;
	char address[20];
	
	void getdata()
	{
		cout<<"\nROLL NO.: ";
		cin>>roll;
		cout<<"\nNAME : ";
		cin>>name;
		cout<<"\nDIVISION : ";
		cin>>div;
		cout<<"\nADDRESS : ";
		cin>>address;
	}
	
	void putdata()
	{
		cout<<endl;
		cout<<"\nROLL NO.: "<<roll;
		cout<<"\nNAME : "<<name;
		cout<<"\nDIVISION : "<<div;
		cout<<"\nADDRESS : "<<address;
	}
};

class file
{
	fstream f;
	student s;
	public:
	void create();
	void display();
	void search();
};

void file :: create()
{
	int n;
	f.open("student.txt", ios::out);
	cout<<"\nHow many students you want to enter? ";
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cout<<"\nENTER DETAILS OF "<<i+1<<" STUDENT : "<<endl;
		s.getdata();
		f.write((char*)&s,sizeof(s));
	}
	f.close();
}

void file :: display()
{
	cout<<"\nSTUDENT DETAILS"<<endl;
	f.open("student.txt", ios::in);
	while (!f.eof())
	{
		f.read((char*)&s,sizeof(s));
		if (!f.eof())
			s.putdata();
	}
	f.close();
}

void file :: search()
{
	int r;
	cout<<"\nEnter the Roll No. of student you want to be Search : ";
	cin>>r;
	f.open("student.txt", ios::in);
	while (!f.eof())
	{
		f.read((char*)&s,sizeof(s));
		if (!f.eof() && s.roll==r)
		{
			s.putdata();
			break;
		}
		else
		{
			cout<<"\nStudent Record Not Found"<<endl;
		}
	}
	f.close();
}

int main()
{
	file o;
	int ch;
	
	do
	{
		cout<<"\n\n-----STUDENT INFORMATION-----"<<endl;
		cout<<"\n\t1.ADD \n\t2.DISPLAY \n\t3.SEARCH \n\t4.EXIT";
		cout<<"\nEnter Your Choice : ";
		cin>>ch;
		
		switch (ch)
		{
			
			case 1:
				o.create();
				break;
				
			case 2:
				o.display();
				break;
				
			case 3:
				o.search();
				break;
				
			case 4:
				cout<<"\nEXIT"<<endl;
				break;
			
			default:
				cout<<"\nInvalid Choice"<<endl;
		}
	}
	while (ch!=4);
	return 0;
}










