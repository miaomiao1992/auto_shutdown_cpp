#ifndef _REG_H_
#define _REG_H_

#include <regex>
#include <string>

namespace Reg {
	using std::string;
	using std::regex;
	using std::cmatch;
	using std::regex_match;
	string getCommand(const string &str) {
		static regex regCommand("^[\\s]*-([a-z]+)[\\s]*[0-9:hmsHMS]*[\\s]*");
		cmatch m;
		auto ret=std::regex_match(str.c_str(), m,regCommand);
		if(ret) {
			return string(m[1].str());
		} else {
			throw "¸ñÊ½´íÎó£¬Î´²¶»ñÃüÁî£¡";
		}
	}

	string  getParameter(const string &str) {
		static regex regCommand("^[\\s]*-[a-z]+[\\s]+([0-9:hmsHMS]*)[\\s]*");
		cmatch m;
		auto ret=regex_match(str.c_str(), m,regCommand);
		if(ret) {
			return string(m[1].str());
		} else {
			return string("");
		}
	}


}

#endif



