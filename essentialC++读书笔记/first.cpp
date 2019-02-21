#include<iostream>
#include<string>
#include<complex>
#include<fstream>
#include<limits>//可用于查询某个类型的最大/最小值
#include<vector>
#include"surface.h"//我们只能在头文件声明函数和变量不能在头文件中定义
/*<>尖括号表示头文件为标准库或项目专属的库 程序会去专门存储这些库的磁盘进行搜索，而""表示用户自己提供的库会直接去与文件相同的磁盘进行搜索
	头文件中的函数声明 只有inline函数可以在头文件中定义 而变量也只有 const typename可以定义
*/
using namespace std;



const int max_int = numeric_limits<int>::max();
const double min_dbl = numeric_limits<double>::min();//在函数外定义的区域我们称为file scope

void display(complex<double> *c){
	//函数内的区域我们称之为局部作用域也即：local scope
	//每次函数结束，函数内申请的内存也会全部释放！整个内存的存活时间又称为储存期或范围
} 

void read(fstream *ofile=0){
	if (ofile != 0) {
		//调用时若传入参数则进行判断
	}
	//不传参则执行其他语句

}//表示函数使用默认参数 

//默认参数的两条定则：
//1，错误示范：
void f(int *i = 0, int x/*=0*/);//默认参数必须在参数列表的最右边 也就是参数列表出现默认参数之后 后面的所有参数都要是默认参数
//2，默认参数的赋值只能在声明和定义的某一处不能两处都赋值，一般都是在定义处赋值！ 错误示范：
void f(int *i /*= 0*/, int x) {}


const vector<int> *fi_seq(int size) {
	static vector<int> elems;//这是局部静态变量，我们在调用函数时普通的变量均为动态变量 函数结束变量内存被收回，而你申请了静态变量则变量会一直存在
	return &elems;
}

//当某些函数我们反复调用时会增加程序的负担（参数传递赋值，内存申请等等） 而当我们用inline标记函数时就可以向编译器申请把独立的函数整合为一体

inline int g(){}//编译的时候该函数就会直接嵌入主函数当中而不会作为独立的函数再调用

int g(int x);
void g(vector<int> *p, int x);
bool g(const string str, int x, double y);//函数重载 当我们需要用到一些功能相似的函数时，我们可以声明定义 参数列表 不同的函数，从而实现重载

template<typename x> //函数模板当你的函数的主体完全相同只是传入的参数的类型可能不同 你就可以用template定义一个模板函数
void display_message(string msg,vector<x> vec) {}

const vector<int> *fibon_seq(int size) {}
const vector<int> *lucas_seq(int size) {}
const vector<int> *pell_seq(int size) {}
const vector<int> *triang_seq(int size) {}
const vector<int> *square_seq(int size) {}
const vector<int> *pent_seq(int size) {}
bool fibon_elem(int pos, int &elem) {
	const vector<int> *pseq = fibon_seq(pos);
}//这里如果我们需要调用以上不同的函数那么则需要写6个不同的bool函数这样子非常的麻烦

const vector<int>* (*seq_ptr)(int) = 0;//这样我们定义了一个函数指针他能指向任何类型完全相同的函数，函数指针能够赋值为0与其他指针相同
bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int)) {
	seq_ptr = fibon_seq;//对于一个函数f()我们把f单独拿出来就是表示函数 f() 的地址
	const vector<int> *pseq = seq_ptr(pos);//这样我们就不需要写多个相同的函数 而是将函数以指针的形式传入直接进行调用
}

const vector<int> f_s(int x){}
const vector<int>* (seq_s(int))= 0;//所以只有指针函数才有函数指针吗？

const vector<int>* (*s_ptr[])(int) = { fibon_seq,lucas_seq,pell_seq,triang_seq,square_seq ,pent_seq };
//同样地我们也可以将函数指针设计成一个数组然后里面存放函数指针 这样我们就可以轻松索引不同的函数指针

enum ns_type {
	ns_1,ns_2,ns_3,ns_4,ns_5,ns_6
};//enum 用于枚举 默认情形下枚举的变量的值从0开始之后每一项都+1

int main() {
	complex<double> density(0, 8.7);//为模板类允许我们不必指明data member的类型 <data member 类型>
	string user_name("Andy");//构造函数初始化，为了处理一些多值初始化的情况
	cout << "input your name" << '\n';
	cin >> user_name;
	return 0;
	//由于反斜线字符常用于表示转义字符 所以双反斜线即表示反斜线字符:'\\'
	const double pi = 3.14159265; //const 表示恒定变量初始化之后便无法修改
	double tmp;
	cout << tmp << (tmp > pi ? 'Y' : 'N');//?表示条件运算符 如果前面表达式返回'true'就执行?后面，否则执行':'后面的表达式
	++tmp;//前置表达式 先递增再进行后面运算
	tmp++;//后置表达式 先进行其他运算再递增
	int min_size = 4;
	while (cin >> user_name) {
		if (user_name.size() < min_size) continue;//表示输入的字符串长度小于4就会跳过该次循环
	}
	fstream outfile("seq_data.txt",ios_base::app); //定义一个fstream的对象，对象里面可以用文件名进行初始化然后 ios_base表示写入的模式
	if (!outfile) cout << "Oops!" << endl;
	else outfile << pi << " " << tmp << " " << user_name << endl;
	ifstream infile("seq_data.txt");//定义一个ifstream的对象，用来读文件

	fstream iofile("seq_data.txt", ios_base::in | ios_base::app);//这样定义对象iofile既可以读文件又可以写文件
	int &x=min_size;//(&x)对象必须初始化 x代表一个int的对象
	int *p;//指针则定义时不需要初始化，但是指针在使用前一定要判断是不是空指针
	p = new int(1024); //new可以用来动态的分配内存 相当于new从heap中申请了一个int的内存然后把地址赋值给了p
	//加入括号表示能够直接给p所指的对象赋值
	p = new int[min_size];
	delete[]p;//表示将p申请的内存释放，我们如果new申请了内存一定要delete释放否则会内存泄漏
}

