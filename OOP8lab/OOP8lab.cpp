#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    vector<double> array = { 2.5, -4.1, 1.2, 8.0, 9.9, 7.5, -2.3, 10.0, 8.8 }; 

    int count_less_than_3 = count_if(array.begin(), array.end(), [](double x) { return x < 3; });
    cout << "Кількість елементів, менших 3: " << count_less_than_3 << endl;

    auto last_negative = find_if(array.rbegin(), array.rend(), [](double x) { return x < 0; });
    int sum_integers_after_last_negative = 0;
    if (last_negative != array.rend()) {
        for (auto it = last_negative.base(); it != array.end(); ++it) {
            sum_integers_after_last_negative += static_cast<int>(*it);
        }
    }
    cout << "Сума цілих частин елементів після останнього від'ємного: " << sum_integers_after_last_negative << endl;

    double max_value = *max_element(array.begin(), array.end()); 
    double threshold = max_value * 0.2; 

    vector<double> close_to_max;
    vector<double> others;

    for (double x : array) {
        if (abs(max_value - x) <= threshold) { 
            close_to_max.push_back(x);
        }
        else {
            others.push_back(x);
        }
    }

    close_to_max.insert(close_to_max.end(), others.begin(), others.end());
    array = close_to_max;

    cout << "Перетворений масив: ";
    for (double x : array) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
