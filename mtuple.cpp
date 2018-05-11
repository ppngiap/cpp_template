#include <iostream>
#include <string>


// incomplete decl
template <typename... Ttypes> class Tuple;

// base case
template <> class Tuple<> { /* empty */ };

//recusive
template <typename Tvalue, typename... Trest>
class Tuple<Tvalue, Trest...> : public Tuple<Trest...> 
{
public:
	Tvalue value;
};


template <size_t idx, typename Ttuple> struct TupleElement;

// access the 0th elem
template <typename Tvalue, typename... Trest>
struct TupleElement<0, Tuple<Tvalue, Trest...> > {
	using type_t = Tvalue;                        // Type of value at this index
	using TupleType_t = Tuple<Tvalue, Trest...>;  // TupleType_t is a Tuple type 
	                                              // with TupleType_t::value has the 
						      // type type_t
};


// recursive TupleElement definition
template <size_t idx, typename Tvalue, typename... Trest>
struct TupleElement<idx, Tuple<Tvalue, Trest...> >
: public TupleElement<idx - 1, Tuple<Trest...> > { /* empty */ };


//get function to access the idxth element in the tuple
template <size_t idx, typename... Ttypes>               // template
typename TupleElement<idx, Tuple<Ttypes...> >::type_t&  // return type
get(Tuple<Ttypes...>& tuple) {
	using TupleType_t = typename TupleElement<idx, Tuple<Ttypes...> >::TupleType_t;
	return static_cast<TupleType_t&>(tuple).value;
}

//// Functions to fill the tuple with values ////
// done case
template <size_t idx, typename Ttuple>
void fillTuple(Ttuple& toFill) {}

// recursive
template <size_t idx, typename Ttuple, typename Tfirst, typename... Trest>
void fillTuple(Ttuple& toFill, const Tfirst& first, Trest... rest) {
	get<idx>(toFill) = first;
	fillTuple<idx + 1>(toFill, rest...);
}

// create tuple from values
template <typename... Ttypes>
Tuple<Ttypes...> makeTuple(Ttypes... args) {
	Tuple<Ttypes...> result;
	fillTuple<0>(result, args...);
	return result;
}

int main()
{
	Tuple<int, char, double> t;
	

	get<0>(t) = 2;
	get<1>(t) = 'c';
	get<2>(t) = 3.1;

	std::cout << get<0>(t) << std::endl;
	std::cout << get<1>(t) << std::endl;
	std::cout << get<2>(t) << std::endl;

	t = makeTuple(3, 'd', 4.1);

	std::cout << get<0>(t) << std::endl;
	std::cout << get<1>(t) << std::endl;
	std::cout << get<2>(t) << std::endl;

	return 0;
}


