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
		cout<<"-----------------欢迎使用关机小助手-----------------------------------"<<endl
		    <<"基本命令如下："<<endl
		    <<"1、-s         ->  shutdown        立刻关机"<<endl
		    <<"2、-s ?h?m?s  ->  shutdown ?h?m?s 多久时间（小时/分/秒）后执行关机"<<endl
		    <<"3、-s ?:?     ->  shutdown ?:?    今天/明天某个时间（点/分）执行关机"<<endl
		    <<"4、-c         ->  cancel          取消关机"<<endl
		    <<"---------------------------------------------------------------------"<<endl;
	}

	void shutdownBySecond(const int &second) {
		if(second<0) {
			throw "关机秒数必须大于0";
		}
		string str="shutdown -s -t "+std::to_string(second);
		cout<<"已执行关机命令："<<str<<endl;
		std::system(str.c_str());
	}

	void cancel() {
		cout<<"已执行取消关机命令：shutdown -a"<<endl;
		std::system("shutdown -a");
	}

	//todo 建议搞成策略模式
	void execute(const string &str,const string &parameter) {
		if(str==string("s")||str==string("shutdowm")) {
			cout<<"计划执行：关机"<<endl;
			int i=	Time::getSecondFromString(parameter);
			// 按具体时间和多久以后关机统一成 按几秒以后关机
			shutdownBySecond(i);
		} else if(str==string("c")||str==string("cancel")) {
			cout<<"立即执行：取消关机"<<endl;
			cancel();
		} else {
			throw "命令无效，请重新再输入！";
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
