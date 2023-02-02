// Main.cpp

#include "Main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <cstring>

#include"identificar_placa.h"

int main(void) {


    cv::Mat imgOriginalScene;                                    // input image
    imgOriginalScene = cv::imread("imagens/image1.png");         // open image

    bool blnKNNTrainingSuccessful = loadKNNDataAndTrainKNN();           // attempt KNN training


    std::vector<PossiblePlate> vectorOfPossiblePlates = detectPlatesInScene(imgOriginalScene);          // detect plates

    vectorOfPossiblePlates = detectCharsInPlates(vectorOfPossiblePlates);                               // detect chars in plates

    if (vectorOfPossiblePlates.empty()) {                                               // if no plates were found
        std::cout << std::endl << "no license plates were detected" << std::endl;       // inform user no plates were found
    } else {                                                                            // else

        std::sort(vectorOfPossiblePlates.begin(), vectorOfPossiblePlates.end(), PossiblePlate::sortDescendingByNumberOfChars);

        PossiblePlate licPlate = vectorOfPossiblePlates.front();

        std::cout << std::endl << "-----------------------------------------";
        std::cout << std::endl << "PLACA = " << licPlate.strChars << std::endl;     // write license plate text to std out


        int RP=0;
        RP=identificar_placa(licPlate.strChars);
        std::cout <<RP<< std::endl;

        std::cout <<"-----------------------------------------" << std::endl;

    }

    cv::waitKey(0);                 // hold windows open until user presses a key

    return(0);
}












