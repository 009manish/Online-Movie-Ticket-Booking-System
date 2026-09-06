class Payment {
protected:
    double amount;
public:
    Payment() : amount(0.0) {}
    virtual ~Payment() = default;
    // ABSTRACTION: pure virtual function defines the payment contract.
    virtual bool pay(double amount) = 0;
};