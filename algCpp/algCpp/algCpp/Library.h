#pragma char once
#include <iostream>
#include <list>
#include <string>
#include <map>
using namespace std;
namespace LibraryNM
{

	class Fuckyou
	{
	public:
		string title;


	};




	class BarrowedBooks;
	class Book;
	class Author;
	class Reader
	{
	public:
		string name;
		list<Book*> readingBook;
	};



	class Book
	{
	public:
		string title;


	};

	struct compareBook
	{

		string title;
		compareBook(string titleN)
		{
			title = titleN;
		}
		bool operator()(Book* b2)
		{
			if (title == b2->title)
				return true;
			else
				return false;
		}
	};

	class Author
	{
	public:
		string name;
		list<Book*> works;
		friend Reader;
	};

	class BarrowedBooks
	{
	public:
		list<Author>::iterator author;
		list<Book>::iterator book;
		friend Reader;
	};
	class Library
	{
	public:
		map<string, Author*> authorList;
		map<string, Reader*> readerList;
		//map<char, Book*>   readingBookList;
		Library()
		{

		}
		//If the author is new, then create 'Author', add author-instance to the authorList.
		//and then create 'Book' and add  it to newly created author-instance

		//if the author is already existing, then also create 'Book' and add  it to existing author-instance
		//if the book is 
		void AddBook()
		{

			string bkNTitle;
			string authN;
			cout << "Enter book name";
			cin >> bkNTitle;

			cout << "Enter author name";
			cin >> authN;
			Book* bk = new Book();
			bk->title = bkNTitle;

			//existing author so add the book to author's class
			if (authorList.find(authN) != authorList.end())
			{
				authorList[authN]->works.push_back(bk);
			}
			else
			{ //Author is not existing,
				Author* ath = new Author();
				ath->name = authN;
				ath->works.push_back(bk);
				authorList.insert(pair<string, Author*>(authN, ath));
			}
		}

		void AddUser()
		{
			string user;
			string authN;
			cout << "Enter user name";
			cin >> user;

			//existing author so add the book to author's class
			if (readerList.find(user) == readerList.end())
			{
				//User is not existing,
				Reader* rdr = new Reader();
				rdr->name = user;
				readerList.insert(pair<string, Reader*>(user, rdr));
			}
		}

		void checkOutBook()
		{
			string bkNTitle;
			string authN;
			string rdr;

			cout << "Enter book name";
			cin >> bkNTitle;

			cout << "Enter author name";
			cin >> authN;

			cout << "Enter reader name";
			cin >> rdr;

			Book* bk = new Book();
			bk->title = bkNTitle;

			if (authorList.find(authN) != authorList.end())
			{
				//Implement == operator on Book, so that find can work
				list<Book*>::iterator itr = find_if(authorList[authN]->works.begin(), authorList[authN]->works.end(), compareBook(bkNTitle));
				readerList[rdr]->readingBook.push_back(*itr);
			}
		}
	};
};