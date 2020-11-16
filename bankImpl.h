
#include "bank.h"
#include <string>
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class BankImpl : public Bank {
private:
  int numOfThreads;
  int numOfResources;
  
vector<int> available;
vector<vector<int>> maximum;
vector<vector<int>> allocation;
vector<vector<int>> need;
vector<bool> finished;
mutex lock;
    
    
  
    void showAllMatrices(const vector<vector<int>>& alloc, const vector<vector<int>>& max, const vector<vector<int>>& need, const string& msg)
    {
        
        
        
        
    };
    
 
    void showVector(vector<int>& vect, string msg, bool finished = false)
    {
        
        
        
    };
    
  
    bool isAvailable(const vector<int>& resource);

    void allocate(int threadNum,  vector<int>& resource){
        
        
        
        
    };
    
    void deallocate(int threadNum,vector<int>& resource){
        
        
        
        
    };
    bool hasMaximum(int threadNum){
        
        
        
        
        
    };
    bool isProcessFinished(){
        
        
        
    };
    vector<int> cpath;

    bool isSafeState(int threadNum, vector<int>& request){
        
        
        
        
        
    };
        
public:
  BankImpl(vector<int>& resources);
  void addCustomer(int threadNum, vector<int>& maxDemand, vector<int>& allocated);
  void getState() {

  int requestResources(int threadNum, vector<int>& request);
  bool releaseResources(int threadNum);
};
