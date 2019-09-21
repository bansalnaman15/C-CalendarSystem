#include<fstream.h>
#include<iomanip.h>
#include<iostream.h>
#include<conio>
#include<stdio>
class calendar{
	int leap, firstday;
	public:
	int year,month, date;
		calendar(){
			leap=0;
		}
		void checkleap();
		void displayfull(int);
		char* dayname(int);
		void datechecker();
		char* monthname(int);
		int numberOfDays(int);
		void write(int);
		void read();
		void Delete();
		int tellLeap();
		int daynumber(int,int,int);
		void displaymonth(int,int);
};

void calendar::checkleap(){
	if((year%400)==0) leap=1;
	else if ((year%4)==0){
		if((year%100)!=0) leap=1;
	}
}
int calendar :: tellLeap(){
	return leap;
}

char* calendar::dayname(int num){
	switch(num){
		case 0: return "Sunday";
		case 1: return "Monday";
		case 2: return "Tuesday";
		case 3: return "Wednesday";
		case 4: return "Thursday";
		case 5: return "Friday";
		case 6: return "Saturday";
		default: return NULL;
	}
}

char* calendar::monthname(int m){
	switch(m){
		case 0: return "January";
		case 1: return "February";
		case 2: return "March";
		case 3: return "April";
		case 4: return "May";
		case 5: return "June";
		case 6: return "July";
		case 7: return "August";
		case 8: return "September";
		case 9: return "October";
		case 10: return "November";
		case 11: return "December";
		default: return NULL;
	}
}

int calendar::numberOfDays (int month){

	switch(month)
	{
		case 0: 	return 31;
		case 1:	if(leap==1)
							return 29;
						else return 28;
	case 2: return 31;
	case 3: return 30;
	case 4: return 31;
	case 5: return 30;
	case 6: return 31;
	case 7: return 31;
	case 8: return 30;
	case 9: return 31;
	case 10: return 30;
	case 11: return 31;
	default: return 0;
	}
}

int calendar::daynumber(int day, int month, int year){
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
							  4, 6, 2, 4 };
	 year -= month < 3;
	 int a = ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
	 return a;
}

void calendar::Delete(){
	int n,k=0;
	calendar c;
	ifstream infile("calendar.dat", ios::binary);
	ofstream onfile("temp.dat",ios::binary);
	if(!infile)
	cout<<"File does not exist";
	else
	{
		read();
		cout<<"Enter the year to be deleted : ";
		cin>>n;
		while(infile.read((char*)&c,sizeof(c)))
		{
			if(c.year==n)
			k=1;
			else onfile.write((char*)&c,sizeof(c));
		}
		if(k==0)
		cout<<"\nRecord not found!";
		else cout<<"Record Deleted...";
		getch();
		onfile.close();
		infile.close();
		remove("calendar.dat");
		rename("temp.dat","calendar.dat");
	}
}

void calendar::displayfull(int year){
	int current = daynumber(01,01,year);
	cout<<"\n\n          CALENDAR "<<year;
	int days;
	for(int i=0; i<12; i++)
	{
		days = numberOfDays(i);
		cout<<"\n  --------------"<<monthname(i)<<"--------------\n";
		cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat \n";
		int k;
		for(k=0; k<current; k++)
		cout<<"     ";
			for(int j=1; j<=days; j++)
			{
				cout<<setw(5)<<j;
				if (++k > 6)
					{
						k = 0;
						cout<<endl;
					}

			}
			if (k)
			cout<<endl;
			current = k;
		}
}

void calendar :: displaymonth(int num, int y){
		int current = daynumber(01,num,y);
		int days = numberOfDays(num);
		cout<<"\n  --------------"<<monthname(num)<<"--------------\n";
		cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat \n";
		int k;
		for(k=0; k<current; k++)
		cout<<"     ";
		for(int j=1; j<=days; j++)
		{
			cout<<setw(5)<<j;
			if (++k > 6)
			{
				k = 0;
				cout<<endl;
			}
		}
		if (k)
			cout<<endl;
		current = k;
	}


void calendar::write(int y){
	ofstream onfile("calendar.dat",ios::binary|ios::app);
	calendar c;
	c.year=y;
	c.checkleap();
	onfile.write((char*)&c,sizeof(calendar));
	onfile.close();
}

void calendar::read(){
	ifstream infile("calendar.dat",ios::binary);
	if(!infile){
	cout<<"File Does not exists";
	return;
	}
	cout<<"Saved years:\n";
	calendar c;
	if(infile.read((char*)&c,sizeof(c)))
	while(infile.read((char*)&c,sizeof(c)))
		cout<<"->"<<c.year<<endl;
	else cout<<"No records\n";
}


int main()
{
	cout<<setw(60)<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_  "<<endl;
	cout<<setw(60)<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_  "<<endl;
	cout<<endl;
	cout<<setw(60)<<"~~~~~~~~   WELCOME TO C++    ~~~~~~~~~  "<<endl;
	cout<<setw(60)<<"~~~~~~~~  COMPUTER PROJECT   ~~~~~~~~~  "<<endl;
	cout<<setw(60)<<"~~~~~~~~         ON          ~~~~~~~~~  "<<endl;
	cout<<setw(60)<<"~~~~~~~~      CALENDAR		  ~~~~~~~~~  "<<endl;
	cout<<setw(60)<<"~~~~~~~~       SYSTEM        ~~~~~~~~~  "<<endl;
	cout<<setw(60)<<"~~~~~~~~                     ~~~~~~~~~  "<<endl;
	cout<<setw(60)<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_  "<<endl;
	cout<<setw(60)<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_  "<<endl;
	cout<<endl;
	cout<<setw(60)<<"!!!**** PRESS ANY KEY TO CONTINUE ****!!!";
	getch();
	clrscr();
	int ch, choice, y, num, number, flag, loop=1;
	cout<<"Enter any year: \n";
	cin>>y;
	calendar c;
	c.year = y;
	clrscr();
	do{
	clrscr();
	cout<<setw(10)<<y<<endl<<" 1. Display full year calendar \n 2. Display one calendar month \n 3. Check day for a date \n 4. Check leap year \n 5. Save year in record \n 6. Show saved years\n 7. Delete year from record  \n 8. Exit\n\n";
	cin>>choice;
	switch(choice){
		case 1: c.displayfull(y);
					break;
		case 2: {
						cout<<"Enter the month number to be displayed : ";
						cin>>num;
						c.displaymonth(num,y);
						break;
		}
		case 3: {
						cout<<"Enter date and month respectively : ";
						cin>>c.date>>c.month;
						number = c.daynumber(c.date, c.month, c.year);
						switch(number){
							case 0:	cout<<"Entered date is on a Sunday\n";
										break;
							case 1:	cout<<"Entered date is on a Monday\n";
										break;
							case 2:	cout<<"Entered date is on a Tuesday\n";
										break;
							case 3: 	cout<<"Entered date is on a Wednesday\n";
										break;
							case 4: 	cout<<"Entered date is on a Thursday\n";
										break;
							case 5: 	cout<<"Entered date is on a Friday\n";
										break;
							case 6: 	cout<<"Entered date is on a Saturday\n";
										break;
	}
	break;
}
		case 4: {
					c.checkleap();
					flag = c.tellLeap();
					if(flag)
						cout<<"\nEntered year is a leap year.\n";
					else
						cout<<"\nEntered year is not a leap year.\n";
					getch();
					break;
					}
		case 5: {
					 c.write(y);
					 cout<<"Year "<<y<<" saved in record!\n\n";
					 getch();
					 break;
					}
		case 6: {c.read();getch(); break;}
		case 7: {c.Delete(); break;}
		case 8: { loop = 0; break;}
	}
 }while(loop);
	return 0;
}