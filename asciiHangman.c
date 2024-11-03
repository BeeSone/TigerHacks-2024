#include <stdio.h>

void printHangman(int wrongCount);

void printTop();
void printHead();
void printBack();
void printEmptyStick();
void printBase();


void printEmptyNoose();
void printStageOne();
void printStageTwo();
void printStageThree();
void printStageFour();
void printFullNoose();



void printEmptyStick(int length){
    char stick = '|';
    for (int i = 0; i< length; i++){
        printf("%15c\n", stick);
    }
    
}

void printBase(){
    char* base = "-------";
    printf("%18s\n", base);
}

void printTop(){
    char* dashes = "   ------------";
    char noose = '|';
    char stick = '|';

    printf("%4s\n", dashes);
    printf("%4c%11c\n", noose, stick);
}
void printEmptyNoose(){
    // The full noose is 10 lines of empty stick
    printTop();
    
    printEmptyStick(10);
    printBase();

}

void printHead(){
    // Head is 3 lines long
    char dash = '-';
    char stick = '|';
    char leftSlant = '/';
    char rightSlant = '\\';
    printf("%3c%2c%10c\n", leftSlant, rightSlant, stick);
    printf("%3c%2c%10c\n", rightSlant, leftSlant, stick);
    printf("%4c%11c\n", dash, stick);
    
}
void printBack(){
    // Back is 2 lines long
    char stick = '|';
    char back = '|';
    printf("%4c%11c\n", back, stick);
    printf("%4c%11c\n", back, stick);
}

void printOneArm(){
    // Back + Arm is 2 lines long
    char stick = '|';
    char back = '|';
    char armOne = '\\';
    printf("%3c%c%11c\n", armOne, back, stick);
    printf("%4c%11c\n", back, stick);

}

void printTwoArms(){
    // Back + Arms is 2 lines long
    char stick = '|';
    char back = '|';
    char armOne = '\\';
    char armTwo = '/';
    printf("%3c%c%c%10c\n", armOne, back, armTwo, stick);
    printf("%4c%11c\n", back, stick);


}

void printOneLeg(){
    char stick = '|';
    char legOne = '/';
    printf("%3c%12c\n", legOne, stick);

}

void printTwoLegs(){
    char stick = '|';
    char legOne = '/';
    char legTwo = '\\';
    printf("%3c%2c%10c\n", legOne, legTwo, stick);
    
}
void printStageOne(){
    printTop();
    // 3 Lines
    printHead();
    
    // 7 Lines
    printEmptyStick(7);
    printBase();

}

void printStageTwo(){
    printTop();
    // 3 Lines
    printHead();
    // 1 Lines
    printBack();
    // 6 Lines
    printEmptyStick(6);
    printBase();
    
}



void printStageThree(){
    printTop();
    // 3 Lines
    printHead();
    // 1 Lines
    printOneArm();
    // 6 Lines
    printEmptyStick(6);
    printBase();
}

void printStageFour(){
    printTop();
    // 3 Lines
    printHead();
    // 1 Lines
    printTwoArms();
    // 6 Lines
    printEmptyStick(6);
    printBase();
}
void printStageFive(){
    printTop();
    // 3 Lines
    printHead();
    // 1 Lines
    printTwoArms();
    // 1 Lines
    printOneLeg();
    // 5 Lines

    printEmptyStick(5);
    printBase();
}

void printFullNoose(){
    
    printTop();
    // 2 Lines
    printHead();
    // 2 Lines
    printTwoArms();
    // 1 Lines
    printTwoLegs();
    // 5 Lines
    printEmptyStick(5);
    printBase();



}




void printHangman(int wrongCount){

    // ascii declarations
    char* dashes = "   ------------";
    char noose = '|';
    char stick = '|';

    switch (wrongCount){
        case 0:
            printEmptyNoose();
            break;

        case 1: 
            printStageOne();
            break;

        case 2:
            printStageTwo();
            break;

        case 3: 
            printStageThree();
            break;

        case 4:
            printStageFour();
            break;
        case 5:
            printStageFive();
            break;

        case 6: 
            printFullNoose();
            printf("\nSorry, you lost!\n");
            break;
    }
    printf("You have gotten %d wrong.\n", wrongCount);



}