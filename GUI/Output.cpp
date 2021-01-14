#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor =WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//added//////Clears the toolbar
void Output::cleartoolbar() const
{
	pWind->SetPen(RED,1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,0,UI.width,UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	
	////added
	
	MenuItemImages[ITM_addgate] = "images\\Menu\\menu_add.jpg";
	MenuItemImages[ITM_simulationmode] = "images\\Menu\\Menu_SIM.jpg";
	MenuItemImages[ITM_save] = "images\\Menu\\menu_save.jpg";
	MenuItemImages[ITM_load] = "images\\Menu\\menu_load.jpg";
	MenuItemImages[ITM_copy] = "images\\Menu\\menu_copy.jpg";
	MenuItemImages[ITM_cut] = "images\\Menu\\menu_cut.jpg";
	MenuItemImages[ITM_paste] = "images\\Menu\\menu_paste.jpg";
	MenuItemImages[ITM_delete] = "images\\Menu\\menu_delete.jpg";
	MenuItemImages[ITM_mdelete] = "images\\Menu\\menu_mdelete.jpg";
	MenuItemImages[ITM_move] = "images\\Menu\\move.jpg";

	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	




	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void Output::creategatebar()const
{
	UI.AppMode = DESIGN;

	string gateItemImages[ITM_DSNgates_CNT];
	gateItemImages[ITM_AND2] = "images\\Menu\\2and.jpg";
	gateItemImages[ITM_OR2] = "images\\Menu\\2or.jpg";
	gateItemImages[ITM_BUFFER] = "images\\Menu\\buffer.jpg";
	gateItemImages[ITM_NAND2] = "images\\Menu\\2nand.jpg";
	gateItemImages[ITM_NOR2] = "images\\Menu\\2nor.jpg";
	gateItemImages[ITM_NOT] = "images\\Menu\\inverter.jpg";
	gateItemImages[ITM_NOR3] = "images\\Menu\\3nor.jpg";
	gateItemImages[ITM_AND3] = "images\\Menu\\3and.jpg";
	gateItemImages[ITM_XNOR2] = "images\\Menu\\2xnor.jpg";
	gateItemImages[ITM_XOR2] = "images\\Menu\\2xor.jpg";
	gateItemImages[ITM_XOR3] = "images\\Menu\\3xor.jpg";
	gateItemImages[ITM_oSWITCH] = "images\\Menu\\oswitch.jpg";
	gateItemImages[ITM_LED] = "images\\Menu\\Led.jpg";
	gateItemImages[ITM_CONNECTION] = "images\\Menu\\line.jpg";
	gateItemImages[ITM_Back] = "images\\Menu\\menu_back.jpg";

	for (int i = 0; i < ITM_DSNgates_CNT; i++)
	{
		pWind->DrawImage(gateItemImages[i], i * UI.ToolItemWidth, UI.ToolBarHeight, UI.ToolItemWidth, UI.ToolBarHeight);
		//Draw a line under the toolbar
		pWind->SetPen(RED, 3);
		pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\h_2and.jpg";
	else  
		GateImage = "Images\\Gates\\2and.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
////2nand gate
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_2nand.jpg";
	else
		GateImage = "Images\\Gates\\2nand.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}

////2or gate
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_2or.jpg";
	else
		GateImage = "Images\\Gates\\2or.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}


////2nor gate
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_2nor.jpg";
	else
		GateImage = "Images\\Gates\\2nor.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}


////2xor gate
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_2xor.jpg";
	else
		GateImage = "Images\\Gates\\2xor.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}

////2xnor gate
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_2xnor.jpg";
	else
		GateImage = "Images\\Gates\\2xnor.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}

////NOT gate
void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_inverter.jpg";
	else
		GateImage = "Images\\Gates\\inverter.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}

////BUFFER gate
void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_buffer.jpg";
	else
		GateImage = "Images\\Gates\\buffer.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}

////AND3
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_3and.jpg";
	else
		GateImage = "Images\\Gates\\3and.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}


////NOR3
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_3nor.jpg";
	else
		GateImage = "Images\\Gates\\3nor.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}

////XOR3
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_3xor.jpg";
	else
		GateImage = "Images\\Gates\\3xor.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}

////SWitch
void Output::DrawoSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_oswitch.jpg";
	else
		GateImage = "Images\\Gates\\oswitch.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}

////LED
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\h_Led.jpg";
	else
		GateImage = "Images\\Gates\\Led.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	//// using same AND2 Image Parameter in UI_Info
}

//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection

	if (selected)
		pWind->SetPen(RED, 1); //highlighted
	else
		pWind->SetPen(BLACK, 1);    //! highlited

	//pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);		//for broken lines


	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
}

//
void Output::DrawWhite(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "Images\\Gates\\white.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//
void Output::DrawConnection_w(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(WHITE,1);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y2);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
}


Output::~Output()
{
	delete pWind;
}

