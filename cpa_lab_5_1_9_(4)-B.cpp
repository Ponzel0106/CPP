#include <iostream>
#include <string>

using namespace std;

class ShopItemOrder
{
public:
	// Constructor
	ShopItemOrder(string name, double unitPrice, int itemCnt)
		: name(name), unitPrice(unitPrice), itemCnt(itemCnt)
	{}
	// Getters
	string getName() const
	{
		return name;
	}
	double getUnitPrice() const noexcept
	{
		return unitPrice;
	}
	int getItemCnt() const noexcept
	{
		return itemCnt;
	}
	// Setters
	void setName(const string& str)
	{
		name = str;
	}
	void setUnitPrice(double uP) noexcept
	{
		unitPrice = uP;
	}
	void setItemCnt(int cnt) noexcept
	{
		itemCnt = cnt;
	}
	// Other methods
	double getTotalPrice() const
	{
		return unitPrice * itemCnt;
	}
	void print() const
	{
		cout << "Name: " << name << endl;
		cout << "Unit price: " << unitPrice << endl;
		cout << "Item count: " << itemCnt << endl;
		cout << "Total price: " << getTotalPrice() << endl;
	}
private:
	string name;
	double unitPrice;
	int itemCnt;
};

int main()
{
	ShopItemOrder sio("TestName", 100., 24);
	sio.print();

	sio.setItemCnt(20);
	cout << "After changing item count:" << endl;
	sio.print();

	sio.setName("AnotherName");
	sio.setUnitPrice(50.);
	cout << "After changing name and unit price:" << endl;
	sio.print();

	return 0;
}