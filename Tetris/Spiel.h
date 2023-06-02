#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

class Spiel
{
public:
	Spiel();
	~Spiel();
	void blockbewegen();
	void blockform();
	void display();
	void reihelöschen();
private:
	int geschwindigkeitcounter;
	int geschwindigkeit;
	int punkte;
	int drehen;
	int blockbewegung;
	int x_pos;
	int y_pos;
	int Blockform;
	int m_xPositionDesBlocks1, m_xPositionDesBlocks2, m_xPositionDesBlocks3, m_xPositionDesBlocks4;
	int m_yPositionDesBlocks1, m_yPositionDesBlocks2, m_yPositionDesBlocks3, m_yPositionDesBlocks4;

	bool blockwurdegedreht;
	bool neuerstellen;

	vector<int> BlockPositionAbspeichern;

	enum Form { richtigL, falschesL, Block, TreppeRechts, TreppeLinks, Stange, Spitze };
	
	char Zeichen;
	
	void drehungüberprüfen(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4);
	void gameover();
};

