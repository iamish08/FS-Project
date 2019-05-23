#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>
#define filename "hotel2.txt"
fstream ifile;
char allroom[100][5],knodes[100][100];
int totroom=0,count=0,indsize=0;
class hotel
{
	char room_no[5],name[20],phone[15],email[25],checkindate[20];
	public:
		void opener(fstream &file,char *fn,int mode);
		void read();
		void pack();
		void unpack();
		void display();
		int search();
		void update(int);
		void deleteRec(int);
		void index();
		void secondary();
		void InvertPrimary();
		void Invertsecondary();
		void Invertsecondarysort();
		void CheckDup();
		void KeySort();
		void InvertSecondarySort();
		int InvertSecondSearch(char *);
		int Binary(char *);
		void indexdisplay(char *);
}h;
void hotel::index()
{
	int size=0;
	char iroom[5]="",Ibuff[100]="";
	count=0;
	ifstream ofile(filename,ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("prim.txt",ios::out);
	if(ofile.fail())
		cout<<"\n\n\nFile does not exist";
	else
	{
		while(1)
		{
				ofile.getline(Ibuff,100,'#');
				if(ofile.fail())
					break;
				if(Ibuff[0]!='$')
				{
				for(int i=0;Ibuff[i]!='|';i++)
					iroom[i]=Ibuff[i];
				count++;
				nfile.seekp(size);
				nfile<<iroom<<"|"<<count<<"|";
				size=size+15;
				}	}
	}
	nfile.close();
	ofile.close();

}
void hotel::KeySort()
{
char Buffer[15],str1[15]="",str2[15]="";
int length=15,ptr,i=0;
fstream file("indo.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	file.read(Buffer,length);
		if(file.fail())
			break;
		for(int j=0;j<15;j++)
			knodes[i][j]=Buffer[j];
		i++;
}

for(int j=0;j<15;j++)
knodes[i][j]=Buffer[j];
file.close();

for(i=0;i<count;i++)
{
	for(int m=0;m<15;m++)
	str1[m]=knodes[i][m];
	j=i-1;
	a:
	for(m=0;m<15;m++)
	str2[m]=knodes[j][m];
	ptr=strnicmp(str1,str2,10);
	while(j>=0&&ptr<0)
	{
	     for(m=0;m<15;m++)
	     knodes[j+1][m]=knodes[j][m];
	     j--;
	 goto a;
	}

	for(m=0;m<15;m++)
	knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];
}

void hotel::secondary()
{
	int size=0;
	char rooms[5]="0",name[20]="0",Buffer[100]="";
	count=0;
	ifstream ofile(filename,ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("dusri.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.getline(Buffer,100,'#');
			 if(ofile.fail())
			  break;
			 if(Buffer[0]!='$')
			 {
	       int j=0;

	       for(int i=0;Buffer[i] != '|';i++)
			rooms[j++]=Buffer[i];
	       rooms[j]='\0';
	       i++;

	       for(j=0;Buffer[i]!='|' ;i++)
		       name[j++]=Buffer[i];
	       name[j]='\0';

			 count++;
			 nfile.seekp(size);
			 nfile<<name<<"|"<<rooms<<"|"<<"#";
			 size=size+30;
		  }       }
	 nfile.close();
	 ofile.close();
}

void hotel::InvertPrimary()
{
int size=0;
	char rooms[5]="0",IBuff[100]="";
	count=0;
	ifstream ofile(filename,ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("prim1.txt",ios::out);
	if(ofile.fail())
		 cout<<"\n\nfile not exist\n\n";
	else
		 while(1)
		  {
			 ofile.getline(IBuff,100,'#');
			 if(ofile.fail())
			  break;
			  if(IBuff[0] != '$')
			  {
			 for(int i=0;IBuff[i]!='|';i++)
			 rooms[i]=IBuff[i];
			 count++;
			 nfile.seekp(size);
			 nfile<<count<<"|"<<rooms<<"|"<<-1<<"|";
			 size=size+25;
			 }
		  }

	 nfile.close();
	 ofile.close();
}
void hotel::Invertsecondary()
{
int size=0;
	char rooms[5]="0",IBuff[100]="",name[20]="";
      count=0;
	ifstream ofile(filename,ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("dusri1.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.getline(IBuff,100,'#');
			 if(ofile.fail())
				  break;
			if(IBuff[0] != '$')
			{
			 for(int i=0;IBuff[i]!='|';i++)
				 rooms[i]=IBuff[i];
			 i++;

			 for(int k=0;IBuff[i]!='|';i++)
				name[k++]=IBuff[i];
			 name[k]='\0';
			 count++;
			 nfile.seekp(size);
			 nfile<<name<<"|"<<count<<"|";
			 size=size+25;
		  }
	}
	 nfile.close();
	 ofile.close();
}
void hotel::Invertsecondarysort()
{
char Buffer[25],str1[30]="",str2[30]="";
int length=25,ptr,i=0;
fstream file("dusri1.txt",ios::in);
file.seekg(0,ios::beg);
for(int j=0;j<25;j++)
knodes[i][j]='\0';
while(1)
{
	for(int j=0;j<25;j++)
		Buffer[j]='\0';
	file.read(Buffer,length);

	if(file.fail())
		break;

	for( j=0;j<25;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

for( j=0;j<25;j++)
	knodes[i][j]=Buffer[j];

file.close();

for(i=0;i<count;i++)
{      j=0;
	for(int m=0;m<25;m++)
		str1[m]=knodes[i][m];
	j=i-1;
	a:
	for(m=0;m<25;m++)
		str2[m]=knodes[j][m];
		ptr=strnicmp(str1,str2,10);

	while(j>=0&&ptr<0)
	{
	     for(m=0;m<25;m++)
		    knodes[j+1][m]=knodes[j][m];
	     j--;
	goto a;
	}

	for(m=0;m<25;m++)
		knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];
}
void hotel::CheckDup()
{
	  int found,size=0,length=100;
	  char nname[25]="",kname[20]="",ind1[5]="",room[5]="",klen[5]="",*endptr,Buffer[100]="",ukk[15]="",pbuff[15];
	  hotel sss;
	  fstream sfile3("dusri3.txt",ios::out);
	  sfile3.seekp(0,ios::beg);
	  fstream ffile("dusri2.txt",ios::out);
	  ffile.seekp(0,ios::beg);
	  fstream file("dusri1.txt",ios::in|ios::out);
	  file.seekg(0,ios::beg);
	   found=count;
	  int i=0;
	  while(i<count)
	  {
	 // int l=0;
		 for(int m=0;m<20;m++)
			 kname[m]='\0';
		 for(int j=0;knodes[i][j]!='|';j++)
			 kname[j]=knodes[i][j];
		 j++;

		for(int n=0;knodes[i][j]!='|';j++)
			 klen[n++]=knodes[i][j];


		int p=strlen(kname);
		int  ptr=strnicmp(kname,nname,p);

		if(ptr==0)
		{
		ffile<<klen<<"|";
		 fstream pfile("prim.txt",ios::in);
		while(1)
		{
			//ind[j]='\0';
			if(pfile.fail())
				break;
			pfile.read(pbuff,15);
			for(int l=0;pbuff[l]!='|';l++)
				room[l]=pbuff[l];
			room[l]='\0';
			l++;
			for(int m=0;pbuff[l]!='|';l++)
			{
				ind1[m]=pbuff[l];
				m++;   }
		      //	ind1[m]='\0';
			if(strcmpi(klen,ind1)==0)
			{
				sfile3<<room<<"|";
				break;
		}
	}
		found=found+1;
		}

	       if(ptr>0)
		 {
			ffile.seekp(size);
			sfile3.seekp(size);
			strcpy(nname,kname);
			ffile<<kname<<"|"<<klen<<"|";
			 fstream pfile("prim.txt",ios::in);
		while(1)
		{
			//ind[j]='\0';
			if(pfile.fail())
				break;
			pfile.read(pbuff,15);
			for(int l=0;pbuff[l]!='|';l++)
				room[l]=pbuff[l];
			room[l]='\0';
			l++;
			for(int m=0;pbuff[l]!='|';l++)
			{
				ind1[m]=pbuff[l];
				m++;   }
		      //	ind1[m]='\0';
			if(strcmpi(klen,ind1)==0)
			{
				sfile3<<kname<<"|"<<room<<"|";
				break;
		} 
	}
			
			
			size=size+30;
		 }

		i++;
	     found--;
	}
  ffile.close();
  file.close();
}
void hotel::InvertSecondarySort()
{
char Buffer[30],str1[30]="",str2[30]="";
int length=30,ptr,i=0;
fstream file("dusri3.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	for(int m=0;m<30;m++)
		Buffer[m]='\0';
	file.read(Buffer,length);
	if(file.fail())
		break;

	for(int j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

	for(int j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	file.close();

for(i=0;i<count;i++)
{     j=0;
	for(int m=0;m<30;m++)
		str1[m]=knodes[i][m];
	j=i-1;
	a:

	for(m=0;m<30;m++)
		str2[m]=knodes[j][m];
	ptr=strnicmp(str1,str2,10);

	while(j>=0&&ptr<0)
	{
	     for(m=0;m<30;m++)
		     knodes[j+1][m]=knodes[j][m];
	     j--;
	 goto a;
	}

	for(m=0;m<30;m++)
		knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];

for(i=0;i<count;i++)
	 for(j=0;j<30;j++)
		cout<<knodes[i][j];
}

int  hotel::InvertSecondSearch(char *key)
{
clrscr();
char str1[30]="";
int found=0;
char Buffer[30];
int length=30,ptr,i=0;
fstream file("dusri3.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	for(int m=0;m<0;m++)
		Buffer[m]='\0';
	file.read(Buffer,length);
	if(file.fail())
	break;
	for(int j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

for(int j=0;j<30;j++)
knodes[i][j]=Buffer[j];

for( i=0;i<count;i++)
{
 for(int j=0;knodes[i][j]!='|';j++)
     str1[j]=knodes[i][j];
     str1[j]='\0';
     int l=strlen(key);
     int ptr=strnicmp(str1,key,l);
     if(ptr==0)
     {
	found=1;
	break;
	 }
 }

if(found==1)

{
	for(int j=0;j<30;j++)
		cout<<knodes[i][j];
return 1;
}
	else
		return -1;
}

int hotel::Binary(char *key)
{
 int mid=0,k,ptr1,low,high,i=0;
 low=0;
 high=count-1;
 char nname[20]="",recaddr[10],*endptr;
 int l=strlen(key);
    while(1)
	  {         for(int j=0;j<15;j++)
			nname[j]='\0';
		mid=(low+high)/2;

		if(low>high)
			return -1;

		for(i=0;knodes[mid][i]!='|';i++)
			nname[i]=knodes[mid][i];
		i++;

		for(int n=0;knodes[mid][i]!='|';i++)
			recaddr[n++]=knodes[mid][i];

		int num=strtol(recaddr,&endptr,10);
		ptr1 = strnicmp(nname,key,l);

		if (ptr1 > 0)
		      high=mid-1;
		else if (ptr1 < 0)
			   low=mid+1;
		else if(ptr1==0)
		return num;

	}
}

void hotel::opener(fstream &file,char *fn,int mode)
{
	file.open(fn,mode);
	if(!file)
	{
		cout<<"Unable to open file!!";
		getch();
		exit(10);
	}
}
int searchDup(char rooms[5])
{
	int found=0;
	for(int i=0;i<totroom;i++)
	{
		if(strcmpi(allroom[i],rooms) == 0)
		{
			found=1;break;
			}
	}
	return found;
}
void hotel::read()
{
	cout<<"\n\n\n";
	cout<<"Enter the Room Number : ";
	gets(room_no);
	while(searchDup(room_no))
	{
		cout<<"\n\nDuplicate Entry please enter room number again : ";
		gets(room_no);
	}
	strcpy(allroom[totroom],room_no);
	//allroom[totroom]=room_no;
	totroom++;
	cout<<"\n\nEnter the Name : ";
	gets(name);
	cout<<"\n\nEnter the Phone Number : ";
	gets(phone);
	cout<<"\n\nEnter the Email address : ";
	gets(email);
	cout<<"\n\nEnter the Check in Date(dd/mm/yy) : ";
	gets(checkindate);
	pack();
	clrscr();
}
void hotel::pack()
{
	char buffer[100];
	strcpy(buffer,room_no);		strcat(buffer,"|");
	strcat(buffer,name);		strcat(buffer,"|");
	strcat(buffer,phone);		strcat(buffer,"|");
	strcat(buffer,email);		strcat(buffer,"|");
	strcat(buffer,checkindate);	strcat(buffer,"|");
	ifile<<buffer<<"#";
}
void hotel::unpack()
{
	char dummy[100];
	ifile.getline(room_no,5,'|');
	ifile.getline(name,20,'|');
	ifile.getline(phone,15,'|');
	ifile.getline(email,25,'|');
	ifile.getline(checkindate,20,'|');
	ifile.getline(dummy,100,'#');
}
void hotel::display()
{
	while(1)
	{
		unpack();
		if(ifile.eof())
			break;
		if(room_no[0] != '$')
		{
		cout<<"\n\n\n\n\n";
		cout<<"\tRoom Number       : "<<room_no;
		cout<<"\n\n\tName          : "<<name;
		cout<<"\n\n\tPhone         : "<<phone;
		cout<<"\n\n\tEmail         : "<<email;
		cout<<"\n\n\tCheck in Date : "<<checkindate;

		getch();
		clrscr();
		}
	}
}
int hotel::search()
{
	char sroom_no[5],dummy[100];
	int flag;
	fstream nfile(filename,ios::in);
	cout<<"\n\nList of rooms currently alloted : \n\n";
	while(!nfile.eof())
	{
		char rooms[5];
		nfile.getline(rooms,5,'|');
		nfile.getline(dummy,100,'#');
		if(rooms[0] != '$')
		cout<<rooms<<"\t";
	}
	nfile.close();
	char ch='y';
	cout<<"\n\nDo you still want to update or delete?(y or n)\n\n";
	cin>>ch;
	if(ch == 'n' || ch == 'N')
		return -1;
	cout<<"\n\nEnter the room number : ";
	gets(sroom_no);
	while(!ifile.eof())
	{
		flag=ifile.tellg();
		unpack();
		if(strcmpi(room_no,sroom_no)==0)
		{
			cout<<"\n\nRecord found!!";
			return flag;
		}
	}
	return -1;
}
void hotel::update(int flag)
{
	ifile.seekp(flag,ios::beg);
	ifile.put('$');
	ifile.seekp(0,ios::end);
	read();
	clrscr();
}
void hotel::indexdisplay(char *key)
{
	int f=1;
	fstream ffile(filename,ios::in);
	while(1)
	{

		if(ffile.fail())
			break;
		//unpack();
		char dummy[100];
		ffile.getline(room_no,5,'|');
		ffile.getline(name,20,'|');
		ffile.getline(phone,15,'|');
		ffile.getline(email,25,'|');
		ffile.getline(checkindate,20,'|');
		ffile.getline(dummy,100,'#');

		if(strcmpi(key,room_no)==0)
		{
			f=0;
			cout<<"\n\n\n\n\n\t\t\t\tRoom No : "<<room_no;
			cout<<"\n\n\t\t\t\tName : "<<name;
			cout<<"\n\n\t\t\t\tPhone : "<<phone;
			cout<<"\n\n\t\t\t\tEmail : "<<email;
			cout<<"\n\n\t\t\t\tCheck in date :"<<checkindate;
			getch();
		}
	}
	if(f)
	{
		cout<<"\nkey not found...";
	}
}
void hotel::deleteRec(int flag)
{
	ifile.seekg(flag,ios::beg);
	ifile.put('$');
	cout<<"\n\nRecord deleted!";
}
void screen()
{
	int ch;
	int flag;
	clrscr();
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\tHotel Records Implementation";
	cout<<"\n\n\t\t1.Read";
	cout<<"\n\n\t\t2.Display";
	cout<<"\n\n\t\t3.Update";
	cout<<"\n\n\t\t4.Delete";
	cout<<"\n\n\t\t5.Exit";
	cout<<"\n\n\t\tEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1 : h.opener(ifile,filename,ios::app);
			 clrscr();
			 h.read();
		    //	 screen();
			 break;
		case 2 : h.opener(ifile,filename,ios::in);
			 clrscr();
			 h.display();
		   //	 screen();
			 break;
		case 3 : h.opener(ifile,filename,ios::in|ios::out|ios::nocreate);
			 clrscr();
			 flag=h.search();
			 clrscr();
			 if(flag == -1)
				cout<<"\n\nRecord Not found or you backed out try again!";
			 else
				h.update(flag);
		     //	 screen();
			 break;
		case 4 : h.opener(ifile,filename,ios::in|ios::out);
			 clrscr();
			 flag=h.search();
			 if(flag == -1)
				cout<<"\n\n\nRecord not found! press enter to continue...";
			 else
				h.deleteRec(flag);
			 getch();
			 clrscr();
		    //	 screen();
			 break;
		case 5 : return;
			 break;
		default :screen();

	}
	h.index();
	h.secondary();
/*	h.InvertPrimary();
	h.Invertsecondary();
	h.Invertsecondarysort();
	h.CheckDup();
	h.secsort3();	*/
	ifile.close();
}
void screen2()
{
	hotel s;
	int a,choice;
	char *key;
	clrscr();

	cout<<"\n\n\n\n\n\n\n\n\t\t\t\tInverted List Indexing";
	cout<<"\n\n\t\t\t1. Indexing";
	cout<<"\n\n\t\t\t2. Exit";
	cout<<"\n\n\t\t\tEnter your choice : ";
	cin>>choice;
	switch(choice)
	{
	case 1: s.InvertPrimary();
	s.Invertsecondary();
	s.Invertsecondarysort();
	s.CheckDup();
//	s.secsort3();
	clrscr();
	cout<<"\n\n\tEnter the Secondary key: ";
	cin>>key;
	a=s.Binary(key);
	if(a==-1)
	{
	cout<<"\n\n\tRecord not found....!";}
	s.InvertSecondarySort();
	int b=s.InvertSecondSearch(key);
	if(b==1)
	{
	s.index();
	s.KeySort();
	cprintf("Enter the Primary key: ");
	cin>>key;
	s.indexdisplay(key);
       }
       //screen2();
       break;
       case 2 : return;
       default : return;
	 }
}
void main()
{
 int choice;
 clrscr();
 for(;;)
 {
	cout<<"\n\n\n\n\n\t**********************************************************";
	cout<<"\n\n\t\t\t\tHotel Record System\n\n";
	cout<<"\t\t\t1. Hotel Record";
	cout<<"\n\n\t\t\t2. Inverted List ";
	cout<<"\n\n\t\t\t3. Exit";
	cout<<"\n\n\t**********************************************************";
	cout<<"\n\n\t\t\tEnter choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1 : screen();
			 clrscr();
			 break;
		case 2 : screen2();
			 clrscr();
			 break;
		default :exit(0);
	}
 }

 getch();
}
