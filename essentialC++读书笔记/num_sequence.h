#pragma once
#include<iostream>
#include<string>
using namespace std;
class num_sequence {
public:
	virtual ~num_sequence() {};//一般规则凡是基类定义了一个以上的虚函数 那么一般其析构函数也要定义为虚函数
	virtual int elem(int pos) const = 0; //对于虚函数我们要不就要让他有定义，否则就要把它设为纯虚函数 这里的=0说明是一个纯虚函数是专门为了继承而设的
	virtual const char *what_am_i()const = 0;
	static int max_elems() { return _max_elems; };
	virtual ostream &s_print(ostream &os = cout) const = 0;

protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos)const;
	static const int _max_elems = 1024;//static 在类中声明变量表示整个类共用所以必须是const类型的
	int _pos;
};
// 如果一个类声明了一个以上的纯虚函数 那么由于其接口的不完整性 程序无法给 该类进行产生任何对象

bool num_sequence::check_integrity(int pos) const {
	return pos <= 0 || pos > _max_elems ? false : true;
}
//如果在基类的构造或者析构函数中调用了虚函数，并不会去调用对应派生类所覆盖定义的虚函数而是 调用基类本身自己虚函数！！
