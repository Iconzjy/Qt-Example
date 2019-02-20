TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += C:\opencv\opencv\build\include

LIBS += C:\opencv\bin\libopencv_calib3d400.dll
LIBS += C:\opencv\bin\libopencv_core400.dll
LIBS += C:\opencv\bin\libopencv_dnn400.dll
LIBS += C:\opencv\bin\libopencv_features2d400.dll
LIBS += C:\opencv\bin\libopencv_flann400.dll
LIBS += C:\opencv\bin\libopencv_highgui400.dll
LIBS += C:\opencv\bin\libopencv_imgcodecs400.dll
LIBS += C:\opencv\bin\libopencv_imgproc400.dll
LIBS += C:\opencv\bin\libopencv_ml400.dll
LIBS += C:\opencv\bin\libopencv_objdetect400.dll
LIBS += C:\opencv\bin\libopencv_photo400.dll
LIBS += C:\opencv\bin\libopencv_shape400.dll
LIBS += C:\opencv\bin\libopencv_stitching400.dll
LIBS += C:\opencv\bin\libopencv_superres400.dll
LIBS += C:\opencv\bin\libopencv_video400.dll
LIBS += C:\opencv\bin\libopencv_videoio400.dll
LIBS += C:\opencv\bin\libopencv_videostab400.dll
LIBS += C:\opencv\bin\opencv_ffmpeg400_64.dll

RESOURCES += \
    pic.qrc
