#include<iostream>
#include<memory>
#include<exception>//这是一个异常操作的基类 我们可以自己写一个类继承他 这样子我们catch的时候只需要catch基类 
#include<string>
#include<sstream>//ostringstream 的使用必须用这个库额
//然后根据不同的类下的what函数进行不同错误的抛出
using namespace std;

class overflow {
public:
	overflow(int index, int max) :_index(index), _max(max) {}//异常输出我们可以写一个专门的类应对不同的异常
	void what_happen(ostream &os=cerr) {
		cerr << "the index: " << _index << " is bigger than the max: " << _max << endl;
	}
private:
	int _index, _max;
};

bool testf(int index, int max) {
	bool state = true;
	overflow err(index, max);
	try {
		if (index > max) throw err;
		else if (index < 0) throw index;
	}
	catch (int index) { //catch语句必须跟着 try语句体 当try语句体有异常被throw的话 就能以catch(typename elem)的形式被捕获然后会直接执行catch语句体
		//并且跳过其他try中的其他语句 以及其他catch语句直接到后面的语句部分！！
		cerr << "the index can't be a minus one!" << endl;
	}
	catch (overflow &iof) {
		iof.what_happen();
		state = false;
	}
	catch (...) {}//这种表示一网打尽 也就是捕捉所有的抛出异常。
	return state;
}

int main() {
	int a = 1024;
	testf(a, 1000);
	testf(-1, 1000);
	int m;
	cin >> m;
	auto_ptr<int> p(new int[m]);
	//可以用类的形式来申请变量空间 这样就能确保在想要进行内存释放的时候直接调用其析构函数就能完成任务
	double *xx;
	try {
		xx = new (nothrow) double[100000000];//如果在申请内存的时候发现内存不够就会抛出 bad_alloc的错误而 bad_alloc是一个class而不是一个对象
	}
	catch (bad_alloc) {//这里我们只关注抛出的错误的类 不关心它具体的对象
		cout << "can't allocate memory for the ptr-xx" << endl;
	}
	
	ostringstream my_os;//他可以将输出格式化的转换为string然后储存到类对象 my_os当中！！
	
	my_os << "why do i love you so";
	string msg = my_os.str();
	cout  << " " << msg << endl;
	istringstream my_is(msg); //当他以这种方式初始化时 会把字符串根据“ ”将分开并储存 然后再下面这个表达当中就可以把字符串一个个传入
	string tmp;
	while (my_is >> tmp) cout << tmp << " "<<endl;// 同样他可以将类中的成员变量string 传入">>"所接的变量！！
	//cout << msg << endl;
	cin >> a;
	
}
