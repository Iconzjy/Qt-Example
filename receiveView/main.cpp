#include <QCoreApplication>
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/types_c.h"
#include "opencv2/highgui/highgui.hpp"
#include <QImage>
#include <QUdpSocket>
#include <QBuffer>
#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QDateTime>
using namespace std;
using namespace cv;
cv::Mat QImage_to_cvMat( const QImage &, bool);
int main(int argc, char *argv[])
{
//   QCoreApplication a(argc, argv);

    cv::Mat mat;
    QUdpSocket udp;
    cv::VideoWriter *cameraWriter = nullptr;
//    cameraWriter.open("D:\\MyVideo.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(640,480), true);
    udp.bind(QHostAddress::AnyIPv4,45454,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
//    udp.joinMulticastGroup(QHostAddress::LocalHost);

    long long int i=0;
    QDateTime currentTime=QDateTime::currentDateTime();
    while (true)
    {
        if(udp.hasPendingDatagrams())
        {

            QByteArray datagram;
            datagram.resize(udp.pendingDatagramSize());
            qDebug()<<udp.pendingDatagramSize();
            udp.readDatagram(datagram.data(), datagram.size());
            qDebug()<<datagram.data()<<datagram.size();
            QImage image(QSize(640,480),QImage::Format_RGB888);
            image.loadFromData(datagram);/*没有读取到任何数据*/
            qDebug()<<image.size();
            if(image.size()!=QSize(0,0))
            {
//            mat=cv::Mat(image.height(),image.width(),CV_8UC4,image.bits(),image.bytesPerLine());
                mat=::QImage_to_cvMat(image,true);
//                if(i==0)
//                {
//                    Size frameSize = Size(mat.size());
//                    int type=cv::VideoWriter::fourcc('F', 'L', 'V', '1');
//                    cv::String path("D:\\");
//                    path.operator+=(currentTime.toString().toStdString());
//                    cameraWriter=new cv::VideoWriter("C:\\MyVideo.avi", -1, 30, frameSize, true);
//                    qDebug()<<type<<cameraWriter->isOpened();
//                    i++;
//                }
//                cameraWriter->write(mat);
                cv::imshow("test",mat);
                waitKey(10);

            }
        }
//        if(i==1000)
//        {
//            cameraWriter->release();
//            i=0;
//        }

    }

//    return a.exec();
}
cv::Mat QImage_to_cvMat( const QImage &image, bool inCloneImageData = true )
{
    switch ( image.format() )
    {
    // 8-bit, 4 channel
    case QImage::Format_RGB32:
    {
        cv::Mat mat( image.height(), image.width(), CV_8UC4, const_cast<uchar*>(image.bits()), image.bytesPerLine() );
        return (inCloneImageData ? mat.clone() : mat);
    }


        // 8-bit, 3 channel
    case QImage::Format_RGB888:
    {
        if ( !inCloneImageData ) {
            qWarning() << "ASM::QImageToCvMat() - Conversion requires cloning since we use a temporary QImage";
        }
        QImage swapped = image.rgbSwapped();
        return cv::Mat( swapped.height(), swapped.width(), CV_8UC3, const_cast<uchar*>(swapped.bits()), swapped.bytesPerLine() ).clone();
    }


        // 8-bit, 1 channel
    case QImage::Format_Indexed8:
    {
        cv::Mat  mat( image.height(), image.width(), CV_8UC1, const_cast<uchar*>(image.bits()), image.bytesPerLine() );


        return (inCloneImageData ? mat.clone() : mat);
    }


    default:
        qDebug("Image format is not supported: depth=%d and %d format\n", image.depth(), image.format());
                break;
    }


    return cv::Mat();
}
