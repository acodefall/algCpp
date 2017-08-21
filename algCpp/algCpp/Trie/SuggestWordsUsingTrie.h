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

namespace SuggestWordsUsingTrieNM //@RED20170819001
{

	/*								
		
		Suggest word to user_RED20170819001
			If the user types 'new' then show {news, newspaper}. {news, newspaper} will be in a dictionary. 
			Load the dictionary in to TRIE. Then starting from Root, trace the pah of the word NEW. 
			After reaching the node for W, explore the every child of node-W, until the leaf. 
			All along the way record every word. 
			
			TRIE
				w o r l d 
						  c u p
				n e W
			          s p a p e r
			            a r t i c l e
			BaseWord: "new" 
			SuggestedWords: {news, newspaper, newsarticle}
	*/
	
	//Node used for storing words
	class TrieNode
	{
		public:
			map<char, TrieNode*> child;	//char will store each letter of word 
			int eow;
			
			TrieNode()
			{
				eow = 0;
				for (int i = 'a'; i < ('a' + 26); i++)
				{
					child.insert(pair<char, TrieNode*>(i, 0));
				}
			}
	};

	class SuggestWordsUsingTrie
	{
	public:
		TrieNode* root;
		SuggestWordsUsingTrie()
		{
			root = new TrieNode();
		}
	
		//If the user types 'new' then show {news, newspaper}
		//baseWord: will have 'new'
		//suggestedWordList: will have {news, newspaper}
		void PrintAllWordSuggestions(TrieNode* cur, string baseWord, list<string>& suggestedWordList)
		{
			//Navigate to the end of baseWord (say New)
			int len = baseWord.length();
			const char* wrd = baseWord.c_str();
			for (int i = 0; i < len; i++)
			{
				if (cur->child[wrd[i]]) //found the 1st letter, go in to 1st letter by setting it to cur
				{
					cur = cur->child[wrd[i]];
				}
				else
				{
					cout << "Base word '" << wrd << "' is missing" << endl;
					return;
				}
			}

			//Fetch the words in downstream that appear after "NEW"
			//Explore the every child of node-W, until the leaf. 
			//We should have two threads 'articles' & 'spapers'
			string dummy = baseWord;
			FetchSuffixes(cur, dummy, suggestedWordList);
			return;
		}
		
		void FetchSuffixes(TrieNode* cur, string word, list<string>& suggestedWordList)
		{
			//cur will be pointing at W (of newW). We have to explore the child-threads starting W-node.
			//We should have two threads 'articles' & 'spapers'
			//         
			//	n e W  
			//        s p a p e r 
			//        a r t i c l e
			if (cur != NULL)
			{
				//Node is VALID, 
				//a) check whether EOW is present
				//b) if so record the letter
				//b) then drill down children 
					
				//if EOW is found then word should be treated as suggested word
				//so add it to suggestedWordList
				if (cur->eow)
				{
					suggestedWordList.push_back(word);
				}

				//go through the child-map. Map will give LETTER and also child node
				//Add LETTER to suggestedWord
				//Recurse in to child node
				for (int i = 'a'; i <= 'z'; i++)
				{
					string wordTillNow = word; //store the word on stack; This will be "neW"
					if (cur->child[(char)i] != NULL)
					{
						wordTillNow += (char)i;	////Add LETTER to suggestedWord
						FetchSuffixes(cur->child[(char)i], wordTillNow, suggestedWordList);
					}
				}
			}
		}

		//insert the word in to TRIE
		void addWord(char* word)
		{
			TrieNode* cur = root;
			int len = strlen(word);
			for (int i = 0; i < len; i++)
			{
				//Iterate the word letter by letter and insert in to TRIE
				if (((int)word[i] >= 'a') && ((int)word[i] <= 'z'))
				{
					//Letter is not in TRIE so create it
					if (cur->child[word[i]] == NULL)
					{
						cur->child[word[i]] = new TrieNode();
					}

					//Go to the child of 
					cur = cur->child[word[i]];
				}
			}

			//When we hit the last letter of the word set EOW.
			if (cur != root)
			{	
				cur->eow = 1;
			}
		}
	};

	class UseSuggestWordsUsingTrie
	{
	public:
		void CallSuggestWordsUsingTrie()
		{
			SuggestWordsUsingTrie objTrieM;
			
			//Add the words to dictionary
			list<string> wrdList;
			wrdList.push_back("new");
			wrdList.push_back( "news");
			wrdList.push_back("newspaper");
			wrdList.push_back("newsarticle");
			wrdList.push_back("world");
			wrdList.push_back("worldcup");
			//add the words to trie
			for (auto itr = wrdList.begin(); itr != wrdList.end(); itr++)
			{
				objTrieM.addWord((char*)(*itr).c_str());
			}


			//find the suggested words for baseWord "NEW" inside TRIE
			//	n e W  
			//        s p a p e r 
			//          a r t i c l e
			string baseWord= "new";
			list<string> suggestedWordList;
			objTrieM.PrintAllWordSuggestions(objTrieM.root, baseWord, suggestedWordList);
			cout << endl << "suggested words for '" << baseWord << "'" << endl;
			for (auto itr = suggestedWordList.begin(); itr != suggestedWordList.end(); itr++)
			{
				cout << (char*)(*itr).c_str() << endl;
			}


			/*
			TRIE
				w o r l d 
						  c u p
				n e W
			          s p a p e r
			            a r t i c l e
			BaseWord: "new" 
				suggested words for 'new'
					new
					news
					newsarticle
					newspaper
			*/
		}
	};

};