#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <fstream>
using namespace std;

namespace TopWordCountUsingTrieNM //@RED20170531012
{

	/*
	*/
	//LAST Node(eow node) will store the WORD and also list of Files where that word appears
	class TrieNode
	{
		public:
			map<char, TrieNode*> child;
			int eow;
			int wordCount; //Number of times the word appears

			TrieNode()
			{
				eow = 0;
				wordCount = 0;
				for (int i = 'a'; i < ('a' + 26); i++)
				{
					child.insert(pair<char, TrieNode*>(i, 0));
				}
			}
	};

	class TopWordCountUsingTrie
	{
	public:
		TrieNode* root;
		TopWordCountUsingTrie()
		{
			root = new TrieNode();
		}
		
		//insert the WORD and its count in to TRIE
		void addWord(char* word, int wordcnt)
		{
			TrieNode* cur = root;
			int len = strlen(word);
			for (int i = 0; i < len; i++)
			{
				//Ignore the word if it is not an A-Z
				if (((int)word[i] >= 'a') && ((int)word[i] <= 'z'))
				{
					if (cur->child[word[i]] == 0)
					{
						cur->child[word[i]] = new TrieNode();
					}

					cur = (TrieNode*)cur->child[word[i]];
				}
			}

			if (cur != root)
			{	
				cur->eow = 1;
				cur->wordCount = wordcnt; //store word count.
			}
		}

		void iterate()
		{
			TrieNode* cur = root;
			int notFound = 0;
			int len = strlen(word);
			for (int i = 0; i < len; i++)
			{
				//Ignore the word if it is not an A-Z
				if (cur->child[word[i]] == 0)
				{
					notFound = 1;
					break;
				}

				cur = (TrieNode*)cur->child[word[i]];
			}

			if ((notFound == 0) && (cur->eow != 0))
			{
				//Return the WORD count to caller
				*count = cur->wordCount;
			}

			return;
		}
		//find  how many times 'word' appears, and return it in count
		void find(char* word, int* count)
		{
			TrieNode* cur = root;
			int notFound = 0;
			int len = strlen(word);
			for (int i = 0; i < len; i++)
			{
				//Ignore the word if it is not an A-Z
				if (cur->child[word[i]] == 0)
				{
					notFound = 1;
					break;
				}

				cur = (TrieNode*)cur->child[word[i]];
			}

			if ((notFound == 0) && (cur->eow != 0))
			{
				//Return the WORD count to caller
				*count = cur->wordCount;
			}

			return;
		}


	};

	class UseTopWordCountUsingTrie
	{
	public:
		void CallUseTopWordCountUsingTrie()
		{
			TopWordCountUsingTrie objTrieM;

			cout << "insert in to TRIE" << endl;
			objTrieM.addWord("one", 1);
			objTrieM.addWord("two", 2);
			objTrieM.addWord("hundred", 100);

			int cnt = 0;
			int cnt1 = 0;
			objTrieM.find("one", &cnt);
			objTrieM.find("hundred", &cnt1);
			cout << "Count of 'one' "<< cnt << endl;
			cout << "Count of 'hundred' " << cnt1 << endl;
			

		}
	};

};