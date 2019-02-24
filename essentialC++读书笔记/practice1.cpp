//============================================================================
// Name        : tt.cpp
// Author      : Libing
// Version     : 
// Copyright   : Your copyright notice
// Description : 第三章习题练习
//============================================================================

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include<map>
#include<fstream>
#include<set>
#include<vector>
#include<functional>
using namespace std;

bool compare_str(string str1,string str2){
	return str1.length()>str2.length() ? true : false;
}

class Lessthan{
public:
	bool operator()(const string &str1,const string &str2){//operator function object 是一个类的对象 Lessthan就是一个类的对象
		return str1.length()<str2.length();				//operator 就可以让类的对象以Lessthan()这种方式直接调用
	}
};

int main() {
	map<string,int> words;
	fstream input;
	input.open("outfile.txt",ios::in|ios::app);
	string str;
	set<string> exclude_word;
	string str1[6]={"a","an","or","the","and","but"};
	for(int i=0;i<6;i++) exclude_word.insert(str1[i]);
	while(input>>str){
		if(!exclude_word.count(str)) words[str]++;
	}
	char ch;

	while(1){
		cout<<"do you want to check the words?"<<endl;
		cin>>ch;
		if(ch=='N'||ch=='n') break;
		cin>>str;
		cout<<"the words "<<str<<"'s times is:"<<words[str]<<endl;
	}
	vector<string> s_vec;
	for(map<string,int>::iterator iter=words.begin();iter!=words.end();iter++){
		cout<<"the key word is: "<<iter->first<<"  the times is: "<<iter->second<<endl;
		s_vec.push_back(iter->first);
	}
	sort(s_vec.begin(),s_vec.end(),less<string>());
	stable_sort(s_vec.begin(),s_vec.end(),Lessthan());
	for(vector<string>::iterator iter=s_vec.begin();iter!=s_vec.end();iter++) cout<<*iter<<endl;



}
