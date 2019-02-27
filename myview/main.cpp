#include <QCoreApplication>
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/types_c.h"
#include <QImage>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QBuffer>
#include <QDebug>
#include <QDir>
using namespace cv;
using namespace std;
void sendImage(QImage&);
int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);

    VideoCapture capture(0);//若测试摄像头有没有打开，/*if(!capture.isOpened())                {cout<< "cannot open the camera.";cin.get();return -1;}*

//    QString s=QDir::currentPath()+"/video.mp4";
//    qDebug()<<s;
//    VideoCapture capture(s.toStdString());

    Mat edges; //定义一个Mat变量，用于存储每一帧的图像
    //【2】循环显示每一帧
    while(1)
    {
        Mat frame; //定义一个Mat变量，用于存储每一帧的图像
        capture >> frame;  //读取当前帧
        if(frame.empty())
        {
            printf("--(!) No captured frame -- Break!");
            //break;
        }
        else
        {
            cvtColor(frame, edges, CV_BGR2GRAY);//彩色转换成灰度
            blur(edges, edges, Size(7, 7));//模糊化
            Canny(edges, edges, 0, 30, 3);//边缘化
            imshow("camera", frame); //显示当前帧
        }

        //转化为bgr图片
        QImage image( (unsigned const char*)(frame.data),frame.cols,frame.rows,QImage::Format_RGB888);
        sendImage(image);

        waitKey(30); //延时30ms
    }

//    return a.exec();
}
void sendImage(QImage& image)
{
    QUdpSocket udpSocket;
    QHostAddress address("139.199.180.227");
//    QHostAddress address=QHostAddress::LocalHost;

    QByteArray byte;
    QBuffer buffer(&byte);
    image.save(&buffer,"JPEG");
//    QByteArray ss=qCompress(byte,5);
//    QByteArray vv=ss.toBase64();
    udpSocket.writeDatagram(byte.data(), byte.size(),
                                   address, 45454);
//    QImage image1;
//    image.loadFromData(ss);
//    cv::Mat mat;
//    mat=cv::Mat(image.height(),image.width(),CV_8UC4,image.bits(),image.bytesPerLine());
//    cv::imshow("two",mat);
}
