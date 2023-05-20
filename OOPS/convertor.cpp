#include <iostream>

using namespace std;

class Value{
    public:
    struct FootInch{
        int feet;
        float inches;
    };
    struct MeterCentimeter{
        int meters;
        float centimeters;
    };

    Value(FootInch ftInch){
        this->ftVal.feet = ftInch.feet;
        this->ftVal.inches = ftInch.inches;
    }

    friend Value convert(FootInch footData);
    friend Value convert(MeterCentimeter meterData);

    private:
    FootInch ftVal;
    MeterCentimeter mtVal;
};

Value convert(Value val){
    Value::MeterCentimeter data;
    data.meters = (val.ftVal.feet * 0.3048) + (footData.inches * 0.0254);
    data.centimeters = data.meters * 100;
    return data;
}
Value::FootInch convert(Value::MeterCentimeter meterData){
    Value::FootInch data;
    data.feet = meterData.meters / 0.3048;
    data.inches = meterData.centimeters / 2.54;
    return data;
}

int main()
{
    Convertor convertor;
    Convertor::FootInch footInchInput;
    
    cout << "Enter feet and inches, space seperated: ";
    cin >> footInchInput.feet >> footInchInput.inches;

    Convertor::MeterCentimeter result = Convertor::convert(footInchInput);

    return 0;
}

// #include <iostream>

// using namespace std;

// int main()
// {
//     return 0;
// }