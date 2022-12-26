#pragma once

#include "shape.h"

class RegPolygon : public shape
{
private:
	int VertNum;
	Point* Verts = nullptr;
	Point com;
public:
	RegPolygon(Point*, int, GfxInfo shapeGfxInfo);
	virtual ~RegPolygon();
	virtual void Save(ofstream& OutFile);
	virtual void Draw(GUI* pUI) const;
	bool isInside(int X, int Y) ;
	double polygonArea();
	void Rotate() override;
};

