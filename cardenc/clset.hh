/*
 * clset.hh
 *
 *  Created on: Nov 22, 2013
 *      Author: aign
 */

#ifndef CLSET_HH_
#define CLSET_HH_

#include <algorithm>
#include <vector>
#include <ostream>

class ClauseSet {
public:
	ClauseSet() : clauses(0) {}
	ClauseSet(ClauseSet& orig) : clauses(orig.clauses) {}

	void clear()
	{
		clauses.clear();
	}

	size_t size()
	{
		return clauses.size();
	}

	void resize(size_t sz_new)
	{
		return clauses.resize(sz_new);
	}

    std::vector<int>& operator[](size_t i)
	{
		return clauses[i];
	}

    void erase(std::vector<int>& cl)
	{
		clauses.erase(std::find(clauses.begin(), clauses.end(), cl));
	}

	void erase_subset(size_t start, ClauseSet& clset)
	{
		if (clset.size()) {
            std::vector<int>& cl_first = clset[0];
            std::vector<std::vector<int> >::iterator begin = std::find(clauses.begin() + start, clauses.end(), cl_first);
			clauses.erase(begin, begin + clset.size());
		}
	}

    std::vector<std::vector<int> >& get_clauses()
	{
		return clauses;
	}

    void add_clause(std::vector<int> cl)
	{
		clauses.push_back(cl);
	}

    void add_clause_ref(std::vector<int>& cl)
	{
		clauses.push_back(cl);
	}

    void create_clause(std::vector<int>& cl)
	{
		add_clause(cl);
	}

	void create_unit_clause(int l)
	{
        std::vector<int> cl; cl.push_back(l);
		clauses.push_back(cl);
	}

	void create_binary_clause(int l1, int l2)
	{
        std::vector<int> cl;
		cl.push_back(l1);
		cl.push_back(l2);

		clauses.push_back(cl);
	}

	void create_ternary_clause(int l1, int l2, int l3)
	{
        std::vector<int> cl;
		cl.push_back(l1);
		cl.push_back(l2);
		cl.push_back(l3);

		clauses.push_back(cl);
	}

    void dump(std::ostream& out)
	{
		for (size_t i = 0; i < clauses.size(); ++i)
			dump_clause(out, clauses[i]);
	}
private:
    void dump_clause(std::ostream& out, std::vector<int>& cl)
	{
		for (size_t i = 0; i < cl.size(); ++i)
				out << cl[i] << " ";
        out << "0" << std::endl;
	}
protected:
    std::vector<std::vector<int> > clauses;
};

#endif // CLSET_HH_
