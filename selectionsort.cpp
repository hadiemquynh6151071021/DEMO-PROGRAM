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
void SelectionSort1(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int minV=a[i], pMin=i;
		for(int j=i+1;j<n;j++)
		{
			if(minV>a[j])
			{
				minV=a[j];
				pMin=j;
			}
		}
		if(i!=pMin)
		{
			swap(a[i],a[pMin]);
		}
	}
}
//giam
void SelectionSort2(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int maxV=a[i], pMax=i;
		for(int j=i+1;j<n;j++)
		{
			if(maxV<a[j])
			{
				maxV=a[j];
				pMax=j;
			}
		}
		if(i!=pMax)
		{
			swap(a[i],a[pMax]);
		}
	}
}
int main()
{
	int n,a[50];
	cout<<"\nNhap so luong phan tu: ";
	cin>>n;
	nhap(a,n);
	SelectionSort1(a,n);
	xuat(a,n);
	SelectionSort2(a,n);
	cout<<endl;
	xuat(a,n);
}
