//前两节
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Libmat {
public:
	Libmat() { cout << "Libmat::Libmat() default constractor" << endl; }
	virtual ~Libmat() { cout << "Libmat::~Libmat() default destractor" << endl; }
	virtual void print() const { cout << "Libmat::print -- i am a Libmat object" << endl; 
	//virtual是一个动态编译的语言，他在编译的时候不会直接去寻找 对象的成员函数在哪 在运行时会根据对象去寻找成员函数！！
	//这是对象继承的一个很重要的关键词 它直接决定了你是否可以分辨出来不同继承对象的调用！！
	}
};

class Book : public Libmat { // : + (public,protected,private) + 类名表示新类继承一个已经存在的类 性质由关键词决定
public:
	Book(const string &title, const string &author) :_title(title), _author(author) { cout << "Libmat::Book() constractor" << endl; }
	virtual ~Book() {cout<< "Libmat::~Book() default destractor" << endl;}
	virtual void print() { 
		cout << "Book::print --is a Book object" << endl;
		cout << "the title is: " << _title << endl;
		cout << "the author is :" << _author << endl;
	}
	string title() { return _title; }
	string author() { return _author; }
protected: //表示只可以自己和自己的继承类可以访问的对象！
	string _title;
	string _author;
};

class Dictionary : public Book {
public:
	Dictionary(const string title, const string author, const string editor) :Book(title,author),_editor(editor) { cout << "dictionary constractor" << endl; }
	//子类在进行构造时 如果父类没用默认构造函数的话 一定要 自己调用构造函数 否则 父类的成员变量没用初始化无法被子类继承！！
	virtual ~Dictionary() { cout << "dictionary destractor" << endl; }
	virtual void print(){
		cout << "Dictionary::print --is a Dictionary object" << endl;
		cout << "the title is: " << _title << endl;   //可以直接访问父类的变量 相当于继承给了自己
		cout << "the author is :" << _author << endl;
		cout << "the editor is : " << _editor << endl;
	}
	string editor() { return _editor; }
protected:
	string _editor;
};
