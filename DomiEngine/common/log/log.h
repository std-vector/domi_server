/******************************************************************** 
创建时间:        2015/06/28 14:36
文件名称:        log.h
文件作者:        Domi
功能说明:        log日志  
其他说明:        采用文件流写入日志
*********************************************************************/

#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "common/basic/basicTypes.h"
#include "common/basic/timeFunction.h"
#include "common/log/fileStream.h"
#include "common/thread/csLocker.h"
#include "common/log/consoleColor.h"

class CLog
{
private:
	enum _e_LogType
	{
		LT_Log,		// log
		LT_Warn,	// 警告
		LT_Error,	// 错误
		LT_Max
	};

private:
	static bool				m_bInitiate;			// 是否已经初始化
	static SYSTEMTIME		m_gSysTime[LT_Max];		// 创建时间
	static char				m_szDirectory[256];		// 路径
	static char				m_szBuffer[2048];		// 缓存
	static CMutex			m_csLock;				// 互斥锁
	static CFileStream		m_clgFile[LT_Max];		// 目标文件 
    static char             m_logFilePrev[ 256 ];	// log文件前缀

private:
	static void	createAFile	(uint8 ucType);
	static void	getDate		(char* pDate,const uint32& uSize);
	static void	setDirectory(const char* pDir);
	static void	_print		(const char* pFormat,va_list&argptr);

public:
	static bool	initialize(const char* root = nullptr, const char* prev = nullptr);		// 初始化
	static void	shutdown();	// 关闭

	static void	print(const char* pFormat,...);
	static void info(const char* pFormat, ...);
	static void	warn(const char* pFormat,...);
	static void	error(const char* pFormat,...);
	static void	lastError(const char* pFormat,...);
};
