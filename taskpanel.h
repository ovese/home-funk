#ifndef TASKPANEL_H
#define TASKPANEL_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <vector>

//#include <random>

class TaskPanel
{
    public:
        TaskPanel(){std::cout<<"Initializing program"<<std::endl;}
        virtual ~TaskPanel(){std::cout<<"Bye from program"<<std::endl;}
        void itemizeTasks(){
            std::cout<<"Task one"<<std::endl;
            std::cout<<"Task two"<<std::endl;
            std::cout<<"Task three"<<std::endl;
            std::cout<<"Task four"<<std::endl;}

    protected:

    private:
};


class TaskTwo{

private:
    size_t firstPlayerDoor, secondPlayerDoor, montyDoor, carPos, ttmp;
    std::string chgResponse;

protected:

public:
    TaskTwo(){std::cout<<"Welcome to task two...Monty Hall problem"<<std::endl;
    firstPlayerDoor=0;
    secondPlayerDoor=0;
    montyDoor=0;
    carPos=0;
    chgResponse="no";
    }
    ~TaskTwo(){std::cout<<"Bye from task two"<<std::endl;}
    void infotwo(){std::cout<<"The Monty hall problem is a game show quiz in which..."<<std::endl;}

    unsigned int car_position(){
        srand (time(NULL)); // initialize random seed
        carPos=rand() % 3+1;
        std::cout<<"debug.....car position:"<<carPos<<std::endl;
        return carPos;
    }

    unsigned int player_select_first(){
        std::cout<<" 1st Choice: Player Selects a door number from 1,2,3"<<std::endl;
        firstPlayerDoor=rand() % 3 +1;

        return firstPlayerDoor;
    }

    unsigned int monty_select(){
        std::cout<<"Monty makes his selection....."<<std::endl;
        std::cin>>montyDoor;

        return montyDoor;
    }

    std::string prompt_switch(){
        std::cout<<"Do you wish to switch doors"<<std::endl;
        std::cin>>chgResponse;

        return chgResponse;
    }

    void status(std::string game_stat){
        std::cout<<game_stat<<std::endl;
    }

    unsigned int player_select_second(std::string resp){
        std::cout<<" 2nd Choice: Player Selects a door number from 1,2,3"<<std::endl;
            if(resp=="YES" or resp=="yes"){
                if(firstPlayerDoor==1 and montyDoor==2){
                    secondPlayerDoor=3;
                }
                else if(firstPlayerDoor==1 and montyDoor==3){
                    secondPlayerDoor=2;
                }
                else if(firstPlayerDoor==2 and montyDoor==1){
                    secondPlayerDoor=3;
                }
                else if(firstPlayerDoor==2 and montyDoor==3){
                    secondPlayerDoor=1;
                }
                else if(firstPlayerDoor==3 and montyDoor==1){
                    secondPlayerDoor=2;
                }
                else if(firstPlayerDoor==3 and montyDoor==2){
                    secondPlayerDoor=1;
                }
                std::cout<<"Second door selected by player: "<<secondPlayerDoor<<std::endl;
            }
            else if(resp=="no" or resp=="No"){ // handles the case of response being no, NO, No
                secondPlayerDoor=firstPlayerDoor;
                std::cout<<"Player maintains FIRST choice of door: "<<secondPlayerDoor<<std::endl;
            }
            else{
                std::cout<<"Incorrect response"<<std::endl;
            }
        return secondPlayerDoor;
    }

    void compare_selection(){
        firstPlayerDoor=player_select_first(); // player makes first selection here
        std::cout<<"Player selected door number: "<<firstPlayerDoor<<std::endl;
        if(firstPlayerDoor==carPos){
            montyDoor=monty_select();
            std::cout<<"Monty selected.....: "<<montyDoor<<std::endl;
            chgResponse=prompt_switch();
            secondPlayerDoor=player_select_second(chgResponse);
            //std::cout<<"debug.....WINS on FIRST try"<<std::endl;
            status("WIN");
        }
        else if(firstPlayerDoor!=carPos){
            //std::cout<<"Player selected door number: "<<firstPlayerDoor<<std::endl;
            montyDoor=monty_select();
            std::cout<<"Monty selected....: "<<montyDoor<<std::endl;
            chgResponse=prompt_switch();
            secondPlayerDoor=player_select_second(chgResponse);
            if(secondPlayerDoor==carPos){
                //std::cout<<"debug.....WINS on second try"<<std::endl;
                status("WIN");
            }
            else{
                //std::cout<<"debug.....LOOSE on second try"<<std::endl;
                status("LOOSE");
            }
        }
        else{
            std::cout<<"ToDo"<<std::endl;
        }
    }

};

class WarAndPeace{
private:

protected:

public:
    WarAndPeace(){std::cout<<"***Welcome to scanning text exercise"<<std::endl;}
    ~WarAndPeace(){std::cout<<"***Bye from text scanning exercise"<<std::endl;}
    int readTextFile(std::string filename){
        std::string textfile(filename);
        std::cout<<"File name to read: "<<textfile<<std::endl;
        std::vector<std::string> lines;
        std::string line;

        std::ifstream file_to_read("book-war-and-peace.txt");
        if(!file_to_read.is_open()){
            std::cerr<<"File cant be opened!!!"<<std::endl;
            return EXIT_FAILURE;
        }
        while (getline(file_to_read, line)){
                lines.push_back(line);
        }
//        for (const auto &i : lines){
//            std::cout<<i<<std::endl;
//        }

        std::string name1="Makar Alexeevich";
        std::string name2="Joseph Bazdeev";
        std::string name3="Boris Drubetskoy";

        unsigned int count1=0;
        unsigned int count2=0;
        unsigned int count3=0;

        size_t sz_lines=lines.size();
        for(size_t ii=0;ii!=sz_lines;++ii){
            //std::cout<<ii<<":"<<lines.at(ii)<<std::endl;
            std::cout<<ii<<":"<<lines[ii]<<std::endl;
            if(lines[ii].find(name1)){
                count1=count1+1;
            }
            if(lines[ii].find(name2)){
                count2=count2+1;
            }
            if(lines[ii].find(name3)){
                count3=count3+1;
            }
        }
        std::cout<<name1 <<" occured: "<< count1<< " times"<<std::endl;
        std::cout<<name2 <<" occured: "<< count2<< " times"<<std::endl;
        std::cout<<name3 <<" occured: "<< count3<< " times"<<std::endl;
        file_to_read.close();


        return EXIT_SUCCESS;
    }

};

#endif // TASKPANEL_H
