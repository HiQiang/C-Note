#pragma once

#include"bdaqctrl.h"
#include"compatibility.h"

using namespace Automation::BDaq;

class DataReadyHandler :public BfdAiEventListener
{public:
	virtual void BDAQCALL BfdAiEvent(void* sender, BfdAiEventArgs* args);
};