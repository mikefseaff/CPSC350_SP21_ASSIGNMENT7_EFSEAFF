#include "Sort.h"
//main method for controlling the runtime mode options the user imputs
int main(int argc, char const *argv[])
{
    string choice = argv[1];
    //creates a file with the given name and number of doubles contains basic error checking
    if(choice == "create"){
        if (argc != 4){
            cout << "incorrect number of parameters (refer to readme for command parameters) " << endl;
            return 0;
        }
        string numDoubles = argv[2];
        string fileName = argv[3];
        Sort tmpSort(fileName,stoi(numDoubles));
    }
    //sorts a given file and outputs the run times of the different algorithms based on the contents of the file, contains basic error checking
    else if (choice == "sort"){
        if (argc != 3){
            cout << "incorrect number of parameters (refer to readme for command parameters) " << endl;
            return 0;
        }
        string fileName = argv[2];
        Sort tmpSort(fileName);
        tmpSort.SortAll();
    }
    //error check for incorrect mode 
    else{
        cout << "invalid input from command line please try again, (refer to readme for command parameters)" << endl;
    }
    
    return 0;
}
