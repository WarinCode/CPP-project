/*  Documents
 *  https://marcuscode.com/lang/cpp/files
 *  https://medium.com/@vachirachat.saw/%E0%B9%82%E0%B8%84%E0%B8%A3%E0%B8%87%E0%B8%AA%E0%B8%A3%E0%B9%89%E0%B8%B2%E0%B8%87%E0%B8%82%E0%B9%89%E0%B8%AD%E0%B8%A1%E0%B8%B9%E0%B8%A5%E0%B8%95%E0%B9%88%E0%B8%B2%E0%B8%87%E0%B9%86%E0%B9%83%E0%B8%99-c-1ccdb706c38e
 *  https://www.devdit.com/post/4200/c-plus-plus-vector-%E0%B8%84%E0%B8%B7%E0%B8%AD%E0%B8%AD%E0%B8%B0%E0%B9%84%E0%B8%A3-%E0%B8%97%E0%B8%B3%E0%B8%87%E0%B8%B2%E0%B8%99%E0%B8%A2%E0%B8%B1%E0%B8%87%E0%B9%84%E0%B8%87#gsc.tab=0
 *  https://medium.com/@marktbss/c-hackerrank-vector-erase-11c65b830a43
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::vector;

// กำหนดจำนวนสินค้าที่เก็บได้ในคลังสูงสุดโดยค่าเริ่มต้นของแต่ละสินค้าจะเก็บอยู่ที่ 20 จำนวน
#define MAX_STOCK 20
// ประเภทหมวดหมู่สินค้า
string categories[] = { "phone", "tablet", "laptop", "computer" };
// สร้่าง struct ไว้จัดการเก็บข้อมูลเป็นกลุ่มเมื่อ loop ข้อมูลมาจากตัวแปร data ได้
typedef struct {
    string name;
    int id;
    float price;
    int stock;
    string category;
} product;

// Superclass class Product เป็น class ต้นแบบที่ให้ subclass สืบทอดคุถสมบัติและพฤติกรรมต่างๆของคลาสนี้
class Product {
public:
    // attributes
    int id; // รหัสสินค้า
    string name; // ชื่อสินค้า
    float price; // ราคาสินค้า
    int stock; // จำนวนสินค้าที่เก็บไว้ในคลัง
    string category; // ประเภทของสินค้า

    // constructor method
    Product(int Id, string Name, float Price, int Stock = MAX_STOCK, string Category = "any"){
        // เมื่อสร้าง object ให้รับค่า arguments ที่ส่งมาจาก constructor แล้วมาเก็บไว้ใน attributes
        setId(Id);
        setName(Name);
        setPrice(Price);
        setStock(Stock);
        setCategory(Category);
    }

    Product(string Category = "any"){
        setId(0);
        setName("");
        setStock(MAX_STOCK);
        setCategory(Category);
    }

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
    string getCategory(){
        return category;
    };

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
    void setCategory(string Category){
        category = Category;
    }
};
// สร้างตัวแปร data เก็บข้อมูลสินค้าทั้งหมดจากในไฟลื data.txt และ ข้อมูล ที่ เพิ่ม ลบ แก้ไขเข้ามา
vector<Product> data = {};

// class File ใช้ในการจัดการไฟล์ data.txt เพื่อเขียนและอ่านข้อมูล
class File {
private:
    // ตัวแปรสำหรับอ่านไฟลืข้อมูล
    ifstream readFile;
    // ตัวแปรสำหรับเขียนไฟล์ข้อมูล
    ofstream writeFile;
    // ตำแหน่งที่อยู่ของไฟล์ data.txt
    const string PATH = R"(C:\Users\ACER USER5949486\Desktop\CPP-project\txt\data.txt)";
public:
    // อ่านข้อมูลในไฟล์ data.txt แล้วมาเก็บไว้ในตัวแปร data
    void read(){
        readFile.open(PATH ,ios::in); // เปิดไฟล์อ่านข้อมูล
        if(readFile.is_open()){
            string line;
            while(std::getline(readFile, line)){
                Product getProducts = Product();
                std::stringstream ss(line);
                ss >> getProducts.id >> getProducts.name >> getProducts.price >> getProducts.stock >> getProducts.category;
                data.push_back(getProducts);
            }
            cout << "read file completed." << endl;
        } else {
            cout << "Error: Cannot open file data.txt to read data!" << endl;
        }
        readFile.close();
    };

    // เขียนข้อมูลลงในไฟล์ data.txt ด้วยข้อมูล vector Product
    void write(){
        writeFile.open(PATH, ios::out);
        if(writeFile.is_open()){
            for(Product item : data){
                writeFile << item.id << "\t" << item.name << "\t" << item.price << "\t" << item.stock << "\t" << item.category << endl;
            }
            cout << "write file completed." << endl;
        } else {
            cout << "Error: Cannot open file data.txt to write data!" << endl;
        }
        writeFile.close();
    }
};

// Subclass
class Phone: public Product {
public:
    Phone(int Id, string Name, float Price, int Stock = MAX_STOCK): Product(Id, Name, Price, Stock, categories[0]){
        cout << "New Product: " << Name << "\tID: " << Id << "\tPrice: " << Price << endl;
    }
    Phone(): Product(categories[0]){}
};

// Subclass
class Tablet: public Product {
public:
    Tablet(int Id, string Name, float Price, int Stock = MAX_STOCK): Product(Id, Name, Price, Stock, categories[1]){
        cout << "New Product: " << Name << "\tID: " << Id << "\tPrice: " << Price << endl;
    }
    Tablet(): Product(categories[1]){}
};

// Subclass
class Laptop: public Product {
public:
    Laptop(int Id, string Name, float Price, int Stock = MAX_STOCK): Product(Id, Name, Price, Stock, categories[2]){
        cout << "New Product: " << Name << "\tID: " << Id << "\tPrice: " << Price << endl;
    }
    Laptop(): Product(categories[2]){}
};

// Subclass
class Computer: public Product {
public:
    Computer(int Id, string Name, float Price, int Stock = MAX_STOCK): Product(Id, Name, Price, Stock, categories[3]){
        cout << "New Product: " << Name << "\tID: " << Id << "\tPrice: " << Price << endl;
    }
    Computer(): Product(categories[3]){}
};

// class ProductManagement มีหน้าที่จัดการเกี่ยวกับสินค้าต่างๆ
class ProductManagement {
public:

    // method แสดงรายการสินค้า
    static void showListProducts(){
        if(data.size() == 0){
            cout << "Out of stock!" << endl;
        } else {
            int number = 1;
            for(Product item : data){
                cout << "No: " << number << "\tID: " << item.id << "\tName: " << item.name << "\tPrice: " << item.price << "\tStock: "<< item.stock << "\tCategory: " << item.category << endl;
                number++;
            }
        }
    }

    // method ในการตรวจสอบสินค้าว่ามีอยู่ในข้อมูลไหม ถ้ามีคืนค่า true ถ้าไม่ คืนค่า false
    static bool findProduct(string key){
        for(Product item : data){
            // key เป็นได้ทั้ง รหัสสินค้า หรือ ชื่อสินค้าก็ได้
            if(to_string(item.getId()) == key || item.name == key){
                return true;
            }
        }
        return false;
    }

    // method เพิ่มสินค้า
    static void addProduct(){
        string selectCategory;
        bool isCategory = false;

        cout << "Product categories ";
        char comma = ',';
        int count = 0;
        for(string category : categories){
            cout << "\"" << category << "\"";
            if(count != 3) cout << comma << ' ';
            count++;
        }

        cout << endl << "Select product category:";
        cin >> selectCategory;

        for(string category : categories){
            if(selectCategory == category) isCategory = true;
        }

        if(isCategory){
            product p;
            Product newProduct;

            cout << "Product Name:";
            cin >> p.name;
            cout << "Product ID:";
            cin >> p.id;
            cout << "pricing:";
            cin >> p.price;

            if(selectCategory == categories[0]){
                Phone phone = Phone(p.id, p.name, p.price);
                newProduct = phone;
            } else if(selectCategory == categories[1]){
                Tablet tablet = Tablet(p.id, p.name, p.price);
                newProduct = tablet;
            } else if(selectCategory == categories[2]){
                Laptop laptop = Laptop(p.id, p.name, p.price);
                newProduct = laptop;
            } else if(selectCategory == categories[3]){
                Computer computer = Computer(p.id, p.name, p.price);
                newProduct = computer;
            }

            data.push_back(newProduct);
            File().write();

            cout << "Added a new product" << endl;
        } else {
            cout << "Error: " << "\"" << selectCategory << "\"" << " is not in categories of products" << endl;
        }
    }

    static void addStockProduct(){
        string input;
        cout << "Enter the product id or product name :";
        cin >> input;

        if(findProduct(input)){
            int newStock;
            int index = 0;

            cout << "amount:";
            cin >> newStock;

            for(Product item : data){
                if(input == to_string(item.getId()) || input == item.getName()){
                    data.at(index).setStock(newStock);
                    break;
                }
                index++;
            }

            File().write();
            cout << "Added new product quantity to stock" << endl;
        } else {
            cout << "Error: " << input << "is not in stock!" << endl;
        }
    }

    // method ลบสินค้า
    static void deleteProduct() {
        string input;

        cout << "Enter the product id or product name:";
        cin >> input;

        if (findProduct(input)) {
            int index = 0;
            for (Product item : data) {
                if (to_string(item.getId()) == input || item.getName() == input) {
                    data.erase(data.begin() + index);
                    break;
                }
                index++;
            }
            cout << "Successfully deleted product" << endl;
            File().write();
        } else {
            cout << "Error: " << input << " is not in stock!" << endl;
        }
    }

        // Override method: แก้ไขชื่อสินค้า
        static void editProduct() {
            string input;

            cout << "Enter the product id or product name:";
            cin >> input;

            if(findProduct(input)){
                int index = 0;
                product p;
                char yesOrNo;

                for (Product item : data) {
                    if (to_string(item.getId()) == input || item.getName() == input) {

                        cout << "Do you want to edit the product name (y/n):";
                        cin >> yesOrNo;
                        if(tolower(yesOrNo) == 'y'){
                            cout << "new product name:";
                            cin >> p.name;
                            data.at(index).setName(p.name);
                        }

                        cout << "Do you want to edit the product id (y/n):";
                        cin >> yesOrNo;
                        if(tolower(yesOrNo) == 'y'){
                            cout << "new product id:";
                            cin >> p.id;
                            data.at(index).setId(p.id);
                        }

                        cout << "Do you want to edit the product price (y/n):";
                        cin >> yesOrNo;
                        if(tolower(yesOrNo) == 'y'){
                            cout << "new product price:";
                            cin >> p.price;
                            data.at(index).setPrice(p.price);
                        }

                        cout << "Do you want to edit the product category (y/n):";
                        cin >> yesOrNo;
                        if(tolower(yesOrNo) == 'y'){
                            cout << "new product category:";
                            cin >> p.category;
                            data.at(index).setCategory(p.category);
                        }
                        break;
                    }
                    index++;
                }

                File().write();
                cout << "Successfully edited product" << endl;
            } else {
                cout << "Error: " << input << " is not in stock!" << endl;
            }

            bool find = false;
        }

    // method ในการขายสินค้า
    static void sellProducts(){
        string input;

        cout << "Enter product name of product id:";
        cin >> input;

        if(findProduct(input)){
            product p;
            int quantity;
            float total = 0;
            bool isValid = false;

            for(int i = 0; i < data.size(); i++){
                Product item = data.at(i);

                if(to_string(item.getId()) == input || item.getName() == input){
                    p.name = item.getName();
                    p.id = item.getId();
                    p.price = item.getPrice();

                    cout << "quantity:";
                    cin >> quantity;

                    // จำนวนสินค้าต้องเป็นเลขจำนวนเต็มบวก
                    if(quantity <= 0) {
                        cout << "Error: invalid quantity!";
                        return;
                    } else if((quantity <= item.getStock()) && (item.getStock() != 0) && ((item.getStock() - quantity) >= 0)){
                        isValid = true;
                        data.at(i).setStock(item.getStock() - quantity);
                    } else {
                        cout << "Error: The quantity of products ordered is greater than the quantity of products in stock.";
                        return;
                    }
                }
            }

            if(isValid){
                total = quantity * p.price;
                cout << p.name << " amount = " << quantity << " total = " << total << endl;
                File().write();
            }

        } else {
            cout << "Error: " << input << "is not in stock!" << endl;
        }
    }
};

// function แสดงตัวเลือกการทำงานของโปรแกรม
void showOptions(){
    cout << endl << endl << "Program" << endl;
    cout << "1.) Show list of all products" << endl;
    cout << "2.) Add product" << endl;
    cout << "3.) Delete product" << endl;
    cout << "4.) Edit product" << endl;
    cout << "5.) sell proudcts" << endl;
    cout << "6.) Exit program" << endl;
    cout << "Enter a number:";
}

int main(){
    // สร้าง opject ไฟล์เพื่อจัดการกับไฟล์ข้อมูล
    File file = File();
    // เริ่มโปรแกรมให้อ่านข้อมูลจากไฟล์ data.txt แล้วมาเก็บไว้ในตัวแปร data
    file.read();

    // ตัวเลือกที่ผู้ใช้งานเลือกว่าจะใช้ง่านคำสั่งอะไร
    int select;
    // วน loop ไปเรื่อยๆเพื่อรอผให้ผู้ใช้งานป้อนตัวเลขให้โปรแกรมทำงานตามหมายเลขนั้น
    while(true){
        showOptions();
        cin >> select;

        // แสดงรายการสินค้าทั้งหมด
        if(select == 1){
            ProductManagement::showListProducts();
        }
        // สั่งซื้อสินค้า
        else if(select == 2){
            ProductManagement::sellProducts();
        }
        // เพิ่มสินค้า
        else if(select == 3){
            ProductManagement::addProduct();
        }
        // ลบสินค้า
        else if(select == 4){
            ProductManagement::deleteProduct();
        }
        // แก้ไขสินค้า
        else if(select == 5){
            ProductManagement::editProduct();
        }
        // ออกจากโปรแกรม
        else if(select == 6){
            cout << endl << "Exit The Program." << endl;
            break;
        }
        // ไม่มีในตัวเลือกวน loop ให้เลือกใหม่
        else {
            cout << endl << select << " is not available. Please select a number between 1 - 6" << endl;
        }
    };

    return 0;
}