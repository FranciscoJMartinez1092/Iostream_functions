//FILE: rec_fun.cxx
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>


namespace main_savitch_6
{
	void binary_print(std::ostream& outs, unsigned int n)
	//converts to binary
	{
		if (n == 0)
			outs << 0;
		if (n < 2)
		{
			if (n % 2 == 1)
				outs << 1;
		}
		else
		{
			binary_print(std::cout, n / 2);
			outs << n % 2;
		}
	}





	void triangle(std::ostream& outs, unsigned int m, unsigned int n)
		// Precondition: m <= n
		// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
		// to the output stream outs. The first line contains m asterisks, the next 
		// line contains m+1 asterisks, and so on up to a line with n asterisks.
		// Then the pattern is repeated backwards, going n back down to m.
		/* Example output:
		   triangle(cout, 3, 5) will print this to cout:
		   ***
		   ****
		   *****
		   *****
		   ****
		   ***
		*/
	{
		assert(m <= n);

		outs << std::string(m, '*') << std::endl;
		if (m == n)
			outs << std::string(m, '*') << std::endl;
		if (m != n)
		{
			triangle(std::cout, m + 1, n);
			outs << std::string(m, '*') << std::endl;
		}
	}

	double Pow(double x, int n)
		// Precondition: If x is zero, then n must be positive. 
		// Postcondition: The value returned is x raised to the power n.
	{
		if (x == 0)
		{
			assert(n > 0);
			return 0;
		}


		double even_odd;
		if (n == 0)
			return 1;

		even_odd = Pow(x, n / 2);
		if (n % 2 == 0)
			return even_odd * even_odd;
		else if (n > 0)
			return x * even_odd*even_odd;
		else // x is nonzero, and n is negative
			return 1 / Pow(x, -n);


	}


	void indented_sentences(size_t m, size_t n)
		// precondition: m <=n; 
		//postcondition: print out the above pattern by calling number from m to n
	{

		assert(m <= n);

		static int w = 0;

		if (m < n)
			std::cout << std::string(w++, ' ') << "This was written by calling number " << m << std::endl;
		if (m == n)
		{
			std::cout << std::string(w, ' ') << "This was written by calling number " << m << std::endl;
			std::cout << std::string(w, ' ') << "This was ALSO written by calling number " << m << std::endl;
		}
		if (m != n)
		{
			indented_sentences(m + 1, n);
			std::cout << std::string(--w, ' ') << "This was ALSO written by calling number " << m << std::endl;
		}

	}

}

using namespace main_savitch_6;
int main()
{
	indented_sentences(3, 5);
	indented_sentences(2, 6);
	indented_sentences(1, 7);
	indented_sentences(17, 23);
	return 0;
}