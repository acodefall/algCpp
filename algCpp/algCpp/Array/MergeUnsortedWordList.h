#pragma once
//MergeUnsortedWordList

#pragma once
#include <iostream>
#include <map>
#include <list>
#include <memory>
#include <unordered_map>
#include <unordered_set>
using namespace std;

namespace MergeUnsortedWordListNM //@RED20170730002
{
	/*
		Merge unsorted word list
			Merge two unsorted array and remove the duplicate from the resultant array. example
			Array1 = {“are”,”you”,”there”}
			Array2={“how”,”are”,”you”}
			output={“how”,”are”,”you”,”there”}

		I do not think merged array should maintain order. All it wants is remove the duplicates.
	    This can be solved using unordered_set and also using TRIE, as they both do deduplication by default.
		unordered_set
			unordered_set will maintain only copy even if we insert same word twice.
			So unordered_set is good at eliminating duplicates.
			Iterate both the word-list and insert the words in to unordered_set.
			Then iterate the unordered_set and print the content. Ouput will not have any duplicates.

			complexity: Inserting the wordlist in unordered_set takes O(N) and O(N).
			Since this can be done in parallel, we can say that loading the data in to unordered_set takes O(N).
			Then reading the unordered_set takes O(N) time so totally O(N+M)

			
		Trie
			Trie also eliminates duplicates. Insert the words in Trie and then iterate the  whole tre and print it.
			This is not that different from unordered_set. In fact unordered_set may have low space-complexity.




	

	*/
	class MergeUnsortedWordList
	{
	public:
		void callMergeUnsortedWordList()
		{
			list<string> lst1;
			list<string> lst2;
			lst1.push_back("how");
			lst1.push_back("are");
			lst1.push_back("you");

			lst2.push_back("OK");
			lst2.push_back("are");
			lst2.push_back("you");
			lst2.push_back("there");



			Merge1(lst1, lst2);
		}

		void Merge1(list<string> lst1, list<string> lst2)
		{
			unordered_set<string> merged;
			for (auto it1 = lst1.begin(); it1 != lst1.end(); it1++)
				merged.insert({ *it1 });
			
			for (auto it1 = lst2.begin(); it1 != lst2.end(); it1++)
				merged.insert({ *it1 });

			cout << "merged list " << endl;
			for (auto itmerged = merged.begin(); itmerged != merged.end(); itmerged++)
			{
				cout << (*itmerged).c_str() << " ";
			}
			cout << endl;
		}
	};
};
