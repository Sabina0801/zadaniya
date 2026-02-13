#include <iostream>
using namespace std;

class TicketDetails {
    string movie;
    int seat;
public:
    TicketDetails(string m,int s):movie(m),seat(s){}
    string GetInfo() {
        return movie + " seat " + to_string(seat);
    }
};

class PaymentDetails {
    string card;
public:
    PaymentDetails(string c):card(c){}
    string GetCard() {
        return card;
    }
};

class ProcessingCenterGateway {
public:
    void Pay(PaymentDetails& pd,double amount) {
        cout<<"Оплата "<<amount<<" картой "<<pd.GetCard()<<endl;
    }
};

class TicketService {
public:
    void BuyTicket(TicketDetails& td) {
        cout<<"Билет куплен: "<<td.GetInfo()<<endl;
    }
};

int main() {
    string movie,card;
    int seat;

    cout<<"Фильм: ";
    cin>>movie;
    cout<<"Место: ";
    cin>>seat;
    cout<<"Карта: ";
    cin>>card;

    TicketDetails ticket(movie,seat);
    PaymentDetails payment(card);
    ProcessingCenterGateway gateway;
    TicketService service;

    gateway.Pay(payment,5000);
    service.BuyTicket(ticket);

    return 0;
}
