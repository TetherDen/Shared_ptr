#include <iostream>
using namespace std;
#include "MySharedPtr.h"






int main()
{
	MySharedPtr<int> ptr (new int(7));
	cout << *ptr<<endl;

	MySharedPtr<int> ptr2 = ptr;
	cout << *ptr2 << endl;
	cout << *ptr << endl;

	*ptr = 8;
	cout << *ptr << endl;

	cout<<"counter: "<<ptr.getCounter()<<endl;



	return 0;
}