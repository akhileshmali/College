#include<iostream>
using namespace std;

int receiver(int tmp1)
{
    int i;
    for(i = 0;i < 5;i++)
        rand();
        i = rand() % tmp1;
        return i;
}

int negack(int tmp1)
{
    int i;
    for(i = 0;i < 5;i++)
        rand();
        i = rand() % tmp1;
        return i;
}

void selectiveRepeat(int windowsize, int noofPacket)
{
    int tmp1, tmp2, tmp3 = 0, tmp4 = 0, tmp5 = 0, i, morePacket = noofPacket;
    
    for(int i = 0;i < 10;i++)
        rand();
    cout<<"Number of frames is: "<<noofPacket;
    
    while(morePacket >= 0)
    {
        tmp1 = simulate(windowsize);
        windowsize -= tmp1;
        tmp4 += tmp1;
        
        if(tmp4 > noofPacket)
            tmp4 = noofPacket;
            
        for(i = noofPacket - morePacket; i <= tmp4; i++)
            cout<<"\nSending Frame "<<i;
            
        tmp2 = receiver(tmp1);
        tmp3 += tmp2;
        
        if(tmp3 > noofPacket)
           tmp3 = noofPacket;
           
        tmp2 = negack(tmp1);
        tmp5 += tmp2;
        
        if(tmp5 != 0)
        {
           cout<<"\nNo acknowledgement for the frame "<<tmp5;
           cout<<"\nRetransmitting frame "<<tmp5;
        }
        morePacket -= tmp1;
        
        if(windowsize <= 0)
           windowsize = 4;
    }
}

int main()
{
    int windowsize = 4, noofPacket;
    for(int i = 0;i < 10;i++)
        rand();
    noofPacket = rand()%10;
    selectiveRepeat(windowsize, noofPacket);
    cout<<"\n Selective Repeat Protocol Ends. All packets are successfully transmitted.";
}
