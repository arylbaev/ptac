#include <iostream>
#include <cmath>
#include <random>
#define M_E 2.7182818284590452353602874713527
std::random_device random_device;
std::mt19937 generator(random_device());

std::pair<double, double> tests(double x, double alpha, int n) {

	std::uniform_real_distribution<> r(0, 1);
	double dist_ab = x;
	double sum = 0;
	double teor_integral = 1 - 2 * pow(M_E, -alpha * x);
	
	for (int i = 0; i < n; i++) {
		sum += ((alpha / 2) * pow(M_E, -alpha * r(generator) * x));
	}

	double resF = dist_ab * sum / n + 0.5;
	double error = abs(resF - teor_integral / teor_integral);

	return { resF, error };
}

void print(double x, double alpha, int n) {
	setlocale(LC_ALL, "Russian");
	std::pair<double, double> answer = tests(x, alpha, n);
	std::cout << "Для n = " << n << ", " << "альфа = " << alpha << ", " <<
				"x = "  << x << " значение равно: " << answer.first << " " <<
				"; ошибка равна: " <<  answer.second << std::endl;
}

int main()
{
	print(2, 2, 100);
	print(2, 2, 1000);
	print(2, 2, 10000);
	std::cout << "\n";
	print(2, 0.5, 100);
	print(2, 0.5, 1000);
	print(2, 0.5, 10000);

}
