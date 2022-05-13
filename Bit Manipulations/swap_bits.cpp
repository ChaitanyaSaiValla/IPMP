#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	unsigned int swapBits(unsigned int n)
	{
		for (int i = 0; i < sizeof(n) * 8; i += 2)
		{
			int a = (n >> i) & 1;
			int b = (n >> (i + 1)) & 1;

			n -= (a << i);
			n -= (b << (i + 1));

			n += (a << (i + 1));
			n += (b << i);
		}

		return n;
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		unsigned int n;
		cin >> n;

		Solution ob;
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}