#pragma once
#include "TStack.h"
#include <math.h>

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
struct TFind {
	TRoot *pS;
	TRoot *pE;
	int Start;
	int End;
};


class TRoot {
protected:

	bool active;
public:
	bool visible;
	int whatIsIt;
	TRoot(bool _visible = true, bool _active = false) {
		visible = _visible;
		active = _active;
		whatIsIt = 0;
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
		whatIsIt = 1;
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
		whatIsIt = 2;
	}
	void setAcive(bool tmp) {
		active = tmp;
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
			while (curr.pS == nullptr) {
				if (dynamic_cast<TChart *>(curr.tC)->pStart->whatIsIt==1)
					curr.pS = dynamic_cast<TChart *>(curr.tC)->pStart;
				else {
					stack.push(curr);
					curr.tC = dynamic_cast<TChart *>(curr.tC)->pStart;
				}
			}
			if (curr.pE == nullptr) {
				if (dynamic_cast<TChart *>(curr.tC)->pEnd->whatIsIt == 1)
					curr.pE = dynamic_cast<TChart *>(curr.tC)->pEnd;
				else {

					stack.push(curr);
					curr.tC = dynamic_cast<TChart *>(curr.tC)->pEnd;
					curr.pS = nullptr;
					stack.push(curr);
				}
			}
			if (curr.pS!=nullptr && curr.pE != nullptr && curr.tC->visible )
				if (curr.pS->whatIsIt == 1 && curr.pE->whatIsIt == 1){
					TPoint *p1 = dynamic_cast<TPoint *>(curr.pS), *p2 = dynamic_cast<TPoint *>(curr.pE);
					p1->Draw(gr, col);
					p2->Draw(gr, col);
					gr->DrawLine(pen, p1->getX(), p1->getY(), p2->getX(), p2->getY());


					if (!stack.isEmpty()) {
						curr = stack.pop();
						if (curr.pS == nullptr) curr.pS = (TRoot*)p2;
						else curr.pE= (TRoot*)p2;
						stack.push(curr);
					}
				}

		}
	}
	

	TFind Find(int x1,int x2,int y1,int y2) {
		bool flag1 = false, flag2 = false;
		TRoot *tmp;
		int Epsilon = 10;
		TCurrLine curr;
		TFind find;
		find.pE = find.pS = nullptr;
		curr.tC = this;
		curr.pS = curr.pE = nullptr;
		stack.clear();
		stack.push(curr);
		while (!stack.isEmpty() && !(flag1 && flag2) ) {
			curr = stack.pop();
			while (curr.pS == nullptr) {
				if (dynamic_cast<TChart *>(curr.tC)->pStart->whatIsIt == 1)
					curr.pS = dynamic_cast<TChart *>(curr.tC)->pStart;
				else {
					stack.push(curr);
					curr.tC = dynamic_cast<TChart *>(curr.tC)->pStart;
				}
			}
			if (curr.pE == nullptr) {
				if (dynamic_cast<TChart *>(curr.tC)->pEnd->whatIsIt == 1)
					curr.pE = dynamic_cast<TChart *>(curr.tC)->pEnd;
				else {

					stack.push(curr);
					curr.tC = dynamic_cast<TChart *>(curr.tC)->pEnd;
					curr.pS = nullptr;
					stack.push(curr);
				}
			}
			if (curr.pS != nullptr && curr.pE != nullptr)
			if (curr.pS->whatIsIt == 1 && curr.pE->whatIsIt == 1) {
				TPoint *p1 = dynamic_cast<TPoint *>(curr.pS), *p2 = dynamic_cast<TPoint *>(curr.pE);
				if (abs(p1->getX() - x1) < Epsilon && abs(p1->getY() - y1 ) < Epsilon && !flag1) {
					find.pS = curr.tC; 
					find.Start = 1;
					flag1 = true;
				}
				if (abs(p2->getX() - x1)<Epsilon && abs(p2->getY() - y1 )<Epsilon && !flag1) {
					find.pS = curr.tC;
					find.Start = 2;
					flag1 = true;
				}
				if (abs(p1->getX() - x2)<Epsilon && abs(p1->getY() - y2 )<Epsilon && !flag2) {
					find.pE = curr.tC;
					find.End = 1;
					flag2 = true;
				}
				if (abs(p2->getX() - x2)<Epsilon && abs(p2->getY() - y2 )<Epsilon && !flag2) {
					find.pE = curr.tC;
					find.End = 2;
					flag2 = true;
				}
				if (!stack.isEmpty()) {
					curr = stack.pop();
					if (curr.pS == nullptr) curr.pS = (TRoot*)p2;
					else curr.pE = (TRoot*)p1;
					stack.push(curr);
				}
			}

		}
		return find;
	
	}
	
	

	virtual void Move(Graphics ^gr, int dx, int dy) {}
};