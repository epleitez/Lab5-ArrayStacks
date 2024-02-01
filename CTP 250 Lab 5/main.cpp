#include <iostream>
#include <fstream>
#include <sstream>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "Node.h"
#include "StackInterface.h"

using namespace std;

int main() {

    //Getting the input
    string input = "";
    cout << "Enter a line of text: ";
    getline(cin, input);

    /*

    for (int i = 0; i < input.length(); i++){
        //cout << input[i] << endl;

        if (isdigit(input[i])){
            cout << ( input[i] - '0') << endl; //assign to int variable or just push the expression

        }//end if
    }//end for
    */

    //vowel counters
    int aCount = 0;
    int eCount = 0;
    int iCount = 0;
    int oCount = 0;
    int uCount = 0;
    int vowelCount = 0;

    //digit counters
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    int threeCount = 0;
    int fourCount = 0;
    int fiveCount = 0;
    int sixCount = 0;
    int sevenCount = 0;
    int eightCount = 0;
    int nineCount = 0;
    int digitCount = 0;

    //symbol counters
    int starCount = 0;
    int slashCount = 0;
    int modCount = 0;
    int plusCount = 0;
    int minusCount = 0;
    int symbolCount = 0;


    ArrayStack<char> vowelStack;
    /* A loop that continues until there are no more characters in the input string
     * Determines if the input string contains any vowels
     * Counts the vowels and adds them to vowelStack; no repeating vowels
     */
    for(int i = 0; i < input.length(); i++){
        //cout << input[i];
        if((input[i] == 'a' || input[i] == 'A') && aCount == 0){
            vowelStack.push(input[i]);
            aCount++;
            vowelCount++;
        }//end a if
        if((input[i] == 'e' || input[i] == 'E') && eCount == 0){
            vowelStack.push(input[i]);
            eCount++;
            vowelCount++;
        }//end e if
        if((input[i] == 'i' || input[i] == 'I') && iCount == 0){
            vowelStack.push(input[i]);
            iCount++;
            vowelCount++;
        }//end i if
        if((input[i] == 'o' || input[i] == 'O') && oCount == 0){
            vowelStack.push(input[i]);
            oCount++;
            vowelCount++;
        }//end o if
        if((input[i] == 'u' || input[i] == 'U') && uCount == 0){
            vowelStack.push(input[i]);
            uCount++;
            vowelCount++;
        }//end u if
    }
    ArrayStack<char> copyVowelStack;
    copyVowelStack.copyStack(vowelStack);

    //displays the Vowel stack
    cout << "\nVowel Stack: " << endl;
    for (int i = 0; i < vowelCount; i++){
        while(!vowelStack.isEmpty()){
            cout << vowelStack.peek() << endl;
            vowelStack.pop();
        }
    }//end for

    ArrayStack<int> digitStack;
    /* A loop that continues until there are no more characters in the input string
     * Determines if the input string contains any digits
     * Counts the digits and adds them to digitStack; no repeating digits
     */
    for(int i = 0; i < input.length(); i++){
        if (isdigit(input[i])){
            if(((input[i] - '0') == 0) && zeroCount == 0){
                digitStack.push(input[i] - '0');
                zeroCount++;
                digitCount++;
            }
            if(((input[i] - '0') == 1) && oneCount == 0){
                digitStack.push(input[i] - '0');
                oneCount++;
                digitCount++;
            }
            if(((input[i] - '0') == 2) && twoCount == 0){
                digitStack.push(input[i] - '0');
                twoCount++;
                digitCount++;
            }
            if(((input[i] - '0') == 3) && threeCount == 0){
                digitStack.push(input[i] - '0');
                threeCount++;
                digitCount++;
            }
            if(((input[i] - '0') == 4) && fourCount == 0){
                digitStack.push(input[i] - '0');
                fourCount++;
                digitCount++;
            }
            if(((input[i] - '0') == 5) && fiveCount == 0){
                digitStack.push(input[i] - '0');
                fiveCount++;
                digitCount++;
            }
            if(((input[i] - '0') == 6) && sixCount == 0){
                digitStack.push(input[i] - '0');
                sixCount++;
                digitCount++;
            }
            if(((input[i] - '0') == 7) && sevenCount == 0){
                digitStack.push(input[i] - '0');
                sevenCount++;
                digitCount++;
            }
            if(((input[i] - '0') == 8) && eightCount == 0){
                digitStack.push(input[i] - '0');
                eightCount++;
                digitCount++;
            }
            if(((input[i] - '0') == 9) && nineCount == 0){
                digitStack.push(input[i] - '0');
                nineCount++;
                digitCount++;
            }
        }
    }

    ArrayStack<int> copyDigitStack;
    copyDigitStack.copyStack(digitStack);

    //displays the digit Stack
    cout << "Digit Stack:" << endl;
    for (int i = 0; i < digitCount; i ++){
        while(!digitStack.isEmpty()){
            cout << digitStack.peek() << endl;
            digitStack.pop();
        }
    }

    ArrayStack<char> symbolStack;
    /* A loop that continues until there are no more characters in the input string
     * Determines if the input string contains any special symbols
     * Counts the symbols and adds them to symbolStack; no repeating symbols
     */
    cout << "Symbol Stack" << endl;
    for(int i = 0; i < input.length(); i++){
        if((input[i] == '*') && starCount == 0){
            //cout << input[i] << endl;
            symbolStack.push(input[i]);
            starCount++;
            symbolCount++;
        }
        if((input[i] == '/') && slashCount == 0){
            symbolStack.push(input[i]);
            slashCount++;
            symbolCount++;
        }
        if((input[i] == '%') && modCount == 0){
            symbolStack.push(input[i]);
            modCount++;
            symbolCount++;
        }
        if((input[i] == '+') && plusCount == 0){
            symbolStack.push(input[i]);
            plusCount++;
            symbolCount++;
        }
        if((input[i] == '-') && minusCount == 0){
            symbolStack.push(input[i]);
            minusCount++;
            symbolCount++;
        }
    }

    ArrayStack<char> copySymbolStack;
    copySymbolStack.copyStack(symbolStack);


    //displays the symbol stack
    for (int i = 0; i < symbolCount; i ++){
        while(!symbolStack.isEmpty()){
            cout << symbolStack.peek() << endl;
            symbolStack.pop();
        }
    }

    /* Result
     * takes the top two int values in the digit stack and assigns then to an
     * x and y variable. takes the top char value in the symbol stack and assigns
     * it to an operator variable.
     * Determines what should be done with x and y variables based on operator.
     * result of x and y displayed.
     */
    int result = 0;

    int x = copyDigitStack.peek();
    copyDigitStack.pop();
    int y = copyDigitStack.peek();
    //op : operator
    char op = copySymbolStack.peek();

    if(op == '*'){
        result = x * y;
    }
    if(op == '/'){
        result = x / y;
    }
    if(op == '%'){
        result = x % y;
    }
    if(op == '+'){
        result = x + y;
    }
    if(op == '-'){
        result = x - y;
    }

    cout << "\nx: " << x << endl;
    cout << "y: " << y << endl;
    cout << "Operator: " << op << endl;
    cout << "Result: " << result << endl;





    cout << "------------------------------------------------------" << endl;
    cout << "Using LinkedStack to determine the Halloween candy" << endl;
    cout << "with the highest calorie count per serving: "<< "\n" << endl;

    //opening a file
    ifstream infile("halloweenCandy.csv");
    if(!infile.is_open()){
        cout << "File not open for input...program terminating" << endl;
        exit(0);
    }

    LinkedStack<string> halloweenCandyName;
    LinkedStack<int> halloweenCandyCalories;

    string line = "";
    string candyName = "";
    string temp = "";
    int calorieCount = 0;
    int amountOfCandy = 0;

    /* File data read using getline
     * candy name pushed on to halloweenCandyName LinkedStack
     * candy calorie amount pushed on to halloweenCandyCalories LinkedStack
     */

    while(getline(infile, line)){
        stringstream ss(line);
        getline(ss, candyName, ',');
        getline(ss, temp, ',');
        calorieCount = stoi(temp);
        halloweenCandyName.push(candyName);
        halloweenCandyCalories.push(calorieCount);
        amountOfCandy++;
    }

    /* Checking that file data was read
    for (int i = 0; i < amountOfCandy; i ++){
        while(!halloweenCandyName.isEmpty()){
            cout << halloweenCandyName.peek() << endl;
            halloweenCandyName.pop();
        }
    }
    for (int i = 0; i < amountOfCandy; i ++){
        while(!halloweenCandyCalories.isEmpty()){
            cout << halloweenCandyCalories.peek() << endl;
            halloweenCandyCalories.pop();
        }
    }
    */

    //LinkedStack<int> copyHalloweenCandyCalories;
    //copyHalloweenCandyCalories.copyStack(halloweenCandyCalories);
    //LinkedStack<string> candyNamesWithHighestCal;

    int highestCalCount = halloweenCandyCalories.peek();
    string highestCalCountName = halloweenCandyName.peek();

    // Determines which Halloween candy had the highest calorie amount
    for(int i = 0; i < amountOfCandy; i ++){
        while(!halloweenCandyCalories.isEmpty()){
            if(halloweenCandyCalories.peek() > highestCalCount){
                highestCalCount = halloweenCandyCalories.peek();
                highestCalCountName = halloweenCandyName.peek();
            }
            else{
                halloweenCandyCalories.pop();
                halloweenCandyName.pop();
            }
        }
    }
    /*
    for(int i = 0; i < amountOfCandy; i++){
        while(!copyHalloweenCandyCalories.isEmpty()){
            if(copyHalloweenCandyCalories.peek() == highestCalCount){
                highestCalCountName = halloweenCandyName.peek();
                candyNamesWithHighestCal.push(highestCalCountName);
            }
            else{
                copyHalloweenCandyCalories.pop();
                halloweenCandyName.pop();
            }
        }
    }
     */

    cout << "\nHighest calorie count: " << highestCalCount << endl;
    cout << "Candy with " << highestCalCount << " calories per serving: " <<
    highestCalCountName<< endl;


    return 0;
}

