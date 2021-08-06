#pragma once
#ifndef HEAPRIORITY_H
#define HEAPRIORITY_H
#include"vector.h"
template <typename E,typename C>
class heappriority
{
public:
	typedef E* Position;
	typedef const E* const_Position;
private:
	vector<E> V;
	C isless;
protected:
	int idx(const_Position p) const
	{
		return p - V.begin();
	}
	bool empty() const
	{
		return V.size() == 0;
	}
	Position pos(int i)
	{
		return  V.begin() + i;
	}
public:
	explicit heappriority() { };
	// constructor
	int size() const
	{
		return V.size() - 1;
	}
	Position left(const_Position p)
	{
		return pos(2 * idx(p));
	}
	Position right(const_Position p)
	{
		return pos(2 * idx(p) + 1);
	}
	Position parent(const_Position p)
	{
		return pos(floor(idx(p) / 2));
	}
	bool hasLeft(const_Position p) const
	{
		return 2 * idx(p) <= size();
	}
	bool hasRight(const_Position p) const { return 2 * idx(p) + 1 <= size(); }
	bool isRoot(Position  p) 
	{
		return idx(p) == 1;
	}
	Position root()
	{
		return pos(1);
	}
	Position last()
	{
		return pos(size());
	}
	void addLast(const E& e)
	{
		if (empty())
		{
			V.push_back(e);
		}	
		V.push_back(e);
	}
	void removeLast()
	{
		V.popback();
	}
	void swap(Position p, Position q)
	{
		E e = *q; *q = *p; *p = e;
	}
	void insert(const E& e)
	{
		addLast(e);
		Position last = V.end() - 1; 
		while (!isRoot(last))
		{
			Position father = parent(last);
			if (isless(*father, *last))
			{
				break;
			}
			swap(last, father);
			last = father;
		}
	}
	const E& min()
	{
		return *(root());
	}
	void removemin()
	{
		if (size() == 1)
			removeLast();
		else
		{
			Position u = root();
			swap(u, V.end() - 1);
			removeLast();
			while (hasLeft(u))
			{
				Position v = left(u);
				if (hasRight(u) && isless(*right(u), *v))
				     v = right(u);
				if (isless(*v, *u))
				{
					swap(v, u);
					u = v;
				}
				else
					break;
			}
		}
	}
	void print()
	{
		V.print();
	}
};
#endif // !HEAPRIORITY_h