#ifndef MY_DOUBLY_LINKED_LIST_HPP
#define MY_DOUBLY_LINKED_LIST_HPP


/**
 * TODO: Implement DoublyLinkedList, its Node, and its Iterator!
 * 
 * I've left some methods filled out for you,
 * 	and stubbed out some structure, to reduce difficulty.
 * 
 * You may add helper methods as you see fit,
 * 	as long as you can still pass all unit tests.
 * 
 * Notice we're inside a namespace here.
 * The DLL is inside a namespace called DoublyLinkedList,
 * 	which is itself inside a namespace called CPSC131
 * This means, if you'd like to play around with your class later,
 * 	you'll need to access it like so:
 * ::CPSC131::DoublyLinkedList::DoublyLinkedList<int> list;
 * 
 * Look into main.cpp and CPP_Tests.cpp for examples of using
 * 	the DLL and your BookStore. But don't worry too much, as you
 * 	only need to implement these classes
 * (main and tests are already done for you)
 */


//
#include <iostream>
#include <stdlib.h>
#include <stdexcept>


/**
 * Namespace for our classroom and DLL !
 */
namespace CPSC131::DoublyLinkedList
{
	/**
	 * Implement our DoublyLinkedList class !
	 */
	template <class T>
	class DoublyLinkedList
	{
		public:
			
			/**
			 * Node class, representing a single item in our linked list
			 */
			// TODO: Complete all class methods
			class Node
			{
				public:
					
					/// CTORS
					/// Member initialization lists?
					Node() {}
					Node(T element) {}
					Node(T element, Node* prev, Node* next) {}
					
					/// Set the pointer to the previous element
					void setPrevious(Node* prev) {}
					
					/// Set the pointer to the previous element
					void setPrev(Node* prev) {}
					
					/// Get a pointer to the previous element
					Node* getPrevious() {}
					
					/// Get a pointer to the previous element
					Node* getPrev() {}
					
					/// Set the pointer to the next node
					void setNext(Node* next) {}
					
					/// Get a pointer to the next node
					Node* getNext() {}
					
					/// Set the element this node holds
					void setElement(T element) {}
					
					/// Get the element this node holds
					///	YOUR WELCOME
					T& getElement() { return this->element_; }
					
					/// Return a reference to the element
					///	YOUR WELCOME
					T& operator*() { return this->element_; }
					
				private:
					T element_;
					Node* prev_;
					Node* next_;
			};
			
			/**
			 * Nested Iterator class.
			 * This allows user code to refer to the Iterator's type as:
			 * 
			 * CPSC131::DoublyLinkedList::DoublyLinkedList<int>::Iterator
			 * 
			 * (as opposed to specifying the template argument two times)
			 */
			class Iterator
			{
				public:
					
					///	Constructor that does nothing; YOUR WELCOME
					Iterator()
					{
						/// yw
					}
					
					///	Constructor taking a head and tail pointer; YOUR WELCOME
					Iterator(Node* head, Node* tail) : head_(head), tail_(tail)
					{
						this->cursor_ = this->end();	/// yw
					}
					
					///	Constructor taking a head, tail, and cursor pointer; YOUR WELCOME
					Iterator(Node* head, Node* tail, Node* cursor) : head_(head), tail_(tail), cursor_(cursor) {}
					
					///	Get a pointer to the head node, or end() if this list is empty
					Node* begin()
					{
						//	TODO: Your code here
					}
					
					///	Get a node pointer representing "end" (aka "depleted"). Probably want to just use nullptr.
					Node* end()
					{
						//	TODO: Your code here
					}
					
					///	Get the node to which this iterator is currently pointing
					Node* getCursor()
					{
						//	TODO: Your code here
					}
					
					///	Return true if this iterator has hit its end; false otherwise
					/// YOUR WELCOME
					bool isAtEnd()
					{
						return this->cursor_ == nullptr;
					}
					
					/**
					 * Assignment operator
					 * Return a copy of this Iterator, after modification
					 */
					Iterator& operator=(const Iterator& other)
					{
						//	TODO: Your code here
					}
					
					///	Comparison operator
					bool operator==(const Iterator& other)
					{
						//	TODO: Your code here
					}
					///	Inequality comparison operator
					bool operator!=(const Iterator& other)
					{
						//	TODO: Your code here
					}
					
					/**
					 * Addition operator
					 */
					Iterator operator +(size_t add)
					{
						//	TODO: Your code here
					}
					
					/**
					 * Subtraction operator
					 */
					Iterator operator -(size_t subtract)
					{
						//	TODO: Your code here
					}
					
					/**
					 * Prefix increment operator
					 * Return a reference to this Iterator, after modification
					 */
					Iterator& operator++()
					{
						//	TODO: Your code here
					}
					
					/**
					 * Postfix increment
					 * Return a copy of this Iterator, BEFORE it was modified
					 */
					Iterator operator++(int)
					{
						//	TODO: Your code here
					}
					
					/**
					 * Prefix decrement operator
					 * Return a reference to this Iterator, after modification
					 */
					Iterator& operator--()
					{
						//	TODO: Your code here
					}
					
					/**
					 * Postfix decrement operator
					 * Return a copy of this Iterator BEFORE it was modified
					 */
					Iterator operator--(int)
					{
						//	TODO: Your code here
					}
					
					/**
					 * AdditionAssignment operator
					 * Return a copy of the current iterator, after modification
					*/
					Iterator operator +=(size_t add)
					{
						//	TODO: Your code here
					}
					/**
					 * SubtractionAssignment operator
					 * Return a copy of the current iterator, after modification
					 */
					Iterator operator -=(size_t sub)
					{
						//	TODO: Your code here
					}
					
					/**
					 * AdditionAssignment operator, supporting positive or negative ints
					 */
					Iterator operator +=(int add)
					{
						//	TODO: Your code here
					}
					
					/**
					 * SubtractionAssignment operator, supporting positive or negative ints
					 */
					Iterator operator -=(int subtract)
					{
						//	TODO: Your code here
					}
					
					/**
					 * Dereference operator returns a reference to the ELEMENT contained with the current node
					 */
					T& operator*()
					{
						//	TODO: Your code here
					}
				
				private:
					
					/// Pointer to the head node
					Node* head_ = nullptr;
					
					/// Pointer to the tail node
					Node* tail_ = nullptr;
					
					/**
					 * Pointer to the cursor node.
					 */
					Node* cursor_ = nullptr;
				
				friend class DoublyLinkedList;
			};
			
			/// Default constructor
			DoublyLinkedList()
			{
				//	TODO: Your code here
			}
			
			///	Copy Constructor
			DoublyLinkedList(const DoublyLinkedList& other)
			{
				//	TODO: Your code here
			}
			
			/// DTOR
			~DoublyLinkedList()
			{
				//	TODO: Your code here
			}
			
			/**
			 * Clear the list and assign the same value, count times.
			 * 
			 * Example:
			 *   T is an int
			 *   count is 5
			 *   value = 3
			 * 
			 * Our list would become:
			 *   {3, 3, 3, 3, 3}
			 */
			void assign(size_t count, const T& value)
			{
				//	TODO: Your code here
			}
			
			/**
			 * Clear the list and assign values from another list.
			 * The 'first' iterator points to the first item copied from the other list.
			 * The 'last' iterator points to the last item copied from the other list.
			 * 
			 * Example:
			 * 	Suppose we have a source list like {8, 4, 3, 2, 7, 1}
			 * 	Suppose first points to the 4 node
			 *	Suppose last points to the 7 node
			 * 	We should end up with our list becoming: {4, 3, 2, 7}
			 *
			 * If the user code sends out-of-order iterators,
			 * 	just copy from 'first' to the end of the source list
			 * 
			 * Example:
			 *  If we have the same source list {8, 4, 3, 2, 7, 1},
			 *  and first points to the 7 node,
			 *  and last points to the 4 node,
			 *  we would end up with: {7, 1}
			 */
			void assign(Iterator first, Iterator last)
			{
				//	TODO: Your code here
			}
			
			/// Return a pointer to the head node, if any
			Node* head() const
			{
				//	TODO: Your code here
			}
			
			/// Return a pointer to the tail node, if any
			Node* tail() const
			{
				//	TODO: Your code here
			}
			
			/**
			 * Return an iterator that points to the head of our list
			 */
			Iterator begin() const
			{
				//	TODO: Your code here
			}
			
			/**
			 * Return an iterator that points to the last element (tail) of our list
			 */
			Iterator last() const
			{
				//	TODO: Your code here
			}
			
			/**
			 * Should return an iterator that represents being past the end of our nodes,
			 * or just that we are finished.
			 * 
			 * You can make this a nullptr or use some other scheme of your choosing,
			 * 	as long as it works with the logic of the rest of your implementations.
			 */
			Iterator end() const
			{
				//	TODO: Your code here
			}
			
			/**
			 * Returns true if our list is empty
			 */
			bool empty() const
			{
				//	TODO: Your code here
			}
			
			/**
			 * Returns the current size of the list
			 * 
			 * Should finish in constant time!
			 * (keep track of the size elsewhere)
			 */
			size_t size() const
			{
				//	TODO: Your code here
			}
			
			/**
			 * Clears our entire list, making it empty
			 */
			void clear()
			{
				//	TODO: Your code here
			}
			
			/**
			 * Insert an element after the node pointed to by the pos Iterator
			 * 
			 * If the list is currently empty,
			 * 	ignore the iterator and just make the new node at the head/tail (list of length 1).
			 * 
			 * If the incoming iterator is this->end(),
			 *   insert the element as the new tail
			 * 
			 * Should return an iterator that points to the newly added node
			 */
			Iterator insert_after(Iterator pos, const T& value)
			{
				//	TODO: Your code here
			}
			
			/**
			 * Insert a new element after the index pos.
			 * Should work with an empty list.
			 * 
			 * If the user attempts to insert to an index
			 * that is out of range (e.g., size=5 but index=13),
			 * just add to the end of the list.
			 * 
			 * Should return an iterator pointing to the newly created node
			*/
			Iterator insert_after(size_t pos, const T& value)
			{
				//	TODO: Your code here
			}
			
			/**
			 * Erase the node pointed to by the Iterator's cursor.
			 * 
			 * If the 'pos' iterator does not point to a valid node,
			 * 	throw an std::range_error
			 * 
			 * Return an iterator to the node AFTER the one we erased,
			 * 	or this->end() if we just erased the tail
			 */
			Iterator erase(Iterator pos)
			{
				//	TODO: Your code here
			}
			
			/**
			 * Add an element just after the one pointed to by the 'pos' iterator
			 * 
			 * Should return an iterator pointing to the newly created node
			 */
			Iterator push_after(Iterator pos, const T& value)
			{
				//	TODO: Your code here
			}
			
			/**
			 * Add a new element to the front of our list.
			 */
			void push_front(const T& value)
			{
				//	TODO: Your code here
			}
			
			/**
			 * Add an element to the end of this list.
			 * 
			 * Should return an iterator pointing to the newly created node.
			 */
			Iterator push_back(const T& value)
			{
				//	TODO: Your code here
			}
			
			/**
			 * Remove the node at the front of our list
			 * 
			 * Should throw an exception if our list is empty
			 */
			void pop_front()
			{
				//	TODO: Your code here
			}
			
			/**
			 * Remove the node at the end of our list
			 * 
			 * Should throw an exception if our list is empty
			 */
			void pop_back()
			{
				//	TODO: Your code here
			}
			
			/**
			 * Return a reference to the element at the front.
			 * 
			 * Throw an exception if the list is empty
			 */
			T& front()
			{
				//	TODO: Your code here
			}
			
			/**
			 * Return a reference to the element at the back.
			 * 
			 * Throw an exception if the list is empty
			 */
			T& back()
			{
				//	TODO: Your code here
			}
			
			/**
			 * Return the element at an index
			 * 
			 * Should throw a range_error is out of bounds
			 */
			T& at(size_t index)
			{
				//	TODO: Your code here
			}
			
			/**
			 * Reverse the current list
			 */
			void reverse()
			{
				//	TODO: Your code here
			}
			
			/**
			 * I bet you're happy I'm not making you do this.
			 * No tests will be run against this function,
			 * 	but feel free to try it out, as a challenge!
			 * 
			 * If I were doing this and didn't care too much for efficiency,
			 * 	I would probably create an extra helper function to swap two
			 * 	positions in the current list.
			 * Then I would simply sweep through the list and perform
			 *  the bubble-sort algorithm. Perhaps selection sort.
			 * 
			 * If you want a huge challenge, try implementing quicksort.
			 * 
			 * (but again, don't worry about this method; it will not be tested)
			 */
			void sort()
			{
				//	TODO: Your code here
			}
			
			/**
			 * Assignment operator
			 * 
			 * Clear this list and fill it with the others' values
			 * (by value, not by reference)
			 * 
			 * Return a reference to this list
			 */
			DoublyLinkedList<T>& operator =(const DoublyLinkedList<T>& other)
			{
				//	TODO: Your code here
			}
			
			/**
			 * Return true if the lists are "equal"
			 * 
			 * "Equal" here is defined as:
			 * - Same size
			 * - Elements at the same indexes would return true for their own comparison operators
			 * 
			 * In other words: "They contain all the same values"
			 * (no need for their pointers or addresses to be the same)
			 */
			bool operator ==(DoublyLinkedList<T>& other)
			{
				//	TODO: Your code here
			}
			
			/**
			 * Return true if the lists are "not equal"
			 * 
			 * See the operator== stub for definition of "equal"
			 */
			bool operator !=(DoublyLinkedList<T>& other)
			{
				//	TODO: Your code here
			}
			
		private:
			
			Node* head_ = nullptr;
			Node* tail_ = nullptr;
			size_t size_ = 0;
	};
}

#endif
