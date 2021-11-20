#include <iostream>
#include <vector>



/*****************************************************************************
 * Priority queue.
 * Complexity: O(logN) for Push() and Extract().
 *****************************************************************************/

template <typename T>
class PriorityQueue
{
public:
	PriorityQueue();
		
	uint32_t Size() const;
	bool Empty() const;
	
	void Push(const T& value);
	void Push(T&& value);

	const T& Top() const;
	void Pop();   // Removes the top element
	T Extract();  // Return and removes the top element

private:
	void Swim(uint32_t k);
	void Sink(uint32_t k);

	template <typename U>
	friend std::ostream& operator <<(std::ostream& os, const PriorityQueue<U>& pq);

	uint32_t size_ = 0;
	std::vector<T> data_;
};
