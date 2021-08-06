// heappriorityqueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include"heappriority.h"
template<typename E>
class Less{
public:
	bool operator()(const E& left, const E& right)
	{
		return left > right;
	}
};

int main()
{
	heappriority<int,Less<int>>object;
	object.insert(6);
	object.insert(2);
	object.insert(3);
	object.insert(5);
    object.insert(4);
	object.insert(0);
	object.insert(-1);
	for (size_t i = 0; i <7; i++)
	{
		cout << *object.root()<<endl;
		object.removemin();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
