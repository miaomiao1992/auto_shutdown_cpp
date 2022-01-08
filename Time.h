
#ifndef _TIME_H__
#define _TIME_H__

#include <string>
#include <regex>
#include <iostream>
#include <stdlib.h>
#include <time.h>

namespace Time {

	using std::string;
	using std::regex_match;
	using std::regex;
	using std::cmatch;
	
	struct def_time {
		int t_hour;
		int t_min;
	};
	def_time getNowTime() {
		std::time_t nowTime=std::time(NULL);
		tm* t_time=std::localtime(&nowTime);
		def_time the_time;
		the_time.t_hour=t_time->tm_hour;
		the_time.t_min=t_time->tm_min;
		return the_time;
		
	}
	int parseHMSToSecond(const string &str) {
		static regex regHMS("([0-9]*)[Hh]?([0-9]*)[Mm]?([0-9]*)[Ss]?");
		cmatch m;
		auto ret=std::regex_match(str.c_str(), m,regHMS);
		if(ret) {
			int second=0;
			if(m[1].str()!=std::string("")) {
				second +=atoi(m[1].str().c_str())*3600;
			}
			if(m[2].str()!=std::string("")) {
				second +=atoi(m[2].str().c_str())*60;
			}
			if(m[3].str()!=std::string("")) {
				second +=atoi(m[3].str().c_str());
			}
			return second;

		} else {
			throw "多久以后关机 ?H?M?S（小时/分/秒）格式错误，未捕获命令！";
		}

	}

	int parseTimeToSecond(const string &str) {
		static regex regTime("([12]?[0-9]):([0-6][0-9])");
		cmatch m;
		auto ret=std::regex_match(str.c_str(), m,regTime);
		if(ret) {
			def_time the_time=	getNowTime();
			int second=0;
			second+=((atoi(m[1].str().c_str())-the_time.t_hour+24)%24)*3600;
			second+=((atoi(m[2].str().c_str())-the_time.t_min))*60;
			return second;
		} else {
			throw "关机时间 ?:?（点/分）格式错误，未捕获命令！";
		}

	}

	/**
	*根据某个时间获取距离目前之间的秒数
	*/
	int getSecondFromString(const string &str) {
		static regex regHMS("[0-9]+[HMShms]+");
		static regex regTime("[0-9]+[:]+");

		if(str==std::string("")) {
			return 0;
		} else if(std::regex_search(str,regHMS)) {
			return parseHMSToSecond(str);
		} else if(std::regex_search(str,regTime)) {
			return parseTimeToSecond(str);
		} else {
			throw "格式错误，未捕获命令！";
		}
	}


}

#endif


