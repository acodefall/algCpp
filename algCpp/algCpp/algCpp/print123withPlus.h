#pragma once
#include <iostream>
#include <memory>
using namespace std;

/*
FB question
	given "123" insert + and - in all combinations and 	then print the result.

	 1 1 1		+1+2+3 = 6
	 0 1 1		1+2+3 = 6
	 1 0 1		+12+3 = 15
	 0 0 1		12+3 = 15
	 1 1 0		+1+23 = 24
	 0 1 0		1+23 = 24
	 1 0 0		+123 = 123
	 0 0 0		123 = 23

*/
class print123withPlusX
{
public:
	void callprint123withPlusX()
	{
		string src;

		src = "123";
		int* x = new int[src.length()]{0};
		unique_ptr<int> bits(new int[src.length()]{ 0 });

		generateCombs(bits.get(), src.length() - 1, src, src.length(), '+');
	}


	void generateCombs(int* bits, int idx, string& src, int width, char symbol)
	{
		if (idx < 0)
		{
			int total = 0;
			string out;
			string out2;
			for (int t = 0; t < width; t++)
			{
				if (bits[t] > 0)
				{
					out2 = out2.append(" 1");
					out = out.append(1, symbol);
				}
				else
					out2 = out2.append(" 0");
				out = out.append(1, src.c_str()[t]);
		
			}
		

		

			cout << out2.c_str() << " "  << out.c_str() ;
			//+123
			//+1+2+3
			//
			int tkn = 0;
			string ts;
			int k = 0;
			for (k = 0; k < out.length(); k++)
			{
				if (k > 0)
				{
					if (out.c_str()[k] == '+')
					{
						ts = out.substr(tkn + 1, k - (tkn + 1));
						total += atoi(ts.c_str());
						tkn = k;
					}
				}
			}
			ts = out.substr(tkn + 1, k - (tkn + 1));
			total += atoi(ts.c_str());
			cout << " = " << total << "\r\n";
			return;
		}

		bits[idx] = 1;
		generateCombs(bits, idx - 1, src, width, symbol);

		bits[idx] = 0;
		generateCombs(bits, idx - 1, src, width, symbol);

		return;
	}
};