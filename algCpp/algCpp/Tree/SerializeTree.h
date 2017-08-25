#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include<algorithm>
#include<queue>
#include <string>
#include "BuildTree.h"
using namespace std;
using namespace BuildTreeNM;


/*
		Serialize a Tree_RED20170825003
			Traverse the tree using in-order traversal and store it in a List.
			Refer to @RED20170825005

			Then traverse the List and rebuild the Tree.
			Refer to RED20170825001
*/
namespace SerializeTreeNM //@RED20170825003
{
	class SerializeTree
	{
	public:
		void callSerializeTree()
		{
			BuildTree objTrrr;
			objTrrr.AddValues();

			cout << "\r\n";
			cout << "Tree content\r\n";
			objTrrr.printTreeInOrder(objTrrr.root);
			cout << "\r\n";

			
		}

	private:
		

		
	};
};



