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
void BubbleSort1(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
}
//giam
void BubbleSort2(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
}
int main()
{
	int n,a[50];
	cout<<"\nNhap so luong phan tu: ";
	cin>>n;
	nhap(a,n);
	BubbleSort1(a,n);
	xuat(a,n);
	BubbleSort2(a,n);
	cout<<endl;
	xuat(a,n);
}
