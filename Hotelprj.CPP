//**************************************************************************************************//
//                                       PROJECT ON HOTEL MANAGEMENT                                //
//												    //
//**************************************************************************************************//




//***************************************************************
//*** Header Files included for the program
//***************************************************************
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <string.h>
#include <fstream.h>
#include <stdlib.h>
#include <ctype.h>
#include <process.h>
#include <iomanip.h>


//***************************************************************
//*** Class Declaration
//***************************************************************

class HOTEL
{
	struct rooms
	{
	int roomcode,roomno;
	char avail;
	} rms;


	struct booking_data
	{
	int roomcode;
	long charge,roomno,hotel;
	  char name[25],address[75],telno[10],date[11],roomtype[15];
	} hbook;

	struct check_in_data
	{
	  int roomcode;
	  long charge,roomno,hotel;
	  char name[25],address[75],telno[10],date[11],roomtype[15];
	} hin;
		
	struct check_out_data
	{
	  int roomcode;
	  long charge,roomno,hotel;
	  char name[25],address[75],telno[10],date[11],odate[11],otime[6];
	} hout;

	struct cancellation_data
	{
	  long roomno;
	  char name[25],address[75],telno[10];
	} hcan;
	
	public:
	void create_roomsdata();	
	void booking();
	void check_in();
	void check_out();
	void cancellation();
 	void restaurant();	
	void taxi_service();
	void view_data();
	void create_bill();
} 	H;


//***************************************************************
//*** Variable Declarations
//***************************************************************

int trap=0,length, height,k=0,dd,mm,yyyy,max_days;
char c[80],*p,h_char,v_char;
fstream f,f1,f2,f3,f4;
ofstream fout;

struct logindata
{
char username[10];
char password[10];
};
logindata l[6]=
{
 {"abbhinav","venkat"},{"student2","student2"},{"student3","student3"},{"Teacher","Teacher"},{"Admin","12345"}
} ;




//***************************************************************
//*** Function Prototypes
//***************************************************************

void welcome();   //*** Function to display welcome screen at the start of program
void thankyou();  //*** Function to display Thank You screen at the exit of program
void title();     //*** Function to display Hotel Name as Screen heading  
void displayBox( int w, int h, char hc, char vc); //*** Function to draw box when coordinates are provided 
						  //*** (width, height, Vertical Character, Horizontal Character)
void login();    //*** Function to login with defined user-id and password

void date_error( int x, int y);  //*** Function to display error message



//*****************************************************///
//*** Details of various Functions in the Program
//*****************************************************///



//***************************************************************
//*** Function to display welcome screen at the start of program
//***************************************************************
void welcome()
{
  char cText[300];
  int x,y,z,a,d=30000;
 
  clrscr();
  for(x=1; x<36; x++)
	{
         gotoxy(x,10); cout << "WELCOME";
	 for(a=1;a<d;a++)
	 gotoxy(x,10); cout << "       ";
        }
  gotoxy(36,10); cout << "WELCOME";	

  for(y=20; y>12;y--)
	{
         gotoxy(38,y); cout << "TO";
	 for(a=1;a<d;a++)
         gotoxy(38,y); cout << "  ";
        }
  gotoxy(38,12); cout << "TO";	

  for(z=65; z>32;z--)
	{
         gotoxy(z,14); cout << "HOTEL CONTINENTAL";
	 for(a=1;a<d;a++)
         gotoxy(z,14); cout << "                 ";

	}
  gotoxy(32,14); cout << "HOTEL CONTINENTAL";

  //*** To Display the box 
  length = 79; height = 12; h_char = '*';v_char = '#';
  gotoxy(1,6); displayBox(length,height,h_char,v_char);
  length = 77; height = 12; h_char = '*';v_char = '#';
  gotoxy(1,7); displayBox(length,height,h_char,v_char);

  for(a=-90000;a<d;a++)
  gotoxy(36,10); cout << "WELCOME";	
  for(a=-90000;a<d;a++)
  gotoxy(38,12); cout << "TO";	
  for(a=-90000;a<d;a++)
  gotoxy(32,14); cout << "HOTEL CONTINENTAL"; 
 
  gotoxy(25,24); cout << " Press Enter to Continue"; 
  getch();
  return;
}


//****************************************************************
//*** Function to display Thank You screen at the exit of program
//****************************************************************

void thankyou()
{
  char cText[300];
  int x,y,z,a,d=30000;

  clrscr();
  for(x=1; x<30; x++)
	{
         gotoxy(x,10); cout << "THANK YOU FOR USING";
	 for(a=1;a<d;a++)
	 gotoxy(x,10); cout << "                   ";
        }
  gotoxy(30,10); cout << "THANK YOU FOR USING";	

  for(y=25; y>12;y--)
	{
         gotoxy(32,y); cout << "HOTEL MANAGEMENT";
	 for(a=1;a<d;a++)
         gotoxy(32,y); cout << "                ";
        }
  gotoxy(32,12); cout << "HOTEL MANAGEMENT";	

  for(z=65; z>34;z--)
	{
         gotoxy(z,14); cout << "SOFTWARE ";
	 for(a=1;a<d;a++)
         gotoxy(z,14); cout << "          ";
        }

  //*** To Display the box 
  length = 79; height = 12; h_char = '*';v_char = '#';
  gotoxy(1,6); displayBox(length,height,h_char,v_char);
  length = 77; height = 12; h_char = '*';v_char = '#';
  gotoxy(1,7); displayBox(length,height,h_char,v_char);

  for(a=-90000;a<d;a++)
  gotoxy(30,10); cout << "THANK YOU FOR USING";	
  for(a=-90000;a<d;a++)
  gotoxy(32,12); cout << "HOTEL MANAGEMENT";	
  for(a=-90000;a<d;a++)
  gotoxy(34,14); cout << "SOFTWARE";
  gotoxy(30,24); cout << " Press Enter to Exit"; 
  getch();
  return;
}


//**********************************************************
//*** Function to display Hotel Name as Screen heading  
//**********************************************************

void title()
{

  length = 79; height = 5; h_char = '-'; v_char = '|';
  clrscr();
  gotoxy(1,1); displayBox(length,height,h_char,v_char);
  gotoxy(15,3); cout << "       H O T E L  C O N T I N E N T A L       ";
  gotoxy(15,4); cout << "      K I N G D O M   O F   B A H R A I N     ";
}


//*****************************************************************************************************************
//*** Function to draw box when coordinates are provided (width, height, Vertical Character, Horizontal Character) 
//*****************************************************************************************************************

void displayBox( int w, int h ,char hc, char vc)
{
 cout << endl;
	for (int i=1; i<= h; i++)
	{
		for (int j=1; j <= w; j++)
		{
		if (i == 1) 
		  cout << hc;
		else if (j == 1) 
		  cout << vc;
		else  if (j == w)
		  cout << vc;
		else if (i == h) 
		  cout << hc;
		else
		  cout << " ";
		}
		cout << endl;
		}
}



//**********************************************************
//*** Function to login with defined user-id and password
//**********************************************************


void login()
{
  int errcount=0, i=0;
  char *temp5=l[5].username, *temp6=l[5].password,uname[20];

  START:

  
//***Two variables to accept username and password
  title();
  height = 20;
  gotoxy(17,5);  displayBox(length,height,h_char,v_char);
  gotoxy(25,7);  cout<<"LOGIN INFORMATION\n\n";
  gotoxy(20,9);  cout<<"User-ID   : ";
  gotoxy(20,11); cout<<"PASSWORD  : ";
  gotoxy(10,13); cout<<"Please note 3 wrong login attempts will exit program";
  gotoxy(33,9); cin>>l[5].username;
  gotoxy(32,11);	

  k=0;
  while(1)
   {
     l[5].password[k]=getch();
     cout << "*";
     if(l[5].password[k] == '\r') 
	{
	  l[5].password[k]= '\0';
	   break;
	}
     k++;
   } 


  // We have predefined 5 sets of usernames and passwords for our progam initially
  // These are stored in file LOGINID.DAT as indicated below
  //  l[0].username='abbhinav';
  //  l[0].password='venkat';
  //  l[1].username='student2';
  //  l[1].password='student2';
  //  l[2].username='student3';
  //  l[2].password='student3';
  //  l[3].username='Teacher';
  //  l[3].password='Teacher';
  //  l[4].username='Admin';
  //  l[4].password='12345';


  //*** The LOGINID.DAT file is opened and username & Password are inserted into file

  fout.open("LOGINID.DAT", ios::out | ios::binary);
  for(i=0;i<5;i++)
    { fout.write((char*) &l[i],sizeof(l[i])); }
  fout.close();

  // *** Authentication of the system begins
  // Declare another stucture variable for the above process and let it be temp


  logindata temp1;
  ifstream fin;

  fin.open("LOGINID.dat", ios::in | ios::binary);

  while((!fin.eof()) && trap==0)
  {
  //This is supposed to be done till the end of file is reached and trap is zero
   fin.read((char*) &temp1, sizeof(l[i]));
   int z= strcmp(temp1.username,temp5);
   if(z==0)     //This means that they are equal i.e. strings match for username
     {
       int z2=strcmp(temp1.password,temp6); // Compare Passwords 
       if(z2==0)
        { trap=1;}
     }

  }
  fin.close();
  if (trap==0)
  {
   gotoxy(15,16); cout<<"User-id/ Password Incorrect !!!";
   errcount++;
   getch();
   if (errcount <3)  // Allows 3 wrong tries, otherwise program will exit
	goto START;
   else
        exit(0);
   }
   return;
}







//**********************************************************
// Function to perform initial Booking of Hotel Guests
//**********************************************************



void HOTEL::booking()
{


  title();
  height = 20;
  gotoxy(17,5); displayBox(length,height,h_char,v_char);
  gotoxy(30,4); cout<<" B O O K I N G ";

  int flag =0;
  char *check_date;

  //*** Opening BOOKING.DAT file and accepting data of Guest 
	f1.open("BOOKING.DAT",ios::app|ios::binary);
	if (f1.fail() !=0) {gotoxy(5,23); cout << "BOOKING File Open Error!";getch();return;}

	//*** Accept Guest name. Check if field is blank. 
	do 
	{ gotoxy(44,9); cout << "Press Zero to return";
	  gotoxy(4,9); cout<<"NAME    : "; 
	  gets(hbook.name);

	  if (hbook.name[0]== '0') 
	{ f1.close(); 
	return;}

	  if (strlen(hbook.name) != 0) 
	 break;
	  gotoxy(5,23); cout << "Field Cannot be Blank!!!";
	}while(1);

	int l=strlen(hbook.name);

	for(int i=0;i<l;i++) 
	hbook.name[i]=toupper(hbook.name[i]);

	gotoxy(44,9); cout << "                     ";	
	gotoxy(5,23); cout << "                          ";	

	//*** Accept Guest Address. Check if field is blank.  
	do
	{ gotoxy(4,10); cout<<"ADDRESS(R) : ";
	  gets(hbook.address);
	  if (strlen(hbook.address) != 0)  break;
	  gotoxy(5,23); cout << "Field Cannot be Blank!!!";
	} while (1);
	gotoxy(5,23); cout << "                          ";	

	//*** Accept Guest Telephone. Check if field is blank. 
	do
	{ gotoxy(4,11); cout<<"TEL. NO.(R) : ";
	  gets(hbook.telno);
          if (strlen(hbook.telno) != 0) break;
	  gotoxy(5,23); cout << "Field Cannot be Blank!!!";
	} while (1);
	gotoxy(5,23); cout << "                          ";	
	
	//*** Accept Check-in Date and validate date
	while (1) {
        	gotoxy(4,12); cout<<"CHECK-IN DATE(dd/mm/yyyy) : ";
		gotoxy(34,12); gets (hbook.date);
		dd=(hbook.date[0]-48)*10+(hbook.date[1]-48);
		mm=(hbook.date[3]-48)*10+(hbook.date[4]-48);
		yyyy=(hbook.date[6]-48)*1000+(hbook.date[7]-48)*100+(hbook.date[8]-48)*10+(hbook.date[9]-48);
		
		if (dd < 1 || dd > 31) { date_error(34,12); continue;}
		if (mm < 1 || mm > 12) { date_error(34,12); continue;}
		if (yyyy < 2012 || yyyy > 2050) { date_error(34,12); continue;}
		if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) max_days = 31; 
		else 
		if (mm == 4 || mm == 6 || mm == 9|| mm == 11 ) max_days = 30;
		else max_days = 28;

   	        if((yyyy%400 ==0 || (yyyy%100 != 0 && yyyy%4 == 0) ) && mm==2)
        		{
			 max_days = 29;
		        }
		if (dd > max_days) { date_error(34,12); continue;}
		break;
		}

	//*** Accept Room Type and validate correct code is chosen
	gotoxy(41,14); cout <<"ROOM TYPES  CODES  CHARGE PER DAY";
	gotoxy(41,15); cout <<"1. Royal Suite  -- BD 200";
	gotoxy(41,16); cout <<"2. Super Deluxe -- BD 150";
	gotoxy(41,17); cout <<"3. Deluxe       -- BD 100";
	gotoxy(41,18); cout <<"4. Double Bed   -- BD  50";
	gotoxy(41,19); cout <<"5. Single Bed   -- BD  25";
	int roomcode;

	do {
	   gotoxy(4,14); cout<<"ROOM CODE : ";
	   cin>>roomcode;
	   if (cin.fail()) 
	     { gotoxy(4,15);
	       cout<<"INVALID ROOM CODE    ";
	       cin.sync();
	       cin.clear(); 
	       continue;
	     }
	   
	   hbook.roomcode = roomcode;
	   switch(roomcode)
	     {
	       case 1 : strcpy(hbook.roomtype,"ROYAL SUITE");
		        hbook.charge=200;
		        break;
	       case 2 : strcpy(hbook.roomtype,"SUPER DELUXE");
		        hbook.charge=150;
		        break;
	       case 3 : strcpy(hbook.roomtype,"DELUXE");
		        hbook.charge=100;
		        break;
	       case 4 : strcpy(hbook.roomtype,"DOUBLE BED");
		        hbook.charge=50;
		        break;
	       case 5 : strcpy(hbook.roomtype,"SINGLE BED");
		        hbook.charge=25;
		        break;
	       default: gotoxy(4,15);cout<<"ENTER THE RIGHT CODE";
		        continue;
	      }  	   break;
	}while(1);

	
   //*** Check Availability of Rooms from ROOMS.DAT file.
  long pos;
  hbook.hotel=0;	
  f.open("ROOMS.DAT",ios::in|ios::binary);
  if (f.fail() !=0) {gotoxy(5,23); cout << "Rooms File Open Error!";getch();return;}
  while (!f.eof())
  {
     f.read((char *)&rms,sizeof(rms));
     if ( (roomcode == rms.roomcode) && (rms.avail == 'A') )
        {	
	 hbook.roomno= rms.roomno;
	 pos = f.tellg(); flag = 1;
	 break; }
     else flag = 0;
       }
     f.close();

     //*** Update the status of room in file ROOMS.DAT as Occupied when flag value is 1. Else Display Room not available
     if (flag == 1)
     {
	  f.open("ROOMS.DAT",ios::in|ios::out| ios::binary);
          if (f.fail() !=0) {gotoxy(5,23); cout << "Rooms File Open Error!";getch();return;}
	  while (!f.eof())
          {
            f.read((char *)&rms,sizeof(rms));
            f.seekg(pos-5);
            rms.roomcode = roomcode;
            rms.roomno = hbook.roomno;
            rms.avail = 'O';
            f.write((char *)&rms,sizeof(rms)); break; 
          }
         f.close();

         //*** COPYING THE RECORD OF THE CUSTOMER INTO A FILE
         f1.write((char *)&hbook,sizeof(hbook));
         f1.close(); 
         gotoxy(4,15); 	cout<<"YOUR ROOM NO. IS : "; cout <<hbook.roomno;
         gotoxy(4,17);	cout<<"PRESS ANY KEY TO CONTINUE";
         getch();
     }
     else 
    {
     gotoxy(5,23); cout<<"ROOM FOR THE TYPE SPECIFIED NOT AVAILABLE. PRESS ANY KEY TO CONTINUE";
     getch();
     f1.close();
    }
  return;
}



//*****************************************************************
// Function to check in Guests provided they have booked in earlier
//*****************************************************************

void HOTEL::check_in()
{
        //*** To Display Header in Screen
	title();
	height = 20;
	gotoxy(17,5); displayBox(length,height,h_char,v_char);
	gotoxy(30,4); cout<<" C H E C K  I N ";

	int rn,flag=0;
	long pos;
	char ans,chk, rc[4];

	//*** Enquire whether booking is done in advance
	do
	{ gotoxy(5,7); cout<<"HAVE YOU BOOKED IN ADVANCE (Y/N): ";
	 gotoxy(41,7); cin>>ans;
	 if(ans=='n'||ans=='N')
	 {
	   gotoxy(5,22); cout<<"PLEASE MAKE BOOKING FIRST, PRESS ANY KEY TO EXIT";
	   getch();
	   return;
	 }
	 else
	 if(ans=='y'||ans=='Y')
	    break;
         else
	   { gotoxy(5,22); cout << "Please enter Y or N only !"; getch(); continue;}
	} while(1);


	//*** Accept Room No.from User
	do 
	{ 
	  gotoxy(5,8); cout<<"ROOM NUMBER  : ";
	  gotoxy(25,8); gets (rc);
	  rn=(rc[0]-48)*100+(rc[1]-48)*10+rc[2]-48;
	  if (rn != 0) break;
	} while(1);


	//*** Open file BOOKING.DAT in input mode for reading
	f1.open("BOOKING.DAT",ios::in|ios::binary);

	//*** Check whether the room number provided has data available in BOOKING.DAT
	//*** If data is available move flag value as 1 and then 
	//*** display other details like name, address, telephone no., room type and check-in date

	if (f1.fail() !=0) {gotoxy(5,23); cout << "Booking File Open Error!";getch();return;}
	flag =0;
	while(!f1.eof())
	 {
	  f1.read((char *)&hbook,sizeof(hbook));
	  if(hbook.roomno==rn)
	       	{
		gotoxy(5,10); cout<<"NAME          : "<<hbook.name;
		gotoxy(5,11); cout<<"ADDRESS(R)    : "<<hbook.address;
		gotoxy(5,12); cout<<"TEL. NO.(R)   : "<<hbook.telno;	
		gotoxy(5,13); cout<<"CHECK-IN DATE : "<<hbook.date;
		gotoxy(5,14); cout<<"ROOM TYPE     : "<<hbook.roomtype;
		flag =1;
		break;
		}
		flag = 0;	
	  }

	//*** If data is not available (ie flag value 0) display error and return to menu
	if (flag == 0)
	{ gotoxy(5,23); cout<<"BOOKING NOT AVAILABLE FOR ABOVE ROOM NO., PRESS ANY KEY TO EXIT";
	getch();
	f1.close();
	return;}
	
	//*** If data is available in file BOOKING.DAT, take input from user whether to check in the Guest
	gotoxy(5,16); cout<<"Check-In the above Guest (Y/N) ";
	gotoxy(47,16); cin >> chk;
	if (chk == 'N' || chk == 'n') 
		{ f1.close(); return;}
	
	//*** Open file CHECKIN.DAT in Append mode so that data could be added 
	f2.open("CHECKIN.DAT",ios::app|ios::binary);
        if (f2.fail() !=0) {gotoxy(5,23); cout << "Checkin File Open Error!";getch();return;}

	//*** Data from BOOKING.DAT is moved to CHECKIN.DAT 
	hin.roomno=hbook.roomno;
	hin.roomcode=hbook.roomcode;
	hin.charge = hbook.charge;
	hin.hotel = hbook.hotel;
	strcpy(hin.name, hbook.name);
	strcpy(hin.address, hbook.address);
	strcpy(hin.telno, hbook.telno);
	strcpy(hin.date,hbook.date);
	strcpy(hin.roomtype,hbook.roomtype);

	//*** Write data to CHECKIN.DAT and then close both BOOKING.DAT and CHECKIN.DAT
	f2.write((char *)&hin,sizeof(hin));
	f1.close();	
	f2.close();

	//*** Deleting the Record from BOOKING.DAT 
	//*** BOOKING.DAT file is opened in Input mode and temporary file TEMP.DAT is opened in output mode
	//*** BOOKING.DAT is read sequentially and written to TEMP.DAT except when the Room No is equal to the one checked-in 
	remove("TEMP.DAT");
	f1.open("BOOKING.DAT",ios::in|ios::binary);
        if (f1.fail() !=0) {gotoxy(5,23); cout << "Booking File Open Error!";getch();return;}
	f.open("TEMP.DAT",ios::out|ios::binary);
	if (f.fail() !=0) {gotoxy(5,23); cout << "Temporary File Open Error!";getch();return;}
	f1.read((char *)&hbook,sizeof(hbook));
	while(!f1.eof())
	{
	  if(hbook.roomno!=rn)
	  {
	    f.write((char *)&hbook,sizeof(hbook));
	    f1.read((char *)&hbook,sizeof(hbook));
	  }
	  else f1.read((char *)&hbook,sizeof(hbook));
	}
	f.close();
	f1.close();
	
	//*** All data from TEMP.DAT is read and data written to BOOKING.DAT 
	//*** For this BOOKING.DAT is opened in output mode and TEMP.DAT is opened in inout mode

	f1.open("BOOKING.DAT",ios::out|ios::binary);
	if (f1.fail() !=0) {gotoxy(5,23); cout << "Booking File Open Error!";getch();return;}
	f.open("TEMP.DAT",ios::in|ios::binary);
	if (f.fail() !=0) {gotoxy(5,23); cout << "Temporary File Open Error!";getch();return;}
	f.read((char *)&hbook,sizeof(hbook));
	while(!f.eof())
	{
	  f1.write((char *)&hbook,sizeof(hbook));
	  f.read((char *)&hbook,sizeof(hbook));
	}

	//*** Files are closed, data cleared and message for update displayed.
	f.close();
	f1.close();
	hbook.roomno=0;	strcpy(hbook.name,"              ");
        gotoxy(5,23); cout<<"GUEST CHECKED-IN, PRESS ANY KEY TO EXIT";
	getch();
	clrscr();
	return;
}


//*****************************************************************
// Function to check out Guests who have already checked-in 
//*****************************************************************

void HOTEL::check_out()
{
	//*** To Display header on Screen
        title();
	height = 20;
	gotoxy(17,5); displayBox(length,height,h_char,v_char);
	gotoxy(30,4); cout<<" C H E C K  O U T ";
	
	//*** Variables used in the function
	int rn,roomcode, flag =0, dd1,dd2,mm1,mm2,yy1,yy2,p,q,r;
	long pos;	
	char chk, rc[4], od[11],ot[6];
	double serv_fee=0, tariff;


	//*** Accept input of Room No. to be Checked out
	do {
	gotoxy(5,7); cout<<"ROOM NUMBER : ";
	gotoxy (25,7); gets(rc);
	rn=(rc[0]-48)*100+(rc[1]-48)*10+rc[2]-48;
	if (rn != 0) break;
	}while (1);


	//*** Open the file CHECKIN.DAT in inout mode
	f1.open("CHECKIN.DAT",ios::in|ios::binary);
	if (f1.fail() !=0) {gotoxy(5,23); cout << "Checkin File Open Error!";getch();return;}
	
	//*** Read the file CHECKIN.DAT and check whether the Room No input exists in the file
	//*** If Room No. input is available, data is displayed on screen and flag value is set to 1

	while(!f1.eof())
	 {
	  f1.read((char *)&hin,sizeof(hin));
	  if(hin.roomno==rn)
	       	{
		gotoxy(5,9); cout<<"NAME              : "<<hin.name;
		gotoxy(5,10); cout<<"ADDRESS(R)        : "<<hin.address;
		gotoxy(5,11); cout<<"TEL. NO.(R)       : "<<hin.telno;
		gotoxy(5,12); cout<<"ROOM TYPE         : "<<hin.roomtype;
		gotoxy(5,13); cout<<"CHECK-IN DATE     : "<<hin.date;
		flag = 1;
		break;
		}
		flag = 0;
	  }
	
	//*** If flag value is 0, then the record is not available in CHECKIN.DAT file. display error and retunr to screen
	if (flag ==0)
	{
		gotoxy(5,23); cout << "Room No not available for Check out. Press Enter to Exit"; getch(); f1.close(); return;
	}

	//*** Accept input whether the Guest is to be Checked Out. 
	//*** ALso display message that the record would be deleted from file CHECKIN.DAT, 
	//*** So bill should be created using function create_bill()

	gotoxy(5,15); cout <<"Data would be deleted after Check Out. Please Create Bill first";
	gotoxy(5,16); cout<<"Check-Out the above Guest (Y/N) : ";
	gotoxy(40,16); cin >> chk;
	if (chk == 'N' || chk == 'n') 
		{ f1.close(); return;}
	gotoxy(5,15); cout <<"                                                               ";	

        //*** Accept Check out Date and valid the field
	DATE_CHECKOUT:
	while (1) {
		gotoxy(5,18); cout<<"CHECK-OUT DATE (dd/mm/yyyy) : ";
		gets(od);
		dd=(od[0]-48)*10+(od[1]-48);
		mm=(od[3]-48)*10+(od[4]-48);
		yyyy=(od[6]-48)*1000+(od[7]-48)*100+(od[8]-48)*10+(od[9]-48);
		
		if (dd < 1 || dd > 31) { date_error(35,8); continue;}
		if (mm < 1 || mm > 12) { date_error(35,8); continue;}
		if (yyyy < 2012 || yyyy > 2050) { date_error(35,8); continue;}
		if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) max_days = 31; 
		else 
		if (mm == 4 || mm == 6 || mm == 9|| mm == 11 ) max_days = 30;
		else max_days = 28;

   	        if((yyyy%400 ==0 || (yyyy%100 != 0 && yyyy%4 == 0) ) && mm==2)
        		{
			 max_days = 29;
		        }
		if (dd > max_days) { date_error(35,8); continue;}
		break;
		}
		

	//*** Open file CHECKOUT.DAT in append mode so that data could be added
	f2.open("CHECKOUT.DAT",ios::app|ios::binary);
	if (f1.fail() !=0) {gotoxy(5,23); cout << "Checkout File Open Error!";getch();return;}

	//COPYING THE RECORD from CHECKIN.DAT to CHECKOUT.DAT and writing the data into CHECKOUT.DAT
	roomcode = hin.roomcode;
	strcpy(hout.name,hin.name);
	strcpy(hout.address,hin.address);
	strcpy(hout.telno,hin.telno);
	strcpy(hout.date,hin.date);
	strcpy(hout.odate,od);
	hout.roomno=hin.roomno;
	hout.hotel=hin.hotel;
	f2.write((char *)&hout,sizeof(hout));
	f2.close();

	//Calculating number of days the GUEST stayed in the Hotel

	dd1=(hin.date[0]-48)*10+(hin.date[1]-48);
	dd2=(od[0]-48)*10+(od[1]-48);
	mm1=(hin.date[3]-48)*10+(hin.date[4]-48);
	mm2=(od[3]-48)*10+(od[4]-48);
	yy1=(hin.date[6]-48)*1000+(hin.date[7]-48)*100+(hin.date[8]-48)*10+(hin.date[9]-48);
	yy2=(od[6]-48)*1000+(od[7]-48)*100+(od[8]-48)*10+(od[9]-48);
	if(yy1%4==0) { p=29; q=28; }
	else if(yy2%4==0) { p=28; q=29; }
	else { p=28; q=28; }
	
	//*** Checking whether the Check out date is greater than check in date	
	if ( (yy1*10000+mm1*100+dd1) > (yy2*10000+mm2*100+dd2) )
 	 { gotoxy(5,21);  cout << "Check-Out Date less than Check-In Date!" ; getch();
	   gotoxy(5,21); cout << "                                       " ; 
	   goto DATE_CHECKOUT;}	

	//*** Calculate Tariff Charge based on room type and days occupied
	int cy[12]={ 31,p,31,30,31,30,31,31,30,31,30,31 };
	int ny[12]={ 31,q,31,30,31,30,31,31,30,31,30,31 };

	if(yy1==yy2 && mm1==mm2 && dd1==dd2) 
		tariff=hin.charge;
	else
	{
	  if(yy1==yy2)
	  {
	    if(mm1==mm2) tariff=hin.charge*(dd2-dd1);
	    else
	    {
	      r=cy[mm1-1]-dd1+dd2;
	      for(int l=mm1;l<mm2-1;l++) r+=cy[l];
	      tariff=hin.charge*r;
	    }
	  }
	  else
	  {
	    r=cy[mm1-1]-dd1+dd2;
	    for(int l=mm1;l<12;l++) r+=cy[l];
	    for(l=0;l<mm2-1;l++) r+=ny[l];
	    tariff=hin.charge*r;
	  }
	}
	
	//*** Display Final Bill on Screen
	//*** A Service Tax of 12% of the Hotel Tariff is charged
	//*** The bill includes Restaurant charges (if any)
	// setw() command is used to set the width of the field for screen display 

	gotoxy(47,7); cout<<"**** FINAL BILL ****";	
	gotoxy(47,9); cout<<"TARIFF            : BD "<< setw(6) << tariff;
	serv_fee = tariff * 0.12;
	gotoxy(47,10); cout<<"RESTAURANT CHARGE : BD "<< setw(6) << hin.hotel;
	gotoxy(47,11); cout<<"SERVICE TAX (12%) : BD "<< setw(6) << serv_fee;
	gotoxy(47,12); cout<< "-------------------------------";
	gotoxy(47,13); cout<<"TOTAL             : BD "<< setw(6) << (tariff+serv_fee+hin.hotel);
	gotoxy(47,14); cout<< "-------------------------------";
	f1.close();
	
	//*** Open CHECKIN.DAT in Input mode and open temporary file TEMP.DAT in output mode
	//*** The CHECKIN.DAT file is read till the Room no. is equal to one being checked out
	//*** All records except this Room No. is copied to temporary file TEMP.DAT

	f1.open("CHECKIN.DAT",ios::in|ios::binary);
	if (f1.fail() !=0) {gotoxy(5,23); cout << "Checkin File Open Error!";getch();return;}
	f.open("TEMP.DAT",ios::out|ios::binary);
	if (f.fail() !=0) {gotoxy(5,23); cout << "Temporary File Open Error!";getch();return;}
	f1.read((char *)&hin,sizeof(hin));
	while(f1)
	{
	  if(hin.roomno!=rn)
	  {
	    f.write((char *)&hin,sizeof(hin));
	    f1.read((char *)&hin,sizeof(hin));
	    
	  }
	  else f1.read((char *)&hin,sizeof(hin));
	}
	f.close();
	f1.close();
	f1.open("CHECKIN.DAT",ios::out|ios::binary);
	if (f1.fail() !=0) {gotoxy(5,23); cout << "Checkin File Open Error!";getch();return;}
	f.open("TEMP.DAT",ios::in|ios::binary);
	if (f.fail() !=0) {gotoxy(5,23); cout << "Temporary File Open Error!";getch();return;}
	f.read((char *)&hin,sizeof(hin));
	while(f)
	{
	  f1.write((char *)&hin,sizeof(hin));
	  f.read((char *)&hin,sizeof(hin));
	}
	f.close();	
	f1.close();

	//*** Updating the above Room NO in the file ROOMS.DAT as Available
	f.open("ROOMS.DAT",ios::in|ios::binary);
	if (f.fail() !=0) {gotoxy(5,23); cout << "Rooms File Open Error!";getch();return;}
	while (!f.eof())
	{
	f.read((char *)&rms,sizeof(rms));

        if (rms.roomno == rn) 
         {	
	   pos = f.tellg();
	   break; }
     }
     f.close();
  
     f.open("ROOMS.DAT",ios::in|ios::out| ios::binary);
     if (f.fail() !=0) {gotoxy(5,23); cout << "Rooms File Open Error!";getch();return;}
     while (!f.eof())
      {
        f.read((char *)&rms,sizeof(rms));
        f.seekg(pos-5);
        rms.roomcode = roomcode;
        rms.roomno = rn;
        rms.avail = 'A';
        f.write((char *)&rms,sizeof(rms)); break; 
       }
     f.close();
	
	//*** Message display to note bill details and return to Menu
	gotoxy(47,18); cout<<"PLEASE NOTE THE BILL DETAILS";
	gotoxy(47,19); cout<<"PRESS ANY KEY TO EXIT";
	getch();
	clrscr();
}



//***********************************************************************
// Function for Cancellation of Guest who have booked but not checked in 
//***********************************************************************

void HOTEL::cancellation()
{
       
	//*** To display screen header 
	title();
	height = 20;
	gotoxy(17,5); displayBox(length,height,h_char,v_char);
	gotoxy(25,4); cout<<" C A N C E L L A T I O N";

	//*** Variables used in the function
	char can,rc[4];
	int flag =0,rn,roomcode;
	long pos;

	//***  Accept Room no. and check if it is available in file BOOKING.DAT
	while (1)
	{
	  do 
	  { 
	    gotoxy(5,7); cout<<"ROOM NUMBER  : ";
	    gotoxy(25,7); gets (rc);
	    rn=(rc[0]-48)*100+(rc[1]-48)*10+rc[2]-48;
	    if (rn != 0) break;
	  } while(1);
	
	  f2.open("BOOKING.DAT",ios::in|ios::binary);
	  if (f2.fail() !=0) {gotoxy(5,23); cout << "Booking File Open Error!";getch();return;}

	  flag =0;
	  while(f2)
	    {
	      f2.read((char *)&hbook,sizeof(hbook));

	      //*** If Room No. is available, display other information of Guest on the Screen
	      if(hbook.roomno==rn)
		{
		   gotoxy(5,9); cout<<"NAME         : "<<hbook.name;
		   gotoxy(5,10); cout<<"ADDRESS(R)   : "<<hbook.address;
		   gotoxy(5,11); cout<<"TEL. NO.(R)  : "<<hbook.telno;
		   gotoxy(5,12); cout<<"ROOM TYPE    : "<<hbook.roomtype; 
		   flag = 1;
		   break;
		}
		flag = 0;
  	   }
				
	  if (flag ==0)
	  { 
             gotoxy(5,21); cout<<"ABOVE ROOM NO IS NOT BOOKED. PRESS ANY KEY TO CONTINUE";
	     getch();
	     f2.close();
	     return;
          }

	
	roomcode = hbook.roomcode;
	gotoxy(5,14); cout<<"Cancel the above Record (Y/N) ";
	gotoxy(47,14); cin >> can;
	if (can == 'N' || can == 'n') 
		{ f2.close(); return;}
	else {f2.close(); break;}
	}

	//***  If User confirm Cancellation by choosing option "Y" or "N"
	//***  COPY THE RECORD OF THE GUEST INTO CANCEL.DAT FILE
	f3.open("CANCEL.DAT",ios::app|ios::binary);
        if (f3.fail() !=0) {gotoxy(5,23); cout << "Cancel File Open Error!";getch();return;}
	strcpy(hcan.name,hbook.name);
	strcpy(hcan.address,hbook.address);
	strcpy(hcan.telno,hbook.telno);
	f3.write((char *)&hcan,sizeof(hcan));
	f3.close();
	f1.close();
	
	//*** Open BOOKING.DAT in Input mode and open temporary file TEMP.DAT in output mode
	//*** The BOOKING.DAT file is read till the Room no. is equal to one being cancelled
	//*** All records except this Room No. is copied to temporary file TEMP.DAT

	f1.open("BOOKING.DAT",ios::in|ios::binary);
	if (f1.fail() !=0) {gotoxy(5,23); cout << "Booking File Open Error!";getch();return;}
	f.open("TEMP.DAT",ios::out|ios::binary);
	if (f.fail() !=0) {gotoxy(5,23); cout << "Temporary File Open Error!";getch();return;}
	f1.read((char *)&hbook,sizeof(hbook));
	while(f1)
	{
	  if(hbook.roomno!=rn)
	  {
	    f.write((char *)&hbook,sizeof(hbook));
	    f1.read((char *)&hbook,sizeof(hbook));
	  }
	  else f1.read((char *)&hbook,sizeof(hbook));
	}
	f.close();
	f1.close();


	//*** Open BOOKING.DAT in output mode and open temporary file TEMP.DAT in inout mode
	//*** Copy all records from TEMP.DAT to BOOKING.DAT
	f1.open("BOOKING.DAT",ios::out|ios::binary);
	if (f1.fail() !=0) {gotoxy(5,23); cout << "Booking File Open Error!";getch();return;}
	f.open("TEMP.DAT",ios::in|ios::binary);
	if (f.fail() !=0) {gotoxy(5,23); cout << "Temporary File Open Error!";getch();return;}
	f.read((char *)&hbook,sizeof(hbook));
	while(f)
	{
	  f1.write((char *)&hbook,sizeof(hbook));
	  f.read((char *)&hbook,sizeof(hbook));
	}
	f.close();
	f1.close();



	//***  MAKING THE ROOM OCCUPIED BY THE GUEST AS UNOCCUPIED in ROOMS.DAT file
	//***  Open ROOMS.DAT in input mode and find location of the record to be updated and store in variable pos
	f.open("ROOMS.DAT",ios::in|ios::binary);
	if (f.fail() !=0) {gotoxy(5,23); cout << "Rooms File Open Error!";getch();return;}
	while (!f.eof())
	{
	  f.read((char *)&rms,sizeof(rms));
	  if (rms.roomno == rn) 
	  {	
	      pos = f.tellg();
	      break; 
	   }
	}
	f.close();


	//***  Open ROOMS.DAT in input and output mode
	//***  Based on variable pos find location of the record to be updated and change status as "A"- Avaialable

	f.open("ROOMS.DAT",ios::in|ios::out| ios::binary);
	if (f.fail() !=0) {gotoxy(5,23); cout << "Rooms File Open Error!";getch();return;}
	while (!f.eof())
	{
	  f.read((char *)&rms,sizeof(rms));
	  f.seekg(pos-5);
	  rms.roomcode = roomcode;
	  rms.roomno = rn;
	  rms.avail = 'A';
	  f.write((char *)&rms,sizeof(rms)); break; 
	}
	f.close();


	gotoxy(5,17); cout<<"RECORD CANCELLED, PRESS ANY KEY TO CONTINUE";
	getch();
	clrscr();
}



//**************************************************************************************
// Function to Use restaurant service and update tariff to CHECKIN.DAT file or pay cash
//**************************************************************************************

void HOTEL::restaurant()
{
        //***   Display Header Information
	title();
	height = 20;
	gotoxy(17,5);
	displayBox(length,height,h_char,v_char);
	
	//***  Define varaibles required for the function

	int fc,y=0,z=-1,count=0;
	double fe=0,fch[61];
	char fi[62][30],answe,nm[25],add[75],tel[10],dt[11],roomtyp[15],answ,ans;
	long pos;
	
	//***  Store the price of the menu items of the Restaurant

	int price[61]={2,3,2,2,3,3,4,3,2,3,
	2,3,3,2,2,2,3,2,2,
	2,2,2,2,
	4,5,4,3,
	2,2,2,1,2,2,2,2,1,1,1,1,2,
	2,1,
	1,1,1,
	2,2,2,2,3,3,2,2,2,2,3,2,2,2,3,3};

	//***  Store the menu items of the Restaurant in an array

	char food[61][30]={"SHAHI PANEER","KADAI PANEER","CHEESE KORMA",
	"MALAI KOFTA","MATAR PANEER","PALAK PANEER","MIX VEG.","ALOO GOBI",
	"ALOO JEERA","CHANA MASALA","MATAR MUSHROOM","RAJMA MAKHANI",
	"DAL MAKHANI","DUM ALOO","MUSHROOM PANEER",

	"MIXED RAITA","BUNDI RAITA","PINEAPPLE RAITA","SALAD(GREEN)",

	"PANEER PULAO","VEG.PULAO","JEERA RICE","STEAMED RICE",

	"RUMALI ROTI","ROTI","NAN","ALOO NAN","PANEER NAN","PARANTHA",
	"ALOO PARANTHA","PANEER PARANTHA","PUDINA PARANTHA","BUTTER NAN",
	"LACHCHA PARANTHA","MISSI ROTI","KHASTA ROTI",
	
	"VEG.BURGER","PANEER BURGER","CHEESE SANDWICH","VEG.PATTI",

	"TEA","COFFEE",	"COLD COFFEE",
	
	"PINEAPPLE","STRAWBERRY","CHOCOLATE","BLACK FOREST",
	"DOUBLE STORIED","TRIPLE STORIED","SOFT CONE","VANILLA","MIXED FRUIT",
	"KULFI","CHOCO CHIPS","MANGO","TUTTI FRUITY","LICHI",
	"PISTA BADAM","CHOCOLATE PISTA BADAM","CHOCO DIP","CHOCOLATE LICHI"};

	//***  Check whether teh Guest would like to order from Restaurant

	do
	{
	gotoxy(5,6); cout << "Do you wish to Order from Restaurant (Y/N) :";
	gotoxy (50,6); cin >> answ;
	if (answ == 'y' || answ == 'Y') 
	      { gotoxy (5,6); cout<<"                                            "; break;}
	else
	if (answ == 'n' || answ == 'N') return;
	else {gotoxy (53,6); cout << "Please enter Y/N only!)"; getch();}
	} while(1);

	//***  Display the Menu card (Item name and Price) based on array information stored earlier

	START:
	title();
	height = 20;
	gotoxy(17,5);
	displayBox(length,height,h_char,v_char);	
	gotoxy(20,4); cout<<"R E S T A U R A N T  M E N U  C A R D";
	gotoxy(25,25); cout << "WELCOME TO THE RESTAURANT";
	gotoxy(5,6); cout<<"VEGETABLE VARITIES";
	for(int i=0;i<15;i++)
	{
	  gotoxy(5,i+8); cout<<i+1;
	  gotoxy(8,i+8); cout<<food[i];
	  gotoxy(28,i+8); cout<<price[i];
	}

	gotoxy(40,6); cout<<"RAITHA-SALAD VARITIES";
	for(i=15;i<19;i++)
	{
	  gotoxy(40,i-7); cout<<i+1;
	  gotoxy(43,i-7); cout<<food[i];
	  gotoxy(63,i-7); cout<<price[i];
	}
	
	gotoxy(40,13); cout<<"RICE VARITIES";
	for(i=19;i<23;i++)
	{
	  gotoxy(40,i-4); cout<<i+1;
	  gotoxy(43,i-4); cout<<food[i];
	  gotoxy(63,i-4); cout<<price[i];
	}
	gotoxy(45,23); cout<<"PRESS <Enter> TO CONTINUE"; getch();
	
	clrscr();
	title();
	height = 20;
	gotoxy(17,5);
	displayBox(length,height,h_char,v_char);	
	gotoxy(20,4); cout<<"R E S T A U R A N T  M E N U  C A R D";
	
	gotoxy(5,6); cout<<"ROTI-NAN VARITIES";
	for(i=23;i<36;i++)
	{
	  gotoxy(5,i-15); cout<<i+1;
	  gotoxy(8,i-15); cout<<food[i];
	  gotoxy(28,i-15); cout<<price[i];
	}

	gotoxy(43,6); cout<<"BURGER-SANDWICH";
	for(i=36;i<40;i++)
	{
	  gotoxy(40,i-27); cout<<i+1;
	  gotoxy(43,i-27); cout<<food[i];
	  gotoxy(63,i-27); cout<<price[i];
	}

	gotoxy(40,14); cout<<"BEVERAGES";
	for(i=40;i<43;i++)
	{
	  gotoxy(40,i-24); cout<<i+1;
	  gotoxy(43,i-24); cout<<food[i];
	  gotoxy(63,i-24); cout<<price[i];
	}
	gotoxy(45,23); cout<<"PRESS <Enter> TO CONTINUE"; getch();	
	
	clrscr();
	title();
	height = 20;
	gotoxy(17,5);
	displayBox(length,height,h_char,v_char);	
	gotoxy(20,4); cout<<"R E S T A U R A N T  M E N U  C A R D";
	
	gotoxy(30,6); cout<<"ICE-CREAMS";
	for(i=43;i<52;i++)
	{
	  gotoxy(5,i-35); cout<<i+1;
	  gotoxy(8,i-35); cout<<food[i];
	  gotoxy(28,i-35); cout<<price[i];

	  gotoxy(40,i-35); cout<<i+10;
	  gotoxy(43,i-35); cout<<food[i+9];
	  gotoxy(68,i-35); cout<<price[i+9];
	}

	//***  To Review Menu Card, Press "0" and "1" to place order
	do 
	{ gotoxy(5,19); cout<<"PRESS <0> to Review Menu Card";
	  gotoxy(5,20); cout<<"PRESS <1> TO Place Order";
	  gotoxy(32,20); cin>>answ;
	  if (answ != '0' && answ != '1')
		{
		   gotoxy(5,21); cout<<"WRONG KEY, PRESS <Enter> to Continue"; getch();
 	           gotoxy(5,21); cout<<"                                         ";
		}
	   else break;

	} while(1);

	//***  If option is chosen as "1", Accept order and display details (item & Price) on screen

	fc = 99; y =0;
	switch(answ)
	{
	  case '0' : goto START;
	  case '1' : title();
		     height = 20;
		     gotoxy(17,5);
		     displayBox(length,height,h_char,v_char);	
		     gotoxy(20,4); cout<<"R E S T A U R A N T  M E N U  O R D E R ";
		     gotoxy(40,6); cout<<" Y O U R  O R D E R ";	
		     gotoxy(5,7); cout<<"ENTER FOOD CODE : ";
		     gotoxy(5,8); cout<<"(Press <Zero> to exit)";
		   
		    do
		     {

		     gotoxy(25,7); cout<< "  ";
		     gotoxy(25,7); cin>>fc;
		     if (!cin)
		      {
			gotoxy(5,23); cout << "Please Enter only Numbers !"; getch(); 
			gotoxy(5,23); cout << "                           ";cin.sync(); cin.clear(); continue;
		       }
		     if (fc < 0 || fc > 61) 
			{ gotoxy (5,23); cout << "Enter between 1 & 61 only"; getch(); continue;}

		      { 
			z++;
			fch[z]=price[fc-1];
		        fe+=price[fc-1];
		        strcpy(fi[z],food[fc-1]);
		        if (fc !=0) 
			  { gotoxy(35,y+7); cout<<setw(3)<< fi[y];
	     	            gotoxy(60,y+7); cout<<setw(3)<< fch[y];
			    y++;
  			  }
			 else { y++; break;}
		       
		      }
		     } while(1);
		
	           //*** On completion of placing order, display total cost of items ordered		   
		   if (fe ==0) {gotoxy(5,23); cout << "You did not order anything. Please Visit us again !!!"; getch(); return;}
		   gotoxy(35,y+6); cout<<"TOTAL";
		   gotoxy(60,y+6); cout << setw(3)<< fe;


		   //***  Check whether Guest is staying in the Hotel
		   //***  If staying in Hotel,get the Room NO, or else the Guest has to Pay Cash		   
		   do 
		   {gotoxy (35,23); cout<<"ARE YOU STAYING IN THIS HOTEL (Y/N) ? ";
		    cin>>ans;
		    if (ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N') 
		      { gotoxy (35,23); cout<<"                                         "; break;}
		    
		   } while(1);
	
		   if(ans=='y' || ans=='Y')
		   {
		     char na[25];
		     int rn;
		ROOMNO:
		    do
		    { gotoxy(5,10); cout <<"ROOM NO. :  ";
		      gotoxy(5,11); cout <<"Press Zero to Pay by Cash";  
		      gotoxy(19,10); cin>>rn;
		     if (cin.fail()) {gotoxy(5,23); cout << "Invalid Room No. Press <Enter> to continue"; getch(); 
			cin.sync();cin.clear(); continue;}
		     else break;
		    }while (1);
		     if (rn ==0) 
		     {
		     gotoxy(5,23), cout<<"PLEASE PAY BILL BY CASH. VISIT US AGAIN";
		     getch();
		     return;}

		      //*** If Guest is staying in the Hotel, 
	              //*** Update the field hotel  with total restaurant charges in the file CHECKIN.DAT
		     //VERIFYING THE ENTERED DATA
		     f1.open("CHECKIN.DAT",ios ::in |ios::out|ios::binary);
		     if (f1.fail() !=0) {gotoxy(5,23); cout << "Checkin File Open Error!";getch();return;}
		     f1.seekg(0L,ios::beg);

		     while(!f1.eof())
		     	{
			pos = f1.tellg();
			f1.read((char *)&hin,sizeof(hin));
		       	 if(hin.roomno==rn)
		       		{
				strcpy(nm,hin.name);
				strcpy(add,hin.address);
				strcpy(tel,hin.telno);
				strcpy(dt,hin.date);
				strcpy(roomtyp,hin.roomtype);
				fe += hin.hotel;
			        f1.seekg(pos);
				hin.roomno=rn;
				strcpy(hin.name,nm);
				strcpy(hin.address,add);
				strcpy(hin.telno,tel);
				strcpy(hin.date,dt);
				strcpy(hin.roomtype,roomtyp);
				hin.hotel =fe;
				f1.write((char *)&hin,sizeof(hin));
				f1.close();
			 	gotoxy(5,20); cout<<"HOTEL RECORD UPDATED !!!";
	  		        gotoxy(5,21); cout<<"PRESS ANY KEY TO CONTINUE";
			        getch();
		     		return;
		       		}
				count++;
			   }
		     f1.close();
		     gotoxy(5,23), cout<<"INVALID ROOM NO. ENTER CORRECT NO.";
		     getch();
		     goto ROOMNO;
		
		

		   }
		   else
		   {
 		     gotoxy(30,23);
		     cout<<"PLEASE PAY THE BILL & PRESS <ENTER> TO EXIT";
		     getch();
		     return;
		   }
	}
	clrscr();
}



//*************************************************************************
// Function to Book for Taxi Service and output is stored in file TAXI.TXT
//*************************************************************************

void HOTEL::taxi_service()
{
        //***  Display Header information on screen
	title();
	height = 20;
	gotoxy(17,5);
	displayBox(length,height,h_char,v_char);
	gotoxy(20,4); cout<<"T A X I  S E R V I C E  R E Q U E S T";
	
	//*** Define variables required for the function
	int room,hh,mm,dd1,mm1,yy1;
	char n[25],t[6],date[11],W;

	//*** Check whether Guest is staying in the Hotel, If not he/she cannot use Taxi Service
	gotoxy(5,7); cout << "Are you staying in this hotel (Y/N) ";
	gotoxy(45,7); cin>> W;
	if (W == 'N' || W == 'n') 
	{
	  gotoxy(5,22); cout<<"PLEASE MAKE BOOKING FIRST, PRESS ANY KEY TO EXIT";
	  getch();
	  return;
	}

	//***  Accept Room No of Guest 

	  gotoxy(5,10); cout<<"ROOM NUMBER : ";
	  cin>>room;
	
	  int l=strlen(n);
	  for(int i=0;i<l;i++) n[i]=toupper(n[i]);

	  //***  VERIFY if Room No entered is checked in from file CHECKIN.DAT
	  //***  If Room No. is available display name and check in date
	 
	  f1.open("CHECKIN.DAT",ios::in|ios::binary);
	  if (f1.fail() !=0) {gotoxy(5,23); cout << "Checkin File Open Error!";getch();return;}
	  f1.read((char *)&hin,sizeof(hin));
	  while(f1)
	  {
	    if(hin.roomno==room)
	    {
	        gotoxy(5,11); cout<<"NAME          : " << hin.name ;
	        gotoxy(5,12); cout<<"CHECK-IN DATE : " << hin.date ;
		dd1=(hin.date[0]-48)*10+(hin.date[1]-48);
		mm1=(hin.date[3]-48)*10+(hin.date[4]-48);
		yy1=(hin.date[6]-48)*1000+(hin.date[7]-48)*100+(hin.date[8]-48)*10+(hin.date[9]-48);
	        goto PROCEED;
	    }
	    f1.read((char *)&hin,sizeof(hin));
	  }
	  f1.close();
	  gotoxy(5,18); cout<<"SORRY.INVALID ROOM NO. PRESS ANY KEY TO CONTINIE"; 
	  getch();
	  return;

	//***   Accept date on which Taxi is needed
	//***   Validate whether date entered is valid 

	PROCEED:	
	while (1)
	    {
		gotoxy(5,13); cout<<"TAXI(s) NEEDED ON (date) : ";
	  	gets(date);

		dd=(date[0]-48)*10+(date[1]-48);
		mm=(date[3]-48)*10+(date[4]-48);
		yyyy=(date[6]-48)*1000+(date[7]-48)*100+(date[8]-48)*10+(date[9]-48);
		
		if (dd < 1 || dd > 31) { date_error(35,13); continue;}
		if (mm < 1 || mm > 12) { date_error(35,13); continue;}
		if (yyyy < 2012 || yyyy > 2050) { date_error(35,13); continue;}
		if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) max_days = 31; 
		else 
		if (mm == 4 || mm == 6 || mm == 9|| mm == 11 ) max_days = 30;
		else max_days = 28;

   	        if((yyyy%400 ==0 || (yyyy%100 != 0 && yyyy%4 == 0) ) && mm==2)
        		{
 			 max_days = 29;
		        }
		if (dd > max_days) { date_error(35,13); continue;}
		break;
    	    }

	//***   Check if Date of Taxi required is after Check in date elseo display error	
	if ( (yy1*10000+mm1*100+dd1) > (yyyy*10000+mm*100+dd) )
 	 { 
           gotoxy(5,21);  cout << "Taxi Booking Date before Check-In Date!" ; getch();
	   gotoxy(5,21); cout << "                                       " ; 
	   goto PROCEED;
          }	
   
  	  //***   Accept date on which Taxi is needed
	  //***   Validate whether date entered is valid 
	  mm=0;hh=0;
	  do 
	   {
	     gotoxy(5,14); cout<<"TAXI(s) NEEDED AT (HH:MM) : ";
	     gotoxy(5,15); cout<<"Hours (0 to 23), Minutes (0 to 59)";
	     gotoxy(35,14); cin >> hh;
	     if (cin.fail()) { gotoxy(5,23); cout << "Enter Hours between 0 and 23"; getch(); cin.sync(); cin.clear(); continue;}
	     if (hh <0 || hh > 23) { gotoxy(5,23); cout << "Enter Hours between 0 and 23"; getch();
				     gotoxy(5,23); cout << "                              "; continue;}
	     gotoxy(37,14); cout << ":"; cin >> mm; 
	     if (cin.fail()) { gotoxy(5,23); cout << "Enter Minutes between 0 and 60"; getch(); cin.sync(); cin.clear(); continue;}
	     if (mm <0 || mm > 59) { gotoxy(5,23); cout << "Enter Minutes between 0 and 59"; getch();
				     gotoxy(5,23); cout << "                                ";continue;}
             gotoxy(41,14); cout << " Hrs";
	     gotoxy(5,18); cout << "The charge per hour of Taxi is BD 2. Please pay this to Driver directly";
	     gotoxy(5,20); cout<<"TAXI WILL BE WAITING FOR YOU AT " <<hh << ":"<< mm <<" Hrs ON " <<date<<" OUTSIDE THE GATE";
	     gotoxy(5,21);cout<<"PLEASE COLLECT ADVICE FOR TAXI SERVICE. PRESS ANY KEY TO EXIT.";
	     getch();
	     break;
	   } while(1);

	//***  Create a file TAXI.TXT as output file with the details entered
	//***  Copy of the Taxi Service to be provided to Guest/ Taxi In-charge
	fout.open("TAXI.TXT");
	if (fout.fail() !=0) {gotoxy(5,23); cout << "TAXI.Txt File Open Error!";getch();return;}
	fout << "\t\t\t  H O T E L  C O N T I N E N T A L \n";
	fout << "\t\t\t\t  M A N A M A \n";
	fout << "\t\t\t  K I N G D O M  O F  B A H R A I N \n\n\n";
	fout << " \t\t\t\t T A X I  S E R V I C E \n";
	fout << " \t\t\t\t-------------------- \n\n";
	fout << "1.  NAME                : " << hin.name << "\n";
	fout << "2.  ADDRESS             : " << hin.address << "\n";
	fout << "3.  TELEPHONE           : " << hin.telno << "\n\n";
	fout << "4.  ROOM TYPE           : " << hin.roomtype << "\n";
	fout << "5.  CHECK IN DATE       : " << hin.date << "\n";
	fout << "6.  TAXI BOOKING DATE   : " << date << "\n";
	fout << "7.  BOOKING TIME        : " << hh << ":" << mm << "  Hrs" << "\n\n";
	fout << "Contact Number for Taxi : 17-260399 \n\n";
	fout << "The charge per hour of Taxi is BD 2. Please pay this to Driver directly";
	fout<<"\n\n\n\n THANK YOU FOR BOOKING TAXI FROM US.";
	fout << flush;
	fout.close();
	f1.close();	      
        return;
	
}


//**********************************************************************
// Function to Create Bill and the output is stored in file BILL.TXT
//**********************************************************************

void HOTEL::create_bill()
{

	//***	Display Header Information on Screen

	title();
	height = 20;
	gotoxy(17,5); displayBox(length,height,h_char,v_char);	
	gotoxy(17,6); cout<<" C R E A T E  B I L L ";
	
	//***  Define Variables required for the Function
	int rn,flag=0;
	double serv_fee=0; 
	long tariff, r;
	int dd1,dd2,mm1,mm2,yy1,yy2,p,q;
	char od[11],ot[6];
	
	//*** Accept Room No. for which Bill needs to be created
	gotoxy(5,8); cout<<"ROOM NO         : ";	
	cin >> rn;       
	//*** Read from CHECKIN.DAT and check if Room No. is checked-in
	//*** If Room No is available display details of Guest like Name, address, telephone, etc
	f4.open("CHECKIN.DAT",ios::in|ios::binary);
	if (f4.fail() !=0) {gotoxy(5,23); cout << "Checkin File Open Error!";getch();return;}
        while(!f4.eof())
	   {
		f4.read((char *)&hin,sizeof(hin));
		if(hin.roomno==rn)
		{
		  gotoxy(5,10); cout<<"NAME           : "<<hin.name;
	  	  gotoxy(5,11); cout<<"ADDRESS(R)     : "<<hin.address;
		  gotoxy(5,12); cout<<"TEL. NO.(R)    : "<<hin.telno;
		  gotoxy(5,13); cout<<"ROOM TYPE      : "<<hin.roomtype;
		  gotoxy(5,14); cout<<"CHECK-IN DATE  : "<<hin.date;
		  flag = 1;
		  break;
		}
	    flag = 0;
	   }
		
	//***  If Room No. is not checked in return back to Menu		
	if (flag ==0)
	  {
	   gotoxy(5,21); cout<<"ABOVE ROOM NO. IS NOT OCCUPIED. PRESS ANY KEY TO CONTINUE";
	   getch();
	   fout << flush;
	   f4.close();
	   return;
	   }
	
	//*** If Room No is available, accept Check-Out date and perform validation
	DATE_CHECKOUT:
	while (1) 
	{
	  gotoxy(5,15); cout<<"CHECK OUT DATE : ";
	  gets(od);  
	  dd=(od[0]-48)*10+(od[1]-48);
	  mm=(od[3]-48)*10+(od[4]-48);
	  yyyy=(od[6]-48)*1000+(od[7]-48)*100+(od[8]-48)*10+(od[9]-48);
	  if (dd < 1 || dd > 31) { date_error(35,8); continue;}
	  if (mm < 1 || mm > 12) { date_error(35,8); continue;}
	  if (yyyy < 2012 || yyyy > 2050) { date_error(35,8); continue;}
	  if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) max_days = 31; 
	  else 
	  if (mm == 4 || mm == 6 || mm == 9|| mm == 11 ) max_days = 30;
	  else max_days = 28;
          if((yyyy%400 ==0 || (yyyy%100 != 0 && yyyy%4 == 0) ) && mm==2)
            {
              max_days = 29;
	    }
	  if (dd > max_days) 
              { 
		date_error(35,8); continue;}
		break;
	      }
			
	//***   CALCULATING NO. OF DAYS THE CUSTOMER OCCUPIED THE ROOM & TARIFF
			
	dd1=(hin.date[0]-48)*10+(hin.date[1]-48);
	dd2=(od[0]-48)*10+(od[1]-48);
	mm1=(hin.date[3]-48)*10+(hin.date[4]-48);
	mm2=(od[3]-48)*10+(od[4]-48);
	yy1=(hin.date[6]-48)*1000+(hin.date[7]-48)*100+(hin.date[8]-48)*10+(hin.date[9]-48);
	yy2=(od[6]-48)*1000+(od[7]-48)*100+(od[8]-48)*10+(od[9]-48);
			
	if ( (yy1*10000+mm1*100+dd1) > (yy2*10000+mm2*100+dd2) )
	 { 
	   gotoxy(5,21); cout << "Check-Out Date less than Check-in date!" ; getch(); goto DATE_CHECKOUT;
         }

	if(yy1%4==0) 
          { 
	    p=29; q=28;
          }
	else if(yy2%4==0) 
         { 
            p=28; q=29;
          }
	else { p=28; q=28; }

	//*** Calculate the Tariff 
	int cy[12]={ 31,p,31,30,31,30,31,31,30,31,30,31 };
	int ny[12]={ 31,q,31,30,31,30,31,31,30,31,30,31 };
	if(yy1==yy2 && mm1==mm2 && dd1==dd2) tariff=hin.charge;
	else
	{
          if(yy1==yy2)
	   {
	    if(mm1==mm2) tariff=hin.charge*(dd2-dd1);
	    else
	    {
	      r=cy[mm1-1]-dd1+dd2;
	      for(int l=mm1;l<mm2-1;l++) r+=cy[l];
	      tariff=hin.charge*r;
	    }
	  }
	  else
	  {
	    r=cy[mm1-1]-dd1+dd2;
	    for(int l=mm1;l<12;l++) r+=cy[l];
	    for(l=0;l<mm2-1;l++) r+=ny[l];
	    tariff=hin.charge*r;
	  }
	}
		

	//***  Display the Final Bill on screen

        gotoxy(47,7); cout<<"**** FINAL BILL ****";	
	gotoxy(47,10); cout<<"TARIFF            : BD "<< setw(6) <<tariff;
	serv_fee = tariff * 0.12;
	gotoxy(47,11); cout<<"RESTAURANT CHARGE : BD " << setw(6) << hin.hotel;
	gotoxy(47,12); cout<<"SERVICE TAX (12%) : BD " << setw(6) << serv_fee;
	gotoxy(47,13); cout<< "-------------------------------";		
	gotoxy(47,14); cout<<"TOTAL             : BD " << setw(6) << (tariff+serv_fee+hin.hotel);
	gotoxy(47,15); cout<< "-------------------------------";

	//***  Generate the Final Bill and create output in file BILL.TXT by opening the file in output mode

	fout.open("BILL.TXT");
	if (fout.fail() !=0) {gotoxy(5,23); cout << "Bill.Txt File Open Error!";getch();return;}
	fout << "\t\t\t  H O T E L  C O N T I N E N T A L \n";
	fout << "\t\t\t\t  M A N A M A \n";
	fout << "\t\t\t  K I N G D O M  O F  B A H R A I N \n\n\n";
	fout << " \t\t\t\t F I N A L  B I L L \n";
	fout << " \t\t\t\t-------------------- \n\n";
	fout << "1.  NAME            : " << hin.name << "\n";
	fout << "2.  ADDRESS         : " << hin.address << "\n";
	fout << "3.  TELEPHONE       : " << hin.telno << "\n\n";
	fout << "4.  ROOM TYPE       : " << hin.roomtype << "\n";
	fout << "5.  CHECK IN DATE   : " << hin.date << "\n";
	fout << "6.  CHECK OUT DATE  : " << od << "\n";
	fout << "7.  NO OF DAYS      : " << setw(6) << tariff/ hin.charge  << "\n\n" ;
	fout << "8.  ROOM TARIFF     : BD " << setw(6) << tariff <<"\n" ;
	fout << "9.  HOTEL CHARGES   : BD " << setw(6) << hin.hotel << "\n"; 
	fout << "10. SERVICE CHARGES : BD " << setw(6) << serv_fee << "\n\n";
	fout << "-----------------------------------------------\n";
	fout << "    T O T A L       : BD " << setw(6) << (tariff+serv_fee+hin.hotel) << "\n";
	fout << "===============================================\n\n\n";
	fout<<"THANK YOU FOR STAYING WITH US. PLEASE COME AGAIN.";
	fout << flush;
	fout.close();
		      
				
	gotoxy(5,21); cout<<"GUEST BILL GENERATED. PRESS ANY KEY TO CONTINUE";
	getch();
	clrscr();
	f4.close();
	return;
}



//**********************************************************
//  Function to View Data
//**********************************************************

void HOTEL::view_data()
{
	//***  Display header information on screen
	//***  Define variables required for the function
	//***  Display the sub-menu items which are available in enquiry/view
	START:
	title();
	height = 20;
	gotoxy(17,5);
	displayBox(length,height,h_char,v_char);
	int choice,count=0,row=9;
	gotoxy(19,10); cout<<"S U B  M E N U - E N Q U I R Y ";
	gotoxy(22,12); cout<<"1.   BOOKING";
	gotoxy(22,13); cout<<"2.   CHECKED IN";
	gotoxy(22,14); cout<<"3.   CHECK OUT";
	gotoxy(22,15); cout<<"4.   CANCELLED";
	gotoxy(22,16); cout<<"5.   ROOMS AVAILABILITY";
	gotoxy(22,17); cout<<"6.   BACK TO MAIN MENU";
	gotoxy(22,19); cout<<"Enter your choice : [   ]";
	gotoxy(44,19); cin>>choice;
	if (!cin) { gotoxy(5,23); cout << "Please enter valid option"; getch(); cin.sync(); cin.clear(); goto START;}
	if (choice < 1 || choice > 6) { gotoxy(5,23); cout << "Please enter valid option"; getch(); goto START;}

	//***  Based on option, choose the fuction using Case statement
	switch(choice)
	{
	
	   //***  Display data of Guest who have made Booking
           //***  Data displayed from file BOOKING.DAT

	case 1 :   title();
		   height = 20;
		   gotoxy(17,5); displayBox(length,height,h_char,v_char);	
		   gotoxy(17,6); cout<<" B O O K I N G  I N F O R M A T I O N";
		   gotoxy(3,8); cout<<"ROOM NO.  NAME          ADDRESS        TEL NO.   DATE       ROOM TYPE";	           
		   f1.open("BOOKING.DAT",ios::in|ios::binary);
		   if (f1.fail() !=0) {gotoxy(5,23); cout << "No BOOKING Data exits. Press <Enter> to exit";getch();goto START;}
		   f1.read((char *)&hbook,sizeof(hbook));

		   while(f1)
		   {
		     gotoxy(3,row);  cout << hbook.roomno;
		     gotoxy(13,row); cout << hbook.name;
		     gotoxy(27,row); cout << hbook.address;
		     gotoxy(42,row); cout << hbook.telno;
		     gotoxy(52,row); cout << hbook.date;
		     gotoxy(63,row); cout << hbook.roomtype;
		     row++; count++;	
		     if (count > 12) {
	      		   gotoxy(5,25); cout<<" Press any key to continue"; getch();
			   title();
		   	   height = 20;
		   	   gotoxy(17,5);
                   	   displayBox(length,height,h_char,v_char);	
			   gotoxy(17,6); cout<<"B O O K I N G  I N F O R M A T I O N";
		           gotoxy(3,8); cout<<"ROOM NO.  NAME          ADDRESS        TEL NO.   DATE       ROOM TYPE";	           
		           count =0;row=9;}
		    

		     f1.read((char *)&hbook,sizeof(hbook));
		   }
   		   gotoxy(5,25); cout<<" Press any key to exit      ";getch();
		   f1.close();
		   clrscr();
		   goto START;

	  //***  Display data of Guest who have Checked-in
	  //***  Data displayed from file CHECKIN.DAT

	case 2 :   title();
		   height = 20;
		   gotoxy(17,5); displayBox(length,height,h_char,v_char);	
		   gotoxy(17,6); cout<<" C H E C K E D-I N  I N F O R M A T I O N";
		   gotoxy(3,8); cout<<"ROOM NO.  NAME          ADDRESS        TEL NO.   DATE       HOTEL CHARGE";	           
		   f2.open("CHECKIN.DAT",ios::in|ios::binary);
		   if (f2.fail() !=0) {gotoxy(5,23); cout << "No Check-In Data Exists. Press <Enter> to exit";getch();goto START;}
		   f2.read((char *)&hin,sizeof(hin));

		   while(f2)
		   {
		     gotoxy(3,row);  cout << hin.roomno;
		     gotoxy(13,row); cout << hin.name;
		     gotoxy(27,row); cout << hin.address;
		     gotoxy(42,row); cout << hin.telno;
		     gotoxy(52,row); cout << hin.date;
		     gotoxy(63,row); cout << hin.hotel;
		     row++; count++;	
		     if (count > 12) {
			   gotoxy(5,25); cout<<" Press any key to continue"; getch();
			   title();
		   	   height = 20;
		   	   gotoxy(17,5);
                   	   displayBox(length,height,h_char,v_char);	
			   gotoxy(17,6); cout<<" C H E C K E D-I N  I N F O R M A T I O N";
		           gotoxy(3,8); cout<<"ROOM NO.  NAME          ADDRESS        TEL NO.   DATE       ROOM TYPE";	           
		           count =0;row=9;}
		    

		     f2.read((char *)&hin,sizeof(hin));
		   }
		   gotoxy(5,25); cout<<" Press any key to exit      "; getch();
		   f2.close();

		   clrscr();
		   goto START;

	   //***  Display data of Guest who have Checked-out
	   //***  Data displayed from file CHECKOUT.DAT

	  case 3 : title();
		   height = 20;count =0;row=9;
		   gotoxy(17,5); displayBox(length,height,h_char,v_char);	
		   gotoxy(17,6); cout<<" C H E C K E D-O U T   I N F O R M A T I O N";
		   gotoxy(3,8); cout<<"ROOM NO.  NAME          TEL NO.    CHECK-IN  CHECK-OUT  ";	       
	           f3.open("CHECKOUT.DAT",ios::in|ios::binary);
		   if (f3.fail() !=0) {gotoxy(5,23); cout << "No Check-Out Data Exists. Press <Enter> to exit";getch();goto START;}
		   f3.read((char *)&hout,sizeof(hout));
		   while(f3)
		   {
		     gotoxy(3,row);  cout << hout.roomno;
		     gotoxy(13,row); cout << hout.name;
		     gotoxy(27,row); cout << hout.telno;
		     gotoxy(37,row); cout << hout.date;
		     gotoxy(48,row); cout << hout.odate;
		     row++; count++;	
		     if (count > 12) {
			   gotoxy(5,25); cout<<" Press any key to continue"; getch();
			   title();
		   	   height = 20;
		   	   gotoxy(17,5);
                   	   displayBox(length,height,h_char,v_char);	
			   gotoxy(17,6); cout<<" C H E C K E D-O U T   I N F O R M A T I O N";
            		   gotoxy(3,8); cout<<"ROOM NO.  NAME          TEL NO.    CHECK-IN  CHECK-OUT  TIME-OUT";	       
		           count =0;row=9;}

		     f3.read((char *)&hout,sizeof(hout));
		   }
		   gotoxy(5,25); cout<<" Press any key to exit      "; getch();
		   clrscr();
		   f3.close();
		   goto START;

	   //***  Display data of Guest who have Cancelled
	   //***  Data displayed from file CANCEL.DAT

	  case 4 : title();
		   height = 20;
		   gotoxy(17,5); displayBox(length,height,h_char,v_char);	
		   gotoxy(17,6); cout<<" C A N C E L L A T I O N   I N F O R M A T I O N";
		   gotoxy(3,8);  cout<<"NAME          ADDRESS               TEL NO";	       
	           f4.open("CANCEL.DAT",ios::in|ios::binary);
		   if (f4.fail() !=0) {gotoxy(5,23); cout << "No Cancellation Data Exists. Press <Enter> to exit";getch();goto START;}
		   f4.read((char *)&hcan,sizeof(hcan));
		   count =0;row=9;
		   while(f4)
		   {
		     gotoxy(3,row);  cout << hcan.name;
		     gotoxy(17,row); cout << hcan.address;
		     gotoxy(39,row); cout << hcan.telno;
		     row++; count++;

		     if (count > 12) {
			   gotoxy(5,25); cout<<" Press any key to continue"; getch();
			   title();
		   	   height = 20;
		   	   gotoxy(17,5);
                   	   displayBox(length,height,h_char,v_char);	
			   gotoxy(17,6); cout<<" C A N C E L L A T I O N   I N F O R M A T I O N";
			   gotoxy(3,8); cout<<"NAME          ADDRESS               TEL NO";	       
		           count =0;row=9;}		

		     f4.read((char *)&hcan,sizeof(hcan));
		   }
		   gotoxy(5,25); cout<<" Press any key to exit      "; getch();
		   clrscr();
		   f4.close();
		   goto START;
	  
	   //***  Display data of Rooms availability, 
	   //***  If value is "A"- diplay Avail, If value is "O" - display Occupy
	   //***  Data displayed from file ROOMS.DAT
	
	  case 5 : title();
		   height = 20;
		   gotoxy(17,5); displayBox(length,height,h_char,v_char);	
   	   	   gotoxy(14,4); cout<<"R O O M  O C C U P A N C Y  I N F O R M A T I O N";
		   int row=7, col = 3, a = 0;
		   do 
		     {
			gotoxy(col,6); cout << "RmNo " << "Status";
			col +=16; a++;
			} while (a < 5);
			row++; col = 3;
		    	f.open("ROOMS.DAT",ios::in|ios::binary);
			if (f.fail() !=0) {gotoxy(5,23); cout << "Rooms Master Data not available. Press <Enter> to exit";getch();goto START;}
			while (!f.eof())
			{
			f.read((char *)&rms,sizeof(rms));
			gotoxy(col+1,row); cout << rms.roomno;
			gotoxy(col+5,row); if (rms.avail == 'A') {cout << "Vacant";} else {cout << "Occupy"; }
			row++;
			if (row > 22) {row = 8; col= col + 16;}
			}
			f.close();
			gotoxy(5,25); cout<< "PRESS <Enter> TO EXIT";
			getch();
		        goto START;

		    
	  case 6 : clrscr();
		   return;
	}

	clrscr();
}



//***************************************************************************************************************************
// Function to create initial file ROOMS.DAT for first time. If file ROOMS.DAT already exists then a new file is not created
//***************************************************************************************************************************

void HOTEL::create_roomsdata()
{

  //***  Define Variable required for function

  int r=0;

  //***  Writing Intial Rooms Availability Data
  //***  Open file ROOMS.DaT in inout mode
  //*** If already exists then it does not create again and function returns back, else proceeds creating
  FILE *fp = fopen("ROOMS.DAT","r");
  if( fp ) { //*** exists
	fclose(fp); return;
	} 


  //***  Writing Intial Rooms Availability Data
  //***  Open file ROOMS.DaT in output mode
  f.open("ROOMS.DAT",ios::out);
  if (f.fail() !=0) {gotoxy(5,23); cout << "Rooms File Open Error!";getch();return;}

  //*** Write Room Code "1" data 
  while (r<15)
  {
    rms.roomcode=1;
    rms.roomno=101+r;
    rms.avail='A';
    f.write((char *)&rms,sizeof(rms));
    r++;
   }

  //*** Write Room Code "2" data 
  r=0;
  while (r<15)
   {
     rms.roomcode=2;
     rms.roomno=201+r;
     rms.avail='A';
     f.write((char *)&rms,sizeof(rms));

    r++;
   }

  //*** Write Room Code "3" data 
  r=0;
  while (r<15)
  {
    rms.roomcode=3;
    rms.roomno=301+r;
    rms.avail='A';
    f.write((char *)&rms,sizeof(rms));
    r++;
  }

  //*** Write Room Code "4" data 
  r=0;
  while (r<15)
  {
   rms.roomcode=4;
   rms.roomno=401+r;
   rms.avail='A';
   f.write((char *)&rms,sizeof(rms));
   r++;
  }

  //*** Write Room Code "5" data 
  r=0;
  while (r<14)
  {
   rms.roomcode=5;
   rms.roomno=501+r;
   rms.avail='A';
   f.write((char *)&rms,sizeof(rms));
   r++;
  }
  f.close();

  return;

}

    
//**********************************************************
//*** Function to display Error Message for Invalid Date
//**********************************************************

void date_error( int x, int y)
		{
		gotoxy(x+11,y); cout << " Invalid Date !"; getch(); 
		gotoxy(x,y); cout << "                          "; 
		return;
		}




//**********************************************************
//*** Main Function of the Program
//**********************************************************

void main()
 {
  int option_code=0;
  welcome(); // Welcome Function
  login();   // Login Function


  //***  To Create ROOMS.DAT file for First Time using the function create_roomsdata()
  //***  Running this function second time will fresh file with all rooms vacant
  H.create_roomsdata();

 LABEL:
   title();
   height = 20;

   // *** Displays box and then the Menu options 

   gotoxy(17,5); displayBox(length,height,h_char,v_char);
   gotoxy(32,8);  cout<< "M A I N  M E N U";
   gotoxy(22,10);  cout<<"(1)  Booking ";
   gotoxy(22,11);  cout<<"(2)  Check In";
   gotoxy(22,12);  cout<<"(3)  Check  Out";
   gotoxy(22,13);  cout<<"(4)  Cancellation ";
   gotoxy(22,14);  cout<<"(5)  Restaurant ";
   gotoxy(22,15);  cout<<"(6)  Taxi Service ";
   gotoxy(22,16);  cout<<"(7)  Enquiry ";
   gotoxy(22,17);  cout<<"(8)  Create Bill ";
   gotoxy(22,18);  cout<<"(9)  E X I T "; 
   gotoxy(22,20);  cout<<"Enter your choice : [   ]";

   //*** Accepts option and if the choice is invalid errors are captured and error message displayed
   gotoxy(44,20);  cin >>option_code;
   if (cin.fail()) { gotoxy(5,23); cout << "Please enter valid option"; getch(); cin.sync(); cin.clear(); goto LABEL;}
   if(option_code < 1 || option_code>9)
     {
	gotoxy(5,23); cout << "Please enter valid option"; getch();
	option_code =0;	
	goto LABEL;
     }

   //*** Choosing the Specific Option and corresponding function
	switch(option_code)
	{
	 case 1:H.booking();       //*** Function for Booking  Hotel Guest
		break;
	 case 2:H.check_in();      //*** Function for Checking Hotel Guest who have already booked
		break;
	 case 3:H.check_out();     //*** Function for Check out of Guest 
		break;
	 case 4:H.cancellation();  //*** Function for Cancellation of Guests booked before check in
		break;
	 case 5:H.restaurant();    //*** Function for Restaurant Service 
		break;
	 case 6:H.taxi_service();  //*** Function for Taxi Service
		break;
	 case 7:H.view_data();     //*** Function for Viewing Data 
		break;
	 case 8:H.create_bill();   //*** Function for Creating Bill of Checked in Guest
		break;
	 case 9:thankyou();        //*** Function for Thank you message on exit of main program
		exit(0);
	}
	goto LABEL;	

    }
