/*  Documents
 *  https://marcuscode.com/lang/cpp/files
 *  https://medium.com/@vachirachat.saw/%E0%B9%82%E0%B8%84%E0%B8%A3%E0%B8%87%E0%B8%AA%E0%B8%A3%E0%B9%89%E0%B8%B2%E0%B8%87%E0%B8%82%E0%B9%89%E0%B8%AD%E0%B8%A1%E0%B8%B9%E0%B8%A5%E0%B8%95%E0%B9%88%E0%B8%B2%E0%B8%87%E0%B9%86%E0%B9%83%E0%B8%99-c-1ccdb706c38e
 *  https://www.devdit.com/post/4200/c-plus-plus-vector-%E0%B8%84%E0%B8%B7%E0%B8%AD%E0%B8%AD%E0%B8%B0%E0%B9%84%E0%B8%A3-%E0%B8%97%E0%B8%B3%E0%B8%87%E0%B8%B2%E0%B8%99%E0%B8%A2%E0%B8%B1%E0%B8%87%E0%B9%84%E0%B8%87#gsc.tab=0
 *  https://medium.com/@marktbss/c-hackerrank-vector-erase-11c65b830a43
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::vector;

// กำหนดปริมาณของจำนวนสินค้า
#define STOCK 20

// ประกาศโครงสร้างข้อมูลโดยอ้างอิงเก็บข้อมูลในไฟล์ data.txt โดยการจัดเก็บข้อความคือ id name price stock category โดยจะเว้นระยะห่าง 1tab
typedef struct {
    int id;
    string name;
    float price;
    int stock;
    string category;
} product;
vector<product> products;

// class File ใช้ในการจัดการไฟล์ data.txt เพื่อเขียนและอ่านข้อมูล
class File {
private:
    ifstream readFile;
    ofstream writeFile;
    const string PATH = R"(C:\Users\ACER USER5949486\Desktop\CPP-project\txt\data.txt)";
public:
    // อ่านข้อมูลในไฟล์ data.txt แล้วมาเก็บไว้ในตัวแปร products
    void read(){
        product p;
        readFile.open(PATH ,ios::in); // เปิดไฟล์อ่านข้อมูล
        if(readFile.is_open()){
            string line;
            while(std::getline(readFile, line)){
                std::stringstream ss(line);
                ss >> p.id >> p.name >> p.price >> p.stock >> p.category;
                products.push_back(p);
            }
            cout << "read file completed." << endl;
        } else {
            cout << "Error: Cannot open file data.txt to read data!" << endl;
        }
        readFile.close();
    };

    // Override method: เขียนข้อมูลในไฟล์ data.txt ด้วยข้อมูลใน products
    void write(){
        writeFile.open(PATH, ios::out);
        if(writeFile.is_open()){
            string oneTab = "   ";
            for(product item : products){
                writeFile << item.id << oneTab << item.name << oneTab << item.price << oneTab << item.stock << oneTab << item.category << endl;
            }
            cout << "write file completed." << endl;
        } else {
            cout << "Error: Cannot open file data.txt to write data!" << endl;
        }
        writeFile.close();
    }

    // Override method: เขียนข้อมูลในไฟล์ data.txt โดยแนบ parameter เข้าไปด้วย
    void write(product p){
        writeFile.open(PATH, ios::out);

        if(writeFile.is_open()){
            for(product item : products){
                writeFile << item.id << " " << item.name << " " << item.price << " " << item.stock << endl;
            }
            writeFile << p.id << " " << p.name << " " << p.price << " " << p.stock << endl;
            cout << "write file completed." << endl;
        } else {
            cout << "Error: Cannot open file data.txt to write data!" << endl;
        }
        writeFile.close();
    }
};

// Superclass class Product เป็น class ต้นแบบที่ให้ subclass สืบทอดคุถสมบัติและพฤติกรรมต่างๆของคลาสนี้
class Product {
public:
    // attributes
    int id;
    string name;
    float price;
    int stock = 20;
    product product1;

    // constructor method
    Product(int Id, string Name, float Price, int Stock = STOCK, string Category = "any"){
        // เมื่อสร้าง object ให้รับค่า arguments ที่ส่งมาจาก constructor แล้วมาเก็บไว้ใน attributes
        id = Id;
        name = Name;
        price = Price;
        stock = Stock;
        product1 = {
                .id = Id, .name = Name, .price = Price, .stock = Stock, .category = Category
        };
        products.push_back(product1);
    }

    Product(){}

    // getter methods
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    float getPrice(){
        return price;
    }
    int getStock(){
        return stock;
    }

    // setter methods
    void setId(int Id){
        id = Id;
    }
    void setName(string Name){
        name = Name;
    }
    void setPrice(float Price){
        price = Price;
    }
    void setStock(int Stock){
        stock = Stock;
    }

    void addProduct(){
        product newProduct = {
                .id = getId(),
                .name = getName(),
                .price = getPrice(),
                .stock = getStock(),
                .category = "any"
        };
        products.push_back(newProduct);
        File().write();
        cout << "Added a new product" << endl;
    }


    // Override method: แก้ไขชื่อสินค้า
    void editProduct(int Id, string Name){
        bool find = false;
        for(int i = 0; i < products.size(); i++){
            if(products.at(i).id == Id){
                find = true;
                products.at(i).name = Name;
                setName(Name);
            }
        }
        if(!find){
            cout << "Error: Cannot find id: " << Id << endl;
        } else {
            File().write();
            cout << "Successfully edited product" << endl;
        }
    }

    // Override method: แก้ไขราคาสินค้า
    void editProduct(int Id, float Price){
        bool find = false;
        for(int i = 0; i < products.size(); i++){
            if(products.at(i).id == Id){
                find = true;
                products.at(i).price = Price;
                setPrice(Price);
            }
        }
        if(!find){
            cout << "Error: Cannot find id: " << Id << endl;
        } else {
            File().write();
        }
    }

    // Override method: แก้ไขราคาสินค้า
    void editProduct(int Id, int Stock){
        bool find = false;
        for(int i = 0; i < products.size(); i++){
            if(products.at(i).id == Id){
                find = true;
                products.at(i).stock = Stock;
                setStock(Stock);
            }
        }
        if(!find){
            cout << "Error: Cannot find id: " << Id << endl;
        } else {
            File().write();
        }
    }
};
vector<Product> vecProdcut;

// Subclass
class Phone: public Product {
public:
    Phone(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, "smartphone"){
        cout << "New Product:" << Name << ", id: " << Id << ", price: " << Price << endl;
    }
    Phone(){}
};

// Subclass
class Tablet: public Product {
public:
    Tablet(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, "tablet"){
        cout << "New Product:" << Name << ", id: " << Id << ", price: " << Price << endl;
    }
    Tablet(){}
};

// Subclass
class Laptop: public Product {
public:
    Laptop(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, "laptop"){
        cout << "New Product:" << Name << ", id: " << Id << ", price: " << Price << endl;
    }
    Laptop(){}
};

// Subclass
class Computer: public Product {
public:
    Computer(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, "laptop"){
        cout << "New Product:" << Name << ", id: " << Id << ", price: " << Price << endl;
    }
    Computer(){}
};

class ProductManagement {
public:
    // method แสดงรายการสินค้า
    static void showListProducts(){
        if(products.size() == 0){
            cout << "Out of stock!" << endl;
        } else {
            int number = 1;
            for(product item : products){
                cout << "No: " << number << "\tID: " << item.id << "\tName: " << item.name << "\tPrice: " << item.price << "\tStock: "<< item.stock << "\tCategory: " << item.category << endl;
                number++;
            }
        }
    }

    // method เพิ่มสินค้า
//    static void addProduct(){
//        product newProduct;
//        cout << "Product Name :" << endl;
//        cin >> newProduct.name;
//        cout << "Product ID :" << endl;
//        cin >> newProduct.id;
//        cout << "pricing :" << endl;
//        cin >> newProduct.price;
//        newProduct.stock = STOCK;
//        newProduct.category = "any";
//        products.push_back(newProduct);
//        File().write();
//        cout << "Added a new product" << endl;
//    }

    // method ลบสินค้า
    static void deleteProduct(){
        int id;
        cout << "Enter the product id :";
        cin >> id;
        int index = 0;
        bool isSuccess = false;
        for(product item : products) {
            if(item.id == id){
                isSuccess = true;
                products.erase(products.begin() + index);
            }
            index++;
        }
        if(isSuccess){
            cout << "Successfully deleted product" << endl;
            File().write();
        } else {
            cout << "This product id is not in stock!" << endl;
        }
    }
};

// functions
void showOptions(){
    cout << "Enter a number" << endl;
    cout << "1.) Add product" << endl;
    cout << "2.) Delete product" << endl;
    cout << "3.) Edit product" << endl;
    cout << "4.) Show list of all products" << endl;
    cout << "5.) Buy proudcts" << endl;
    cout << "6.) Exit program" << endl;
    cout << "user :";
}

int main(){
    // สร้าง opject ไฟล์เพื่อจัดการกับไฟล์ข้อมูล
    File file = File();
    // เริ่มโปรแกรมให้อ่านข้อมูลจากไฟล์ data.txt แล้วมาเก็บไว้ในตัวแปร products
    file.read();
    // สร้าง objects สินค้า
    Phone phone = Phone();
    Tablet tablet = Tablet();
    Laptop laptop = Laptop();
    Computer computer = Computer();

    // ตัวเลือกที่ผู้ใช้งานเลือก
    int select;
    // วน loop ไปเรื่อยๆเพื่อรอผู้ใช้งานป้อนตัวเลขให้โปรแกรมทำงานตามหมายเลขนั้น
    while(true){
        showOptions();
        cin >> select;
        // เพิ่มข้อมูลสินค้า
        if(select == 1){
            string category;
            cout << "Select product category :" << endl;
            cin >> category;
            if(category == "phone"){

            } else if(category == "tablet"){

            } else if(category == "laptop"){

            } else {

            }

        }
        // ลบสินค้า
        else if(select == 2){
            ProductManagement::deleteProduct();
        }
        // แก้ไขสินค้า
        else if(select == 3){

        }
        // แสดงรายการสินค้าทั้งหมด
        else if(select == 4){
            ProductManagement::showListProducts();
        }
        // ซื้อสินค้า
        else if(select == 5){

        }
        // ออกจากโปรแกรม
        else if(select == 6){
            break;
        }
        // ไม่มีในตัวเลือกวน loop ให้เลือกใหม่
        else {
            cout << select << " is not available. Please select a number between 1 - 6" << endl;
        }
    };
    return 0;
}