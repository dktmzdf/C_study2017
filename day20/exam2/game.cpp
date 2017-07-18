#include "stdafx.h"

Pen *g_pBlackPen;



struct S_PlayerGhost
{
	irr::core::vector2df m_pos;
};

S_PlayerGhost g_RemotePlayer;

void OnUpdate(double fDelta) 
{

}



void OnRender(double fDelta,Graphics *pGrp)
{
	pGrp->Clear(Color(200,191,231));

	Matrix originalMat(1,0,0,1,160,120);
	pGrp->SetTransform(&originalMat);
	{
		Matrix tempMat;
		pGrp->GetTransform(&tempMat);
		pGrp->TranslateTransform(g_RemotePlayer.m_pos.X,g_RemotePlayer.m_pos.Y);
		pGrp->DrawEllipse(g_pBlackPen,Rect(-8,-8,16,16));
		pGrp->SetTransform(&tempMat);

	}
	pGrp->ResetTransform();
}

#define BUFLEN 512

struct S_UDPObject
{
	SOCKET m_socket;
	sockaddr_in m_serverAddr, m_si_otherAddr;

	int m_recv_len, m_slen;
	char m_buf[BUFLEN];
	WSADATA m_wsa;
};

S_UDPObject g_udpObject;
DWORD ThreadID;
HANDLE hThread;

DWORD WINAPI ThreadFunc(LPVOID temp)
{
	S_UDPObject *pUDP = (S_UDPObject *)temp;
	OutputDebugStringA("start recv thread\n");

	while (1) {
		memset(pUDP->m_buf,'\0', BUFLEN);
		OutputDebugStringA("waiting for data.....\n");

		if ((pUDP->m_recv_len = recvfrom(pUDP->m_socket,pUDP->m_buf,BUFLEN,0,(sockaddr *)&pUDP->m_si_otherAddr,&pUDP->m_slen)) == SOCKET_ERROR) 
		{
			OutputDebugStringA("recvfrom error\n");
		}
		
		else {
			OutputDebugStringA("recvfrom success\n");
			OutputDebugStringA(pUDP->m_buf);
			OutputDebugStringA("\n");

			cJSON *root = cJSON_Parse(pUDP->m_buf);
			cJSON *xpos = cJSON_GetObjectItemCaseSensitive(root, "xpos");
			cJSON *ypos = cJSON_GetObjectItemCaseSensitive(root, "ypos");

			g_RemotePlayer.m_pos.X = xpos->valueint - 160;
			g_RemotePlayer.m_pos.Y = ypos->valueint - 120;
		}
		
	}
}

int openNetWork(S_UDPObject *pUDP, int nPort)
{
	pUDP->m_slen = sizeof(pUDP->m_si_otherAddr);
	if (WSAStartup(MAKEWORD(2, 2), &pUDP->m_wsa) != 0) {
		OutputDebugStringA("WSAStartup Failed\n");
		return WSAGetLastError();
	}
	OutputDebugStringA("WSAStartup Success\n");

	if ((pUDP->m_socket = socket(AF_INET,SOCK_DGRAM,0)) == INVALID_SOCKET) {
		OutputDebugStringA("socket Failed\n");
		return WSAGetLastError();
	}
	OutputDebugStringA("socket Success\n");

	pUDP->m_serverAddr.sin_family = AF_INET;
	pUDP->m_serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	pUDP->m_serverAddr.sin_port = htons(nPort);

	if (bind(pUDP->m_socket, (sockaddr *)&pUDP->m_serverAddr, sizeof(pUDP->m_serverAddr)) == SOCKET_ERROR) {
		OutputDebugStringA("bind Failed\n");
		return WSAGetLastError();
	}
	OutputDebugStringA("bind Success\n");

	hThread = CreateThread(NULL, 0, ThreadFunc, &g_udpObject, 0, &ThreadID);
	return 0;
}

void closeNetWork(S_UDPObject *pUDP) 
{
	
	closesocket(pUDP->m_socket);
	WSACleanup();
}

void InitGame() 
{
	g_pBlackPen = new Pen(Color(0,0,0));
	plusEngine::fpOnLoop = OnUpdate;
	plusEngine::fpOnRender = OnRender;

	openNetWork(&g_udpObject,3333);
}

void finishGame()
{
	delete g_pBlackPen;
	closeNetWork(&g_udpObject);
}

