// Copyright (c) 2022 Nicolas Riscalas All rights reserved.
//
// Created by: Nicolas Riscalas
// Created on:April 25 2022
// This program figures out the area of a triangle

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;

float level() {
    bool loopCheck = false;
    string mark;
    int percentage;
    do {
        cout << "What was you level on the last assignment: ";
        cin >> mark;
        if (mark == "4++") {
            percentage = 100;
            loopCheck = true;
        } else if (mark == "4+") {
            percentage = 97.5;
            loopCheck = true;
        } else if (mark == "4") {
            percentage = 90.5;
            loopCheck = true;
        } else if (mark == "4-") {
            percentage = 83;
            loopCheck = true;
        } else if (mark == "3+") {
            percentage = 78;
            loopCheck = true;
        } else if (mark == "3")  {
            percentage = 74.5;
            loopCheck = true;
        } else if (mark == "3-") {
            percentage = 71;
            loopCheck = true;
        } else if (mark == "2+") {
            percentage = 68;
            loopCheck = true;
        } else if (mark == "2") {
            percentage = 64.5;
            loopCheck = true;
        } else if (mark == "2-") {
            percentage = 61;
            loopCheck = true;
        } else if (mark == "1+") {
            percentage = 58;
            loopCheck = true;
        } else if (mark == "1") {
            percentage = 54.5;
            loopCheck = true;
        } else if (mark == "1-") {
            percentage = 51;
            loopCheck = true;
        } else {
            cout << "you have to input a level above a level 1- or below a 4++";
        }
    } while (loopCheck == false);
    return percentage;
}


float percentageCalc() {
    string percentageStr;
    float percentage;
    bool breakLoop = false;
    do {
        cout << "What percentage did you get on this assignment: ";
        cin >> percentageStr;
        try {
            percentage = std::stof(percentageStr);
            if (percentage > 100 || percentage < 0) {
                cout << "you have to input a percentage lower "\
                    "than 100 or higher than 0";
                continue;
            }
            breakLoop = true;
        } catch (...) {
            cout << "you have to input an integer";
        }
    } while (breakLoop == false);
    return percentage;
}

float fraction() {
    string numeratorStr, denominatorStr;
    float denominator, numerator, percentage;
    bool breakLoop = false;
    do {
        cout << "Enter the numerator of the fraction: ";
        cin >> numeratorStr;
        cout << "Enter the denominator of the fraction: ";
        cin >> denominatorStr;
        try {
            numerator = std::stof(numeratorStr);
            denominator = std::stof(denominatorStr);
            percentage = (numerator / denominator) * 100;
            if (percentage < 0  || percentage > 100) {
                cout << "You have to input a fraction that has a "\
                    "percentage less than 100  and higher than 0";
                continue;
            }
            breakLoop = true;
        } catch (...) {
            cout << "you have to input an integer";
        }
    } while (breakLoop == false);
    return percentage;
}

int main() {
    // try again loop
    while (true) {
        // variables
        float totalPercentage = 0.00, averagePercentage;
        string typeOfInput, garbage;
        int counter = 0.00;
        // variable to check if the loop should break
        bool loopCheck;
        do {
            loopCheck = false;
            cout <<  "What type of mark did you get(P for percentage/L "\
                "for level/F for fraction/C for calculate): ";
            cin >> typeOfInput;
            if (typeOfInput == "L"||
                typeOfInput == "l" ||
                typeOfInput == "level") {
                counter++;
                loopCheck = true;
                totalPercentage = level() + totalPercentage;
            } else if (typeOfInput == "P" ||
                        typeOfInput == "p" ||
                        typeOfInput == "percentage") {
                loopCheck = true;
                counter++;
                totalPercentage = percentageCalc() + totalPercentage;
            } else if (typeOfInput == "F" ||
                        typeOfInput == "f" ||
                        typeOfInput == "fraction") {
                loopCheck = true;
                counter++;
                totalPercentage = fraction() + totalPercentage;
            }
        } while (loopCheck == true);
        if (counter > 0) {
            averagePercentage = totalPercentage / counter;
            cout << "You average percentage is "\
                    << std::fixed << std::setprecision(2) << averagePercentage;
        } else {
            cout << "your average percentage is 0 since "\
                    "you didn't input any valid values";
        }
        cin.get();
        cout << "\nIf you would like to calculate again just press <enter>: ";
        if (cin.get() == '\n') {
            continue;
        } else if (cin.get() != '\n') {
            cin >> garbage;
            continue;
        }
    }
}
