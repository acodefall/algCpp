#pragma once
#include <iostream>
using namespace std;

namespace RemoveCommaNM
{
	class RemoveCommaX
	{
		public:
			void callRemoveComma()
			{
				RemoveCommaY("ywe,,u7iui,yui,,,,789");
			}

			void RemoveCommaY(char* src)
			{
				int len = strlen(src);
				int idx = 0;
				int skip = 0;
				char* dup1 = strdup((const char*) src);

				while (idx < len)
				{
					if (dup1[idx] == ',')
					{
						skip++;
					}
					else
					{
						dup1[idx - skip] = dup1[idx];
					}
					idx++;
				}

				dup1[strlen(src) - skip] = 0;
				cout << dup1;
				if (dup1)
					free(dup1);
			}


	};

};