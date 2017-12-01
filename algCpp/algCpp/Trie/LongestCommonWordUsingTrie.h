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
                                                                                                              
	
	
	Trie over view_20170903001
		Visualize the TRIE as a cloth hanger with 26 ribbons hanging from it. Assume this this TRIE holds all the words that are in a physical dictionary. 1st ribbon has the ALL the words of dictionary that start from letter A, and 2nd ribbon has the ALL the words of dictionary that starts from letter B...This goes on until Z.

		Every node at every level has 26 child nodes and this continues until there are no alphabets, in both x & y directions. This is why TRIE is able to represent whole dictionary. Take the example of words "AA", "AB", "AC"..."AZ".  All these words start with A and that is represeted by the node-A which is child of ROOT. That node-A will have 26 child nodes to take care of 2nd lete of "AA", "AB", "AC"..."AZ". As you see words all these words share common node for "A". This is why TRIE is efficient.  When we store a new word in TRIE, it does not get built from scarch instead existing word will be extended to accomadate the new word. Ex: ROCKET can be created by adding ET to ROCK.


	Trie Node structure_20170903002
		Typically Node object will have 3 data members. EOW flag, Metadata object and MAP object.
		-A thread of nodes strecthing from Root to Leaf will have several words on same thread(like Rocket and Rock). EOW flag will be set only if the node happens to be the last letter of a word. Ex: In case of Rocket and Rock; K and T will have EOW flag. When iterating, do not stop just because EOW was found.
		-Metadata object will have metadata. Not all nodes will have Metadata; only the node where EOW is set will have the Metedata. For example: TRIE for Telephone Dictionary will have  phone number as metadata. Meta data will hold the phone number only on the node where person name ends.

		-MAP object holds the node object for next letter of the word. MAP will have 26 entries, where KEY is alphabet and value is NODE for that alphabet. KEY will always have a something but VAUE will be valid-object only if there is a NEXT letter. If the child is null, then do not go forward. When doing a DFS iteraton on TRIE, end the iteration if a node a NO Last node in the THREAD will have no child object at all.

		Notice that Node does not tell about the alphabet that it is representing(node has EOW flag and child nodes, but no info about the letter that node is representing). To know the alphabet for that node, go to parent node and read the KEY in its MAP. This is why root node does not stand for ANY letter because it has no parent, so no MAP and thus no alphabet.

	Inserting Word in to Trie 20170903003
		Insert Ex: ART in to TRIE
		Note that TRIE will not create the word from scratch; instead it extends the existing word.
		When it comes to adding the word ART; first 'letter A' should be made child of Root-node; then 'letter R' should be made child of 'letter A'; similarly add 'letter T' also.

		If the Root node already has a child object for letter-A, reuse it. If there is no existing child-object, create a brand new node object and store it in MAP of root node. When storing in map, use letter-A has KEY. Now the 'letter A' has been put inside TRIE, it does not matter whether we created a brand new node or it already existed in map.

		Take the node for letter-A, and check if it has child for letter-R, if it is present, reuse it; otherwise create a brand new node object and store it in the MAP of 'letter-A'.

		Similarly take care of letter T also; since T is the last letter in the word ART, set EOW flag. There is NO letter after T, so T will not have any child node, so the MAP will only have NULL values.

		Details:
			There will be two cursors: srcCursor and TrieCursor.
			-TrieCursor will be pointing to ROOT node.

			-Read the letter from src, and use it as KEY for MAP of  TrieCursor. If the MAP has non-NULL value, then read it and assign it to TrieCursor. Otherwise creaye a brand new Node object, and store it in MAP. Then assign the newly created value to TrieCursor
			{
				for (letter in src)
				{
					If(TrieCursor.MAP[letter] == NULL)
						TrieCursor.MAP[letter] = New Node();
					else
						//do not create NODE, because it exists MAP.
				}
				TrieCursor = TrieCursor.MAP[letter]; //advance the TrieCursor

				//Out of ForLoop TrieCursor will be pointing to 'last letter' of word, and set EOW to TRUE on this node
				TrieCursor.EOW = true;
			}
			-In the next loop, next another letter from src will be added to TRIE.
			-AFter exhasting the src-arry, come out of loop. TrieCursor will be pointing to the last letter of the word, and set EOW to TRUE on this node

	Finding Word in Trie 20170903004
		Logic for searching a word in TRIE is same as inserting a WORD. Insert first tries to find the alphhabet and if it is not present, then it creates a node object and inserts it in to TRIE. Where as Search will exits with FAILURE if the alphabet is missing. So Insert code is supeset of Search code. There is one more difference between the two; Search returns TRUE, ONLY if every alphabet is present and also EOW has been set on last alphabet of WORD.

		Coming to implementation:
		There will be two cursors: srcCursor and TrieCursor.
		-TrieCursor will be pointing to ROOT node.

		-Read an alphabet from src, and look for it inside MAP; if the MAP has non-null child node, then alphabet is present in TRIE, advance the cusror and continue to next round. Next round will look for new alphabet. Do this untill we process every letter of src-array.  Advancing the cusror involves assigning (newly found)child-node to TriCursor

		If the MAP has null value, then alphabet is missing, that means word is not present in Trie, so break the forLoop and return FALSE.

		If every alphabet is present, then Forloop will exit after processing every character. Once out of ForLoop, TrieCursor will be pointing to last alphabet of WORD. Go in to that node and check if EOW flag set. If the EOW flag is present then we can conclude that WORD exits in TRIE.

			for (letter in src)
			{
				If(TrieCursor.MAP[letter] == NULL)
					TrieCursor = TrieCursor.MAP[letter]; //advance the TrieCursor
				else
					notFound = true;
					break;
			}
			if(notFound == false)
				if(TieCursor.EOW == TRUE)
					//word is present in TRIE



	Iterating TRIE_20170903005
		TRIE can be iterated using DFS based on recursion. TRIE node keeps its children in MAP. Start the iteration from Root. Once inside a node, iterate the MAP using ForLoop, if the MAP has Non-Null child node, then we need to go in to that child node as per the rules of DFS. So make a recursion call by passing the child node as parameter.
		Once the recursion returns, make a similar recursion call to next entry in MAP. If the node is LEAF, then none of entry in MAP will have valid child node, that is when DFS makes a U-turn.

		During iteration we may want to record the word. We know the node's parent knows about the alphabet represented by Node; and Node will know about EOW and chlldren. So record the alphabet when iterating the MAP, and then place the rfecursion call if VALUE is non-null. Once inside the recursion for child noe, check EOW is set, if so record that as WORD. After that start a forLoop to iterate MAP. If the MAP all null objects, then this is a LEAF node. As soon we enter the recursion check whether the node is valid, then only iterate the MAP.

	

	Computing LCW_20170805004           
		LCW means longest among the among compound words. Word has to be compound word and also Longest word.
		We should ignore the words that are long but not compound word. Ex: Elephant. When compared to CatRat, Elephant is longer but it is not a 
		compound word, so ignore it

		This is how we check for LCW
		-Go through the word list given by User, and load them in to TRIE.
		-Next step is to filter out the words that are not Compound words.
		 Do this as follows. Iterate the Wordlist once more, and try to locate the word inside TRIE.
		 The word should have more than one EOW, then it is a Compound word and keep it, else reject it.
		 
		 
		-Next st is make sure every subword is a simple word. EXtract the subwords one by one and make sure they are directly under the root.
		-There should not be any subword that is not a simple word.  
		 If the word meets all these pre-requisites, then record its length.
		 Several words may pass this qualification round, record all their length.
		 Finally select the word who's length is max.

		This is how we can verify subwords are simple words.
		Think of every compound word to be having "firstword" and "rest of the word".
		Ex: "CatRatDog". Here Cat is first word and 'RatDog' is rest-word.

		In a loop, starting from left, extract "firstword" and "rest of the word".
		Then check if the "firstword" is simple word. If it is not a simple word, then reject the whole word.
		If it is a simple word, then explore "rest of the word". Explore in the sense,
		split the "rest of the word", as "firstword" and "rest of the word".
		Continue to do this until the length of the "rest of the word" becomes 0.
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