#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	Is_h = h;
}


void LED::Operate()
{
	if (m_InputPins[0].getStatus() == LOW) {
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}
}


void LED::Draw(Output* pOut)
{
	pOut->DrawLED(m_GfxInfo,Is_h);
}
int LED::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n-1].getStatus();
}

void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}
