#include "Linear.hpp"

using namespace std;

int main()
{
	// ex00 test //
	//Matrix<int> m = {{1, 2, 3, 4},
	//                 {5, 6, 7, 8},
	//                 {9, 10, 11, 12}};

	//Vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	//m.print();
	//v.print();

	//cout << m.getShape() << endl;
	//cout << boolalpha << m.isSquare() << endl;
	//cout << v.getSize() << endl;

	//Matrix<int> test = v.reshapeVectorToMatrix(3, 3);
	//Matrix<int> test2 = v.reshapeVectorToMatrix(3, 3, true);
	//Vector<int> test1 = m.reshapeMatrixToVector();

	//test.print();
	//cout << endl;
	//test2.print();
	//cout << endl;
	//test1.print();
	//cout << boolalpha << test.isSquare() << endl;

	//Matrix<int> m2 = {{1, 2, 3, 4},
	//                  {5, 6, 7, 8},
	//                  {9, 10, 11, 12}};

	//Vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	//m.add(m2);
	//m.scl(3);
	//m.print();

	//v.add(v2);
	//v.print();
	//v.scl(2);
	//v.print();

	// ex01 test
	// Vector<int> test({1, 2, 3, 4, 5, 6, 7, 8, 9});
	// Vector<int> test2({1, 2, 3, 4, 5, 6, 7, 8, 9}, false);
	// Vector<int> test3 = test + test2;
	// cout << test3 << endl;
	// Vector<float> e1 = {1.f, 0.f, 0.f};
	// Vector<float> e2 = {0.f, 1.f, 0.f};
	// Vector<float> e3 = {0.f, 0.f, 1.f};

	// Vector<float> v1 = {1.f, 2.f, 3.f};
	// Vector<float> v2 = {0.f, 10.f, -100.f};

	// linear_combination({e1,e2,e3}, {10.f,-2.f,0.5f}).print();
	// cout << endl;

	// linear_combination({v1, v2}, {10.f,-2.f}).print();
	// cout << endl;

	// ex02 test

	// Matrix<int> m = {{1, 2, 3, 4},
	// 				 {5, 6, 7, 8},
	// 				 {9, 10, 11, 12}};
	// Matrix<int> m2 = {{1, 2, 3, 4},
	// 				 {5, 6, 7, 8},
	// 				 {9, 10, 11, 12}};
	// Matrix<int> m3 = m + m2;
	// m3.print();

	// cout << endl;
	// cout << lerp(0.f, 1.f, 0.f) << endl;
	// cout << lerp(0.f, 1.f, 1.f) << endl;
	// cout << lerp(0.f, 1.f, 0.5f) << endl;
	// cout << endl;

	// lerp(Vector<float>({2.f, 1.f}), Vector<float>({4.f, 2.f}), 0.3).print();
	// cout << endl;

	// lerp(Matrix<float>({2.f, 1.f}), Matrix<float>({4.f, 2.f}), 0.3).print();
	// cout << endl;

	// lerp(Matrix<float>({{2.f, 1.f}, {3.f, 4.f}}),
	// 	 Matrix<float>({{20.f, 10.f}, {30.f, 40.f}}), 0.5)
	// 	.print();
	// cout << endl;

	// ex03 test

	Vector<float> v{ 1.f, 1.f };
	Vector<float> u{ 0.f, 0.f };
	Vector<float> er{ 0.f, 0.f, 0.f };

	cout << v.dot(u) << endl;
	cout << v.dot(er) << endl;

	Vector<float> u1{ 1.f, 1.f };

	cout << v.dot(u1) << endl;

	Vector<float> v1{ 3.f, 2.f };
	Vector<float> u2{ -1.f, 6.f };

	cout << v1.dot(u2) << endl;

	return 0;
}