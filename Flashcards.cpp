// Flashcards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool checkInput(string userInput) {
    /*Remove leading and trailing white spaces*/
    int bad = 0;
    userInput.erase(remove_if(userInput.begin(), userInput.end(), isspace), userInput.end());
    for (int i = 0; i < int(userInput.size()); i++) {
        if (!(isalpha(userInput.at(i))) ) {
            bad++;
        }
    }
    if (bad >= 1) {
        return false;
    }
    else {
        return true;
    }
}

bool checkAnswerInput(string userInput) {
    /*Remove leading and trailing white spaces*/
    int bad = 0;
    userInput.erase(remove_if(userInput.begin(), userInput.end(), isspace), userInput.end());
    for (int i = 0; i < int(userInput.size()); i++) {
        if (!(isalpha(userInput.at(i)))) {
            bad++;
        }
    }
    if (bad >= 1) {
        return false;
    }
    else {
        return true;
    }
}

void displayQuestionAskForAnswer(vector<string> questions, vector<string> answers) {
    //Not passed by reference beacuse not modifying any data.
    string flashcardsInput;
    cout << "\n\nFlashcards: question is displayed.  Press n to see answer." << endl;
    for (int i = 0; i < int(answers.size()); i++) {
        cout << "Question " << i + 1 << " is: " << questions.at(i) << ".\n\n Press n to see answer " << endl;
        cin >> flashcardsInput;
        flashcardsInput.erase(remove_if(flashcardsInput.begin(), flashcardsInput.end(), isspace), flashcardsInput.end());
        bool isGood = (int(flashcardsInput.size()) == 1 && flashcardsInput.at(0) == 'n' ||
        flashcardsInput.at(0) == 'N'); //check condition with true or false here
        if(!isGood) {
                while (!isGood) {
                    if (int(flashcardsInput.size()) == 1 && flashcardsInput.at(0) == 'n' ||
                        flashcardsInput.at(0) == 'N') {
                        cout << "\nAnswer to question " << i + 1 << " is: " << answers.at(i) << endl;
                        isGood = true;
                    }
                    else {
                        isGood = false;
                        cout << "Your input was invalid.  Flashcards: question is displayed.  Press n to see answer." << endl;
                        cin >> flashcardsInput;
                    }
                }
        }//end if
        else {
            cout << "Answer to question " << i + 1 << " is: " << answers.at(i) << endl;
        }
    }
    cout << endl;
    cout << endl;
    cout << "FLASHCARDS ALL DONE!  You have reached the end of the list.  Run the program again to play again." << endl;
    cout << "Questions with no answer will not have been displayed." << endl;
}


int main()
{
    cout << "Welcome to the flashcards program!\n";
    cout << endl;
    cout << "Enter question and answer pairs, until you're done.  When done, type done." << endl;

    bool keepGoing = true;
    
    string userInput;
    vector<string> questions;
    vector<string> answers;

    string savedInput;

    int count = 1;
    while (keepGoing) {
        cout << "Please enter question number " << count << ": ";
        //cin >> userInput;
        getline(cin, userInput);
        /*Remove white spaces.*/
        userInput.erase(remove_if(userInput.begin(), userInput.end(), isspace), userInput.end());
        /*check if DONE*/
        //put strings to lower
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
        if (userInput == "done" && count >= 3) {
                cout << "All done! (terminated from question loop)" << endl;
                break;
        }
        else if(userInput == "done" && count < 3){
            cout << "Must enter at least 2 questions, sorry!" << endl;
            continue;
        }

        if (checkInput(userInput)) {
            questions.push_back(userInput);
            cout << "Question was valid!" << endl;
          
                bool keepCheckingAnswers = true;
                while (keepCheckingAnswers) {
                    userInput = "8";
                    cout << "Please enter answer number " << count << ": ";
                    //cin >> userInput;
                    getline(cin, userInput);
                    /*Remove white spaces.*/
                    userInput.erase(remove_if(userInput.begin(), userInput.end(), isspace), userInput.end());

                    if (checkAnswerInput(userInput) && userInput != "done") {
                        cout << "Answer was valid!" << endl;
                        answers.push_back(userInput);
                        keepCheckingAnswers = false;
                        //Increment the count only
                        count++;
                        break; //If done, all done!
                    }
                    else if (userInput == "done" && count >=3) {
                        cout << "All done! (terminated from answer loop)" << endl;
                        keepGoing = false;
                        break;
                    }
                    else if (userInput == "done" && count < 3) {
                        cout << "Sorry, must enter at least 2 before quitting." << endl;
                        continue;
                    }
                    else {
                        cout << "Answer was invalid!  Please keep trying.";
                        continue;
                }
            }
        }
        else {
            cout << "Your question input was not valid.  Please try again." << endl;
            continue;
        }
    } //End WHILE loop

    displayQuestionAskForAnswer(questions, answers);
}
