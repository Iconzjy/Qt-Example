#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
using namespace cv;
using namespace std;

void find_contour_demo(int,void*);//回调函数，用于createTrackbar，进行边缘检测，并画出轮廓图
void press(int event,int x,int y,int flag,void* param);//回调函数，用于setMouseCallback，用于鼠标按下左键时画轮廓用的函数
static Mat base;//用于读取图片，作为原始图片
static Mat source,canny,copy1;//分别为资源图片,轮廓线在这张图上显示；canny用于边缘检测的图片，copy1用来显示为二值化的图片,即最初的那张图片。
static int value=100;//阈值变量的初始值，用于createTrackbar函数
static Mat contour;//显示自己用鼠标画出来的轮廓；
static Mat roi;//将canny处理后，画出来的轮廓图和contour自己画的轮廓重合的部分作为要抠选的区域
int main()
{
    //图像二值化，初始化数据
    base=imread("qq.jpg");
    base.copyTo(source);
    base.copyTo(copy1);
    cvtColor(source,source,COLOR_BGR2GRAY);
    contour=Mat::zeros(source.size(),source.type());

    //设置窗口名称
    namedWindow("source"  /*,WINDOW_NORMAL*/);
    namedWindow("roi"   /*,WINDOW_NORMAL*/);
    namedWindow("roi_before");
    namedWindow("result"   /*,WINDOW_NORMAL*/);

    imshow("source",source);

    //设置鼠标事件
    setMouseCallback("source",press,(void*)&source);

    //创建阈值的滑动按键，初始值为100
    createTrackbar("threshold value","source",&value,255,find_contour_demo);
    find_contour_demo(0,nullptr);


    waitKey(0);
    return 0;
}
void find_contour_demo(int,void*)
{
    //使用canny边缘检测的图片
    Canny(copy1,canny,value,value*2,3,false);
    imshow("canny detection", canny);

    //查找轮廓，并显示彩色轮廓，接下来将彩色轮廓转为灰度，用于roi设置
    vector<vector<cv::Point>> contours;
    vector<Vec<int,4>> hierachy;
    findContours(canny,contours,hierachy,RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
    Mat drawImage = Mat::zeros(source.size(), CV_8UC3);//边缘检测后的轮廓图，用彩色画出来
    RNG rng(12345);
    for(int i=0;i<contours.size();i++)
    {
        Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        drawContours(drawImage, contours, i, color, 3, LINE_AA, hierachy, 0, Point(0, 0));
    }
    cvtColor(drawImage,drawImage,COLOR_BGR2GRAY);


    //重置图片，将电脑计算的边缘和自己画的边缘重合，用于画出roi区域
    roi=Mat::zeros(contour.size(),contour.type());
    for(int i=0;i<drawImage.rows;i++)
        for(int j=0;j<drawImage.cols;j++)
            if( (contour.ptr<uchar>(i)[j]==255) && (drawImage.ptr<uchar>(i)[j]!=0) )
                roi.ptr<uchar>(i)[j]=255;

    //设置种子，用于水漫填充，即找到roi区域内的任意一点黑点
    Point seed;
    int flag=0;
    for(int i=0;i<roi.rows;i++)
    {
        for(int j=0;j<roi.cols;j++)
        {
            if((contour.ptr<uchar>(i)[j]==255)&&(contour.ptr<uchar>(i+5)[j]==0))
            {
                seed.y=5+i;
                seed.x=j;
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }

    //进行漫水填充
    imshow("roi_before",roi);
    floodFill(roi, seed, Scalar(255,255,255), nullptr,Scalar(20, 20, 20),Scalar(20, 20, 20));
    imshow("roi",roi);


    //显示最终效果图片，底色为白色，用漫水填充的图片，如果值为0（黑色），那么就在原图上将原值改为255（白色），即为白底
    for (int i=0;i<base.rows;i++) {
        for(int j=0;j<base.cols;j++){
            if(roi.ptr<uchar>(i)[j]==0)
            {
                base.ptr<uchar>(i)[base.channels()*j]=255;
                base.ptr<uchar>(i)[base.channels()*j+1]=255;
                base.ptr<uchar>(i)[base.channels()*j+2]=255;
            }
        }
    }
    imshow("result",base);
    return;
}
void press(int event,int y,int x,int flag,void* param)
{
    //左键按下时候的事件，在二值图上画出黑线轮廓
    Mat* pic=(Mat*)param;
    if(flag==EVENT_LBUTTONDOWN)
    {
        if(!(*(pic->ptr<uchar>(x)+y)==0))
        {
            cout<<x<<" "<<y<<" "<<(int)(*(pic->ptr<uchar>(x)+y))<<endl;
            for(int i=-2;i<3;i++)
                for(int j=-2;j<3;j++)
                {
                    *(pic->ptr<uchar>(x+i)+y+j)=0;
                    contour.ptr<uchar>(x+i)[y+j]=255;
                }

        }
    }
//    imshow("contour",contour);
    imshow("source",source);
}
