// algCpp.cpp : Defines the entry point for the console application.
//

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


int main()
{
	LibraryNM::Library objLibrary;

	cout << "main begins";
	FindTopTenPercentNM::callFindTopTenPercentX objcallFindTopTenPercentX;
	objcallFindTopTenPercentX.callFindTopTenPercent();

	BoyerMooreVotingNM::BoyerMooreVotingX objBoyerMooreVotingX;
	objBoyerMooreVotingX.callBoyerVoting();
	
	RotateArrayUsingReverseNM::RotateArrayUsingReverseX objRotateArrayUsingReverseX;
	objRotateArrayUsingReverseX.callRotateArrayUsingReverse();

	RotateArrayNM::RotateArrayX objRotateArray;
	objRotateArray.callRotateArray();

	ReverseDoublyLinkedListNM::ReverseDoublyLinkedListX objReverseDoublyLinkedListX;
	objReverseDoublyLinkedListX.callRevDLL();

	

	testSingleTonOneX objtestSingleTonOneX;
	objtestSingleTonOneX.callSingleTonOneX();


	MedianOfMedian objMedianOfMedian;
	objMedianOfMedian.call();



	PrintTopAndBottomFacingNodes objPrintTopAndBottomFacingNodes;
	objPrintTopAndBottomFacingNodes.callPrintTopAndBottomFacingNodes();

	SwapKthNode<int> objSwapKthNode;
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

