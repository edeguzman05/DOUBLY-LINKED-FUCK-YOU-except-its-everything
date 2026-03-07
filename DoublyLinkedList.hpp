#ifndef MY_DOUBLY_LINKED_LIST_HPP
#define MY_DOUBLY_LINKED_LIST_HPP

/**
 *Name: Emmanuel De Guzman 
 *CWID: 884886995
 *Email: edeguzmanjr05@csu.fullerton.edu
 */

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
                Node() : next_(nullptr), prev_(nullptr) {}	
                Node(T element) : element_(element), prev_(nullptr), next_(nullptr) {}
                Node(T element, Node* prev, Node* next) : prev_(prev), next_(next), element_(element) {}

                   
                    /// Set the pointer to the previous element
                    void setPrevious(Node* prev) { prev_ = prev; }
                   
                    /// Set the pointer to the previous element
                    void setPrev(Node* prev) { prev_ = prev; }
                   
                    /// Get a pointer to the previous element
                    Node* getPrevious() { return this->prev_; }
                   
                    /// Get a pointer to the previous element
                    Node* getPrev() { return this->prev_; }
                   
                    /// Set the pointer to the next node
                    void setNext(Node* next) { next_ = next; }
                   
                    /// Get a pointer to the next node
                    Node* getNext() {  return this->next_; }
                   
                    /// Set the element this node holds
                    void setElement(T element) { element_ = element; }
                   
                    /// Get the element this node holds
                    /// YOUR WELCOME
                    T& getElement() { return this->element_; }
                   
                    /// Return a reference to the element
                    /// YOUR WELCOME
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
                   
                    /// Constructor that does nothing; YOUR WELCOME
                    Iterator()
                    {
                        /// yw
                    }
                   
                    /// Constructor taking a head and tail pointer; YOUR WELCOME
                    Iterator(Node* head, Node* tail) : head_(head), tail_(tail)
                    {
                        this->cursor_ = this->end();    /// yw
                    }
                   
                    /// Constructor taking a head, tail, and cursor pointer; YOUR WELCOME
                    Iterator(Node* head, Node* tail, Node* cursor) : head_(head), tail_(tail), cursor_(cursor) {}
                   
                    /// Get a pointer to the head node, or end() if this list is empty
                    Node* begin()
                    {                      
                        return head_;
                    }
                   
                    /// Get a node pointer representing "end" (aka "depleted"). Probably want to just use nullptr.
                    Node* end()
                    {
                       return nullptr;
                    }
                   
                    /// Get the node to which this iterator is currently pointing
                    Node* getCursor()
                    {
                        return cursor_;
                    }
                   
                    /// Return true if this iterator has hit its end; false otherwise
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
                        this->head_ = other.head_;
                    	this->tail_ = other.tail_;
                    	this->cursor_ = other.cursor_;
                    	return *this;
                    }
                   
                    /// Comparison operator
                    bool operator==(const Iterator& other)
                    {
                        if(this->cursor_ == other.cursor_) {
                        	return true;
                    	} else {
                    		return false;
                    	}

                    }
                    /// Inequality comparison operator
                    bool operator!=(const Iterator& other)
                    {
                        if (cursor_ != other.cursor_) {
                        	return true;
                        } else {
                        	return false;
		    	}
		    }
						
                   
                    /**
                     * Addition operator
                     */
                    Iterator operator +(size_t add)
                    {
                   	Iterator tempIte = *this;
                    	for (size_t i = 0; i < add && tempIte.cursor_ != nullptr; i++) {
                            	tempIte.cursor_ = tempIte.cursor_->getNext();    
                    	}
                    	return tempIte;
                    }
                   
                    /**
                     * Subtraction operator
                     */
                    Iterator operator -(size_t subtract)
                    {
                       Iterator tempIte = *this;
                    	for (size_t i = 0; i < subtract && cursor_ != nullptr; i++) {
                            	tempIte.cursor_ = tempIte.cursor_->getPrev();    
                    	}
                    	return tempIte;

                    }
                   
                    /**
                     * Prefix increment operator
                     * Return a copy of this Iterator, after modification
                     */
                    Iterator& operator++()
                    {
                        if (cursor_ != nullptr) {
                        	cursor_ = cursor_->getNext();
                    	}
                    	return *this;

                    }
                   
                    /**
                     * Postfix increment
                     * Return a copy of this Iterator, BEFORE it was modified
                     */
                    Iterator operator++(int)
                    {
                    	
                    	Iterator Iverson = *this;
                    	if (cursor_ != nullptr) {
                        	cursor_ = cursor_->getNext();
                    	}
                    	return Iverson;
                    }
                   
                    /**
                     * Prefix decrement operator
                     * Return a copy of this Iterator, after modification
                     */
                    Iterator& operator--()
                    {                     
                        if (cursor_ != nullptr) {
                        cursor_ = cursor_->getPrev();
                    	}
                    	return *this;
                    }

                   
                    /**
                     * Postfix decrement operator
                     * Return a copy of this Iterator BEFORE it was modified
                     */
                    Iterator operator--(int)
                    {
                        Iterator Rose = *this;
                    	if (cursor_ != nullptr) {
                        	cursor_ = cursor_->getPrev();
                    	}
                    	return Rose;
                    }
                   
                    /**
                     * AdditionAssignment operator
                     * Return a copy of the current iterator, after modification
                    */
                    Iterator operator +=(size_t add)
                    {
                        for (size_t i = 0; i < add && cursor_ != nullptr; i++) {
                            	cursor_ = cursor_->getNext();    
                    	}
                    	return *this;

                    }
                    /**
                     * SubtractionAssignment operator
                     * Return a copy of the current iterator, after modification
                     */
                    Iterator operator -=(size_t subtract)
                    {
                        for (size_t i = 0; i < subtract && cursor_ != nullptr; i++) {
                            	cursor_ = cursor_->getPrev();    
                    	}
                    	return *this;
                    }
                   
                    /**
                     * AdditionAssignment operator, supporting positive or negative ints
                     */
                    Iterator operator +=(int add)
                    {
                    	// If add is positive, it is supposed to increment
                         for (int i = 0; i < add && cursor_ != nullptr; i++) {
                            	cursor_ = cursor_->getNext();    
                    	}
                    	
                        // If add is negative, it is supposed to decrement
                        for (int i = 0; i > add && cursor_ != nullptr; i--) {
                                cursor_ = cursor_->getPrev();
                        	}
                    	return *this;
                    }
                   
                    /**
                     * SubtractionAssignment operator, supporting positive or negative ints
                     */
                    Iterator operator -=(int subtract)
                    {
                         for (int i = 0; i < subtract && cursor_ != nullptr; i++) {
                                cursor_ = cursor_->getPrev();
                        	}
                     	//If subtact is negative, it is supposed to decrement
                        for (int i = 0; i > subtract && cursor_ != nullptr; i--) {
                                cursor_ = cursor_->getNext();
                        	}
                    	return *this;

                    }
                   
                    /**
                     * Dereference operator returns a reference to the ELEMENT contained with the current node
                     */
                    T& operator*()
                    {
                        if (cursor_ != nullptr) {
                        	return this->cursor_->getElement();
                    	} 
                        	throw std::out_of_range("Can't return an empty reference buddy!");

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
                head_ = nullptr;
				tail_ = nullptr;
				size_ = 0;
            }
           
            /// Copy Constructor
            DoublyLinkedList(const DoublyLinkedList& other)
            {
             	clear();
             	Node* MJ = other.head_;
             	while (MJ != other.tail_){
             		push_back(MJ->getElement());
             		MJ = MJ->getNext();
		}
             	push_back(MJ->getElement());
            }
           
            /// DTOR
            ~DoublyLinkedList()
            {
               this->clear();
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
                this->clear();
                
                size_t Jared = 0;
                while (Jared < count) {
                	this->push_back(value);
                	++Jared;
                }
                
            }
           
            /**
             * Clear the list and assign values from another list.
             * The 'first' iterator points to the first item copied from the other list.
             * The 'last' iterator points to the last item copied from the other list.
             *
             * Example:
             *  Suppose we have a source list like {8, 4, 3, 2, 7, 1}
             *  Suppose first points to the 4 node
             *  Suppose last points to the 7 node
             *  We should end up with our list becoming: {4, 3, 2, 7}
             *
             * If the user code sends out-of-order iterators,
             *  just copy from 'first' to the end of the source list
             *
             * Example:
             *  If we have the same source list {8, 4, 3, 2, 7, 1},
             *  and first points to the 7 node,
             *  and last points to the 4 node,
             *  we would end up with: {7, 1}
             */
             //FUNNNY ASSIGNNNNNNNN
            void assign(Iterator first, Iterator last)
            {  
            	clear();
            	Node* Jokic = first.getCursor();
            	Node* Murray = last.getCursor();
            	
            	while ((Jokic != nullptr) && (Murray == nullptr || Jokic != Murray->getNext())){
            		push_back(Jokic->getElement());
            		Jokic = Jokic->getNext();
            	}
            }
           
            /// Return a pointer to the head node, if any
            Node* head() const
            {
                return head_;
            }
           
            /// Return a pointer to the tail node, if any
            Node* tail() const
            {
                return tail_;
            }
           
            /**
             * Return an iterator that points to the head of our list
             */
            Iterator begin() const
            {
                return Iterator(head_, tail_, head_);
            }
           
            /**
             * Return an iterator that points to the last element (tail) of our list
             */
            Iterator last() const
            {
                return Iterator(head_, tail_, tail_);
            }
           
            /**
             * Should return an iterator that represents being past the end of our nodes,
             * or just that we are finished.
             *
             * You can make this a nullptr or use some other scheme of your choosing,
             *  as long as it works with the logic of the rest of your implementations.
             */
            Iterator end() const
            {
                return Iterator(head_, tail_, nullptr);
            }
           
            /**
             * Returns true if our list is empty
             */
            bool empty() const
            {
                if (head_ == nullptr) {
                	return true;
            	} else {
                	return false;
            	}
            }
           
            /**
             * Returns the current size of the list
             *
             * Should finish in constant time!
             * (keep track of the size elsewhere)
             */
            size_t size() const
            {
                return size_;
            }
           
            /**
             * Clears our entire list, making it empty
             */
             
             //THIS CLEAR FUNCTION IS GONNA BE THE DEATH OF ME
             //IT'S ALWAYS CLEAR
            void clear()
            {
               Node* Shaq = this->head_;
               while (Shaq != tail_) {
               		if (Shaq != nullptr) {
               		Node* Kobe = Shaq->getNext();
               		delete Shaq;
               		Shaq = Kobe;  
               		}	  
               }
               this->head_ = nullptr;
	       this->tail_ = nullptr;
	       size_ = 0;
	       
            }
           
            /**
             * Insert an element after the node pointed to by the pos Iterator
             *
             * If the list is currently empty,
             *  ignore the iterator and just make the new node at the head/tail (list of length 1).
             *
             * If the incoming iterator is this->end(),
             *   insert the element as the new tail
             *
             * Should return an iterator that points to the newly added node
             */
            Iterator insert_after(Iterator pos, const T& value)
            {
                Node* insertedNode = pos.getCursor(); // This grabs the cursor of the pos iterator (or current position)
                
                if (pos == end()) {
                	return push_back(value);
                }
                
                if (head_ == nullptr) { //This first case is when the list is empty
                	head_ = new Node(value); // This sets the head to the new value
                	tail_ = head_; // This sets the tail to the head (since there is only one element
                	size_++; //Size increases
                	return Iterator(head_, head_, tail_); //This then returns the iterator of head, tail, tail (since same element lol)
                	
                } else if (insertedNode == nullptr) { //The inserted node sets the tail to new value, gets the next, 
                	tail_->setNext(new Node(value)); //This sets the tail's next to the new value
                	tail_->getNext()->setPrev(tail_); // This gets the next element, and sets prev ptr to the tail
                	tail_ = tail_->getNext(); // This sets the tail to the next element after the tail
                	size_++;
                	return Iterator(tail_, head_, tail_); //Returns the new value, head, and cursor is at tail
                	
                } else {
                	Node* diffInsertedNode = new Node(value); // This is the other case where list isn't empty, and new node != null
                	diffInsertedNode->setNext(insertedNode->getNext()); //Sets the next value of the previous element to its nxt
                	diffInsertedNode->setPrev(insertedNode); // Sets previous of the pos to the new value
                	insertedNode->setNext(diffInsertedNode); //This sets next node of previous value to the curspr
                	
                	if (diffInsertedNode->getNext() != nullptr) {
                	diffInsertedNode->getNext()->setPrev(diffInsertedNode); 
                	} else {
                	tail_ = diffInsertedNode; 
                	}
                	
           	size_++;
           	return Iterator(head_, tail_, diffInsertedNode);
           	}	
            }
           
            /**
             * Insert a new element after the index pos.
             * Should work with an empty list.
             *
             * If the user attempts to insert an element
             * That is out of range (eg ., size=5, index=13),
             * Just add to the end of the list
             *
             * Should return an iterator pointing to the newly created node
            */

            //PROFESSOR THIS IS MY 13TH REASON
            Iterator insert_after(size_t pos, const T& value)
            {
            if (pos >= size_) {
		return push_back(value);
	    }
            
            Iterator LeBron = begin(); //Thank you professor you are the best and i think we should get an extension
            	
            	for (size_t Anthony = 0; Anthony < pos; Anthony++) { //for count is less then position, iterator goes up
            		LeBron++; // This then moves up the iterator
            	} 
            	
            	return insert_after(LeBron, value); //Uses the iterator insert after         	
            }         	
           	
            /**
             * Erase the node pointed to by the Iterator's cursor.
             *
             * If the 'pos' iterator does not point to a valid node,
             *  throw an std::range_error
             *
             * Return an iterator to the node AFTER the one we erased,
             *  or this->end() if we just erased the tail
             */
            Iterator erase(Iterator pos)
            {
				Node* Kat = pos.getCursor();
              	Node* Ant = pos.getCursor()->getNext();	//nextNode
              	Node* Rud = pos.getCursor()->getPrev(); //prevNode
              	       
             if (Kat == this->head_) {
					this->head_ = Ant;
					if (this->head_ != nullptr) {
						Ant->setPrev(nullptr);
					}
					delete Kat;
					this->size_--;
					return Iterator(this->head_, this->tail_, this->head_);
				}

				if (Kat == this->tail_) {
					this->head_ = Rud;
					if (this->tail_ != nullptr) {
						Rud->setNext(nullptr);
					}
					delete Kat;
					this->size_--;
					return end();
				}

				Ant->setPrev(Rud);
				Rud->setNext(Ant);
				this->size_--;
				delete Kat;
	
				return Iterator(head_, tail_, Kat);
            }
               
            /**
             * Add an element just after the one pointed to by the 'pos' iterator
             *
             * Should return an iterator pointing to the newly created node
             */
             
             
            Iterator push_after(Iterator pos, const T& value)
            {
               if (head_ == nullptr) { //If the list is empty, insert during iterator and tail
               		return insert_after(last(), value);
               } else {
               		return insert_after(pos, value); //Inserts after the position and value 
            	}
           }
            /**
             * Add a new element to the front of our list.
             */
            void push_front(const T& value)
            {
                Node* newP = new Node(value);
           	 
            	if (head_ == nullptr) { //If empty, push front simply makes head and tail to the new value
                	head_ = newP;
                	tail_ = newP;
            	} else {
                	newP->setNext(head_); //This sets the new element's next to the head
                	head_->setPrev(newP); // This sets the old head's prev to the new element
                	head_ = newP; // This sets the head to the new element
            	}
            	size_++;

            }
           
            /**
             * Add an element to the end of this list.
             *
             * Should return an iterator pointing to the newly created node.
             */
            Iterator push_back(const T& value)
            {
                Node* newQ = new Node(value);
           	 
            	if (tail_ == nullptr) {
                	head_ = newQ;
                	tail_ = newQ;
            	} else {
                	newQ->setPrev(tail_);
                	tail_->setNext(newQ);
            	}
            	tail_ = newQ;
            	size_++;
            	return Iterator(newQ, head_, tail_);
            }
           
            /**
             * Remove the node at the front of our list
             *
             * Should throw an exception if our list is empty
             */
            void pop_front()
            {
                if (head_ == nullptr) {
                	throw std::range_error("Ah Ah Ah! You can't delete what's already empty Silly Wabbit! ");
            	}
           	 
            	Node* poppedHead = head_;
            	head_ = head_->getNext();
            	if (head_ != nullptr) {
                	head_->setPrev(nullptr);
            	}
            		tail_ = nullptr;
           	 
            	delete poppedHead;
            	size_--;
            	

            }
           
            /**
             * Remove the node at the end of our list
             *
             * Should throw an exception if our list is empty
             */
            void pop_back()
            {
                if (head_ == nullptr && tail_ == nullptr) {
                	throw std::range_error("We went over this! What are you doing? C'mon! Do Better!");
            	}
           	 
            	Node* poppedTail = tail_;
           	 
            	if (tail_ != nullptr) {
                	tail_ = tail_->getPrev();
            	}
            	delete poppedTail;
            	size_--;
           	 
            	if (size_ <= 0 && tail_== nullptr) {
                	head_ = nullptr;
            	}

            }
           
            /**
             * Return a reference to the element at the front.
             *
             * Throw an exception if the list is empty
             */
            T& front()
            {
                if (head_ == nullptr) {
                	throw std::range_error("Wow you really don't learn! It's empty! Nothing is there!");
            	}
            	return head_->getElement();
            }
           
            /**
             * Return a reference to the element at the back.
             *
             * Throw an exception if the list is empty
             */
            T& back()
            {
                if (head_ == nullptr) {
                	throw std::range_error("Oh, you're starting to piss me off... you jackrabbit son of a [BLEEP]");
            	}
           	 
            	return tail_->getElement();
            }
           
            /**
             * Return the element at an index
             *
             * Should throw a range_error is out of bounds
             */
            T& at(size_t index)
            {	 
            	
            	if (index >= size_) { 
                	throw std::range_error("Ok first you try to do stuff with an empty list, now this?");	
                }
            	
            		Node* Abi = head_;
            		if (Abi != nullptr) {
            		for (size_t count = 0; count < index; ++count) {
            			Abi = Abi->getNext();
            		}
           	}
                return Abi->getElement();
            	
            }
           
            /**
             * Reverse the current list
             */
            void reverse()
            {
               
               DoublyLinkedList<T> reverseList; // Create a temporary list
           	 
            	Node* newFirst = head_; // New first is where we start from
           	
            	while (newFirst != nullptr) {
                	reverseList.push_front(newFirst->getElement()); //We grab the head element, then push it front 
                	newFirst = newFirst->getNext(); // Grab the next few elements, then push those to the front
            	}
           	 
            	head_ = reverseList.head_; //Replace the head with the temp list head
            	tail_ = reverseList.tail_; //Same as the top but with the tail
            	size_ = reverseList.size_; //Same as the other 2 except you're setting the size
            	
            	
            	reverseList.head_ = nullptr; //List falls out of scope, which dies out, set head and tail to null and size to 0
            	reverseList.tail_ = nullptr;
            	reverseList.size_ = 0;
            }
           
            /**
             * I bet you're happy I'm not making you do this.
             * No tests will be run against this function,
             *  but feel free to try it out, as a challenge!
             *
             * If I were doing this and didn't care too much for efficiency,
             *  I would probably create an extra helper function to swap two
             *  positions in the current list.
             * Then I would simply sweep through the list and perform
             *  the bubble-sort algorithm. Perhaps selection sort.
             *
             * If you want a huge challenge, try implementing quicksort.
             *
             * (but again, don't worry about this method; it will not be tested)
             */
            void sort()
            {
                //I'll do this later (never)
            }
           
            /**
             * Assignment operator
             *
             * Clear this list and fill it with the others' values
             * (by value, not by reference)
             *
             * Return a reference to this list
             */
             
             //tempHead == nullptr causes segfault
             //Pushback call is specifically where it causes segfault
             //13th Reason why.
            DoublyLinkedList<T>& operator =(DoublyLinkedList<T>& other)
            { 
                clear();
             	Node* KB = other.head_;
             	while (KB != other.tail_){
             		push_back(KB->getElement());
             		KB = KB->getNext();
		}
             	push_back(KB->getElement());
             	return *this;
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
               if (size_ != other.size_){
               		return false;
               }
               
               Node* Tam = head_;
               Node* Vincent = other.head_;
               
               while (Tam != nullptr && Vincent != nullptr) {
			if (Tam->getElement() != Vincent->getElement()){
			return false;
			}
			Tam = Tam->getNext();
			Vincent = Vincent->getNext();
		}
		return true;
            }
           
            /**
             * Return true if the lists are "not equal"
             *
             * See the operator== stub for definition of "equal"
             */
            bool operator !=(DoublyLinkedList<T>& other)
            {
            	return !(*this == other);
                
            }
           
        private:
           
            Node* head_ = nullptr;
            Node* tail_ = nullptr;
            size_t size_ = 0;
    };
}





#endif