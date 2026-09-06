#include <iostream>
#include <iomanip>
using namespace std;

class CashPayment : public Payment {
public:
    CashPayment() = default;
    bool pay(double amount) override {
        this->amount = amount;
        cout << "Cash payment of Rs. "<< fixed << setprecision(2)<< amount<< " received.\n";
        return true;
    }
};