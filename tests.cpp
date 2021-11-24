#include "priority_queue.h"
#include "index_min_pq.h"
#include <cassert>
#include <iostream>

using namespace std;



void TestPriorityQueue()
{
	cout << "---------- " << __func__ << " ----------\n";

	PriorityQueue<int> pq;
	cout << "Size: " << pq.Size() << ", Empty: " << pq.Empty() << '\n';
	assert( pq.Size() == 0 && pq.Empty() == true );

	pq.Push(10);
	pq.Push(25);
	pq.Push(20);
	pq.Push(15);
	cout << pq;

	cout << "Size: " << pq.Size() << ", Empty: " << pq.Empty() << '\n';
	assert( pq.Size() == 4 && pq.Empty() == false );

	cout << "Top: " << pq.Top() << '\n';
	assert( pq.Top() == 25 );
	pq.Pop();
	assert( pq.Top() == 20 );
	pq.Pop();

	cout << "Size: " << pq.Size() << ", Empty: " << pq.Empty() << '\n';
	assert( pq.Size() == 2 && pq.Empty() == false );

	cout << "Top: " << pq.Extract() << '\n';
	assert( pq.Top() == 10 );
	cout << pq;

	cout << "Top: " << pq.Extract() << '\n';
	cout << pq;
	cout << "Is empty: " << pq.Empty() << ", size = " << pq.Size() << '\n';

	pq.Extract();  pq.Pop();
	pq.Extract();  pq.Pop();

	cout << __func__ << " is OK.\n\n";
}



void TestIndexMinPQ1()
{
	cout << "---------- " << __func__ << " ----------\n";

	IndexMinPQ<uint32_t> pq(5);
	cout << "Size: " << pq.Size() << ", Empty: " << pq.Empty() << '\n';
	assert( pq.Size() == 0 && pq.Empty() == true );

	pq.Insert(0, 1000);
	pq.Insert(1, 100);
	pq.Insert(2, 10);
	pq.Insert(3, 1);
	pq.Print();

	cout << "Size: " << pq.Size() << ", Empty: " << pq.Empty() << '\n';
	assert( pq.Size() == 4 && pq.Empty() == false );

	cout << pq.Contains(0) << ' ' << pq.Contains(3) << ' '
	     << pq.Contains(4) << '\n';
	assert( pq.Contains(0) == true && pq.Contains(3) == true &&
	        pq.Contains(4) == false );

	uint32_t a = pq.DelMin();
	uint32_t b = pq.DelMin();
	uint32_t c = pq.DelMin();
	uint32_t d = pq.DelMin();
	cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	assert( a == 3 && b == 2 && c == 1 && d == 0 );

	pq.Print();
	cout << "Size: " << pq.Size() << ", Empty: " << pq.Empty() << '\n';
	assert( pq.Size() == 0 && pq.Empty() == true );
//	pq.DelMin();  // Exception here

	cout << __func__ << " is OK.\n\n";
}



void TestIndexMinPQ2()
{
	cout << "---------- " << __func__ << " ----------\n";

	IndexMinPQ<double> pq(10);

	pq.Insert(1, 3.2);
	pq.Insert(2, 1.5);
	pq.Insert(3, 3.8);
	pq.Insert(4, 1.7);
	pq.Insert(5, 2.4);
	pq.Print();

	pq.DecreaseElem(3, 2.9);
	pq.DecreaseElem(5, 0.2);
	cout << pq.At(3) << ' ' << pq.At(5) << '\n';
	assert( pq.At(3) == 2.9 && pq.At(5) == 0.2 );

	pq.ChangeElem(5, 100.0);
	pq.ChangeElem(4, 50.0);
	pq.ChangeElem(1, 2.0);
//	pq.ChangeKey(555, 1.0);  // Exception here
	pq.Print();
	assert( pq.At(1) == 2.0 && pq.At(4) == 50.0 && pq.At(5) == 100.0 );
	assert( pq.Size() == 5 && pq.Empty() == false );

	cout << __func__ << " is OK.\n\n";
}
