#include "AddLED.h"
#include "ApplicationManager.h"

AddLED::AddLED(ApplicationManager* pApp) :Action(pApp)
{
	abort = 0;
}

AddLED::~AddLED(void)
{
}

void AddLED::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("LED: Click to add the LED");

	pIn->GetPointClicked(Cx, Cy);

	pOut->ClearStatusBar();

	//////////////////
	if (Cy < 185 || Cy > 675) {
		abort = 1;
		pOut->PrintMsg("Action aborted, you can only draw in the drawing area");
	}
	//////////////////
}

void AddLED::Execute()
{
	ReadActionParameters();

	if (abort != 0) {
		return;
	}

	int Len = UI.AND2_Width;	//default
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo;

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	LED* pA = new LED(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddLED::Undo()
{}

void AddLED::Redo()
{}

