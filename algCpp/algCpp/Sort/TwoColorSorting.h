#pragma once
#include "PartitionArray.h"
namespace TwoColorSortingNM
{
	/*
		TwoColorSorting_20170528003
			This is same as 3colorSorting. Src-array will have just 0 and 1.
			We use Selection-Method of QuickSort() for bringing all the 0s to left side.
			We call Selection-method only once with 0 as anchor element.
	*/
	class TwoColorSorting
	{
	public:
		void callTwoColorSorting()
		{
			int data[16] = { 0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,1 };
			int len = 16;

			cout << "\r\n Before Two color sorting\r\n ";
			for (int i = 0; i < 16; i++)
			{
				cout << data[i] << " ";
			}
			int anchor = 1;
			PartitionArrayNM::PartitionArray objPartitionArray;
			int ret = objPartitionArray.PartitionInTo2Parts(data, 0, len - 1, anchor);



			cout << "\r\n After Two color sorting \r\n";
			for (int i = 0; i < 16; i++)
			{
				cout << data[i] << " ";
			}
		
		}

		
		
	};
};