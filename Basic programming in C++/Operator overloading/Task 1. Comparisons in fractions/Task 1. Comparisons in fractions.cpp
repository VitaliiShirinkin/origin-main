#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator==(const Fraction& other) const = default;
	bool operator!=(const Fraction& other) { return !(*this == other); };

	auto operator<(Fraction) const;
	auto operator>(Fraction) const;
	auto operator<=(Fraction) const;
	auto operator>=(Fraction) const;
};

    auto Fraction::operator<(Fraction f2) const {
	int bf1 = numerator_/denominator_;
	int bf2 = f2.numerator_ / f2.denominator_;
	return (bf1 < bf2) ? true : false;
}

    auto Fraction::operator>(Fraction f2) const { return f2 < *this; }

	auto Fraction::operator<=(Fraction f2) const { return !(*this > f2); }

	auto Fraction::operator>=(Fraction f2) const { return !(*this < f2); }

int main()
{
	Fraction f1(4, 3);

	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}

