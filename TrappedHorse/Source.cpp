#include<iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

struct Node
{
	int preValues;
	Node* next;
};


class Horse
{
private:

	int x;
	int y;
	int value;
	int moveCount;
	Node* head, * tail;

public:

	Horse()
	{
		x = 0;
		y = 0;
		value = 1;
		moveCount = 0;
		head = NULL;
		tail = NULL;
	}
	~Horse()
	{
		delete head;
		delete tail;
	}
	int getValue()
	{
		return value;
	}

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void setXYV(int a, int b, int v);
	void printXY();
	void horseMoves(int a);

};

void Horse::printXY()
{
	cout << "x is:" << x << "y is:" << y << endl;
}

int  returnQuarter(int a, int b)
{
	if (a == 0 && b == 0)
	{
		return 0;
	}
	else if (a > 0 && b > 0)
	{
		return 1;
	}
	else if (a < 0 && b > 0)
	{
		return 2;
	}
	else if (a < 0 && b < 0)
	{
		return 3;
	}
	else if (a > 0 && b < 0)
	{
		return 4;
	}
	else if (a > 0 && b == 0)
	{
		return 11;
	}
	else if (a == 0 && b > 0)
	{
		return 22;
	}
	else if (a < 0 && b == 0)
	{
		return 33;
	}
	else if (a == 0 && b < 0)
	{
		return 44;
	}
}

void Horse::moveRight()
{
	int quarter;
	quarter = returnQuarter(x, y);

	switch (quarter)
	{
	case 0:
		value = value + 1;
		break;
	case 1:
		if (abs(x) < abs(y))
		{
			value = value - 1;
		}
		if (abs(x) >= abs(y))
		{
			value = value + (1 + (8 * abs(x)));
		}
		break;
	case 2:
		if (abs(x) <= abs(y))
		{
			value = value - 1;
		}
		if (abs(x) > abs(y))
		{
			value = value - (5 + (8 * (abs(x) - 1)));
		}
		break;
	case 3:
		if (abs(x) <= abs(y))
		{
			value = value + 1;
		}
		if (abs(x) > abs(y))
		{
			value = value - (5 + (8 * (abs(x) - 1)));
		}
		break;
	case 4:
		if (abs(x) <= abs(y))
		{
			value = value + 1;
		}
		if (abs(x) > abs(y))
		{
			value = value + (1 + (8 * abs(x)));
		}
		break;
	case 11:
		value = value + (1 + (8 * abs(x)));
		break;
	case 22:
		value = value - 1;
		break;
	case 33:
		value = value - (5 + (8 * (abs(x) - 1)));
		break;
	case 44:
		value = value + 1;
		break;
	default:
		break;
	}
	x++;
	cout << value;
}

void Horse::moveUp()
{

	int quarter;
	quarter = returnQuarter(x, y);

	switch (quarter)
	{
	case 0:
		value = value + 3;
		break;
	case 1:
		if (abs(x) > abs(y))
		{
			value = value + 1;
		}
		if (abs(x) <= abs(y))
		{
			value = value + (3 + (8 * abs(y)));
		}
		break;
	case 2:
		if (abs(x) > abs(y))
		{
			value = value - 1;
		}
		if (abs(x) <= abs(y))
		{
			value = value + (3 + (8 * abs(y)));
		}
		break;
	case 3:
		if (abs(x) >= abs(y))
		{
			value = value - 1;
		}
		if (abs(x) < abs(y))
		{
			value = value - (7 + (8 * (abs(y) - 1)));
		}
		break;
	case 4:
		if (abs(x) > abs(y))
		{
			value = value + 1;
		}
		if (abs(x) <= abs(y))
		{
			value = value - (7 + (8 * (abs(y) - 1)));
		}
		break;
	case 11:
		value = value + 1;
		break;
	case 22:
		value = value + (3 + (8 * abs(y)));
		break;
	case 33:
		value = value - 1;
		break;
	case 44:
		value = value - (7 + (8 * (abs(y) - 1)));
		break;
	default:
		break;
	}
	y++;
	cout << value;
}

void Horse::moveLeft()
{
	int quarter;
	quarter = returnQuarter(x, y);

	switch (quarter)
	{
	case 0:
		value = value + 5;
		break;
	case 1:
		if (abs(x) <= abs(y))
		{
			value = value + 1;
		}
		if (abs(x) > abs(y))
		{
			value = value - (1 + (8 * (abs(x) - 1)));
		}
		break;
	case 2:
		if (abs(x) > abs(y))
		{
			value = value + 1;
		}
		if (abs(x) <= abs(y))
		{
			value = value + (5 + (8 * (abs(x))));
		}
		break;
	case 3:
		if (abs(x) < abs(y))
		{
			value = value - 1;
		}
		if (abs(x) >= abs(y))
		{
			value = value + (5 + (8 * (abs(x))));
		}
		break;
	case 4:
		if (abs(x)-1 <= abs(y))
		{
			value = value - 1;
		}
		/*if (abs(x) < abs(y))*/else
		{
			value = value - (1 + (8 * (abs(x) - 1)));
		}
		break;
	case 11:
		value = value - (1 + (8 * (abs(x) - 1)));
		break;
	case 22:
		value = value + 1;
		break;
	case 33:
		value = value + (5 + (8 * (abs(x))));
		break;
	case 44:
		value = value - 1;
		break;
	default:
		break;
	}
	x--;
	cout << value;
}

void Horse::moveDown()
{

	int quarter;
	quarter = returnQuarter(x, y);

	switch (quarter)
	{
	case 0:
		value = value + 7;
		break;
	case 1:
		if (abs(x) >= abs(y))
		{
			value = value - 1;
		}
		if (abs(x) < abs(y))
		{
			value = value - (3 + (8 * (abs(y) - 1)));
		}
		break;
	case 2:
		if (abs(x) >= abs(y))
		{
			value = value + 1;
		}
		if (abs(x) < abs(y))
		{
			value = value - (3 + (8 * (abs(y) - 1)));
		}
		break;
	case 3:
		if (abs(x) > abs(y))
		{
			value = value + 1;
		}
		if (abs(x) <= abs(y))
		{
			value = value + (7 + (8 * (abs(y))));
		}
		break;
	case 4:
		if (abs(x) >= 3 && abs(x)-2 >= abs(y))
		{
			value = value - 1;
		}
		/*if (abs(x) < 3 && abs(x) >= abs(y))*/else
		{
			value = value + (7 + (8 * (abs(y))));
		}
		break;
	case 11:
		if (abs(x) == 1) { value = value + 7; }
		else value = value - 1;
		break;
	case 22:
		value = value - (3 + (8 * (abs(y) - 1)));
		break;
	case 33:
		value = value + 1;
		break;
	case 44:
		value = value + (7 + (8 * abs(y)));
		break;
	default:
		break;
	}
	y--;
	cout << value;
}

void Horse::horseMoves(int a)
{
	int flag;
	/*srand(time(0));
	flag = ((rand() % 8) + 1);*/
	flag = a;
	cout << "flag is: " << flag << endl;


	switch (flag)
	{
	case 1:
		moveRight();
		moveRight();
		moveUp();
		break;
	case 2:
		moveRight();
		moveUp();
		moveUp();
		break;
	case 3:
		moveLeft();
		moveUp();
		moveUp();
		break;
	case 4:
		moveLeft();
		moveLeft();
		moveUp();
		break;
	case 5:
		moveLeft();
		moveLeft();
		moveDown();
		break;
	case 6:
		moveLeft();
		moveDown();
		moveDown();
		break;
	case 7:
		moveRight();
		moveDown();
		moveDown();
		break;
	case 8:
		moveRight();
		moveRight();
		moveDown();
		break;
	default:
		break;
	}
}

void Horse::setXYV(int a, int b, int v)
{
	x = a;
	y = b;
	value = v;
}

int main()
{
	Horse horse;
	int value;
	int getButton = 'h';
	char movement;

	value = horse.getValue();
	cout << value << endl;


	while (true)
	{
		int a;

		switch (getButton)
		{
		case'h':
			cin >> a;
			horse.horseMoves(a);
			cout << "horse moved" << endl;
			break;
		case 'r':
			horse.moveRight();
			break;
		case 'u':
			horse.moveUp();
			break;
		case 'l':
			horse.moveLeft();
			break;
		case 'd':
			horse.moveDown();
			break;
		default:
			break;
		}

		value = horse.getValue();
		cout << value << endl;
		/*getButton++;
		cin >> getButton;*/
	}
	
}