#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>//C����(char)��Ҫ��.h
#include <conio.h>//getch()ͷ�ļ�
#include "hacker.h"

//C++�����ڴ����м䶨��,C�����ڴ��뿪ͷִ�����ǰ����
//���ú������п���,׷�����ܼ����򲻵��ú���
//ʹ��E���Կ����ڿ͹��ܺ���ң�����
//���ÿ�Ľӿ�
//��ͬ�о�Ժ֮����Դ���ᱣ���ʲ�-��ʹ�ÿ��ļ�,�������һ��ֻ���߹���,ֻ���ӿ�
using namespace std;

#define WIDTH	40
#define HEIGHT	15
#define MAXSIZE 4096

//��ʼ���趨���ڴ�С
void init(){
	char cmd[128];
	sprintf_s(cmd,"mode con cols=%d lines=%d",WIDTH,HEIGHT);
	system(cmd);
}

//���д�ӡ����
void printInMiddle(string msg){
	int space=(WIDTH - msg.length())/2;
	for (int i=0;i<space;i++){
		cout<<' ';
	}
	cout<<msg<<endl;
}

void inputPwd(char pwd[], int size){//pwd[]ָ�ַ�����
	//cout<<"����������:";
	char c;
	int i=0;

	while (1){
	c=getch();	//�������(���ն���ʾ),�����س�������'\r'
				//c��char�ͼǵ����ַ�������'\0'<=>0
	if ( c=='\r')break;
	pwd[i++]=c;
	cout<<'*';
	}
}
//��װ����[����],��¼
void login(){
	string name;

	//int pwd;ֻ�����뵥�ַ�
	//string pwd;��������ַ�
	char pwd[32];

	while (1){
		system("cls");//�����Ļ,��ֹ������Ӱ������
		cout<<"�������˺�:";
		cin>>name;//���û������˺�,�����浽name��,ֻ�ܴ�һ���ַ�

		cout<<"����������:";
		//cin>>pwd;
		inputPwd(pwd,sizeof(pwd));

		if (name=="ourr" && strcmp(pwd,"wxhgzy")) {//�ַ����鲻��ֱ��==���Ƚ�,��Ҫ��strcmp( , )�����Ϊ0,string����ֱ����==���Ƚ�
			break;//<=>return
		}else{
			cout<<"�û����������������!"<<endl;//�޵ȴ�����������Ҫ������ͣ
			system("pause");
		}
	}
}

//������ʾ�˵�
void menuShow(){
	system("cls");

	string menu[]={ "1.��վ404����" ,
					"2.��վ�۸Ĺ���",
					"3.��վ������¼",
					"4.��վ�����޸�" ,
					"5.�˳�",
	};

	system("cls");
	printInMiddle("--�ڿ͹���ϵͳ--");

	int max=0;
	int menuCount = sizeof(menu)/sizeof(menu[0]);//1��sizeof�������Ľ��������size_t�������ͱ�֤������ʵ������������������ֽڴ�С�� 

	//���ַ�������е��ַ���
	for (int i=0;i<menuCount;i++){//iΪ����
		if ( menu[i].length()>max){
			max = menu[i].length();
		}
	}

	int leftSpace = (WIDTH - max)/2;
	for (int i=0;i<menuCount;i++){//iΪ����
		for (int i=0;i<leftSpace;i++){//iΪ�ո���
			cout<<' ';
		}
		cout<<menu[i]<<endl;
	}
	system("pause");
}


//��ò˵�ѡ��
int menuChoice(){//��������ָ���Ǻ�������ֵ����
	int n;
	while (1) {
	cin>>n;
	if (cin.fail() || n>5 || n<0 ){
	cin.clear();//������뻺�����ڵ�����
	cin.sync();//������뻺�����ڳ����������������
	cout<<"��Ч����,����������:";
	}else break;
	}

	return n;//����ֵǰ��һ��
}

void attack404(){
	char id[64];//��վ��ID
	char response[MAXSIZE];//������,�ӷ��������صĽ��,��hacker.h��MAXSIZE=4096
	
	system("cls");
	printInMiddle("--��վ404����--");

	cout<<"������׼����������վID:";
	scanf_s("%s",id,sizeof(id));

	//���𹥻�
	cout<<"����ִ��404����...\n";//�ȴ���Ҫ�����û���ʾ,��Ʒ�������
	hk_404(id, response);//��Ϊ�ӿ���Ҫ����char *��(C),����Ҫ����(C)��char

	string retStr = UTF8ToGBK(response);
	cout<<retStr;

	system("pause");
}

//��վ�۸Ĺ���
void siteEdit(){
	char id[64];
	char response[MAXSIZE];
	string attackText;

	system("cls");
	printInMiddle("--��վ�۸Ĺ���--");

	cout<<"������׼����������վID:";
	scanf_s("%s",id,sizeof(id));//idΪchar��(C)��Ҳ��C�е�scanf

	cout<<"��������Ҫд�������:";
	cin>>attackText;
	GBKToUTF8(attackText);//�ѱ��ص�gbkתΪ��������utf-8����

	cout<<"����ִ����վ�۸Ĺ���...\n";//����������ʱ��,�ȴ���Ҫ�����û���ʾ,��Ʒ�������
	//���𹥻�
	hk_tamper(id,(char *)attackText.c_str(),response);//��Ϊc���Ե��ַ��������ǿ������ת��
							
	
	string retStr = UTF8ToGBK(response);
	cout<<retStr;
	system("pause");
}

void attackRecord(){
	char id[64];
	char response[MAXSIZE];

	system("cls");
	printInMiddle("--��վ������¼--");

	cout<<"��������վ��ID:";
	scanf_s("%s",id,sizeof(id));

	//���𹥻�
	cout<<"���ڲ鿴������¼...\n";
	hk_record(id, response);

	string retStr = UTF8ToGBK(response);
	cout<<retStr;

	system("pause");
}

void attackRepair(){
	char id[64];
	char response[MAXSIZE];

	system("cls");
	printInMiddle("--��վ�����޸�--");

	cout<<"������׼���޸�����վ��ID:";
	scanf_s("%s",id,sizeof(id));

	//���𹥻�
	cout<<"����ִ����վ�����޸�...\n";
	hk_restore(id, response);

	string retStr = UTF8ToGBK(response);
	cout<<retStr;

	system("pause");
}

int main(){//ֻ��main����֪���ܹ�
	init();//��ʼ������
	login();//ʵ�ֵ�¼����

	while (1){
		menuShow();
		cout<<"������˵����:";
		int n = menuChoice();//�û�����ı��

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
			return 0;//�˳���Ϊ�������
		}
	}
	system("pause");
	return 0;
}