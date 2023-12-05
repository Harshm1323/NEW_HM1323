#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void login();
void registration();
void forgot();

int main()
{
	int c; /*c for choice*/
	cout<<"\t\t\t___________________________________ \n\n\n";
	cout<<"\t\t\t  welcome to the login page         \n\n\n";
	cout<<"\t\t\t___________    menu    _____________\n\n\n";
	cout<<"                                           \n\n";
	cout<<"\t| Press 1 to login                       |"<<endl;
	cout<<"\t| Press 2 to register                    |"<<endl;
    cout<<"\t| Press 3 If you forget your password    |"<<endl;
    cout<<"\t| Press 4 to Exit                        |"<<endl;
    cout<<"\n\t\t\t please enter your choice:";
    cin>>c;
    cout<<endl;
    
    switch(c)
	{
		   case 1:
		   	login();
		   	break;
		   	
		   	
	      case 2:
	      	registration();
	      	break;
	      case 3:
	      	forgot();
	      	break;
	      case 4:
	      	cout<<"\t\t\t Thankyou!\n\n";
	      	break;
	      default:
	      	system("cls");
	      	cout<<"\t\t\t please select from the option goiven above\n"<<endl;
	      	main();
	}
	
	
}
void login()
{
	int count;
	string userId, password, id, pass;
	system("cls");
	cout<<"\t\t\t please enter the username and password :"<<endl;
	cout<<"\t\t\t username";
	cin>>userId;
	cout<<"\t\t\t Password";
	cin>>password;
	
	ifstream input ("records.txt");
	while(input>>id>>pass)
	{
		if(id==userId && pass==password)
		{
			count=1;
			system("cls");
		}
	}
      input.close();
     if(count==1)
    {
      cout<<userId<<"\n your login is successfull\n thanks for logging in\n";
 	  main();
    }
     else{
 	      cout<<"\n Login error \n please check your username and password\n";
 	     main();
    }
     
  }
  
 void registration()
{
   	string ruserId,rpassword,rid,rpass;
   	system("cls");
   	cout<<"\t\t\t Enter the username : ";
   	cin>>ruserId;
   	cout<<"\t\t\t Enter the password  : ";
   	cin>>rpassword;
   	
   	ofstream f1("records.txt", ios::app);
	   f1<<ruserId<<' '<<rpassword<<endl;
	   system("cls");
	   cout<<"\n\t\t\t Registration is successfi=ull!\n";
	   main();
	   
	   
    }

  void forgot()
  {
   	int option;
   	system("cls");
   	 cout<<"\t\t\t You forgot the password? No worries \n";
	 cout<<"press 1 to search your Id by username "<<endl;
	 cout<<"press 2 to go back to main menu"<<endl;
	 cout<<"\t\t\t Enter your choice:";
	 cin>>option;
	 switch(option)
	 {	
	 	case 1:
	 	{
	 		int count=0;
	 		string suserId,sId,spass;
	 		cout<<"\n\t\t\t Enter the username which you remembered :";
	 		cin>>suserId;
	 		
	 		ifstream f2("records.txt");
	 		while(f2>>sId>>spass)
	 		{
	 			if(sId==suserId)
	 			{
	 				count=1;
				 }
			 }
			 f2.close();
			 if(count==1)
			 {
			 	cout<<"\n\n Your account is found! \n";
			 	cout<<"\n\nYour password id: "<<spass;
			 	main();
			 }
			 else{
			 	cout<<"\n\t Sorry! your account is not found! \n";
			 	main();
			 	
			 }
			 break;
		}
		 case 2:
		 	{
		 		main();
		       }
		       
		 default:
			 	cout<<"\t\t\t Wrong choice ! Please try again "<<endl;
			 	forgot();
	 }
}


