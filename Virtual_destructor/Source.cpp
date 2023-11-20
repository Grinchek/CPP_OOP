#include <iostream>
using namespace std;


class Pizza {
public:
    virtual void CookPizza() const = 0;
};

class MilanPizza : public Pizza {
public:
    void CookPizza() const override {
        cout << "Milan Pizza is ready." << endl;
    }
};
class GreekPizza : public Pizza {
public:
    void CookPizza() const override {
        cout << "Greek Pizza is ready." << endl;
    }
};

class Sauce {
public:
    virtual void CookSauce() const = 0;
};

class MilanSauce : public Sauce {
public:
    void CookSauce() const override {
       cout << "Milan Sauce is redy."<<endl;
    }
};

class GreekSauce : public Sauce {
public:
    void CookSauce() const override {
       cout << "Greek Sauce is ready."<<endl;
    }
};

class PizzaFactory {
public:
    virtual Pizza* CreatePizza() const = 0;
    virtual Sauce* CreateSauce() const = 0;
    virtual ~PizzaFactory() =0 {};
};

class MilanPizzaFactory : public PizzaFactory {
    Pizza* milano_pizza;
public:                      
    Pizza* CreatePizza() const override {
      
        return   new MilanPizza;
    }

    Sauce* CreateSauce() const override {
        return new MilanSauce();
    }

    ~MilanPizzaFactory() override {
        cout << "Milan Pizza Factory Destructor."<<endl;
    }
};

class GreekPizzaFactory : public PizzaFactory {
public:
    Pizza* CreatePizza() const override {
        return new GreekPizza();
    }

    Sauce* CreateSauce() const override {
        return new GreekSauce();
    }

    ~GreekPizzaFactory() override {
        cout << "Greek Pizza Factory Destructor."<<endl;
    }
};

void main() {
    MilanPizzaFactory mpf;
    GreekPizzaFactory gpf;
    mpf.CreatePizza()->CookPizza();
    mpf.CreateSauce()->CookSauce();
    cout << "_______________________" << endl;
    gpf.CreatePizza()->CookPizza();
    gpf.CreateSauce()->CookSauce();
    cout << "_______________________" << endl;
    
}