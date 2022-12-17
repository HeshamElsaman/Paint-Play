#include "Polygon.h"
#include <iostream>
using namespace std;

PolyGon::PolyGon(Point* P_, int vertNum, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	VertNum = vertNum;
	Verts = new Point[VertNum];
	if (!Verts) { exit(-1); }
	for (int i = 0; i < vertNum; i++) { Verts[i].x = P_[i].x; Verts[i].y = P_[i].y; }
}

PolyGon::~PolyGon()
{}

void PolyGon::Save(ofstream& OutFile)
{
    OutFile << "Polygon" << "  "
        << this->ID << "  ";
    for (int i = 0; i < VertNum; i++)
    {
        OutFile << this->Verts[i].x << "  " << this->Verts[i].y << "  ";
    }
    OutFile
        << (int)this->ShpGfxInfo.DrawClr.ucRed << "  "
        << (int)this->ShpGfxInfo.DrawClr.ucBlue << "  "
        << (int)this->ShpGfxInfo.DrawClr.ucGreen << "  "
        << (int)this->ShpGfxInfo.FillClr.ucRed << "  "
        << (int)this->ShpGfxInfo.FillClr.ucBlue << "  "
        << (int)this->ShpGfxInfo.FillClr.ucGreen << "  "
        << (int)this->ShpGfxInfo.BorderWdth << "  " 
        << this->IsDeleted() << "  " << endl;
}

void PolyGon::Draw(GUI* pUI) const
{
	//Call Output::DrawPolygon to draw a polygon on the screen	
	pUI->DrawPolygon(Verts, VertNum, ShpGfxInfo);
}
double PolyGon::polyGonArea()
{

    // Initialize area
    double area = 0.0;

    // Calculate value of shoelace formula
    int j = VertNum - 1;
    for (int i = 0; i < VertNum; i++)
    {
        area += (Verts[j].x + Verts[i].x) * (Verts[j].y - Verts[i].y);
        j = i;  // j is previous vertex to i
    }

    return abs(area / 2.0);
}
bool PolyGon::isInside(int X, int Y)
{
    double triarea = 0.0;
    int j = VertNum - 1;
    double dist1, dist2, dist3, S;
    for (int i = 0; i < VertNum; i++)
    {
        dist1 = sqrt(pow(X - Verts[j].x, 2) + pow(Y - Verts[j].y, 2));
        dist2 = sqrt(pow(X - Verts[i].x, 2) + pow(Y - Verts[i].y, 2));
        dist3 = sqrt(pow(Verts[i].x - Verts[j].x, 2) + pow(Verts[i].y - Verts[j].y, 2));
        S = 0.5 * (dist1 + dist2 + dist3);
        triarea += sqrt(S * (S - dist1) * (S - dist2) * (S - dist3));
        j = i;
    }
    if (triarea <= this->polyGonArea())
    {
        cout << this->polyGonArea() << endl << triarea << endl << endl;
        return true;
    }
    return false;
}