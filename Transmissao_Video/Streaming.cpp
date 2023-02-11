#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <raspicam/raspicam_cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
  raspicam::RaspiCam_Cv camera;
  
  // Inicializa a câmera
  if (!camera.open()) {
    cerr << "Não foi possível inicializar a câmera" << endl;
    return -1;
  }

  // Define as configurações da câmera
  camera.set(CV_CAP_PROP_FORMAT, CV_8UC3);
  camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
  camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
  
  // Cria o objeto de captura de vídeo
  VideoWriter video("appsrc ! videoconvert ! x264enc ! rtph264pay ! udpsink host=<endereço IP destino> port=<porta>", 0, 30, Size(640, 480), true);

  // Verifica se o objeto de captura de vídeo foi criado com sucesso
  if (!video.isOpened()) {
    cerr << "Não foi possível inicializar o objeto de captura de vídeo" << endl;
    return -1;
  }

  // Laço principal para capturar e transmitir o vídeo
  while (true) {
    Mat frame;
    camera.grab();
    camera.retrieve(frame);
    video.write(frame);
    imshow("Streaming de Vídeo", frame);
    if (waitKey(30) >= 0) break;
  }
  
  // Fecha o objeto de captura de vídeo e a câmeda
  video.release();
  camera.release();
  
  return 0;
}
