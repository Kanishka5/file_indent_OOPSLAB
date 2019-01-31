#include <iostream>
using namespace std;
int main()
{
    int x = 30, i;
    for (i = 1; i <= 10; i++)
    {
        if (!(x % i))
        {
            cout << x << " is divisible by " << i << "." << endl;
        }
        else
        {
            cout << x << " is not divisible by " << i << "." << endl;
        }
    }
    return 0;
}