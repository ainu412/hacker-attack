#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//��������,Ϊ123���¼�ɹ�,��ʾ��¼�˵�,������ʾ��������
int main(){
	string pwd;
	cout<<"Please enter password:";
	while (1){

	cin>>pwd;
		if (pwd=="123"){
			cout<<"login success!"<<endl;
			cout<<"��ѯ���"<<endl;
			cout<<"�һ����"<<endl;
			break;
		}else {
			cout<<"error!Please enter again:";
		}
	}

	system("pause");
	return 0;
}