// You are working on a project for a digital marketplace that specializes in selling electronic gadgets.
//  To streamline the process, you have designed a system using object-oriented principles.
// Gadget is the abstract base class. MobilePhone and Laptop are classes inherited from the Gadget class.
//  Customer is a class that uses MobilePhone and Laptop objects.
// • Gadget: Contains data members such as price (float) and basic behaviors like void Buy() and void Sell().
// • MobilePhone and Laptop: They have additional attributes like model name (string) and specifications. They also implement the Buy and Sell methods.
// • Customer: Inherits from MobilePhone and Laptop classes. It has data members for customer name and ID. It implements a Display method to show customer details and the number of gadgets they own.
// You have gadgets like iPhone, Samsung Galaxy, MacBook, and Dell XPS listed on your marketplace with arbitrary prices.
// Customers such as Ali, Maryam, and Maaz are using the platform to buy and sell gadgets.
// In the main function, you need to:
// 1. Ali buys an iPhone.
// 2. Maryam sells her Dell XPS.
// 3. Maaz buys two Samsung Galaxy phones.
// 4. Call the display function to show the final details of customers and listed gadgets using the abstract base class pointer.
#include <iostream>
#include <string>
using namespace std;
#include <vector>
class Gadget
{
private:
    float price;

public:
    float getprice()
    {
        return price;
    };
    virtual void buy() =0;
    virtual void sell() =0;
    Gadget(){};
    Gadget(float gadgetprice): price(gadgetprice) {};
    virtual ~Gadget() {};
};

class MobilePhone : virtual public Gadget
{
public:
    string modelName;
    MobilePhone(){};
    MobilePhone(float mobPrice, string mobname) : Gadget(mobPrice) , modelName(mobname) {};
    void buy() override {
    cout<<"model "<<modelName<<" bought for "<<getprice()<<endl;
    };
    void sell() override {
        cout<<"model "<<modelName<<" sold for "<<getprice()<<endl;
    };
    ~MobilePhone() {};
};

class Laptop : virtual public Gadget
{
public:
    string mName;
    Laptop(){};
    Laptop(float lapPrice , string lapname) : Gadget(lapPrice), mName(lapname) {};
    void buy() override {
        cout<<"model "<<mName<<" bought for "<<getprice()<<endl;
    };
    void sell() override {
        cout<<"model "<<mName<<" sold for "<<getprice()<<endl;

    };
    ~Laptop() {};
};

class Customer
{
private:
    string customerName;
    int customerID;
    vector<Gadget*> gadgetcount;

public:
    Customer(string name, int ID) : customerName(name), customerID(ID), gadgetcount(0){};
    ~Customer() {};
  
    string cusName()
    {
        return customerName;
    }
    int cusID()
    {
        return customerID;
    }
    void display()
    {
        cout << cusName()<<" with ID "<<cusID() << " owns " <<gadgetcount.size()<<" gadgets " << endl;
    }
    void buygadget(Gadget* g){
      g->buy();
      gadgetcount.push_back(g);
    };
    void sellgadget(Gadget* g){
     g->sell();
    };
};

int main() {
    MobilePhone m1(1000.67, "iphone");
    Laptop l1 (1600.45, "Dell xps");
    MobilePhone m2(980.23, "samsung galaxy");
    Customer c1("Ali", 123);
    Customer c2("Maryam", 344);
    Customer c3("Maaz", 678);
    c1.buygadget(&m1);
    c2.sellgadget(&l1);
    c3.buygadget(&m2);
    c3.buygadget(&m2);
    c1.display();
    c2.display();
    c3.display();

}
