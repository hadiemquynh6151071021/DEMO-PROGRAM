#include <iostream>
using namespace std;
//nhap
void nhap(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nNhap a["<<i<<"]=";
		cin>>a[i];
	}
}
//xuat
void xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
//swap
void Swap(int a,int b)
{
	int t=a;
	a=b;
	b=t;
}
//tang
void InsertionSort1(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int x=a[i];
		int j=i-1;
		while(j>=0 && a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
//giam
void InsertionSort2(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int x=a[i];
		int j=i-1;
		while(j>=0 && a[j]<x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
int main()
{
	int n,a[50];
	cout<<"\nNhap so luong phan tu: ";
	cin>>n;
	nhap(a,n);
	InsertionSort2(a,n);
	xuat(a,n);
	//SelectionSort2(a,n);
	//cout<<endl;
	//xuat(a,n);
}
