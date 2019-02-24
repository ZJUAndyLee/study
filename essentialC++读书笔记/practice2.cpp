#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
typedef vector<string> vstring;

void populate_map(ifstream &outfile,map<string,vstring> &famtree){
	outfile.open("familytree.txt",ios::in);
	string strline;
	string familyname;
	vstring child;
	while(getline(outfile,strline)){
		string::size_type pos=0,pre_pos=0,text_size=strline.size();
		while((pos=strline.find_first_of(" ",pos))!=string::npos){//npos 表示在string当中找不到对应的字符或者字符串
			string::size_type end_pos=pre_pos-pos;
			if(!pre_pos)familyname=strline.substr(pre_pos,end_pos);//substr()函数是用来提取从第一个参数pre_pos开始后面“end_pos”个的复制副本作为返回值
			child.push_back(strline.substr(pre_pos,end_pos));
		}
		if(!pre_pos) familyname=strline;
		if(pre_pos<strline.size&&pre_pos){
			famtree[familyname]=child;
		}
	}
}

int main() {
	cout<<"hello world!";
}
