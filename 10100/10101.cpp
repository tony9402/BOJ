#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c && c == 60)return cout << "Equilateral", 0;
	if (a + b + c == 180)
		if (a == b || b == c || c == a)return cout << "Isosceles", 0;
		else return cout << "Scalene", 0;
	cout << "Error";
	return 0;
}