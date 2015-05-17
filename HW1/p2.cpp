#include <iostream>

using namespace std;

int main()
{
	int p = 0;
	int q = 0;
	cin >> p;
	cin >> q;
	while (p % q > 0)
	{
		int	r = p % q;
		cout << r << " ";
		p = q;
		q = r;
	}
	cout << "\n" << q;
	return 0;
}
