#include <iostream>
#include <vector>

using namespace std;

class ShoppingCart{
    struct Item{
        int code;
        float price;
    };
    vector<Item> list;

    public:
    void addItem(int code, float price){
        Item item;
        item.code = code;
        item.price = price;

        this->list.push_back(item);
    }

    void removeItem(int code){
        int index = 0;
        for(Item i : this->list){
            if(i.code == code)
                break;

            index++;
        }

        this->list.erase(this->list.begin() + index);
    }

    void bill(){
        cout << "Code\tPrice" << endl;
        cout << "-------------------------------" << endl;
        float total = 0.0;
        for(int i = 0; i < this->list.size(); i++){
            total += this->list[i].price;
            cout << this->list[i].code << "\t" << this->list[i].price << endl;
        }
        cout << "-------------------------------" << endl;
        cout << "Total\t" << total << endl;
    }
};

int main()
{
    ShoppingCart cart;
    cout << "Shopping Cart" << endl;
    bool run = true;
    while(run){
        int choice;
        int code;
        cout << endl << "Actions:" << endl << "\tAdd an item -> 1\n\tDelete an item -> 2\n\tPrint the Bill -> 3\n\tChoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            float price;
            cout << "Enter the code for the product and the price in float, space seperated: ";
            cin >> code;
            cin >> price;
            cart.addItem(code, price);
            break;
        case 2:
            cout << "Item code to be removed: ";
            cin >> code;
            cart.removeItem(code);
            break;
        case 3:
            cart.bill();
            break;
            run = false;
        default:
            run = false;
        }
    }
    
    cart.bill();

    return 0;
}