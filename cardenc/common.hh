/*
 * common.hh (based on the 'card' library from BOLT)
 *
 *  Created on: Sep 25, 2017
 *      Author: aign
 */

#ifndef CARDCOMMON_HH_
#define CARDCOMMON_HH_

#include "clset.hh"

//
//=============================================================================
inline void common_encode_atleast1(ClauseSet& clset, std::vector<int>& vars)
{
    std::vector<int> cl;

	for (size_t i = 0; i < vars.size(); ++i)
		cl.push_back(vars[i]);

	clset.create_clause(cl);
}

//
//=============================================================================
inline void common_encode_atleastN(ClauseSet& clset, std::vector<int>& vars)
{
	for (size_t i = 0; i < vars.size(); ++i) {
        std::vector<int> cl(1, vars[i]);
		clset.create_clause(cl);
	}
}

//
//=============================================================================
inline void common_encode_atmost0(ClauseSet& clset, std::vector<int>& vars)
{
	for (size_t i = 0; i < vars.size(); ++i) {
        std::vector<int> cl(1, -vars[i]);
		clset.create_clause(cl);
	}
}

//
//=============================================================================
inline void common_encode_atmostNm1(ClauseSet& clset, std::vector<int>& vars)
{
    std::vector<int> cl;

	for (size_t i = 0; i < vars.size(); ++i)
		cl.push_back(-vars[i]);

	clset.create_clause(cl);
}

#endif // CARDCOMMON_HH_
