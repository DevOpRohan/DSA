#include <iostream>
using namespace std;

void swap(char &, char &);
void p(string s, int l, int r);

int main()
{
    string s;
    cout << "Enter a string:-  ";
    getline(cin, s);

    p(s,0,(s.length()-1));

    return 0;
}

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void p(string s, int l, int r)
{

    if (l == r)
    {
        cout << s << endl;
    }
    for (int i = l; i <= r; i++)
    {
        swap(s[i], s[l]);
        p(s, l + 1, r);
        // swap(s[i], s[l]); //backtracking
    }
}
