#include <iostream>

using namespace std;

int main(void)
{
	float grossprice, taxrate, netprice, taxvalue;

	cout << "Enter a gross price: ";
	cin >> grossprice;
	cout << "Enter a tax rate: ";
	cin >> taxrate;

	taxvalue = grossprice - (netprice = grossprice / (1 + taxrate / 100.0f));

	cout << "Net price: " << netprice << endl;
	cout << "Tax value: " << taxvalue << endl;
	return 0;
}