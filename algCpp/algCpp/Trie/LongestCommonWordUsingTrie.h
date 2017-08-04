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

namespace LongestCommonWordUsingTrieNM //@RED20170803004
{

	/*
		
		Implement TelePhone directory using TRIE_20170803004
			Load the UserName and thier Telephone number in to TRIE. Store the  Telephone number on the node that has EOW( the node that has last letter of user name)
			Then iterate the TRIE to gather both UserName and Telephone number, and print them
			
	*/
	
	//Node with EOW flag will have the last lettter of the WORD
	class TrieNode
	{
		public:
			map<char, TrieNode*> child;  //char will store each letter of WORD
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

	class LongestCommonWordUsingTrie
	{
	public:
		TrieNode* root;
		LongestCommonWordUsingTrie()
		{
			root = new TrieNode();
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
					if (cur->child[word[i]] == 0)
					{
						cur->child[word[i]] = new TrieNode();
					}

					cur = (TrieNode*)cur->child[word[i]];
				}
			}

			//When we hit the last letter of WORD, so set EOW 
			if (cur != root)
			{	
				cur->eow = 1;
			}
		}

		//We are interested in NonCompound word, means the word that has no letters after the first EOW node.
		//Cmpnd word will have letter after the node with EOW.
		//In case of both Cpmpd & NonCmpd words, do not make any more recursion calls; we do not want to go down any further after the first EOW node.
		//If the word is compund, do not record; otherwise record it.
		//Iterate from root and keep on checking for EOW. If the node has EOW and also has at least one non-null child node, then word is compound word. 
		//Do not record. If all of the child nodes are NULL, then word is non-compound word, record it.
		//In both the return, 
		void extractFirstWord(TrieNode* curIn, string word, string& firstWord)
		{
			const char* tmp = word.c_str();
			TrieNode* cur = curIn;
			for (int i = 0; i <= word.length(); i++) // "<=" is used because the Root node is not having the 1st letter of the word being searched.
			{										 //First character is actually in 2nd node of the thread of nodes.
				if (cur->eow)
				{	//Exit as soon as we get 1st EOW. 
					//This marks the end of first the WORD
					//, check whether any child node is valid. Then WORD is compound, then do not record.
					//If all the child nodes are NULL, then WORD is non-compound, record it.
					firstWord = word.substr(0, i);
					return;
				}
				cur = cur->child[tmp[i]];
			}
			return;
		}
		//Find LCW
		//Find the inter mediatory words and check whether they are in 
		//'betweenWord' is the word between two EOWs. "catRatDog" betweenWord could be 'Rat', Dog'
		void TraverseAndFindLCW(TrieNode* cur, string betweenWord, string wholeWord, unordered_set<string>& nonCompndWordList, string& longestLCW)
		{
			if (cur != NULL)
			{
				//This conditon won't apply for root node
				if (cur->eow)
				{	
					//This marks the end of the word, check whether 'betweenWord' is non-cpmd word
					if (nonCompndWordList.find(betweenWord) == nonCompndWordList.end())
					{	//betweenWord is a compound word so exit
						cout << "word '" << betweenWord.c_str() << "' is a compound word so ignore whole word '" << wholeWord.c_str() << "'" << endl;
						//do not make any recursion calls exit.
						return;
					}
					else
					{	//betweenWord is non-compound word so exit
						cout << "word '" << betweenWord.c_str() << "' is a non-compound word so continue to decompose whole word '" << wholeWord.c_str() << "'" << endl;
					}
					

					//reset the betweenWord. This is because betweenWord records the word between two EOWs
					betweenWord = "";
				}

				bool endOfThread = true;
				//Go through the child list, if the all the child objects are NULL, then we are the end of the thread. 
				//In that case we have check whether word is LCW
				//CHARACTER is considered part of the WORD, so add the CHAR to 'word'
				for (int i = 'a'; i < ('a' + 26); i++)
				{
					if (cur->child[i] != NULL)
					{
						endOfThread = false;
						//Add the current character to whole word & betweenWord.
						string wholeWordTmp;// += (char)i;
						string betweenWordTmp;// += (char)i;

						wholeWordTmp = wholeWord + (char)i;
						betweenWordTmp = betweenWord + (char)i;
						//We want to know whether 'cur->child[i]' is EOW or has children.
						//To know that make recursion call
						TraverseAndFindLCW(cur->child[i], betweenWordTmp, wholeWordTmp, nonCompndWordList, longestLCW);
					}
				}

				//if we have reached this point, it means all the words in this theard were Non-compoundword.
				//So this is a word that is totally madeup of Non-Compund words, so check whether this word is longest amond LCW 
				if (endOfThread)
				{
					//whole word should be a Compound word to qualify for LCW verification.
					//so make sure wholeWord is not part of nonCompndWordList
					if (nonCompndWordList.find(wholeWord) == nonCompndWordList.end())
					{
						if (longestLCW.length() < wholeWord.length())
						{
							cout << "End of thread. Word is LCW '" << wholeWord.c_str() << "'" << endl;
							longestLCW = wholeWord;
						}
					}
					else
					{
						cout << "End of thread. Word is not compound word at all '" << wholeWord.c_str() << "' so ignore it" << endl;
					}
				}
			}
			return;
		}


	};

	class UseLongestCommonWordUsingTrie
	{
	public:
		void CallLongestCommonWordUsingTrie()
		{
			LongestCommonWordUsingTrie objTrieM;
			list<string> rawWordList;
			rawWordList.push_back("cat");
			rawWordList.push_back("cats");
			rawWordList.push_back("catsdogcats");
			rawWordList.push_back("catxdogcatsrat");
			rawWordList.push_back("dog");
			rawWordList.push_back("dogcatsdog");
			rawWordList.push_back("hippopotamuses");
			rawWordList.push_back("rat");
			rawWordList.push_back("ratcatdogcat");
			//{ "cat", "cats", "catsdogcats", "catxdogcatsrat", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat" };


			cout << "Load the words in to TRIE" << endl;
			for (auto itr = rawWordList.begin(); itr != rawWordList.end(); itr++)
			{
				objTrieM.addWord((char*)(*itr).c_str());
			}

			//among the input words, there will be compound words and non-compound words.
			//make a list of noncompound words.
			string firstWord;
			unordered_set<string> nonCompndWordList;
			for (auto itr = rawWordList.begin(); itr != rawWordList.end(); itr++)
			{
				objTrieM.extractFirstWord(objTrieM.root, (*itr) ,firstWord);
				nonCompndWordList.insert(firstWord);
			}

			//Go through the list of noncompound words and record the longest word

			//find the LCW
			string wholeWord;
			string wordBtwnEOW;
			string longestLCW;
			
			objTrieM.TraverseAndFindLCW(objTrieM.root, wordBtwnEOW, wholeWord, nonCompndWordList, longestLCW);
			cout << "LCW is '"<< longestLCW.c_str() <<"'" << endl;
			/*
				Phone number of 'one' 111111
				Phone number of 'hundred' 1001000
					cot  141616716781
					cotton  99999999999
					hundred  1001000
					one  111111
					two  222222

			*/
		}
	};

};