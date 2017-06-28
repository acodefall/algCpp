// algCpp.cpp : Defines the entry point for the console application.
//

/*
	#pragma region DebugX  
	#pragma endregion DebugX 
	CTRL + M + O will collapse all.

	CTRL + M + L will expand all. (in VS 2013 - Toggle All outlining)

	CTRL + M + P will expand all and disable outlining.

	CTRL + M + M will collapse / expand the current section.
*/
#include "stdafx.h"
#include "print123withPlus.h"
#include "BinarySearchForLoop.h"
#include "RemoveComma.h"
#include "ReverseLL.h"
#include "Graphbuild.h"
#include "GraphSearch.h"
#include "EditablePriorityQueue.h"

#include "MatrixRotatePrint.h"
#include "MovieRatingGraph.h"
#include "Combinations.h"
#include "Permutation.h"
#include "MemoryMngrBuddy.h"
#include "CombinationWithoutDupesBitGen.h"
#include "PowerSet.h"
#include "InvertedIndex.h"
#include "Library.h"
#include "Stack1.h"
#include "Median.h"
#include "SyncQx.h"
#include "ProdConsumer.h"
#include "AreStringRotated.h"
#include "BinarySearchForLoop.h"
#include "LCSString.h"
#include "ArrayHasConsqNumbers.h"
#include "SwapAlternativeKthNode.h"
#include "PrintTopAndBottomFacingNodes.h"
#include "SingleTonOne.h"
#include "ReverseDoublyLinkedList.h"
#include "RotateArray.h"
#include "RotateArrayUsingReverse.h"
#include "BoyerMooreVoting.h"
#include "FindTopTenPercent.h"
#include "TwoColorSorting.h"
#include "AddAlternateNumbersDP.h"
#include "PalidroneUsingRecursion.h"
#include "TwoColorSortEvenOdd.h"
#include "ThreeColorSorting.h"
#include "LongestCommonPalidrone.h"
#include "ColorHomeWithMinimumCostUsingDP.h"
#include "ColoringHomeUsingCombination.h"
#include "BSTToDoublyLinkedLL.h"
#include "RecursiveAdditionExceptCurrentItem.h"
#include "KnapsackUsingDP.h"
#include "CuttingRodUsingDP.h"
#include "3SUMProblem.h"
#include "WaysOfMakingN.h"
#include "PlaceLettersApart.h"
#include "FindSmallestWindowOfSubstring.h"
#include "PatternMatchUsingOccurCount.h"
#include "IndexOfItemLargerThanK.h"
#include "BinarySearchSizeUnknown.h"
#include "KthItemUnsortedArray.h"
#include "KthLargestItemUsingMergeSort.h"
#include "HeapBase.h"
#include "MedianUnsortedUsingKthOrder.h"
#include "MedianOfBST.h"
#include "MedianOfTwoSortedArrays.h"
#include "RealTimeMedian.h"
#include "InsertionSort.h"
#include "CountingSort.h"
#include "MergeSorting.h"
#include "PartitionArray.h"
#include "QuickSort.h"
#include "MergeSortAndStoreInSameArray.h"
int main()
{
	LibraryNM::Library objLibrary;


	cout << "main begins \r\n";

	MergeSortAndStoreInSameArrayNM::MergeSortAndStoreInSameArray objMergeSortAndStoreInSameArray;
	objMergeSortAndStoreInSameArray.CallMergeSortAndStoreInSameArray();

	MedianUnsortedUsingKthOrderNM::MedianUnsortedUsingKthOrder objMedianUnsortedUsingKthOrder;
	objMedianUnsortedUsingKthOrder.callKthItemUnsortedArray();

	KthItemUnsortedArrayNM::KthItemUnsortedArray objKthItemUnsortedArray;
	objKthItemUnsortedArray.callKthItemUnsortedArray();


	PartitionArrayNM::PartitionArray objPartitionArray;
	objPartitionArray.CallPartitionArray();


	ThreewaysortingNM::ThreewaySorting objThreewaysorting;
	objThreewaysorting.CallThreewaySorting();

	TwoColorSortEvenOddNM::TwoColorSortEvenOdd objTwoColorSortEvenOddNM;
	objTwoColorSortEvenOddNM.callTwoColorSortEvenOdd();

	QuickSortNM::QuickSort objQuickSort;
	objQuickSort.CallQuickSort();


	CountingSortNM::CountingSort objCountingSort;
	objCountingSort.CallCountingSort();
	
	MergeSortingNM::MergeSort objMergeSort;
	objMergeSort.CallMergeSort();

	InsertionSortNM::InsertionSort objInsertionSort;
	objInsertionSort.CallInsertionSort();

	RealTimeMedianNM::CallRealTimeMedian objCallRealTimeMedian;
	objCallRealTimeMedian.CallCallRealTimeMedianX();

	MedianOfTwoSortedArraysNM::MedianOfTwoSortedArrays objMedianOfTwoSortedArrays;
	objMedianOfTwoSortedArrays.CallMedianOfTwoSortedArrays();

	MedianOfBSTNM::MedianOfBST objMedianOfBST;
	objMedianOfBST.CallMedianOfBST();



	HeapBaseNM::UseHeap objUseHeap;
	objUseHeap.CallUseHeap();

	KthLargestItemUsingMergeSortNM::KthLargestItemUsingMergeSort objKthLargestItemUsingMergeSort;
	objKthLargestItemUsingMergeSort.CallKthLargestItemUsingMergeSort();

	
	BinarySearchSizeUnknownNM::BinarySearchSizeUnknown objBinarySearchSizeUnknown;
	objBinarySearchSizeUnknown.callBinarySearchSizeUnknown();

	IndexOfItemLargerThanKNM::IndexOfItemLargerThanK objIndexOfItemLargerThanK;
	objIndexOfItemLargerThanK.CallIndexOfItemLargerThanK();

	PatternMatchUsingOccurCountNM::PatternMatchUsingOccurCount objPatternMatchUsingOccurCount;
	objPatternMatchUsingOccurCount.callPatternMatchUsingOccurCount();

	FindSmallestWindowOfSubstringNM::FindSmallestWindowOfSubstring objFindSmallestWindowOfSubstring;
	objFindSmallestWindowOfSubstring.CallFindSmallestWindowOfSubstring();

	PlaceLettersApartNM::PlaceLettersApart objPlaceLettersApart;
	objPlaceLettersApart.CallPlaceLettersApart();

	WaysOfMakingNNM::WaysOfMakingN objWaysOfMakingN;
	objWaysOfMakingN.callWaysOfMakingN();

	ThreeSumProblemNM::ThreeSumProblem objThreeSumProblem;
	objThreeSumProblem.Call3SumProblem();
	
	KnapsackUsingDPNM::KnapsackUsingDP objKnapsackUsingDP;
	objKnapsackUsingDP.CallKnapsackUsingDP();
	
	CuttingRodNM::CuttingRod objCuttingRod;
	objCuttingRod.CallCuttingRod();


	AddAlternateNumbersDPNM::AddAlternateNumbersDP objAddAlternateNumbersDP;
	objAddAlternateNumbersDP.callAddAlternateNumbersDP();


	RecursiveAdditionExceptCurrentItemNM::RecursiveAdditionExceptCurrentItem objRecursiveAdditionExceptCurrentItem;
	objRecursiveAdditionExceptCurrentItem.callRecursiveAdditionExceptCurrentItem();

	RotateArrayNM::RotateArrayX objRotateArray;
	objRotateArray.callRotateArray();

	RotateArrayUsingReverseNM::RotateArrayUsingReverseX objRotateArrayUsingReverseX;
	objRotateArrayUsingReverseX.callRotateArrayUsingReverse();

	BSTToDoublyLinkedLLNM::BSTToDoublyLinkedLL objBSTToDoublyLinkedLL;
	objBSTToDoublyLinkedLL.callBSTToDoublyLinkedLL();

	ColoringHomeUsingCombinationNM::ColoringHomeUsingCombination objColoringHomeUsingCombination;
	objColoringHomeUsingCombination.callColoringHomeUsingCombination();

	ColorHomeWithMinimumCostUsingDPNM::ColorHomeWithMinimumCostUsingDP objColorHomeWithMinimumCostUsingDP;
	objColorHomeWithMinimumCostUsingDP.callColorHomeWithMinimumCostUsingDP();

	LongestCommonPalidroneNM::CallLongestCommonPalidrone objLongestCommonPalidrone;
	objLongestCommonPalidrone.callLongestCommonPalidrone();

	

	PalidroneUsingRecursionNM::PalidroneUsingRecursion objPalidroneUsingRecursion;
	objPalidroneUsingRecursion.CallPalidroneUsingRecursion();

	
	TwoColorSortingNM::TwoColorSorting objTwoColorSorting;
	objTwoColorSorting.callTwoColorSorting();

	RevLLNM::RevLL objRevLL;
	objRevLL.callRevLL();

	FindTopTenPercentNM::callFindTopTenPercentX objcallFindTopTenPercentX;
	objcallFindTopTenPercentX.callFindTopTenPercent();

	BoyerMooreVotingNM::BoyerMooreVotingX objBoyerMooreVotingX;
	objBoyerMooreVotingX.callBoyerVoting();
	




	ReverseDoublyLinkedListNM::ReverseDoublyLinkedListX objReverseDoublyLinkedListX;
	objReverseDoublyLinkedListX.callRevDLL();

	

	testSingleTonOneX objtestSingleTonOneX;
	objtestSingleTonOneX.callSingleTonOneX();


	MedianOfMedian objMedianOfMedian;
	objMedianOfMedian.call();



	PrintTopAndBottomFacingNodes objPrintTopAndBottomFacingNodes;
	objPrintTopAndBottomFacingNodes.callPrintTopAndBottomFacingNodes();

	SwapAlternativeKthNodeNM::SwapKthNode objSwapKthNode;
	objSwapKthNode.callSwapKthNode();

	ArrayHasConsecutiveNumber objArrayHasConsecutiveNumber;
	objArrayHasConsecutiveNumber.callArrayHasConsecutiveNumber();

	LCSstring objLCSstring;
	objLCSstring.getLCS();

	BinSearchForLoopNM::BinSearchForLoop objbinSearchForLoop;
	objbinSearchForLoop.callBinSearchForLoop();

	StringRotatedNM::StringRotated objStringRotated;
	objStringRotated.callStringRotated();

	StackTest xStackTest;
	xStackTest.TestStack();


	CallSyncDq objCallSyncDq;
	objCallSyncDq.callSyncDqX();
	objCallSyncDq.callSyncDqXSync();

	callProdConsume objcallProdConsume;
	objcallProdConsume.callProd();
	////////////////////////////////////////////////
	
	TrieNM::UseInvertedIndex objUseInvertedIndex;
	objUseInvertedIndex.CallUseInvertedIndex();

	PowerSetNM::CallPowerSet objCallPowerSet;
	objCallPowerSet.callPowerSetX();

	CombinationsBitGenNM::CombinationUsingBitGen objCombinationUsingBitGen;
	objCombinationUsingBitGen.useCombination();

	BuddyMemoryManager::callAllocator callAllocatorX;
	callAllocatorX.UseMemoryManager();
		
	PermutationsNM::Permutation objPerm;
	objPerm.usePermutation();

	CombinationsNM::Combination objComb1;
	objComb1.useCombination();

	GraphMovie::testGraphMv objtestGraphMv;
	objtestGraphMv.testGraph();

	MatrixRotateNm::MatrixInCircle objMatrixInCircle;
	objMatrixInCircle.callMatrixInCircle();




	editablePQ::TestEditablePQ objTestEditablePQ;
	objTestEditablePQ.callEditablePQ();

	GraphSearch::callGraphSearch objcallGraphSearch;
	objcallGraphSearch.callGraphSearchX();

	testGraphAirLine objtestGraphAirLine;
	objtestGraphAirLine.calltestGraphAirLine();

	RemoveCommaX objRemoveCommaX;
	objRemoveCommaX.callRemoveComma();


	print123withPlusX objprint123withPlusX;
	objprint123withPlusX.callprint123withPlusX();

    return 0;
}

