#pragma once
#include "TStack.h"


using namespace std;
using namespace System::Drawing;




class TRoot;
class TPoint;
class TChart;


struct TCurrLine {
	TRoot *tC;
	TRoot *pS;
	TRoot *pE;
};


class TRoot {
protected:
	bool visible;
	bool active;
public:
	TRoot(bool _visible = true, bool _active = false) {
		visible = _visible;
		active = _active;
	}

	virtual void Draw(Graphics ^gr, Color col) = 0;
	virtual void Move(Graphics ^gr, int dx, int dy) = 0;
};


class TPoint : public TRoot {
protected:
	int x;
	int y;
public:
	TPoint(int _x = 0, int _y = 0) : TRoot() {
		x = _x;
		y = _y;
	}
	int getX() { return x; }
	int getY() { return y; }
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	virtual void Draw(Graphics ^gr, Color col) {
		SolidBrush^ brush = gcnew SolidBrush(col);
		gr->FillEllipse(brush, x - 2, y - 2, 5, 5);
	}
	virtual void Move(Graphics ^gr, int dx, int dy){
		
			Draw(gr,Color::Black);
			x += dx;
			y += dy;
			Draw(gr, Color::White);
	}
};
 

class TChart :public TRoot {
protected:
	TRoot *pStart;
	TRoot *pEnd;
	TStack<TCurrLine> stack;
public:
	TChart(TRoot *_pStart = nullptr, TRoot *_pEnd = nullptr) {
		pStart = _pStart;
		pEnd = _pEnd;
	}

	void setStart(TRoot *_pStart) {
		TPoint *tp = dynamic_cast<TPoint *>(_pStart);
		TChart *tc = dynamic_cast<TChart *>(_pStart);
		if (tp || tc)
		pStart = _pStart;
	}
	void setEnd(TRoot *_pEnd) {
		TPoint *tp = dynamic_cast<TPoint *>(_pEnd);
		TChart *tc = dynamic_cast<TChart *>(_pEnd);
		if (tp || tc) 
		pEnd = _pEnd;
	}

	TRoot* getBegin() { return pStart; }
	TRoot* getEnd() { return pEnd; }

	TRoot* Draw(Graphics ^gr, TRoot *pCurr, Color col) {
		TPoint *pS, *pE;
		TChart *tC;
		pS = dynamic_cast<TPoint *>(pCurr);
		if (pS != nullptr) {
			pS->Draw(gr, col);
			return pCurr;
		}
		else {
			tC = dynamic_cast<TChart *>(pCurr);
			pS = dynamic_cast<TPoint *>(Draw(gr, tC->pStart, col));
			pE = dynamic_cast<TPoint *>(Draw(gr, tC->pEnd, col));
			Pen^ pen = gcnew Pen(col);
			gr->DrawLine(pen, pS->getX(), pS->getY(), pE->getX(), pE->getY());
			return (TRoot*)tC;
		}
	}
	virtual void Draw(Graphics ^gr, Color col) {
		TRoot *tmp;
		Pen^ pen = gcnew Pen(col);
		TCurrLine curr;
		curr.tC = this;
		curr.pS = curr.pE = nullptr;
		stack.clear();
		stack.push(curr);
		while (!stack.isEmpty()) {
			curr = stack.pop();
			while (curr.pE == nullptr) {
				if (dynamic_cast<TPoint *>(dynamic_cast<TChart *>(curr.tC)->pStart) != nullptr)
					curr.pS = dynamic_cast<TChart *>(curr.tC)->pStart;
				else {
					stack.push(curr);
					curr.tC = dynamic_cast<TChart *>(curr.tC)->pStart;
				}
			}
			if (curr.pE == nullptr) {
				if (dynamic_cast<TPoint *>(dynamic_cast<TChart *>(curr.tC)->pEnd) != nullptr)
					curr.pE = dynamic_cast<TChart *>(curr.tC)->pEnd;
				else {

					stack.push(curr);
					curr.tC = dynamic_cast<TChart *>(curr.tC)->pEnd;
					curr.pS = nullptr;
					stack.push(curr);
				}
			}
			if (curr.pS != nullptr && curr.pE != nullptr) {
				TPoint *p1 = dynamic_cast<TPoint *>(curr.pS), *p2 = dynamic_cast<TPoint *>(curr.pE);
				p1->Draw(gr, col);
				p2->Draw(gr, col);
				gr->DrawLine(pen, p1->getX(), p1->getY(), p2->getX(), p2->getY());

			}

		}
	}


	
	

	virtual void Move(Graphics ^gr, int dx, int dy) {}
};