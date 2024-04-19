


#include<fstream>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstdio>
#include<dos.h>
#include<cstdlib>
#include <random>

using namespace std;
class plane                 // stores details of the planes
{ public:
	char planename[50], start[50], destination[50]; 
		char nam[50], st[50], dest[50];
    char date[50]; char da[50];
    char time[50];  char ti[50];
 	int planeno;  
	int pl;
    int distance;  int di;
	plane()                 // constructor
	{
		
	}
	void getdata()         // get details of the plane
	{
		cout << "Enter the following details..";
		cout << "\n\n\n\t\tPlane Number : ";
		cin >> planeno;
		cout << "\n\n\t\tPlane Name : ";
		cin>>ws;
		cin.getline(planename,50);
		cout << "\n\n\t\tBoarding Point : ";
		cin.getline(start,50);
		cout << "\n\n\t\tDestination : ";
		cin.getline(destination,50);
		cout<<"\n\n\t\tDistance : ";
		cin>>distance;
		cout<<"\n\n\t\t Date : ";
		cin>>ws;
		cin.getline(date,50);
		cout<<"\n\n\t\tTime : ";
		cin.getline(time,50);
		cout<<endl;		
	}
	void putdata()          // display details of the plane
	{
		cout<<planeno<<"\t\t\t"<<planename<< "\t\t\t"<<start<< "\t\t\t"<<destination<<"\t\t\t"<<date<<"\t\t\t"<<time;
		cout<<endl;
	}

	void modify()        // used to modify any record
	{
		cout << "\n\n\t\tPlane Number : ";
		cout << planeno;
		cout << "\n\t\tPlane Name : ";
		puts(planename);
		cout << "\n\t\tBoarding point : ";
		puts(start);
		cout << "\n\t\tDestination : ";
		puts(destination);
		cout << "\n\n\tEnter new Details. " << endl;
		cout << "\n\n\t\tNew Plane No. :(Enter -1 to retain old one) ";
		cin >> pl;
		cout << "\n\t\tNew Plane Name. :(Press '.' to retain old one) ";
		cin>>ws;
		cin>>nam;
		cout << "\n\t\tNew Boarding Pt. :(press '.' to retain old ome) ";
		cin>>st;
		cout << "\n\tNew Destination. :(press '.' to retain old one) ";
		cin>>dest;
		cout<<"\n\t New Distance. :(Enter -1 to retain old one)";
		cin>>di;
		cout<<"\n\tNew Date :(press '.' to retain old one)";
		cin>>ws;
		gets(da);
		cout<<"\n\tNew Time :(press'.' to retain old one )";
		gets(ti);
		if (pl != -1)
		
			planeno = pl;
		if (strcmp(nam, ".") != 0)
			strcpy(planename, nam);
		if (strcmp(st, ".") != 0)
			strcpy(start, st);
		if (strcmp(dest, ".") != 0)
			strcpy(destination, dest);
	    if(di!=-1)
	       distance=di;
	    if(strcmp(da,".")!=0)
	       strcpy(date,da);
	    if(strcmp(ti,".")!=0)
	       strcpy(time,ti);
	}

}p;        // object of class "plane"

class tickets             // stores details of tickets made
{  public:
	int age, pn;
	char name[50];
    char psource[50],pdestination[50];
	int resno;     // reservation no.
    float fare;
    float rough_fare;

	void get()             // get details of user for tickets
	{
		resno=rand()+(350 - 20 + 1);
		cout<< "\nEnter your details :-......";
		cout << "\n\n\tName : ";
		cin>>ws;
		gets(name);
		cout << "\n\tAge : ";
		cin >> age;
		
		cout<<"\n\tSource : ";
		cin>>ws;
		gets(psource);
		cout<<"\n\tDestination : ";
		gets(pdestination);
	    float rough_fare=price(psource,pdestination);
		cout << "\n\n\n\t\t\tWait till your ticket is being booked...";
		cout << "\n\n\t\tYour Reservation No. is : " << resno;
		//fare=rough_fare;//+(rough_fare*0.05);
		fare=rough_fare;
		cout<<"\n\tPrice : "<<fare<<" Birr."<<endl;

	}
	void put()             // display details of tickets
	{
		
		cout << "\nYour Details are : ...";
		cout << "\n\tReservation No. : " << resno;
		cout << "\n\tName : "; puts(name);
		cout << "\n\tAge : " << age;
        cout<<"\n\tSource : "; puts(psource);
		cout<<"\n\tDestination : "; puts(pdestination);
		cout<<"\n\tDate : ";rdate(psource,pdestination);
		cout<<"\n\tTime : ";rtime(psource,pdestination);
	    cout<<"\n\tPrice : "<<fare;
	}
	int price(char tsource[50],char tdestination[50]);
	void rdate(char tsource[50],char tdestination[50]);
	void rtime(char tsource[50],char tdestination[50]);
}t;       // object of class "tickets"

void tickets::rdate(char tsource[50],char tdestination[50])
{
	ifstream fin;
	fin.open("plane.dat",ios::in|ios::binary);
	plane p2;
	char adate[50];
	while(!fin.eof())
	{
		 fin.read((char*)&p2,sizeof(p2));
	    if(strcmp(p2.start,tsource)==0&&strcmp(p2.destination,tdestination)==0)
	     strcpy(adate,p2.date);
	
	} fin.close();
	cout<<adate;
	
}
void tickets:: rtime(char tsource[50],char tdestination[50])
{
	ifstream fin;
	fin.open("plane.dat",ios::in|ios::binary);
	plane p2;
	char atime[50];
	while(!fin.eof())
	{
		 fin.read((char*)&p2,sizeof(p2));
	    if(strcmp(p2.start,tsource)==0&&strcmp(p2.destination,tdestination)==0)
	     strcpy(atime,p2.time);
	
	} fin.close();
	cout<<atime;
	
}
void write()     // writes details to file
{  	
	ofstream fout;
	fout.open("plane.dat", ios::out | ios::binary);
	if (!fout)
		cout << "File can't be created";
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		system("cls");
		
		p.getdata();
		fout.write((char*)& p, sizeof(p));
		cout << "\n\n\n\n\t\tWant to enter more ? (y/n) ";
		cin >> ch;
	}
	fout.close();
}

void display()               //  display/  read details of a file
{
	ifstream fin;
	fin.open("plane.dat", ios::in | ios::binary);
	if (!fin)
		cout << "\n\n\n\n\n\n\t\tFile can't be opened ";
	
	cout<<"  Plane Number \t\t Plane Name \t\t Source \t\t Destination \t\t Date \t\t Time \n\n ";
	cout<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;
	while (fin.read((char*)& p, sizeof(p)))
	
	{
		p.putdata();
		getch();
		}
	fin.close();
}

void add()                 // add record to the file
{

	ofstream fout;
	fout.open("plane.dat", ios::out | ios::app | ios::binary);
	if (!fout)
		cout << "File can't be opened";
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		system("cls");
		p.getdata();
		fout.write((char*)& p, sizeof(p));
		cout << "\n\n\n\n\t\tWant to enter more ? (y/n) ";
		cin >> ch;
	}
	fout.close();
}

void search()         // search any record from the file
{
	ifstream fo;
	fo.open("plane.dat", ios::out | ios::binary);
	if (!fo)
		cout << "\n\n\t\t\tFile Can't be Found ... ";
	cout << "\n\n\n\t\tEnter the Plane No. whose details you want to see . : ";
	int ps;
	cin >> ps;
	while (!fo.eof())
	{
		fo.read((char*)& p, sizeof(p));
		if (p.planeno == ps)
		{
			p.putdata();
			cout << "\n\n\tPress 'Enter' .. ";
			_getch();
			break;
		}
		else
			cout << "\n\n\n\t\tNo such Plane is in Service ";
	}
	fo.close();
}

void mod()             // modify any record 
{
	fstream fio;
	fio.open("plane.dat", ios::in | ios::out | ios::binary);
	int pno; long pos; char found = 'f';
	cout << "\n\n\tEnter the Plane no. whose record is to be modified \n ";
	cin >> pno;
	while (!fio.eof())
	{
		pos = fio.tellg();
		fio.read((char*)& p, sizeof(p));
		if (p.planeno == pno)
		{
			p.modify();
			fio.seekg(pos);
			fio.write((char*)& p, sizeof(p));
			found = 't';
			break;
		}
	}
	if (found == 'f')
		cout << "\n\n\tRecord not found !!\n";
	fio.seekg(0);
	fio.close();
}

void del()              // delete any record
{
	ifstream fio;
	ofstream file;
	fio.open("plane.dat", ios::in | ios::binary);
	file.open("temp.dat", ios::out | ios::binary);
	int pn; char found = 'f', confirm = 'n';
	cout << "\n\n\t\tEnter the Plane No. whose record is to be deleted \n ";
	cin >> pn;
	
	while (!fio.eof())
	{
		fio.read((char*)& p, sizeof(p));
		if (p.planeno == pn)
		{
			p.putdata();
			found = 't';
			cout << "\n\n\tAre you sure you want to delete this record? (y/n).. ";
			cin >> confirm;
			if (confirm == 'n')
				file.write((char*)& p, sizeof(p));
		}
		else
			file.write((char*)& p, sizeof(p));
	}
	if (found == 'f')
		cout << "\n\n\n\tRecord not found !! \n";
	fio.close();
	file.close();
	remove("plane.dat");
	rename("temp.dat", "plane.dat");
	
}

void reservation()                  // ticket reservation
{
	cout << "\n\n\t\t\tREGISTER YOUR TICKETS ";
	char a;
	cout << "\n\n\n\t\tWant to see details of flights available ?(y/n)";
	cin >> a;
	if (a == 'y' | a == 'Y')
	{
		display();
	}
	ofstream fo;
	fo.open("ticket.dat", ios::out | ios::binary);
	if (!fo)
		cout << "file can't be opened..";
	char b = 'y';
	while (b == 'y' | b == 'Y')
	{
		t.get();
		fo.write((char*)& t, sizeof(t));
		cout << "\n\n\t\tWant to register more tickets ?(y/n)";
		cin >> b;
	}
	
	fo.close();
}

int tickets:: price(char tsource[50],char tdestination[50]) //price Calculation
{   
	ifstream fin;
	fin.open("plane.dat",ios::in|ios::binary);
	if(!fin)
	{
    cout<<"File Is empty"<<endl;
	 exit(0);
    }  plane p1;
	int fare;
	int tdistance;
	while(!fin.eof())
	{   fin.read((char*)&p1,sizeof(p1));
	    if(strcmp(p1.start,tsource)==0&&strcmp(p1.destination,tdestination)==0)
	      tdistance=p1.distance;
	 }
	 if(tdistance<=200)
	 fare=20*tdistance;
	 else if(tdistance>200&&tdistance<=500)
	 fare=18*tdistance;
	 else if(tdistance>500&&tdistance<=1000)
	 fare=15*tdistance;
	 else if(tdistance>1000&&tdistance<=2500)
	 fare=14*tdistance;
	 else if(tdistance>2500&&tdistance<=5000)
	 fare=12*tdistance;
	 else if(tdistance>5000&&tdistance<=10000)
	 fare=10*tdistance;
	 else
	 fare=8*tdistance;
	 
		  return (fare);
		  fin.close();
}

void cancellation()          // ticket cancellation
{   
	cout << "Welcome to CANCELLATION counteR";
	cout << "\n\n\n";
	ifstream fin;
	ofstream fo;
	fin.open("ticket.dat", ios::in | ios::binary);
	fo.open("temp.dat", ios::out | ios::binary);
	if (!fin)
		cout << "\n\t\t\tFile can't be found ... ";
	if (!fo)
		cout << "\n\t\t\tFile can't be opened....";
	cout << "\n\n\t\tEnter the Reservation No. which you want to cancel ";
	int rn;
	cin >> rn;
	while (!fin.eof())
	{
		fin.read((char*)& t, sizeof(t));
		if (t.resno == rn)
		{
			t.put();
			cout << "\n\n\tDo you really want to cancel your ticket ?(y/n)";
			char r;
			cin >> r;
			if (r == 'y' || r == 'Y')
			{
				cout << "\n\n\t\t\tYour Ticket has been cancelled ";
			}
			else
			{
				fo.write((char*)& t, sizeof(t));
			}
			break;
		}
		else
		{
			cout << "\n\n\t\tSorry!! No such reservation has been done...";
			fo.write((char*)& t, sizeof(t));
		}
	}
	remove("ticket.dat");
	rename("temp.dat", "ticket.dat");
	fin.close();
	fo.close();
}

void dispreserve()                // display records of tickets
{
	ifstream fin;
	fin.open("ticket.dat", ios::in | ios::binary);
	if (!fin)
		cout << "\n\n\n\t\t\t File Can't Be opened .. ";
	cout << "Enter the Reservation No. of Ticket you Want to see  :  ";
	int res;
	cin >> res;
	int a = 0;
	while (!fin.eof())
	{
		fin.read((char*)& t, sizeof(t));
		if (t.resno == res)
		{
			a = 1;
			break;
		}
		else
			a = 4;
	}
	if (a == 1)
	{
		t.put();
		cout << "\n\n\tPress Enter to go back to the menu . ";
            		_getch();
	}
	if (a == 4)
		cout << "\n\n\n\t\tNo such Reservation has been done . ";
	fin.close();
}
// PROGRAM STARTS FROM HERE...

int main()
{
	
       
      mainmap: 
	system("cls");
		cout <<"\n\n\t\t\t\t  ************************************** \n";
		cout<<"\t\t\t\t               ELITE AIRLINE       \n";
		cout <<"\t\t\t\t  ************************************** \n\n";
	cout << "\n\n\n\n\t\t\t  (1.)  ADMINISTRATOR  ";
	cout << "\n\n\t\t\t  (2.)  USER   ";
	cout << "\n\n\t\t\t Enter 0 if u want to exit ";
	int den;
	cout << "\n\n\n\t\tEnter : ";
	cin >> den;
	
	system("cls");
	if (den == 0)
	{
		cout << "\n\n\t\t\tExitting from the software ... ";
		cout << "\n\n\n\n\n\n\t\tThanks for trying it..";
		exit(0);

	}

	else if (den == 2)
	{

		char ch = 'y';
		while (ch == 'y' || ch == 'Y')
		{
			system("cls");
			cout << "\n\n\n\n\n\n";
			cout << "*************************************************************************";
			cout << "\n\n\n\t\t\t\t\t\tM E N U !!! ";
			cout << "\n\n\t\t\t(1.) Display Flight Details . ";
			cout << "\n\n\t\t\t(2.) Reserve a Ticket . ";
			cout << "\n\n\t\t\t(3.) Display your Ticket . ";
			cout << "\n\n\t\t\t(4.) Cancel a Ticket . ";
			cout << "\n\n\t\t\t(5.) Exit . ";
			cout << "\n\n\n";
			cout << "*************************************************************************";
			int choice;
			cout << "\n\n\n\t\t\t\t\tEnter your choice... : ";
			cin >> choice;
			system("cls");		
			switch (choice)
			{
			case 1: display();
				break;
			case 2: reservation();
				break;
			case 3: dispreserve();
				break;
			case 4: cancellation();
				break;
			case 5: cout << "\n\n\t\t\tExitting from the software ... ";
				cout << "\n\n\n\n\n\n\t\tThanks for trying it..";
				exit(0);
				break;
			default: cout << "\n\n\n\t\t\tUnknown choice...";
				cout << "\n\n\t\t\tWant to enter the choice again?(y/n)";
				cin >> ch;
			}
		}
	}

	else if (den == 1)
	{
	
		char ch1 = 'y';
		while (ch1 == 'y' || ch1 == 'Y')
		{
			system("cls");
			cout << "\n\n\n\n\n\n";
			cout << "*************************************************************************";
			cout << "\n\n\n\t\t\t\t\t\tM E N U !!! ";
			cout << "\n\n\t\t\t(1.) Create Brand New File .";
			cout << "\n\n\t\t\t(2.) Display Flight Details . ";
			cout << "\n\n\t\t\t(3.) Add Record . ";
			cout << "\n\n\t\t\t(4.) Search a Data . ";
			cout << "\n\n\t\t\t(5.) Modify a Record . ";
			cout << "\n\n\t\t\t(6.) Delete a Record . ";
			cout << "\n\n\t\t\t(7.) Exit.";
			cout << "\n\n\n";
			cout << "*************************************************************************";
			int choice1;
			cout << "\n\n\n\t\t\t\t\tEnter your choice... : ";
			cin >> choice1;
			system("cls");
			switch (choice1)
			{
			case 1: write();
				break;
			case 2: display();
				break;
			case 3: add();
				break;
			case 4: search();
				break;
			case 5: mod();
				break;
			case 6: del();
				break;

			case 7: cout << "\n\n\t\t\tExitting from the software ... ";
				cout << "\n\n\n\n\n\n\t\tThanks for trying it..";
				goto mainmap;
				break;
			default: cout << "\n\n\n\t\t\tUnknown choice...";
				cout << "\n\n\t\t\tWant to enter the choice again?(y/n)";
				cin >> ch1;
			}
		}
	}
	_getch();
}



