#include<iostream>
#include"CacheOverflowHandler.h"
using namespace std;

void BDAQCALL CacheOverflowHandler::BfdAiEvent(void* sender, BfdAiEventArgs* args)
{
	cout << "Streaming AI Cache Overflow: offset = " << args->Offset << ", count = " << args->Count << endl;
}
