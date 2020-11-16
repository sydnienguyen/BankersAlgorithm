//
//  bank.h
//  Banker's_Algorithm
//
//  Created by Sydnie Nguyen on 11/10/20.
//

#ifndef bank_h
#define bank_h
#include "customer.h"

//class Customer;
//extern pthread_mutex_t mutex_;

class Bank{
public:
    Bank() = default;
    Bank(const ext_vector<int>& available) : avail(available), customers() { }

    ext_vector<int> get_avail() const {return avail; }
    bool is_avail(const ext_vector<int> &req) const{return req<avail;}
    
    bool is_safe(int id, const ext_vector<int>&req){return true;}
    bool req_approved (int id, const ext_vector<int>&req){return true;}
    
    void add_customer(Customer* c){customers.push_back(c);  }
    
    void withdraw_resources(const ext_vector<int>& req){
        if(!is_avail(req)){
        pthread_mutex_lock(&mutex_);
        std::cerr<< "WARNING: req: "<<req<<" is not available \n";
        pthread_mutex_unlock(&mutex_);
        return;
        }
        if(is_avail(req)){avail -=req;}
    }
    
    void deposit_resources(const ext_vector<int>&req){avail+= req;}
    
    ext_vector<Customer*> get_customers() const {return customers; }
    
    void show() const {
        pthread_mutex_lock(&mutex_);
        std:: cout<<"avail:  ["<< avail << "]\n";
        pthread_mutex_unlock(&mutex_);

        for (Customer* c : customers) {
            c->show();
        }
        std::cout<<"\n";
    }
    
    
    friend std::ostream& operator<<(std::ostream& os, const Bank& be) {
        be.show();
        return os;
    }
    
private:
    ext_vector <int> avail;
    ext_vector<Customer*> customers;
};
#endif /* bank_h */
