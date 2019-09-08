#include<iostream> 
#include<time.h> 
#include <string>
#include <math.h>
#include<algorithm>
#include <random>
#include <vector>
using namespace std;
#define MAX_NUMBER 11

struct Point {
	int x = 0;
	int y = 0;
	int z = 0;
	bool isused = false;
	float length = 0.0f;
public:
	bool GetUsed()const { return isused; }
	void SetUsed(const bool value) { isused = value; }

};
bool operator<(const Point& lhs, const Point& rhs) 
	{ return lhs.length < rhs.length; }

void SetVectorLength(Point& p) {
	float result = sqrt((p.x*p.x) + (p.y*p.y) + (p.z*p.z));
	p.length = result;
}


int main() {

	Point pointList;
	vector <Point>savelist;
	pointList.x = 0;
	pointList.y = 0;
	pointList.z = 0;
	int Whilenumber = 0;
	char c;
	cout << "+ x y z : 리스트 맨위 입력" << endl;
	cout << "- 리스트 맨위 삭제" << endl;
	cout << "e x y z : 리스트 맨 아래 입력" << endl;
	cout << "l 리스트 길이 출력" << endl;
	cout << "d 리스트 맨아래 삭제" << endl;
	cout << "c 리스트를 비움 " << endl;
	cout << "m 원점에서 가장 먼 거리 좌표 출력" << endl;
	cout << "n 원점에서 가장 가까운 거리 좌표 출력" << endl;
	cout << "q 프로그램 종료" << endl;
	while (Whilenumber != 1) {
		cin >> c;
		switch (c) {
		case'+': {
			cout << "x , y ,z 입력" << endl;
			cout << endl << endl;
			cin >> pointList.x >> pointList.y >> pointList.z;
			auto falseIndex = std::find_if(savelist.begin(), savelist.end(), [](const Point& lhs) {return (!lhs.GetUsed()); });

			if (falseIndex != savelist.end() && savelist.size() >= MAX_NUMBER - 1) {
				falseIndex->x = pointList.x;
				falseIndex->y = pointList.y;
				falseIndex->z = pointList.z;
				SetVectorLength(*falseIndex);
				falseIndex->SetUsed(true);
			}
			else if (savelist.size() < MAX_NUMBER) {
				SetVectorLength(pointList);
				pointList.SetUsed(true);
				savelist.push_back(pointList);
			}
			if (savelist.size() < MAX_NUMBER) {
				int indexnumber = savelist.size() - 1;
				for (auto i = savelist.rbegin(); i != savelist.rend(); i++) {
					if (i->GetUsed()) {
						cout <<   indexnumber <<   "   l " << i->x << " " << i->y << " " << i->z << "   " << endl;
					}
					else {
						cout  << indexnumber << "   l " << std::endl;
					}
					indexnumber--;
				}
			}
			else
				cout << "넘어 섰습니다." << endl;
			break;
		}
		case'-': {
			savelist.pop_back();
			cout << endl;
			int indexnumber = savelist.size() - 1;
			for (auto i = savelist.rbegin(); i != savelist.rend(); i++) {
				std::cout << indexnumber << "   l " << i->x << " " << i->y << " " << i->z << "   " << endl;
				indexnumber--;
			}
			break;
		}
		case'd':
		case'D': {
			auto iter = savelist.begin();
			iter->SetUsed(false);
			cout << endl;
			int indexnumber = savelist.size() - 1;
			for (auto i = savelist.rbegin(); i != savelist.rend(); i++) {

				if (i->GetUsed()) {
					
					cout << indexnumber << "   l " << i->x << " " << i->y << " " << i->z << "   " << endl;

				}
				else {
					cout << indexnumber << "   l " << std::endl;
				}
				indexnumber--;

			}
			break;
		}
		case'C':
		case'c':
			savelist.clear();
			break;
		case'E': {
		case'e': {
			if (savelist.size() < MAX_NUMBER) {
				cout << "x , y ,z 입력" << endl;
				cout << endl << endl;
				cin >> pointList.x >> pointList.y >> pointList.z;
				SetVectorLength(pointList);
				auto it = savelist.begin();
				savelist.insert(it, pointList);

				int indexnumber = savelist.size() - 1;
				for (auto i = savelist.rbegin(); i != savelist.rend(); i++) {
					cout << indexnumber << "   l " << i->x << " " << i->y << " " << i->z << "   " << endl;
					indexnumber--;

				}
			}
			else
				cout << "넘어 섰습니다." << endl;
			break;
		}
		}
		case'l':
		case'L': {
			cout << "length of list : " << savelist.size() - 2 << endl;
		}

				 break;
		case 'M':
		case 'm': {
			auto farPoint = std::max_element(savelist.begin(), savelist.end(), [](const Point& lhs, const Point& rhs) {return lhs < rhs; });
			cout << "가장 먼 좌표값" << "(" << farPoint->x << ", " << farPoint->y << " , " << farPoint->z<<")";
			break;
		}
		case 'N': {
		case 'n': {
			auto farPoint2 = std::min_element(savelist.begin(), savelist.end(), [](const Point& lhs, const Point& rhs) {return lhs < rhs; });
			cout << "가장 가까운 좌표값" << "(" << farPoint2->x << ", " << farPoint2->y << " , " << farPoint2->z << ")";
			break;
		}
		}
		case'q':
		case'Q':
			Whilenumber += 1;
			cout << "종료 합니다." << endl;
			break;
		default: {
			std::cout << "잘못된 명령어를 입력했습니다." << std::endl;
			break;
		}
		}
	}
}