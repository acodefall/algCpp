#pragma once
#include <iostream>
#include <memory>
using namespace std;

struct NodeX1
{
	unique_ptr<NodeX1> next;
	int data;
	NodeX1(int x)
	{
		data = x;
		next = nullptr;
	}
};


class RevLL
{
	unique_ptr<NodeX1> prev;
	public:
		void reversetLL(unique_ptr<NodeX1> rt)
		{
			unique_ptr<NodeX1> cur = std::move(rt);
			while (cur != nullptr)
			{
				unique_ptr<NodeX1> tmp = std::move(cur->next);
				cur->next = std::move(prev);
				prev = std::move(cur);
				cur = std::move(tmp);
			}
		}
		/*unique_ptr<NodeX1> buildRevLL()
		{
			int v = 10;
			unique_ptr<NodeX1> rt(new NodeX1(v++));
			rt->next = make_unique<NodeX1>(new NodeX1(v++));
			rt->next->next = make_unique<NodeX1>(new NodeX1(v++));
			rt->next->next->next = make_unique<NodeX1>(new NodeX1(v++));
			rt->next->next->next->next = make_unique<NodeX1>(new NodeX1(v++));
			rt->next->next->next->next->next = make_unique<NodeX1>(new NodeX1(v++));
			rt->next->next->next->next->next->next = make_unique<NodeX1>(new NodeX1(v++));
			rt->next->next->next->next->next->next->next = make_unique<NodeX1>(new NodeX1(v++));
			rt->next->next->next->next->next->next->next->next = make_unique<NodeX1>(new NodeX1(v++));
			rt->next->next->next->next->next->next->next->next->next = make_unique<NodeX1>(new NodeX1(v++));
			rt->next->next->next->next->next->next->next->next->next->next = make_unique<NodeX1>(new NodeX1(v++));
			rt->next->next->next->next->next->next->next->next->next->next->next = make_unique<NodeX1>(new NodeX1(v++));

			return rt;
		}*/

		

};