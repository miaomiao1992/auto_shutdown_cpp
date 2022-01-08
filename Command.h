#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <iostream>
#include <cstdlib>
#include "Reg.h"
#include "Time.h"



namespace Command {
	
using std::cin;
using std::cout;
using std::endl;
using std::string;


	void show() {
		cout<<"-----------------��ӭʹ�ùػ�С����-----------------------------------"<<endl
		    <<"�����������£�"<<endl
		    <<"1��-s         ->  shutdown        ���̹ػ�"<<endl
		    <<"2��-s ?h?m?s  ->  shutdown ?h?m?s ���ʱ�䣨Сʱ/��/�룩��ִ�йػ�"<<endl
		    <<"3��-s ?:?     ->  shutdown ?:?    ����/����ĳ��ʱ�䣨��/�֣�ִ�йػ�"<<endl
		    <<"4��-c         ->  cancel          ȡ���ػ�"<<endl
		    <<"---------------------------------------------------------------------"<<endl;
	}

	void shutdownBySecond(const int &second) {
		if(second<0) {
			throw "�ػ������������0";
		}
		string str="shutdown -s -t "+std::to_string(second);
		cout<<"��ִ�йػ����"<<str<<endl;
		std::system(str.c_str());
	}

	void cancel() {
		cout<<"��ִ��ȡ���ػ����shutdown -a"<<endl;
		std::system("shutdown -a");
	}

	//todo �����ɲ���ģʽ
	void execute(const string &str,const string &parameter) {
		if(str==string("s")||str==string("shutdowm")) {
			cout<<"�ƻ�ִ�У��ػ�"<<endl;
			int i=	Time::getSecondFromString(parameter);
			// ������ʱ��Ͷ���Ժ�ػ�ͳһ�� �������Ժ�ػ�
			shutdownBySecond(i);
		} else if(str==string("c")||str==string("cancel")) {
			cout<<"����ִ�У�ȡ���ػ�"<<endl;
			cancel();
		} else {
			throw "������Ч�������������룡";
		}
	}

	void run() {
		//char  c[50];
		//std::cin.getline(c,50) ;
		string command;
		std::getline(cin,command); 
		string theCommannd=Reg::getCommand(command);
		string theParameter=Reg::getParameter(command);
		execute(theCommannd,theParameter);

	}


}

#endif
