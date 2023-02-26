#include <iostream>
#include <cmath>


using namespace std;

class circle {
private:
	float radius, x_center, y_center;

public:

	void set_circle(float r, float x, float y) {

		radius = r;
		x_center = x;
		y_center = y;
	}

	float square() {
		double s = 3.14 * (radius * radius);
		return s;
	}

	bool triangle_around(float a, float b, float c) {
		double p;
			p = (a + b + c) / 2;
		double s = sqrt((p - a) * (p - b) * (p - c) * p);
		if (radius == (a + b + c) / 4 * s) return true;
		else return false;
	}

	bool triangle_in(float a, float b, float c) {
		double p = (a * b * c) / 2;
		if (radius == sqrt((p - a) * (p - b) * (p - c) * p)) return true;
		else return false;
	}

	bool check_circle(float r, float x_cntr, float y_cntr) {
		if ((r == radius && x_cntr == x_center && y_cntr == y_center) || (r + radius) > (sqrt(pow(x_cntr - x_center, 2) + pow(y_cntr - y_center, 2)))) {
			return true;
		}
		else return false;
	}

};

int main() {
	setlocale(LC_ALL, "Russian");

	circle mas[3];
	double radius, x_center, y_center;
	for (int i = 0; i < 3; i++) {
		cout << "Введите: радиус окружности, координату точки X, координату точки Y.";
		cin >> radius >> x_center >> y_center;
		mas[i].set_circle(radius, x_center, y_center);
	}
	for (int i = 0; i < 3; i++) {
		mas[i].square();
		float a, b, c;
		float r, x_cntr = 0, y_cntr = 0;
		cout << "Впишите стороны треуголника";
		cin >> a >> b >> c;
		cout << "Треугольник описан" << mas[i].triangle_around(a, b, c) << endl;
		cout << "Треугольник вписан " << mas[i].triangle_in(a,b,c) << endl;
		cout << "Введите данные второй окружности: радиус окружности, координату точки X, координату точки Y.";
		cin >> r, x_cntr, y_cntr;
		cout << " Окружность 1 пересекается с окружностью 2" << mas[i].check_circle(r, x_cntr, y_cntr);
	}
	return 0;
}
