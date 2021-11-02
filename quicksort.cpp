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
void QuickSort1(int a[], int left, int right)
{
	int x=a[(left+right)/2];
	int i=left,j=right;
	
	do{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if(i<=j)
		{
			swap (a[i],a[j]);
			i++;
			j--;
		}
	}
	while(i<j);
	
	if(left<j)
	{
		QuickSort1(a,left,j);
	}
	if(right>i)
	{
		QuickSort1(a,i,right);
	}
}
//giam
void QuickSort2(int a[], int left, int right)
{
	int x=a[(left+right)/2];
	int i=left,j=right;
	
	do{
		while (a[i] > x)
			i++;
		while (a[j] < x)
			j--;
		if(i<=j)
		{
			swap (a[i],a[j]);
			i++;
			j--;
		}
	}
	while(i<j);
	
	if(left<j)
	{
		QuickSort2(a,left,j);
	}
	if(right>i)
	{
		QuickSort2(a,i,right);
	}
}
int main()
{
	int n,a[50];
	cout<<"\nNhap so luong phan tu: ";
	cin>>n;
	nhap(a,n);
	QuickSort1(a,0,n-1);
	xuat(a,n);
	QuickSort2(a,0,n-1);
	cout<<endl;
	xuat(a,n);
}
