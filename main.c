#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// define color setting for console output
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// clear the console output
#define CLEAR printf("\e[1;1H\e[2J");


// function declaration
void appIntroduction(), mainMenu(), invalidInput(), programExit(), wearAssist();

int inputRangeCheck(int userInput, int maxVal);

// --------------------- MAIN FUNCTION START ----------------------
int main()
{
    appIntroduction();
    mainMenu();
    return 0;
}
// --------------------- MAIN FUNCTION END ----------------------

// introduction to the app tells the user what can they expect from it
void appIntroduction()
{
    CLEAR
    printf("Vitejte v aplikaci pro asistenci pri oblekani.\nTato aplikace vam poradi co si vzit na sebe, s ohledem na aktualni venkovni teplotu.\n");
    printf("Teplotu zadava uzivatel sam, jelikoz aplikace neni schopna se pripojit k internetum aby si zjistila teplotu sama.\nStisknete Enter pro pokracovani...");
    getchar();
}

// main menu of the app
void mainMenu()
{
    int mainMenuSelect;
    CLEAR
    printf(CYAN"----- HLAVNI MENU -----\n\n"WHITE);
    printf("Prejete si:\n1 - Zjistit co na sebe\n2 - Ukoncit program\nZvolte operaci zadanim odpovidajiciho cisla: ");
    scanf("%d", &mainMenuSelect);

    if (inputRangeCheck(mainMenuSelect, 2))
    {
        invalidInput();
        mainMenu();
    }

    switch (mainMenuSelect)
    {
    case 1:
        wearAssist();
        break;
    case 2:
        programExit();
        break;
    }

}

// check if user input is in valid range and returns 1 if it's not
int inputRangeCheck(int userInput, int maxVal)
{
    return (userInput >= 1 && userInput <= maxVal) ? 0 : 1;
}

// invalid input error message and clear screen
void invalidInput()
{
    CLEAR
    printf(RED"Zadana hodnota neodpovida moznostem v nabidce!"WHITE);
    sleep(2);
    CLEAR
}

// main part of the program, input current temp and get results
void wearAssist()
{
    int temperature;
    CLEAR
    printf(CYAN"----- ASISTENT PRI OBLEKANI -----\n\n"WHITE);
    printf("Zadejte aktualni teplotu ve stupnich celsia: ");
    scanf("%d", &temperature);

    if (temperature >= -60 && temperature <= -10)
    {
        // fucknig freezing
    }
    else if (temperature >= -9 && temperature <= 0)
    {
        // freezing
    }
    else if (temperature >= 1 && temperature <= 10)
    {
        // cold
    }
    else if (temperature >= 10 && temperature <= 20)
    {
        // less cold
    }
    else if (temperature >= 20 && temperature <= 30)
    {
        // warm
    }
    else if (temperature >= 30 && temperature <= 60)
    {
        // fucking sauna hot
    }
    else
    {
        CLEAR
        printf(RED"Zadali jste nesmyslnou hodnotu, zkuste to znovu..."WHITE);
        sleep(2);
        wearAssist();
    }


}

// make sure that the user wants to exit the program and if no, return him to mainMenu()
void programExit()
{
    int programExitMenuSelect;
    CLEAR
    printf(YELLOW"OPRAVDU SI PREJETE UKONCIT PROGRAM?\n\n"WHITE);
    printf("1 - Ano, ukoncit\n2 - Ne, navrat do hlavniho menu\nZvolte operaci zadanim odpovidajiciho cisla: ");
    scanf("%d", &programExitMenuSelect);

    if (inputRangeCheck(programExitMenuSelect, 2))
    {
        invalidInput();
        programExit();
    }

    CLEAR

    switch (programExitMenuSelect)
    {
    case 1:
        printf(RED"----- UKONCENI PROGRAMU -----"WHITE);
        sleep(1);
        exit(0);
        break;
    case 2:
        printf(GREEN"----- NAVRAT DO HLAVNIHO MENU -----"WHITE);
        sleep(1);
        mainMenu();
        break;
    }
}