#include <iostream>
using namespace std;

void toh(int n, int a, int b, int c)
{
    if (n == 1)
    {
        cout << "Move a disk from tower " << a << " to tower " << c << endl;
    }
    else
    {
        toh(n - 1, a, c, b);
        cout << "Move a disk from tower " << a << " to tower " << c << endl;
        toh(n - 1, b, a, c);
    }
}
int main()
{
    int n;
    cout << "Enter the no. of disks:- ";
    cin >> n;
    toh(n, 1, 2, 3);
    return 0;
}