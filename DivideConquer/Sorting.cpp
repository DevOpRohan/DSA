#include <iostream>
using namespace std;

int selection(int *arr, int n); //SelectionSort

int InsertionSort(int *arr, int n); //InsertionSort

int bubbleSort(int *arr, int n); //BubbleSort

int merge(int l, int mid, int u, int *arr);
int MergeSort(int l, int u, int *arr);      //MergeSort

int QuickSort(int l, int u, int *arr);      //QuickSort
int partition(int l, int u, int *arr);


void display(int *arr, int n);
int swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
    return 0;
}

int main()
{
    int n;
    cout << "Enter the size of array:- " << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        // cout << "Enter the " << i + 1 << "th element:- ";
        cin >> arr[i];
    }
    display(arr, n);
    // selection(arr, n);
    // MergeSort(0, n - 1, arr);
    // QuickSort(0, n - 1, arr);
    // InsertionSort(arr, n);
    bubbleSort(arr,n);
    display(arr, n);
    return 0;
}

//SelectionSort
int selection(int *arr, int n) //Select a position and finding the correct element for it
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    return 0;
}

//MergeSort
int merge(int l, int mid, int u, int *arr)
{
    int temp[u - l + 1];
    int i = 0, j = l, k = mid + 1;
    while (j <= mid && k <= u)
    {
        if (arr[j] < arr[k])
        {
            temp[i] = arr[j];
            j++;
        }
        else
        {
            temp[i] = arr[k];
            k++;
        }
        i++;
    }

    while (j <= mid)
    {
        temp[i] = arr[j];
        j++;
        i++;
    }

    while (k <= u)
    {
        temp[i] = arr[k];
        k++;
        i++;
    }

    //Copying temp array into the original one
    i = 0;
    for (j = l; j <= u; j++)
    {
        arr[j] = temp[i];
        i++;
    }
    return 0;
}

int MergeSort(int l, int u, int *arr)
{
    if (l < u)
    {
        int mid = (l + u) / 2;
        MergeSort(l, mid, arr);
        MergeSort(mid + 1, u, arr);
        merge(l, mid, u, arr);
    }
    return 0;
}

//QuickSort
int QuickSort(int l, int u, int *arr)
{
    if (l < u)
    {
        int p = partition(l, u, arr); //p->index of the correct position of pivot
        QuickSort(l, p - 1, arr);
        QuickSort(p + 1, u, arr);
    }
    return 0;
}

int partition(int l, int u, int *arr)
{
    //choosing a pivot element as arr[u]
    int i = l;
    int p = l; //p for getting the correct index of pivot
    while (i <= u)
    {
        if (arr[i] < arr[u])
        {
            swap(arr[i], arr[p]);
            p++;
        }
        i++;
    }
    swap(arr[p], arr[u]);
    return p;
}

void display(int *arr, int n)
{
    cout << "\nThe array:- ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
}

//InsertionSort
int InsertionSort(int *arr, int n)
{
    int i, j, key;
    for (i = 0; i < n - 1; i++)
    {
        j = i;
        key = arr[j + 1];
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return 0;
}



//BubbleSort
int bubbleSort(int *arr, int n)
{
    int i, j;
    int flag;

    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    return 0;
}