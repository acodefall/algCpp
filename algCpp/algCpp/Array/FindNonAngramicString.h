#pragma once

namespace FindNonAngramicStringNM
{
	/*
		Find NonAnagramic string in List of strings. 
		1) Insert the strings in to map, where KEY is STRING and VALUE is anagramic signature. 
		2) Insert the strings in to List.
	    3) Go through the LIST and XOR adjacent VALUES. Before XORing sort them characters.
		   "xor 1st string with 2nd string". Then take the output of XOR and XOR it against 3rd string. 
		   Finally we will be left with the non anagramic string.
		   
	*/
	class FindNonAngramicString
	{

	};
};