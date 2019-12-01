#include <iostream>

using namespace std;
constexpr int N_MAX = 1000000, BANKNOTES[5] = {1, 5, 10, 20, 50};
int dp[N_MAX], prevb[N_MAX];

int main(void)
{
	int n;
	cin >> n;
	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = N_MAX + 1; // Infinity
		for (auto banknote : BANKNOTES)
			if (i >= banknote && dp[i - banknote] < dp[i])
				dp[i] = dp[i - banknote], prevb[i] = banknote;
		++dp[i];
	}
	while (n > 0)
	{
		cout << prevb[n] << ' ';
		n -= prevb[n];
	}
	return 0;
}