#pragma once

#include <iostream>
using namespace std;

namespace BinSearchBaseNM
{
	class BinSearchBase
	{
		public:

			int BinSearch(int src[], int srcLen, int Value)
			{
				cout << "\r\n" << "BinSearch() \r\n";
				for (int i = 0; i < srcLen; i++)
				{
					cout << src[i] << " ";
				}
				cout << "\r\n";
				int ret = BinSearchX(src, srcLen, Value);
				cout << "\r\n" << "BinSearch() return "<< ret << "\r\n";
				cout << "\r\n";
				return ret;
			}

			int BinSearchPtr(int* src, int srcLen, int Value)
			{
				cout << "\r\n" << "BinSearch() \r\n";
				for (int i = 0; i < srcLen; i++)
				{
					cout << src[i] << " ";
				}
				cout << "\r\n";
				int ret = BinSearchX(src, srcLen, Value);
				cout << "\r\n" << "BinSearch() return " << ret << "\r\n";
				cout << "\r\n";
				return ret;
			}

			int BinSearchException(int src[], int srcLen, int Value)
			{
				cout << "\r\n" << "BinSearchException() \r\n";
				int ret = BinSearchExceptionX(src, srcLen, Value);
				cout << "\r\n" << "BinSearchException() return " << ret << "\r\n";
				cout << "\r\n";
				return ret;
			}

			int BinSearchX(int src[], int srcLen, int Value)
			{
				int start = 0;
				int end = srcLen - 1;
				int mid = 0;

				while (start <= end)
				{
					mid = start + (end - start) / 2;
					if (Value > src[mid])
					{
						cout << "\r\n Value :" << Value << " src[" << mid << "] = " << src[mid] << " s: " << start << " e: " << end << " Tot: " << srcLen << " \r\n";
						start = mid + 1;
					}
					else if (Value < src[mid])
					{
						cout << "\r\n Value :" << Value << " src[" << mid << "] = " << src[mid] << " s: " << start << " e: " << end << " Tot: " << srcLen << " \r\n";
						end = mid - 1;
					}
					else
					{
						cout << "\r\n Value :" << Value << " src[" << mid << "] = " << src[mid] << " s: " << start << " e: " << end << " Tot: " << srcLen << " \r\n";
						return mid;
					}
				}
				return -1;
			}

			int BinSearchExceptionX(int src[], int srcLen, int Value)
			{
				int vTemp = 0;
				int start = 0;
				int end = srcLen - 1;
				int mid = 0;
				
				while (start <= end)
				{
					mid = start + (end - start) / 2;
					try
					{
						vTemp = src[mid];
					}
					catch (...)
					{
						end = mid - 1;
						cout << "\r\n Exception at " << mid << "new End " << end << "\r\n";
						break;
					}
					if (Value > vTemp)
					{
						cout << "\r\n Value :" << Value << " src[" << mid << "] = " << vTemp << " s: " << start << " e: " << end << " Tot: " << srcLen << " \r\n";
						start = mid + 1;
					}
					else if (Value < vTemp)
					{
						cout << "\r\n Value :" << Value << " src[" << mid << "] = " << vTemp << " s: " << start << " e: " << end << " Tot: " << srcLen << " \r\n";
						end = mid - 1;
					}
					else
					{
						cout << "\r\n Value :" << Value << " src[" << mid << "] = " << vTemp << " s: " << start << " e: " << end << " Tot: " << srcLen << " \r\n";
						return mid;
					}
				}

				
				return -1;
			}

	};
};