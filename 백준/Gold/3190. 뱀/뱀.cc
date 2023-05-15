#include <bits/stdc++.h>

using namespace std;

enum class Snake_Dir
{
	DOWN,
	RIGHT,
	UP,
	LEFT,
};

struct Point
{
public:
	int x;
	int y;

public:
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	bool operator == (Point _Data)
	{
		if (x == _Data.x && y == _Data.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

Point CalculateNextHeadPos(Point _point, Snake_Dir _dir)
{
	switch (_dir)
	{
	case Snake_Dir::DOWN:
	{
		return Point(_point.x, _point.y + 1);
	}
		break;
	case Snake_Dir::RIGHT:
	{
		return Point(_point.x + 1, _point.y);
	}
		break;
	case Snake_Dir::UP:
	{
		return Point(_point.x, _point.y - 1);
	}
		break;
	case Snake_Dir::LEFT:
	{
		return Point(_point.x - 1, _point.y);
	}
		break;
	default:
		break;
	}
}

void RotateHeadDir(Snake_Dir& _dir, char _order)
{
	// 오른쪽 회전
	if (_order == 'L')
	{
		_dir = (Snake_Dir)(((int)_dir + 1) % 4);
	}

	// 왼쪽 회전
	else if (_order == 'D')
	{
		if ((int)_dir - 1 < 0)
			_dir = Snake_Dir::LEFT;
		else
		{
			_dir = (Snake_Dir)(((int)_dir - 1) % 4);
		}
	}
}

int main()
{
	int board_size;
	int apple_count;
	int snake_length = 1;

	list<Point> Snake_Occupied;
	Snake_Occupied.push_back(Point(1, 1));

	Snake_Dir CurSnakeDir = Snake_Dir::RIGHT;

	std::cin >> board_size;
	std::cin >> apple_count;

	int** board = new int*[board_size + 1];

	// 게임 판 생성
	for (int i = 0; i <= board_size; ++i)
		board[i] = new int[board_size + 1] {0};

	
	int NewApple_x, NewApple_y;

	// 사과 세팅
	for (int i = 1; i <= apple_count; ++i)
	{
		std::cin >> NewApple_x >> NewApple_y;

		board[NewApple_x][NewApple_y] = 1;
	}

	int move_order;
	std::cin >> move_order;

	deque<pair<int, char>> Move_Order_Queue;


	// 이동 정보 대입
	for (int i = 1; i <= move_order; ++i)
	{
		int aftertime;
		char dir;

		std::cin >> aftertime >> dir;

		Move_Order_Queue.push_back(make_pair(aftertime, dir));
	}

	int Game_Played_time = 0;


	// 보드판 출력하기
	//for (int i = 1; i <= board_size; ++i)
	//{
	//	for (int j = 1; j <= board_size; ++j)
	//	{
	//		std::cout << board[i][j] << " ";
	//	}

	//	std::cout << endl;
	//}



	// 게임 동작
	while (true)
	{
		// 머리 방향 전환
		if (Move_Order_Queue.size() != 0 && Move_Order_Queue.front().first - Game_Played_time == 0)
		{
			RotateHeadDir(CurSnakeDir, Move_Order_Queue.front().second);
			//Game_Played_time += 1;
			Move_Order_Queue.pop_front();


		}
		 

		/*if (Move_Order_Queue.size() != 0)
		{
			auto iter = Move_Order_Queue.begin();
			iter->first = iter->first - 1;

		}*/


		// 갈 수 있는지 먼저 확인
		Point NextHeadPos = CalculateNextHeadPos(Snake_Occupied.front(), CurSnakeDir);

		// 다음 위치가 자신의 몸과 부딫히는 경우
		for (list<Point>::iterator iter = Snake_Occupied.begin(); iter != Snake_Occupied.end(); ++iter)
		{
			if (NextHeadPos == *iter)
			{
				std::cout << Game_Played_time + 1<< std::endl;
				return 0;
			}
		}

		// 다음 위치가 벽 바깥으로 나가는 경우
		if (NextHeadPos.x > board_size || NextHeadPos.y > board_size || NextHeadPos.x <= 0 || NextHeadPos.y <= 0)
		{
			std::cout << Game_Played_time + 1 << std::endl;
			return 0;
		}

		// 여기 이후부터는 뱀이 다음위치로 움직일 수 있음


		// 다음 위치에 사과가 있는경우
		if (board[NextHeadPos.y][NextHeadPos.x] == 1)
		{
			//std::cout << "NextPos" << NextHeadPos.x << " " << NextHeadPos.y << std::endl;

			// 사과를 먹고
			board[NextHeadPos.y][NextHeadPos.x] = 0;

			// 뱀의 길이를 늘린다.
			Snake_Occupied.push_front(NextHeadPos);

			// 시간 경과
			Game_Played_time += 1;
		}


		// 다음 위치에 사과가 없는경우
		else
		{
			//std::cout << "NextPos" << NextHeadPos.x << " " << NextHeadPos.y << std::endl;

			Snake_Occupied.push_front(NextHeadPos);
			Snake_Occupied.pop_back();

			Game_Played_time += 1;
		}

		 
		
	}

	return 0;
}