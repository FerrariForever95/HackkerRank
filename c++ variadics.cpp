#include <iostream>
using namespace std;
template <bool... digits>
struct Binary;

template <>
struct Binary<>
{
    static int value()
    {
        return 0;
    }
};

template <bool first, bool... rest>
struct Binary<first, rest...>
{
    static int value()
    {
        return first + 2 * Binary<rest...>::value();
    }
};

template <bool... digits>
int reversed_binary_value()
{
    return Binary<digits...>::value();
}

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}
