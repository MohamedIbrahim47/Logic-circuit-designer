#include "AddANDgate3.h"
#include "ApplicationManager.h"
AddANDgate3::AddANDgate3(ApplicationManager* pApp) :Action(pApp)
{
	abort = 0;
}

AddANDgate3::~AddANDgate3(void)
{
}

void AddANDgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

	//////////////////
	if (Cy < 185 || Cy > 675) {
		abort = 1;
		pOut->PrintMsg("Action aborted, you can only draw in the drawing area");
	}
	//////////////////


}

void AddANDgate3::Execute()
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
	AND3* pA = new AND3(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddANDgate3::Undo()
{}

void AddANDgate3::Redo()
{}

