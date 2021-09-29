#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(void)
{
	string a, b, c;
	cin >> a >> b >> c;
	
	if(c == "?")
	{
		if(a == "A" && b == "A")
			cout << "A A {A,O}" << endl;
			
		else if(a == "A" && b == "B")
			cout << "A B {A,AB,B,O}" << endl;
		
		else if(a == "A" && b == "O")
			cout << "A O {A,O}" << endl;
		
		else if(a == "A" && b == "AB")
			cout << "A B {A,AB,B}" << endl;
		
		
		else if(a == "B" && b == "A")
			cout << "B A {A,AB,B,O}" << endl;
		
		else if(a == "B" && b == "B")
			cout << "B B {B,O}" << endl;
			
		else if(a == "B" && b == "O")
			cout << "B O {B,O}" << endl;
			
		else if(a == "B" && b == "AB")
			cout << "B AB {A,AB,B}" << endl;
			
			
		else if(a == "O" && b == "A")
			cout << "O A {A,O}" << endl;
			
		else if(a == "O" && b == "B")
			cout << "O B {B,O}" << endl;
		
		else if(a == "O" && b == "O")
			cout << "O O O" << endl;
			
		else if(a == "O" && b == "AB")
			cout << "O AB {A,B}" << endl;
		
			
		else if(a == "AB" && b == "A")
			cout << "AB A {A,AB,B}" << endl;
		
		else if(a == "AB" && b == "B")
			cout << "AB B {A,AB,B}" << endl;
			
		else if(a == "AB" && b == "O")
			cout << "AB O {A,B}" << endl;
			
		else if(a == "AB" && b == "AB")
			cout << "AB AB {A,AB,B}" << endl;
	}
	else if(a == "?")
	{
		if(b == "A" && c == "A")
			cout << "{A,AB,B,O} A A" << endl;
			
		else if(b == "A" && c == "B")
			cout << "{AB,B} A B" << endl;
			
		else if(b == "A" && c == "O")
			cout << "{A,B,O} A O" << endl;
			
		else if(b == "A" && c == "AB")
			cout << "{B,AB} A AB" << endl;
			
			
		else if(b == "B" && c == "A")
			cout << "{A,AB} B A" << endl;
			
		else if(b == "B" && c == "B")
			cout << "{A,AB,B,O} B B" << endl;
			
		else if(b == "B" && c == "O")
			cout << "{A,B,O} B O" << endl;
			
		else if(b == "B" && c == "AB")
			cout << "{A,AB} B AB" << endl;
			
			
		else if(b == "O" && c == "A")
			cout << "{A,AB} O A" << endl;
			
		else if(b == "O" && c == "B")
			cout << "{AB,B} O B" << endl;
			
		else if(b == "O" && c == "O")
			cout << "{A,B,O} O O" << endl;
			
		else if(b == "O" && c == "AB")
			cout << "impossible O AB" << endl;
			
			
		else if(b == "AB" && c == "A")
			cout << "{A,AB,B,O} AB A" << endl;
			
		else if(b == "AB" && c == "B")
			cout << "{A,AB,B,O} AB B" << endl;
			
		else if(b == "AB" && c == "O")
			cout << "impossible AB O" << endl;
			
		else if(b == "AB" && c == "AB")
			cout << "{A,AB,B} AB AB" << endl;
	}
	else if(b == "?")
	{
		if(a == "A" && c == "A")
			cout << "A {A,AB,B,O} A" << endl;
			
		else if(a == "A" && c == "B")
			cout << "A {AB,B} B" << endl;
			
		else if(a == "A" && c == "O")
			cout << "A {A,B,O} O" << endl;
			
		else if(a == "A" && c == "AB")
			cout << "A {AB,B} AB" << endl;
			
			
		else if(a == "B" && c == "A")
			cout << "B {A,AB} A" << endl;
			
		else if(a == "B" && c == "B")
			cout << "B {A,AB,B,O} B" << endl;
			
		else if(a == "B" && c == "O")
			cout << "B {A,B,O} O" << endl;
			
		else if(a == "B" && c == "AB")
			cout << "B {A,AB} AB" << endl;
			
			
		else if(a == "O" && c == "A")
			cout << "O {A,AB} A" << endl;
			
		else if(a == "O" && c == "B")
			cout << "O {AB,B} B" << endl;
			
		else if(a == "O" && c == "O")
			cout << "O {A,B,O} O" << endl;
			
		else if(a == "O" && c == "AB")
			cout << "O impossible AB" << endl;
			
			
		else if(a == "AB" && c == "A")
			cout << "AB {A,AB,B,O} A" << endl;
			
		else if(a == "AB" && c == "B")
			cout << "AB {A,AB,B,O} B" << endl;
			
		else if(a == "AB" && c == "O")
			cout << "AB impossible O" << endl;
			
		else if(a == "AB" && c == "AB")
			cout << "AB {A,B,AB} AB" << endl;
	}
	
	
	return 0; 
}
