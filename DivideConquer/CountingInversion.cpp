#include <iostream>
using namespace std;

long long inversion(int l, int u, int arr[]);
long long merge(int l, int mid, int u, int arr[]);

int main()
{
    int arr[10] = {10, 20, 30, 1, 2, 5, 4, 3, 7,6};
    long long inv = inversion(0, 9, arr);
    cout << inv;
    return 0;
}

long long inversion(int l, int u, int arr[])
{
    long long inv = 0;
    if (l < u)
    {
        int mid = (l + u) / 2;
        inv += inversion(l, mid, arr);
        inv += inversion(mid + 1, u, arr);
        inv += merge(l, mid, u, arr);
    }
    return inv;
}

long long merge(int l, int mid, int u, int arr[])
{

    int temp[u - l + 1];
    int i = 0, j = l, k = mid + 1; // for iterations
    int inv = 0;                   //to count inversions
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
            inv+=(mid-j+1);
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
    return inv;
    ;
}