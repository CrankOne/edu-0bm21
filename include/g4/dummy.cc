#include "factory-scorer.hh"
#include <iostream>

int main(){
    CounterFactory* factory1 =  new KahanCounterFactory;
    auto counter1 = factory1->Create();

    CounterFactory* factory2 =  new PolinaCounterFactory;
    auto counter2 = factory2->Create();

    CounterFactory* factory3 =  new NikitaCounterFactory;
    auto counter3 = factory3->Create();
    float k;
    for(size_t i=0;i<10000;i++){
        k = static_cast<float>(i);
        counter1->Increment(k); 
        counter2->Increment(k);
        counter3->Increment(k);

    }

    float value1 = counter1->GetValue();
    float value2 = counter2->GetValue();
    float value3 = counter3->GetValue();
    
    //IT DOES NOT WORK CORRECTLY!!! I DONT KNOW!!!!!!!!!!!!
    // std::cout<<counter1->KahanCounter::GetName()<<": "<<value1<<std::endl;
    // std::cout<<counter2->PolinaCounter::GetName()<<": "<<value2<<std::endl;
    // std::cout<<counter3->NikitaCounter::GetName()<<": "<<value3<<std::endl;
    std::cout<<"Kaha: "<<value1<<std::endl;
    std::cout<<"Pol: "<<value2<<std::endl;
    std::cout<<"Nik: "<<value3<<std::endl;

return 0;
}
