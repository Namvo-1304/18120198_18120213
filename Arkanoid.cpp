#include "Arkanoid.h"
#include <time.h>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
Arkanoid::Arkanoid()
{

}
Arkanoid:: ~Arkanoid()
{

}
int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}
void Arkanoid::run()

{
	srand(time(0));
	int r;
	RenderWindow frame(VideoMode(Width, Height), "Arkanoid!");
	frame.setFramerateLimit(60);

	Background Upper(Vector2f(Width, 13), Vector2f(0, 0), "resources/images/topbar.png");
	Background Upper1(Vector2f(Width, 13), Vector2f(0, 63), "resources/images/topbar.png");
	Background Bottom(Vector2f(Width, 13), Vector2f(0, Height - 13), "resources/images/bottombar.png");
	Background Left(Vector2f(13, Height), Vector2f(0, 0), "resources/images/leftbar.png");
	Background Right(Vector2f(13, Height), Vector2f(Width - 13, 0), "resources/images/rightbar.png");

	Texture t1, t2, t3, th, tx1, tx2, tx3, tx4, tx5;
	t1.loadFromFile("images/block01.png");
	tx1.loadFromFile("images/block01.png");
	tx2.loadFromFile("images/block02.png");
	tx3.loadFromFile("images/block03.png");
	tx4.loadFromFile("images/block04.png");
	tx5.loadFromFile("images/block05.png");
	t2.loadFromFile("images/paddle.png");
	t3.loadFromFile("images/hamster.png");
	th.loadFromFile("images/heart.png");


	Font font;
	if (!font.loadFromFile("resources/PressStart2P.ttf"))
		exit(EXIT_FAILURE);
	Text pauseMessage;
	pauseMessage.setFont(font);
	pauseMessage.setCharacterSize(30);
	pauseMessage.setPosition(Width / 2 - 11 * 30, Height - 150);
	pauseMessage.setFillColor(Color::Green);
	pauseMessage.setString("NHAN ENTER DE VAO GAME");

	float score = 0;

	Text Scoretxt;
	if (!font.loadFromFile("resources/PressStart2P.ttf"))
		exit(EXIT_FAILURE);
	Scoretxt.setFont(font);
	Scoretxt.setFillColor(Color::White);
	Scoretxt.setCharacterSize(40);
	Scoretxt.setString(ftos(score, 1));
	Scoretxt.setPosition(Width - 300, 13);

	vector<Sprite>Heart;
	Heart.clear();
	Sprite paddle(t2);
	paddle.setScale(1.8, 1.3);
	paddle.setPosition(Width / 2 - 80, Height - 13 - 21);

	vector<Sprite>ball;
	ball.clear();
	if (ball.empty())
	{
		Sprite temp(t3);
		temp.setScale(0.3, 0.3);
		temp.setPosition(Width / 2 - 10, Height - 33 - 22 * 2);
		ball.push_back(temp);
	}

	vector<Sprite>block;
	block.clear();
	vector<Sprite>obstacles;
	obstacles.clear();
	r = random(1, 3);
	for (int i = 0; i <= 13; i++)
	{

		for (int j = 0; j < 7; j++)
		{
			Sprite temp;
			if (r == 1) {
				if (i == 1 && j == 0) {
					temp.setTexture(tx3);
				}
				if (i == 2 && j == 0) {
					temp.setTexture(tx5);
				}
				if (i == 0 && j == 1) {
					temp.setTexture(tx2);
				}
				if (i == 0 && j == 2) {
					temp.setTexture(tx5);
				}
				if (i == 0 && j == 3) {
					temp.setTexture(tx2);
				}
				if (i == 0 && j == 4) {
					temp.setTexture(tx3);
				}
				if (i == 3 && j == 1) {
					temp.setTexture(tx2);
				}
				if (i == 3 && j == 2) {
					temp.setTexture(tx5);
				}
				if (i == 3 && j == 3) {
					temp.setTexture(tx2);
				}
				if (i == 3 && j == 4) {
					temp.setTexture(tx3);
				}
				if (i == 1 && j == 5) {
					temp.setTexture(tx5);
				}
				if (i == 2 && j == 5) {
					temp.setTexture(tx3);
				}
				if (i == 6 && j == 0) {
					temp.setTexture(tx3);
				}
				if (i == 7 && j == 0) {
					temp.setTexture(tx5);
				}
				if (i == 5 && j == 1) {
					temp.setTexture(tx2);
				}
				if (i == 5 && j == 2) {
					temp.setTexture(tx5);
				}
				if (i == 5 && j == 3) {
					temp.setTexture(tx2);
				}
				if (i == 5 && j == 4) {
					temp.setTexture(tx3);
				}
				if (i == 8 && j == 1) {
					temp.setTexture(tx2);
				}
				if (i == 8 && j == 2) {
					temp.setTexture(tx5);
				}
				if (i == 8 && j == 3) {
					temp.setTexture(tx2);
				}
				if (i == 8 && j == 4) {
					temp.setTexture(tx3);
				}
				if (i == 6 && j == 5) {
					temp.setTexture(tx5);
				}
				if (i == 7 && j == 5) {
					temp.setTexture(tx3);
				}
				if (i == 10 && j == 0) {
					temp.setTexture(tx3);
				}
				if (i == 10 && j == 1) {
					temp.setTexture(tx2);
				}
				if (i == 10 && j == 2) {
					temp.setTexture(tx5);
				}
				if (i == 10 && j == 3) {
					temp.setTexture(tx2);
				}
				if (i == 10 && j == 4) {
					temp.setTexture(tx3);
				}
				if (i == 10 && j == 5) {
					temp.setTexture(tx4);
				}
				if (i == 11 && j == 0) {
					temp.setTexture(tx3);
				}
				if (i == 12 && j == 0) {
					temp.setTexture(tx5);
				}
				if (i == 12 && j == 1) {
					temp.setTexture(tx2);
				}
				if (i == 12 && j == 2) {
					temp.setTexture(tx5);
				}
				if (i == 12 && j == 3) {
					temp.setTexture(tx3);
				}
				if (i == 11 && j == 3) {
					temp.setTexture(tx3);
				}
			}
			else if (r == 2) {
				if ((i + j) % 4 == 0)
				{
					temp.setTexture(tx3);
				}
				else if ((i + j) % 4 == 1)
				{

					temp.setTexture(tx2);
				}
				else if ((i + j) % 4 == 2 )
				{
					temp.setTexture(tx3);
				}
				else if ((i + j) % 4 == 3 )
				{
					temp.setTexture(tx5);
				}
			}
			else if (r == 3) {
				if (i == 2 && j == 5) {
					temp.setTexture(tx2);
				}
				if (i == 3 && j == 5) {
					temp.setTexture(tx3);
				}
				if (i == 4 && j == 5) {
					temp.setTexture(tx5);
				}
				if (i == 5 && j == 5) {
					temp.setTexture(tx3);
				}
				if (i == 6 && j == 5) {
					temp.setTexture(tx2);
				}
				if (i == 6 && j == 3) {
					temp.setTexture(tx3);
				}
				if (i == 6 && j == 2) {
					temp.setTexture(tx5);
				}
				if (i == 3 && j == 6) {
					temp.setTexture(tx2);
				}
				if (i == 4 && j == 6) {
					temp.setTexture(tx3);
				}
				if (i == 5 && j == 6) {
					temp.setTexture(tx5);
				}
				if (i == 7 && j == 6) {
					temp.setTexture(tx5);
				}
				if (i == 8 && j == 6) {
					temp.setTexture(tx2);
				}
				if (i == 3 && j == 4) {
					temp.setTexture(tx2);
				}
				if (i == 4 && j == 4) {
					temp.setTexture(tx3);
				}
				if (i == 5 && j == 4) {
					temp.setTexture(tx5);
				}
				if (i == 6 && j == 4) {
					temp.setTexture(tx5);
				}
				if (i == 7 && j == 4) {
					temp.setTexture(tx3);
				}
				if (i == 8 && j == 4) {
					temp.setTexture(tx2);
				}
				if (i == 8 && j == 3) {
					temp.setTexture(tx3);
				}
				if (i == 8 && j == 2) {
					temp.setTexture(tx5);
				}
				if (i == 6 && j == 1) {
					temp.setTexture(tx2);
				}
				if (i == 5 && j == 0) {
					temp.setTexture(tx2);
				}
				if (i == 8 && j == 1) {
					temp.setTexture(tx3);
				}
				if (i == 7 && j == 0) {
					temp.setTexture(tx3);
				}
				if (i == 7 && j == 2) {
					temp.setTexture(tx5);
				}
				if (i == 7 && j == 3) {
					temp.setTexture(tx2);
				}
				if (i == 10 && j == 2) {
					temp.setTexture(tx3);
				}
				if (i == 11 && j == 1) {
					temp.setTexture(tx3);
				}
				if (i == 12 && j == 1) {
					temp.setTexture(tx3);
				}
				if (i == 10 && j == 1) {
					temp.setTexture(tx3);
				}
				if (i == 11 && j == 0) {
					temp.setTexture(tx3);
				}
				if (i == 12 && j == 0) {
					temp.setTexture(tx3);
				}
				if (i == 13 && j == 0) {
					temp.setTexture(tx3);
				}
				if (i == 13 && j == 1) {
					temp.setTexture(tx3);
				}
				if (i == 13 && j == 2) {
					temp.setTexture(tx3);
				}
				if (i == 13 && j == 3) {
					temp.setTexture(tx3);
				}
				if (i == 13 && j == 4) {
					temp.setTexture(tx3);
				}
				if (i == 13 && j == 5) {
					temp.setTexture(tx3);
				}
				if (i == 13 && j == 6) {
					temp.setTexture(tx3);
				}
			}
			temp.setScale(1.5, 1.5);
			temp.setPosition((i + 1) * 43 * 1.5, (j + 3) * 20 * 1.5 + 15);
			block.push_back(temp);
		}
		cout << endl;

	}

	float paddleSpeed;
	vector<float> ballSpeed;
	vector<float> ballAngle;
	ballAngle.clear();
	ballSpeed.clear();
	ballSpeed.resize(100);
	ballAngle.resize(100);
	Clock clock;
	paddleSpeed = 500;
	for (int i = 0; i < 100; i++)
		ballSpeed[i] = 250;


	float modifier = 1;
	bool pause = 1;
	int screen = 0;
	while (frame.isOpen())
	{
		Event e;
		while (frame.pollEvent(e))
		{
			if (e.type == Event::Closed)
				frame.close();
			else if (e.type == Event::KeyPressed)
			{
				if (screen == 0)
				{
					if (e.key.code == (Keyboard::Enter))
					{
						if (pause)
						{
							for (int k = 0; k < 100; k++)
							{
								do {
									ballAngle[k] = -PI * (rand() % 4) / 4;
								} while ((sin(ballAngle[k]) < -0.8) || (sin(ballAngle[k]) == 0));

							}
							for (int i = 0; i < 3; i++)
							{
								Sprite temp(th);
								temp.setScale(0.2, 0.2);
								temp.setPosition(13 + 60 * i, 1);
								Heart.push_back(temp);
							}
							pause = 0;
						}
					}
					if (e.key.code == (Keyboard::Escape))
					{
						return;
					}
				}
				else if (screen == 1)
				{
					if (e.key.code == (Keyboard::Enter))
					{
						screen = 2;


					}



				}
				else if (screen == 2)
				{
					if (e.key.code == (Keyboard::Enter))
						return;
				}
			}
		}

		if (screen == 0)
		{
			if (pause == 0)
			{
				float deltaTime = clock.restart().asSeconds();
				//Di chuyen thanh paddle
				if (Keyboard::isKeyPressed(Keyboard::Right))
				{
					if (!paddle.getGlobalBounds().intersects(Right.getGlobalBounds()))
					{
						paddle.move(deltaTime * paddleSpeed, 0);
					}
				}

				if (Keyboard::isKeyPressed(Keyboard::Left))
				{
					if (!paddle.getGlobalBounds().intersects(Left.getGlobalBounds()))
					{
						paddle.move(-deltaTime * paddleSpeed, 0);
					}
				}

				// Di chuyen bong
				for (int k = 0; k < ball.size(); k++)
				{
					float factor = ballSpeed[k] * deltaTime;
					ball[k].move(cos(ballAngle[k]) * factor, sin(ballAngle[k]) * factor);
				}

				//Xet va cham bien
				for (int k = 0; k < ball.size(); k++)
				{
					if (ball[k].getGlobalBounds().intersects(Left.getGlobalBounds()))
					{
						ballAngle[k] = PI - ballAngle[k];
						ball[k].setPosition(13, ball[k].getPosition().y);
					}
					if (ball[k].getGlobalBounds().intersects(Right.getGlobalBounds()))
					{
						ballAngle[k] = PI - ballAngle[k];
						ball[k].setPosition(Width - 17 - ballRadius * 2, ball[k].getPosition().y);
					}
					if (ball[k].getGlobalBounds().intersects(Upper1.getGlobalBounds()))
					{
						ballAngle[k] = -ballAngle[k];
						ball[k].setPosition(ball[k].getPosition().x, Upper1.getPosition().y + 13);
					}
					if (ball[k].getGlobalBounds().intersects(Bottom.getGlobalBounds()))
					{
						ballAngle[k] = -ballAngle[k];
						ball[k].setPosition(ball[k].getPosition().x, Height - 35 - ballRadius * 2);
						Heart.pop_back();
						if (ball.size() > 1)
						{
							ball.erase(ball.begin() + k);
							ballAngle.erase(ballAngle.begin() + k);
						}

					}

				}

				//Xet va cham giua ball va paddle
				for (int k = 0; k < ball.size(); k++)
				{
					if (ball[k].getGlobalBounds().intersects(paddle.getGlobalBounds()))
					{
						ballAngle[k] = -ballAngle[k];
						if (ballSpeed[k] < 350)
						{
							ballSpeed[k] = 1.1 * ballSpeed[k];
						}
						do
						{
							ball[k].move(0, -1);
						} while (ball[k].getGlobalBounds().intersects(paddle.getGlobalBounds()));

					}
				}

				//Xet va cham obstacle va block
				for (int k = 0; k < ball.size(); k++)
				{
					for (int i = 0; i < block.size(); i++)
					{
						if (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()))
						{
							if (ball[k].getPosition().y + 10 > block[i].getPosition().y + 20 * 1.5)
							{
								ballAngle[k] = -ballAngle[k];
								do
								{
									ball[k].move(0, 1);
								} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
							}
							else if (ball[k].getPosition().y + 10 < block[i].getPosition().y)
							{
								ballAngle[k] = -ballAngle[k];
								do
								{
									ball[k].move(0, -1);
								} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
							}
							else
							{
								if (ball[k].getPosition().x + 10 < block[i].getPosition().x)
								{
									ballAngle[k] = PI - ballAngle[k];
									do
									{
										ball[k].move(-1, 0);
									} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
								}
								else if (ball[k].getPosition().x + 10 > block[i].getPosition().x + 43 * 1.5)
								{
									ballAngle[k] = PI - ballAngle[k];
									do
									{
										ball[k].move(1, 0);
									} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
								}
							}
							int ran = rand() % 100;
							if (ran < 18)
							{
								modifier = 2;
							}
							else if ((ran >= 18) && (ran < 36))
							{
								modifier = 0.5;
							}
							else if ((ran >= 36) && (ran < 46))
							{
								paddle.setScale(1.8, 1.3);
							}
							else if ((ran >= 46) && (ran < 59))
							{
								paddle.setScale(2.6, 1.3);
								if (ball.size() < 3)
								{
									Sprite temp(t3);
									temp.setScale(0.3, 0.3);
									temp.setPosition(Width / 2 - 10, Height - 33 - 22 * 2);
									ball.push_back(temp);
								}
							}
							else if ((ran >= 59) && (ran < 69 + 3))
							{
								block[i].setTexture(tx4);
								obstacles.push_back(block[i]);
							}
							else if ((ran > 75) && (ran <= 87))
							{
								if (Heart.size() < 6)
								{
									Sprite temp(th);
									temp.setScale(0.2, 0.2);
									temp.setPosition(Heart[Heart.size() - 1].getPosition().x + 60, 1);
									Heart.push_back(temp);
								}

							}
							score += 500 * modifier;
							modifier = 1;
							Scoretxt.setString(ftos(score, 1));
							block.erase(block.begin() + i);
							i--;
						}
					}
					for (int i = 0; i < block.size(); i++)
					{
						if (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()))
						{
							if (ball[k].getPosition().y + 10 > block[i].getPosition().y + 20 * 1.5)
							{
								ballAngle[k] = -ballAngle[k];
								do
								{
									ball[k].move(0, 1);
								} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
							}
							else if (ball[k].getPosition().y + 10 < block[i].getPosition().y)
							{
								ballAngle[k] = -ballAngle[k];
								do
								{
									ball[k].move(0, -1);
								} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
							}
							else
							{
								if (ball[k].getPosition().x + 10 < block[i].getPosition().x)
								{
									ballAngle[k] = PI - ballAngle[k];
									do
									{
										ball[k].move(-1, 0);
									} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
								}
								else if (ball[k].getPosition().x + 10 > block[i].getPosition().x + 43 * 1.5)
								{
									ballAngle[k] = PI - ballAngle[k];
									do
									{
										ball[k].move(1, 0);
									} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
								}
							}
							int ran = rand() % 100;
							if (ran < 18)
							{
								modifier = 2;
							}
							else if ((ran >= 18) && (ran < 36))
							{
								modifier = 0.5;
							}
							else if ((ran >= 36) && (ran < 46))
							{
								paddle.setScale(1.8, 1.3);
							}
							else if ((ran >= 46) && (ran < 59))
							{
								paddle.setScale(2.6, 1.3);
								if (ball.size() < 3)
								{
									Sprite temp(t3);
									temp.setScale(0.3, 0.3);
									temp.setPosition(Width / 2 - 10, Height - 33 - 22 * 2);
									ball.push_back(temp);
								}
							}
							else if ((ran >= 59) && (ran < 69 + 3))
							{
								block[i].setTexture(tx4);
								obstacles.push_back(block[i]);
							}
							else if ((ran > 75) && (ran <= 87))
							{
								if (Heart.size() < 6)
								{
									Sprite temp(th);
									temp.setScale(0.2, 0.2);
									temp.setPosition(Heart[Heart.size() - 1].getPosition().x + 60, 1);
									Heart.push_back(temp);
								}

							}
							score += 500 * modifier;
							modifier = 1;
							Scoretxt.setString(ftos(score, 1));
							block.erase(block.begin() + i);
							i--;
						}
					}
					for (int i = 0; i < obstacles.size(); i++)
					{
						if (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()))
						{
							if (ball[k].getPosition().y + 10 > obstacles[i].getPosition().y + 20 * 1.5)
							{
								ballAngle[k] = -ballAngle[k] + PI / 12;
								do
								{
									ball[k].move(0, 1);
								} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
							}
							else if (ball[k].getPosition().y + 10 < obstacles[i].getPosition().y)
							{
								ballAngle[k] = -ballAngle[k] + PI / 12;
								do
								{
									ball[k].move(0, -1);
								} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
							}
							else
							{
								if (ball[k].getPosition().x + 10 < obstacles[i].getPosition().x)
								{
									ballAngle[k] = PI - ballAngle[k] + PI / 12;
									do
									{
										ball[k].move(-2, 0);
									} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
								}
								else if (ball[k].getPosition().x + 10 > obstacles[i].getPosition().x + 43 * 1.5)
								{
									ballAngle[k] = PI - ballAngle[k] + PI / 12;
									do
									{
										ball[k].move(2, 0);
									} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
								}
							}

						}
					}
					for (int i = 0; i < obstacles.size(); i++)
					{
						if (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()))
						{


							if (ball[k].getPosition().y + 10 > obstacles[i].getPosition().y + 20 * 1.5)
							{
								ballAngle[k] = -ballAngle[k] + PI / 12;
								do
								{
									ball[k].move(0, 1);
								} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
							}
							else if (ball[k].getPosition().y + 10 < obstacles[i].getPosition().y)
							{
								ballAngle[k] = -ballAngle[k] + PI / 12;
								do
								{
									ball[k].move(0, -1);
								} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
							}
							else
							{
								if (ball[k].getPosition().x + 10 < obstacles[i].getPosition().x)
								{
									ballAngle[k] = PI - ballAngle[k] + PI / 12;
									do
									{
										ball[k].move(-2, 0);
									} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
								}
								else if (ball[k].getPosition().x + 10 > obstacles[i].getPosition().x + 43 * 1.5)
								{
									ballAngle[k] = PI - ballAngle[k] + PI / 12;
									do
									{
										ball[k].move(2, 0);
									} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
								}
							}

						}
					}
				}

				if (Heart.empty())
				{
					screen = 1;
					pauseMessage.setString("YOU LOSE");
					pauseMessage.setPosition(Width / 2 - 4 * 30, Height - 150);
					vector<float >point;
					point.resize(10);
					ifstream in;
					in.open("Arkanoid.txt");
					if (!in.is_open())
					{
						exit(EXIT_FAILURE);
					}
					else
					{


						for (int i = 0; i < 10; i++)
						{

							in >> point[i];
						}

						point.push_back(score);

					}
					in.close();
					sort(point.begin(), point.end());
					ofstream out;
					out.open("Arkanoid.txt");
					if (!out.is_open())
					{
						exit(EXIT_FAILURE);
					}
					else
					{

						for (int i = 0; i < 10; i++)
						{
							out << point[point.size() - 1 - i] << endl;

							cout << point[point.size() - 1 - i] << endl;

						}
					}
					out.close();

				}
				if (block.empty())
				{
					screen = 1;
					pauseMessage.setString("YOU WIN");
					pauseMessage.setPosition(Width / 2 - 4 * 30, Height - 150);
					vector<float >point;
					point.resize(10);
					ifstream in;
					in.open("Arkanoid.txt");
					if (!in.is_open())
					{
						exit(EXIT_FAILURE);
					}
					else
					{


						for (int i = 0; i < 10; i++)
						{

							in >> point[i];
						}

						point.push_back(score);

					}
					in.close();
					sort(point.begin(), point.end());
					ofstream out;
					out.open("Arkanoid.txt");
					if (!out.is_open())
					{
						exit(EXIT_FAILURE);
					}
					else
					{

						for (int i = 0; i < 10; i++)
						{
							out << point[point.size() - 1 - i] << endl;
							cout << point[point.size() - 1 - i] << endl;
						}
					}
					out.close();
				}

			}
		}



		frame.clear();

		if (screen == 0)
		{
			for (int k = 0; k < ball.size(); k++)
			{

				frame.draw(ball[k]);
			}
			for (int i = 0; i < block.size(); i++)
			{
				frame.draw(block[i]);
			}
			for (int i = 0; i < obstacles.size(); i++)
			{
				frame.draw(obstacles[i]);
			}
			for (int i = 0; i < Heart.size(); i++)
			{
				frame.draw(Heart[i]);
			}
			frame.draw(paddle);
			frame.draw(Bottom);
			frame.draw(Upper1);
			frame.draw(Left);
			frame.draw(Right);
			frame.draw(Scoretxt);

			if (pause == 1)
			{
				frame.draw(pauseMessage);
			}
		}
		else if (screen == 1)
		{
			for (int i = 0; i < obstacles.size(); i++)
			{
				frame.draw(obstacles[i]);
			}
			for (int k = 0; k < ball.size(); k++)
			{

				frame.draw(ball[k]);
			}
			for (int i = 0; i < block.size(); i++)
			{
				frame.draw(block[i]);
			}
			frame.draw(paddle);
			frame.draw(Bottom);
			frame.draw(Upper1);
			frame.draw(Left);
			frame.draw(Right);
			frame.draw(Scoretxt);
			frame.draw(pauseMessage);
		}
		else if (screen == 2)
		{
			Score sb(Width, Height);
			sb.drawA(frame);
		}
		frame.display();

	}



}

void Arkanoid::runAI()

{
	srand(time(0));

	RenderWindow frame(VideoMode(Width, Height), "Arkanoid!");
	frame.setFramerateLimit(60);

	Background Upper(Vector2f(Width, 13), Vector2f(0, 0), "resources/images/topbar.png");
	Background Upper1(Vector2f(Width, 13), Vector2f(0, 63), "resources/images/topbar.png");
	Background Bottom(Vector2f(Width, 13), Vector2f(0, Height - 13), "resources/images/bottombar.png");
	Background Left(Vector2f(13, Height), Vector2f(0, 0), "resources/images/leftbar.png");
	Background Right(Vector2f(13, Height), Vector2f(Width - 13, 0), "resources/images/rightbar.png");

	Texture t1, t2, t3, th, tx1, tx2, tx3, tx4, tx5;
	t1.loadFromFile("images/block01.png");
	tx1.loadFromFile("images/block01.png");
	tx2.loadFromFile("images/block02.png");
	tx3.loadFromFile("images/block03.png");
	tx4.loadFromFile("images/block04.png");
	tx5.loadFromFile("images/block05.png");
	t2.loadFromFile("images/paddle.png");
	t3.loadFromFile("images/hamster.png");
	th.loadFromFile("images/heart.png");


	Font font;
	if (!font.loadFromFile("resources/PressStart2P.ttf"))
		exit(EXIT_FAILURE);
	Text pauseMessage;
	pauseMessage.setFont(font);
	pauseMessage.setCharacterSize(30);
	pauseMessage.setPosition(Width / 2 - 11 * 30, Height - 150);
	pauseMessage.setFillColor(Color::Green);
	pauseMessage.setString("NHAN ENTER DE VAO GAME");

	float score = 0;

	Text Scoretxt;
	if (!font.loadFromFile("resources/PressStart2P.ttf"))
		exit(EXIT_FAILURE);
	Scoretxt.setFont(font);
	Scoretxt.setFillColor(Color::White);
	Scoretxt.setCharacterSize(40);
	Scoretxt.setString(ftos(score, 1));
	Scoretxt.setPosition(Width - 300, 13);

	vector<Sprite>Heart;
	Heart.clear();
	Sprite paddle(t2);
	paddle.setScale(1.8, 1.3);
	paddle.setPosition(Width / 2 - 80, Height - 13 - 21);

	vector<Sprite>ball;
	ball.clear();
	if (ball.empty())
	{
		Sprite temp(t3);
		temp.setScale(0.3, 0.3);
		temp.setPosition(Width / 2 - 10, Height - 33 - 22 * 2);
		ball.push_back(temp);
	}

	vector<Sprite>block;
	block.clear();
	vector<Sprite>obstacles;
	obstacles.clear();
	for (int i = 0; i <= 13; i++)
	{

		for (int j = 0; j < 7; j++)
		{
			Sprite temp;

			if ((i + j) % 4 == 0)
			{
				temp.setTexture(tx3);
			}
			else if ((i + j) % 4 == 1)
			{

				temp.setTexture(tx2);
			}
			else if ((i + j) % 4 == 2)
			{
				temp.setTexture(tx3);
			}
			else if ((i + j) % 4 == 3)
			{
				temp.setTexture(tx5);
			}
			temp.setScale(1.5, 1.5);
			temp.setPosition((i + 1) * 43 * 1.5, (j + 3) * 20 * 1.5 + 15);
			block.push_back(temp);
		}
		cout << endl;

	}

	float paddleSpeed;
	vector<float> ballSpeed;
	vector<float> ballAngle;
	ballAngle.clear();
	ballSpeed.clear();
	ballSpeed.resize(100);
	ballAngle.resize(100);
	Clock clock;
	paddleSpeed = 500;
	for (int i = 0; i < 100; i++)
		ballSpeed[i] = 250;


	float modifier = 1;
	bool pause = 1;
	int screen = 0;
	while (frame.isOpen())
	{
		Event e;
		while (frame.pollEvent(e))
		{
			if (e.type == Event::Closed)
				frame.close();
			else if (e.type == Event::KeyPressed)
			{
				if (screen == 0)
				{
					if (e.key.code == (Keyboard::Enter))
					{
						if (pause)
						{
							for (int k = 0; k < 100; k++)
							{
								do {
									ballAngle[k] = -PI * (rand() % 4) / 4;
								} while ((sin(ballAngle[k]) < -0.8) || (sin(ballAngle[k]) == 0));

							}
							for (int i = 0; i < 3; i++)
							{
								Sprite temp(th);
								temp.setScale(0.2, 0.2);
								temp.setPosition(13 + 60 * i, 1);
								Heart.push_back(temp);
							}
							pause = 0;
						}
					}
					if (e.key.code == (Keyboard::Escape))
					{
						return;
					}
				}
				else if (screen == 1)
				{
					if (e.key.code == (Keyboard::Enter))
					{
						return;


					}



				}
			}
		}

		if (screen == 0)
		{
			if (pause == 0)
			{
				float deltaTime = clock.restart().asSeconds();
				//Di chuyen thanh paddle
				if (ball[0].getPosition().x + ball[0].getGlobalBounds().width / 2 < paddle.getPosition().x + 162 / 2)
				{
					if (cos(ballAngle[0]) < 0)
					{
						if (!paddle.getGlobalBounds().intersects(Left.getGlobalBounds()))
						{
							paddle.move(-deltaTime * paddleSpeed, 0);
						}
					}

				}
				else
				{
					if (cos(ballAngle[0]) > 0)
					{
						if (!paddle.getGlobalBounds().intersects(Right.getGlobalBounds()))
						{
							paddle.move(deltaTime * paddleSpeed, 0);
						}
					}

				}

				// Di chuyen bong
				for (int k = 0; k < ball.size(); k++)
				{
					float factor = ballSpeed[k] * deltaTime;
					ball[k].move(cos(ballAngle[k]) * factor, sin(ballAngle[k]) * factor);
				}

				//Xet va cham bien
				for (int k = 0; k < ball.size(); k++)
				{
					if (ball[k].getGlobalBounds().intersects(Left.getGlobalBounds()))
					{
						ballAngle[k] = PI - ballAngle[k];
						ball[k].setPosition(13, ball[k].getPosition().y);
					}
					if (ball[k].getGlobalBounds().intersects(Right.getGlobalBounds()))
					{
						ballAngle[k] = PI - ballAngle[k];
						ball[k].setPosition(Width - 17 - ballRadius * 2, ball[k].getPosition().y);
					}
					if (ball[k].getGlobalBounds().intersects(Upper1.getGlobalBounds()))
					{
						ballAngle[k] = -ballAngle[k];
						ball[k].setPosition(ball[k].getPosition().x, Upper1.getPosition().y + 13);
					}
					if (ball[k].getGlobalBounds().intersects(Bottom.getGlobalBounds()))
					{
						ballAngle[k] = -ballAngle[k];
						ball[k].setPosition(ball[k].getPosition().x, Height - 35 - ballRadius * 2);
						Heart.pop_back();
						if (ball.size() > 1)
						{
							ball.erase(ball.begin() + k);
							ballAngle.erase(ballAngle.begin() + k);
						}

					}

				}

				//Xet va cham giua ball va paddle
				for (int k = 0; k < ball.size(); k++)
				{
					if (ball[k].getGlobalBounds().intersects(paddle.getGlobalBounds()))
					{
						ballAngle[k] = -ballAngle[k];
						if (ballSpeed[k] < 350)
						{
							ballSpeed[k] = 1.1 * ballSpeed[k];
						}
						do
						{
							ball[k].move(0, -1);
						} while (ball[k].getGlobalBounds().intersects(paddle.getGlobalBounds()));

					}
				}

				//Xet va cham obstacle va block
				for (int k = 0; k < ball.size(); k++)
				{
					for (int i = 0; i < block.size(); i++)
					{
						if (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()))
						{
							if (ball[k].getPosition().y + 10 > block[i].getPosition().y + 20 * 1.5)
							{
								ballAngle[k] = -ballAngle[k];
								do
								{
									ball[k].move(0, 1);
								} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
							}
							else if (ball[k].getPosition().y + 10 < block[i].getPosition().y)
							{
								ballAngle[k] = -ballAngle[k];
								do
								{
									ball[k].move(0, -1);
								} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
							}
							else
							{
								if (ball[k].getPosition().x + 10 < block[i].getPosition().x)
								{
									ballAngle[k] = PI - ballAngle[k];
									do
									{
										ball[k].move(-1, 0);
									} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
								}
								else if (ball[k].getPosition().x + 10 > block[i].getPosition().x + 43 * 1.5)
								{
									ballAngle[k] = PI - ballAngle[k];
									do
									{
										ball[k].move(1, 0);
									} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
								}
							}
							int ran = rand() % 100;
							if (ran < 18)
							{
								modifier = 2;
							}
							else if ((ran >= 18) && (ran < 36))
							{
								modifier = 0.5;
							}
							else if ((ran >= 36) && (ran < 46))
							{
								paddle.setScale(1.8, 1.3);
							}
							else if ((ran >= 46) && (ran < 59))
							{
								paddle.setScale(2.6, 1.3);
								if (ball.size() < 3)
								{
									Sprite temp(t3);
									temp.setScale(0.3, 0.3);
									temp.setPosition(Width / 2 - 10, Height - 33 - 22 * 2);
									ball.push_back(temp);
								}
							}
							else if ((ran >= 59) && (ran < 69 + 3))
							{
								block[i].setTexture(tx4);
								obstacles.push_back(block[i]);
							}
							else if ((ran > 75) && (ran <= 87))
							{
								if (Heart.size() < 6)
								{
									Sprite temp(th);
									temp.setScale(0.2, 0.2);
									temp.setPosition(Heart[Heart.size() - 1].getPosition().x + 60, 1);
									Heart.push_back(temp);
								}

							}
							score += 500 * modifier;
							modifier = 1;
							Scoretxt.setString(ftos(score, 1));
							block.erase(block.begin() + i);
							i--;
						}
					}
					for (int i = 0; i < block.size(); i++)
					{
						if (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()))
						{
							if (ball[k].getPosition().y + 10 > block[i].getPosition().y + 20 * 1.5)
							{
								ballAngle[k] = -ballAngle[k];
								do
								{
									ball[k].move(0, 1);
								} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
							}
							else if (ball[k].getPosition().y + 10 < block[i].getPosition().y)
							{
								ballAngle[k] = -ballAngle[k];
								do
								{
									ball[k].move(0, -1);
								} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
							}
							else
							{
								if (ball[k].getPosition().x + 10 < block[i].getPosition().x)
								{
									ballAngle[k] = PI - ballAngle[k];
									do
									{
										ball[k].move(-1, 0);
									} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
								}
								else if (ball[k].getPosition().x + 10 > block[i].getPosition().x + 43 * 1.5)
								{
									ballAngle[k] = PI - ballAngle[k];
									do
									{
										ball[k].move(1, 0);
									} while (ball[k].getGlobalBounds().intersects(block[i].getGlobalBounds()));
								}
							}
							int ran = rand() % 100;
							if (ran < 18)
							{
								modifier = 2;
							}
							else if ((ran >= 18) && (ran < 36))
							{
								modifier = 0.5;
							}
							else if ((ran >= 36) && (ran < 46))
							{
								paddle.setScale(1.8, 1.3);
							}
							else if ((ran >= 46) && (ran < 59))
							{
								paddle.setScale(2.6, 1.3);
								if (ball.size() < 3)
								{
									Sprite temp(t3);
									temp.setScale(0.3, 0.3);
									temp.setPosition(Width / 2 - 10, Height - 33 - 22 * 2);
									ball.push_back(temp);
								}
							}
							else if ((ran >= 59) && (ran < 69 + 3))
							{
								block[i].setTexture(tx4);
								obstacles.push_back(block[i]);
							}
							else if ((ran > 75) && (ran <= 87))
							{
								if (Heart.size() < 6)
								{
									Sprite temp(th);
									temp.setScale(0.2, 0.2);
									temp.setPosition(Heart[Heart.size() - 1].getPosition().x + 60, 1);
									Heart.push_back(temp);
								}

							}
							score += 500 * modifier;
							modifier = 1;
							Scoretxt.setString(ftos(score, 1));
							block.erase(block.begin() + i);
							i--;
						}
					}
					for (int i = 0; i < obstacles.size(); i++)
					{
						if (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()))
						{
							if (ball[k].getPosition().y + 10 > obstacles[i].getPosition().y + 20 * 1.5)
							{
								ballAngle[k] = -ballAngle[k] + PI / 18;
								do
								{
									ball[k].move(0, 1);
								} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
							}
							else if (ball[k].getPosition().y + 10 < obstacles[i].getPosition().y)
							{
								ballAngle[k] = -ballAngle[k] + PI / 18;
								do
								{
									ball[k].move(0, -1);
								} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
							}
							else
							{
								if (ball[k].getPosition().x + 10 < obstacles[i].getPosition().x)
								{
									ballAngle[k] = PI - ballAngle[k] + PI / 18;
									do
									{
										ball[k].move(-2, 0);
									} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
								}
								else if (ball[k].getPosition().x + 10 > obstacles[i].getPosition().x + 43 * 1.5)
								{
									ballAngle[k] = PI - ballAngle[k] + PI / 18;
									do
									{
										ball[k].move(2, 0);
									} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
								}
							}

						}
					}
					for (int i = 0; i < obstacles.size(); i++)
					{
						if (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()))
						{


							if (ball[k].getPosition().y + 10 > obstacles[i].getPosition().y + 20 * 1.5)
							{
								ballAngle[k] = -ballAngle[k] + PI / 18;
								do
								{
									ball[k].move(0, 1);
								} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
							}
							else if (ball[k].getPosition().y + 10 < obstacles[i].getPosition().y)
							{
								ballAngle[k] = -ballAngle[k] + PI / 18;
								do
								{
									ball[k].move(0, -1);
								} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
							}
							else
							{
								if (ball[k].getPosition().x + 10 < obstacles[i].getPosition().x)
								{
									ballAngle[k] = PI - ballAngle[k] + PI / 18;
									do
									{
										ball[k].move(-2, 0);
									} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
								}
								else if (ball[k].getPosition().x + 10 > obstacles[i].getPosition().x + 43 * 1.5)
								{
									ballAngle[k] = PI - ballAngle[k] + PI / 18;
									do
									{
										ball[k].move(2, 0);
									} while (ball[k].getGlobalBounds().intersects(obstacles[i].getGlobalBounds()));
								}
							}

						}
					}
				}

				if (Heart.empty())
				{
					screen = 1;
					pauseMessage.setString("YOU LOSE");
					pauseMessage.setPosition(Width / 2 - 4 * 30, Height - 150);


				}
				if (block.empty())
				{
					screen = 1;
					pauseMessage.setString("YOU WIN");
					pauseMessage.setPosition(Width / 2 - 4 * 30, Height - 150);

				}

			}
		}



		frame.clear();

		if (screen == 0)
		{
			for (int k = 0; k < ball.size(); k++)
			{

				frame.draw(ball[k]);
			}
			for (int i = 0; i < block.size(); i++)
			{
				frame.draw(block[i]);
			}
			for (int i = 0; i < obstacles.size(); i++)
			{
				frame.draw(obstacles[i]);
			}
			for (int i = 0; i < Heart.size(); i++)
			{
				frame.draw(Heart[i]);
			}
			frame.draw(paddle);
			frame.draw(Bottom);
			frame.draw(Upper1);
			frame.draw(Left);
			frame.draw(Right);
			frame.draw(Scoretxt);

			if (pause == 1)
			{
				frame.draw(pauseMessage);
			}
		}
		else if (screen == 1)
		{
			for (int i = 0; i < obstacles.size(); i++)
			{
				frame.draw(obstacles[i]);
			}
			for (int k = 0; k < ball.size(); k++)
			{

				frame.draw(ball[k]);
			}
			for (int i = 0; i < block.size(); i++)
			{
				frame.draw(block[i]);
			}
			frame.draw(paddle);
			frame.draw(Bottom);
			frame.draw(Upper1);
			frame.draw(Left);
			frame.draw(Right);
			frame.draw(Scoretxt);
			frame.draw(pauseMessage);
		}
		frame.display();

	}



}
