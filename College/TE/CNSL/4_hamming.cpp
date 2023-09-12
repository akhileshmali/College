/*Write a program for error detection and correction for 7/8 bits ASCII codes using Hamming Codes or CRC*/
#include<iostream>

using namespace std;
void conv(int x,int y,int z)
{
    int binaryNumber[3];
    int decimalNumber = 0, i = 0, remainder;
    binaryNumber[0]=x;
    binaryNumber[1]=y;
    binaryNumber[2]=z;

    for (i = 0; i < 3; i++) {
        decimalNumber += binaryNumber[i] << (2 - i);
    }
    int sum = 0;
    for (i = 0; i < 3; i++) {
        sum += binaryNumber[i];
    }
    cout << "Error at bit position " << decimalNumber << endl;
}

int main()
{
	int data[7]={0};
	cout<<"Enter 1st data bit "<<endl;
	cin>>data[0];//d7
	cout<<"Enter 2nd data bit "<<endl;
	cin>>data[1];//d6
	cout<<"Enter 3rd data bit "<<endl;
	cin>>data[2];//d5
	cout<<"Enter 4th data bit "<<endl;
	cin>>data[4];//d3	
	data[3]=data[0]^(data[1]^data[2]); //p4
	data[5]=data[0]^(data[1]^data[4]); //p2
	data[6]=data[0]^(data[2]^data[4]); //p1
	for(int i=0;i<7;i++)
	{
		cout<<data[i];
	}	
	int rec[7]={0};
	cout<<endl;
	for(int i=0;i<7;i++)
	{
		cout<<"Enter received data bits from MSB "<<endl;
		cin>>rec[i];
	}
	int p4=rec[0]^(rec[1]^rec[2]); //p4
	int p2=rec[0]^(rec[1]^rec[4]); //p2
	int p1=rec[0]^(rec[2]^rec[4]); //p1
	if(p4!=data[3] || p2!=data[5] || p1!=data[6])
	{
		cout<<"Error !!!!"<<endl;
		int a = (rec[0]+rec[1]+rec[2]+rec[3])%2;
		int b = (rec[0]+rec[1]+rec[4]+rec[5])%2;
		int c = (rec[0]+rec[2]+rec[4]+rec[6])%2;
		conv(a,b,c); 	
	} 
}

