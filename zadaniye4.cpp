#include <iostream>
using namespace std;


class IVehicle {
public:
    virtual void Drive() = 0;
    virtual void Refuel() = 0;
    virtual ~IVehicle() {}
};


class Car : public IVehicle {
    string brand, model, fuel;
public:
    Car(string b, string m, string f) : brand(b), model(m), fuel(f) {}

    void Drive() {
        cout << "Автомобиль " << brand << " " << model << " едет\n";
    }

    void Refuel() {
        cout << "Заправка " << fuel << endl;
    }
};


class Motorcycle : public IVehicle {
    string type;
    int engine;
public:
    Motorcycle(string t, int e) : type(t), engine(e) {}

    void Drive() {
        cout << "Мотоцикл типа " << type << " едет\n";
    }

    void Refuel() {
        cout << "Заправка мотоцикла\n";
    }
};


class Truck : public IVehicle {
    int capacity, axles;
public:
    Truck(int c, int a) : capacity(c), axles(a) {}

    void Drive() {
        cout << "Грузовик едет, грузоподъемность " << capacity << endl;
    }

    void Refuel() {
        cout << "Заправка грузовика\n";
    }
};


class Bus : public IVehicle {
    int seats;
public:
    Bus(int s) : seats(s) {}

    void Drive() {
        cout << "Автобус едет, мест: " << seats << endl;
    }

    void Refuel() {
        cout << "Заправка автобуса\n";
    }
};


class VehicleFactory {
public:
    virtual IVehicle* CreateVehicle() = 0;
    virtual ~VehicleFactory() {}
};


class CarFactory : public VehicleFactory {
public:
    IVehicle* CreateVehicle() {
        string b, m, f;
        cout << "Марка: ";
        cin >> b;
        cout << "Модель: ";
        cin >> m;
        cout << "Тип топлива: ";
        cin >> f;
        return new Car(b,m,f);
    }
};


class MotorcycleFactory : public VehicleFactory {
public:
    IVehicle* CreateVehicle() {
        string t;
        int e;
        cout << "Тип мотоцикла: ";
        cin >> t;
        cout << "Объем двигателя: ";
        cin >> e;
        return new Motorcycle(t,e);
    }
};


class TruckFactory : public VehicleFactory {
public:
    IVehicle* CreateVehicle() {
        int c,a;
        cout << "Грузоподъемность: ";
        cin >> c;
        cout << "Количество осей: ";
        cin >> a;
        return new Truck(c,a);
    }
};


class BusFactory : public VehicleFactory {
public:
    IVehicle* CreateVehicle() {
        int s;
        cout << "Количество мест: ";
        cin >> s;
        return new Bus(s);
    }
};


int main() {
    int choice;
    VehicleFactory* factory = nullptr;

    cout << "1-Car 2-Motorcycle 3-Truck 4-Bus: ";
    cin >> choice;

    if(choice==1) factory = new CarFactory();
    else if(choice==2) factory = new MotorcycleFactory();
    else if(choice==3) factory = new TruckFactory();
    else if(choice==4) factory = new BusFactory();

    if(factory) {
        IVehicle* v = factory->CreateVehicle();
        v->Drive();
        v->Refuel();
    }

    return 0;
}
