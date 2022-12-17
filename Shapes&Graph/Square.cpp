#include "Square.h"

Square::Square(Point P1, Point P2,/*Point P3,*/ GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	//Corner3 = P3;
}

Square::~Square()
{}

void Square::Save(ofstream& OutFile) // the file name is Outfile
{
	OutFile << "SQR" << "  "
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

void Square::Draw(GUI* pUI) const
{
	//Call Output::Drawcircle to draw a line on the screen	
	pUI->DrawSquare(Corner1, Corner2, /*Corner3,*/ ShpGfxInfo);

}
bool Square::isInside(int X, int Y)
{
	int Xmin = (Corner1.x <= Corner2.x) ? Corner1.x : Corner2.x;
	int Ymin = (Corner1.y <= Corner2.y) ? Corner1.y : Corner2.y;
	int Xmax = (Corner1.x > Corner2.x) ? Corner1.x : Corner2.x;
	int Ymax = (Corner1.y > Corner2.y) ? Corner1.y : Corner2.y;
	if (X >= Xmin && X <= Xmax && Y <= Ymax && Y >= Ymin)
	{
		return true;
	}
	return false;
}