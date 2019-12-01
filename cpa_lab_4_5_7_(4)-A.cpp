#include <string>
#include <iostream>

using namespace std;

int main()
{
	char cha[256] = {}, chb[256] = {};
	string a, b;
	cin >> a >> b;

	if (a.size() != b.size())
	{
		cout << "not anagrams" << endl;
		return 0;
	}
	bool anagram = true;
	for (size_t i = 0; i < a.size(); ++i)
		++cha[a[i]], ++chb[b[i]];
	for (int x = 0; x < 255; ++x)
		if (cha[x] != chb[x])
		{
			anagram = false;
			break;
		}
	cout << (anagram ? "anagrams" : "not anagrams") << endl;

	return 0;
}