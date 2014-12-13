#pragma once
#include <iostream>
class subscriber_t;

class MyMap
{
public:
	MyMap();
	~MyMap();
};

template <class IND, class INF>
struct Pair{
	IND first;
	INF second;
	Pair() :first(IND()), second(INF()){}
	Pair(const Pair &p) :first(p.first), second(p.second){}
};


template <class IND, class INF>
std::ostream & operator <<(std::ostream &os, const Pair<IND, INF> &p)
{
	os << '"' << p.first << '"';
	if (p.second)
		os << " is a " << (*p.second);
	else
		os << "is empty";
	return os;
}

template <class IND, class INF>
const Pair<IND, INF> make_pair(const IND& s, const INF &p)
{
	return Pair<IND, INF>(s, p);
}

template <class IND, class INF>
class MymapIt;

template <class IND, class INF>
class const_MymapIt;

template <class IND, class INF>
class Mymap
{
	friend class MymapIt < IND, INF > ;
	friend class const_MymapIt < IND, INF > ;
private:
	static const int QUOTA = 10;
	int cnt;
	Pair<IND, INF> *arr;
	int maxsz;
public:
	typedef MymapIt<IND, INF> Iterator;
	typedef const_MymapIt<IND, INF> const_Iterator;

	Mymap() :maxsz(QUOTA), cnt(0), arr(new Pair<IND, INF>[QUOTA]){}
	Mymap(const Mymap<IND, INF> &);
	Mymap(Mymap<IND, INF> && p);
	~Mymap(){ delete[] arr; }
	//перемещающее присваивание
	//перемещающий конструктор
	Mymap<IND, INF>& operator = (const Mymap<IND, INF> &);
	Mymap<IND, INF>& operator = ( Mymap<IND, INF> &&);
	int size();

	void insert(const IND&, const INF&);
	void clear(){ delete[] arr; }

	Iterator find(const IND&);
	Iterator begin();
	Iterator end();

	const_Iterator begin() const;
	const_Iterator end() const;
};

template < class IND, class INF >
Mymap<IND, INF>& Mymap<IND, INF>::operator = (Mymap<IND, INF> &&ob)
{
	int tcnt = cnt;
	cnt = ob.cnt;
	ob.cnt = tcnt;

	Pair<IND, INF> *tarr=arr;
	arr = ob.arr;
	ob.arr = tarr;

	int tmaxsz = maxsz;
	maxsz = ob.maxsz;
	ob.maxsz = tmaxsz;

	return *this;

}

template < class IND, class INF >
Mymap<IND, INF>::Mymap<IND, INF>(Mymap<IND, INF> &&ob) :
	cnt(ob.cnt),
	maxsz(ob.maxsz),
	arr(ob.arr)
{
	ob.arr = nullptr;
}

template <class IND, class INF>
MymapIt<IND, INF> Mymap<IND, INF>::begin()
{
	return MymapIt<IND, INF>(*this);
}

template <class IND, class INF>
MymapIt<IND, INF> Mymap<IND, INF>::end()
{
	return MymapIt<IND, INF>(*this, cnt);
}

template <class IND, class INF>
const_MymapIt<IND, INF> Mymap<IND, INF>::begin() const
{
	return const_MymapIt<IND, INF>(*this);
}

template <class IND, class INF>
const_MymapIt<IND, INF> Mymap<IND, INF>::end() const
{
	return const_MymapIt<IND, INF>(*this, cnt);
}

template <class IND, class INF>
Mymap<IND, INF>::Mymap(const Mymap<IND, INF> &t) :maxsz(t.maxsz), cnt(t.cnt)
{
	arr = new Pair<IND, INF>[maxsz];
	for (int i = 0; i < cnt; i++)
		arr[i] = t.arr[i];
}

template <class IND, class INF>
Mymap<IND, INF>& Mymap<IND, INF>::operator = (const Mymap<IND, INF> &a)
{
	if (this != &a){
		delete[] arr;
		arr = new Pair<IND, INF>[maxsz = a.maxsz];
		cnt = a.cnt;
		for (int i = 0; i < cnt; i++)
			arr[i] = a.arr[i];
	}
	return *this;
}

template <class IND, class INF>
void Mymap<IND, INF>::insert(const IND &s, const INF &f)
{
	int i;

	for (i = 0; i < cnt; ++i)
		if (arr[i].first == s)
			throw std::exception("dupplicate key");

	if (cnt == maxsz)
	{
		Pair<IND, INF> *cur = new Pair<IND, INF>[maxsz += QUOTA];

		for (i = 0; i < cnt; i++)
			cur[i] = arr[i];
		delete[] arr;
		arr = cur;
	}
	arr[cnt].first = s;
	arr[cnt++].second = f;
}



template <class IND, class INF>
MymapIt<IND, INF> Mymap<IND, INF>::find(const IND &s)
{
	for (int i = 0; i < cnt; ++i)
		if (arr[i].first == s)
			return MymapIt<IND, INF>(*this, i);
	return MymapIt<IND, INF>(*this, cnt);
}

template <class IND, class INF>
int Mymap<IND, INF>::size()
{
	return cnt;
}

// -------- template class MymapIt ----------------
template <class IND, class INF>
class MymapIt
{
private:
	Mymap<IND, INF> *pAs;
	int cur;
public:
	MymapIt(Mymap<IND, INF> &as, int last = 0) :pAs(&as), cur(last){}
	MymapIt() :pAs(NULL), cur(0){}
	Pair<IND, INF>& operator *();
	MymapIt<IND, INF>& operator ++();
	MymapIt<IND, INF> operator ++(int);
	int operator !=(const MymapIt<IND, INF> &) const;
	int operator ==(const MymapIt<IND, INF> &) const;
};

template <class IND, class INF>
Pair<IND, INF>& MymapIt<IND, INF>::operator *()
{
	return pAs->arr[cur];
}

template <class IND, class INF>
MymapIt<IND, INF>& MymapIt<IND, INF>::operator ++()
{
	++cur;
	return *this;
}

template <class IND, class INF>
MymapIt<IND, INF> MymapIt<IND, INF>::operator ++(int)
{
	MymapIt r(*this);
	++cur;
	return r;
}

template <class IND, class INF>
int MymapIt<IND, INF>::operator !=(const MymapIt<IND, INF> &a) const
{
	return pAs != a.pAs || cur != a.cur;
}

template <class IND, class INF>
int MymapIt<IND, INF>::operator ==(const MymapIt<IND, INF> &a) const
{
	return pAs == a.pAs && cur == a.cur;
}



// -------- template class const_MymapIt ----------------
template <class IND, class INF>
class const_MymapIt
{
private:
	const Mymap<IND, INF> *pAs;
	int cur;
public:
	const_MymapIt(const Mymap<IND, INF> &as, int last = 0) :pAs(&as), cur(last){}
	const_MymapIt() :pAs(NULL), cur(0){}

	const Pair<IND, INF>& operator *() const;

	const_MymapIt<IND, INF>& operator ++();
	const_MymapIt<IND, INF> operator ++(int);

	int operator !=(const const_MymapIt<IND, INF> &) const;
	int operator ==(const const_MymapIt<IND, INF> &) const;
};

template <class IND, class INF>
const Pair<IND, INF>& const_MymapIt<IND, INF>::operator *() const
{
	return pAs->arr[cur];
}

template <class IND, class INF>
const_MymapIt<IND, INF>& const_MymapIt<IND, INF>::operator ++()
{
	++cur;
	return *this;
}

template <class IND, class INF>
const_MymapIt<IND, INF> const_MymapIt<IND, INF>::operator ++(int)
{
	const_MymapIt r(*this);
	++cur;
	return r;
}

template <class IND, class INF>
int const_MymapIt<IND, INF>::operator !=(const const_MymapIt<IND, INF> &a) const
{
	return pAs != a.pAs || cur != a.cur;
}

template <class IND, class INF>
int const_MymapIt<IND, INF>::operator ==(const const_MymapIt<IND, INF> &a) const
{
	return pAs == a.pAs && cur == a.cur;
}


