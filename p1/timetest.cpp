//
//  timetest.cpp
//
//
//  Created by Melody Chang on 1/14/16.
//
//
#include "CPUTimer.h"
#include "LinkedList.h"
#include "StackAr.h"
#include "CursorList.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "SkipList.h"

#include <iostream>
#include <fstream>


using namespace std;

vector<CursorNode <int> > cursorSpace (500001);


int getChoice()
{
    int userChoice;
    
    cout << "ADT Menu";
    cout << "\n0. Quit";
    cout << "\n1. LinkedList";
    cout << "\n2. CursorList";
    cout << "\n3. StackAr";
    cout << "\n4. StackLi";
    cout << "\n5. QueueAr";
    cout << "\n6. SkipList\n";
    cout << "Your choice >> ";
    cin >> userChoice;
    
    return userChoice;
} //getChoice()

void RunList(ifstream &file)
{
    string command, action;
    int data;
    
    file.ignore(1000, '\n');
    List<int> list;
    ListItr<int> itr = list.zeroth();
    
    while(file>>command)
    {
        action = command.substr(0,1);
        data = atoi(command.substr(1).c_str());
        
        if (action == "i")
        {
            list.insert(data, itr);
        }//insert
        
        if (action == "d")
        {
            list.remove(data);
        }//remove
    }
}//list()

void RunCursorList(ifstream &file)
{
    string command, action;
    int data;
    file.ignore(1000, '\n');
    
    CursorList<int> CursorList(cursorSpace);
    CursorListItr<int> CursorItr = CursorList.zeroth();
    while(file>>command)
    {
        action = command.substr(0,1);
        data = atoi(command.substr(1).c_str());
        
        if (action == "i")
        {
            CursorList.insert(data, CursorItr);
        }//insert
        
        if (action == "d")
        {
            CursorList.remove(data);
        }//remove
    }//while()
}//cursorList()

void RunStackAr(ifstream &file)
{
    string command, action;
    int data;
    file.ignore(1000, '\n');
    
    StackAr<int> stackAr(5000001);
    
    while(file>>command)
    {
        action = command.substr(0,1);
        data = atoi(command.substr(1).c_str());
        
        if (action == "i")
        {
            stackAr.push(data);
        }//push
        
        if (action == "d")
        {
            stackAr.pop();
        }//pop
    }//while()
}//stackArray()

void RunStackLi(ifstream &file)
{
    string command, action;
    int data;
    file.ignore(1000, '\n');
    
    StackLi<int> stackLi;
    
    while(file>>command)
    {
        action = command.substr(0,1);
        data = atoi(command.substr(1).c_str());
        
        if (action == "i")
        {
            stackLi.push(data);
        }//push
        
        if (action == "d")
        {
            stackLi.pop();
        }//pop
        
    }//while()
}//stackList()

void RunQueueAr(ifstream &file)
{
    string command, action;
    int data;
    file.ignore(1000, '\n');
    
    Queue<int> q(5000001);
    
    while(file>>command)
    {
        action = command.substr(0,1);
        data = atoi(command.substr(1).c_str());
        
        if (action == "i")
        {
            q.enqueue(data);
        }//enqueue
        
        if (action == "d")
        {
            q.dequeue();
        }//dequeue
    }//while()
}//queueArray()

void RunSkipList(ifstream &file)
{
    string command, action;
    int data;
    file.ignore(1000, '\n');
    
    file >> command;
    action = command.substr(0,1);
    data = atoi(command.substr(1).c_str());
    
    SkipList<int> s(-1, 5000001);
    while(file>>command)
    {
        action = command.substr(0,1);
        data = atoi(command.substr(1).c_str());
        if (action == "i")
        {
            s.insert(data);
        }//insert
        
        if (action == "d")
        {
            s.deleteNode(data);
        }//delete
    }//while()
} //skipList()


int main()
{
    string filename;
    CPUTimer ct;
    int choice;
    
    cout << "Filename >> ";
    cin >> filename;
    ifstream file(filename.c_str(), ifstream::in);
    
    do //code from TA
    {
        choice = getChoice();
        ct.reset();
        
        switch (choice)
        {
            case 1: RunList(file); break;
            case 2: RunCursorList(file); break;
            case 3: RunStackAr(file); break;
            case 4: RunStackLi(file); break;
            case 5: RunQueueAr(file); break;
            case 6: RunSkipList(file); break;
        } //switch based on user choice
        cout << "CPU time: " << ct.cur_CPUTime() << endl;
    } while(choice > 0);
     cout << "hello" << endl;
    
    return 0;
}//main()
