
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>

#define CIRCLE 2
#define RECTANGLE 1
#define MOVE 40
using namespace std;
template<class T>
bool AABBCollision(T box1_left, T box1_top, T box1_right, T box1_bottom, T box2_left, T box2_top, T box2_right, T box2_bottom) {


	if (box1_right <= box2_left)return false;  //left
	else if (box2_right <= box1_left)return false;  //right
	else if (box1_bottom <= box2_top)return false;  //top
	else if (box2_bottom <= box1_top)return false;  //bottom
	return true;

}

int main()
{

	char move;
	int choice_number = 0;
	int whilenumber = 0;
	int circle_x = 0;
	int circle_y = 0;
	int Rectangle_x = 0;
	int Rectangle_y = 0;
	int circle_radius = 0;
	int shape1x1 = 0, shape1x2 = 0, shape1y1 = 0, shape1y2 = 0;
	int shape2x1 = 0, shape2x2 = 0, shape2y1 = 0, shape2y2 = 0;
	HDC hdc = GetWindowDC(GetForegroundWindow()); // 첫번째 도형[가만히 있을 것]
	HDC hdc2 = GetWindowDC(GetForegroundWindow());// 두번째 도형[움직일 것]
	cout << "1번 사각형 과 사각형 2번 사각형 과 동그라미";
	cin >> choice_number;
	if (choice_number == RECTANGLE) {
		cout << "첫번째 도형의 좌표들을 입력하세요";
		cin >> shape1x1 >> shape1y1 >> shape1x2 >> shape1y2;
		cout << "두번째 도형의 좌표들을 입력하세요";
		cin >> shape2x1 >> shape2y1 >> shape2x2 >> shape2y2;
		system("cls");
		Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
		Rectangle(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
	}
	else if (choice_number == CIRCLE) {
		cout << "첫번째 도형의 좌표들을 입력하세요";
		cin >> shape1x1 >> shape1y1 >> shape1x2 >> shape1y2;
		cout << "두번째 도형의 좌표들을 입력하세요";
		cin >> shape2x1 >> shape2y1 >> shape2x2 >> shape2y2;
		if (shape2x1 == shape2y1 && shape2x2 == shape2y2) {
			system("cls");
			Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
			Ellipse(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
		}

	}

	cout << "Command: a(left) / d(right) /s(down) / w(up)";

	while (whilenumber != 1) {
		cin >> move;
		system("cls");


		switch (move) {
		case'a':
		case'A':
			system("cls");
			shape2x1 -= MOVE;
			shape2x2 -= MOVE;

			{	
				if (choice_number == RECTANGLE && !(AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Rectangle(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" << "(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << ")," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;

			}
			else if (choice_number == RECTANGLE && (AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
				cout << "충돌 되었습니다.";
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Rectangle(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" << "(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," 
					<< "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;
			}
			else if (choice_number == CIRCLE && !(AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Ellipse(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" << "(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," 
					<< "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;
			}
			else if (choice_number == CIRCLE && (AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
				cout << "충돌 되었습니다.";
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Ellipse(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" << "(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 
					<< "),(" << shape2x2 << "," << shape2y2 << ")" << endl;
			}

			}break;
		case'd':
		case'D':
		{
			system("cls");
			shape2x1 += MOVE;
			shape2x2 += MOVE;
			if (choice_number == RECTANGLE && !(AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Rectangle(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" 
					<< "(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;

			}
			else if (choice_number == RECTANGLE && AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2)) {
				cout << "충돌 되었습니다.";
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Rectangle(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" << 
					"(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;
			}

			else if (choice_number == CIRCLE && !(AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Ellipse(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" <<
					"(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;
			}
			else if (choice_number == CIRCLE && (AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
				cout << "충돌 되었습니다.";
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Ellipse(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" 
					<< "(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;
			}


		}break;
		case'w':
		case'W':
		{
			system("cls");
			shape2y1 -= MOVE;
			shape2y2 -= MOVE;
			if (choice_number == RECTANGLE && !(AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Rectangle(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" << 
					"(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;

			}
			else if (choice_number == RECTANGLE && (AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
				cout << "충돌 되었습니다.";
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Rectangle(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" 
					<< "(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;
			}
			else if (choice_number == CIRCLE && !(AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Ellipse(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" 
					<< "(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;

			}
			else if (choice_number == CIRCLE && (AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
				cout << "충돌 되었습니다.";
				Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
				Ellipse(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
				cout << "Command: a(left) / d(right) /s(down) / w(up)" << 
					"(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;
			}

		}break;
		case's':
		case'S':

		{	system("cls");
			shape2y1 += MOVE;
			shape2y2 += MOVE;
		if (choice_number == RECTANGLE && !(AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
			Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);

			Rectangle(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
			cout << "Command: a(left) / d(right) /s(down) / w(up)" << 
				"(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;

		}
		else if (choice_number == RECTANGLE && (AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
			cout << "충돌 되었습니다.";
			Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
			Rectangle(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
			cout << "Command: a(left) / d(right) /s(down) / w(up)" << 
				"(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;
		}
		else if (choice_number == CIRCLE && !(AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
			Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
			Ellipse(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
			cout << "Command: a(left) / d(right) /s(down) / w(up)" << 
				"(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;

		}
		else if (choice_number == CIRCLE && (AABBCollision(shape1x1, shape1y1, shape1x2, shape1y2, shape2x1, shape2y1, shape2x2, shape2y2))) {
			cout << "충돌 되었습니다.";
			Rectangle(hdc, shape1x1, shape1y1, shape1x2, shape1y2);
			Ellipse(hdc2, shape2x1, shape2y1, shape2x2, shape2y2);
			cout << "Command: a(left) / d(right) /s(down) / w(up)" << "(" << shape1x1 << "," << shape1y1 << "),(" << shape1x2 << "," << shape1y2 << ")" << "," << "(" << shape2x1 << "," << shape2y1 << "),(" << shape2x2 << "," << shape2y2 << ")" << endl;
		}
		}break;
		case'q':
		case'Q':
			whilenumber++;
			break;
		default:
			cout << "error" << endl;
			break;
		}
	}
}

