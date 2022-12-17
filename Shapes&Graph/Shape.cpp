#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

int shape::getID()
{
	return ID;
}

void shape::setID(int id)
{
	this->ID = id;
}

void shape::SetDeleted(bool s)
{
	ShpGfxInfo.isDeleted = s;
}

bool shape::IsDeleted() const
{
	return ShpGfxInfo.isDeleted;
}

void shape::SetFilled(bool s)
{
	ShpGfxInfo.isFilled = s;
}

bool shape::IsFilled() const
{
	return ShpGfxInfo.isFilled;
}

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}

