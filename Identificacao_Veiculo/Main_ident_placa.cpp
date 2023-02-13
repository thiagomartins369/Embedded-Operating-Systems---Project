// Main.cpp

#include "Main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <cstring>

#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;

#include"identificar_placa.h"

int main(void)
{

    Mat frame;
    VideoCapture cap;

    int deviceID = 0;
    int apiID = cv::CAP_ANY;

    cap.open(deviceID, apiID);

    if (!cap.isOpened())
    {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }


    while(1)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read(frame);
        // check if we succeeded
        if (frame.empty())
        {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // show live and wait for a key with timeout long enough to show images
        imshow("Live", frame);

    //cv::Mat imgOriginalScene;                                    // input image
    //imgOriginalScene = cv::imread("imagens/image1.png");         // open image

    bool blnKNNTrainingSuccessful = loadKNNDataAndTrainKNN();           // attempt KNN training


    std::vector<PossiblePlate> vectorOfPossiblePlates = detectPlatesInScene(frame);          // detect plates

    vectorOfPossiblePlates = detectCharsInPlates(vectorOfPossiblePlates);                               // detect chars in plates

    if (vectorOfPossiblePlates.empty())                                                 // if no plates were found
    {
        std::cout << std::endl << "no license plates were detected" << std::endl;       // inform user no plates were found
    }
    else                                                                                // else
    {

        std::sort(vectorOfPossiblePlates.begin(), vectorOfPossiblePlates.end(), PossiblePlate::sortDescendingByNumberOfChars);

        PossiblePlate licPlate = vectorOfPossiblePlates.front();

        std::cout << std::endl << "-----------------------------------------";
        std::cout << std::endl << "PLACA = " << licPlate.strChars << std::endl;     // write license plate text to std out

        char *char_arr;
        char_arr = &licPlate.strChars[0];

        int RP=0;
        RP=ID(char_arr);
        std::cout <<RP<< std::endl;

        std::cout <<"-----------------------------------------" << std::endl;

    }
    }
    //cv::waitKey(0);                 // hold windows open until user presses a key

    return(0);
}












