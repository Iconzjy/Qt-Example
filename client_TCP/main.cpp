#include <iostream>
#include <arpa/inet.h> //sockaddr_in
#include <sys/socket.h>
#include <memory.h>
#include <unistd.h>   //read

using namespace std;

int main()
{
    int cln_sock;
    cln_sock=socket(PF_INET,SOCK_STREAM,0);
    if(-1==cln_sock)
        cerr<<"sock() error"<<endl;

    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    char* addr="127.0.0.1";
    char* port="9190";
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr(addr);
    serv_addr.sin_port=htons(atoi(port));

    if(-1==connect(cln_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))){
        cerr<<"connect() error"<<endl;
    }

    string message{};
    while(message!=string("q")){
        cout<<"请输入要传送的信息： ";
        cin>>message;
        size_t len=message.size();
        cout<<"  "<<write(cln_sock,message.c_str(),len)<<endl;
        size_t reclen=0;
        message.clear();
        int i=0;
        while(reclen<len){
            char r[1];
            ssize_t l=read(cln_sock,r,1);
            cout<<*r<<" "<<l<<"  ";
            message.append(&r[0]);
            reclen+=l;
            i++;
        }
        cout<<"i:"<<i<<" "<<reclen<<" "<<len<<endl;
        cout<<message<<endl;
    }
    close(cln_sock);
    return 0;
}
