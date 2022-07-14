#include "taskpanel.h"

int main(int argc, char* argv[]){
    TaskPanel tp;
    //tp.ItemizeTasks();

    MontyGame mg;
    mg.playMonty();

    std::cout<<std::endl;

    WarAndPeace wnp;
    wnp.readTextFile("book-war-and-peace.txt");

    return 0;
}

