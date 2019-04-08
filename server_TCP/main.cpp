#include <iostream>
#include <sys/socket.h>//getsockopt() setsockopt()
#include <unistd.h>
#include <memory.h>
#include <stdlib.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
    int serv_sock;

    struct sockaddr_in serv_addr;
    struct sockaddr_in cln_addr;

    serv_sock=socket(AF_INET,SOCK_STREAM,0);
    if(serv_sock==-1){
        cout<<"socket() error"<<endl;
    }

    //发生地址分配错误时候
    socklen_t optlen;
    int option;
    optlen=sizeof(option);
    option=true;
    setsockopt(serv_sock,SOL_SOCKET,SO_REUSEADDR,(void*)&option,optlen);

    memset(&serv_addr,0,sizeof(serv_addr));
    char* port="9190";
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(atoi(port));
    if(-1==bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))){
        close(serv_sock);
        std::cerr<<"bine() error"<<endl;
    }
    if(-1==listen(serv_sock,5)){
        std::cerr<<"listen() error"<<endl;
    }
    memset(&cln_addr,0,sizeof(cln_addr));
    socklen_t len=sizeof(cln_addr);
    int cln_sock=accept(serv_sock,(struct sockaddr*)&cln_addr,&len);
    if(-1==cln_sock) cerr<<"accept() error"<<endl;

    while(true){
        string ss{};
        char cc[1];
        ssize_t lll=0;
        long lenn;
        while(true){
            if((lenn=read(cln_sock,cc,1))!=0){
                cout.flush();
                ss.append(cc);
                lll++;
            }
            break;
        }
//        do{
//            cout<<"1";
//            cout.flush();
//            int a=read(cln_sock,cc,1);
//            cout<<a<<*cc<<endl;
//            cout.clear();
//            ss.append(cc);
//            lll++;
//        }while(1);

        cout<<"read size: "<<lll<<endl;
        cout<<"read: "<<ss<<endl;
        cout<<"write size: "<<write(cln_sock,ss.c_str(),lll)<<endl;
        cout<<"write: "<<ss<<endl;
    }
    close(cln_sock);
    close(serv_sock);
    return 0;
}
