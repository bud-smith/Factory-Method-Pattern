/*The Factory Method pattern*/
/*It’s very useful when you need to provide a high level of flexibility for your code.*/
/*Factory methods can be recognized by creation methods, which create objects from concrete classes,
but return them as objects of abstract type or interface.*/

#include<iostream>
#include<memory>
#include<string>

using namespace std;

/**
 * The Investment interface declares the operations that
 *all concrete investments must implement.
 */

class Investment {
public:
    //write constructor here to initialise data
    virtual ~Investment() { delete data; }
    virtual string operation() const = 0;
protected:
    int* data;
};

/**
 * Concrete investments provide various implementations of the Investment interface.
 */

class Stock : public Investment {
public:
    //write constructor here to initialise data
    string operation() const override {
        return "Result of the Stock Investment";
    }
};

class Bond : public Investment {

public:
    //write constructor here to initialise data
    string operation() const override {
        return "Result of the Bond Investment";
    }
};

class RealEstate : public Investment {

public:
    //write constructor here to initialise data
    string operation() const override {
        return "Result of the RealEstate Investment";
    }
};

/**
 * The Creator class declares the factory method that is supposed to return an
 * object of an Investment class.
 */

 /** Write a custom deleter called deleteInvestment here*/

 /*....*/

 /**
*create a templated Creator class here
*the factory method creator must return a unique_ptr
*the unique_ptr should have custom deleter
*/

class Creator {
public:
    ... creator() const
    {
        //body of the factory method
        return  ...........;
    }
};


int main()
{
    auto investment = Creator.....creator();
    cout << investment->operation() << endl;

    return 0;
}