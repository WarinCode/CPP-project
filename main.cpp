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

// กำหนดจำนวนสินค้าตอนเริ่มต้น มี 20 จำนวน ของแต่ละสินค้า
#define STOCK 20
// ประเภทหมวดหมู่สินค้า
const string categories[] = { "phone", "tablet", "laptop", "computer" };
// สร้่าง struct ไว้จัดการเก็บข้อมูลเป็นกลุ่มเมื่อ loop ข้อมูลมาจากตัวแปร data ได้
typedef struct {
    string name;
    int id;
    float price;
    int stock;
    string category;
    int quantity;
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
    Product(int Id, string Name, float Price, int Stock = STOCK, string Category = "any"){
        // เมื่อสร้าง object ให้รับค่า arguments ที่ส่งมาจาก constructor แล้วมาเก็บไว้ใน attributes
        setId(Id);
        setName(Name);
        setPrice(Price);
        setStock(Stock);
        setCategory(Category);
    }
    // constructor method (override) สำหรับการสร้าง object ให้มีค่าเริ่มต้น
    Product(string Category = "any"){
        setId(0);
        setName("");
        setStock(STOCK);
        setCategory(Category);
    }

    // getter methods ให้ข้อมูลใน attribute
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

    // setter methods แก้ไขข้อมูลใน attribute
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
public:
    // method อ่านข้อมูลในไฟล์ data.txt แล้วมาเก็บไว้ในตัวแปร data
    static void read(string path = R"(C:\Users\ACER USER5949486\Desktop\CPP-project\txt\data.txt)", bool showMessage = false){
        // ตัวแปรสำหรับอ่านไฟลืข้อมูล
        ifstream readFile;
        // เปิดไฟล์อเพื่อ่านข้อมูล
        readFile.open(path ,ios::in);
        // เช็คว่าสามารถเเปิดไฟล์ได้หรือไม่
        if(readFile.is_open()){
            // ล้างข้อมูลทั้งหมดที่เก็บไว้ในตัวแปร data
            data.clear();
            string line;
            // loop อ่านไฟล์ data.txt ทีละบรรทัด
            while(std::getline(readFile, line)){
                // สร้าง object สินค้า
                Product getProducts = Product();
                // สร้างตัวแปร string stream สำหรับเก็บข้อความทีละบรรทัด
                stringstream ss(line);
                // ให้ตัวแปร ss นำเข้าข้อมูลสินค้าทีละตัวแปร
                ss >> getProducts.id >> getProducts.name >> getProducts.price >> getProducts.stock >> getProducts.category;
                // เก็บข้อมูลทีละ object
                data.push_back(getProducts);
            }
            showMessage && cout << "Read file completed." << endl;
        } else {
            showMessage && cout << "Error: Cannot open file data.txt to read data!" << endl;
        }
        readFile.close();
    };

    // method เขียนข้อมูลลงในไฟล์ data.txt ด้วยข้อมูล vector Product
    static void write(string path = R"(C:\Users\ACER USER5949486\Desktop\CPP-project\txt\data.txt)", bool showMessage = false){
        // ตัวแปรสำหรับเขียนไฟล์ข้อมูล
        ofstream writeFile;
        // เปิดไฟล์เพื่อเขียนข้อมูล
        writeFile.open(path, ios::out);
        // เช็คว่าสามารถเเปิดไฟล์ได้หรือไม่
        if(writeFile.is_open()){
            // loop ข้อมูลตัวแปร data
            for(Product item : data){
                // เขียนข้อมูลทีละบรรทัด โดยข้อมูลสินค้าแต่ละส่วนจะเว้นระยะห่าง 1 tab
                writeFile << item.id << "\t" << item.name << "\t" << item.price << "\t" << item.stock << "\t" << item.category << endl;
            }
            showMessage && cout << "Write file completed." << endl;
        } else {
            showMessage && cout << "Error: Cannot open file data.txt to write data!" << endl;
        }
        writeFile.close();
    }

    // method (override) เขียนข้อมูลรายการสินค้าที่สั่งซื้อไปลงไฟล์ orders.txt โดยเอาข้อมูลจาก parameter orders มาเขียน
    static void write(vector<product> orders, int totalNumbers, int totalAmount, string path = R"(C:\Users\ACER USER5949486\Desktop\CPP-project\txt\orders.txt)", bool showMessage = false){
        // ตัวแปรสำหรับเขียนไฟล์ข้อมูล
        ofstream writeFile;
        // เปิดไฟล์เพื่อเขียนข้อมูล
        writeFile.open(path, ios::app);
        // เช็คว่าสามารถเเปิดไฟล์ได้หรือไม่
        if(writeFile.is_open()){
            // loop ข้อมูลตัวแปร data
            for(product order : orders){
                writeFile << "name = " <<  order.name << "\tprice = " << order.price << "\t quantity = " << order.quantity << "\t category = " << order.category << endl;
            }

            writeFile << endl << "Total number of products = " << totalNumbers << endl;
            writeFile << "Total amount = " << totalAmount << endl;

            for(int i = 1; i <= 60; i++){
                writeFile <<  "-";
                i == 40 && writeFile << endl;
            }
            showMessage && cout << "Write file completed." << endl;
        } else {
            showMessage && cout << "Error: Cannot open file data.txt to write data!" << endl;
        }
        writeFile.close();
    }

    // method อัปเดตข้อมูลล่าสุดของไฟล์ data.txt และ ตัวแปรที่เก็บข้อมูลสินค้า data
    static void update(){
        write();
        read();
    }
};

// Subclass
class Phone: public Product {
public:
    Phone(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, categories[0]){}
    Phone(): Product(categories[0]){}
};

// Subclass
class Tablet: public Product {
public:
    Tablet(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, categories[1]){}
    Tablet(): Product(categories[1]){}
};

// Subclass
class Laptop: public Product {
public:
    Laptop(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, categories[2]){}
    Laptop(): Product(categories[2]){}
};

// Subclass
class Computer: public Product {
public:
    Computer(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, categories[3]){}
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
            cout << endl << "\t\tList of all products" << endl;
            // แสดงรายการสินค้าทั้งหมด
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
            if(to_string(item.getId()) == key || item.getName() == key){
                return true;
            }
        }
        return false;
    }

    // (override) สำหรับตรวจสอบ id
    static bool findProduct(int id){
        for(Product item : data){
            if(item.getId() == id){
                return true;
            }
        }
        return false;
    }

    // method ตรวจสอบว่าเป็นหมวดหมู่สินค้าที่ได้กำหนดไว้ไหม ถ้าใช้คืน true ถ้าไม่คืน false
    static bool isCategory(string category){
        for(string c : categories){
            if(c == category){
                return true;
            }
        }
        return false;
    }

    // method เพิ่มสินค้า
    static void addProduct(){
        string selectCategory;

        cout << "Product categories ";
        char comma = ',';
        int count = 0;
        // แสดงหมวดหมู่ของสินค้าที่สามารถเพิ่มได้
        for(string category : categories){
            cout << "\"" << category << "\"";
            if(count != 3) cout << comma << ' ';
            count++;
        }

        cout << endl << "Select product category:";
        cin >> selectCategory;

        // ถ้ามีหมวดหมู่สินค้านั้นอยู่ในรายการ
        if(isCategory(selectCategory)){
            product p; // สร้างตัวแปร p เพิ่อมารอรับข้อมูลสินค้าใหม่
            Product newProduct; // ตัวแปรที่เก็บ object ของสินค้าที่เพิ่มเข้ามาใหม่

            // รับข้อมูลสินค้าใหม่ที่จะเพิ่ม
            cout << "Product Name:";
            cin >> p.name;
            // ตรวจสอบว่า name ว่าซ้ำกันไหม
            if(findProduct(p.name)){
                cout << "Error: The new product name must not be duplicated with the product that already has this name!" << endl;
                return;
            }
            cout << "Product ID:";
            cin >> p.id;
            // ตรวจสอบว่า id ซ้ำกันไหม
            if(findProduct(p.id)){
                cout << "Error: The new product id must not be duplicated with the product that already has this id!" << endl;
                return;
            }
            cout << "Pricing:";
            cin >> p.price;

            // ตรวจสอบว่าเป็นหมวดหมู่ของสินค้าอันไหน แล้วจากนั้นให้สร้าง object ของสินค้าแต่ละประเภท
            // หลังจากนั้นให้ตัวแปร newProduct เก็บค่า object ตัวนั้น
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
            // นำ newProduct ที่ได้เพิ่มเข้าในรายการสินค้า data
            data.push_back(newProduct);
            // update รายการสินค้าล่าสุดของไฟลื data.txt และ ข้อมูล data
            File::update();

            cout << "Added a new product" << endl;
        } else {
            cout << "Error: " << "\"" << selectCategory << "\"" << " is not in categories of products" << endl;
        }
    }

    // method สำหรับเพิ่มจำนวนสินค้าใน stock
    static void addStockProduct(){
        string input;
        cout << "Enter the product name or product id:";
        cin >> input;

        // ถ้ามีสินค้านั้นอย่ในข้อมูล
        if(findProduct(input)){
            int number;
            int index = 0;
            // รับข้อมูล
            cout << "Amount:";
            cin >> number;

            // จำนวนสินค้าที่เพิ่มเข้ามาต้องเป็นเลขจำนวนเต็มบวก
            if(number <= 0){
                cout << "Invalid number. Please enter a positive number!" << endl;
                return;
            }

            // loop เช็คข้อมูลสินค้าทีละอัน เมื่อเช็คสินค้าเจอให้เพิ่มจำนวนสินค้าที่ระบุ
            for(Product item : data){
                // เช็ค ชื่อ หรือ id สินค้า ว่าตรงกันไหม
                if(input == to_string(item.getId()) || input == item.getName()){
                    // นำจำนวนค้าที่เหลือไปบวกกับจำนวนค้าที่เพิ่มเข้ามา
                    int remain = number + item.getStock();
                    // แก้ไขจำนวนใน stock
                    data.at(index).setStock(remain);
                    // เมื่อเจอสินค้าที่ระบุแล้วให้หยุด loop
                    break;
                }
                index++;
            }
            // อัปเดตข้อมูล
            File::update();
            cout << "Added new product quantity to stock" << endl;
        } else {
            cout << "Error: " << input << "is not in data!" << endl;
        }
    }

    // method ลบสินค้า
    static void deleteProduct() {
        string input;

        cout << "Enter the product name or product id:";
        cin >> input;

        // ถ้ามีสินค้านั้นอย่ในข้อมูล
        if (findProduct(input)) {
            int index = 0;
            // loop ข้อมูลใน data
            for (Product item : data) {
                // เช็คชื่อ และ id สินค้าว่าตรงกันไหม
                if (to_string(item.getId()) == input || item.getName() == input) {
                    // ลบสินค้า(สมาชิกใน data)ออกจากตัวแปร data โดยเอาเลข index เป็นตัวบ่งบอกตำแหน่งของสมาชิกใน data
                    data.erase(data.begin() + index);
                    // เมื่อเจอสินค้าที่ระบุแล้วให้หยุด loop
                    break;
                }
                index++;
            }
            cout << "Successfully deleted product" << endl;
            // อัปเดตข้อมูล
            File::update();
        } else {
            cout << "Error: " << input << " is not in data!" << endl;
        }
    }

    // method แก้ไขข้อมูลสินค้า
    static void editProduct() {
        string input;

        cout << "Enter the product name or product id:";
        cin >> input;

        // ถ้ามีสินค้านั้นอยู่ในข้อมูล
        if(findProduct(input)){
            int index = 0;
            // สร้างตัวแปรมารอรับข้อมูลที่ผู้ใช้งานป้อนเข้ามา
            product p;
            // คำตอบที่ผู้ใช้งานตอบมีแค่ y หรือ n เท่านั้น
            typedef struct {
                char yn1, yn2, yn3, yn4;
            } yesOrNo;
            yesOrNo yn;
            // loop ข้อมูลสินค้าทั้งหมด
            for (Product item : data) {
                // เช็คว่าเป็นสินค้าชิ้นนั้น
                if (to_string(item.getId()) == input || item.getName() == input) {
                    // ถามว่าต้องการแก้ไขข้อมูลสินค้าในส่วนไหนบ้างโดยตอบ y และ n
                    // ถ้าตอบ y ให้ดำเนินการแก้ไขข้อมูลในส่วนนั้น ถ้าตอบ n หรืออื่นๆคือผ่าน
                    // ถามว่าต้องการแก้ไขชื่อสินค้าไหม
                    cout << "Do you want to edit the product name (y/n):";
                    cin >> yn.yn1;
                    if(tolower(yn.yn1) == 'y'){
                        cout << "New product name:";
                        cin >> p.name;
                        // ตรวจสอบว่า name ที่แก้ไขว่าซ้ำกันกับข้อมูลที่มีแล้วไหม
                        if(findProduct(p.name)){
                            cout << "Error: Cannot edit to name " << "\"" <<p.name << "\"" << " because the name is the same as an existing product name." << endl;
                            return;
                        } else {
                            data.at(index).setName(p.name);
                        }
                    }

                    // ถามว่าต้องการแก้ไขชื่อรหัสสินค้าไหม
                    cout << "Do you want to edit the product id (y/n):";
                    cin >> yn.yn2;
                    if(tolower(yn.yn2) == 'y'){
                        cout << "New product id:";
                        cin >> p.id;
                        getchar();
                        // ตรวจสอบว่า name ที่แก้ไขว่าซ้ำกันกับข้อมูลที่มีแล้วไหม
                        if(findProduct(p.id)){
                            cout << "Error: Cannot edit to id " << "\"" <<p.id << "\"" << " because the id is the same as an existing product id." << endl;
                            return;
                        } else {
                            data.at(index).setId(p.id);
                        }
                    }

                    // ถามว่าต้องการแก้ไขราคาสินค้าไหม
                    cout << "Do you want to edit the product price (y/n):";
                    cin >> yn.yn3;
                    if(tolower(yn.yn3) == 'y'){
                        cout << "New product price:";
                        cin >> p.price;
                        // ตรวจสอบว่าเป็นเลขจำนวนเต็มบวกหรือไม่
                        if(p.price <= 0){
                            cout << "Error: Invalid price. Please enter a positive number!" << endl;
                            return;
                        } else {
                            data.at(index).setPrice(p.price);
                        }
                    }

                    // ถามว่าต้องการแก้ไขหมวดหมู่สินค้าไหม
                    cout << "Do you want to edit the product category (y/n):";
                    cin >> yn.yn4;
                    if(tolower(yn.yn4) == 'y'){
                        cout << "New product category:";
                        cin >> p.category;
                        // ตรวจสอบว่าอยู่ในหมวดหมู่สินค้าที่ได้กำหนดไว้หรือไม่
                        if(!isCategory(p.category)){
                            cout << "Error: " << "\"" << p.category << "\"" << " is not in categories of products" << endl;
                        } else {
                            data.at(index).setCategory(p.category);
                        }
                    }
                    // เมื่อเจอสินค้าที่ระบุแล้วให้หยุด loop
                    break;
                }
                index++;
            }
            // อัปเดตข้อมูล
            File::update();
            cout << "Successfully edited product" << endl;
        } else {
            cout << "Error: " << input << " is not in stock!" << endl;
        }
    }

    // method ในการขายสินค้า
    static void sellProducts(){
        string input;
        bool isRunning = true;
        char e;
        // รายการสินค้าที่สั่งซื้อ
        vector<product> list = {};
        // สินค้า 1 อย่างที่สั่งซือ
        product p;

        cout << "Enter \"e\" to exit the sale." << endl;

        // loop ไปเรื่อยๆจนกว่าผู้ใช้จะพิมพ์ตัว e
        while(isRunning){
            cout << "Enter product name of product id:";
            cin >> input;

            // เอาอักษรตัวแรกของ string input
            e = input.at(0);
            // เช็คว่าอักตรตัว e หรือไม่ ถ้าใช้ ให้ออกจากการขายสินค้า
            if(tolower(e) == 'e'){
                int total = 0; // จำนวนเงินทั้งหมด
                int quantity = 0; // จำนวนสินค้าทั้งหมด
                int i = 1; // ลำดับสินค้าที่สั่ง
                // ออกจากการขายสินค้าและคำนวณราคาสินค้าทั้งหมด
                isRunning = false;

                if(list.size() != 0){
                    cout << endl << "\t\tYou order products." << endl;

                    // คำนวณจำนวนเงินทั้งหมดที่สั่งสินค้า และ แสดงรายการสินค้าที่สั่งซื้อ
                    for(product item : list){
                        cout << i << ". " << "Product: "<< item.name << "\tPrice: " << item.price << "\tQuantity: " << item.quantity << "\t Total price: " << (item.quantity * item.price) << endl;
                        // คำนวณเงินที่ต้องจ่ายทั้งหมดที่สั่งสินค้ามา
                        total += item.price * item.quantity;
                        // เพิ่มจำนวนสินค้า
                        quantity += item.quantity;
                        i++;
                    }
                    // แสดงจำนวนเงินทั้งหมดที่ต้องจ่าย
                    cout << endl << "Total number of products = " << quantity << endl;
                    cout << "Total amount = " << total << endl;

                    File::write(list, quantity, total);
                    // ลบรายการสินค้าทั้งหมดที่สั่ง
                    list.clear();
                    File::update();
                }
            } else {
                // เช็คว่า ชื่อ หรือ id ที่พิมพ์มาอยู่ใน data หรือไม่
                if(findProduct(input)){
                    int j = 0;
                    for(Product item : data){
                        if(to_string(item.getId()) == input || item.getName() == input){
                            p.name = item.getName();
                            p.id = item.getId();
                            p.price = item.getPrice();
                            p.category = item.getCategory();

                            cout << "quantity:";
                            cin >> p.quantity;

                            // จำนวนสินค้าต้องเป็นเลขจำนวนเต็มบวก
                            if(p.quantity <= 0) {
                                cout << "Error: invalid quantity!";
                                isRunning = false;
                                return;
                            } else if((p.quantity <= item.getStock()) && (item.getStock() != 0) && ((item.getStock() - p.quantity) >= 0)){
                                data.at(j).setStock(item.getStock() - p.quantity);
                                list.push_back(p);
                                File::write();
                            } else {
                                cout << "Error: The quantity of products ordered is greater than the quantity of products in stock.";
                                isRunning = false;
                                return;
                            }
                        }
                        j++;
                    }
                } else {
                    cout << "Error: " << input << " is not in data!" << endl;
                }
            }
        }
    }
};

// function แสดงตัวเลือกการทำงานของโปรแกรม
void showOptions(){
    cout << endl << "Program" << endl;
    cout << "1.) Show list of all products" << endl;
    cout << "2.) Sell proudcts" << endl;
    cout << "3.) Add product" << endl;
    cout << "4.) Delete product" << endl;
    cout << "5.) Edit product" << endl;
    cout << "6.) Add product to stock" << endl;
    cout << "7.) Exit program" << endl;
    cout << "Enter a number:";
}

int main(){
    // เริ่มโปรแกรมให้อ่านข้อมูลจากไฟล์ data.txt แล้วมาเก็บไว้ในตัวแปร data
    File::read();

    // ตัวเลือกที่ผู้ใช้งานเลือกว่าจะใช้ง่านคำสั่งอะไร
    int select;
    // วน loop ไปเรื่อยๆเพื่อรอให้ผู้ใช้งานป้อนตัวเลขให้โปรแกรมทำงานตามหมายเลขนั้น
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
        // เพิ่มจำนวนสินค้าในคลัง
        else if(select == 6){
            ProductManagement::addStockProduct();
        }
        // ออกจากโปรแกรม
        else if(select == 7){
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