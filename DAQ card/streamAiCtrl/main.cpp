#include<iostream>
#include"bdaqctrl.h"
#include"compatibility.h"
#include<fstream>
#include<stdio.h>
#include<stdlib.h>

#include"DataReadyHandler.h"
#include"CacheOverflowHandler.h"
#include"OverrunHandler.h"
#include"StoppedHandler.h"

using namespace std;
using namespace Automation::BDaq;

//#define deviceDescription L"DemoDevice,BID#0"

#define deviceDescription L"USB-4711A,BID#1"

int32 startChannel = 0;
const int32 channelCount = 4;
const int32 intervalCount = 1024;
const int32 sampleCount = 4096;

#define USER_BUFFER_SIZE channelCount*intervalCount
double userDataBuffer[USER_BUFFER_SIZE];

//以下四个类可以拆开写到不同文件中


int main()
{
	ErrorCode ret = Success;//Errorcode 是一个 自定义的枚举类型
	cout << "ret:0X" << hex << ret << endl;//十六进制 输出ErrorCode 
	cout.unsetf(ios::hex);
	BufferedAiCtrl* bfdAiCtrl = AdxBufferedAiCtrlCreate();//BufferedAiCtrl 是一个 类

	DataReadyHandler onDataReady;
	bfdAiCtrl->addDataReadyListener(onDataReady);//BufferedAiCtrl的成员函数 参数按引用方式传递 返回值为空

	OverrunHandler OnOverRun;
	bfdAiCtrl->addOverrunListener(OnOverRun);//如果没有添加处理Overrun的handler采集卡在真正Overrun的时候没有默认的处理方法，将会忽略overrun

	CacheOverflowHandler onCacheOverflow;
	bfdAiCtrl->addCacheOverflowListener(onCacheOverflow);

	StoppedHandler onStopped;
	bfdAiCtrl->addStoppedListener(onStopped);

	do
	{
		DeviceInformation devInfo(deviceDescription);//DeviceInformation 是一个 struct
		ret = bfdAiCtrl->setSelectedDevice(devInfo);//类成员函数 返回值是一个ErrorCode类型的枚举
		cout << "ret:0X" <<hex<< ret << endl;//十六进制 输出ErrorCode 
		cout.unsetf(ios::hex);
		CHK_RESULT(ret);

		ScanChannel* scanChannel = bfdAiCtrl->getScanChannel();//类成员函数 返回ScanChannel类型的指针
		ret = scanChannel->setChannelStart(startChannel);//类成员函数 设置开始通道 返回ErrorCode类型的枚举
		CHK_RESULT(ret);
		ret = scanChannel->setChannelCount(channelCount);
		CHK_RESULT(ret);
		ret = scanChannel->setIntervalCount(intervalCount);
		CHK_RESULT(ret);
		ret = scanChannel->setSamples(sampleCount);//类成员函数 设置每个通道的 sampleCount
		CHK_RESULT(ret);

		ret = bfdAiCtrl->setStreaming(true);//类成员函数 设置打开Stream采集 否则第一次装满 buffer 后 便会停止采集
		CHK_RESULT(ret);

		ret = bfdAiCtrl->Prepare();//样例程序中带有的 可能和设备初始化有关 
		CHK_RESULT(ret);
		ret=bfdAiCtrl->Start();
		CHK_RESULT(ret);
		cout << "The BufferedAiCtrl started" << endl;

		do {
			SLEEP(24);
		} while (false);
		bfdAiCtrl->Stop();
		bfdAiCtrl->Dispose(); //类成员函数 清除实例 释放内存

		cout << "The BufferedAiCtrl ended" << endl;

	} while (false);

	return 0;
}

