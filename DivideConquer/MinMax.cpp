#include <iostream>
using namespace std;
struct p
{
    int min, max;
};
p MinMax(int l, int u, int arr[])
{
    if (u == l + 1)
    {
        p p1;
        if (arr[l] <= arr[u])
        {
            p1 = {arr[l], arr[u]};
        }
        else
            p1 = {arr[u], arr[l]};

        return p1;
    }

    else if (l == u)
    {
        p p1 = {arr[l], arr[u]};
        return p1;
    }

    else if (l < u)
    {
        int mid = (l + u) / 2;
        p p1 = MinMax(l, mid, arr);
        p p2 = MinMax(mid + 1, u, arr);
        p p3;
        p3.min = (p1.min <= p2.min) ? p1.min : p2.min;
        p3.max = (p1.max >= p2.max) ? p1.max : p2.max;
        return p3;
    }
}
int main()
{
    int arr[10] = {930, 930, 3789, 830, 1993, 19301, 89, 89, 89, 1000};
    p p1 = MinMax(0, 9, arr);
    cout << "Max is " << p1.max << " & Min is " << p1.min;
    return 0;
}