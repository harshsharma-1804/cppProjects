#include <iostream>
#include <vector>
#include<cstdlib>
#include<ctime>
#include<limits>
#include<iomanip>
#include<conio.h>

using namespace std;

class Matrix{
    private:
    int rows,columns;
    vector<vector<int>> matrix, transMatrix;
    vector<vector<int>> identityMatrix;

    public:
        void cMat(){
        char input;
        int currentRow =1;
        int Columns=0;

        cout << "To start a new row, enter '+'. To exit, enter '='." << endl;

        do{
            vector<int> row;
            cout << "Enter values in row "<<currentRow<<" or enter '/' to end this row: "<<endl;
            do{
                int data;
                cin>>data;

                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                row.push_back(data);

            }while(true);

            if (!row.empty()) {
                // Check if it's the first row
                if (matrix.empty()) {
                    Columns = row.size();
                } else if (row.size() != Columns) {
                    cout << "Error: The number of columns in each row must be the same as the first row." << endl;
                    continue;  // Skip the current row
                }

                matrix.push_back(row);
            }

            
            int col=0;
            int iteration =0;
            for(const auto &rows: matrix){
                for(int element : rows){
                    col++;
                }
                iteration++;
            }
            rows = iteration;
            columns = col/iteration;
            currentRow++;
            cout<<"Enter '+' to continue with new row or enter '=' to exit: ";
            cin>>input;
        }while(input != '=');
    }
/*------------------------------------------------------------------------------------------------*/
    void dmAT(){
        matrix.clear();
        cout<<"Matrix is cleared."<<endl;
        rows=0;
        columns=0;
    };
    void makeEmpty(){
        cout<<"Null ";
        for(auto &row: matrix){
            for (int& element : row){
                element =0;
            }
        }
    };

    Matrix identity(){

        if(rows!=columns) cout<<"Identity matrix id only possible for square matrices."<<endl;
        else 
        {identityMatrix.resize(rows,vector<int>(columns, 0));
            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;++j){
                    int& element = identityMatrix[i][j];
                    element =1;
                    if (i == j) {
                    element = 1;
                    } else {
                        element = 0;
                    }
                }
            }
        }
        return *this;
    }

/*------------------------------------------------------------------------------------------------*/
    int Rows(){
        return rows;
    };
    void getRows(){
        cout<<"Number of rows in the matrix is : "<<rows<<endl;
    };
/*------------------------------------------------------------------------------------------------*/
    int Cols(){
        return columns;
    };

    void getCols(){
        cout<<"Number of Columns in the matrix is: "<<columns<<endl;
    };
/*------------------------------------------------------------------------------------------------*/
    void printMat(){
        cout << "Matrix:" << endl;
        for (const auto &row : matrix) {
            for (int element : row) {
                cout <<setw(4)<<element << " ";
            }
            cout << endl;
        }
        size();
    }

    void printTrans(){
        cout << "Transpose Matrix:" << endl;
        for (const auto &row : transMatrix) {
            for (int element : row) {
                cout <<setw(4)<<element << " ";
            }
            cout << endl;
        }
        size();
    }

     void printIdentity(){
        cout << "Identity Matrix:" << endl;
        for (const auto &row : identityMatrix) {
            for (int element : row) {
                cout <<setw(4)<<element << " ";
            }
            cout << endl;
        }
        size();
    }
/*------------------------------------------------------------------------------------------------*/

    // bool isEqual(Matrix m2){
        
    // }
/*------------------------------------------------------------------------------------------------*/
    bool Compatible(Matrix m2){
        return Cols() == m2.Rows();
    }
    void isCompatible(Matrix m2){
        if(!Compatible(m2)){
            cout<<"The matrices are not compatible for multiplication."<<endl;
        }
        else{
            cout<<"The matrices are compatible for multiplication."<<endl;
        }
    }
/*------------------------------------------------------------------------------------------------*/
    Matrix size(){
        cout<<"size of matrix is: ("<<rows<<","<<columns<<")"<<endl;
        return *this;
    }
/*------------------------------------------------------------------------------------------------*/

    bool Samesize(Matrix m2){
        return Rows() == m2.Rows() && Cols() == m2.Cols();
    };
    //
/*------------------------------------------------------------------------------------------------*/

    void Add(Matrix m2){
        if(!Samesize(m2)){
            cout<<"The matrices are not of same size hence cannot be added."<<endl;
        }else {
            vector<vector<int>> result;
            for (int i=0;i<rows;i++){
                vector<int> row;
                for(int j=0;j<columns;j++){
                    row.push_back(matrix[i][j]+m2.matrix[i][j]);
                }
                result.push_back(row);
            }
            cout<<"The addition matrix is: "<<endl;
            for (const auto &row :result){
                for(int element:row){
                    cout<<element<<" ";
                }
                cout<<endl;
            }
        }
    };
/*------------------------------------------------------------------------------------------------*/

    void Sub(Matrix m2){
        if(!Samesize(m2)){
            cout<<"The matrices are not of same size hence cannot be subtracted."<<endl;
        }else {
            vector<vector<int>> result;
            for (int i=0;i<rows;i++){
                vector<int> row;
                for(int j=0;j<columns;j++){
                    row.push_back(matrix[i][j]-m2.matrix[i][j]);
                }
                result.push_back(row);
            }
            cout<<"The subtraction matrix is: "<<endl;
            for (const auto &row :result){
                for(int element:row){
                    cout<<element<<" ";
                }
                cout<<endl;
            }
        }
    };
/*------------------------------------------------------------------------------------------------*/

    void Mult(Matrix m2){
        if(!Compatible(m2)){
            cout<<"Matrices cannot be multiplied as they are not compatible.";
        }
        else{
            int mulrow = Rows();
            int mulcol = m2.Cols();
            for(int i=0;i<mulrow;i++){
                for(int j=0;j<mulcol;j++){
                    
                }
            }
        }
    };

/*------------------------------------------------------------------------------------------------*/

    // void MultConst(){}

/*------------------------------------------------------------------------------------------------*/
    Matrix Trans(){
        int column= matrix[0].size();
        vector<int> transArray;
        for (const auto &row : matrix) {
            for (int element : row) {
                transArray.push_back(element);
            }
        }
        transMatrix.clear();
        for(int i=0;i<column;i++){
            vector<int> transRow;
            for(int j=i;j<transArray.size();j=j+column){
                transRow.push_back(transArray[j]);
            }
            transMatrix.push_back(transRow);
        }

        return *this;
    }
/*------------------------------------------------------------------------------------------------*/

    // void Read(){};
    // void Write(){};
};


