#include "priority_queue.h"
#include "index_min_pq.h"
#include <cassert>
#include <iostream>

using namespace std;



void TestPriorityQueue()
{
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

	cout << "TestPriorityQueue is OK.\n\n";
}



void TestIndexMinPQ1()
{
	IndexMinPQ<uint32_t> pq(5);
	cout << "Size: " << pq.Size() << ", Empty: " << pq.Empty() << '\n';
	assert( pq.Size() == 0 && pq.Empty() == true );

	pq.Insert(1, 1000);
	pq.Insert(2, 100);
	pq.Insert(3, 10);
	pq.Insert(4, 1);
	pq.Print();

	cout << "Size: " << pq.Size() << ", Empty: " << pq.Empty() << '\n';
	assert( pq.Size() == 4 && pq.Empty() == false );

	cout << pq.Contains(1) << ' ' << pq.Contains(4) << ' '
	     << pq.Contains(5) << '\n';
	assert( pq.Contains(1) == true && pq.Contains(4) == true &&
	        pq.Contains(5) == false );

	uint32_t a = pq.DelMin();
	uint32_t b = pq.DelMin();
	uint32_t c = pq.DelMin();
	uint32_t d = pq.DelMin();
	cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	assert( a == 4 && b == 3 && c == 2 && d == 1 );

	pq.Print();
	cout << "Size: " << pq.Size() << ", Empty: " << pq.Empty() << '\n';
	assert( pq.Size() == 0 && pq.Empty() == true );
//	pq.DelMin();  // Exception here

	cout << "TestIndexMinPQ1 is OK.\n\n";
}



void TestIndexMinPQ2()
{
	IndexMinPQ<double> pq(10);

	pq.Insert(1, 3.2);
	pq.Insert(2, 1.5);
	pq.Insert(3, 3.8);
	pq.Insert(4, 1.7);
	pq.Insert(5, 2.4);
	pq.Print();

	pq.DecreaseKey(3, 2.9);
	pq.DecreaseKey(5, 0.2);
	cout << pq.At(3) << ' ' << pq.At(5) << '\n';
	assert( pq.At(3) == 2.9 && pq.At(5) == 0.2 );

	pq.ChangeKey(5, 100.0);
	pq.ChangeKey(4, 50.0);
	pq.ChangeKey(1, 2.0);
//	pq.ChangeKey(555, 1.0);  // Exception here
	pq.Print();
	assert( pq.At(1) == 2.0 && pq.At(4) == 50.0 && pq.At(5) == 100.0 );
	assert( pq.Size() == 5 && pq.Empty() == false );

	cout << "TestIndexMinPQ2 is OK.\n";
}
