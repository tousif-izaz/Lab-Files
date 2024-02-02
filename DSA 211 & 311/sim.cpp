//<tizaz>

#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
#include "cust.h"
#include "pqueue.h"

const int COST_PER_ITEM = 3;
const int SHOP_TIME_PER_ITEM = 2;
const int CHECKOUT_TIME_PER_ITEM = 1;
const int ROB_TIME = 7;
const int STARTING_CHECKER_CASH = 250;
// checks if integer is is legal or not
bool legal_int(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}
// reads input and saves customers to arrivalQ
void read_input(ifstream &inFile, PQueue &arrivalPQueue)
{
    string buffer;
    string name;
    string robber;
    string arrival;
    string items;
    while (inFile >> buffer)
    {
        name = buffer;
        inFile >> robber;
        inFile >> arrival;
        inFile >> items;
        bool robbed = (robber == "robber") ? true : false;
        arrivalPQueue.enqueue(new Cust(name, robbed, stoi(arrival), stoi(items)), stoi(arrival));
    }
}
//runs the simulaton
void run_simulation(int checker_count, PQueue &arrivalPQueue, int checker_break_function, ostream &os)
{
    struct Checker
    {
        int m_cash;
        int m_done_time;
        Cust *m_cust;
    };
    Checker* checkers = new Checker[checker_count];
    for (int i = 0; i < checker_count; i++)
    {
        checkers[i].m_done_time = 0;
        checkers[i].m_cash = STARTING_CHECKER_CASH;
        checkers[i].m_cust = NULL;
    }
    PQueue checkerQ, shoppingQ;
    int customer_count = arrivalPQueue.getSize();
    int clock = 0;
    for (clock = 1; customer_count > 0; clock++)
    {	
        int priorityArrival, priorityShopping;
        // checks for customers in arrivalQ and dispatches
        while (arrivalPQueue.getFirstPriority(priorityArrival) && priorityArrival == clock)
        {
            Cust *removed;
            if(arrivalPQueue.dequeue(removed)) {
                shoppingQ.enqueue(removed, priorityArrival + removed->getItems() * SHOP_TIME_PER_ITEM);
                os << clock << ": " << removed->getName() << " entered store" << endl;
            }
        }
        //checks for customers in shoppingQ
        while (shoppingQ.getFirstPriority(priorityShopping) && priorityShopping == clock)
        {
            Cust *removed;
            if(shoppingQ.dequeue(removed)) {
                checkerQ.enqueue(removed, 0);
            os << clock << ": " << removed->getName() << " done shopping" << endl;
            }
            
        }
        // assigns customers to checkers
    	for (int i = 0; i < checker_count; i++) {
        if (checkers[i].m_done_time == clock && checkers[i].m_cust != NULL) {
            int money = checkers[i].m_cust->getItems() * COST_PER_ITEM;
            if (checkers[i].m_cust->getRobber()) {
                os << clock << ": " << checkers[i].m_cust->getName() << " stole $" << checkers[i].m_cash << " and "
                   << checkers[i].m_cust->getItems() << (checkers[i].m_cust->getItems() > 1 ? " items " : " item ") 
                   << "from checker " << i << endl;
                checkers[i].m_done_time = clock + checker_break_function;
                checkers[i].m_cash = 0;
            } else {
                os << clock << ": " << checkers[i].m_cust->getName() << " paid $" << money << " for " 
                   << checkers[i].m_cust->getItems() <<  (checkers[i].m_cust->getItems() > 1 ? " items " : " item ") 
                   << "to checker " << i << endl;
                checkers[i].m_cash += money;
            }
            customer_count--;
            delete checkers[i].m_cust;
            checkers[i].m_cust = NULL;
        }
    }
    for (int i = 0; i < checker_count; i++) {
        if (checkers[i].m_done_time <= clock && checkers[i].m_cust == NULL) {
            if (!checkerQ.isEmpty()) {
                Cust *removed;
                if(checkerQ.dequeue(removed)) {
                    checkers[i].m_cust = removed;
                checkers[i].m_done_time = clock + (checkers[i].m_cust->getRobber() ? ROB_TIME : 
                                                     checkers[i].m_cust->getItems() * CHECKOUT_TIME_PER_ITEM);
                os << clock << ": " << checkers[i].m_cust->getName() << " started checkout with checker " << i << endl;
                }
                
                }
            }
        }
    }
    for(int i=0; i<checker_count; i++) {
        os << "registers[" << i <<"] = $" << checkers[i].m_cash << endl;
    }
    os << "time = " << (clock<1 ? 1 :clock) << endl;
    delete[] checkers;
}

int main(int argc, char *argv[])
{
    int checker_count, checker_break_length;
    if (argc != 5)
    {
        cerr << "Error: invalid number of command line arguments." << endl;
        exit(1);
    }
    if (!legal_int(argv[1]) || (stoi(argv[1]) < 1))
    {
        cerr << "Error: invalid number of checkers specified." << endl;
        exit(1);
    }
    else
    {
        checker_count = atoi(argv[1]);
    }
    if (!legal_int(argv[2]) || atoi(argv[2]) < 0)
    {
        cerr << "Error: invalid checker break duration specified." << endl;
        exit(1);
    }
    else
    {
        checker_break_length = atoi(argv[2]);
    }
    ifstream inFile(argv[3]);
    if (!inFile)
    {
        cerr << "Error: could not open input file <" << argv[3] << ">." << endl;
        exit(1);
    }
    ofstream outFile(argv[4]);
    if (!outFile)
    {
        cerr << "Error: could not open output file <" << argv[4] << ">." << endl;
        exit(1);
    }
    PQueue arrivalPQueue;
    read_input(inFile, arrivalPQueue);
    run_simulation(checker_count, arrivalPQueue, checker_break_length, outFile);
    return 0;
}