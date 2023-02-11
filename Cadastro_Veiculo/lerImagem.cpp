#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Carregar a imagem
    Mat image = imread("veiculo.jpg");
    
    // Verificar se a imagem foi carregada com sucesso
    if(image.empty())
    {
        cout << "Não foi possível carregar a imagem" << endl;
        return -1;
    }
    
    // Convertendo a imagem para escala de cinza
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    imshow("Imagem ColorGray", gray);

    // Aplicar equalização de histograma para ajustar o contraste e brilho
    Mat adjusted;
    equalizeHist(gray, adjusted);
    imshow("Imagem equalizada", adjusted);
    
    // Aplicar a bilateração para suavizar as bordas da placa
    Mat blurred;
    bilateralFilter(adjusted, blurred, 9, 75, 75);
    imshow("Imagem Suavizada", blurred);
    
    // Aplicar threshold para tornar a imagem binária
    Mat thresholded;
    threshold(blurred, thresholded, 150, 255, THRESH_BINARY);
    imshow("Imagem Suavizada", thresholded);
    
    // Encontrar os contornos da placa
    vector<vector<Point>> contours;
    findContours(thresholded, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
    
    // Verificar cada contorno encontrado
    for(int i = 0; i < contours.size(); i++)
    {
        // Obter o retângulo delimitador do contorno
        Rect boundingRect = cv::boundingRect(contours[i]);
        
        // Verificar se o retângulo tem dimensões adequadas para uma placa de veículo
        float aspectRatio = boundingRect.width / (float)boundingRect.height;
        if(aspectRatio >= 2.5 && aspectRatio <= 4.0 &&
           boundingRect.width >= 100 && boundingRect.width <= 200 &&
           boundingRect.height >= 50 && boundingRect.height <= 150)
        {
            // Desenhar o retângulo na imagem
            rectangle(image, boundingRect, Scalar(0, 255, 0), 2);
            
            // Mostrar a placa reconhecida na imagem
            Mat plate = thresholded(boundingRect);
            imshow("Placa", plate);
            waitKey();
        }
    }
    
    // Mostrar a imagem com as placas reconhecidas
    imshow("Imagem", image);
    waitKey();
    
    return 0;
}