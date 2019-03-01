#include"Libmat.h"
#include<vector>
#include<typeinfo>//该头文件可以动态的进行类型鉴定 非常有用
class Fibonacci : public num_sequence {
public:
	Fibonacci(int length = 1, int pos = 1) :_length(length), _beg_pos(pos) {};
	virtual int elem(int pos)const;
	virtual const char *what_am_i()const;
	virtual ostream &s_print(ostream &os = cout) const;
protected:
	int _length, _beg_pos;
	virtual void gen_elems(int pos)const ;
	static vector<int> element;
};

vector<int> Fibonacci::element;//***重中之重 static的成员变量在类中申明了之后 仍需在类外定义一遍否则会不对的！！！

int Fibonacci::elem(int pos)const { //在类之外对虚函数进行定义时，不必指明关键字virtual
	if (!check_integrity(pos)) return 0;
	if (pos > element.size()) Fibonacci::gen_elems(pos);//在该函数中我们清楚的知道我们需要用哪一个gen_elems所以我们直接标记出来跳过虚拟机的部分
	return element[pos-1];
}

void Fibonacci::gen_elems(int pos)const {
	if (element.empty()) {
		element.push_back(1);
		element.push_back(1);
	}
	if (element.size() < pos) {
		for (int ix = element.size(); ix < pos; ix++) element.push_back(element[ix - 1] + element[ix - 2]);
	}
}

ostream &Fibonacci::s_print(ostream &os) const{
	int st_pos = _beg_pos - 1;
	int end_pos = st_pos + _length;
	if (end_pos > element.size()) Fibonacci::gen_elems(end_pos);
	for (int ix = st_pos; ix < end_pos; ix++) os << element[ix] << " ";
	return os;
}

const char * Fibonacci::what_am_i() const {//基类中定义的虚函数 如果子类要完全承接的话一定要保证与基类的函数"完全相同!"
	return typeid(*this).name();//函数前加const表示该函数的返回值是const的不能改变 而函数主体前加const表示函数内部不会的类的成员进行任何更改！
	// typeid的函数作用于一个类的实例 会返回一个多态的type_info的对象 而name()函数则会返回一个 const char* 作为类的名字
}

ostream &operator<<(ostream &os, const num_sequence &elem) {
	return(elem.s_print(os));
}
int main() {
	Fibonacci fib;
	cout << "t1:" << fib << endl;
	Fibonacci fib2(16);
	cout << "t2: " << fib2 << endl;
	Fibonacci fib3;
	fib3 = fib2;
	cout << "t3: " << fib3 << " "<<fib3.what_am_i()<<endl;
	int xx;
	cout << typeid(xx).name();//可以返回任意类的名字 非常好用
	num_sequence *pr= &fib3;
	Fibonacci *pf;
	if (typeid(*pr) == typeid(fib)) {//typeid 可以作用一个对象返回它的属性或者说类！！！
		cout << "yes!!" << endl;
		pf = static_cast<Fibonacci *>(pr);//static_cast 无条件的将后面的参数转换为 另一个类下的参数
		pf = dynamic_cast<Fibonacci *>(pr); //dynamic_cast 他会判断 能否转换再进行转换而不是无条件的！！
	}
	else cout << "No" << endl;
	cin >> xx;

}
