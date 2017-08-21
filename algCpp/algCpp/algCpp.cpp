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
#include "ValueOfMidNode.h"
#include "EditablePriorityQueue.h"

#include "MatrixRotatePrint.h"
#include "MovieRatingGraph.h"
#include "Permutation.h"
#include "MemoryMngrBuddy.h"
#include "CombinationToWidth.h"
#include "PowerSet.h"
#include "TrieInvertedIndex.h"
#include "TopWordCountUsingTrie.h"
#include "Library.h"
#include "StackUsingArray.h"
#include "SyncQx.h"
#include "ProdConsumer.h"
#include "AreStringRotated.h"
#include "BinarySearchForLoop.h"
#include "LCSString.h"
#include "ArrayHasConsqNumbers.h"
#include "ReverseEveryKNodes.h"
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
#include "CountPathsInMatrix.h"
#include "SearchForNumberInSortedMatrix.h"
#include "CountPathInMatrixWithObstruction.h"
#include "PrintPathsOfMatrix.h"
#include "PathOfLowestCost.h""
#include "PrintDiagonalValues.h"
#include "CircularLLCheck.h"
#include "FindKthNodeFromTail.h"
#include "LinkedListToBSTConvertion.h"
#include "MergeSortedLL.h"
#include "PartitionLL.h"
#include "RemoveDuplicateNodesLL.h"
#include "ReverseAlternativeKNodes.h"
#include "CheckTreeIsBSTUsingMinMax.h"
#include "BstToGreaterSum.h"
#include "BSTUsingPreOrderData.h"
#include "CheckTreeIsMIRROR.h"
#include "CheckTreeIsIdentical.h"
#include "ConstructSingleThreadedTree.h"
#include "DFSSearch.h"
#include "FindNodeDistanceFromRoot.h"
#include "FindDeepestLeftNode.h"
#include "FindDeepestNodeInPlainTree.h"
#include "FindSuccessorNode.h"
#include "FindNodeDistanceKFromLeaf.h"
#include "FindMaxValueNode.h"
#include "TraversalsUsingStack.h"
#include "TraversalUsingRecursion.h"
#include "PostOrderUsingStack.h"
#include "LowestCommonDescendent.h"
#include "CreateBSTFromArray.h"
#include "PrintAllPathsOfTree.h"
#include "PrintFullNodes.h"
#include "PrintLeftFacingNodes.h"
#include "PrintPathTilllSumReachesK.h"
#include "FindPathToNodeValueKInPlainBinaryTree.h"
#include "SumOfLeftLEAF.h"
#include "NodeCount.h"
#include "TreeHeightUsingRecursion.h"
#include "TreeHeightUsingNonRecursion.h"
#include "TreeBalanced.h"
#include "MaxSubArray.h"
#include "ReverseWithoutTemp.h"
#include "UniqueChars.h"
#include "FindNumberHigherThanKSorted.h"
#include "MaxDifference.h"
#include "IntersectionOfSortedArray.h"
#include "FindPeakElementUnsorted.h"
#include "Find2DPeak.h"
#include "FindKthUniqueItem.h"
#include "FindLowerRepeatIndexUnSorted.h"
#include "FindMissingNumber.h"
#include "FindOddNumberElements.h"
#include "FindKthUniqueItem.h"
#include "FindContiguousSubArrayWithSumX.h"
#include "BinSearchWhileLoop.h"
#include "CheckForConsecutiveNumb.h"
#include "FindCommonElementsSorted.h"
#include "Anagram1.h"
#include "AsciiToInt.h"
#include "BinarySearchInRotatedArray.h"
#include "BoyerMoore.h"
#include "CompactStringRemovingSpaces.h"
#include "BracketMatch.h"
#include "Division.h"
#include "FibForLoop.h"
#include "FibRecurse.h"
#include "FindSquareRoot.h"
#include "FibRecurseDP.h"
#include "FindNonDuplicateNumber.h"
#include "GeneratePrimeNumbers.h"
#include "ChildHopping.h"
#include "ChildHoppingDP.h"
#include "InplaceMergingOfSortedArray.h"
#include "InplaceReversalWithoutTemp.h"
#include "IntToAscii.h"
#include "KnuthShuffle.h"
#include "MinMaxUsingLeastComparisons.h"
#include "OccurenceCountInSortedArray.h"
#include "Palidrone.h"
#include "RabinKarpRollingHash.h"
#include "CountEnabledBits.h"
#include "BitVector.h"
#include "BitDifference.h"
#include "BitSwapping.h"
#include "BitOperations.h"
#include "QueueUsingStack.h"
#include "StackWithGetMinimum.h"
#include "TowerOfHanoi.h"
#include "StackUsingLinkedList.h"
#include "BrickPoints.h"
#include "SortUsingStack.h"
#include "RemoveDuplicates.h"
#include "CombinationToTargetSum.h"
#include "CombinationsAll.h"
#include "ReverseWithoutTemp.h"
#include "Memcpy.h"
#include "MergeUnsortedWordList.h"
#include "PatternReplace.h"
#include "PrintLevelsOfTreeInALine.h"
#include "MergeAlternateNodesLL.h"
#include "PhoneBookUsingTrie.h"
#include "LongestCommonWordUsingTrie.h"
#include "FindAnagramsUsingTrie.h"
#include "BreakLongWordToSubwords.h"
#include "CoinChangeMakingUsingPerm.h"
#include "LongestCommonPrefixUsingTrie.h"
#include "SuggestWordsUsingTrie.h"
#include "KthItemInSortedAryUsingIntersection.h"
#include "FindOutOfOrderChar.h"
#include "FindKthItemInBST.h"
#include "AddTwoLL.h"

int main()
{
	AddTwoLLNM::AddTwoLL objAddTwoLL;
	objAddTwoLL.CallAddTwoLL();

	ValueOfMidNodeNM::ValueOfMidNode objValueOfMidNode;
	objValueOfMidNode.CallValueOfMidNode();

	FindKthItemInBSTNM::FindKthItemInBST objFindKthItemInBST;
	objFindKthItemInBST.callFindKthItemInBST();

	FindOutOfOrderCharNM::FindOutOfOrderChar objFindOutOfOrderChar;
	objFindOutOfOrderChar.callFindOutOfOrderChar();

	KthItemInSortedAryUsingIntersectionNM::KthItemInSortedAryUsingIntersection objKthItemInSortedAryUsingIntersection;
	objKthItemInSortedAryUsingIntersection.callKthItemInSortedAryUsingIntersection();

	SuggestWordsUsingTrieNM::UseSuggestWordsUsingTrie objUseSuggestWordsUsingTrie;
	objUseSuggestWordsUsingTrie.CallSuggestWordsUsingTrie();

	LongestCommonPrefixUsingTrieNM::UseLongestCommonPrefixUsingTrie objUseLongestCommonPrefixUsingTrie;
	objUseLongestCommonPrefixUsingTrie.CallLongestCommonPrefixUsingTrie();

	CoinChangeMakingUsingPermNM::CoinChangeMakingUsingPerm objCoinChangeMaking;
	objCoinChangeMaking.useCoinChangeMaking();

	CombinationToTargetSumNM::CombinationToTargetSum objCombinationToTargetSum;
	objCombinationToTargetSum.useCombination();

	BreakLongWordToSubwordsNM::BreakLongWordToSubwords objBreakLongWordToSubwords;
	objBreakLongWordToSubwords.callBreakLongWordToSubwords();

	FindAnagramsUsingTrieNM::UseFindAnagramsUsingTrie objUseFindAnagramsUsingTrie;
	objUseFindAnagramsUsingTrie.CallUseFindAnagramsUsingTrie();

	LowestCommonDescendentNM::LowestCommonDescendent objLowestCommonDescendent;
	objLowestCommonDescendent.callLowestCommonDescendent();

	LibraryNM::Library objLibrary;
	LongestCommonWordUsingTrieNM::UseLongestCommonWordUsingTrie objUseLongestCommonWordUsingTrie;
	objUseLongestCommonWordUsingTrie.CallLongestCommonWordUsingTrie();

	PhoneBookUsingTrieNM::UsePhoneBookUsingTrie objUsePhoneBookUsingTrie;
	objUsePhoneBookUsingTrie.CallPhoneBookUsingTrie();

	TopWordCountUsingTrieNM::UseTopWordCountUsingTrie objTopWordCountUsingTrie;
	objTopWordCountUsingTrie.CallUseTopWordCountUsingTrie();

	MergeAlternateNodesLLNM::MergeAlternateNodesLL objMergeAlternateNodesLL;
	objMergeAlternateNodesLL.callMergeAlternateNodesLL();

	PrintEveryLevelOfTreeInALineNM::PrintEveryLevelOfTreeInALine objPrintLevelsOfTreeInALine;
	objPrintLevelsOfTreeInALine.callPrintEveryLevelOfTreeInALine();

	PatternReplaceNM::PatternReplace	objPatternReplace;
	objPatternReplace.callPatternReplace();

	MergeUnsortedWordListNM::MergeUnsortedWordList objMergeUnsortedWordList;
	objMergeUnsortedWordList.callMergeUnsortedWordList();

	MemcpyNM::Memcpy objMemcpy;
	objMemcpy.CallMemcpy();

	ReverseWithoutTempNM::ReverseWithoutTemp objReverseWithoutTemp;
	objReverseWithoutTemp.callReverseWithoutTemp();

	PermutationsNM::Permutation objPerm;
	objPerm.usePermutation();


	CombinationsAllNM::CombinationsAll objCombinationsAll;
	objCombinationsAll.useCombination();

	

	CombinationsOfWidthXNM::CombinationsOfWidthX objCombinationUsingBitGen;
	objCombinationUsingBitGen.useCombination();

	PowerSetNM::CallPowerSet objCallPowerSet;
	objCallPowerSet.callPowerSetX();


	cout << "main begins \r\n";
	RemoveDuplicatesNM::RemoveDuplicates objRemoveDuplicates;
	objRemoveDuplicates.callRemoveDuplicates();

	SortUsingStackNM::SortUsingStack objSortUsingStack;
	objSortUsingStack.callSortUsingStack();

	BrickPointsNM::BrickPoints objBrickPoints;
	objBrickPoints.callBrickPoints();

	StackUsingLinkedListNM::callStackUsingLinkedList objcallStackUsingLinkedList;
	objcallStackUsingLinkedList.callStackUsingLL();

	TowerOfHanoiNM::TowerOfHanoi objTowerOfHanoi;
	objTowerOfHanoi.CallTowerOfHanoi();

	StackWithGetMinimumNM::callStackWithGetMinimum objcallStackWithGetMinimum;
	objcallStackWithGetMinimum.callStackWithGetMinimumX();

	QueueUsingStackNM::QueueUsingStackX objQueueUsingStack;
	objQueueUsingStack.callQueueUsingStack();

	StackUsingArrayNM::StackTest objStackTest;
	objStackTest.TestStack();

	BitOperationsNM::BitOperations objBitOperations;
	objBitOperations.callBitOperations();

	BitSwappingNM::BitSwapping objBitSwapping;
	objBitSwapping.callBitSwapping();

	BitDifferenceNM::BitDifference objBitDifference;
	objBitDifference.callBitDifference();

	BitVectorNM::BitVector objBitVector;
	objBitVector.callBitVector();

	CountEnabledBitsNM::CountEnabledBits objCountEnabledBits;
	objCountEnabledBits.callCountEnabledBits();


	GeneratePrimeNumbersNM::GeneratePrimeNumbers objGeneratePrimeNumbers;
	objGeneratePrimeNumbers.callGeneratePrimeNumbers();


	RabinKarpRollingHashNM::RabinKarpRollingHash objRabinKarpRollingHash;
	objRabinKarpRollingHash.callRabinKarpRollingHash();

	PalidroneNM::Palidrone objPalidrone;
	objPalidrone.callPalidrone();

	OccurenceCountInSortedArrayNM::OccurenceCountInSortedArray objOccurenceCountInSortedArray;
	objOccurenceCountInSortedArray.callOccurenceCountInSortedArray();
	MinMaxUsingLeastComparisonsNM::MinMaxUsingLeastComparisons objMinMaxUsingLeastComparisons;
	objMinMaxUsingLeastComparisons.callMinMaxUsingLeastComparisons();

	KnuthShuffleNM::KnuthShuffle objKnuthShuffle;
	objKnuthShuffle.callKnuthShuffle();

	IntToAsciiNM::IntToAscii	objIntToAscii;
	objIntToAscii.callIntToAscii();

	InplaceReversalWithoutTempNM::InplaceReversalWithoutTemp objInplaceReversalWithoutTemp;
	objInplaceReversalWithoutTemp.callInplaceReversalWithoutTemp();

	InplaceMergingOfSortedArrayNM::InplaceMergingOfSortedArray objInplaceMergingOfSortedArray;
	objInplaceMergingOfSortedArray.callInplaceMergingOfSortedArray();

	ChildHoppingDPNM::ChildHoppingDP objChildHoppingDP;
	objChildHoppingDP.callChildHoppingDP();

	ChildHoppingNM::ChildHopping objChildHopping;
	objChildHopping.callChildHopping();

	
	FindSquareRootNM::FindSquareRoot	objFindSquareRoot;
	objFindSquareRoot.callFindSquareRoot();

	FindNonDuplicateNumberNM::FindNonDuplicateNumber objFindNonDuplicateNumber;
	objFindNonDuplicateNumber.callFindNonDuplicateNumber();

	FibRecurseDPNM::FibRecurseDP	objFibRecurseDP;
	objFibRecurseDP.callFibRecursee();

	FibRecurseNM::FibRecurse objFibRecurse;
	objFibRecurse.callFibRecursee();

	FibForLoopNM::FibForLoop objFibForLoop;
	objFibForLoop.calllFibForLoop();

	DivisionNM::Division objDivision;
	objDivision.callDivision();

	BracketMatchNM::BracketMatch objBracketMatch;
	objBracketMatch.callBracketMatch();

	CompactStringRemovingSpacesNM::CompactStringRemovingSpaces objCompactStringRemovingSpaces;
	objCompactStringRemovingSpaces.callCompactStringRemovingSpaces();

	BoyerMooreNM::BoyerMoore objBoyerMoore;
	objBoyerMoore.callBoyerMoore();

	AsciiToIntNM::AsciiToInt objAsciiToInt;
	objAsciiToInt.callAsciiToInt();

	BinarySearchInRotatedArrayNM::BinarySearchInRotatedArray objBinarySearchInRotatedArray;
	objBinarySearchInRotatedArray.callBinarySearchInRotatedArray();

	Anagram1NM::Anagram1 objAnagram1;
	objAnagram1.callAnagram1();

	FindCommonElementsSortedNM::FindCommonElementsSorted objFindCommonElementsSorted;
	objFindCommonElementsSorted.callFindCommonElementsSorted();

	CheckForConsecutiveNumbNM::CheckForConsecutiveNumb objCheckForConsecutiveNumb;
	objCheckForConsecutiveNumb.callCheckForConsecutiveNumber();

	BinSearchWhileLoopNM::BinSearchWhileLoop objBinSearchWhileLoop;
	objBinSearchWhileLoop.callBinSearchWhileLoop();

	FindContiguousSubArrayWithSumXNM::FindContiguousSubArrayWithSumX objFindContiguousSubArrayWithSumX;
	objFindContiguousSubArrayWithSumX.callFindContiguousSubArrayWithSumX();

	FindKthUniqueItemNM::FindKthUniqueItem objFindKthUniqueItem;
	objFindKthUniqueItem.callFindKthUniqueItem();
	Find2DPeakNM::Find2DPeak objFind2DPeak;
	objFind2DPeak.callFindPeakElementUnsorted();

	FindPeakElementUnsortedNM::FindPeakElementUnsorted objFindPeakElement;
	objFindPeakElement.callFindPeakElementUnsorted();

	IntersectionOfSortedArrayNM::IntersectionOfSortedArray objIntersectionOfSortedArray;
	objIntersectionOfSortedArray.callIntersectionOfSortedArray();

	MaxDifferenceNM::MaxDifference objMaxDifference;
	objMaxDifference.callMaxDifference();

	FindNumberHigherThanKSortedNM::FindNumberHigherThanKSorted objFindNumberHigherThanKSorted;
	objFindNumberHigherThanKSorted.callFindNumberHigherThanK();
		
	UniqueCharsNM::UniqueChars objUniqueChars;
	objUniqueChars.callUniqueChars();



	MaxSubArrayNM::MaxSubArray objMaxSubArray;
	objMaxSubArray.callMaxSubArray();

	TreeBalancedNM::TreeBalanced objTreeBalanced;
	objTreeBalanced.callTreeBalanced();
	TreeHeightUsingNonRecursionNM::TreeHeightUsingNonRecursion objTreeHeightUsingNonRecursion;
	objTreeHeightUsingNonRecursion.callTreeHeightUsingNonRecursion();

	TreeHeightUsingRecursionNM::TreeHeightUsingRecursion	objTreeHeight;
	objTreeHeight.callTreeHeight();

	NodeCountNM::NodeCount	objNodeCount;
	objNodeCount.callNodeCount();


	SumOfLeftLEAFNM::SumOfLeftLEAF objSumOfLeftLEAF;
	objSumOfLeftLEAF.callSumOfLeftLEAF();

	FindPathToNodeValueKInPlainBinaryTreeNM::FindPathToNodeValueKInPlainBinaryTree objFindPathToNodeValueKInPlainBinaryTree;
	objFindPathToNodeValueKInPlainBinaryTree.callFindPathToNodeValueKInPlainBinaryTree();

	PrintPathTilllSumReachesKNM::PrintPathTilllSumReachesK objPrintPathTilllSumReachesK;
	objPrintPathTilllSumReachesK.callPrintPathTilllSumReachesK();

	PrintLeftFacingNodesNM::PrintLeftFacingNodes objPrintLeftFacingNodes;
	objPrintLeftFacingNodes.callPrintLeftFacingNodes();
	
	PrintFullNodesNM::PrintFullNodes objPrintFullNodes;
	objPrintFullNodes.callPrintAllPathsOfTree();

	PrintAllPathsOfTreeNM::PrintAllPathsOfTree objPrintAllPathsOfTree;
	objPrintAllPathsOfTree.callPrintAllPathsOfTree();

	CreateBSTFromArrayNM::CreateBSTFromArray objCreateBSTFromArray;
	objCreateBSTFromArray.callCreateBSTFromArray();


	TraversalUsingRecursionNM::TraversalUsingRecursion objTraversalUsingRecursion;
	objTraversalUsingRecursion.callTraversalUsingRecursion();

	TreeTraversalsUsingStackNM::TreeTraversalsUsingStack objTreeTraversalsUsingStack;
	objTreeTraversalsUsingStack.callTreeTraversalsUsingStack();

	PostOrderUsingStackNM::PostOrderUsingStack objPostOrderUsingStack;
	objPostOrderUsingStack.callTreeTraversalsUsingStack();

	FindMaxValueNodeNM::FindMaxValueNode objFindMaxValueNode;
	objFindMaxValueNode.callFindMaxValueNode();

	FindNodeDistanceKFromLeafNM::FindNodeDistanceKFromLeaf objFindNodeDistanceKFromLeaf;
	objFindNodeDistanceKFromLeaf.callFindNodeDistanceKFromLeaf();

	FindSuccessorNodeNM::FindSuccessorNode objFindSuccessorNode;
	objFindSuccessorNode.callFindSuccessorNode();

	FindDeepestNodeInPlainTreeNM::FindDeepestNodeInPlainTree objFindDeepestNodeInPlainTree;
	objFindDeepestNodeInPlainTree.callFindDeepestNodeInPlainTree();

	FindDeepestLeftNodeNM::FindDeepestLeftNode objFindDeepestLeftNode;
	objFindDeepestLeftNode.callFindDeepestLeftNode();

	FindNodeDistanceFromRootNM::FindNodeDistanceFromRoot objFindNodeDistanceFromRoot;
	objFindNodeDistanceFromRoot.callFindNodeDistanceFromRoot();

	DFSSearchNM::DFSSearch objDFSSearch;
	objDFSSearch.callDFSSearch();

	ConstructSingleThreadedTreeNM::ConstructSingleThreadedTree objConstructSingleThreadedTree;
	objConstructSingleThreadedTree.callConstructSingleThreadedTree();

	CheckTreeIsIdenticalNM::CheckTreeIsIdentical objCheckTreeIsIdentical;
	objCheckTreeIsIdentical.callCheckTreeIsIdentical();

	CheckTreeIsMIRRORNM::CheckTreeIsMIRROR objCheckTreeIsMIRROR;
	objCheckTreeIsMIRROR.callCheckTreeIsMIRROR();

	BSTUsingPreOrderDataNM::BSTUsingPreOrderData  objBSTUsingPreOrderData;
	objBSTUsingPreOrderData.callBSTUsingPreOrderData();

	BstToGreaterSumNM::BstToGreaterSum objBstToGreaterSum;
	objBstToGreaterSum.callBstToGreaterSum();

	CheckTreeIsBSTUsingMinMaxNM::CheckTreeIsBSTUsingMinMax objCheckTreeIsBSTUsingMinMax;
	objCheckTreeIsBSTUsingMinMax.callCheckTreeIsBSTUsingMinMaxNM();

	ReverseDoublyLinkedListNM::ReverseDoublyLinkedListX objReverseDoublyLinkedListX;
	objReverseDoublyLinkedListX.callRevDLL();


	ReverseAlternativeKNodesNM::ReverseAlternativeKNodes objReverseAlternativeKNodes;
	objReverseAlternativeKNodes.callReverseAlternativeKNodes();

	ReverseEveryKNodesNM::ReverseEveryKNodes objReverseEveryKNodes;
	objReverseEveryKNodes.callReverseEveryKNodes();

	RemoveDuplicateNodesLLNM::RemoveDuplicateNodesLL objRemoveDuplicateNodesLL;
	objRemoveDuplicateNodesLL.callRemoveDuplicateNodesLL();

	PartitionLLNM::PartitionLL objPartitionLL;
	objPartitionLL.callPartitionLL();

	MergeSortedLLNM::MergeSortedLL objMergeSorted;
	objMergeSorted.callMergeSortedLL();

	LinkedListToBSTConvertionNM::LinkedListToBSTConvertion objLinkedListToBSTConvertion;
	objLinkedListToBSTConvertion.callLinkedListToBSTConvertion();

	FindKthNodeFromTailNM::FindKthNodeFromTail objFindKthNodeFromTail;
	objFindKthNodeFromTail.callFindKthNodeFromTail();

	CircularLLCheckNM::CircularLLCheck objCircularLLCheck;
	objCircularLLCheck.callCircularLLCheck();

	PrintDiagonalValuesNM::PrintDiagonalValues objPrintDiagonalValues;
	objPrintDiagonalValues.callPrintDiagonals();

	PathOfLowestCostNM::PathOfLowestCost objPathOfLowestCost;
	objPathOfLowestCost.callPathOfMinimumCost();

	PrintPathsOfMatrixNM::PrintPathsOfMatrix objPrintPathsOfMatrix;
	objPrintPathsOfMatrix.callCountPathsinMatrx();

	CountPathInMatrixWithObstructionNM::CountPathInMatrixWithObstruction objCountPathInMatrixWithObstruction;
	objCountPathInMatrixWithObstruction.CallCountPathsFromTopCornerToBottomMatrix();

	SearchForNumberInSortedMatrixNM::SearchForNumberInSortedMatrix objSearchForNumberInSortedMatrix;
	objSearchForNumberInSortedMatrix.callSearchForNumberInSortedMatrix();

	CountPathsFromTopCornerToBottomMatrixNM::CountPathsFromTopCornerToBottomMatrix  objCountPathsFromTopCornerToBottomMatrix;
	objCountPathsFromTopCornerToBottomMatrix.CallCountPathsFromTopCornerToBottomMatrix();

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
	




	
	

	testSingleTonOneX objtestSingleTonOneX;
	objtestSingleTonOneX.callSingleTonOneX();




	PrintTopAndBottomFacingNodes objPrintTopAndBottomFacingNodes;
	objPrintTopAndBottomFacingNodes.callPrintTopAndBottomFacingNodes();



	ArrayHasConsecutiveNumber objArrayHasConsecutiveNumber;
	objArrayHasConsecutiveNumber.callArrayHasConsecutiveNumber();

	LCSstring objLCSstring;
	objLCSstring.getLCS();

	BinSearchForLoopNM::BinSearchForLoop objbinSearchForLoop;
	objbinSearchForLoop.callBinSearchForLoop();

	StringRotatedNM::StringRotated objStringRotated;
	objStringRotated.callStringRotated();

	


	CallSyncDq objCallSyncDq;
	objCallSyncDq.callSyncDqX();
	objCallSyncDq.callSyncDqXSync();

	callProdConsume objcallProdConsume;
	objcallProdConsume.callProd();
	////////////////////////////////////////////////
	
	TrieInvertedIndexNM::UseTrieInvertedIndex objUseInvertedIndex;
	objUseInvertedIndex.CallUseInvertedIndex();




	BuddyMemoryManager::callAllocator callAllocatorX;
	callAllocatorX.UseMemoryManager();
	


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

	RemoveCommaNM::RemoveCommaX objRemoveCommaX;
	objRemoveCommaX.callRemoveComma();


	print123withPlusX objprint123withPlusX;
	objprint123withPlusX.callprint123withPlusX();

    return 0;
}

