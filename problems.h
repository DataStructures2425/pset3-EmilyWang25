#include <iostream>
#include <vector> 
#include <map>
#include "queue.h"
using namespace std;

/*
    Return the number of people aware of the secret after
    n days (modulo 10^9 + 7)
*/


int peopleAwareOfSecret(int n, int delay, int forget) 
{
    long long modFactor = 1000000007;
    /*Queue<pair<int,int>> q1;
    int sum = 0;
    pair<int,int> help;
    help.first = 1;
    help.second= 1+forget;
    q1.enqueue(help);
    while(!q1.isEmpty()){
       // cout<<"fine"<<endl;
       // cout<<sum<<endl;
       //cout<<q1.front().first<<endl;
        if(q1.front().first+delay>n){
            if(q1.front().second>n){
                sum++;
            }
            q1.dequeue();
            continue;
        }


        if(q1.front().second <= n){
                for(int i= q1.front().first+delay;i<q1.front().second;i++){

                     help.first = i;
                     help.second = i+forget;
                     q1.enqueue(help);
                     //cout<<"ok"<<endl;

                }
            
            q1.dequeue();
        }else{
            sum++;
                for(int i= q1.front().first+delay;i<=n;i++){

                     help.first = i;
                     help.second = i+forget;
                     q1.enqueue(help);
                    // cout<<"yes"<<endl;
                }
            q1.dequeue();
        }
        
    }

    return sum%modFactor;*/
    int curr = 0;
    long long ans=0;
    int sum = 0;
    Queue<pair<int,int>> q1;
    Queue<pair<int,int>> spreaders;
    pair<int,int> help;
    help.first = 1;
    help.second = 1;
    q1.enqueue(help);
    spreaders.enqueue(help);
    for(int i=2;i<=n;i++){
        pair<int,int> help1;
        if(q1.front().second + forget <= i){
            curr -= q1.front().first;
            //cout<<curr<<endl;
            q1.dequeue();
        }

        if(spreaders.front().second + delay <= i){
            curr+= spreaders.front().first;
           // cout<<curr<<endl;
            spreaders.dequeue();
            
        }
             
        //cout<<"i:"<<i<<" "<<"curr:"<<curr<<endl;
        if(i+forget>n){
            ans = (ans + curr) % modFactor;
        }
        help1.first = curr;
        help1.second = i;
        q1.enqueue(help1);
         spreaders.enqueue(help1);
       
    }


    return ans;

    // YOUR CODE HERE

}

/*
    Return maximum number of robots that can be run while
    staying within the budget
*/
int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) 
{
    // YOUR CODE HERE
    Deque<int> robots;
    Deque<int> Max_charge;
    int n = runningCosts.size();
    int num = 0;
    int cost;
    int max_charge = 0;
    int max_ans=0;
    int k = 0;
    int sum = 0;
    while(num<n){

        robots.push_back(num);
       k++;

       while(!Max_charge.isEmpty()&&chargeTimes[num]>chargeTimes[Max_charge.rear()]){
           Max_charge.pop_back();
       }
       Max_charge.push_back(num);
      // cout<<num<<endl;
       //cout<<"Max_charge"<<Max_charge.front()<<endl;

        sum+= runningCosts[num];
        cost = chargeTimes[Max_charge.front()]+ k*sum;
        //cout<<"cost "<<cost<<endl;

        while(cost>budget){
            //cout<<"hey"<<endl;
                sum-=runningCosts[robots.front()];
                k--;
                if(!Max_charge.isEmpty()&&robots.front()>=Max_charge.front()){
                    Max_charge.pop_front();
                }
                robots.pop_front();
                if(robots.isEmpty()){
                    k=0;
                   //cout<<"right"<<endl;
                    break;
                }
                cost = chargeTimes[Max_charge.front()] + k*sum;
               // cout<<"cost1 "<<cost<<endl;


        }

        if(k>max_ans){
            max_ans = k;
        }
       // cout<<"max_ans"<<max_ans<<endl;
        num++;
    }
    return max_ans;
}

/*
    Return smallest number of intervals required to complete
    all tasks
*/
int leastInterval(vector<char>& tasks, int n) 
{
    int count=0;
    int help = 0;
    char help1;
    int currentlevel = 0;
    map<char,int> frequency;
    for(int i=0;i<tasks.size();i++){
        for(int j=i+1;j<tasks.size();j++){
            if(tasks[j]<tasks[i]){
                help1 = tasks[j];
                tasks[j]=tasks[i];
                tasks[i]=help1;
            }
        }
    }
    PriorityQueue<char> q1= PriorityQueue(tasks[0],0);
    frequency[tasks[0]]++;
    for(int i=1;i<tasks.size();i++){
        //cout<<tasks[i];
        //cout<<frequency[tasks[i]]<<endl;
        q1.push(tasks[i],frequency[tasks[i]]);
        frequency[tasks[i]]++;
    }
 
    while(!q1.isEmpty()){
        if(q1.levelpeek() > currentlevel && help<n+1){
            //cout<<"idle"<<endl;
            count++;
            help++;
            continue;
        }
        if(q1.levelpeek() > currentlevel){
            help=0;
        }
        count++;
        help++;
        currentlevel = q1.levelpeek();
        q1.pop();
        //cout<<q1.pop()<<endl;;
        //cout<<count<<endl;
    }

    return count;
    // YOUR CODE HERE
}
