#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//输入密码,为123则登录成功,显示登录菜单,否则提示重新输入
int main(){
	string pwd;
	cout<<"Please enter password:";
	while (1){

	cin>>pwd;
		if (pwd=="123"){
			cout<<"login success!"<<endl;
			cout<<"查询余额"<<endl;
			cout<<"兑换外币"<<endl;
			break;
		}else {
			cout<<"error!Please enter again:";
		}
	}

	system("pause");
	return 0;
}