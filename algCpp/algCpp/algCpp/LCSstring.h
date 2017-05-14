#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<memory>

using namespace std;

class LCSstring
{
	public:
			void getLCS()
			{
				int data[5][5] = {};
				string s1("CATCGA");
				string s2("GTACCGTCA");
				finfLCS(s1,s2);
			}

			void finfLCS(string s1, string s2)
			{
				int **sol = new int*[s1.length()+1];
				for (int i = 0; i <= s1.length(); i++)
				{
					sol[i] = new int[s2.length()+1];
				}

				//top-row zero
				for (int i = 0; i <= s2.length(); i++)
				{
					sol[0][i] = 0;
				}

				//left-most column
				for (int i = 0; i <= s1.length(); i++)
				{
					sol[i][0] = 0;
				}

				const char* p = s1.c_str();
				const char* q = s2.c_str();

				for (int i = 1; i <= s1.length(); i++)
				{
					for (int j = 1; j <= s2.length(); j++)
					{
						if (p[i - 1] == q[j - 1])
						{
							sol[i][j] = sol[i - 1][j - 1] + 1;
						}
						else
						{
							if (sol[i - 1][j] > sol[i][j - 1])
								sol[i][j] = sol[i - 1][j];
							else
								sol[i][j] = sol[i][j - 1];
						}
					}
				}

				for (int i = 0; i <= s1.length(); i++)
				{
					for (int j = 0; j <= s2.length(); j++)
					{
						cout << sol[i][j] << " ";
					}
					cout << endl;
				}
				int k = 0;
				char* p1 = (char*) s1.c_str();
				char* q1 = (char*) s2.c_str();
				
				char  out[_MAX_PATH] = { '\0' };
				//find LCS word. Walk from botto-left to top
				int x = s1.length() - 1;
				int y = s2.length() - 1;

				
				while(x > 0 && y > 0)
				{
					if (p1[x - 1] == q1[y - 1])
					{

						out[k++] = p1[x - 1];
						x--;
						y--;
					}
					else
					{
						if (sol[x - 1][y] > sol[x][y - 1])
						{
							x--;
						}
						else
						{
							y--;
						}
					}
				}
			}
};