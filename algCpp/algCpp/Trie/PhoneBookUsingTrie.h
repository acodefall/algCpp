#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iomanip>
using namespace std;

namespace PhoneBookUsingTrieNM //@RED20170803004
{

	/*
		
		Implement TelePhone directory using TRIE_20170803004
			Load the UserName and thier Telephone number in to TRIE. Store the  Telephone number on the node that has EOW( the node that has last letter of user name)
			Then iterate the TRIE to gather both UserName and Telephone number, and print them
			
	*/
	
	//Node with EOW flag will have the last lettter of the user-name
	//This Node(eow node) will store the phone number for the user
	class TrieNode
	{
		public:
			map<char, TrieNode*> child;  //char will store each letter of user name
			int eow;
			
			string PhoneNumber; //phone number of user

			TrieNode()
			{
				eow = 0;
				
				for (int i = 'a'; i < ('a' + 26); i++)
				{
					child.insert(pair<char, TrieNode*>(i, 0));
				}
			}
	};

	class PhoneBookUsingTrie
	{
	public:
		TrieNode* root;
		PhoneBookUsingTrie()
		{
			root = new TrieNode();
		}
		
		//insert the UserName and his Telephone number in to TRIE
		void addUserAndPhoneNumber(char* userName, string telephone)
		{
			TrieNode* cur = root;
			int len = strlen(userName);
			for (int i = 0; i < len; i++)
			{
				//Iterate the USer name letter by letter and insert in to TRIE
				//Ignore the UserName if it is not an A-Z
				if (((int)userName[i] >= 'a') && ((int)userName[i] <= 'z'))
				{
					if (cur->child[userName[i]] == 0)
					{
						cur->child[userName[i]] = new TrieNode();
					}

					cur = (TrieNode*)cur->child[userName[i]];
				}
			}

			//When we hit the last letter of userName, store his tele phone number 
			if (cur != root)
			{	
				cur->eow = 1;
				cur->PhoneNumber = telephone; //store word count.
			}
		}

		void TraversePrintUserAndPhoneNumber(TrieNode* cur, string Name)
		{
			if (cur != NULL)
			{
				//This conditon won't apply for root node
				if (cur->eow)
				{	//This marks the end of the UserName, print the userName and also his phone number
					
					cout << Name.c_str() << "  " << cur->PhoneNumber.c_str() << endl;
				}
				
				//Go through the child list, if the child object is valid, then corresponding 
				//CHARACTER is considered part of the WORD, so add the CHAR to 'word'
				for (int i = 'a'; i < ('a' + 26); i++)
				{
					if (cur->child[i] != NULL)
					{
						//record the current character.
						string wordTillNow = Name + (char)i;
						
						//We want to know whether 'cur->child[i]' is EOW or has children.
						//To know that make recursion call
						TraversePrintUserAndPhoneNumber(cur->child[i], wordTillNow);
					}
				}
			}
			return;
		}
		//find  Telephone number of the UserName
		void getUserPhoneNumber(char* UserName, string& phoneNumber)
		{
			TrieNode* cur = root;
			int notFound = 0;
			int len = strlen(UserName);
			for (int i = 0; i < len; i++)
			{
				//Iterate the USer name letter by letter and accordingly select the ENTRY in MAP 
				if (cur->child[UserName[i]] == 0)
				{
					notFound = 1;
					break;
				}

				cur = (TrieNode*)cur->child[UserName[i]];
			}

			//We have found the userName because we got the EOW, now read the telephone number for that userName
			if ((notFound == 0) && (cur->eow != 0))
			{
				//Return the phone number of userName
				phoneNumber = cur->PhoneNumber;
			}

			return;
		}


	};

	class UsePhoneBookUsingTrie
	{
	public:
		void CallPhoneBookUsingTrie()
		{
			PhoneBookUsingTrie objTrieM;

			cout << "insert in to TRIE" << endl;
			
			//insert UserName and some imaginary TelePhone number
			objTrieM.addUserAndPhoneNumber("one", "111111");
			objTrieM.addUserAndPhoneNumber("two", "222222");
			objTrieM.addUserAndPhoneNumber("hundred", "1001000");
			objTrieM.addUserAndPhoneNumber("cot", "141616716781");
			objTrieM.addUserAndPhoneNumber("cotton", "99999999999");

			string phn1;
			string phn2;
			//Go back to TRIE, and re-read the UserName and Telephne number that we inserted above.
			objTrieM.getUserPhoneNumber("one", phn1);
			objTrieM.getUserPhoneNumber("hundred", phn2);
			cout << "Phone number of 'one' "<< phn1 << endl;
			cout << "Phone number of 'hundred' " << phn2 << endl;
			
			
			string userName;
			//Iterate the TRIE and print username and telephone number
			objTrieM.TraversePrintUserAndPhoneNumber(objTrieM.root, userName);
		
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