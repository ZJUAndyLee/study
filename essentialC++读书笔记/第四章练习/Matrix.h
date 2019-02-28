#pragma once
#include<iostream>
using namespace std;
class Matrix
{
	//friend ostream& operator<<(ostream &os, Matrix &elem);
public:
	Matrix();
	Matrix(float ptr[16]);
	~Matrix();
	Matrix(Matrix &elem);
	const Matrix &operator+(const Matrix &elem); //是否用const的标准 可以看返回值是否可变 也就是是否在等号的右边 在右边说明不可变可以用const
	void operator+=(const Matrix &);           //成员函数必定有调用对象的 且对象为类的对象 所以如果对象函数的调用对象不为类的对象 那就说明函数是非成员函数
	const Matrix &operator*(const Matrix &elem);
	float &operator()(const int row, const int col);
	friend ostream& operator<<(ostream& os, Matrix& elem);
	friend istream & operator>>(istream& is, Matrix& elem);
private:
	float *array;
};

istream &operator>>(istream& is, Matrix& elem) {
	for (int i = 0; i < 16; i++) is >> elem.array[i];
	return is;
}

ostream &operator<<(ostream &os, Matrix &elem) {
	for (int i = 0; i < 16; i++) os << "(" << i % 4 + 1 << i / 4 + 1 << ")" << ": " << elem.array[i] << endl;
	return os;
}


Matrix::Matrix() {
	array = new float[16];
}

Matrix::~Matrix() {
	//cout << "delete all" << endl;
	//delete[]array;
}

Matrix::Matrix(Matrix &elem) {
	array = new float[16];
	for (int i = 0; i < 16; i++) array[i] = elem.array[i];
}

Matrix::Matrix(float ptr[16]) {
	array = new float[16];
	for (int i = 0; i < 16; i++) array[i] = ptr[i];
}

const Matrix &Matrix::operator+(const Matrix &elem) {//::一般用来表示成员函数 成员函数一定要用scope操作符申明！！！！
	Matrix Tmp_mat;
	for (int i = 0; i < 16; i++) { Tmp_mat.array[i] = array[i] + elem.array[i]; }
	return Tmp_mat;
}

void Matrix::operator+=(const Matrix &elem) {
	for (int i = 0; i < 16; i++) this->array[i] += elem.array[i];
}

const Matrix &Matrix::operator*(const Matrix &elem) {
	Matrix Tmp_mat;
	float tmp = 0;
	for (int i = 0; i < 4; i++) { 
		for (int j = 0; j < 4; j++) {
			tmp = 0;
			for (int k = 0; k < 4; k++) {
				tmp += this->array[i * 4 + k] * elem.array[j * 4 + k];
			}
			Tmp_mat.array[i * 4 + j] = tmp;
		}
	}
	return Tmp_mat;
}

float &Matrix::operator()(const int row,const int col){
	return array[4 * (row - 1) + col];
}

/*1、由于 + -都是出现在 = 号的右边，如c = a + b，即会返回一个右值，可以返回const型值
2、后几个表达式讨论的就是，数和对象混合运算符的情况，一般出现这种情况，常使用友元函数
3、双目运算符的重载：
重载运算符函数名：operator@(参数表)
隐式调用形式：obj1 + obj2
显式调用形式：obj1.operator+(OBJ obj2)-- - 成员函数
operator+(OBJ obj1，OBJ obj2) 这样的话该重载函数就不是一个成员函数-- - 友元函数
执行时，隐式调用形式和显式调用形式都会调用函数operator + ()*/
