#include<bits/stdc++.h>
using namespace std;

class SeatLockingService{
    public:
    void lockseat(){
        cout<<"Seat Locked..."<<endl;
    }
};
class PaymentService{
    public:
    void makepayment(){
        cout<<"Payment done.."<<endl;
    }
};
class NotificationService{
    public:
    void notify(){
        cout<<"Your Seat is Booked!"<<endl;
    }
};
class LoyaltyPointsSerice{
    public:
    void gainpoints(){
        cout<<"Loyalty Points Transferred"<<endl;
    }
};
class FeedBackService{
    public:
    void feeback(){
        cout<<"Kindly give us Feedback"<<endl;
    }
};

class BookMovieTicket{
    private:
    SeatLockingService* seatLockingService;
    PaymentService* paymentService;
    NotificationService* notificationService;
    LoyaltyPointsSerice* loyaltyPointsSerice;
    FeedBackService* feedBackService;


    public:
    BookMovieTicket(){
        seatLockingService = new SeatLockingService();
        paymentService = new PaymentService();
        notificationService = new NotificationService();
        loyaltyPointsSerice = new LoyaltyPointsSerice();
        feedBackService = new FeedBackService();
    }

    void bookticket(){
        seatLockingService->lockseat();
        paymentService->makepayment();
        notificationService->notify();
        loyaltyPointsSerice->gainpoints();
        feedBackService->feeback();
    }

    ~BookMovieTicket(){
        delete seatLockingService;
        delete paymentService;
        delete notificationService;
        delete loyaltyPointsSerice;
        delete feedBackService;
    }
};

int main(){
    BookMovieTicket* book=new BookMovieTicket();
    book->bookticket();
    delete book;
    return 0;
}