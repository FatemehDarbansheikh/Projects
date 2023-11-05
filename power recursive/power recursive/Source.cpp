#include<iostream>
using namespace std;

int power(int a, int b)
{
	if (b == 1)
		return a;
	else
		return a*power(a, b - 1);
}

void main()
{
	int x, y;
	cin >> x >> y;
	cout << power(x, y) << endl;
}