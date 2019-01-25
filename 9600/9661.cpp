#include<iostream>
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin >> n;
	ll cal1 = (n + 3) % 5;
	ll cal2 = n % 5;

	if (!cal1 || !cal2)
	{
		cout << "CY";
	}
	else
	{
		cout << "SK";
	}
	return 0;
}