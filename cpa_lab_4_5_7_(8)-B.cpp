#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
	string values, templ, p;
	getline(cin, values);
	getline(cin, templ);

	unordered_map<string, string> vals;
	istringstream iss(values);
	while (getline(iss, p, ','))
	{
		const size_t pos = p.find('=');
		vals[p.substr(0, pos)] = p.substr(pos + 1);
	}

		for (const auto& [key, val] : vals)
		{
			const string patt = '[' + key + ']';
			size_t pos = 0;
			while (true)
			{
				pos = templ.find(patt, pos);
				if (pos == string::npos)
					break;
				templ.replace(pos, patt.size(), val);
				pos += val.size();
			}
		}

	cout << templ << endl;

	return 0;
}