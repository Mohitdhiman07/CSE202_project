#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>


using namespace std;

class player{
	public:
	int match,inng,runs,hscore,cen,hcen,six,fours;
	float avg,sr,ovrs,wkts,econ;
	string name;
	string plteam;


		void add_player_bat();
		void add_player_bowl();
		void del_batsmen();
		void del_bowler();
		void search_batsmen();
		void search_bowler();
		void information_batsman();
		void information_bowler();
		void modify_batsmen();
		void modify_bowler();
		void report_bat()
		{
			cout<<name<<setw(15)<<plteam<<setw(15)<<match<<setw(15)<<inng<<setw(15)<<runs<<setw(15)<<hscore<<setw(15)<<avg<<setw(15)<<cen<<setw(15)<<hcen<<setw(15);
		}
		void report_bowl()
		{
			cout<<name<<setw(15)<<plteam<<setw(15)<<match<<setw(10)<<inng<<setw(10)<<ovrs<<setw(10)<<econ<<setw(10);
		}
		void display_allbat();
		void display_allbowl();

}p1,p2;

void player :: information_batsman()

{
		cout<<"\n\nENTER PLAYER NAME :   ";
		cin.ignore();
		getline(cin,name);
		cout<<"\n\nENTER TEAM NAME FOR WHICH PLAYER PLAYS :    ";
		cin.ignore();
		getline(cin,plteam);
		cout<<"\n\nENTER TOTAL NUMBER OF MATCHES PLAYED :    ";
		cin>>match;
		cout<<"\n\nENTER TOTAL NUMBER OF INNINGS PLAYED :    ";
		cin>>inng;

		cout<<"\n\nENTER TOTAL RUN SCORED :    ";
		cin>>runs;

		cout<<"\n\nENTER HIGHEST SCORE PLAYER MADE :    ";
		cin>>hscore;

		cout<<"\n\nENTER TOTAL NUMBER OF CENTURY PLAYER MADE :    ";
		cin>>cen;

		cout<<"\n\nENTER TOTAL NUMBER OF HALF CENTURY PLAYER MADE :    ";
		cin>>hcen;

		avg=inng/(float)runs;


}


void player :: information_bowler()
{
		cout<<"\n\nENTER PLAYER NAME :   ";
		cin.clear();
		cin.sync();
		getline(cin,name);
		cout<<"\n\nENTER TEAM NAME FOR WHICH PLAYER PLAYS :    ";
		cin.clear();
		cin.sync();
		getline(cin,plteam);
		cout<<"\n\nENTER TOTAL NUMBER OF MATCHES PLAYED :    ";
		cin>>match;
		cout<<"\n\nENTER TOTAL NUMBER OF INNINGS PLAYED :    ";
		cin>>inng;
		cout<<"\n\nENTER TOTAL OVERS THROWN :     ";
		cin>>ovrs;
		cout<<"\n\nENTER TOTAL WICKET TAKEN :    ";
		cin>>wkts;
		econ=inng/(float)wkts;
}



fstream f;//global file


void player :: add_player_bat()
{
		char ch;
	f.open("batsmen.dat",ios::app|ios::out);
	do
	{;
		f.write((char*)this,sizeof(*this));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	f.close();

}



void player :: add_player_bowl()
{
		char ch;
	f.open("bowler.dat",ios::app|ios::out);
	do
	{

		f.write((char*)this,sizeof(*this));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	f.close();
}



void player :: modify_batsmen()
{
	string n;;
	int found=0;
	cout<<"\n\n\tMODIFY BATSMEN REOCORD.... ";
	cout<<"\n\n\tENTER BATSMEN NAME :    ";
	cin>>n;
	f.open("batsmen.dat",ios::in|ios::out);
	f.read((char*)this,sizeof(*this));
	while(!f.eof() && found==0)
	{
		if(p1.name==n)
		{
			
		 	cout<<"========================================================================================================================================================\n";
			cout<<"PLAYER NAME"<<setw(15)<<"PLAYER TEAM"<<setw(15)<<"MATCHS"<<setw(15)<<"INNINGS"<<setw(15)<<"RUNS"<<setw(15)<<"HIGHEST SCORE"<<setw(15)<<"AVERAGE"<<setw(15)<<"100's"<<setw(15)<<"50's"<<setw(15);
			cout<<"\n========================================================================================================================================================\n";
			report_bat();
			information_batsman();
			int pos=-1*sizeof(p1);
		    	f.seekp(pos,ios::cur);
		    	f.write((char*)this,sizeof(*this));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}

    	f.close();
    	if(found==0)
    		cout<<"\n\n Record Not Found ";
    	getch();
}




void player :: modify_bowler()
{
	string n;;
	int found=0;
	cout<<"\n\n\tMODIFY BOWLER REOCORD.... ";
	cout<<"\n\n\tENTER BOWLER NAME :    ";
	cin>>n;
	f.open("bowler.dat",ios::in|ios::out);
	f.read((char*)this,sizeof(this));
	while(!f.eof() && found==0)
	{
		if(p2.name==n)
		{
			cout<<"===================================================================================================================\n";
			cout<<"PLAYER NAME"<<setw(15)<<"PLAYER TEAM"<<setw(15)<<"MATCHS"<<setw(5)<<"INNINGS"<<setw(5)<<"OVERS"<<setw(7)<<"WICKETS"<<setw(4)<<"ECONOMY"<<setw(4)<<"\n";
			cout<<"===================================================================================================================\n";

			report_bowl();
		 	
			information_bowler();
			int pos=-1*sizeof(p1);
		    	f.seekp(pos,ios::cur);
		    	f.write((char*)this,sizeof(*this));
		    	cout<<"\n\n\t Record Updated";
		    	found=1;
		}
	}

    	f.close();
    	if(found==0)
    		cout<<"\n\n Record Not Found ";
    	getch();
}




void player :: del_batsmen()
{
	string n;
	int flag=0;

    	cout<<"\n\n\n\tDELETE PLAYER...";
    	cout<<"\n\nEnter The Name of the Player You Want To Delete : ";
    	cin>>n;
    	f.open("batsmen.dat",ios::in|ios::out);
    	fstream fp;
    	fp.open("Temp1.dat",ios::out);
    	f.seekg(0,ios::beg);
    	while(f.read((char*)this,sizeof(*this)))
	{
		if(p1.name==n)
	     		fp.write((char*)this,sizeof(*this));
		else
	   		flag=1;
	}

	fp.close();
    	f.close();
    	remove("batsmen.dat");
    	rename("Temp1.dat","batsmen.dat");
    	if(flag==1)
     		cout<<"\n\n\tRecord Deleted ..";
    	else
     		cout<<"\n\nRecord not found";
    	getch();
}









void player :: del_bowler()
{
	string n;
	int flag=0;

    	cout<<"\n\n\n\tDELETE PLAYER...";
    	cout<<"\n\nEnter The Name of the Player You Want To Delete : ";
    	cin>>n;
    	f.open("bowler.dat",ios::in|ios::out);
    	fstream fp;
    	fp.open("Temp.dat",ios::out);
    	f.seekg(0,ios::beg);
    	while(f.read((char*)this,sizeof(*this)))
	{
		if(p2.name==n)
	     		fp.write((char*)this,sizeof(*this));
		else
	   		flag=1;
	}

	fp.close();
    	f.close();
    	remove("bowler.dat");
    	rename("Temp.dat","bowler.dat");
    	if(flag==1)
     		cout<<"\n\n\tRecord Deleted ..";
    	else
     		cout<<"\n\nRecord not found";
    	getch();
}

void player :: search_batsmen()
{			
			int counter=0;
			string bat;
			f.open("batsmen.dat",ios::in|ios::binary);
			cout<<"\nENTER PLAYER NAME TO SEARCH :    ";
			cin.ignore();
			getline(cin,bat);
			f.read((char*)this,sizeof(*this));
			while(!f.eof())
			{
				if(p1.name==bat)
				{
					cout<<"========================================================================================================================================================\n";
					cout<<"PLAYER NAME"<<setw(15)<<"PLAYER TEAM"<<setw(15)<<"MATCHS"<<setw(15)<<"INNINGS"<<setw(15)<<"RUNS"<<setw(15)<<"HIGHEST SCORE"<<setw(15)<<"AVERAGE"<<setw(15)<<"100's"<<setw(15)<<"50's"<<setw(15);
					cout<<"\n========================================================================================================================================================\n";
					report_bat();
					counter++;
				}
				f.read((char*)this,sizeof(*this));
			}
			if(counter==0)
			{
				cout<<"\n*************RECORD NOT FOUND****************\n";
			}
			
}


void player :: search_bowler()
{			
			int counter=0;
			string bowl;
			f.open("bowler.dat",ios::in|ios::binary);
			cout<<"\nENTER PLAYER NAME TO SEARCH :    ";
			cin.ignore();
			getline(cin,bowl);
			f.read((char*)this,sizeof(*this));
			while(!f.eof())
			{
				if(p1.name==bowl)
				{
					cout<<"===================================================================================================================\n";
					cout<<"PLAYER NAME"<<setw(15)<<"PLAYER TEAM"<<setw(15)<<"MATCHS"<<setw(5)<<"INNINGS"<<setw(5)<<"OVERS"<<setw(7)<<"WICKETS"<<setw(4)<<"ECONOMY"<<setw(4)<<"\n";
					cout<<"===================================================================================================================\n";

					report_bowl();
					counter++;
				}
				f.read((char*)this,sizeof(*this));
			}
			if(counter==0)
			{
				cout<<"\n*************RECORD NOT FOUND****************\n";
			}
			
}


void player::display_allbat()
{
	f.open("batsmen.dat",ios::in|ios::binary);
	if(!f)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tPLAYER LIST\n\n";
	cout<<"========================================================================================================================================================\n";
	cout<<"PLAYER NAME"<<setw(15)<<"PLAYER TEAM"<<setw(15)<<"MATCHS"<<setw(15)<<"INNINGS"<<setw(15)<<"RUNS"<<setw(15)<<"HIGHEST SCORE"<<setw(15)<<"AVERAGE"<<setw(15)<<"100's"<<setw(15)<<"50's"<<setw(15);
	cout<<"\n========================================================================================================================================================\n";
	f.read((char*)this,sizeof(*this));
	while(!f.eof())
	{
		report_bat();
		f.read((char*)this,sizeof(*this));
	}
     	f.close();
     	getch();
}




void player ::display_allbowl()
{

	f.open("bowler.dat",ios::in|ios::binary);
	if(!f)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
     	}

	cout<<"\n\n\t\tPLAYER LIST\n\n";
	cout<<"===================================================================================================================\n";
	cout<<"PLAYER NAME"<<setw(15)<<"PLAYER TEAM"<<setw(15)<<"MATCHS"<<setw(5)<<"INNINGS"<<setw(5)<<"OVERS"<<setw(7)<<"WICKETS"<<setw(4)<<"ECONOMY"<<setw(4)<<"\n";
	cout<<"===================================================================================================================\n";

	f.read((char*)this,sizeof(*this));

	while(!f.eof())
	{
		report_bowl();
		f.read((char*)this,sizeof(*this));
	}
     	f.close();
     	getch();
}



int main()
{
		
		char ch;
	do
	{

		cout<<"\n\n\n\t\t\t***************** MAIN MENU ************************";
		cout<<"\n\n\n\n\t01. ADD PLAYER";
		cout<<"\n\n\t02. DISPLAY ALL BATSMEN";
	  	cout<<"\n\n\t03. DISPLAY ALL BOWLER";
	  	cout<<"\n\n\t04. DELETE PLAYER";
	  	cout<<"\n\n\t05. SEARCH PLAYER";
	  	cout<<"\n\n\t06. MODIFY PLAYER";
	  	cout<<"\n\n\t07. VIEW MATCH SCHEDULE";
	  	cout<<"\n\n\t08. VIEW TEAM SQUADS";
	  	cout<<"\n\n\t09. EXIT";
	  	cout<<"\n\n\tPlease Select Your Option (1-9) ";
	  	cin>>ch;
	  	switch(ch)
	  	{
			case '1':
				 	int n;
				 	cout<<"ENTER 1 TO ADD BATSMEN AND 2 TO ADD BOWLER  :    ";
				 	cin>>n;
				 	switch(n)
				 	{
				 		case 1:
				 			p1.information_batsman();
				 			p1.add_player_bat();
				 			break;
				 		case 2:
				 			p2.information_bowler();
				 			p2.add_player_bowl();
				 			break;
				 		default:
				 			cout<<"\n************INVALID INPUT*******************";

							 			 }
			   	 break;
		  	case '2':p1.display_allbat();
			    	 break;
		  	case '3':p2.display_allbowl();
				 break;
		  	case '4':int k;
			  		 cout<<"ENTER 1 TO DELETE BATSMEN AND 2 TO DELETE BOWLER :    ";
			  		 cin>>k;
			  		 switch(n)
			  		 {
			  		 	case 1 : p1.del_batsmen();
			  		 	break;
			  		 	case 2: p2.del_bowler();
			  		 	break;
			  			default:
				 		cout<<"\n************INVALID INPUT*******************";

					   }
				case '5':k=0;
			  		 cout<<"ENTER 1 TO SEARCH BATSMEN AND 2 TO SEARCH BOWLER :    ";
			  		 cin>>k;
			  		 switch(n)
			  		 {
			  		 	case 1 : p1.search_batsmen();
			  		 	break;
			  		 	case 2: p2.search_bowler();
			  		 	break;
			  			default:
				 		cout<<"\n************INVALID INPUT*******************";

					   }
				case '6':k=0;
			  		 cout<<"ENTER 1 TO MODIFY BATSMEN AND 2 TO MODIFY BOWLER :    ";
			  		 cin>>k;
			  		 switch(n)
			  		 {
			  		 	case 1 : p1.modify_batsmen();
			  		 	break;
			  		 	case 2: p2.modify_bowler();
			  		 	break;
			  			default:
				 		cout<<"\n************INVALID INPUT*******************";

					   }
				case '7':
						{
							f.open("schedule.txt",ios::in);
							string line;
							cout<<"\n\n\n\n";
							while(!f.eof())
							{
								getline(f,line);
								cout<<"\t"<<line<<endl;
								}
							f.close();
						}
							break;
				case '8':
					{
						f.open("teams.txt",ios::in);
						string lin;
						cout<<"\n\n\n";
						while(!f.eof())
						{
							getline(f,lin);
							cout<<"\t"<<lin<<endl;
						}
						f.close();
						
					}
				default :cout<<"\a";
		}
    	}while(ch!='9');
}


