/******************************************************************** 
创建时间:        2015/07/10 15:50
文件名称:        domiServer.h
文件作者:        Domi
功能说明:        游戏服务器  
其他说明:         
*********************************************************************/

#include "common/singleton/singleton.h"
#include "common/serverroot/serverRoot.h"
#include "network/tcp_connect.h"
#include "logic/logicnet/local_network.h"
#include "logic/logicnet/word_session.h"


class CDomiServer : public Singleton<CDomiServer>
				  , public CServerRoot
{
public:
	CDomiServer();
	~CDomiServer();

public:
	void ShowServerInfo();

	bool initialize(uint16 uServerID);	// 初始化server
	bool startServices();				// 启动server	
	void timerProcess();				// timer工作线程，逻辑在这里处理
	bool canExitServices();				// 能否退出,这里做数据落地操作
	void stopServices();				// 关闭server
	void denyServices();				// 拒绝server

public:
	CLocalNetwork m_netServer;			// 处理clien连接的tcpserver
	CTcpConnect m_connect;				// 主动连接其他内部服务器
	CWordSession m_wordSess;			// word server session
};
