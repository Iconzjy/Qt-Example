QT       += core gui
QT           += network widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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
