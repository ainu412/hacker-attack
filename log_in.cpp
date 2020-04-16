#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>//C语言(char)需要加.h
#include <conio.h>//getch()头文件
#include "hacker.h"

//C++可以在代码中间定义,C必须在代码开头执行语句前定义
//调用函数会有开销,追求性能极致则不调用函数
//使用E语言开发黑客功能和外挂，外售
//调用库的接口
//不同研究院之间资源争夺保密资产-故使用库文件,像黑箱子一样只告诉功能,只给接口
using namespace std;

#define WIDTH	40
#define HEIGHT	15
#define MAXSIZE 4096

//初始化设定窗口大小
void init(){
	char cmd[128];
	sprintf_s(cmd,"mode con cols=%d lines=%d",WIDTH,HEIGHT);
	system(cmd);
}

//居中打印标题
void printInMiddle(string msg){
	int space=(WIDTH - msg.length())/2;
	for (int i=0;i<space;i++){
		cout<<' ';
	}
	cout<<msg<<endl;
}

void inputPwd(char pwd[], int size){//pwd[]指字符数组
	//cout<<"请输入密码:";
	char c;
	int i=0;

	while (1){
	c=getch();	//不会回显(在终端显示),读到回车符返回'\r'
				//c中char型记得在字符结束后补'\0'<=>0
	if ( c=='\r')break;
	pwd[i++]=c;
	cout<<'*';
	}
}
//封装函数[功能],登录
void login(){
	string name;

	//int pwd;只可输入单字符
	//string pwd;可输入多字符
	char pwd[32];

	while (1){
		system("cls");//清除屏幕,防止缓存区影响输入
		cout<<"请输入账号:";
		cin>>name;//让用户输入账号,并保存到name中,只能存一个字符

		cout<<"请输入密码:";
		//cin>>pwd;
		inputPwd(pwd,sizeof(pwd));

		if (name=="ourr" && strcmp(pwd,"wxhgzy")) {//字符数组不能直接==作比较,需要用strcmp( , )相等则为0,string可以直接与==作比较
			break;//<=>return
		}else{
			cout<<"用户名或密码输入错误!"<<endl;//无等待输入的输出需要附带暂停
			system("pause");
		}
	}
}

//居中显示菜单
void menuShow(){
	system("cls");

	string menu[]={ "1.网站404攻击" ,
					"2.网站篡改攻击",
					"3.网站攻击记录",
					"4.网站攻击修复" ,
					"5.退出",
	};

	system("cls");
	printInMiddle("--黑客攻击系统--");

	int max=0;
	int menuCount = sizeof(menu)/sizeof(menu[0]);//1）sizeof操作符的结果类型是size_t，该类型保证能容纳实现所建立的最大对象的字节大小。 

	//求字符数最大行的字符数
	for (int i=0;i<menuCount;i++){//i为行数
		if ( menu[i].length()>max){
			max = menu[i].length();
		}
	}

	int leftSpace = (WIDTH - max)/2;
	for (int i=0;i<menuCount;i++){//i为行数
		for (int i=0;i<leftSpace;i++){//i为空格数
			cout<<' ';
		}
		cout<<menu[i]<<endl;
	}
	system("pause");
}


//获得菜单选择
int menuChoice(){//函数类型指的是函数返回值类型
	int n;
	while (1) {
	cin>>n;
	if (cin.fail() || n>5 || n<0 ){
	cin.clear();//清除输入缓冲区内的数字
	cin.sync();//清除输入缓冲区内除数字外的其他内容
	cout<<"无效输入,请重新输入:";
	}else break;
	}

	return n;//返回值前空一行
}

void attack404(){
	char id[64];//网站的ID
	char response[MAXSIZE];//攻击后,从服务器返回的结果,因hacker.h中MAXSIZE=4096
	
	system("cls");
	printInMiddle("--网站404攻击--");

	cout<<"请输入准备攻击的网站ID:";
	scanf_s("%s",id,sizeof(id));

	//发起攻击
	cout<<"正在执行404攻击...\n";//等待中要给与用户提示,产品体验更好
	hk_404(id, response);//因为接口需要输入char *型(C),故需要定义(C)的char

	string retStr = UTF8ToGBK(response);
	cout<<retStr;

	system("pause");
}

//网站篡改攻击
void siteEdit(){
	char id[64];
	char response[MAXSIZE];
	string attackText;

	system("cls");
	printInMiddle("--网站篡改攻击--");

	cout<<"请输入准备攻击的网站ID:";
	scanf_s("%s",id,sizeof(id));//id为char型(C)故也是C中的scanf

	cout<<"请输入你要写入的内容:";
	cin>>attackText;
	GBKToUTF8(attackText);//把本地的gbk转为服务器的utf-8编码

	cout<<"正在执行网站篡改攻击...\n";//攻击需消耗时间,等待中要给与用户提示,产品体验更好
	//发起攻击
	hk_tamper(id,(char *)attackText.c_str(),response);//改为c语言的字符数组后再强制类型转换
							
	
	string retStr = UTF8ToGBK(response);
	cout<<retStr;
	system("pause");
}

void attackRecord(){
	char id[64];
	char response[MAXSIZE];

	system("cls");
	printInMiddle("--网站攻击记录--");

	cout<<"请输入网站的ID:";
	scanf_s("%s",id,sizeof(id));

	//发起攻击
	cout<<"正在查看攻击记录...\n";
	hk_record(id, response);

	string retStr = UTF8ToGBK(response);
	cout<<retStr;

	system("pause");
}

void attackRepair(){
	char id[64];
	char response[MAXSIZE];

	system("cls");
	printInMiddle("--网站攻击修复--");

	cout<<"请输入准备修复的网站的ID:";
	scanf_s("%s",id,sizeof(id));

	//发起攻击
	cout<<"正在执行网站攻击修复...\n";
	hk_restore(id, response);

	string retStr = UTF8ToGBK(response);
	cout<<retStr;

	system("pause");
}

int main(){//只看main函数知道架构
	init();//初始化界面
	login();//实现登录功能

	while (1){
		menuShow();
		cout<<"请输入菜单编号:";
		int n = menuChoice();//用户输入的编号

		switch (n){
		case 1:
			attack404();
			break;
		case 2:
			siteEdit();
			break;
		case 3:
			attackRecord();
			break;
		case 4:
			attackRepair();
			break;
		case 5:
			return 0;//退出即为程序结束
		}
	}
	system("pause");
	return 0;
}