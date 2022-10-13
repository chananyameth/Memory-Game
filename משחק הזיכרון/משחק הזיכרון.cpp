#include<iostream>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class yeshno
{
	bool** arr;
	int len;
	bool male;
public:
	bool is_male()
	{
		return male;
	}
	void set(int x, int y)
	{
		male=0;
		arr = new bool*[y];
		for(int i=0; i<x; ++i)
			arr[i] = new bool[x];
		for(int i=0; i<y; ++i)
			for(int j=0; j<x; ++j)
				arr[j][i] = false;
		len = x*y;
	}
	void insert(int x, int y)
	{
		static int i=0;
		++i;
		if(i == len)
			male = 1;
		arr[y-1][x-1] = true;
	}
	bool there_is(int x, int y)
	{
		return arr[y][x];
	}
};
char** hatzava(char** arr, int x, int y)
{
	char* a=new char[x*y];
	char c=1;
	int temp, mikum1, mikum2;

	for(int i=0; i<y; ++i)
		a[i]=NULL;
	for(int i=0; i<x*y; i+=2, (c==6?c=14:c++))
	{
		a[i]=a[i+1]=c;
	}
	for(int i=0; i<x*y; ++i)
	{
		mikum1 = rand() % (x*y);
		mikum2 = rand() % (x*y);
		temp = a[mikum1];
		a[mikum1] = a[mikum2];
		a[mikum2] = temp;
	}
	for(int i=0,i_a=0; i<y; ++i)
		for(int j=0; j<x; ++j, ++i_a)
			arr[i][j]=a[i_a];
	delete[] a;
	return arr;
}
void print(int x, int y)
{
	cout<<"  ";
	for(int i=1; i<=x; ++i)
		cout<<i;
	cout<<endl;
	for(int i=1; i<=y; ++i)
	{
		cout<<i<<" ";
		for(int j=0; j<x; ++j)
			cout<<(char)219;
		cout<<endl;
	}
}
void print(char** arr,int x, int y, int x1, int y1, int x2, int y2, yeshno& yesh)
{
	system("CLS");
	if(yesh.is_male())
		throw ("very good!!!");
	cout<<"("<<y1<<","<<x1<<")  "<<"("<<y2<<","<<x2<<")\n";
	cout<<"  ";
	for(int i=1; i<=x; ++i)
		cout<<i;
	cout<<endl;
	for(int i=0; i<y; ++i)
	{
		cout<<i+1<<" ";
		for(int j=0; j<x; ++j)
		{
			if(yesh.there_is(i,j))
				cout<<arr[i][j];
			else if((i+1==y1 && j+1==x1) || (i+1==y2 && j+1==x2))
				cout<<arr[i][j];
			else
				cout<<(char)219;
		}
		cout<<endl;
	}
	Sleep(4000);
	system("CLS");
	if(arr[y1-1][x1-1] != arr[y2-1][x2-1])
	{
		print(x,y);
	}
	else
	{
		cout<<"good!";
		Sleep(1000);
		system("CLS");
		yesh.insert(x1,y1);
		yesh.insert(x2,y2);
	}
}
void input_len(int& x,int& y)
{
	bool flag=1;
	do
	{
		if(!flag) cout<<"Error!\n";
		cout<<"Enter mispar turim:	";
		cin>>x;
		cout<<"Enter mispar shurot:	";
		cin>>y;
		cout<<endl;
		flag = ((x*y)%2 == 0) ? 1 : 0;
		if(x == 0 || y == 0)
			flag=false;
	}while(!flag);
}
void input_points(int x, int y, int& x1,int& y1, int& x2,int& y2)
{
	bool flag=1;
	do
	{
		if(!flag) cout<<"Error!\n";
		cout<<"enter point number 1 (shura, and tur):\n";
		cin>>y1>>x1;
		flag = ((x1<x+1) && (y1<y+1) && (x1>0) && (y1>0)) ? 1 : 0;
	}while(!flag);
	do
	{
		if(!flag) cout<<"Error!\n";
		cout<<"enter point number 2 (shura, and tur):\n";
		cin>>y2>>x2;
		flag = ((x2<x+1) && (y2<y+1) && (x2>0) && (y2>0)) ? 1 : 0;
	}while(!flag);
}
void main()
{
	try
	{
		system("chcp 1255");
		srand(time(NULL));
		char** arr;
		yeshno yesh;
		int x,y;
		int x1,y1,x2,y2;
		bool flag=1;

		input_len(x,y);
		yesh.set(x,y);

		arr = new char*[y];
		for(int i=0; i<y; ++i)
			arr[i] = new char[x];

		print(x,y);
		arr = hatzava(arr,x,y);
		while(1)
		{
			input_points(x,y,x1,y1,x2,y2);
			print(arr,x,y,x1,y1,x2,y2,yesh);
		}
	}
	catch(string s)
	{
		cout<<s;
	}
	system("pause");
}
/*
char** hatzava(char** arr, int x, int y)
{
	char* a = new char[(x*y)+1];
	int ran;
	bool ThereIs_1=false, ThereIs_2=false;

	for(int i=0; i<(x*y); ++i)
	{
		if((!ThereIs_1) && (!ThereIs_2))
		{
			ran = (rand()%26) + 97;
			ThereIs_1 = false;
			ThereIs_2 = false;
		}
		for(int j=0; j<i; ++j)
		{
			if(a[i] == ran)
			{
				if(ThereIs_1)
					ThereIs_2 = true;
				ThereIs_1 = true;
			}
		}
		a[i] = ran;
	}
	for(int i=0; i<y; ++i)
	{
		for(int j=0; j<x; ++j)
		{
			ran = rand() % (x*y);
			a[ran] ? (arr[i][j]=a[ran], a[ran]=NULL) : (j ? --j : (--i, j=y-1));
		}
	}
	delete[] a;
	return arr;
}
void print(char** arr,int x, int y, int x1, int y1, int x2, int y2)
{
	system("CLS");
	cout<<"("<<x1<<","<<y1<<")  "<<"("<<x2<<","<<y2<<")\n";
	for(int i=y; i>0; --i)
	{
		for(int j=x; j>0; --j)
		{
			if((i==x1 && j==y1) || (i==x2 && j==y2))
				cout<<arr[y-i][x-j];
			else
				cout<<(char)219;
		}
		cout<<" "<<i;
		cout<<endl;
	}
	for(int i=x; i>0; --i)
		cout<<i;
	cout<<endl<<endl;
}
void print(int x, int y)
{
	for(int i=y; i>0; --i)
	{
		for(int j=0; j<x; ++j)
			cout<<(char)219;
		cout<<" "<<i;
		cout<<endl;
	}
	for(int i=x; i>0; --i)
		cout<<i;
	cout<<endl<<endl;
}
*/