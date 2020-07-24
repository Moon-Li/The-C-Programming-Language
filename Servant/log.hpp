#ifndef _LOG_HPP_
#define _LOG_HPP_

#include<iostream>
#include<string>
#include<sys/time.h>


#define Normal 1
#define Warning 2
#define fatal 3

uint64_t GetTime()
{
	struct timeval time;
	if(gettimeofday(&time, nullptr) == 0)
	{
		return time.tv_sec;
	}
	return 0;
}


//[时间] [错误级别] [错误信息] [文件名] [行号] 
void Log(std::string lev, std::string err_msg, std::string file_name, int line)
{
	std::cerr << "[ " << GetTime() << " ][ " << lev << " ][ " << err_msg << " ][ " << file_name<< " ][ " << line << " ]" << std::endl;
}


#define LOG(level, message) Log(#level, message, __FILE__, __LINE__)

#endif
