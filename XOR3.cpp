#include "XOR3.h"

XOR3::XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut, bool h) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;

	Is_h = h;
}


void XOR3::Operate()
{
	int v1 = 0;
	int v2 = 0;
	int v3 = 0;
	int vfinal = 0;

	if (m_InputPins[0].getStatus() == LOW) {
		v1 = 0;
	}
	else
	{
		v1 = 1;
	}


	if (m_InputPins[1].getStatus() == LOW) {
		v2 = 0;
	}
	else
	{
		v2 = 1;
	}


	if (m_InputPins[2].getStatus() == LOW) {
		v3 = 0;
	}
	else
	{
		v3 = 1;
	}

	vfinal = v1 ^ v2 ^ v3;
	if (vfinal == 1) {
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}

}


void XOR3::Draw(Output* pOut)
{
	pOut->DrawXOR3(m_GfxInfo, Is_h);
}

int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
