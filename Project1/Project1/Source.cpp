#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

void tower(int a[11][3], int b[11][1], int d, int n)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = 0;
		}
		b[i][0] = 0;
	}

	for (int i = 0; i <= d; i++)
	{
		a[n - i][0] = d - i;
		b[n - i][0] = d - i;
	}
}

int main()
{
	setlocale(0, "");

	int a[11][3];
	int b[11][1];
	int n = 10;
	int d = 0;	// количество колец
	int stolbec = 0, hod = 0;
	bool take = false; //для определения взято ли кольцо
	bool GameOver = false;
	bool win = false;
	int p = 0; // для определения победы
	int z = 20;	// множитель
	int y1 = 100; // координата для курсора
	bool menu = true;
	bool bhelp = false;
	bool AfterWin = false;
	bool blevel = false;
	int mx, my; // координаты мыши
	bool TurnOnTimer = true;
	bool lastlevel = false;

				// массивы с координатами
	int x[3] = { 80,315,530 };
	int y[11];
	for (int i = 0; i < 11; i++)
	{
		y[11 - i] = 438 - i * z; // координаты колец на стрежнях	
	}
	y[0] = y1 + 65;  // координата взятого кольца

	sf::RenderWindow window(sf::VideoMode(640, 480), "Hanoi towers", sf::Style::Close);

	sf::Clock clock;

	// меню 
	sf::Texture tmenu;
	tmenu.loadFromFile("menu.png");
	sf::Sprite smenu;
	smenu.setTexture(tmenu);

	// выбор уровня
	sf::Texture tlevel;
	tlevel.loadFromFile("level.png");	// 230x370
	sf::Sprite slevel;
	slevel.setTexture(tlevel);

	// помощь
	sf::Texture thelp;
	thelp.loadFromFile("help.png");		// 300x300
	sf::Sprite shelp;
	shelp.setTexture(thelp);

	// карта
	sf::Texture tmap;
	tmap.loadFromFile("map.png");
	sf::Sprite smap;
	smap.setTexture(tmap);

	// курсор
	sf::Texture tkursor;
	tkursor.loadFromFile("kursor 30x40.png");
	sf::Sprite skursor;
	skursor.setTexture(tkursor);
	skursor.setPosition(x[stolbec], y1);

	// диск 1
	sf::Texture tdisk1;
	tdisk1.loadFromFile("disk 41x20.png");
	sf::Sprite sdisk1;
	sdisk1.setTexture(tdisk1);

	// диск 2
	sf::Texture tdisk2;
	tdisk2.loadFromFile("disk 51x20.png");
	sf::Sprite sdisk2;
	sdisk2.setTexture(tdisk2);

	//// диск 3
	sf::Texture tdisk3;
	tdisk3.loadFromFile("disk 61x20.png");
	sf::Sprite sdisk3;
	sdisk3.setTexture(tdisk3);

	// диск 4
	sf::Texture tdisk4;
	tdisk4.loadFromFile("disk 71x20.png");
	sf::Sprite sdisk4;
	sdisk4.setTexture(tdisk4);

	// диск 5
	sf::Texture tdisk5;
	tdisk5.loadFromFile("disk 81x20.png");
	sf::Sprite sdisk5;
	sdisk5.setTexture(tdisk5);

	// диск 6
	sf::Texture tdisk6;
	tdisk6.loadFromFile("disk 91x20.png");
	sf::Sprite sdisk6;
	sdisk6.setTexture(tdisk6);

	// диск 7
	sf::Texture tdisk7;
	tdisk7.loadFromFile("disk 101x20.png");
	sf::Sprite sdisk7;
	sdisk7.setTexture(tdisk7);

	// диск 8
	sf::Texture tdisk8;
	tdisk8.loadFromFile("disk 111x20.png");
	sf::Sprite sdisk8;
	sdisk8.setTexture(tdisk8);

	// диск 9
	sf::Texture tdisk9;
	tdisk9.loadFromFile("disk 121x20.png");
	sf::Sprite sdisk9;
	sdisk9.setTexture(tdisk9);

	// диск 10
	sf::Texture tdisk10;
	tdisk10.loadFromFile("disk 131x20.png");
	sf::Sprite sdisk10;
	sdisk10.setTexture(tdisk10);

	// после победы
	sf::Texture tAfterWin;
	tAfterWin.loadFromFile("after win.png");  // 150х210
	sf::Sprite sAfterWin;
	sAfterWin.setTexture(tAfterWin);

	// последний уровень
	sf::Texture tLastLevel;
	tLastLevel.loadFromFile("last level.png");  //200x200
	sf::Sprite sLastLevel;
	sLastLevel.setTexture(tLastLevel);
	sLastLevel.setPosition(220, 140);

	// шрифт
	sf::Font font;
	font.loadFromFile("arial.ttf");

	// текст начать игру
	sf::Text txtbegin;
	txtbegin.setFont(font);
	txtbegin.setString("Start");
	txtbegin.setPosition(285, 136);

	// текс помощь
	sf::Text txthelp;
	txthelp.setFont(font);
	txthelp.setString("Help");
	txthelp.setPosition(287, 216);

	// текст выход
	sf::Text txtexit;
	txtexit.setFont(font);
	txtexit.setString("Exit");
	txtexit.setPosition(287, 296);

	// текст уровень  1
	sf::Text txtlevel1;
	txtlevel1.setFont(font);
	txtlevel1.setString("1");
	txtlevel1.setPosition(240 + 25, 70 + 5);

	// текст уровень 2
	sf::Text txtlevel2;
	txtlevel2.setFont(font);
	txtlevel2.setString("2");
	txtlevel2.setPosition(240 + 25, 140 + 5);

	// текст уровень 3
	sf::Text txtlevel3;
	txtlevel3.setFont(font);
	txtlevel3.setString("3");
	txtlevel3.setPosition(240 + 25, 210 + 5);

	// текст уровень 4
	sf::Text txtlevel4;
	txtlevel4.setFont(font);
	txtlevel4.setString("4");
	txtlevel4.setPosition(240 + 25, 280 + 5);

	// текст уровень 5
	sf::Text txtlevel5;
	txtlevel5.setFont(font);
	txtlevel5.setString("5");
	txtlevel5.setPosition(240 + 25, 350 + 5);

	// текст уровень 6
	sf::Text txtlevel6;
	txtlevel6.setFont(font);
	txtlevel6.setString("6");
	txtlevel6.setPosition(340 + 25, 70 + 5);

	// текст уровень 7
	sf::Text txtlevel7;
	txtlevel7.setFont(font);
	txtlevel7.setString("7");
	txtlevel7.setPosition(340 + 25, 140 + 5);

	// текст уровень 8
	sf::Text txtlevel8;
	txtlevel8.setFont(font);
	txtlevel8.setString("8");
	txtlevel8.setPosition(340 + 25, 210 + 5);

	// текст уровень 9
	sf::Text txtlevel9;
	txtlevel9.setFont(font);
	txtlevel9.setString("9");
	txtlevel9.setPosition(340 + 25, 280 + 5);

	// текст уровень 10
	sf::Text txtlevel10;
	txtlevel10.setFont(font);
	txtlevel10.setString("10");
	txtlevel10.setPosition(340 + 15, 350 + 5);

	// последний уровень
	sf::Text txtOk;
	txtOk.setFont(font);
	txtOk.setString("Ok");
	txtOk.setPosition(220 + 39 + 40, 140 + 119 + 7);

	// текст победы
	sf::Text txtYouWin;
	txtYouWin.setFont(font);
	txtYouWin.setPosition(250, 68);

	// текст после победы следующий уровень
	sf::Text  txtAfterWinNextLevel;
	txtAfterWinNextLevel.setFont(font);
	txtAfterWinNextLevel.setString("Next level");
	txtAfterWinNextLevel.setPosition(280 - 25, 115 + 5);

	// текст после победы начать сначало
	sf::Text txtAfterWinRestart;
	txtAfterWinRestart.setFont(font);
	txtAfterWinRestart.setString("Restart");
	txtAfterWinRestart.setPosition(280 - 10, 215 + 5);

	// текст после победы меню
	sf::Text txtAfterWinMenu;
	txtAfterWinMenu.setFont(font);
	txtAfterWinMenu.setString("Menu");
	txtAfterWinMenu.setPosition(280, 315 + 5);

	// текст числа ходов
	sf::Text txtChisloHodov;
	txtChisloHodov.setFont(font);
	string moves;
	txtChisloHodov.setString(moves);
	txtChisloHodov.setCharacterSize(20);
	txtChisloHodov.setFillColor(sf::Color::Red);
	txtChisloHodov.setPosition(128 + 5, 0 + 5);

	// текст мин числа ходов
	sf::Text txtMinChisloHodov;
	txtMinChisloHodov.setFont(font);
	string minmoves;
	txtMinChisloHodov.setCharacterSize(20);
	txtMinChisloHodov.setFillColor(sf::Color::Red);
	txtMinChisloHodov.setPosition(0 + 5, 0 + 5);

	// начать сначало (во время игры)
	sf::Text txtRestart;
	txtRestart.setFont(font);
	txtRestart.setString("Restart");
	txtRestart.setCharacterSize(20);
	txtRestart.setFillColor(sf::Color::Red);
	txtRestart.setPosition(384 + 30, 0 + 10    );

	// текст меню в игре
	sf::Text txtmenu;
	txtmenu.setFont(font);
	txtmenu.setString("Menu");
	txtmenu.setCharacterSize(20);
	txtmenu.setFillColor(sf::Color::Red);
	txtmenu.setPosition(512 + 40, 0 + 10);

	// Секуномер
	sf::Text txtTimer;
	txtTimer.setFont(font);
	txtTimer.setCharacterSize(20);
	txtTimer.setFillColor(sf::Color::Red);
	txtTimer.setPosition(256 + 10, 0 + 10);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/////////////////////////////////////////////  меню   //////////////////////////////////////////////////////
		while (menu == true)
		{
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}

			mx = sf::Mouse::getPosition(window).x;
			my = sf::Mouse::getPosition(window).y;

			// выход
			if (mx >= 220 && mx <= 420 && my >= 290 && my <= 340) // && bhelp == false && blevel == false
			{
				txtexit.setFillColor(sf::Color::Red);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					window.close();
				}
			}
			else
			{
				txtexit.setFillColor(sf::Color::White);
			}

			// помощь
			if (mx >= 220 - 2 && mx <= 420 + 1 && my >= 210 - 2 && my <= 260 + 1)
			{
				txthelp.setFillColor(sf::Color::Red);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					bhelp = true;
					shelp.setPosition(170, 90);
					window.draw(shelp);
					window.display();
					while (bhelp == true)
					{
						mx = sf::Mouse::getPosition(window).x;
						my = sf::Mouse::getPosition(window).y;

						while (window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
							{
								window.close();
							}
						}
						if (mx < 170 || mx > 470 || my < 90 || my > 390)
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { ; }
								bhelp = false;
							}
						}
					}
				}
			}
			else
			{
				txthelp.setFillColor(sf::Color::White);
			}

			// выбор уровня
			if (mx >= 220 && mx <= 420 && my >= 130 && my <= 180) // && bhelp == false
			{
				txtbegin.setFillColor(sf::Color::Red);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { ; }
					blevel = true;
					slevel.setPosition(210, 50);

					while (blevel == true)
					{
						mx = sf::Mouse::getPosition(window).x;
						my = sf::Mouse::getPosition(window).y;

						while (window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
								window.close();
						}

						if (mx >= 240 && mx <= 310 && my >= 70 && my <= 120)
						{
							txtlevel1.setFillColor(sf::Color::Red);
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
									;
								} d = 1; menu = false; tower(a, b, d, n); GameOver = false; minmoves = "Min moves:\n      " + to_string(int(pow(2, d) - 1)); txtMinChisloHodov.setString(minmoves); break;
							}
						}
						else
						{
							txtlevel1.setFillColor(sf::Color::White);
						}

						if (mx >= 240 && mx <= 310 && my >= 140 && my <= 190)
						{
							txtlevel2.setFillColor(sf::Color::Red);
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
									;
								} d = 2; menu = false; tower(a, b, d, n); GameOver = false; minmoves = "Min moves:\n      " + to_string(int(pow(2, d) - 1)); txtMinChisloHodov.setString(minmoves); break;
							}
						}
						else
						{
							txtlevel2.setFillColor(sf::Color::White);
						}

						if (mx >= 240 && mx <= 310 && my >= 210 && my <= 260)
						{
							txtlevel3.setFillColor(sf::Color::Red);
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
									;
								} d = 3; menu = false; tower(a, b, d, n); GameOver = false; minmoves = "Min moves:\n      " + to_string(int(pow(2, d) - 1)); txtMinChisloHodov.setString(minmoves); break;
							}
						}
						else
						{
							txtlevel3.setFillColor(sf::Color::White);
						}

						if (mx >= 240 && mx <= 310 && my >= 280 && my <= 330)
						{
							txtlevel4.setFillColor(sf::Color::Red);
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
									;
								} d = 4; menu = false; tower(a, b, d, n); GameOver = false; minmoves = "Min moves:\n      " + to_string(int(pow(2, d) - 1)); txtMinChisloHodov.setString(minmoves); break;
							}
						}
						else
						{
							txtlevel4.setFillColor(sf::Color::White);
						}

						if (mx >= 240 && mx <= 310 && my >= 350 && my <= 400)
						{
							txtlevel5.setFillColor(sf::Color::Red);
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
									;
								} d = 5; menu = false; tower(a, b, d, n); GameOver = false; minmoves = "Min moves:\n      " + to_string(int(pow(2, d) - 1)); txtMinChisloHodov.setString(minmoves); break;
							}
						}
						else
						{
							txtlevel5.setFillColor(sf::Color::White);
						}

						if (mx >= 340 && mx <= 410 && my >= 70 && my <= 120)
						{
							txtlevel6.setFillColor(sf::Color::Red);
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
									;
								} d = 6; menu = false; tower(a, b, d, n); GameOver = false; minmoves = "Min moves:\n      " + to_string(int(pow(2, d) - 1)); txtMinChisloHodov.setString(minmoves); break;
							}
						}
						else
						{
							txtlevel6.setFillColor(sf::Color::White);
						}

						if (mx >= 340 && mx <= 410 && my >= 140 && my <= 190)
						{
							txtlevel7.setFillColor(sf::Color::Red);
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
									;
								} d = 7; menu = false; tower(a, b, d, n); GameOver = false; minmoves = "Min moves:\n      " + to_string(int(pow(2, d) - 1)); txtMinChisloHodov.setString(minmoves); break;
							}
						}
						else
						{
							txtlevel7.setFillColor(sf::Color::White);
						}

						if (mx >= 340 && mx <= 410 && my >= 210 && my <= 260)
						{
							txtlevel8.setFillColor(sf::Color::Red);
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
									;
								} d = 8; menu = false; tower(a, b, d, n); GameOver = false; minmoves = "Min moves:\n      " + to_string(int(pow(2, d) - 1)); txtMinChisloHodov.setString(minmoves); break;
							}
						}
						else
						{
							txtlevel8.setFillColor(sf::Color::White);
						}

						if (mx >= 340 && mx <= 410 && my >= 280 && my <= 330)
						{
							txtlevel9.setFillColor(sf::Color::Red);
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
									;
								} d = 9; menu = false; tower(a, b, d, n); GameOver = false; minmoves = "Min moves:\n      " + to_string(int(pow(2, d) - 1)); txtMinChisloHodov.setString(minmoves); break;
							}
						}
						else
						{
							txtlevel9.setFillColor(sf::Color::White);
						}

						if (mx >= 340 && mx <= 410 && my >= 350 && my <= 400)
						{
							txtlevel10.setFillColor(sf::Color::Red);
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
									;
								} d = 10; menu = false; tower(a, b, d, n); GameOver = false; minmoves = "Min moves:\n      " + to_string(int(pow(2, d) - 1)); txtMinChisloHodov.setString(minmoves); break;
							}
						}
						else
						{
							txtlevel10.setFillColor(sf::Color::White);
						}

						if (mx < 210 || mx > 440 || my < 50 || my > 420) // 230x370
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { ; }
								blevel = false;
							}
						}

						window.draw(slevel);
						window.draw(txtlevel1);
						window.draw(txtlevel2);
						window.draw(txtlevel3);
						window.draw(txtlevel4);
						window.draw(txtlevel5);
						window.draw(txtlevel6);
						window.draw(txtlevel7);
						window.draw(txtlevel8);
						window.draw(txtlevel9);
						window.draw(txtlevel10);
						window.display();
					}
				}
			}
			else
			{
				txtbegin.setFillColor(sf::Color::White);
			}

			window.clear();
			window.draw(smenu);
			window.draw(txtbegin);
			window.draw(txthelp);
			window.draw(txtexit);
			window.display();
		}
		//_______________________________________________________________________

		/////////////////////////////////   игра   /////////////////////////////
		while (GameOver == false)
		{
			mx = sf::Mouse::getPosition(window).x;
			my = sf::Mouse::getPosition(window).y;
			if(TurnOnTimer == true)
			{
				clock.restart();
				TurnOnTimer = false;
			}
				
			txtTimer.setString("Time:" + to_string(int(clock.getElapsedTime().asSeconds())));

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			// button restart
			if (mx >= 384 && mx < 512 && my>0 && my < 40)
			{
				txtRestart.setFillColor(sf::Color::Blue);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					clock.restart();
					stolbec = 0;
					skursor.setPosition(x[stolbec], y1);
					hod = 0;
					take = false;
					tower(a, b, d, n);
				}
			}
			else
			{
				txtRestart.setFillColor(sf::Color::Red);
			}

			// button menu
			if (mx >= 512 && my > 0 && my < 40)
			{
				txtmenu.setFillColor(sf::Color::Blue);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					TurnOnTimer = true;
					clock.restart();
					stolbec = 0;
					skursor.setPosition(x[stolbec], y1);
					hod = 0;
					take = false;
					GameOver = true;
					menu = true;
				}
			}
			else
			{
				txtmenu.setFillColor(sf::Color::Red);
			}

			// вверх
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				for (int i = 1; i <= n; i++)
				{
					if (a[i][stolbec] != 0 && take == false)
					{
						a[0][stolbec] = a[i][stolbec];
						a[i][stolbec] = 0;
						take = true;
						hod++;
						break;
					}
				}
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { ; }
			}

			// вниз
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				for (int i = 0; i <= n; i++)
				{
					if (a[n - i][stolbec] == 0 && take == true)
					{
						a[n - i][stolbec] = a[0][stolbec];
						a[0][stolbec] = 0;
						take = false;
						break;
					}
					else
					{
						if (a[0][stolbec] > a[n - i][stolbec] && take == true)
						{
							break;
						}
					}
				}
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { ; }
			}

			// вправо
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if (stolbec != 2)
				{
					a[0][stolbec + 1] = a[0][stolbec];
					a[0][stolbec] = 0;
					stolbec++;
				}
				else
				{
					a[0][stolbec - 2] = a[0][stolbec];
					a[0][stolbec] = 0;
					stolbec = 0;
				}
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { ; }
				skursor.setPosition(x[stolbec] - 1, y1);
			}

			// влево
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if (stolbec != 0)
				{
					a[0][stolbec - 1] = a[0][stolbec];
					a[0][stolbec] = 0;
					stolbec--;
				}
				else
				{
					a[0][stolbec + 2] = a[0][stolbec];
					a[0][stolbec] = 0;
					stolbec = 2;
				}
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { ; }
				skursor.setPosition(x[stolbec] - 1, y1);
			}

			moves = "Move: " + to_string(hod);
			txtChisloHodov.setString(moves);

			//////////////////////   определение победы   /////////////////////////
			for (int i = 0; i <= n; i++)
			{
				if (a[i][2] == b[i][0]) { p++; }
			}

			if (p == n + 1) { win = true; GameOver = true; }

			p = 0;
			if (win == true)
			{
				AfterWin = true;
				sAfterWin.setPosition(170, 65);
				if(hod==int(pow(2,d)-1))
				{
					txtYouWin.setString("Perfect");
				}
				else
				{
					if (hod <= int(pow(2, d) - 1) + 3)
					{
						txtYouWin.setString("Excellent");
					}
					else
					{
						txtYouWin.setString("Good job");
					}
				}
			}

			//////////////////////   Отрисовка   /////////////////////
			for (int i = 0; i <= n; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (a[i][j] == 1) { sdisk1.setPosition(x[j] - 6, y[i]); }
					if (a[i][j] == 2) { sdisk2.setPosition(x[j] - 11, y[i]); }
					if (a[i][j] == 3) { sdisk3.setPosition(x[j] - 16, y[i]); }
					if (a[i][j] == 4) { sdisk4.setPosition(x[j] - 21, y[i]); }
					if (a[i][j] == 5) { sdisk5.setPosition(x[j] - 26, y[i]); }
					if (a[i][j] == 6) { sdisk6.setPosition(x[j] - 31, y[i]); }
					if (a[i][j] == 7) { sdisk7.setPosition(x[j] - 36, y[i]); }
					if (a[i][j] == 8) { sdisk8.setPosition(x[j] - 41, y[i]); }
					if (a[i][j] == 9) { sdisk9.setPosition(x[j] - 46, y[i]); }
					if (a[i][j] == 10) { sdisk10.setPosition(x[j] - 51, y[i]); }
				}
			}

			window.clear();
			window.draw(smap);
			window.draw(skursor);
			window.draw(txtChisloHodov);
			window.draw(txtMinChisloHodov);
			window.draw(txtRestart);
			window.draw(txtmenu);
			window.draw(txtTimer);
			if (d == 1)
			{
				window.draw(sdisk1);
			}
			if (d == 2)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
			}
			if (d == 3)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
			}
			if (d == 4)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
			}
			if (d == 5)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
			}
			if (d == 6)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
				window.draw(sdisk6);
			}
			if (d == 7)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
				window.draw(sdisk6);
				window.draw(sdisk7);
			}
			if (d == 8)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
				window.draw(sdisk6);
				window.draw(sdisk7);
				window.draw(sdisk8);
			}
			if (d == 9)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
				window.draw(sdisk6);
				window.draw(sdisk7);
				window.draw(sdisk8);
				window.draw(sdisk9);
			}
			if (d == 10)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
				window.draw(sdisk6);
				window.draw(sdisk7);
				window.draw(sdisk8);
				window.draw(sdisk9);
				window.draw(sdisk10);
			}
			window.display();
		}
		//________________________________________________________________________

		///////////////////////////   после победы   /////////////////////////////
		while (AfterWin == true) //300x350    т. 170 65
		{
			TurnOnTimer = true;
			
			mx = sf::Mouse::getPosition(window).x;
			my = sf::Mouse::getPosition(window).y;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (mx >= 220 + 39 && mx <= 220 + 161 && my >= 140 + 119 && my <= 140 + 170 && lastlevel)  // last level
			{
				txtOk.setFillColor(sf::Color::Red);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					lastlevel = false;
				}
			}
			else
			{
				txtOk.setFillColor(sf::Color::White);
			}

			if (mx >= 170 + 58 && mx <= 170 + 243 && my >= 65 + 49 && my <= 65 + 49 + 52 && lastlevel == false)  // button next level
			{
				txtAfterWinNextLevel.setFillColor(sf::Color::Red);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && d!=10)
				{
					while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { ; }
					clock.restart();
					stolbec = 0;
					skursor.setPosition(x[stolbec], y1);
					hod = 0;
					AfterWin = false;
					GameOver = false;
					win = false;
					d = d + 1;
					minmoves = "Min moves: " + to_string(int(pow(2, d) - 1));
					txtMinChisloHodov.setString(minmoves);
					tower(a, b, d, n);
					break;
				}
				else
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						lastlevel = true;
					}
				}
			}
			else
			{
				txtAfterWinNextLevel.setFillColor(sf::Color::White);
			}

			if (mx >= 170 + 58 && mx <= 170 + 243 && my >= 65 + 149 && my <= 65 + 149 + 52 && lastlevel == false)   // button restart
			{
				txtAfterWinRestart.setFillColor(sf::Color::Red);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { ; }
					clock.restart();
					stolbec = 0;
					skursor.setPosition(x[stolbec], y1);
					hod = 0;
					AfterWin = false;
					GameOver = false;
					win = false;
					tower(a, b, d, n);
					break;
				}
			}
			else
			{
				txtAfterWinRestart.setFillColor(sf::Color::White);
			}

			if (mx >= 170 + 58 && mx <= 170 + 243 && my >= 65 + 249 && my <= 65 + 249 + 52 && lastlevel == false)   // button menu
			{
				txtAfterWinMenu.setFillColor(sf::Color::Red);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { ; }
					TurnOnTimer = true;
					clock.restart();
					stolbec = 0;
					skursor.setPosition(x[stolbec], y1);
					hod = 0;
					AfterWin = false;
					GameOver = false;
					win = false;
					menu = true;
					break;
				}
			}
			else
			{
				txtAfterWinMenu.setFillColor(sf::Color::White);
			}

			window.clear();
			window.draw(smap);
			window.draw(skursor);
			window.draw(txtChisloHodov);
			window.draw(txtMinChisloHodov);
			window.draw(txtRestart);
			window.draw(txtmenu);
			window.draw(txtTimer);
			if (d == 1)
			{
				window.draw(sdisk1);
			}
			if (d == 2)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
			}
			if (d == 3)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
			}
			if (d == 4)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
			}
			if (d == 5)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
			}
			if (d == 6)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
				window.draw(sdisk6);
			}
			if (d == 7)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
				window.draw(sdisk6);
				window.draw(sdisk7);
			}
			if (d == 8)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
				window.draw(sdisk6);
				window.draw(sdisk7);
				window.draw(sdisk8);
			}
			if (d == 9)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
				window.draw(sdisk6);
				window.draw(sdisk7);
				window.draw(sdisk8);
				window.draw(sdisk9);
			}
			if (d == 10)
			{
				window.draw(sdisk1);
				window.draw(sdisk2);
				window.draw(sdisk3);
				window.draw(sdisk4);
				window.draw(sdisk5);
				window.draw(sdisk6);
				window.draw(sdisk7);
				window.draw(sdisk8);
				window.draw(sdisk9);
				window.draw(sdisk10);
			}
			window.draw(sAfterWin);
			window.draw(txtYouWin);
			window.draw(txtAfterWinNextLevel);
			window.draw(txtAfterWinRestart);
			window.draw(txtAfterWinMenu);
			if (lastlevel)
			{
				window.draw(sLastLevel);
				window.draw(txtOk);
			}
			window.display();
		}
		//___________________________________________________________

	}

	return 0;
}
