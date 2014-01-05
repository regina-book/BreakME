

    /**/
    //@CrackMex01
    //@Toufik Airane
    //@2013.10
    /**/
    #include<iostream>
    #include<ctime>
    #define NOTICE "We have to found the right number between 1 and 10000\n"\
                    "You got only ONE chance :)\n"
    using namespace std;
    int main(){cout<<NOTICE;int pass,salt=time(NULL)-1382912020;salt=salt*salt%10000;
    cin>>pass;(pass==salt)?cout<<"GOOD JOB :) !!!\n":cout<<"BAD BOY :( !!!\n";return 0;}
