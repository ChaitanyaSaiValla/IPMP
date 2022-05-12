#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> rotate(int n, int d)
	{
		d %= 16;
		vector<int> ans(2);
		int temp, mask, shift;

		temp = n;
		mask = (1 << d) - 1;
		shift = temp & mask;
		temp >>= d;
		temp |= (shift << (16 - d));
		ans[1] = temp;

		temp = n;
		mask = ~((1 << (16 - d)) - 1);
		shift = temp & mask;
		temp <<= d;
		temp |= (shift >> (16 - d));
		mask = (1 << 16) - 1;
		temp &= mask;
		ans[0] = temp;

		return ans;
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, d;
		cin >> n >> d;
		Solution ob;
		vector<int> res = ob.rotate(n, d);
		cout << res[0] << endl
			 << res[1] << endl;
	}
}
