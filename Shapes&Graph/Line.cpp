#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Line::~Line()
{}

void Line::Save(ofstream& OutFile)
{

	OutFile << "Line" << "  "
		<< this->ID << "  "
		<< this->Corner1.x << "  "
		<< this->Corner1.y << "  "
		<< this->Corner2.x << "  "
		<< this->Corner2.y << "   "
		<< (int)this->ShpGfxInfo.DrawClr.ucRed << "  "
		<< (int)this->ShpGfxInfo.DrawClr.ucBlue << "  "
		<< (int)this->ShpGfxInfo.DrawClr.ucGreen << "  "
		<< "No fill color" << "  "
		<< (int)this->ShpGfxInfo.BorderWdth << "  "
		<<this->IsDeleted() << "  " << endl;
}


void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pUI->DrawLine(Corner1, Corner2, ShpGfxInfo);
}
bool Line::isInside(int X, int Y)
{
	double m = double((Corner2.y - Corner1.y)) / (Corner2.x - Corner1.x);
	double b = Corner2.y - m * Corner2.x;
	int Xmin = (Corner1.x <= Corner2.x) ? Corner1.x : Corner2.x;
	int Ymin= (Corner1.y <= Corner2.y) ? Corner1.y : Corner2.y;
	int Xmax=(Corner1.x > Corner2.x) ? Corner1.x : Corner2.x;
	int Ymax= (Corner1.y > Corner2.y) ? Corner1.y : Corner2.y;
	if (X >= Xmin && X <= Xmax && Y<=Ymax && Y>=Ymin)
	{
		if (Y <= m * X + b + (ShpGfxInfo.BorderWdth)+10 && Y >= m * X + b - (ShpGfxInfo.BorderWdth)-10)
			return true;
		return false;
	}
	return false;
}


void Line::Rotate() 
{
	Point cent, gen;
	cent.x = 0.5 * (Corner1.x + Corner2.x);
	cent.y = 0.5 * (Corner1.y + Corner2.y);
	gen = Corner1;
	Corner1.x = cos(2 * atan(1)) * (gen.x - cent.x) - sin(2 * atan(1)) * (gen.y - cent.y) + cent.x;
	Corner1.y = sin(2 * atan(1)) * (gen.x - cent.x) + cos(2 * atan(1)) * (gen.y - cent.y) + cent.y;
	gen = Corner2;
	Corner2.x = cos(2 * atan(1)) * (gen.x - cent.x) - sin(2 * atan(1)) * (gen.y - cent.y) + cent.x;
	Corner2.y = sin(2 * atan(1)) * (gen.x - cent.x) + cos(2 * atan(1)) * (gen.y - cent.y) + cent.y;
}