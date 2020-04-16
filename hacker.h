#pragma once

#include <iostream>
#define MAXSIZE 4096

//不指定编码，使用时可能导致乱码
//#pragma execution_character_set("utf-8")  

//id指对应网站的端口号
//服务器返回的结果是utf-8编码格式,而默认是GBK编码

//库文件hacker.lib的头文件
int hk_404(char *id, char *response) ;

//恢复网站
int hk_restore(char *id, char *response);

//网页篡改攻击，para表示填充内容(parameter参数)
int hk_tamper(char *id, char *para, char *response);//网站id,返回值-响应结果

//查看攻击记录
int hk_record(char *id, char *response);

// 检查攻击是否成功
bool check_response(const char *response);

std::string UTF8ToGBK(const char* strUTF8);//编码转换,GBK为C++默认编码
void GBKToUTF8(std::string &strGBK);//客户端是GBK的,将输入字符(C++默认编码)转为库文件的编码