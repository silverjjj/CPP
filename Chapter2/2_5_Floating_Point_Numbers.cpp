#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main()
{
	using namespace std;

	float f(3.141592f);	// f를 붙이지 않으면 double -> float
	double d(3.141592);
	long double ld(3.141592);

	cout << sizeof(f) << endl;
	cout << sizeof(d) << endl;
	cout << sizeof(ld) << endl;

	cout << numeric_limits<float>::max() << endl;
	cout << numeric_limits<double>::max() << endl;
	cout << numeric_limits<long double>::max() << endl;

	// min() : 표현할 수 있는 가장 작은 숫자의 절대값
	cout << numeric_limits<float>::min() << endl;
	cout << numeric_limits<double>::min() << endl;
	cout << numeric_limits<long double>::min() << endl;

	cout << numeric_limits<float>::lowest() << endl;
	cout << numeric_limits<double>::lowest() << endl;
	cout << numeric_limits<long double>::lowest() << endl;

	// 3.14 = 31.4 * 0.1
	// 3.14 * 100 == 3.14e2
	// e-1 = 1/10
	cout << 3.14 << endl;
	cout << 31.4e-1 << endl;
	cout << 31.4e-2 << endl;
	cout << 31.4e1 << endl;
	cout << 31.4e2 << endl;

	cout << 1 / 3 << endl;
	cout << 1.0 / 3.0 << endl;	// 0.333333
	cout << std::setprecision(16);	// 소수점 16자리 출력
	cout << 1.0 / 3.0 << endl;	// 0.333333... (16자리까지)


	float f2(123456789.0f);	// 10 significant digits

	cout << std::setprecision(9);
	cout << f2 << endl;	// 123456792 => 오차


	double d2(0.1);

	cout << d2 << endl;
	cout << std::setprecision(17);
	cout << d2 << endl;	// 0.100000...001

	// 중요,, : 컴퓨터는 약간의 오차가 존재함
	double d3(1.0);
	double d4(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
	cout << d3 << endl;	// 1
	cout << d4 << endl;	// 0.9999...99989, 오차가 누적된다

	// inf, -inf
	double zero = 0.0;
	double posinf = 5.0 / zero;
	double neginf = -5.0 / zero;
	double nan = zero / zero;		// nan : not a number

	// isnan : 정상적인 숫자인지 아닌지를 판단 
	// isinf : infinite 인지 아닌지 판단
	cout << posinf << " " << std::isnan(posinf) << " " << std::isinf(posinf) << endl;
	cout << neginf << " " << std::isnan(neginf) << " " << std::isinf(neginf) << endl;
	cout << nan << " " << std::isnan(nan) << " " << std::isinf(nan) << endl;
	cout << 0.3 << " " << std::isnan(0.3) << " " << std::isinf(0.3) << endl;

	/*
	3.141592
	31.41
	0.001000
	123.0002
	0.0000000001
	234560000.000
	*/
	cout << 3.141592e0 << endl;
	cout << 3.141e1 << endl;
	cout << 1.0e-3 << endl;
	cout << 1.2300002e+2 << endl;
	cout << 1.0e-10 << endl;
	cout << 2.3456e+8 << endl;

	return 0;
}