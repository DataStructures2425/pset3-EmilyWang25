#include "problems.h"
#include<vector>
#include<iostream>
#include <chrono>
//#include "queue.h"
using namespace std;
using namespace std::chrono;


int main()
{
    //auto start0 = high_resolution_clock::now();
    int a = peopleAwareOfSecret(6,2,4);
    //auto stop0 = high_resolution_clock::now();
    cout<<a<<endl;

    //auto diff0 = duration_cast<nanoseconds>(stop0-start0); 
    //cout<<"time for native:"<<diff0.count()<<endl;
    
   // auto start = high_resolution_clock::now(); // time before cout
    //int b= peopleAwareOfSecret(4,1,3);
    //auto stop = high_resolution_clock::now(); // time after cout
    //cout<<b<<endl;

    //auto diff = duration_cast<nanoseconds>(stop-start); // get difference
    //cout <<"time for queue:"<<diff.count()<<endl;
    cout<<"Robots:"<<endl;
    vector<int> chargingTimes = {3,6,1,3,4};
    vector<int> runningCosts = {2,1,3,4,5};
    int budget = 25;
    cout<<maximumRobots(chargingTimes,runningCosts,budget)<<endl;

    
    cout<<"Leastinterval:"<<endl;
    vector<char> help{'A','A','A','B','B','B'};
    int n = 2;
    cout<<leastInterval(help,n)<<endl;
}
