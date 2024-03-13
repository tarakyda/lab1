#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class RealNumber {
private:
    double value;
    string representation;

public:
    RealNumber(double val) : value(val) {
        ostringstream oss;
        oss << val;
        representation = oss.str();
    }

    double getValue() const {
        return value;
    }

    string getRepresentation() const {
        return representation;
    }

    int countDigitsInIntegerPart() const {
        size_t dotPosition = representation.find('.');
        if (dotPosition != string::npos) {
            return dotPosition;
        }
        return representation.length();
    }

    void printParameters() const {
        cout << "Значение: " << value << ", Запись: " << representation << endl;
    }

    friend ostream& operator<<(ostream& os, const RealNumber& number);
    friend istream& operator>>(istream& is, RealNumber& number);
};

ostream& operator<<(ostream& os, const RealNumber& number) {
    os << "Значение: " << number.value << ", Запись: " << number.representation;
    return os;
}

istream& operator>>(istream& is, RealNumber& number) {
    double input;
    is >> input;
    number = RealNumber(input);
    return is;
}

int main() {
    vector<RealNumber> numbers;
    double sum = 0;
    int totalDigitsInIntegerPart = 0;

    int numCount;
    cout << "Введите количество чисел: ";
    cin >> numCount;

    for (int i = 0; i < numCount; ++i) {
        RealNumber realNumber;
        cout << "Введите  число #" << i + 1 << ": ";
        cin >> realNumber;

        numbers.push_back(realNumber);

        sum += realNumber.getValue();
        totalDigitsInIntegerPart += realNumber.countDigitsInIntegerPart();
    }

    cout << "\nВсе числа:\n";
    for (const auto& number : numbers) {
        cout << number << endl;
    }

    cout << "\nСумма чисел: " << sum << endl;
    cout << "Общее количество цифр в целых частях: " << totalDigitsInIntegerPart << endl;

    return 0;
}
