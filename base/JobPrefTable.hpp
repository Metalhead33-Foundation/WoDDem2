#ifndef JOBPREFTABLE_HPP
#define JOBPREFTABLE_HPP
#include <unordered_map>
#include <limits>
typedef std::unordered_map<int,float> JobPrefTable;
typedef JobPrefTable::iterator JobPrefIterator;

bool isFloatZero(const float& flt);
bool isDoubleZero(const double& dbl);

template<typename T> struct numeric_details_default {
	static T epsilon() { return std::numeric_limits<T>::epsilon(); }
};

#define NUMERICAL_DETAILS( name, EPS ) \
template<typename T> struct numeric_details_##name { \
	static T epsilon() { return EPS; } \
};
NUMERICAL_DETAILS(work, 0.005)

template<typename T, class Traits = numeric_details_default<T> > bool isZero(const T& dbl) {
	return std::abs(dbl) < Traits::epsilon();
}

#endif // JOBPREFTABLE_HPP
