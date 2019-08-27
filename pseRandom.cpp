#include <iostream>
using namespace std;
int main()
{
	int M = 256;
    int a = 65;
    int c = 27;
    int X = 1;
    int i;
    for(i=0; i<256; i++)
    {
        X=(a * X + c) % M;
        cout << X << " ";
    }
    return 0;
}
