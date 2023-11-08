#include<iostream>
using namespace std;

void han(int x, char a, char temp, char b)
{
	if (x == 1)
		cout << " number " << x << " from " << a << " to " << b << endl;

	else
	{
		han(x - 1, a, b, temp);
		cout << " number " << x << " from " << a << " to " << b << endl;
		han(x - 1, temp, a, b);
	}
}
void main()
{
	int n;
	char A, B, C;
	cin >> n;
	cin >> A >> B >> C;
	han(n, A, B, C);
}