#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
	has = 0;
	is_selected = false;
	is_deleted = false;
}

Component::Component()
{
	has = 0;
	is_selected = false;
	is_deleted = false;
}

Component::~Component()
{}

//added//
GraphicsInfo Component::getGraphicsInfo() {
	return m_GfxInfo;
}


int Component::gethas() {
	return has;
}
void Component::sethas(int b) {
	has = b;
}

//
bool Component::Getis_selected() {
	return is_selected;
}
void Component::Setis_selected(bool s) {
	is_selected = s;
}
//
void Component::Setis_deleted(bool b) {
	is_deleted = b;
}
bool Component::Getis_deleted() {
	return is_deleted;
}
