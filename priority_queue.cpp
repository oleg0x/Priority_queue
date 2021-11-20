#include "priority_queue.h"
#include <iostream>
#include <vector>



template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	data_.push_back({});
};



template <typename T>
uint32_t PriorityQueue<T>::Size() const
{
	return size_;
}



template <typename T>
bool PriorityQueue<T>::Empty() const
{
	return (size_ == 0);
}



template <typename T>
void PriorityQueue<T>::Push(const T& value)
{
	data_.push_back(value);
	Swim(++size_);
}



template <typename T>
void PriorityQueue<T>::Push(T&& value)
{
	data_.push_back(std::move(value));
	Swim(++size_);
}



template <typename T>
const T& PriorityQueue<T>::Top() const
{
	return data_[1];
}



template <typename T>
void PriorityQueue<T>::Pop()
{
	if ( data_.size() >= 1 )
	{
		data_[1] = data_[size_--];
		data_.pop_back();
		Sink(1);
	}
}



template <typename T>
T PriorityQueue<T>::Extract()
{
	T temp;
	if ( data_.size() >= 1 )
	{
		temp = data_[1];
		Pop();
	}
	return temp;
}



template <typename T>
void PriorityQueue<T>::Swim(uint32_t k)
{
	while ( k > 1 && data_[k/2] < data_[k] )
	{
		std::swap(data_[k], data_[k/2]);
		k /= 2;  // Parent of node at k is at k/2
	}
}



template <typename T>
void PriorityQueue<T>::Sink(uint32_t k)
{
	while ( 2*k <= size_ )
	{
		uint32_t j = 2*k;  // Children of node at k are 2k and 2k+1
		if ( j < size_ && data_[j] < data_[j+1] )  ++j;
		if ( !(data_[k] < data_[j]) )  break;
		std::swap(data_[k], data_[j]);
		k = j;
	}
}



template <typename T>
std::ostream& operator <<(std::ostream& os, const PriorityQueue<T>& pq)
{
	if ( pq.size_ > 0 )
		for ( uint32_t i = 1; i <= pq.size_; ++i )
			os << pq.data_[i] << ' ';
	else
		std::cout << "The PriorityQueue is empty";
	os << '\n';
	return os;
}



template class PriorityQueue<int>;
template std::ostream& operator<<(std::ostream& os, const PriorityQueue<int>& pq);
