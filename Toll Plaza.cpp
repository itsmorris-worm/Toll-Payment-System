//*******************************************PROJECT: TOLL-PLAZA*************************************************
#include<iostream>
#include<iomanip>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;
class vehicle            //ABSTRACT CLASS 
	{
		protected:        //protected access specifier to make it inheritable
		string vehicle_number;
		long int collection;
		int x,temp;
		public:
			void vehicle_data();
			void way();
	};
void vehicle::way()
{
	cout<<"PLEASE SELECT THE BULLET NUMBER: "<<endl<<"1->single journey\n"<<"2->Return Journey\n"<<"3->Monthly pass\n";
	f:
	cin>>temp;
	switch(temp)         //loading data on files
	{
		case 1:
			{ofstream fout1;      
	      fout1.open("single_journey.dat");
	      fout1<<vehicle_number<<"\n";
	      fout1.close();
	       break;}
	    case 2:
		{
	      ofstream fout2;
	      fout2.open("return_journey.dat");
	      fout2<<vehicle_number<<"\n";
	      fout2.close();
	      break;}
	    case 3:{
	    	ofstream fout3;
	    	fout3.open("monthly.dat");
	    	fout3<<vehicle_number<<"\n";
	    	fout3.close();
	    	break;}
	    default:{
	    	cout<<"You haven't chosen any! Please select one:  ";
		    goto f;}  
     }
}
//             DERIVED CLASSES
class non_paid:public vehicle
{
	public:
		void for_nonpaid();
};
class car:public vehicle
{
	public:
		void for_car();
};
class bus:public vehicle
{
	public:
		void for_bus();
};
void non_paid::for_nonpaid()
{
	ofstream fout("nonpaid_vehicle.dat",ios::app);
	fout<<vehicle_number<<"\n";
	fout.close();
	cout<<"CAN PASS!\n";
}
void car::for_car()
{
	pix0:
	ofstream fout;
	fout.open("car.dat",ios::app);
	fout<<vehicle_number<<"\n";
	fout.close();
	
	switch(temp)
	{
		case 1:
			{cout<<"You are to pay 95 INR for single journey\n"<<"THANK YOU!\n";
			ifstream fin("collection.dat");
			fin>>collection;
			collection+=95;
			ofstream fout("collection.dat");
			fout<<collection;
			fout.close();}
			break;
		case 2:
		    {cout<<"you are to pay 145 INR for return journey\n"<<"THANK YOU!\n";
		    ifstream fin("collection.dat");
			fin>>collection;
			collection+=145;
			ofstream fout("collection.dat");
			fout<<collection;
			fout.close();}
			break;
	    case 3:
		    cout<<"Permitted to pass through(montly pass holder)!\n";
		break;
		default:
			goto pix0;
    }
}
void bus::for_bus()
{
	xy:
	ofstream fout;
	fout.open("bus.dat",ios::app);   //opening files in append mode
	fout<<vehicle_number<<"\n";
	fout.close();
	switch(temp)
	{
	case 1:
			{cout<<"You are to pay 325 for one way\n"<<"THANK YOU!\n";
			ifstream fin("collection.dat");
			fin>>collection;
			collection+=325;
			ofstream fout("collection.dat");
			fout<<collection;
			fout.close();}
			break;
		case 2:
		    {cout<<"you are to pay 485 for two way\n"<<"THANK YOU!\n";
		    ifstream fin("collection.dat");
			fin>>collection;
			collection+=485;
			ofstream fout("collection.dat");
			fout<<collection;
			fout.close();}
			break;
		case 3:
		    cout<<"Permitted to pass through!\n";	
        break;
        default:
        	goto xy;
        	break;
    }
}
class upto_3axle:public vehicle
{
	public:
		void for_upto_3axle();
};
void upto_3axle::for_upto_3axle() 
{
	xy1:
	ofstream fout;
	fout.open("upto_3axle.dat",ios::app);
	fout<<vehicle_number<<"\n";
	fout.close();
	switch(temp)
	{
	    case 1:
			{cout<<"You are to pay 505 INR for single journey\n"<<"THANK YOU!\n";
			ifstream fin("collection.dat");
			fin>>collection;
			collection+=505;
			ofstream fout("collection.dat");
			fout<<collection;
			fout.close();}
			break;
		case 2:
		    {cout<<"you are to pay 760 INR for return journey\n"<<"THANK YOU!\n";
		    ifstream fin("collection.dat");
			fin>>collection;
			collection+=760;
			ofstream fout("collection.dat");
			fout<<collection;
			fout.close();}
			break;
		case 3:
		    cout<<"Permitted to pass through!\n";
			break;
		default:
			goto xy1;
			break;
    }
}
class _4to7axle:public vehicle
{
	public:
		void for_4to7axle();
};
void _4to7axle::for_4to7axle()
{
	xy3:
	ofstream fout;
	fout.open("4to7axle.dat",ios::app);
	fout<<vehicle_number<<"\n";
	fout.close();
		switch(temp)
	{
	case 1:
			{cout<<"You are to pay 505 INR for single journey\n"<<"THANK YOU!\n";
			ifstream fin("collection.dat");
			fin>>collection;
			collection+=505;
			ofstream fout("collection.dat");
			fout<<collection;
			fout.close();}
			break;
		case 2:
		    {cout<<"you are to pay 760 INR for return journey\n"<<"THANK YOU\n";
		    ifstream fin("collection.dat");
			fin>>collection;
			collection+=760;
			ofstream fout("collection.dat");
			fout<<collection;
			fout.close();}
			break;
		case 3:
		    cout<<"Permitted to pass through!\n";
		default:
			goto xy3;
			break;
    }
}
void vehicle::vehicle_data()
{
	time_t now=time(0);   //current system time under <ctime> library
	char* time_=ctime(&now);
	
	cout<<"enter the vehicle number: ";
	cin>>vehicle_number;
	ofstream outfile,fout;
	outfile.open("vehicle_data.dat",ios::app);
	outfile<<vehicle_number<<"\n";
	outfile.close();
	fout.open("vehicle_time.dat",ios::app);
	fout<<time_;
	fout.close();
}	
void function1()
{    
   
	cout<<"PRESS THE BULLET KEY FOR THE TYPE OF VEHICLE\n";
	cout<<"1->Car/Jeep/Van"<<endl<<"2->Bus/Truck"<<endl<<"3->Upto 3 Axle"<<endl<<"4->4 to 7 Axle vehicle\n"<<"5->Government vehicle/Ambulance\n"<<endl;
   	 pix1:
	   car a;
	bus b;
    upto_3axle c;
    _4to7axle d;
    non_paid e;
	int y;
	cin>>y;
	switch(y)
	{
		case 1:
			a.vehicle_data();
			a.way();
			a.for_car();
			break;
		case 2:
	        b.vehicle_data();
	        b.way();
	        b.for_bus();
	        break;
	    case 3:
	    	c.vehicle_data();
	    	c.way();
	    	c.for_upto_3axle();
	    	break;
	    case 4:
	    	d.vehicle_data();
	    	d.way();
	    	d.for_4to7axle();
	    	break;
	    case 5:
	    	e.vehicle_data();
	    	e.for_nonpaid();
	    	break;
	    default:
	    	cout<<"you haven't chosen any!\n";
			goto pix1;
	}
	
}

void search()
{
	cout<<"please enter the vehicle number to search: ";
	string x,y;
	const int N=100;
	char line[N];
	char line1[100],line2[100];
	cin>>x;
	ifstream fin("vehicle_data.dat");
	ifstream fin1("vehicle_time.dat");
	while(!fin.eof()&&!fin1.eof())
	{
		fin>>y;
	    int z=x.compare(y);
			fin1.getline(line,N);
		if(z==0&&strlen(line)!=0){
			ifstream fin2("up_time.dat");
			while(fin2.getline(line1,100))
			{
				int z=strcmp(line,line1);
				if(z==0)
			{cout<<"vehicle passed from meerut to delhi(UP) way on "<<line<<endl;}
		    }
		    ifstream fin3("down_time.dat");
		    while(fin3.getline(line2,100))
		    {
		    	int t=strcmp(line,line2);
		    	if(t==0)
		    	{cout<<"vehicle passed from delhi to meerut(down)way on "<<line<<endl;}
			}
		}
		else
		{;}
		}
}
//void data_for_passing()
void data_vehiclewise()
{
	system("cls");
	int x,z,k;
	string g,f,i,j;
	int count=0;
	int count1=0;
	cout<<"           Please select one:)         \n";
	cout<<"1->Data of Cars/Jeep/Van\n"<<"2->Data of bus/trucks\n"<<"3->Data of upto 3 axle vehicles\n"<<"4->Data of 4-7 axle vehicles\n";
	cout<<"5->Data of Government vehicles and Ambulances\n";
    v:
	cin>>x;
	switch(x)
	{
		case 1:
			{
				ifstream fin("car.dat");
				system("cls");
				cout<<"VEHICLE NUMBERS:-\n";
				while(fin>>g){
	            cout<<g<<endl;
				count++;}
				fin.close();
				cout<<"\nTOTAL CARS/JEEP/VAN PASSED FROM BOTH THE WAYS : "<<count<<endl;
			}
			break;
		case 2:
			{
				ifstream fin("bus.dat");
				system("cls");
				cout<<"VEHICLE NUMBERS:-\n";
				while(fin>>g){
	            cout<<g<<endl;
				count++;}
				fin.close();
				cout<<"\nTOTAL BUS/TRUCKS PASSED FROM BOTH THE WAYS : "<<count<<endl;
			}
			break;
		case 3:
			{
					ifstream fin("upto_3axle.dat");
				system("cls");
					cout<<"VEHICLE NUMBERS:-\n";
				while(fin>>g){
	            cout<<g<<endl;
				count++;}
				fin.close();
				cout<<"\nTOTAL VEHICLES UPTO 3 AXLES PASSED FROM BOTH THE WAYS : "<<count<<endl;	// ©@daRsh_raj.11812708
			}
			break;
		case 4:
			{
					ifstream fin("4to7axle.dat");
				system("cls");
					cout<<"VEHICLE NUMBERS:-\n";
				while(fin>>g){
	            cout<<g<<endl;
				count++;}
				fin.close();
				cout<<"\nTOTAL VEHICLES FROM 4 TO 7 AXLES THAT PASSED FROM BOTH THE WAYS : "<<count<<endl;	
			}
			break;
		case 5:
			{
					ifstream fin("nonpaid_vehicle.dat");
				system("cls");
					cout<<"VEHICLE NUMBERS:-\n";
				while(fin>>g){	
	            cout<<g<<endl;
				count++;}
				fin.close();
				cout<<"\nTOTAL NON-PAID VEHICLES INCLUDING GOVERNMENT'S AND AMBULANCES THAT PASSED FROM BOTH THE WAYS : "<<count<<endl;	
			}
			break;
			default:
			cout<<"YOU HAVEN'T SELECTED ANY\n";
			goto v;
           
	}	
}
void data_lanewise()
{    
    system("cls");
	int x;
	string h;
	int count=0;
	cout<<"                                               What are you looking for:)                             \n";
	cout<<"1->vehicles passed from lane1\n"<<"2->vehicles passed from lane 2\n"<<"3->vehicles passed from lane 3\n"<<"4->vehicles passed from lane 3\n";
	cout<<"4->vehicles passed from fast lane 4\n"<<"5->vehicles passed from lane 5\n"<<"6->vehicles passed from lane 6\n"<<"7->vehicles passed from lane 7\n";
    cout<<"8->vehicles passed from fast lane 8\n"<<"9->EXIT\n";
	xz:	
	cin>>x;
	switch(x)
	{
		case 1:
			{
				ifstream fin("lane1.dat");
				cout<<"VEHICLE NUMBERS;)\n";
				system("cls");
				while(fin>>h)
			    {
				cout<<h<<"\n";
				count++;
			   	}
			   	fin.close();
			    cout<<"\nnumber of vehicles passed from lane 1: "<<count<<endl;
			}
			
			break;
		 case 2:
			{
				system("cls");
				ifstream fin("lane2.dat");
					cout<<"VEHICLE NUMBERS;)\n";
				while(fin>>h)
			    {
				cout<<h<<"\n";
				count++;
			   	}
			   	fin.close();
			    cout<<"\nNumber of vehicles passed from lane 2: "<<count<<endl;
			}
			 break;
			  case 3:
			{system("cls");
				ifstream fin("lane3.dat");
					cout<<"VEHICLE NUMBERS;)\n";
				while(fin>>h)
			    {
				cout<<h<<"\n";
				count++;
			   	}
			   	fin.close();
			    cout<<"\nNumber of vehicles passed from lane 3: "<<count<<endl;
			}
			 break;
			  case 4:
			{system("cls");
				ifstream fin("lane1.dat");
					cout<<"VEHICLE NUMBERS;)\n";
				while(fin>>h)
			    {
				cout<<h<<"\n";
				count++;
			   	}
			   	fin.close();
			    cout<<"\nNumber of vehicles passed from lane 1: "<<count<<endl;
			}
			 break;
			  case 5:
			{system("cls");
				ifstream fin("lane5.dat");
					cout<<"VEHICLE NUMBERS;)\n";
				while(fin>>h)
			    {
				cout<<h<<"\n";
				count++;
			   	}
			   	fin.close();
			    cout<<"\nNumber of vehicles passed from lane 5: "<<count<<endl;
			}
			 break;
			  case 6:
			{system("cls");
				ifstream fin("lane6.dat");
					cout<<"VEHICLE NUMBERS;)\n";
				while(fin>>h)
			    {
				cout<<h<<"\n";
				count++;
			   	}
			   	fin.close();
			    cout<<"\nNumber of vehicles passed from lane 6: "<<count<<endl;
			}
			 break;
			  case 7:
			{system("cls");
				ifstream fin("lane7.dat");
					cout<<"VEHICLE NUMBERS;)\n";
				while(fin>>h)
			    {
				cout<<h<<"\n";
				count++;
			   	}
			    fin.close();
				cout<<"\nNumber of vehicles passed from lane 7: "<<count<<endl;
			}
			 break;
			  case 8:
			{system("cls");
				ifstream fin("fastlane8.dat");
					cout<<"VEHICLE NUMBERS;)\n";
				while(fin>>h)
			    {
				cout<<h<<"\n";
				count++;
			   	}
			   	fin.close();
			    cout<<"\nNumber of vehicles passed from lane 8: "<<count<<endl;
			}
			break;
			case 9:
				exit(1);
			 break;
			 default:
			 	cout<<"you haven't selected one!\n";
			 	goto xz;			 
	}
}
void enter_database()
{
	cout<<"CHOOSE ONE: \n"<<"1->SEARCH FOR VEHICLE\n"<<"2->TOTAL COLLECTION\n"<<"3->GET DATA OF VEHICLES LANEWISE\n"<<"4->GET DATA OF VEHICLES TYPEWISE\n"<<"5->EXIT\n";
	int x;
	l:
	cin>>x;
	switch(x)
	{
		case 1:
			r:
				char x;
			search();
			cout<<"Search terminated!\n"<<"Do you want to search another vehicle?(y/n): ";
			cin>>x;
			if(x=='y')
			goto r;//changed here
			break;
		case 2:
				{	long x;
			ifstream fin("collection.dat");
			fin>>x;
		    cout<<"THE TOTAL COLLECTION AS OF NOW IS: "<<x<<endl;
		    fin.close();
			}
		break;
		case 3:
		    data_lanewise();
		    break;
		case 4:
			data_vehiclewise();
			break;
		case 5:
			exit(1);
		default:
			cout<<"You haven't chosen any\n";
			goto l;
			break;
			}
}
void up_time()
{
	char line1[100],line2[100];
	ifstream fin1("vehicle_time.dat");
			while(fin1.getline(line1,100))//(!fin.eof())
			{
				strcpy(line2,line1);
			}
			fin1.close();
			ofstream fout2("up_time.dat",ios::app);
			fout2<<line2<<"\n";
			fout2.close();
}
void down_time()
{
	
	char line1[100],line2[100];
	ifstream fin1("vehicle_time.dat");
			while(fin1.getline(line1,100))//(!fin.eof())
			{
				strcpy(line2,line1);
			}
			fin1.close();
			ofstream fout2("down_time.dat",ios::app);
			fout2<<line2<<"\n";
			fout2.close();
}
void fn_for_lane()
{
cout<<"please enter the lane number from 1 to 8\n";
cout<<"MEERUT TO DELHI WAY\n";
cout<<"1->Way 1\n"<<"2->Way 2\n"<<"3->Way 3\n"<<"4->Way 4(FAST)\n";
cout<<"DELHI TO MEERUT WAY\n";
cout<<"5->Way 5\n"<<"6->Way 6\n"<<"7->Way 7\n"<<"8->Way 8(FAST)\n";
cout<<"Any key to exit\n";
int x;
cin>>x;
switch(x)
{
	case 1:
		{
			l:
			system("cls");
			cout<<"***************LANE 1*******************\n";
			function1();
			string line;
			const int N=100;
			
			ofstream fout("lane1.dat",ios::app);
			ifstream fin;
			fin.open("vehicle_data.dat");
			while(!fin.eof())
			{
				fin>>line;	
			}
			fout<<line<<"\n";
			ofstream fout1("UP.dat",ios::app);
			fout1<<line<<"\n";
			fout1.close();
			fout.close();
			fin.close();
			up_time();
			cout<<"Do you want to continue in the same lane(y/n)\n";
			char x;cin>>x;
		    if(x=='y')
		    goto l;
     	break;}
	case 2:
			{
			h:
			system("cls");
			cout<<"***************LANE 2*******************\n";
			function1();
			string line;
			ofstream fout("lane2.dat",ios::app);
			ifstream fin;
			fin.open("vehicle_data.dat");
			while(!fin.eof())
			{
				fin>>line;	
			}
			fout<<line<<"\n";
			ofstream fout1("UP.dat",ios::app);
			fout1<<line<<"\n";
			fout1.close();
			fout.close();
			fin.close();
			up_time();
			cout<<"Do you want to continue in the same lane(y/n)\n";
			char x;cin>>x;
		    if(x=='y')
		    goto h;
	    break;}
	case 3:
		{  
		i:
		 system("cls");
			cout<<"***************LANE 3*******************\n";
			function1();
			string line;
			ofstream fout("lane2.dat",ios::app);
			ifstream fin;
			fin.open("vehicle_data.dat");
			while(!fin.eof())
			{
				fin>>line;	
			}
			fout<<line;
			ofstream fout1("UP.dat",ios::app);
			fout1<<line<<"\n";
			fout1.close();
			fout.close();
			fin.close();
			up_time();
			cout<<"Do you want to continue in the same lane(y/n)\n";
			char x;cin>>x;
		    if(x=='y')
		    goto i;
	    break;}
    case 4:
    	{
		   j:	
		    system("cls");
			cout<<"***************FAST LANE 4*******************\n";
		    function1();
			string line;
			ofstream fout("fastlane4.dat",ios::app);
			ifstream fin;
			fin.open("vehicle_data.dat");
			while(!fin.eof())
			{
				fin>>line;	
			}
			fout<<line<<"\n";
			
			ofstream fout1("UP.dat",ios::app);
			fout1<<line<<"\n";
			fout1.close();
			fout.close();
			fin.close();
			up_time();
			cout<<"Do you want to continue in the same lane(y/n)\n";
			char x;cin>>x;
		    if(x=='y')
		    goto j;
	    break;}
	case 5:
		{k:   
		system("cls");
			cout<<"***************LANE 5*******************\n";
		    function1();
			string line;
			ofstream fout("lane5.dat",ios::app);
			ifstream fin;
			fin.open("vehicle_data.dat");
			while(!fin.eof())
			{
				fin>>line;	
			}
			fout<<line<<"\n";
			ofstream fout1("DOWN.dat",ios::app);
			fout1<<line<<"\n";
			fout1.close();	
			fout.close();
			fin.close();
			down_time();
				cout<<"Do you want to continue in the same lane(y/n)\n";
			char x;cin>>x;
		    if(x=='y')
		    goto k;
	    break;}
	case 6:
		{m:   
		system("cls");
			cout<<"***************LANE 6*******************\n";
			function1();
			string line;
			ofstream fout("lane6.dat",ios::app);
			ifstream fin;
			fin.open("vehicle_data.dat");
			while(!fin.eof())
			{
				fin>>line;	
			}
			fout<<line<<"\n";
			ofstream fout1("DOWN.dat",ios::app);
			fout1<<line<<"\n";
			fout1.close();
			fout.close();
			fin.close();
			down_time();
				cout<<"Do you want to continue in the same lane(y/n)\n";
			char x;cin>>x;
		    if(x=='y')
		    goto m;
	    break;}
	case 7:
		{	n:
		    system("cls");
			cout<<"***************LANE 7*******************\n";
		    function1();
			string line;
			ofstream fout("lane7.dat",ios::app);
			ifstream fin;
			fin.open("vehicle_data.dat");
			while(!fin.eof())
			{
				fin>>line;	
			}
			fout<<line<<"\n";
			ofstream fout1("DOWN.dat",ios::app);
			fout1<<line<<"\n";
			fout1.close();
			fout.close();
			fin.close();
			down_time();
				cout<<"Do you want to continue in the same lane(y/n)\n";
			char x;cin>>x;
		    if(x=='y')
		    goto n;
	    break;}
	case 8:
		{   o:
		    system("cls");
			cout<<"***************FAST LANE 8*******************\n";
			function1();
			string line;
			ofstream fout("fastlane8.dat",ios::app);
			ifstream fin;
			fin.open("vehicle_data.dat");
			while(!fin.eof())
			{
				fin>>line;	
			}
			fout<<line<<"\n";
			ofstream fout1("DOWN.dat",ios::app);
			fout1<<line<<"\n";
			fout1.close();
			fout.close();
			fin.close();
			down_time();
				cout<<"Do you want to continue in the same lane(y/n)\n";
			char x;cin>>x;
		    if(x=='y')
		    goto o;
	    break;}
	    default:
	    	exit(1);
	    	break;
		
}
}	
void gotoxy( int x, int y )
    {
    COORD p = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
    }
int main()
{
	int ch;
	gotoxy(22,10);
	cout<<"WELCOME TO MEERUT DELHI EXPRESSWAY;)\n";
	system("pause");
	while(2>1)
	{
		gotoxy(22,13);		
	cout<<"Press 1 to Enter Billing section\n";
	gotoxy(22,14);
	cout<<"Press 2 to enter the Database "<<endl;
	gotoxy(22,16);
	cout<<"any key to exit"<<endl;
	cin>>ch;
    switch(ch)
    {    	
    	case 1:
    		system("cls");
    		gotoxy(22,13);
    		fn_for_lane();
    		break;
    	case 2:
    		system("cls");
    		gotoxy(22,13);
            enter_database();
            break;
        default:
        	exit(1);
            
			break;
	}
    system("pause");
	system("cls");
   }
   system("cls");    
return 0;
}

