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
#include "PriorityQUsage.h"
#include "SetComparison.h"
#include "MapComparison.h"
#include "MatrixRotatePrint.h"


int main()
{
	MatrixRotateNm::MatrixInCircle objMatrixInCircle;
	objMatrixInCircle.callMatrixInCircle();

	SetComparisonNM::testSetComparisonNM objtestSetComparisonNM;
	objtestSetComparisonNM.SetComparisonNM();

	MapComparisonNM::testMapComparisonNM  objtestMapComparisonNM;
	objtestMapComparisonNM.MapComparisonNM();

	UsageOfPrioriQNm::TestUsageOfPriorotyQ objTestUsageOfPriorotyQ;
	objTestUsageOfPriorotyQ.callTestingUsageOfPriorityQ();

	editablePQ::TestEditablePQ objTestEditablePQ;
	objTestEditablePQ.callEditablePQ();

	GraphSearch::callGraphSearch objcallGraphSearch;
	objcallGraphSearch.callGraphSearchX();

	testGraphAirLine objtestGraphAirLine;
	objtestGraphAirLine.calltestGraphAirLine();

	RemoveCommaX objRemoveCommaX;
	objRemoveCommaX.callRemoveComma();

	BinSearchForLoop objBinSearchForLoop;
	objBinSearchForLoop.callBinSearchForLoop();

	print123withPlusX objprint123withPlusX;
	objprint123withPlusX.callprint123withPlusX();

    return 0;
}

