#include "BookStore.hpp"


//
#include <iostream>
#include <sstream>
#include <string>


//
using std::cout, std::cin, std::endl;
using std::string, std::to_string;
using std::stringstream;


//
namespace CPSC131::BookStore
{

	/// Your welcome
	BookStore::BookStore() {}
	
	/**
	 * Adjust the store's account balance
	 * Should accept positive or negative adjustments
	 */
	void BookStore::adjustAccountBalance(int adjustment)
	{
		account_balance_ += adjustment;
	}
	
	/**
	 * Return the store's current account balance
	 */
	int BookStore::getAccountBalance() const
	{
		return account_balance_;
	}
	
	/**
	 * Find a book by its ISBN
	 * 
	 * Return this->bookList.end() if the book isn't found.
	 * 
	 * Return an interator pointing to the Book if it is found.
	 */
	DoublyLinkedList::DoublyLinkedList<Book>::Iterator BookStore::findBook(std::string isbn) const
	{
		 
		for (auto harryPotter = this->book_list_.begin(); harryPotter != this->book_list_.end(); ++harryPotter) { 
			if ((*harryPotter).getIsbn() == isbn) { // If the ISBN matches with the isbn
				return harryPotter; // Return the iterator since book was found
			}
		}
		
		return this->book_list_.end(); //Return end if it's not found
	}
	
	/**
	 * Check whether a book exists, by its ISBN
	 * 
	 * Return true if it exists, or false otherwise
	 */
	bool BookStore::bookExists(std::string isbn) const
	{
		return (findBook(isbn) != book_list_.end()); //Checks if the book list exists by making sure it doesn't equal to end
	}
	
	/**
	 * Check the quantity of stock we have for a particular book, by ISBN
	 * 
	 * If the book doesn't exist, just return 0
	 */
	size_t BookStore::getBookStockAvailable(std::string isbn) const
	{
		auto book = findBook(isbn);
		
		if (book == book_list_.end()) {
			return 0;
		} else {
			return (*book).getStockAvailable();
		}
	}
	
	/**
	 * Locate a book by ISBN and return a reference to the Book
	 * 
	 * If the book doesn't exist, throw an exception
	 */
	Book& BookStore::getBook(std::string isbn) const
	{
	
		auto TKAMB = findBook(isbn);
		if (TKAMB != book_list_.end()) {
			return (*TKAMB);
		} else {
			throw InsufficientInventory("Whoaaa there! Sorry this book doesn't exist here! Try your nearest B & N!");
		}
		
	}
	
	/**
	 * Take a Book instance and add it to inventory
	 * 
	 * If the book's ISBN already exists in our store,
	 * 	simply adjust account balance by the book's price and quantity,
	 * 	but ignore other details like title and author.
	 * 
	 * If the book's ISBN doesn't already exist in our store,
	 * 	adjust our account balance and push the book into our list
	 */
	void BookStore::purchaseInventory(const Book& book)
	{
		
		auto Metamorphosis = findBook(book.getIsbn());
		
		if (Metamorphosis != book_list_.end()){ 
			account_balance_ -= (book.getPriceCents() * book.getStockAvailable());
			(*Metamorphosis).adjustStockAvailable(book.getStockAvailable());
			
		} else {
		
			book_list_.push_back(book);
			account_balance_ -= (book.getPriceCents() * book.getStockAvailable());
		}
		
	}
	
	/**
	 * Take some book details and add the book to our inventory.
	 * 
	 * Use the same rules as the other overload for this function.
	 * 
	 * You might want to avoid repeating code by simply building a Book
	 * 	object from the details, then calling the other overload
	 * 	with the new Book object.
	 */
	void BookStore::purchaseInventory(
		std::string title, std::string author, std::string isbn,
		size_t price_cents,
		size_t unit_count
	)
	{
		Book book (title, author, isbn, price_cents, unit_count);
		purchaseInventory(book);
	}
	
	/**
	 * Print out inventory.
	 * Should be in a particular way to earn unit test points.
	 * Example (ignore the asterisks at the left of this comment block):
	 * 
	 * *** Book Store Inventory ***
	 * "Book1", by Author1 [123] (5 in stock)
	 * "Book2", by Author2 [456] (19 in stock)
	 * 
	 * Should print a trailing std::endl after the last book line, for the unit tests
	 */
	void BookStore::printInventory() const
	{
		std::cout << "*** Book Store Inventory ***" << std::endl;
		
		for (auto inventory = book_list_.begin(); inventory != book_list_.end(); inventory++) {
			std::cout << "\"" << (*inventory).getTitle() <<"\", by " << (*inventory).getAuthor() << " [" 
				  << (*inventory).getIsbn() << "] " << "(" << (*inventory).getStockAvailable() 
				  << " in stock)" << std::endl;
		}
	}
	
	/**
	 * Sell a book to a customer!
	 * 
	 * Takes the ISBN of the book, the selling price of the book, and the quantity of books sold
	 * 
	 * Uses the same rules as the other overload.
	 * 
	 * You may wish to just grab a reference to the book and call the other overload,
	 * 	to avoid repeating code
	 */
	void BookStore::sellToCustomer(std::string isbn, size_t price_cents, size_t quantity)
	{
		auto temp = findBook(isbn);
		
		if (temp == book_list_.end()) {
			throw InsufficientInventory("Whoaaa there! Sorry this book doesn't exist here! Try your nearest B & N!");
		} else {
			Book &book = *temp;
			sellToCustomer(book, price_cents, quantity);
		}		
	}
	/**
	 * Sell a book to a customer!
	 * 
	 * Takes a Book reference, the selling price of the book, and the quantity of books sold
	 * 
	 * If we don't have enough of this book in stock for the quantity the customer wants to purchase,
	 * 	throw an std::range_error
	 * 
	 * Otherwise, adjust the stock available in our store, and update our account balance.
	 */
	void BookStore::sellToCustomer(Book& book, size_t price_cents, size_t quantity)
	{
		if (book.getStockAvailable() < quantity) { 
			throw InsufficientInventory("Looks like you're gonna have to pirate that book! We don't have it!");
		} else {
			book.adjustStockAvailable(-(int)quantity);
			adjustAccountBalance(price_cents * quantity);
		}
		
	}
	
}