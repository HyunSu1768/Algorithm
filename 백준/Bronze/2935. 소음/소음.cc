#include <iostream>;
using namespace std;

int main() 
{
	string a, b, ans;
	char oper;

	cin >> a >> oper >> b;	

	if (oper == '+')
	{
		if (a.size() > b.size())
		{
			a.erase(a.size() - b.size(), a.size());
			ans = a + b;
		}
		else if (a.size() == b.size())
		{
			a.erase(a.begin());
			ans = '2' + a;
		}
		else if (a.size() < b.size())
		{
			b.erase(b.size() - a.size(), b.size());
			ans = b + a;
		}
	}
	else if (oper == '*')
	{
		b.erase(b.begin());
		ans = a + b;
	}	

	cout << ans << "\n";
}