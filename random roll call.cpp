#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream.h>
using namespace std;
struct student_id{
	char name[100];
	char classes[100];
	char id_num[100];
}stu[1000],temp;
char str1[100],str2[100],str3[100];
int r,t=0,p,delay_time=2000;
void init()
{
	ifstream in("student_data.txt");
	if(!in.is_open()) return;
	else
	{
		while(!in.eof())
		{
			p=0;
			in.getline(stu[t].name,100); if(in.eof()) break;else p++;
			in.getline(stu[t].classes,100); if(in.eof()) break;else p++;
			in.getline(stu[t].id_num,100); if(in.eof()) break;else p++;
			t++;
		}
	}
}
void delay_msec(int msec)        
{   
    clock_t now = clock();  
    while(clock()-now < msec);  
}  
void table()
{
	cout<<"			Random roll call system"<<endl;
	cout<<"1:Input students' information"<<endl;
	cout<<"2:Random roll call"<<endl;
	cout<<"3:Settings"<<endl;
	cout<<"4:Quit the system"<<endl;
	cout<<"by HYF"<<endl;
}
void input_data()
{
	cout<<"The current student's amount: "<<t+1<<endl;
	cout<<"1:Student's name:"<<endl;
	cin>>stu[t].name;
	cout<<"2:Student's class"<<endl;
	cin>>stu[t].classes;
	cout<<"3:Student's id_number"<<endl;
	cin>>stu[t].id_num;
	ofstream out("student_data.txt",ios::app);
	if(out.is_open())
	{
		out<<stu[t].name<<endl;
		out<<stu[t].classes<<endl;
		out<<stu[t].id_num<<endl;
		out.close();
	}
	t++;
}
void setings()
{
	cout<<"please set the delay time(the origin one is 2000ms)"<<endl;
	cin>>delay_time;
}
void random_roll_call()
{
	r=rand()%t;
	cout<<"THE UNLUCKY ONE IS:"<<endl;
	cout<<stu[r].classes<<endl;
	cout<<stu[r].name<<endl;
	cout<<stu[r].id_num<<endl; 
	delay_msec(delay_time);
}
int main(int argc,char **argv)
{
	t=0;
	init();
	srand((unsigned)time(NULL));
	while(1)
	{
		table();
		cin>>r;
		switch(r)
		{
			case 1:
			{
				system("cls");
				input_data();
				break;
			}
			case 2:
			{
				system("cls");
				random_roll_call();
				break;
			}
			case 4:
			{
				return 0;
			}
		}
		system("cls");
	}   
	return 0;
} 
