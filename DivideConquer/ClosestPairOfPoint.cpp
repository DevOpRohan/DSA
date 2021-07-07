#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x;
    int y;
};

class cl
{
public:
    double d;
    point p1;
    point p2;
};

//functions
bool compX(point a, point b);
bool compY(point a, point b);
cl closest(point arr[], int size);
double distance(point p1, point p2);
cl closestUtil(point arrx[], point arry[], int l, int u, int size);



//Driver code
int main()
{
    point arr[6] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    cl p = closest(arr, 6);
    cout << "Min distance is:- " << p.d << endl;
    cout << "Closest paor is:- {" << p.p1.x << " ," << p.p1.y << "} {" << p.p2.x << " ," << p.p2.y << "} ";
}

//comparator func for sort
bool compX(point a, point b)
{
    return a.x <= b.y;
}
bool compY(point a, point b)
{
    return a.y <= b.y;
}

cl closest(point arr[], int size)
{
    point arrx[size];
    point arry[size];
    for (int i = 0; i < size; i++)
    {
        arrx[i] = arr[i];
        arry[i] = arr[i];
    }

    // Sort according to x corrdinate and y coordinate
    sort(arrx, arrx + size, compX);
    sort(arry, arry + size, compY);
    cl p = closestUtil(arrx, arry, 0, size - 1, size);
    return p;
}


//to calculate distance b/w two points
double distance(point p1, point p2)
{
    double d = sqrt((p1.x - p2.x) * (p1.x - p2.x) - (p1.y - p2.y) * (p1.y - p2.y));
    return d;
}

//
cl closestUtil(point arrx[], point arry[], int l, int u, int size)
{
    cl p;
    //Base case size=2, size =3  //Brute force
    if (u == l + 1)
    {
        p.d = distance(arrx[l], arrx[u]);
        p.p1 = arrx[l];
        p.p2 = arrx[u];
    }
    else if (u == l + 2)
    {
        p.d = distance(arrx[l], arrx[l + 1]);
        for (int i = l; i <= u; i++)
        {
            for (int j = i + 1; j <= u; j++)
            {
                double temp = distance(arrx[i], arrx[j]);
                if (temp < p.d)
                {
                    p.d = temp;
                    p.p1 = arrx[i];
                    p.p2 = arrx[j];
                }
            }
        }
    }

    //recursice case-> Divide & Conquer

    else
    {
        int mid = (l + u) / 2;
        cl p1 = closestUtil(arrx, arry, l, mid, size);
        cl p2 = closestUtil(arrx, arry, mid + 1, u, size);
        p = (p1.d < p2.d) ? p1 : p2;

        //for case if both point is in opposite side of the mid;

        //1.Strip formation;
        point strip[size];
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (abs(arry[i].x - arrx[mid].x) <= p.d)
            {
                strip[j] = arry[i];
                j++;
            }
        }

        for (int i = 0; i < j; i++)
        {
            for (int k = i + 1; k < i + 7 && k < j; k++)
            {
                double temp = distance(strip[i], strip[j]);
                if (temp < p.d)
                {
                    p.d = temp;
                    p.p1 = strip[i];
                    p.p2 = strip[k];
                }
            }
        }
    }

    return p;
}
