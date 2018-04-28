

namespace PolishNotationNM
{
	class PolishNotation
	{
		public:
				void callPolishNotation()
				{
					stack<int> st;
					string s="*-567"; //(5-6)*7
					
					for(int i = 0; i < s.length(); i++;)
					{
						if(c >= '0' || c <= '9')
						{
							char sym = st.pop();
							if(sym == '+')
							{
							
								
							}
						}
						else
						{
							st.push(c);
						}
						
					}
					
				
				}
	}

};