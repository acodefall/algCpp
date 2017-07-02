#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <fstream>
using namespace std;

namespace TrieNM
{

	/*
		ForwardIndex and InvertedIndex
		Forward Index is a map of words to line-number or database rows. Inverted index is a map of words to books and websites. Example for Forward is index at the end of the book.
		Example for inverted index is googlesearch, where we give a word, and search engine comes back with websites containing those terms.

		Buidling Inverted Index for books.
		Say we have few books and would like to build inverted index out of it. Extract the words from books and load them in to TRIE. 
		At the node where word ends, store the name of the books. Now the inverted index is ready; when user searches for the word, we go to that word in TRIE. TRIE will tell us which all books are holding reference to them.

		Steps: (building WORD -> BookNames Inverted Index)
				1) Extract words from Book
				2) Load them in to TRIE
				3) EOW nodes of TRIE should store name of the book
				4) Expose the method to retrieve the book-name, when searched using WORD
	*/
	class TrieNode
	{
		public:
				map<char, TrieNode*> child;
				int eow;
				vector<string> fileNames;

				TrieNode()
				{
					eow = 0;
					for (int i = 'a'; i < ('a' + 26); i++)
					{
						child.insert(pair<char,TrieNode*>(i,0));
					}
				}
	};

	class TrieM
	{
		public:
			TrieNode* root;
			TrieM()
			{
				root = new TrieNode();
			}
			void indexFile(string filename)
			{
				string line;
				fstream fname(filename);
				while (getline(fname, line))
				{
					const char* p = line.c_str();
					char word[255] = { 0 };
					int len = strlen(p);
					int c = 0;
					int w = 0;
					while (c < len)
					{
						if (c == ' ')
						{
							if (w > 0)
							{
								word[w] = 0;
								addWord(word, line);
								w = 0;
								word[w] = 0;
							}
						}
						else
						{
							word[w++] = c;
						}
						c++;
					}
				}

			}
			void addWord(char* line, string filename)
			{
				TrieNode* cur = root;
				int len = strlen(line);
				for (int i = 0; i < len; i++)
				{
					//Ignore the word if it is not an A-Z
					if (((int)line[i] >= 'a') && ((int)line[i] <= 'z'))
					{
						if (cur->child[line[i]] == 0)
						{
							cur->child[line[i]] = new TrieNode();
						}

						cur = (TrieNode*)cur->child[line[i]];
					}
				}

				if (cur != root)
				{	//something has been assigned	
					cur->eow = 1;
					cur->fileNames.push_back(filename);
				}
			}

			void find(char* line)
			{
				TrieNode* cur = root;
				int notFound = 0;
				int len = strlen(line);
				for (int i = 0; i < len; i++)
				{
					//Ignore the word if it is not an A-Z
					if (cur->child[line[i]] == 0)
					{
						notFound = 1;
						break;
					}
	
					cur = (TrieNode*)cur->child[line[i]];
				}

				if ((notFound == 0) && (cur->eow != 0))
				{	
					for (vector<string>::iterator itr = cur->fileNames.begin(); itr != cur->fileNames.end(); )
					{
						cout << *itr << "\r\n";

					}
				}

				return ;
			}


	};

	class UseInvertedIndex
	{
		public:
				void CallUseInvertedIndex()
				{
					TrieM objTrieM;

					objTrieM.indexFile("c:\\sample1.txt");
					objTrieM.indexFile("c:\\sample2.txt");

					 objTrieM.find("rama");

				}
	};

};