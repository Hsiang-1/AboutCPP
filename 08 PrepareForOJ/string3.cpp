#include <iostream>
#include <string>

using namespace std;

int main (void)
{
	string aaa = "abcdefghijkl mn";
	
	cout << aaa.substr(3) << endl;
	cout << aaa.substr(3,5) << endl;
	
	
	return 0;
}
