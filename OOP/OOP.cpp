#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;
# define M_PI           3.14159265358979323846  /* pi */
//Create a land sales class
class SellingLand {
protected:
    string Name;
    string Address;
public:
    SellingLand(string _Name = "Anh Kiet", string _Address = "Address 1") {
        Name = _Name;
        Address = _Address;
    }
    virtual double Perimeter() = 0; //create a purely virtual Perimeter layer 
    virtual double Acreage() = 0; //create a purely virtual Acreage layer
    virtual double landMoney() = 0; //create a purely virtual landMoney layer
    void xuat() {
        cout << Name << endl;
        cout << Address << endl;
        cout << Perimeter() << endl;
        cout << Acreage() << endl;
        cout << landMoney() << " USD" << endl;
    }
};

//Create a circle land class
class Circle : public SellingLand {
    double radius;
public:
    Circle(string _Name = "Anh Kiet", string _Address = "Address 1", double _radius = 2)
        : SellingLand(_Name, _Address)
    {
        radius = _radius;
    }

    double Perimeter() { return M_PI * 2 * radius; }
    double Acreage() { return M_PI * radius * radius; }
    double landMoney() {
        if (Address == "Address 1") {
            return Acreage() * 70;
        }
        else if (Address == "Address 2") {
            return Acreage() * 30;
        }
        else if (Address == "Address 3") {
            return Acreage() * 40;
        }
        else {
            return Acreage() * 50;
        }
    }

};

//Create a quadrilateral land class
class Quadrilateral : public SellingLand {
    double a, b, e, d;
public:
    Quadrilateral(string _Name = "Anh Kiet", string _Address = "Address 1", double _a = 2, double _b = 3, double _c = 4, double _d = 1)
        : SellingLand(_Name, _Address)
    {
        a = _a; b = _b; e = _c; d = _d;
    }

    double Perimeter() { return a + b + e + d; }
    double Acreage()
    {
        double p = (a + b + e + d) / 2;
        double res = sqrt((p - a) * (p - b) * (p - e) * (p - d));
        return res;
    }
    double landMoney() {
        if (Address == "Address 1") {
            return Acreage() * 70;
        }
        else if (Address == "Address 2") {
            return Acreage() * 30;
        }
        else if (Address == "Address 3") {
            return Acreage() * 40;
        }
        else {
            return Acreage() * 50;
        }
    }
};

int main() {
    string name;
    string address;
    char ch;
    vector<SellingLand*> sl;
    while (cin >> ch) {
        cin.ignore();
        getline(cin, name);
        getline(cin, address);
        if (ch == 'C') {
            double r;
            cin >> r;
            sl.push_back(new Circle(name, address, r));
        }
        if (ch == 'Q') {
            double a, b, c, d;
            cin >> a >> b >> c >> d;
            sl.push_back(new Quadrilateral(name, address, a, b, c, d));
        }
    }

    for (int i = 0; i < sl.size(); i++) {
        cout << i + 1<<", ";
        sl[i]->xuat();
        cout << endl;
    }

    return 0;
}
