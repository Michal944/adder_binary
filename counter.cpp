#include "counter.hpp"


using std::cout;
using std::endl;
using std::cin;

Counter::Counter(){cout<<"READY!"<<endl;}
Counter::~Counter(){cout<<"CLOSE"<<endl;}

void change_to_binary(const int &value,
                      const US &bitX,
                      std::vector<US> &vec)
{
    int N;
    if(value<0)
    {
        int last_bit=1;
        for(N=0; N<(bitX-1); N++)
            last_bit*=2;
        last_bit--;
        last_bit+=value;

        for(N=0; N<(bitX-1); N++)
        {
            if(last_bit%2)
                vec.push_back(1);
            else
                vec.push_back(0);
            last_bit/=2;
        }

        vec.push_back(1);
    }
    else
    {
        int all_bits;
        all_bits=value;
        N=(bitX-1);
        while(N)
        {
            if(all_bits%2)
                vec.push_back(1);
            else
                vec.push_back(0);
            all_bits/=2;
            N--;
        }
        vec.push_back(0);
    }
}
void Counter::view()
{
    std::vector<US>::const_iterator iter;
    iter=VALUE.cend();
    iter--;

    std::vector<US>::const_iterator iter_1;
    std::vector<US>::const_iterator iter_2;
    iter_1=A.cend();
    iter_2=B.cend();

    iter_1--;
    iter_2--;
    
    US N=bits;
    while(N)
    {
        cout<<*iter_1;
        iter_1--;
        N--;
    }
    cout<<endl;
    
    N=bits;
    while(N)
    {
        cout<<*iter_2;
        iter_2--;
        N--;
    }
    cout<<endl;
    
    N=bits;
    while(N)
    {
        cout<<*iter;
        iter--;
        N--;
    }
    cout<<endl;
}



void Counter::put_value()
{    
    cout<<"-----VALUE1----"<<endl;
    cout<<"DECIMAL: ";
    cin>>value_a;
    cin.clear();
    cin.ignore(100,'\n');

    cout<<"-----VALUE2----"<<endl;
    cout<<"DECIMAL: ";
    cin>>value_b;
    cin.clear();
    cin.ignore(100,'\n');

    cout<<"-----BITS------"<<endl;
    cout<<"DECIMAL ";
    cin>>bits;

}

void Counter::add_f()
{
    auto iter = A.cbegin();
    auto iter2= B.cbegin();

    for(bool bufor=0; iter!=A.cend() && iter2!=B.cend(); 
        iter++, iter2++)
    {
        if(*iter && *iter2)
        {
            if(!bufor)
            {
            VALUE.push_back(0);
            bufor=1;
            }

            else
            VALUE.push_back(1);
        }

        else if(!(*iter || *iter2))
        {
            if(bufor)
            {
                bufor=0;
                VALUE.push_back(1);
            }
            else
                VALUE.push_back(0);
        }

        else if( (*iter || *iter2) && (*iter!=*iter2) )
        {
            if(!bufor)
                VALUE.push_back(1);
            else
                VALUE.push_back(0);
        }
    

    }

}
















        
