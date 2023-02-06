cmake_minimum_required(VERSION 2.8)
project( Main )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

SET (SRC
 Main.cpp
 identificar_placa.cpp
 DetectPlates.cpp
 Preprocess.cpp
 DetectChars.cpp
 PossibleChar.cpp
 PossiblePlate.cpp
)

add_executable( Main ${SRC} )
target_link_libraries( Main ${OpenCV_LIBS})

SET(classifications.xml
    images.xml
)