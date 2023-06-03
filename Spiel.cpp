#include "pch.h"
#include "Spiel.h"

Spiel::Spiel()
{
	Zeichen = 254;
	x_pos = 5;
	y_pos = 0;
	neuerstellen = 1;
	blockwurdegedreht = 0;
	blockbewegung = 0;
	drehen = 0;
	punkte = 0;
	geschwindigkeit = 10;
	geschwindigkeitcounter = 0;

	BlockPositionAbspeichern.push_back(0);
	BlockPositionAbspeichern.push_back(15);
	BlockPositionAbspeichern.push_back(1);
	BlockPositionAbspeichern.push_back(15);
	BlockPositionAbspeichern.push_back(2);
	BlockPositionAbspeichern.push_back(15);
	BlockPositionAbspeichern.push_back(3);
	BlockPositionAbspeichern.push_back(15);
	BlockPositionAbspeichern.push_back(4);
	BlockPositionAbspeichern.push_back(15);
	BlockPositionAbspeichern.push_back(5);
	BlockPositionAbspeichern.push_back(15);
	BlockPositionAbspeichern.push_back(6);
	BlockPositionAbspeichern.push_back(15);
	BlockPositionAbspeichern.push_back(7);
	BlockPositionAbspeichern.push_back(15);
	BlockPositionAbspeichern.push_back(8);
	BlockPositionAbspeichern.push_back(15);
	BlockPositionAbspeichern.push_back(9);
	BlockPositionAbspeichern.push_back(15);
}

Spiel::~Spiel()
{
}

void Spiel::blockbewegen()
{
	if (_kbhit()) {
		char Taste = _getch();
		if (Taste == 'a') {
			m_xPositionDesBlocks1--;
			m_xPositionDesBlocks2--;
			m_xPositionDesBlocks3--;
			m_xPositionDesBlocks4--;

			for (int i = 1; i < BlockPositionAbspeichern.size(); i += 2) {
				if ((m_yPositionDesBlocks1 == BlockPositionAbspeichern[i] - 1 && m_xPositionDesBlocks1 == BlockPositionAbspeichern[i - 1])
					|| (m_yPositionDesBlocks2 == BlockPositionAbspeichern[i] - 1 && m_xPositionDesBlocks2 == BlockPositionAbspeichern[i - 1])
					|| (m_yPositionDesBlocks3 == BlockPositionAbspeichern[i] - 1 && m_xPositionDesBlocks3 == BlockPositionAbspeichern[i - 1])
					|| (m_yPositionDesBlocks4 == BlockPositionAbspeichern[i] - 1 && m_xPositionDesBlocks4 == BlockPositionAbspeichern[i - 1])) {
					m_xPositionDesBlocks1++;
					m_xPositionDesBlocks2++;
					m_xPositionDesBlocks3++;
					m_xPositionDesBlocks4++;
				}
			}
		}
		if (Taste == 'd') {
			m_xPositionDesBlocks1++;
			m_xPositionDesBlocks2++;
			m_xPositionDesBlocks3++;
			m_xPositionDesBlocks4++;

			for (int i = 1; i < BlockPositionAbspeichern.size(); i += 2) {
				if ((m_yPositionDesBlocks1 == BlockPositionAbspeichern[i] - 1 && m_xPositionDesBlocks1 == BlockPositionAbspeichern[i - 1])
					|| (m_yPositionDesBlocks2 == BlockPositionAbspeichern[i] - 1 && m_xPositionDesBlocks2 == BlockPositionAbspeichern[i - 1])
					|| (m_yPositionDesBlocks3 == BlockPositionAbspeichern[i] - 1 && m_xPositionDesBlocks3 == BlockPositionAbspeichern[i - 1])
					|| (m_yPositionDesBlocks4 == BlockPositionAbspeichern[i] - 1 && m_xPositionDesBlocks4 == BlockPositionAbspeichern[i - 1])) {
					m_xPositionDesBlocks1--;
					m_xPositionDesBlocks2--;
					m_xPositionDesBlocks3--;
					m_xPositionDesBlocks4--;
				}
			}
		}
		if (Taste == 'w') {
			drehen++; //Form wechseln (Uhrzeigersinn)
			if (drehen == 4) {
				drehen = 0;
			}
			blockwurdegedreht = 1;
		}
		if (Taste == 's') {
			m_yPositionDesBlocks1++;
			m_yPositionDesBlocks2++;
			m_yPositionDesBlocks3++;
			m_yPositionDesBlocks4++;

			for (int l = 1; l < BlockPositionAbspeichern.size(); l += 2) {
				if ((m_yPositionDesBlocks1 == BlockPositionAbspeichern[l] && m_xPositionDesBlocks1 == BlockPositionAbspeichern[l - 1])
					|| (m_yPositionDesBlocks2 == BlockPositionAbspeichern[l] && m_xPositionDesBlocks2 == BlockPositionAbspeichern[l - 1])
					|| (m_yPositionDesBlocks3 == BlockPositionAbspeichern[l] && m_xPositionDesBlocks3 == BlockPositionAbspeichern[l - 1])
					|| (m_yPositionDesBlocks4 == BlockPositionAbspeichern[l] && m_xPositionDesBlocks4 == BlockPositionAbspeichern[l - 1])) {

					m_yPositionDesBlocks1--;
					m_yPositionDesBlocks2--;
					m_yPositionDesBlocks3--;
					m_yPositionDesBlocks4--;
				}
			}
		}
	}

	//nicht nach rechts raus
	if (m_xPositionDesBlocks1 > 9 || m_xPositionDesBlocks2 > 9 || m_xPositionDesBlocks3 > 9 || m_xPositionDesBlocks4 > 9) {
		m_xPositionDesBlocks1--;
		m_xPositionDesBlocks2--;
		m_xPositionDesBlocks3--;
		m_xPositionDesBlocks4--;
	}

	//nicht nach links raus
	if (m_xPositionDesBlocks1 < 0 || m_xPositionDesBlocks2 < 0 || m_xPositionDesBlocks3 < 0 || m_xPositionDesBlocks4 < 0) {
		m_xPositionDesBlocks1++;
		m_xPositionDesBlocks2++;
		m_xPositionDesBlocks3++;
		m_xPositionDesBlocks4++;
	}

	blockbewegung++;
	if (blockbewegung == geschwindigkeit) {
		m_yPositionDesBlocks1++;
		m_yPositionDesBlocks2++;
		m_yPositionDesBlocks3++;
		m_yPositionDesBlocks4++;
		blockbewegung = 0;
	}
}

void Spiel::blockform()
{
	if (neuerstellen == 1) {
		Blockform = rand() % 7;
	}

	if (Blockform == richtigL) {
		if (neuerstellen == 1) {
			m_xPositionDesBlocks1 = x_pos;
			m_xPositionDesBlocks2 = x_pos;
			m_xPositionDesBlocks3 = x_pos;
			m_xPositionDesBlocks4 = x_pos + 1;

			m_yPositionDesBlocks1 = y_pos;
			m_yPositionDesBlocks2 = y_pos + 1;
			m_yPositionDesBlocks3 = y_pos + 2;
			m_yPositionDesBlocks4 = y_pos + 2;
			
			gameover();
		}

		if (drehen == 0 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1 += 1;
			m_xPositionDesBlocks3 -= 1;

			m_yPositionDesBlocks1 -= 1;
			m_yPositionDesBlocks3 += 1;
			m_yPositionDesBlocks4 += 2;
		}
		drehungüberprüfen(-1, 0, 1, 0, 1, 0, -1, -2);

		if (drehen == 1 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1 += 1;
			m_xPositionDesBlocks3 -= 1;
			m_xPositionDesBlocks4 -= 2;

			m_yPositionDesBlocks1 += 1;
			m_yPositionDesBlocks3 -= 1;
		}
		drehungüberprüfen(-1,0,1,2,-1,0,1,0);

		if (drehen == 2 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1 -= 1;
			m_xPositionDesBlocks2;
			m_xPositionDesBlocks3 += 1;
			m_xPositionDesBlocks4;

			m_yPositionDesBlocks1 += 1;
			m_yPositionDesBlocks2;
			m_yPositionDesBlocks3 -= 1;
			m_yPositionDesBlocks4 -= 2;
		}
		drehungüberprüfen(1,0,-1,0,-1,0,1,2);

		if (drehen == 3 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1 -= 1;
			m_xPositionDesBlocks2;
			m_xPositionDesBlocks3 += 1;
			m_xPositionDesBlocks4 += 2;

			m_yPositionDesBlocks1 -= 1;
			m_yPositionDesBlocks2;
			m_yPositionDesBlocks3 += 1;
			m_yPositionDesBlocks4;
		}
		drehungüberprüfen(1,0,-1,-2,1,0,-1,0);

	}

	if (Blockform == falschesL) {
		if (neuerstellen == 1) {
			m_xPositionDesBlocks1 = x_pos+1;
			m_xPositionDesBlocks2 = x_pos+1;
			m_xPositionDesBlocks3 = x_pos+1;
			m_xPositionDesBlocks4 = x_pos;

			m_yPositionDesBlocks1 = y_pos;
			m_yPositionDesBlocks2 = y_pos+1;
			m_yPositionDesBlocks3 = y_pos+2;
			m_yPositionDesBlocks4 = y_pos+2;
			
			gameover();
		}

		if (drehen == 0 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1+=1;
			m_xPositionDesBlocks2;
			m_xPositionDesBlocks3-=1;
			m_xPositionDesBlocks4-=2;

			m_yPositionDesBlocks1-=1;
			m_yPositionDesBlocks2;
			m_yPositionDesBlocks3+=1;
			m_yPositionDesBlocks4;
		}
		drehungüberprüfen(-1,0,1,2,+1,0,-1,0);

		if (drehen == 1 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1+=1;
			m_xPositionDesBlocks2;
			m_xPositionDesBlocks3-=1;
			m_xPositionDesBlocks4;

			m_yPositionDesBlocks1+=1;
			m_yPositionDesBlocks2;
			m_yPositionDesBlocks3-=1;
			m_yPositionDesBlocks4-=2;
		}
		drehungüberprüfen(-1,0,1,0,-1,0,1,2);

		if (drehen == 2 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1-=1;
			m_xPositionDesBlocks2;
			m_xPositionDesBlocks3+=1;
			m_xPositionDesBlocks4+=2;

			m_yPositionDesBlocks1+=1;
			m_yPositionDesBlocks2;
			m_yPositionDesBlocks3-=1;
			m_yPositionDesBlocks4;
		}
		drehungüberprüfen(1,0,-1,-2,-1,0,1,0);

		if (drehen == 3 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1-=1;
			m_xPositionDesBlocks2;
			m_xPositionDesBlocks3+=1;
			m_xPositionDesBlocks4;

			m_yPositionDesBlocks1-=1;
			m_yPositionDesBlocks2;
			m_yPositionDesBlocks3+=1;
			m_yPositionDesBlocks4+=2;
		}
		drehungüberprüfen(1,0,-1,0,1,0,-1,-2);

	}

	if (Blockform == Block) {
		if (drehen == 0 && neuerstellen == 1) {
			m_xPositionDesBlocks1 = x_pos;
			m_xPositionDesBlocks2 = x_pos+1;
			m_xPositionDesBlocks3 = x_pos;
			m_xPositionDesBlocks4 = x_pos+1;

			m_yPositionDesBlocks1 = y_pos;
			m_yPositionDesBlocks2 = y_pos;
			m_yPositionDesBlocks3 = y_pos+1;
			m_yPositionDesBlocks4 = y_pos+1;
			
			gameover();
		}
	}

	if (Blockform == TreppeRechts) {
		if (drehen == 2) {
			drehen = 0;
		}
		if (neuerstellen == 1) {
			m_xPositionDesBlocks1 = x_pos;
			m_xPositionDesBlocks2 = x_pos+1;
			m_xPositionDesBlocks3 = x_pos+1;
			m_xPositionDesBlocks4 = x_pos+2;

			m_yPositionDesBlocks1 = y_pos+1;
			m_yPositionDesBlocks2 = y_pos+1;
			m_yPositionDesBlocks3 = y_pos;
			m_yPositionDesBlocks4 = y_pos;

			gameover();
		}
		if (drehen == 0 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1;
			m_xPositionDesBlocks2+=1;
			m_xPositionDesBlocks3;
			m_xPositionDesBlocks4+=1;

			m_yPositionDesBlocks1+=2;
			m_yPositionDesBlocks2+=1;
			m_yPositionDesBlocks3;
			m_yPositionDesBlocks4-=1;
		}
		drehungüberprüfen(0,-1,0,-1,-2,-1,0,1);

		if (drehen == 1 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1;
			m_xPositionDesBlocks2-=1;
			m_xPositionDesBlocks3;
			m_xPositionDesBlocks4-=1;

			m_yPositionDesBlocks1-=2;
			m_yPositionDesBlocks2-=1;
			m_yPositionDesBlocks3;
			m_yPositionDesBlocks4+=1;
		}
		drehungüberprüfen(0,1,0,1,2,1,0,-1);

	}

	if (Blockform == TreppeLinks) {
		if (drehen == 2) {
			drehen = 0;
		}
		if (neuerstellen == 1) {
			m_xPositionDesBlocks1 = x_pos;
			m_xPositionDesBlocks2 = x_pos+1;
			m_xPositionDesBlocks3 = x_pos+1;
			m_xPositionDesBlocks4 = x_pos+2;

			m_yPositionDesBlocks1 = y_pos;
			m_yPositionDesBlocks2 = y_pos;
			m_yPositionDesBlocks3 = y_pos+1;
			m_yPositionDesBlocks4 = y_pos+1;

			gameover();
		}

		if (drehen == 0 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1-=2;
			m_xPositionDesBlocks2-=1;
			m_xPositionDesBlocks3;
			m_xPositionDesBlocks4+=1;

			m_yPositionDesBlocks1;
			m_yPositionDesBlocks2-=1;
			m_yPositionDesBlocks3;
			m_yPositionDesBlocks4-=1;
		}
		drehungüberprüfen(2,1,0,-1,0,1,0,1);

		if (drehen == 1 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1+=2;
			m_xPositionDesBlocks2+=1;
			m_xPositionDesBlocks3;
			m_xPositionDesBlocks4-=1;

			m_yPositionDesBlocks1;
			m_yPositionDesBlocks2+=1;
			m_yPositionDesBlocks3;
			m_yPositionDesBlocks4+=1;
		}
		drehungüberprüfen(-2,-1,0,1,0,-1,0,-1);

	}

	if (Blockform == Stange) {
		if (drehen == 2) {
			drehen = 0;
		}
		if (neuerstellen == 1) {
			m_xPositionDesBlocks1 = x_pos;
			m_xPositionDesBlocks2 = x_pos;
			m_xPositionDesBlocks3 = x_pos;
			m_xPositionDesBlocks4 = x_pos;

			m_yPositionDesBlocks1 = y_pos;
			m_yPositionDesBlocks2 = y_pos+1;
			m_yPositionDesBlocks3 = y_pos+2;
			m_yPositionDesBlocks4 = y_pos+3;

			gameover();
		}

		if (drehen == 0 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1-=2;
			m_xPositionDesBlocks2-=1;
			m_xPositionDesBlocks3;
			m_xPositionDesBlocks4+=1;

			m_yPositionDesBlocks1-=2;
			m_yPositionDesBlocks2-=1;
			m_yPositionDesBlocks3;
			m_yPositionDesBlocks4+=1;
		}
		drehungüberprüfen(2, 1, 0, -1, 2, 1, 0, -1);

		if (drehen == 1 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1+=2;
			m_xPositionDesBlocks2+=1;
			m_xPositionDesBlocks3;
			m_xPositionDesBlocks4-=1;

			m_yPositionDesBlocks1+=2;
			m_yPositionDesBlocks2+=1;
			m_yPositionDesBlocks3;
			m_yPositionDesBlocks4-=1;
		}
		drehungüberprüfen(-2, -1, 0, 1, -2, -1, 0, 1);
	}

	if (Blockform == Spitze) {
		if (neuerstellen == 1) {
			m_xPositionDesBlocks1 = x_pos;
			m_xPositionDesBlocks2 = x_pos+1;
			m_xPositionDesBlocks3 = x_pos+1;
			m_xPositionDesBlocks4 = x_pos+2;

			m_yPositionDesBlocks1 = y_pos;
			m_yPositionDesBlocks2 = y_pos;
			m_yPositionDesBlocks3 = y_pos+1;
			m_yPositionDesBlocks4 = y_pos;

			gameover();
		}
		if (drehen == 0 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1-=1;
			m_xPositionDesBlocks2;
			m_xPositionDesBlocks3-=1;
			m_xPositionDesBlocks4+=1;

			m_yPositionDesBlocks1-=1;
			m_yPositionDesBlocks2;
			m_yPositionDesBlocks3+=1;
			m_yPositionDesBlocks4+=1;
		}
		drehungüberprüfen(1,0,1,-1,1,0,-1,-1);

		if (drehen == 1 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1+=1;
			m_xPositionDesBlocks2;
			m_xPositionDesBlocks3-=1;
			m_xPositionDesBlocks4-=1;

			m_yPositionDesBlocks1-=1;
			m_yPositionDesBlocks2;
			m_yPositionDesBlocks3-=1;
			m_yPositionDesBlocks4+=1;
		}
		drehungüberprüfen(-1,0,1,1,1,0,1,-1);

		if (drehen == 2 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1+=1;
			m_xPositionDesBlocks2;
			m_xPositionDesBlocks3+=1;
			m_xPositionDesBlocks4-=1;

			m_yPositionDesBlocks1+=1;
			m_yPositionDesBlocks2;
			m_yPositionDesBlocks3-=1;
			m_yPositionDesBlocks4-=1;
		}
		drehungüberprüfen(-1,0,-1,1,-1,0,1,1);

		if (drehen == 3 && blockwurdegedreht == 1) {
			m_xPositionDesBlocks1-=1;
			m_xPositionDesBlocks2;
			m_xPositionDesBlocks3+=1;
			m_xPositionDesBlocks4+=1;

			m_yPositionDesBlocks1+=1;
			m_yPositionDesBlocks2;
			m_yPositionDesBlocks3+=1;
			m_yPositionDesBlocks4-=1;
		}
		drehungüberprüfen(1,0,-1,-1,-1,0,-1,1);

	}

	neuerstellen = 0;
	blockwurdegedreht = 0;
}

void Spiel::display()
{
	for (int h = 0; h < 15; h++) {
		for (int i = 0; i < 10; i++) {
			int zwischenzahl=0;
			if (i == m_xPositionDesBlocks1 && h == m_yPositionDesBlocks1) {
				cout << " " << Zeichen;
				zwischenzahl++;
			}
			if (i == m_xPositionDesBlocks2 && h == m_yPositionDesBlocks2) {
				cout << " " << Zeichen;
				zwischenzahl++;
			}
			if (i == m_xPositionDesBlocks3 && h == m_yPositionDesBlocks3) {
				cout << " " << Zeichen;
				zwischenzahl++;
			}
			if (i == m_xPositionDesBlocks4 && h == m_yPositionDesBlocks4) {
				cout << " " << Zeichen;
				zwischenzahl++;
			}
			for (int j = 0; j < BlockPositionAbspeichern.size(); j += 2) {
				if (i == BlockPositionAbspeichern[j] && h == BlockPositionAbspeichern[j+1]) {
					cout << " " << Zeichen;
					zwischenzahl++;
				}
			}
			if (zwischenzahl<1) {
				cout << " -";
			}
		}
		cout << endl;
	}

	//Block ist unten angekommen.
	int vektorgröße = BlockPositionAbspeichern.size();
	bool raus = 0;
	for (int i = 1; i < vektorgröße; i += 2) {
		if (	(m_yPositionDesBlocks1 == BlockPositionAbspeichern[i]-1 && m_xPositionDesBlocks1 == BlockPositionAbspeichern[i - 1]) 
			||	(m_yPositionDesBlocks2 == BlockPositionAbspeichern[i]-1 && m_xPositionDesBlocks2 == BlockPositionAbspeichern[i - 1]) 
			||	(m_yPositionDesBlocks3 == BlockPositionAbspeichern[i]-1 && m_xPositionDesBlocks3 == BlockPositionAbspeichern[i - 1]) 
			||	(m_yPositionDesBlocks4 == BlockPositionAbspeichern[i]-1 && m_xPositionDesBlocks4 == BlockPositionAbspeichern[i - 1])) {

			if (raus == 0) {
				neuerstellen = 1;
				drehen = 0;

				BlockPositionAbspeichern.push_back(m_xPositionDesBlocks1);
				BlockPositionAbspeichern.push_back(m_yPositionDesBlocks1);
				BlockPositionAbspeichern.push_back(m_xPositionDesBlocks2);
				BlockPositionAbspeichern.push_back(m_yPositionDesBlocks2);
				BlockPositionAbspeichern.push_back(m_xPositionDesBlocks3);
				BlockPositionAbspeichern.push_back(m_yPositionDesBlocks3);
				BlockPositionAbspeichern.push_back(m_xPositionDesBlocks4);
				BlockPositionAbspeichern.push_back(m_yPositionDesBlocks4);
				raus = 1;
			}
		}
	}
}

void Spiel::reihelöschen()
{
	int anzhaleinerreihe = 0;

	for (int j = 14; j >= 0; j--) {
		for (int i = 1; i < BlockPositionAbspeichern.size(); i += 2) {
			if (BlockPositionAbspeichern[i] == j) {
				anzhaleinerreihe++;
				if (anzhaleinerreihe == 10) {
					for (int h = BlockPositionAbspeichern.size() -1; h >= 0; h-=2) {
						if (BlockPositionAbspeichern[h] == j) {
							BlockPositionAbspeichern.erase(BlockPositionAbspeichern.begin() + h);		//Fehlermeldung
							BlockPositionAbspeichern.erase(BlockPositionAbspeichern.begin() + (h - 1));
						}
					}
					anzhaleinerreihe = 0;
					for (int k = 1; k < BlockPositionAbspeichern.size(); k += 2) {
						if (BlockPositionAbspeichern[k] <= j) {
							BlockPositionAbspeichern[k] += 1;
						}
					}
					punkte++;
					geschwindigkeitcounter++;
					if (geschwindigkeitcounter == 4) {
						if (geschwindigkeit > 1) {
							geschwindigkeit--;
						}
						geschwindigkeitcounter = 0;
					}
				}
			}
		}
		anzhaleinerreihe = 0;
	}
}

void Spiel::gameover()
{
	for (int i = 1; i < BlockPositionAbspeichern.size(); i += 2) {
		if (	(m_yPositionDesBlocks1 == BlockPositionAbspeichern[i] && m_xPositionDesBlocks1 == BlockPositionAbspeichern[i - 1])
			||	(m_yPositionDesBlocks2 == BlockPositionAbspeichern[i] && m_xPositionDesBlocks2 == BlockPositionAbspeichern[i - 1])
			||	(m_yPositionDesBlocks3 == BlockPositionAbspeichern[i] && m_xPositionDesBlocks3 == BlockPositionAbspeichern[i - 1])
			||	(m_yPositionDesBlocks4 == BlockPositionAbspeichern[i] && m_xPositionDesBlocks4 == BlockPositionAbspeichern[i - 1])) {
			
			system("cls");
			cout << "GAMEOVER" << endl;
			cout << "Du hast " << punkte << " Reihen geloescht.";
			while(true){
			}
		}
	}
}

void Spiel::drehungüberprüfen(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
	for (int i = 1; i < BlockPositionAbspeichern.size(); i += 2) {
		if ((blockwurdegedreht == 1 &&
			(m_yPositionDesBlocks1 == BlockPositionAbspeichern[i] && m_xPositionDesBlocks1 == BlockPositionAbspeichern[i - 1])
			|| (m_yPositionDesBlocks2 == BlockPositionAbspeichern[i] && m_xPositionDesBlocks2 == BlockPositionAbspeichern[i - 1])
			|| (m_yPositionDesBlocks3 == BlockPositionAbspeichern[i] && m_xPositionDesBlocks3 == BlockPositionAbspeichern[i - 1])
			|| (m_yPositionDesBlocks4 == BlockPositionAbspeichern[i] && m_xPositionDesBlocks4 == BlockPositionAbspeichern[i - 1]))) {

			m_xPositionDesBlocks1 += x1;
			m_xPositionDesBlocks2 += x2;
			m_xPositionDesBlocks3 += x3;
			m_xPositionDesBlocks4 += x4;

			m_yPositionDesBlocks1 += y1;
			m_yPositionDesBlocks2 += y2;
			m_yPositionDesBlocks3 += y3;
			m_yPositionDesBlocks4 += y4;
		}
	}
}
