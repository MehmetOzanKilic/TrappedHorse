#include<iostream>
#include <stdlib.h>
#include <ctime>
#include <algorithm> 
using namespace std;

bool stop = false;

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
	Node* head;

public:

	Horse()
	{
		x = 0;
		y = 0;
		value = 1;
		moveCount = 0;
		head = NULL;
	}
	~Horse()
	{
		delete head;
	}
	int getValue()
	{
		return value;
	}
	void incMoveCount()
	{
		moveCount++;
	}
	void printMC()
	{
		cout << moveCount;
	}

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void setXYV(int a, int b, int v);
	void printXY();
	void horseMoves();
	void horseMoves(int a, Node* start);
	int checkMovement();
	void addValue2LL(int prevVal);
	int findBiggest();


};

void Horse::printXY()
{
	cout << "x is:" << x << "y is:" << y << endl;
}

//A function to find where the horse is before moveing
int  returnQuadrant(int a, int b)
{
	//first four represents the quadrant
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
	//last four represents the lines
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

//For horse to move in a direction it needs to know which quadrant it is in and
//where it is according to the diagonal line of that quadrant, 
//except for the fourth quadrant where the diagonal line is shifted to the right 
//for some directions.


//And also absolute values of the x and y has been used because we just need to compare 
//their magnitude against each other, their position is only important to find their quadrant.

void Horse::moveRight()
{
	int quadrant;
	quadrant = returnQuadrant(x, y);

	switch (quadrant)
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
	//cout << value;
}

void Horse::moveUp()
{

	int quadrant;
	quadrant = returnQuadrant(x, y);

	switch (quadrant)
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
	//cout << value;
}

//If we continue like we did for Right and Up directions fourt quadrant will not give us the 
//correnct results because after the spiral square finishes one of its layers it has to move one
//extra step right and this messes up with the definitions we have as our diagonals. The diaonal of
//the fourth quadrant moves right for the Left and Down direction.

void Horse::moveLeft()
{
	int quadrant;
	quadrant = returnQuadrant(x, y);

	switch (quadrant)
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
		if (abs(x) < abs(y))
		{
			value = value + 1;
		}
		if (abs(x) >= abs(y))
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
		//Diagonal moves right by one.
	case 4:
		if (abs(x) - 1 <= abs(y))
		{
			value = value - 1;
		}
		else
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
	//cout << value;
}

void Horse::moveDown()
{

	int quadrant;
	quadrant = returnQuadrant(x, y);

	switch (quadrant)
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
		//Diagonal moves right by 2.
	case 4:
		if (abs(x) - 2 >= abs(y))
		{
			value = value - 1;
		}
		else
		{
			value = value + (7 + (8 * (abs(y))));
		}
		break;
	case 11:
		if (x == 1) { value = value + 7; }
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
	//cout << value ;
}

//This is the movement function for the main horse.
void Horse::horseMoves()
{
	//Since the main horse has to go to the smallest value and cannot go to a value it has been
	//before wee need to check every possible value it might have before moveing it and sellect
	//the correct one

	//This flag keeps the move that gives the correct value.
	int flag;
	flag = checkMovement();


	switch (flag)
	{
	case 1:
		moveRight();
		moveRight();
		moveUp();
		//cout << endl;
		break;
	case 2:
		moveRight();
		moveUp();
		moveUp();
		//cout << endl;
		break;
	case 3:
		moveLeft();
		moveUp();
		moveUp();
		//cout << endl;
		break;
	case 4:
		moveLeft();
		moveLeft();
		moveUp();
		//cout << endl;
		break;
	case 5:
		moveLeft();
		moveLeft();
		moveDown();
		//cout << endl;
		break;
	case 6:
		moveLeft();
		moveDown();
		moveDown();
		//cout << endl;
		break;
	case 7:
		moveRight();
		moveDown();
		moveDown();
		//cout << endl;
		break;
	case 8:
		moveRight();
		moveRight();
		moveDown();
		//cout << endl;
		break;
	default:
		break;
	}

	//The value after the movement is added to a linked list so that the system can keep track
	//of the value it has visited before.
	addValue2LL(value);
}

//This function is for the smaller horses that will be created to check if the main horse can and 
//should move in a spesific direction

void Horse::horseMoves(int flag, Node* start)
{
	//the move that the smaller horse is going to make is given to it. 
	switch (flag)
	{
	case 1:
		moveRight();
		moveRight();
		moveUp();
		//cout << endl;
		break;
	case 2:
		moveRight();
		moveUp();
		moveUp();
		//cout << endl;
		break;
	case 3:
		moveLeft();
		moveUp();
		moveUp();
		//cout << endl;
		break;
	case 4:
		moveLeft();
		moveLeft();
		moveUp();
		//cout << endl;
		break;
	case 5:
		moveLeft();
		moveLeft();
		moveDown();
		//cout << endl;
		break;
	case 6:
		moveLeft();
		moveDown();
		moveDown();
		//cout << endl;
		break;
	case 7:
		moveRight();
		moveDown();
		moveDown();
		//cout << endl;
		break;
	case 8:
		moveRight();
		moveRight();
		moveDown();
		//cout << endl;
		break;
	default:
		break;
	}

	//After the movement the value is searched within the linked list.
	//If it is found the value in this smaller horse becomes 0.If not 
	//everything continues normally.
	Node* p = new Node;
	p = start;
	while (p != NULL)
	{
		if (value == p->preValues)
		{
			value = 0;
		}
		p = p->next;
	}

}

//This is the fuction tha creates to check which of the possible moves are available and which one has
//the smaller value. Unavailable values are converted to 0 and if all of the values are 0 that means
//horse cannot move. If there is a available value and it is the smallest move number of that value 
//returns to the Horse::horseMoves() function.
int Horse::checkMovement()
{
	int i, smallest;
	int values[8];
	int valuesMemory[8];
	Horse checkers[8];
	for (i = 0;i < 8;i++)
	{
		checkers[i].setXYV(this->x, this->y, this->value);
	}
	//small horses has been set with XYV.

	for (i = 0;i < 8;i++)
	{
		checkers[i].horseMoves(i + 1, head);
	}

	for (i = 0;i < 8;i++)
	{
		values[i] = checkers[i].getValue();
	}

	//Values are also stored in a different array so that once the other array is sorted
	//we have a place to find the move number of that value.
	for (i = 0;i < 8;i++)
	{
		valuesMemory[i] = checkers[i].getValue();
	}

	int len = sizeof(values) / sizeof(values[0]);
	sort(values, values + len);

	i = 0;
	while (values[i] == 0 && i < 8)
	{
		i++;
	}

	if (values[7] == 0)
	{
		//if the last member of the array is 0 after everything is sorted that means there are 
		//no possible moves left.
		stop = true;
	}
	smallest = values[i];
	int index;

	//Move number of the smallest value is found.
	for (index = 0;index < 8;index++)
	{
		if (valuesMemory[index] == values[i])
		{
			break;
		}
		else
		{

		}
	}

	return index + 1;
}

void Horse::setXYV(int a, int b, int v)
{
	x = a;
	y = b;
	value = v;
}

//This function adds the previosly visited values to the head of the linked list.
//Since the horse always moves close to itself it is more faster to search for 
//the next value if we insert values to the head.
void Horse::addValue2LL(int prevVal)
{
	Node* p = new Node;
	p->preValues = prevVal;
	p->next = head;
	head = p;
	p = head;
	while (p != NULL)
	{
		p = p->next;
	}
}

int Horse::findBiggest()
{
	Node* p = new Node;
	int biggest;
	p = head;
	biggest = p->preValues;

	while (p != NULL)
	{
		if (p->preValues > biggest)
		{
			biggest = p->preValues;
		}

		p = p->next;
	}
	delete p;
	return biggest;
}

//Every corner of the squares inside the spiral are the squares of the odd number.
//If we can find the first even number ,square of which is bigger than the number we give it,
//we can determine the square our number is in and this will help us run a better similation.
int findSquare(int num)
{
	int i = 0;
	while ((((i * 2) + 1) * ((i * 2) + 1)) < num)
	{
		i++;
	}

	return i;
}

int main()
{
	Horse horse;
	int value;

	value = horse.getValue();

	horse.addValue2LL(1);

	while (stop == false)
	{

		horse.incMoveCount();
		horse.horseMoves();
	}
	int biggest;
	biggest = horse.findBiggest();
	value = horse.getValue();
	cout << "Ending value is: " << value << endl;
	cout << "Horse moved: ";horse.printMC();cout << " times" << endl;
	cout << "Biggest number is: " << biggest << endl;
	cout << "Biggest number is in the square number " << findSquare(biggest) + 1;
}