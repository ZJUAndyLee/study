//generic programing
//Standard Template Library(STL) 主要有两种构建：即容器(container)和泛型算法(generic algorithm)
#include<vector>
#include<list>
#include<map>
#include<set>
#include<iostream>
#include<string>
#include<algorithm>//使用泛型算法必须 加入头文件<algorithm>
#include<functional>//使用函数对象必须加入头文件
#include<iterator>//使用插入适配器(iterator adapter) 必须加入该头文件
#include<fstream>
using namespace std;

template<typename Iteratortype,typename elemtype>
Iteratortype find_xx(Iteratortype first,Iteratortype last,elemtype elem) {
	for (; first != last; first++) {
		if (*first == elem) return first;
	}
	return first;
}//在这里把Iterator当成一个类型名 写成一个模板 然后后面就可以调用find_xx()函数

bool less_than(int x, int y) {
	return x < y ? 0 : 1;
}

bool bigger_than(int x, int y) {
	return x > y ? 0 : 1;
}

vector<int> filter_ver1(const vector<int> &vec, int filter_value, bool(*pred)(int, int)) {
	vector<int> temp_vec;
	for (vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); iter++) {
		if (pred(*iter, filter_value)) temp_vec.push_back(*iter);
	}
	return temp_vec;
}//用函数指针的方法把大于以及小于的函数都整合进了 一个函数当中

template<typename Inputiterator,typename Outputiterator,typename elemtype,typename comp>
Outputiterator filter_v(Inputiterator first, Inputiterator last, Outputiterator at,elemtype elem,comp pred) {
	while ((first = find_if(first, last, bind2nd(pred,elem))) != last) {//bind2nd()函数可以将二元的函数对象转化为一个一元的对象
		cout << "found value:" << *first << endl;//本来 像less<int>() 等函数是一个代表 二元 函数对象 比如像大于小于等等
		*at++ = *first++;						 //而经过绑定之后就可以表示诸如 >elem <elem 大于某个数小于某个数的 一元 函数对象
											     // bind2nd 函数的参数 函数在前 常数在后！！！					
	}											 //在if，while等需要进行条件判断的地方我们需要注意 条件判断优先级大于赋值 所以先会进行
	return at;									 //条件判断 而条件判断得到的一个bool值会再进行赋值
}									//我们还可以加 not操作 对函数对象的真伪去反

int main() {

	int a1 = 5;
	int *a2;
	const int *x = &a1;//const 在*的左侧说明每个指针所指的值是常数无法改变，而指针是可以改变的
	int * const y = a2;//const 在*的右侧，紧连变量说明指针是无法改变的，而指针所指的值是可以改变的
	int const * const z = &a1;//说明 指针常量都无法改变
	vector<string> svec;

	for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++) cout << iter->size();//可以直接把他当成一个string的指针使用
	//iter 是一个泛型指针 他是比底层指针更抽象一层的对象 这是定义的标准容器的iterator 我们也可以自己定义iterator class
	const vector<int> ivec;
	for (vector<int>::const_iterator iter = ivec.begin(); iter != ivec.end(); iter++) {
		cout << *iter << endl;
		//如果我们定义的是const类型的容器那么我们也要用 const_iterator 来实现迭代操作
	}//我们可以直接把 vector<int>::iterator 看成一种数据类型
	vector<string>::iterator it;
	string a = "why do i love you so";
	it = find_xx(svec.begin(), svec.end(), a);//这样的话我们就可以不拘泥于数据类型，以及数据的容器；我么也可以如下调用函数：
	int arr[10];
	a2 = find_xx(arr, arr + 10, 3);//这里相当于是寻找数组里的某个元素，而上面的调用是寻找vector内的某个元素
	list<double> dlist;
	list<double>::iterator iter;
	iter = find_xx(dlist.begin(), dlist.end(), 3.8);/*在vector和array里面寻找下一个元素就是直接指针运算++，而对于list链表类的数据
	类型的数据结构 不能直接用底层的指针，而是需要更抽象一层的泛型指针，而该函数的调用就可以使iterator作为一个迭代器 而运算符++重载也就可以
	实现我们list也像vector和array一样使用相同的代码即可以实现遍历或者说迭代*/
	vector<string>::iterator it1 = svec.begin();
	vector<string>::iterator it2 = svec.end();
	it = find(it1, it2, a);/*这里find为一个泛型函数 搜索范围由iterator[first,last)标出。如果找到目标，
	find会返回一个iterator指向目标，否则返回last*/
	binary_search(it1, it2, a);//这个函数只能用于对有序集合进行搜索。返回值为 true or false
	count(it1, it2, a);//该函数用来进行计算集合内参数有多少个与目标相同，返回值为相同的个数
	vector<string> svec1 = { "why","do","I","love","you","so" };
	search(it1, it2, svec1);//该函数用来搜索 某个容器内是否存在目标即(svec1)子列 若存在返回子列起始处的iterator 否则返回last(it2)
	it = max_element(it1, it2);//返回容器内的最大值
	vector<string> temp;
	copy(it1, it2, temp.begin());//将容器的值复制一遍存入 temp当中去
	vector<int> ivec1;
	ivec1 = filter_ver1(ivec, 10, less_than);//函数以参数的形式传入

	//function object 是某种class的实例对象，这类class对function call运算符做了重载的操作，这样子f-o就能够当成一般函数调用
	sort(it1, it2, greater<string>());//这样子函数就像参数一样传进去了

	int ia[8] = { 23,11,3,4,9,6,7,8 };
	vector<int> ivec2(ia, ia + 8), ivec3(8);//初始化的区间为：[first,last)
	vector<int>::iterator itr1, itr2;
	int ia2[8];
	filter_v(ia, ia + 8, ia2, 7, less<int>());  //这两个函数即为上面函数模板引用的例子
	filter_v(ivec2.begin(), ivec2.end(), ivec3.begin(), 8, less<int>());
	/*在这里我们必须事先把要被复制的目标容器大小确定好 比如ivec3大小要先确定好 而现实往往不这样更好 于是我们有*/
	filter_v(ivec2.begin(), ivec2.end(), back_inserter(ivec3), 8, less<int>());
	/*插入适配器(insertion adapter) 可以把前面函数里的复制变成一个插入函数的形式 比如back_inserter(ivec3) 就是加入一个push_back()函数
	而这些适配器 但是参数形式变成了什么呢？*/


	map<string, int> word;//map 的基本数据结构是pair map很像python里的dict 
	word["andy"] = 1;

	for (map<string, int>::iterator iter; iter != word.end(); iter++) {
		cout << "key: " << iter->first << " " << "value: " << iter->second << endl;
		//在这里我们可以把map看成一个pair的数组 map本身并没有first或者second的操作 但是他的每个泛型指针都有！！
	}
	//map查询操作
	int count = 0;
	if (!(count = word["andy"])) cout << "andy is not in word";//我们可以通过这个方法寻找 map里面是否有“andy” 其实是在word里创一个
	//key 为“andy”的实例 
	map<string, int>::iterator itt;
	itt = word.find("andy");//而map本身也有一个find函数如果找到了就返回对应pair的泛型指针 没找到返回 word.end()
	word.count("andy");//查找word里面 key value为 “andy” 的个数然后返回这个个数

	set<string> word_exclusion;
	word_exclusion.count["a"];//如果存在 a 直接返回true 否则返回false 与map相似但是 set的 value限定为bool 只有是否存在的可能性
	word_exclusion.insert("a");//插入元素
	word_exclusion.insert(it1, it2);//范围插入元素 参数为泛型指针

	ifstream in_file("input.txt");
	ofstream out_file("output.txt");
	istream_iterator<string> is(in_file);
	istream_iterator<string> eof;
	vector<string> text;
	copy(is, eof, back_inserter(text));
	sort(text.begin(), text.end());
	ostream_iterator<string> os(out_file, "\t");
	copy(text.begin(), text.end(), os);//文件标准化输入输出

	istream_iterator<string> is(cin);
	istream_iterator<string> eof;
	vector<string> text;
	copy(is, eof, back_inserter(text));
	sort(text.begin(), text.end());
	ostream_iterator<string> os(cout, " ");
	copy(text.begin(), text.end(), os);//键入标准化输入输出
}

