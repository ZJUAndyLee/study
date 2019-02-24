//第三章练习4
#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;

class even_elem{
public:
	bool operator()(const int &x){//注意自己写函数对象的方法！！！
		return x%2==0;
	}
};

int main(){
	istream_iterator<int> input(cin);
	istream_iterator<int> ee;
	vector<int> words;
	copy(input,ee,back_inserter(words));
	vector<int>::iterator tmp=partition(words.begin(),words.end(),even_elem()),tmp1=tmp;//用来将STL分类然后返回分类后第二类的第一个泛型指针
	//for(vector<int>::iterator iter=words.begin();iter!=words.end();iter++) cout<<*iter<<endl;
	ofstream even_txt("even.txt",ios::app);
	ostream_iterator<int> output1(even_txt,"\n");//迭代器用来格式化输入和输出
	copy(words.begin(),tmp,output1);
	for(vector<int>::iterator iter=tmp1;iter!=words.end();iter++) cout<<*iter<<endl;
	ofstream odd_txt("odd.txt",ios::app);
	ostream_iterator<int> output2(odd_txt," ");
	copy(tmp1,words.end(),output2);
	odd_txt.close();

}
