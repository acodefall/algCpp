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

namespace LongestCommonWordUsingTrieNM //@RED20170805004
{

	/*								
															
							
  (Word List)
    Cat         //simple word
    Dog              "  
    Rat              "
    Elephant    //SimpleWord and is also quite long, but we ignore this beacause it is not a compound word.
    CatDogX     //CompoundWord but has foriegn word X, so compWord shoul be ignored        
    CatDogRat   //CompoundWord is Perfect becs every subword is simple word
    
  (Word List loaded to TRIE)
                ROOT
        C           D    E    R          Verify given Word is Simple word
        a           o    l    a            Simlle Word sits directly under root of TRIE. 
        t           g    e    t            So apply the FIND logic starting from Root node
        D                p                 Ex: 'Dog', 'Rat' are simple words because they sit under Root. Find will locate it 
        o                h                     'DogRat' is not simple word because it is not direct under Root. Find fails 
        g                a                      But if you split it in to simple words 'Dog' and 'Rat', we will find them.
        R    X           n
        a                t
        t

        
  (Splicing Compound Word  'CatDogRat' to find LCW)

                ROOT                                (Logic)                MAP (CompndWord     SubWOrdtoBeSpliced)
        C           D    E    R                     CatDogRat                   CatDogRat            CatDogRat
        a           o    l    a                      /\                             .                    .  
        t           g    e    t                     /  \                            .                    .    
        D                p                        Cat   DogRat                      .                 DogRat
        o                h                                / \                       .                    .
        g                a                               /   \                      .                    .
        R    X           n                             Dog   Rat                    .                   Rat 
        a                t                                   /\                     .                    .      
        t                                                   /  \                    .                    .
                                                          Rat   ""              CatDogRat                ""
                                                                                  
                                                                                CatDogRatX           CatDogRatX 
                                                                                    .                 DogRatX 
                                                                                    .                  RatX
                                                                                    .                  X
                                                                                                              
	
	
	Trie over view_20170803001
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

		Note: Do not stop the iteration just because a node has EOW flag set. A thread of Nodes/ribbon can have many EOWs so go until the nodes who’s child nodes are all NULL.




		

		Computing LCW_20170805004           
			Broadly speaking filter out the simple words and keep only the compound words.  Further splice the compound word in to 1stWord and ‘Rest of the word’. We know 1stword, which is also the left-most word has only word, and check whether that itself is a Simple word(by trying to Search for it under ROOT). If the 1st word is a simple word, this compound word is still in the game, so splice ‘Rest of the word’. This will produce one more set of 1stWord and ‘Rest of the word’, and make sure 1stWord is a Simple word(by trying to Search for it under ROOT); if so compound word is still the game. In the next round splice the ‘Rest of the word’ again. Do this until there is nothing to be spliced. After every split resulting 1st word must pass the test for Simple word(means Search for it under ROOT). Then the original word is a good compound word and save it in a separate list. 

			Apply the Splice logic on every compound word that user has entered. The compound words that pass the splice test should be added to a separate list. 

			In the end we will have a list of qualified compound words. These words are totally made up of Simple worlds; they do not contain foreign letter. Select longest compound word for that. 

			Splicing logic uses MAP of  “CompoundWordThatUserEntered” V/s ‘CompoundWordToBeSpliced’. In the first round KEY and VALUE will be same; and as we splice the Compound Word, we change the VALUE. In the end VALUE will recude to “” string. That is when we stop the splicing operation. 


			Example for Splicing of compound word ‘CatDogRat’:
				In the 1st loop, extract left-most subword(Cat), and that leaves second part(DogRat).
				If the extracted 1st word is a simple word, go to 2nd loop. 

				In the 2nd loop extract left-most subword(Dog) from 'DogRat'. If 'Dog' is the extracted 1st word and rest is 'Rat'. If 1t word is a simple word, go to 3rd loop.

				In the 3rd loop extract left-most subword(Rat) from 'Rat'. If the 1t word RAT is a simple word, go to 4th round.
			In 4th round we have nothing to splice. By now every subword ‘Cat’ ‘Rat’ Dog has proven to be Simple word, so we can say that the CompoundWord 'CarDogRat' is indeed Valid compound word
 



			
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
			{		
				if (cur != NULL)
				{
					//First character is actually in 2nd node of the thread of nodes.
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
			}
			return;
		}
		//Find LCW
		//Find the inter mediatory words and check whether they are in 
		//'betweenWord' is the word between two EOWs. "catRatDog" betweenWord could be 'Rat', Dog'
		void TraverseAndFindLCW(TrieNode* root, list<string>& fullyCompoundWord, unordered_map<string,string>& nonCompndWordList, string& longestLCW)
		{
			while (nonCompndWordList.size() > 0)
			{
				//process one item at time
				auto itr = nonCompndWordList.begin();
					string prefix = "";
					string cmpmdWord = (*itr).second;
					string OriginalWord = (*itr).first;
					extractFirstWord(root, cmpmdWord, prefix);
					if (prefix.length() == 0)
					{
						//word does not have ROOT word. disqualifying the word 
						//Do not add to fullyCompoundWord
						nonCompndWordList.erase(OriginalWord);
					}
					else if (prefix.length() == cmpmdWord.length())
					{
						//full length if cmpmdWord word is a root-Word, so we do not have to anything to this word, so remove from MAP.
						//Word qualifying as totaly compound word so add to fullyCompoundWord.
						nonCompndWordList.erase(OriginalWord);

						fullyCompoundWord.push_back(OriginalWord);
						/*//full length if cmpmdWord word is a root-Word, no more to inspect.
						if (longestLCW.length() < OriginalWord.length())
						{
							cout << "End of thread. Word is LCW '" << wholeWord.c_str() << "'" << endl;
							longestLCW = OriginalWord;
						}*/
					}
					else if (prefix.length() < cmpmdWord.length())
					{

						//1st Part of cmpmdWord word is a root-Word, but we do not know about the rest of the word. 
						//We have to disect the 2nd part in to piecse, so the the WORD be in MAP.
						//But update the MAP with the 2nd part of the word that we want to inspect.

						//We want to update the MAP VALUE, but iterator does not all UPDATE of VALUE, so REMOVE() and INSERT()
						//Remove and insert the ENTRY
						nonCompndWordList.erase(OriginalWord);

						//update VALUE. This VAUE will be disected later in the loop
						nonCompndWordList.insert({ OriginalWord, cmpmdWord.substr(prefix.length()) });
					}
				}

			
		}

		

	};

	class UseLongestCommonWordUsingTrie
	{
	public:
		void CallLongestCommonWordUsingTrie()
		{
			unordered_map<string,string> CompndWordList;
			list<string> totallyCompoundWord; //Every subword is some 'root-word'. so whole compound word becomes totally compoundWod. 
			LongestCommonWordUsingTrie objTrieM;
			list<string> rawWordList;
			rawWordList.push_back("cat");
			rawWordList.push_back("cats");
			rawWordList.push_back("catsdogcats");
			rawWordList.push_back("catxdogcatsrat");  //CompoundWord but will get eleiminated becaues it has foriegn letter X
			rawWordList.push_back("dog");
			rawWordList.push_back("dogcatsdog");
			rawWordList.push_back("hippopotamuses");  //Simple word but longest. this will be ignored because this is not a CompoundWord
			rawWordList.push_back("rat");
			rawWordList.push_back("ratcatdogcat");
		


			cout << "Load the words in to TRIE" << endl;
			for (auto itr = rawWordList.begin(); itr != rawWordList.end(); itr++)
			{
				objTrieM.addWord((char*)(*itr).c_str());
			}
			

			//Original words provided by user will have both compound words and non-compound words, we have to seperate them.
			//We are intersted in compoundWords only. We do not care about non-compound words
			//We want to check whether the every subword of compound word is Root word.
			
			//DogCat This compound word because 'g' has EOW (frstWord Len < wholeWordLen)
			//Rat    This is not compound word because 't' has EOW and that happens be the end of whole word. (frstWord Len == wholeWordLen)
			string firstWord;
			for (auto itr = rawWordList.begin(); itr != rawWordList.end(); itr++)
			{
				objTrieM.extractFirstWord(objTrieM.root, (*itr) ,firstWord);
				if ((*itr).length() > firstWord.length())
				{
					//it is a compund word
					CompndWordList.insert({ (*itr),(*itr) });
				}
			}

			
			//Go through the list of compound words and record the longest word
			//find the LCW
			string wholeWord;
			string wordBtwnEOW;
			string longestLCW;
			
			objTrieM.TraverseAndFindLCW(objTrieM.root, totallyCompoundWord, CompndWordList, longestLCW);
			cout << "LCW is '"<< longestLCW.c_str() <<"'" << endl;
		
		}
	};

};