#include<iostream>
using namespace std;
class Sorting
{
public:
    int a[10],n,i,j,temp;

    void input();
    void output();
    void BubbleSort();
    void MergeSort(int[],int,int);
    void Merge(int[],int,int,int);
    void QuickSort(int[],int,int);
    int Quick(int[],int,int);
    void SelectionSort();
    void InsertionSort();

};
void Sorting::input()
{
    cout<<endl<<"Enter length of an array :";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter element : ";
        cin>>a[i];
    }
}
void Sorting::output()
{
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}
void Sorting::BubbleSort()
{
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout<<"Array is sorted!";
}
void Sorting::MergeSort(int a[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low+high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        Merge(a, low, high, mid);
    }
}
void Sorting::Merge(int a[], int low, int high, int mid)
{
    int k;
    int temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
void Sorting::QuickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pivot = Quick(a, low, high);
        QuickSort(a, low, pivot-1);
        QuickSort(a, pivot+1, high);
    }
}
int Sorting::Quick(int a[], int low, int high)
{
    int pivot = a[high];
    int i=low-1;
    int j=0;
    for(j=low;j<=high-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;
    return (i+1);
}
void Sorting::SelectionSort()
{
    int mini;
    for(i=0;i<n-1;i++)
    {
        mini = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[mini])
            {
                mini = j;
                temp = a[i];
                a[i] = a[mini];
                a[mini] = temp;
            }
        }
    }
    cout<<"Array is sorted!";
}
void Sorting::InsertionSort()
{
    for(i=1;i<n;i++)
    {
        temp = a[i];
        j= i-1;
        while((temp<a[j]) && (j>=0))
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    cout<<"Array is sorted.!";
}
int main()
{
    Sorting s;
    int ch;
    do
    {
        cout<<endl<<"1.Input"<<endl<<"2.Output"<<endl<<"3.Bubble Sort"<<endl<<"4.Merge Sort"<<endl;
        cout<<"5.Quick Sort"<<endl<<"6.Selection Sort"<<endl<<"7.Insertion Sort"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 0:
                break;
            case 1:
                s.input();
                break;
            case 2:
                s.output();
                break;
            case 3:
                s.BubbleSort();
                break;
            case 4:
                s.MergeSort(s.a,0,s.n-1);
                cout<<"Array is sorted!";
                break;
            case 5:
                s.QuickSort(s.a,0,s.n-1);
                cout<<"Array is sorted!";
                break;
            case 6:
                s.SelectionSort();
                break;
            case 7:
                s.InsertionSort();
                break;
        }
    }while(ch != 0);
}
