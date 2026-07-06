#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//Product class 
class Product{
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

//violating srp

class ShopingCart{
private:
    vector<Product*> products;

public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }

    //caluclate total price
    double calculateTotal(){
        double total = 0;

        for(auto p: products){
            total += p->price;
        }
        return total;
    }

    //invoice printer
    void printInvoice(){
        cout<<"Shopping Cart Invoice:\n";

        for(auto p: products){
            cout<<p->name<<" - $"<<p->price <<endl;
        }
        cout<<"Total: $"<<calculateTotal()<<endl;
    }

    //save to db
    void saveToDatabase(){
        cout<<"Saving to the database..."<<endl;
    }
};


int main(){
    ShopingCart* cart = new ShopingCart();

    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse", 50));
    
    cart->printInvoice();
    cart->saveToDatabase();

    return 0;
}
