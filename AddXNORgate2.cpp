#include "AddXNORgate2.h"
#include "ApplicationManager.h"

AddXNORgate2::AddXNORgate2(ApplicationManager* pApp):Action(pApp)
{
	abort = 0;
}

AddXNORgate2::~AddXNORgate2(void)
{
}

void AddXNORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XNOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

	//////////////////
	if (Cy < 185 || Cy > 675) {
		abort = 1;
		pOut->PrintMsg("Action aborted, you can only draw in the drawing area");
	}
	/////////////////

}

void AddXNORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	if (abort != 0) {
		return;
	}

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	XNOR2* pA = new XNOR2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddXNORgate2::Undo()
{}

void AddXNORgate2::Redo()
{}

