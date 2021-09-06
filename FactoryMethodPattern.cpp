#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Investment {
public:
    // Constructor
    Investment(int x) { data = &x; }

    virtual ~Investment() {}
    virtual string operation() const = 0;
protected:
    int* data;
};

class Stock : public Investment {
public:
    // Constructor
    Stock() : Investment(0) {}
    Stock(int x) : Investment(x) {}

    string operation() const override {
        return "Result of the Stock Investment";
    }
};

class Bond : public Investment {
public:
    // Constructor
    Bond() : Investment(0) {}
    Bond(int x) : Investment(x) {}

    string operation() const override {
        return "Result of the Bond Investment";
    }
};

class RealEstate : public Investment {
public:
    // Constructor
    RealEstate() : Investment(0) {}
    RealEstate(int x) : Investment(x) {}

    string operation() const override {
        return "Result of the RealEstate Investment";
    }
};

// Deleter
auto deleteInvestment = [](Investment* x) {
    delete x; 
};

// Factory Method pattern class
template<typename T>
class Creator {
public:
    auto creator(int x = 0) const {
        return unique_ptr<Investment, decltype(deleteInvestment)>(new T(x), deleteInvestment);
    }
};


int main() {
    auto investmentStock = Creator<Stock>().creator();
    cout << investmentStock->operation() << endl;

    auto investmentStock1 = Creator<Stock>().creator(1);
    cout << investmentStock1->operation() << endl;

    auto investmentBond = Creator<Bond>().creator();
    cout << investmentBond->operation() << endl;

    auto investmentBond1 = Creator<Bond>().creator(2);
    cout << investmentBond1->operation() << endl;

    auto investmentRealEstate = Creator<RealEstate>().creator();
    cout << investmentRealEstate->operation() << endl;

    auto investmentRealEstate1 = Creator<RealEstate>().creator(3);
    cout << investmentRealEstate1->operation() << endl;
}