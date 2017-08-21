#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iomanip>
using namespace std;

namespace TopWordCountUsingTrieNM //@RED20170803002
{

	/*
		
		List the words based on their occurence count_20170803002
			Load the words and thier occurence count in to TRIE. Store the count on the node that has EOW ( the node that has last letter of the WORD)
			Then iterate the TRIE to gather both WORD and its count. 
			Load that info in to a MULTIMAP(Key is Count, Value is Word).
			By default MultiMap will sort based on KEY, then go through the multiMAP and print it.

		
		Trie  over view_20170803001
			Visualize the TRIE as a cloth hanger that has 26 ribbons hanging from it. 1st ribbon has the words starting from letter A, and 2nd ribbon has the word starting from letter B...This goes on until Z. There is one ribbon for every letter.

			What is special about TRIE is that it can record a new word by adding few letters to an already existing word, if the new word is SUFFIX of a word that is already in TRIE.
			For example: The ribbon for letter R, can have both ROCK and ROCKET. Rocket gets created by adding two letters to the already existing word ROCK. This is why Trie is space efficient.  Since several words sit on same thread on nodes, Trie will FLAG 'end of word' flag by setting a flag. 
			Ex: In case of Rocket and Rock, both K and T will have 'end of word' flag.  So the program iterating the nodes 
			Should look for EOW and if present, it should record that as word. 

			Every node has 26 child nodes. So if you go back to Ribbon analogy, at every level, the number of ribbons increases by a mupliple of 26. First/root level will have 26 ribbons, and each child node will have 26 children, so the second 
			level will have 26 * 26 ribbons. This layout helps TRIE to represent whole dictionary by using less space.
			
			Coming to the members of NODE.
			Node will have a MAP with 26 entries, who's KEY is the alphabet and VALUE is child node.  Node does not store the character (that it is representing) in any data member at all. 	For that we have to see the KEY inside parent node's map. 
			Node tells two things: It tells whether the letter marks EOW; and it also gives child nodes; but it does not tell about the character repreasnted by node iteelf. Iteratig logic SHOULD be aware of this.

			Ex: Assume TRIE has word RAT. 
			Iteration starts from ROOT node; and Root node does not represent any letter at all, but it's MAP has a non-NULL VALUE for letter 'R'; that is how we come to know that the child represents letter R. Then we step in to that child node, and it does not have  any class member that says that we are in R-node. Map of R-node will have non-NULL VALUE for letter A. We step in to A-Node. Map of A-node will have non-NULL VALUE for letter T. Then we enter T node, and that will have EOW flag. Then we record RAT as a word. 

			Note: When iterating TRIE, do stop just because a node has EOW flag set, because a ribbon of nodes will host several words. Go until node whose MAP has all but NULL values. Go through all the 26 child nodes, even if the current node has EOW flag. Example: Rock and Rocket.  Node for K will have EOW flag but thread does not end there; there will be two more letters E and T.




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
		//if the 
		void addWord(char* word, int wordcnt)
		{
			TrieNode* cur = root;
			int len = strlen(word);
			for (int i = 0; i < len; i++)
			{
				//Iterate the WORD letter by letter and insert in to TRIE
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

			//When we hit the last letter of WORD store its occurence count
			if (cur != root)
			{	
				cur->eow = 1;
				cur->wordCount = wordcnt; //store word count.
			}
		}

		//iterate the TRIE from ROOT to every leaf, and gather each word and store it in MAP as KEY. 
		//Number of occurence of that word is stored as metadata in the node of last letter.
		//Store the count as VALUE in MAP
		void Traverse(TrieNode* cur, string word, multimap<int, string>& wordOccurence)
		{
			if (cur != NULL)
			{
				//This conditon won't apply for root node
				if (cur->eow)
				{	//This marks the end of the word, store it in MULTIMAP. Also fecth the occurence count from Trie Node
					wordOccurence.insert({ cur->wordCount, word });

					//NOTE: we do not check whether the WORD already exists because TRIE will not keep
					//same WORD at more than one place.
				}
				
				//Go through the child list, if the child object is valid, then corresponding 
				//CHARACTER is considered part of the WORD, so add the CHAR to 'word'
				for (int i = 'a'; i < ('a' + 26); i++)
				{
					if (cur->child[i] != NULL)
					{
						//record the current character.
						string wordTillNow = word + (char)i;
						
						//We want to know whether 'cur->child[i]' is EOW or has children.
						//To know that make recursion call
						Traverse(cur->child[i], wordTillNow, wordOccurence);
					}
				}
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
				//Iterate the WORD letter by letter and accordingly select the ENTRY in MAP 
				if (cur->child[word[i]] == 0)
				{
					notFound = 1;
					break;
				}

				cur = (TrieNode*)cur->child[word[i]];
			}

			//We have found the userName because we got the EOW, now read the telephone number for that userName
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
			
			//insert few words and some imaginary occurence count.
			//Both info will be stored in TRIE.
			objTrieM.addWord("one", 1);
			objTrieM.addWord("two", 2);
			objTrieM.addWord("hundred", 100);
			objTrieM.addWord("cot", 14);
			objTrieM.addWord("cotton", 9);

			int cnt = 0;
			int cnt1 = 0;
			//Go back to TRIE, and re-read the words that we inserted above.
			//occurence count has to be same.
			objTrieM.find("one", &cnt);
			objTrieM.find("hundred", &cnt1);
			cout << "Count of 'one' "<< cnt << endl;
			cout << "Count of 'hundred' " << cnt1 << endl;
			
			//To know which the HIGHEST repeating WORD, we have to iterate  the whole TRIE,
			//and build a multimap(COUNT, WORD).
			//That multi-map will give the word based on their repeatition count
			
			string word;
		
			//Use multimap because there could be two words with same count
			multimap<int,string> OccurenceAndWordList; //KEY - count VALUE - word.
			objTrieM.Traverse(objTrieM.root, word, OccurenceAndWordList);
		
			cout << "words bsed on count in 'wordOccurence' map " << endl;
			for (auto itr = OccurenceAndWordList.begin(); itr != OccurenceAndWordList.end(); itr++)
			{
				cout << setw(5) <<   (*itr).first << "    " << (*itr).second.c_str() << endl;
				
			}
			/*
				Count of 'one' 1
			Count of 'hundred' 100
		
			words bsed on count in 'wordOccurence' map. SORTED based on COUNT
						1    one
						2    two
						9    cotton
					   14    cot
					  100    hundred
			*/
		}
	};

};