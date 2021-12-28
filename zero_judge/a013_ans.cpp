#include <iostream>
#include <bits/stdc++.h>

using namespace std;

 

const char RomanNumerals[7]={'I','V','X','L','C','D','M'};

const int Numerals[7]={1,5,10,50,100,500,1000};

 

int inputCalculate(string input)

{
    int value=0,temp[2];

    for(int i=0;i<input.length();++i)

    {
        for(int j=0;j<7;++j){
            if(input[i]==RomanNumerals[j])

                temp[0]=Numerals[j];

            if(input[i+1]==RomanNumerals[j] && i!=input.length()-1)

                temp[1]=Numerals[j];
        }

        if(temp[0]<temp[1]&&i!=input.length()-1)

            value+=-temp[0];

        else

            value+=temp[0];

    }

    return value;

}

 

void outputCalculate(int output)

{
    int number[4],divisor=1000,count=6;

 

    for(int i=0;i<4;++i)

    {
        number[i]=output/divisor;

        output%=divisor;

        divisor/=10;

    }

 

    for(int i=0;i<4;++i)

    {
        if(1<=number[i]&&number[i]<=3)

            for(int j=0;j<number[i];++j)

                cout<<RomanNumerals[count];

        else if(number[i]==4)

            cout<<RomanNumerals[count]<<RomanNumerals[count+1];

        else if(number[i]==5)

            cout<<RomanNumerals[count+1];

        else if(6<=number[i]&&number[i]<=8)

        {
            cout<<RomanNumerals[count+1];

            for(int j=0;j<number[i]-5;++j)

                cout<<RomanNumerals[count];

        }

        else if(number[i]==9)

            cout<<RomanNumerals[count]<<RomanNumerals[count+2];

        count-=2;

    }

    cout<<endl;

}

int main()

{
    string input[2];

    while(1)

    {
        cin>>input[0];

        if(input[0]=="#")

            break;

        cin>>input[1];

        int value[2],output;

        value[0]=inputCalculate(input[0]);

        value[1]=inputCalculate(input[1]);

        output=abs(value[0]-value[1]);

        if(output==0)

            cout<<"ZERO"<<endl;

        else

            outputCalculate(output);

    }

    return 0;

}