#include <iostream>
using namespace std;

int main() {

    int hour, minutes, seconds;

    cout<<"Enter the time in hours: ";
    cin >> hour;

    cout<<"Enter the time in minutes: ";
    cin>>minutes;

    cout<<"Enter the time in seconds: ";
    cin>>seconds;

    int totalSeconds = (hour*3600) + (minutes*60)+seconds;
    cout<<"\nTotal seconds: "<< totalSeconds<<endl;


    int inputSeconds;
    cout<<"Enter total seconds: ";
    cin>>inputSeconds;

    int Hours =inputSeconds/3600;
    int Minutes =(inputSeconds%3600)/60;
    int Seconds =inputSeconds%60;

    cout<<"HH:MM:SS => "
         <<Hours<< ":"
         <<(Minutes<10?"0" : "")<< Minutes << ":"
         <<(Seconds<10?"0" : "")<< Seconds << endl;

    return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
}