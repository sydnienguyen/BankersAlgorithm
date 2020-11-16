//
//  customer.h
//  Banker's_Algorithm
//
//  Created by Sydnie Nguyen on 11/10/20.
//

#ifndef Customer_h
#define Customer_h
#include "bank.h"

class Bank;
extern pthread_mutex_t mutex_;

class Customer{
public:
    Customer()=default;
    Customer(int index, const ext_vector<int>&allocate, const ext_vector<int>& maximum, Bank* bank_=nullptr)
    :idx(index), alloc(allocate), max_(maximum), bank(bank_), need(max_-alloc){    }
    
    int get_id() const {return idx;}
    pthread_t* get_threadid()const {return &thread_id;}
    
    Bank* get_bank() const {return bank;}
    ext_vector<int> get_max() const {return max_;}
    
    
    bool needs_met() const {return alloc==max_;    }
    
    void alloc_req(const ext_vector<int>& req){alloc+= req; need -=req;}
    void dealloc_req(const ext_vector<int>& req){alloc-= req; need +=req;}

    void release_all_resources(){
        ext_vector<int> zero(alloc.size(),0);
        alloc -= max_=need=zero;
     //   need +=max_;
        std:: cout<<"Customer P#"<<idx<<" has released all resources and is shutting down\n";
    }
    
    int create_req(){
        
    }
    
    void show() const{
        std:: cout<< "P #"<< idx<< "     "<< alloc<< "   "<< max_<< "     "<<need<<"\n";
    }
    friend std:: ostream& operator<< (std::ostream& os, const Customer&c){
        c.show();
        return os;
    }
private:
    int idx;
    ext_vector<int> alloc;
    ext_vector<int> max_;
    ext_vector<int> need;

    Bank* bank;
    
};

#endif /* Customer_h */


