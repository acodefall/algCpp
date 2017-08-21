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

namespace LongestCommonPrefixUsingTrieNM //@RED20170819002
{
	/*								
		Find longest common prefix_@RED20170819002
			LCP is the common prefix among several words. "New", "News", "Newspaper", "NewsArticle"
			Longest common prefix is the First word of the longest thread found in Trie.
			Logic for computing LCP is.
			Traverse the whole TRIE. Record the firstPrefix, "longest word" and "Lcp" in 3 variable.
			Update these variables when ever we come across EOW.
			Whenever EOW is encountered, compare the length of currenWord against existing "longest word", if the currenWord is longer, then assign 
			currenWord to "longest word", and assign  firstPrefix to Lcp.
			Once we complete the traversal we will have the LCP.
				
				if(EOW)
					if( LEN(currentWord) > LEN(longestWord))
						longestWord = currentWord
						LCP = firstPrefix

		TRIE
			W o r l d
			          c u p
					      l t u r e
			N e w 
			      s p a p e r
			        a r t i c l e 
			
		LCP is World

	*/
	
	//Node used for storing word
	class TrieNode
	{
		public:
			map<char, TrieNode*> child;	//char will store each letter of word 
			int eow;
			
			TrieNode()
			{
				eow = 0;
				for (int i = 'a'; i <= 'z' ; i++)
				{
					child.insert(pair<char, TrieNode*>(i, 0));
				}
			}
	};

	class LongestCommonPrefixUsingTrie
	{
	public:
		TrieNode* root;
		LongestCommonPrefixUsingTrie()
		{
			root = new TrieNode();
		}
		


		//
		//wordThread - Many 'thread of word' will begin from root and goes until the leaf.
		//			    wordThread holds the 'thread of word' currently being traced. 
		//             So whenever the cursor reaches the root node, reset wordThread to "", and start storing the new word. 
		//			   wordThread could have "newspaper" then it could change to "worldcup"
		//firstPrefixword - 1st word found in the wordThread. Ex: For "newspaper", "new" is the firstPrefixword
		//longestThread -	This should have the longest word AS OF NOW. 
		//					Whenever EOW is encountered,
		//					if(EOW)
		//						if( LEN(currentWord) > LEN(longestWord))
		//							longestWord = currentWord
		//							LCP = firstPrefix
								
		void FindLCP(TrieNode* cur, string firstPrefixword, string currentWord, string& longestWord, string& LCP)
		{
			if (cur != NULL)
			{	//Node is VALID, 
				//a) check whether EOW is present
				//b) if so record the letter
				//b) then drill down children 

				//passing through the root. This is beginning of new word thread, so reset the existing wordThread 
				//Also reset the firstPrefixword
				if (cur == root)
				{
					currentWord = "";
					firstPrefixword = "";
				}
				//a) check whether EOW is present
				if (cur->eow)
				{	//EOW. 
					//If this the 1st word in the wordThread, then it is the first prefix, so record it as firstPrefixword
					if (firstPrefixword.length() == 0)
						firstPrefixword = currentWord;
					
					//If current word is longer than the anything seen before then record the corresponding PREFIX
					if (currentWord.length() > longestWord.length())
					{
						longestWord = currentWord;
						LCP = firstPrefixword;
					}
				}

				//Go through the child list, if the child object is valid, then corresponding 
				//CHARACTER is considered part of the WORD, so add the CHAR to 'word'
				for (int i = 'a'; i < ('a' + 26); i++)
				{
					if (cur->child[i] != NULL)
					{
						//record the current character.
						string wordTillNow = currentWord + (char)i;

						//We want to know whether 'cur->child[i]' is EOW or has children.
						//To know that make recursion call
						FindLCP(cur->child[i], firstPrefixword, wordTillNow, longestWord, LCP);
					}
				}
			}
			
			return;
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

	class UseLongestCommonPrefixUsingTrie
	{
	public:
		void CallLongestCommonPrefixUsingTrie()
		{
			LongestCommonPrefixUsingTrie objTrieM;
			
			//Add the words to dictionary
			list<string> wrdList;
			wrdList.push_back("new");
			wrdList.push_back("news");
			wrdList.push_back("newspaper");
			wrdList.push_back("newsarticle");
			wrdList.push_back("world");
			wrdList.push_back("worldcup");
			wrdList.push_back("worldculture");
			for (auto itr = wrdList.begin(); itr != wrdList.end(); itr++)
			{
				objTrieM.addWord((char*)(*itr).c_str());
			}


			
			string firstPrefixword; //this will hold first word in every thread-of-letters Ex: "new" and "world"
			string wordThread;  //this will hold the word built as we navigate the thread-of-letters
			string longestThread; //this will longest word 
			string Lcp; //Longest common prefix. (First word in the longest thread in Trie)
			objTrieM.FindLCP(objTrieM.root, firstPrefixword, wordThread, longestThread, Lcp);

			cout << endl << "Longest common prefix " << endl;
			cout << endl << Lcp << endl;

			//output
			// World
			/*
					TRIE
						W o r l d
								  c u p
									  l t u r e
						N e w 
							  s p a p e r
								a r t i c l e 
			
					LCP is World
			
			*/
		}
	};

};