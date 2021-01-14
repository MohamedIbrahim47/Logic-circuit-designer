#pragma once
#include "Components/Component.h"
#include "Components/InputPin.h"
#include "Components/OutputPin.h"

class Connection_w : public Component
{
public:
	Connection_w(const GraphicsInfo& r_GfxInfo);

	virtual void Operate();
	virtual void Draw(Output* pOut);	


	void setSourcePin(OutputPin* pSrcPin);
	void setDestPin(InputPin* pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin();


	virtual int GetOutPinStatus();	
	virtual int GetInputPinStatus(int n);	

	virtual void setInputPinStatus(int n, STATUS s);


};
