#include "Oval.h"

Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	com.x = 0.5 * (Corner1.x + Corner2.x);
	com.y = 0.5 * (Corner1.y + Corner2.y);
}

Oval::~Oval()
{}

void Oval::Save(ofstream& OutFile)
{
	OutFile << "Oval" << "  "
		<< this->ID << "  "
		<< this->Corner1.x << "  "
		<< this->Corner1.y << "  "
		<< this->Corner2.x << "  "
		<< this->Corner2.y << "   "
		<< (int)this->ShpGfxInfo.DrawClr.ucRed << "  "
		<< (int)this->ShpGfxInfo.DrawClr.ucBlue << "  "
		<< (int)this->ShpGfxInfo.DrawClr.ucGreen << "  "
		<< (int)this->ShpGfxInfo.FillClr.ucRed << "  "
		<< (int)this->ShpGfxInfo.FillClr.ucBlue << "  "
		<< (int)this->ShpGfxInfo.FillClr.ucGreen << "  "
		<< (int)this->ShpGfxInfo.BorderWdth << "  " 
		<< this->IsDeleted() << "  " << endl;
}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawOval to draw an oval on the screen	
	pUI->DrawOval(Corner1, Corner2, ShpGfxInfo);
}
bool Oval::isInside(int X,int Y)
{
	double cent_x = (Corner1.x + Corner2.x)/2.0;
	double cent_y = (Corner1.y + Corner2.y)/2.0;
	double axis1 = (Corner1.x - Corner2.x)/2.0;
	double axis2 = (Corner1.y - Corner2.y)/2.0;
	double relation = pow((X - cent_x), 2.0) / pow(axis1, 2.0) + pow((Y - cent_y), 2.0) / pow(axis2, 2.0);
	if (relation <= 1)
	if (relation <=1)
		return true;
	return false;
}

void Oval::Rotate(double theta = 2 * atan(1))
{
	Point gen;
	gen = Corner1;
	Corner1.x = cos(theta) * (gen.x - com.x) - sin(theta) * (gen.y - com.y) + com.x;
	Corner1.y = sin(theta) * (gen.x - com.x) + cos(theta) * (gen.y - com.y) + com.y;
	gen = Corner2;
	Corner2.x = cos(theta) * (gen.x - com.x) - sin(theta) * (gen.y - com.y) + com.x;
	Corner2.y = sin(theta) * (gen.x - com.x) + cos(theta) * (gen.y - com.y) + com.y;
}


void Oval::Move(int dx, int dy)
{
	Corner1.x += dx;
	Corner1.y += dy;
	Corner2.x += dx;
	Corner2.y += dy;
	com.x += dx;
	com.y += dy;
}



void Oval::setCorners(vector <Point> pts)
{
	Corner1 = pts[0];
	Corner2 = pts[1];
}
void Oval::getCorners(vector <Point>& pts)
{
	pts.push_back(Corner1);
	pts.push_back(Corner2);
}