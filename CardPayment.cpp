#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CardPayment : public Payment {
private:
    string cardNumber;
public:
    explicit CardPayment(const string& cardNumber)
        : cardNumber(cardNumber) {}

    bool pay(double amount) override {
        this->amount = amount;
        bool valid = cardNumber.size() >= 4;
        if (valid) {
            cout << "Card payment of Rs. "<< fixed << setprecision(2)<< amount<< " successful.\n";
        }
        return valid;
    }
};