#include<time.h>
#include<iostream>
#include<string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib> 
#include<stdio.h> 
#include <thread>
#include "heap.cpp"

using namespace std;
#define REL_TIME true
struct Qitem{
    string name;
    time_t time;
    int priority=0; 
};

 time_t inline strToTime(string s){
        std::tm t = {};
    std::istringstream ss(s);
    ss.imbue(std::locale());
    //2017​/​02​/​10​ ​5​:​00​
    ss >> std::get_time(&t, "%Y/%m/%d %H:%M");
    if (ss.fail()) {
        std::cout << "Parse failed, Date formate isn't parsable format\n";
        return -1;
    } else {
        
        //std::cout << std::put_time(&t, "%c") << '\n';
        return mktime(&t);
    }  
}
void sleep_me(double time);
void runQueue(heap<struct Qitem>* HQueue,time_t currtime);

int main(int argc, char *argv[])
{
    if(argc !=3 )
    {
        cout << "arguments needed 2/n run using cmd ./a.out input.txt \"2019/2/10 4:59\"" << "\n"; 
        
        return -1;
    }
    else{

    }

    heap<struct Qitem> HQueue;
    std::string delimiter = ",";
    std::string token;
     std::ifstream input( argv[1] );
     time_t currtime = strToTime(argv[2]);
    size_t temp,temp2;
      for (std::string line=""; std::getline(input, line);) {
         struct Qitem item;
           temp = line.find(delimiter,0);  //name
           if(temp != string::npos){
            item.name = line.substr(0,temp );
           }
           temp++;
            temp2 = line.find(delimiter,temp); //date 
            temp++;
            if(temp2 !=string::npos)
            {token = line.substr(temp,temp2-temp  );
            temp2++;
            string s = line.substr(temp2);
                   item.priority = stoi(s);
            }
            else 
            {
                token = line.substr(temp);
               
            }
            item.time = strToTime(token);

            //std::cout << item.name <<"   "<<token <<"  "<< item.priority <<"  "<<'\n';
        HQueue.insert(item);
    }

    //HQueue.print_heap();
    runQueue(& HQueue,currtime);
    return 0;
}

void runQueue(heap<struct Qitem>* HQueue,time_t currtime )
{
    struct Qitem item ;

    while(HQueue->isEmpty())
    {
         item =  HQueue->popOut();
         struct tm * ptm;
         double seconds = difftime(item.time,currtime);
         if(seconds>0){sleep_me(seconds);
         currtime = item.time;
         }
            ptm = localtime ( &item.time );
    //std::cout << item.name <<"   "<<item.time <<"  "<< item.priority <<"  "<<HQueue->size()<<'\n';
          std::cout <<"Current time ["<< 1900+ptm->tm_year<<"/"<<1+ptm->tm_mon<<"/"<<ptm->tm_mday <<"], Event "<<item.name <<"  Processed\n";

    }
}
void sleep_me(double time)
{
     std::chrono::seconds sec((long)time);
    std::this_thread::sleep_for(sec);
}