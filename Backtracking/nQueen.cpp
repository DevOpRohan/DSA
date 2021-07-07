#include <iostream>
using namespace std;

bool isSafe(int **a, int n, int r, int c);
int nQueen(int **a, int n, int r);

int main()
{
    cout << "Enter the dimension: ";
    int n;
    cin >> n;

    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    if(nQueen(a,n,0)){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else cout<<"No soln";
    
return 0;
}

bool isSafe(int **a, int n, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (a[i][c] == 1)
            return false;
    }

    int x = r, y = c;
    //checking first diagonal
    while (x >= 0 && y >= 0)
    {
        if (a[x][y] == 1)
            return false;
        x--;
        y--;
    }

    //checking 2nd diagonal
    x = r;
    y = c;
    while (x >= 0 && y < n)
    {
        if (a[x][y] == 1)
            return false;
        x--;
        y++;
    }

    return true;
}

int nQueen(int **a, int n, int r)
{
    if (r == n)
    {
        return 1;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(a, n, r, j))
        {
            a[r][j] = 1;
            if (nQueen(a, n, r + 1))
            {
                return 1;
            }
            a[r][j] = 0; //backtracking
        }
    }

    return 0;
}