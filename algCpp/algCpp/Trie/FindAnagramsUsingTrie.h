#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iomanip>
#include <unordered_set>
using namespace std;

namespace FindAnagramsUsingTrieNM
{

	/*								
		Print the Anagram and also the origianl words used for making anagram TRIE_@RED20170816002
			Think anagram as one signature used for representing several words that are made up of same letters but placed in different order.
			Ex: ART and RAT contain same letters, placed in different order. Sorting these words will give signature and that is anagram. 
			We can also say that Anagram/Signature could be representing several different words. 
			Ex: 'Dgo' is signature/anagram for 'Dog' and 'God'
			Our program should print the Dog and God when the input is 'Dgo'
        	In order to support this, TRIE should connect Original source words and their Anagram. This means connecting God, Dog with thier anagram Dgo.
			TRIE node will store the letters of Anagram (example: DGO).
			Then the Node of the last letter will store the list of source words(Dog, God) in a Linked List.
			
			This is implemented as follow:
				Insert(anagram, list of original words)
					Store the anagram in TRIE nodes. When we reach the last letter, store the list of origal words also.

				FetchAnagrams(anagram)
					Use anagram for navigating TRIE. Once at the last letter, get teh LL of original words and return to caller. 			
	*/
	
	//Node used for storing Anagram and also the source words used for making Anagram.
	class TrieNode
	{
		public:
			map<char, TrieNode*> child;	//char will store each letter of Anagram 
			int eow;
			list<string> originalWord;	//Original Words who's anagram we are storing. Ex: If Anagram'dgo' represents Dog, God. 
										//Then TRIE will 'dgo' and originalWord will have Dog and God
			TrieNode()
			{
				eow = 0;
				for (int i = 'a'; i < ('a' + 26); i++)
				{
					child.insert(pair<char, TrieNode*>(i, 0));
				}
			}
	};

	class FindAnagramsUsingTrie
	{
	public:
		TrieNode* root;
		FindAnagramsUsingTrie()
		{
			root = new TrieNode();
		}
		void findAnagram(char* anagram, list<string>& originalWords)
		{
			bool missingLetter = false;
			TrieNode* cur = root;
			int len = strlen(anagram);
			for (int i = 0; i < len; i++)
			{
				if (cur->child[anagram[i]] == NULL) //could not find one of the LETTER so break
				{
					missingLetter = true;
					break;
				}
				cur = cur->child[anagram[i]]; //move to next LETTER
			}

			//All the letters of the word are present. check wether there is EOW at the end.
			if (missingLetter == false)
			{
				if (cur->eow == true)
				{
					//found the word. Now take the list of original words and return them to the caller.
					for (auto itr = cur->originalWord.begin(); itr != cur->originalWord.end() ; itr++)
					{
						originalWords.push_back(*itr);
					}
				}
			}
		}
		
		//insert the word in to TRIE
		//sourceWords: are used for making anagram. Think about anagram as signature of word
		void addWord(char* anagram, list<string>& sourceWords)
		{
			TrieNode* cur = root;
			int len = strlen(anagram);
			for (int i = 0; i < len; i++)
			{
				//Iterate the word letter by letter and insert in to TRIE
				if (((int)anagram[i] >= 'a') && ((int)anagram[i] <= 'z'))
				{
					//Letter is not in TRIE so create it
					if (cur->child[anagram[i]] == NULL)
					{
						cur->child[anagram[i]] = new TrieNode();
					}

					//Go to the child of 
					cur = cur->child[anagram[i]];
				}
			}

			//When we hit the last letter of the Anagram(say DGO), set EOW and also attach the wordlist(DOG. GOD)
			if (cur != root)
			{	
				cur->eow = 1;
				if (sourceWords.size() > 0)
				{
					for (auto itr= sourceWords.begin(); itr != sourceWords.end(); itr++)
					{
						cur->originalWord.push_back(*itr);
					}
				}
			}
		}

		
		
		

	};

	class UseFindAnagramsUsingTrie
	{
	public:
		void CallUseFindAnagramsUsingTrie()
		{
			FindAnagramsUsingTrie objTrieM;
			
		
			//Add anagram and the orignal words represented by Anagram
			string anagram("dgo");
			list<string> wrdList;
			wrdList.push_back("dog");
			wrdList.push_back( "god");

			objTrieM.addWord((char*)anagram.c_str(), wrdList);
			
			
			string anagram1("art");
			list<string> wrdList2;
			wrdList2.push_back("art");
			wrdList2.push_back("rat");

			objTrieM.addWord((char*)anagram1.c_str(), wrdList2);

			string s1("dgo");
			list<string> wrdListR1;
			objTrieM.findAnagram((char*)s1.c_str(), wrdListR1);
			cout << "Wordlist for Anagram '" << s1.c_str() << "' " << endl;
			for (auto itr = wrdListR1.begin(); itr != wrdListR1.end(); itr++)
			{
				cout << *itr << endl;
			}
		}
	};

};