#include <iostream>
#include<iomanip>
#include "matrixMake.h"

using namespace std;

void matrix(){
    Matrix m1,m2;
    int choice;
    do{
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"|"<<setw(16)<<left<<"  Option Id"<<"|"<<setw(49)<<left<<"   Options"<<"|"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"|"<<setw(16)<<left<<"  1."<<"|"<<setw(49)<<left<<"   Create a Matrix"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  2."<<"|"<<setw(49)<<left<<"   Print the Matrix"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  3."<<"|"<<setw(49)<<left<<"   Create Null of the Matrix"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  4."<<"|"<<setw(49)<<left<<"   Create Identity Matrix"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  5."<<"|"<<setw(49)<<left<<"   Create Transpose of the Matrix"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  6."<<"|"<<setw(49)<<left<<"   Create Another Matrix"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  7."<<"|"<<setw(49)<<left<<"   Print the 2nd Matrix"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  8."<<"|"<<setw(49)<<left<<"   Create Null of the 2nd Matrix"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  9."<<"|"<<setw(49)<<left<<"   Create Identity of the 2nd Matrix"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  10."<<"|"<<setw(49)<<left<<"   Create Transpose of the 2nd Matrix"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  11."<<"|"<<setw(49)<<left<<"   Add both Matrices"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  12."<<"|"<<setw(49)<<left<<"   Subtract both Matrix"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  13."<<"|"<<setw(49)<<left<<"   Delete Matrix 1"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  14."<<"|"<<setw(49)<<left<<"   Delete Matrix 2"<<"|"<<endl;
        cout<<"|"<<setw(16)<<left<<"  15."<<"|"<<setw(49)<<left<<"   Exit"<<"|"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;

        cin>>choice;
        cout<<endl;
        switch (choice)
        {
        case 1:
            m1.cMat();
            break;
        case 2:
            m1.printMat();
            break;
        case 3:
            m1.makeEmpty();
            m1.printMat();
            break;
        case 4:
            m1.identity();
            m1.printIdentity();
            break;
        case 5:
            m1.Trans();
            m1.printTrans();
            break;
        case 6:
            m2.cMat();
            break;
        case 7:
            m2.printMat();
            break;
        case 8:
            m2.makeEmpty();
            m2.printMat();
            break;
        case 9:
            m2.identity();
            m2.printIdentity();
            break;
        case 10:
            m2.Trans();
            m2.printTrans();
            break;
        case 11:
            m1.Add(m2);
            break;
        case 12:
            m1.Sub(m2);
            break;
        case 13:
            m1.dmAT();
            break;
        case 14:
            m2.dmAT();
            break;
        case 15:
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }    
    }while(choice !=15);
}