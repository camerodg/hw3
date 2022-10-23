#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
   /// Add whatever helper functions and data members you need below
  std::vector<T>list; // vector to store all the nodes 
  void trickleDown(unsigned int idx); //for placing nodes in correct location
  unsigned int d_ary;
  PComparator compared;
};

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) 
{
	d_ary = m;
	compared = c;
	
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(unsigned int idx){
  //create variable for the left child and right child
   unsigned int leftChild = (d_ary*idx) +1;
   unsigned int rightChild;
	 //check to see if there no child node
   if(leftChild >= list.size()){
    return;
   }
   for(unsigned int i = 0; i < d_ary; i++)
   {
		 //check to see if right node is nonexistent 
    rightChild = leftChild + i + 1;
    if(rightChild >= list.size())
    {
      break;
    }
		//swaps right child and left child 
    if(compared(list[rightChild],list[leftChild]))
    {
      leftChild = rightChild;
    }
  }
  if(compared(list[leftChild],list[idx]))
  {
    std::swap(list[idx],list[leftChild]);
    trickleDown(leftChild);
  }
}
// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
		 throw std::underflow_error("The Heap is Empty"); 
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	
	return list.at(0); 
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
		 throw std::underflow_error("The Heap is Empty"); 
  }
	//push the item to the top
	//pop the top and trickledown
	list.at(0) = list.back(); 
	list.pop_back();
	trickleDown(0); 
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
list.push_back(item);
unsigned int curr = list.size()-1;
unsigned int parent = (curr-1)/d_ary;
//push back the item, create parent and child node 
//iterate up until in correct position
  while(parent >= 0 && compared(list[curr],list[parent]))
  {
		//swaps nodes and then change variables 
		//to account for swapping 
      std::swap(list[parent],list[curr]);
      curr = parent;
      parent = curr/d_ary;
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
	return (list.size() == 0);
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
	return list.size();
}
#endif