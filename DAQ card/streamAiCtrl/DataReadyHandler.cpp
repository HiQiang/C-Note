#include<iostream>
#include"DataReadyHandler.h"

using namespace std;

void BDAQCALL DataReadyHandler::BfdAiEvent(void* sender, BfdAiEventArgs* args)
{
	//BfdAiEventArgs �ṹ��
	//args->Count �����ݵĸ���
	//args->offect ��������buffer�е�ƫ��
	cout << "Streaming AI data ready: count = " << args->Count << ",\t offset = " << args->Offset << endl;
}
