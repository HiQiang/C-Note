#include<iostream>
#include"DataReadyHandler.h"

using namespace std;

void BDAQCALL DataReadyHandler::BfdAiEvent(void* sender, BfdAiEventArgs* args)
{
	//BfdAiEventArgs 结构体
	//args->Count 新数据的个数
	//args->offect 新数据在buffer中的偏移
	cout << "Streaming AI data ready: count = " << args->Count << ",\t offset = " << args->Offset << endl;
}
