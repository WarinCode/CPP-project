/*  Documents
 *  https://marcuscode.com/lang/cpp/files
 *  https://medium.com/@vachirachat.saw/%E0%B9%82%E0%B8%84%E0%B8%A3%E0%B8%87%E0%B8%AA%E0%B8%A3%E0%B9%89%E0%B8%B2%E0%B8%87%E0%B8%82%E0%B9%89%E0%B8%AD%E0%B8%A1%E0%B8%B9%E0%B8%A5%E0%B8%95%E0%B9%88%E0%B8%B2%E0%B8%87%E0%B9%86%E0%B9%83%E0%B8%99-c-1ccdb706c38e
 *  https://www.devdit.com/post/4200/c-plus-plus-vector-%E0%B8%84%E0%B8%B7%E0%B8%AD%E0%B8%AD%E0%B8%B0%E0%B9%84%E0%B8%A3-%E0%B8%97%E0%B8%B3%E0%B8%87%E0%B8%B2%E0%B8%99%E0%B8%A2%E0%B8%B1%E0%B8%87%E0%B9%84%E0%B8%87#gsc.tab=0
 *  https://medium.com/@marktbss/c-hackerrank-vector-erase-11c65b830a43
 *  https://www.geeksforgeeks.org/how-to-clear-console-in-cpp
 */

/* รายชื่อสมาชิกในกลุ่มที่เขียนโปรแกรมนี้
 * 1. นาย วรินทร์ สายปัญญา รหัสนิสิต 6630250435 หมู่เรียน ภาคปฎิบัติ 881
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
#define NUMBER_CATEGORIES 16
// ประเภท หรือ หมวดหมู่สินค้า
// ยึดตาม ตย.รูปภาพนี้ http://ctnphrae.com/ckfinder/userfiles/images/%E0%B8%97%E0%B8%94%E0%B8%AA%E0%B8%AD%E0%B8%9A%E0%B8%AB%E0%B8%B2%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%AA%E0%B8%B4%E0%B8%97%E0%B8%98%E0%B8%B4%E0%B8%A0%E0%B8%B2%E0%B8%9E%E0%B9%80%E0%B8%A7%E0%B9%87%E0%B8%9A%E0%B9%84%E0%B8%8B%E0%B8%95%E0%B9%8C.png
const string productCategories[NUMBER_CATEGORIES] = { "phone", "tablet", "laptop", "computer", "car",
                                     "health and beauty","game", "bag", "electrical appliance", "pet",
                                     "camera", "shoes", "watch", "sport", "musical instrument",
                                     "furniture"
};
// สร้่าง struct ไว้จัดการเก็บข้อมูลเป็นกลุ่มเมื่อ loop ข้อมูลมาจากตัวแปร data ได้
typedef struct {
    string name;
    int id;
    float price;
    int stock;
    string category;
    int quantity;
    int sum;
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
            // loop ข้อมูลตัวแปร orders
            for(product order : orders){
                // เขียนข้อมูลสินค้าที่สั่งซื้อ
                writeFile << "name = " <<  order.name << ",\tprice = " << order.price << ",\t quantity = " << order.quantity << ",\t category = " << order.category << endl;
            }
            // เขียนสรุป ยอดจำนวนเงิน และ จำนวนที่สั่งซื้อ
            writeFile << endl << "Total number of products = " << totalNumbers << endl;
            writeFile << "Total amount = " << totalAmount << endl;
            // เขียนเส้นตัดบรรทัด
            for(int i = 1; i <= 60; i++){
                writeFile <<  "-";
                i == 40 && writeFile << endl;
            }
            showMessage && cout << "Write file completed." << endl;
        } else {
            showMessage && cout << "Error: Cannot open file orders.txt to write data!" << endl;
        }
        writeFile.close();
    }

    // method อัปเดตข้อมูลล่าสุดของไฟล์ data.txt และ ตัวแปรที่เก็บข้อมูลสินค้า data
    static void update(){
        write();
        read();
    }
};

// สร้าง class หมวดหมู่สินค้า หรือ ประเภทสินค้าต่อไปนี้ โดยให้ subclass(หมวดหมู่สินค้า) สืบทอดคุณสมบัติทุกอย่าง ของ superclass(class สินค้า)
// Subclass
class Phone: public Product {
public:
    Phone(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[0]){}
    Phone(): Product(productCategories[0]){}
};

// Subclass
class Tablet: public Product {
public:
    Tablet(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[1]){}
    Tablet(): Product(productCategories[1]){}
};

// Subclass
class Laptop: public Product {
public:
    Laptop(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[2]){}
    Laptop(): Product(productCategories[2]){}
};

// Subclass
class Computer: public Product {
public:
    Computer(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[3]){}
    Computer(): Product(productCategories[3]){}
};

// Subclass
class Car: public Product {
public:
    Car(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[4]){}
    Car(): Product(productCategories[4]){}
};

// Subclass
class HealthAndBeauty: public Product {
public:
    HealthAndBeauty(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[5]){}
    HealthAndBeauty(): Product(productCategories[5]){}
};

// Subclass
class Game: public Product {
public:
    Game(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[6]){}
    Game(): Product(productCategories[6]){}
};

// Subclass
class Bag: public Product {
public:
    Bag(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[7]){}
    Bag(): Product(productCategories[7]){}
};

// Subclass
class ElectricalAppliance: public Product {
public:
    ElectricalAppliance(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[8]){}
    ElectricalAppliance(): Product(productCategories[8]){}
};

// Subclass
class Pet: public Product {
public:
    Pet(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[9]){}
    Pet(): Product(productCategories[9]){}
};

// Subclass
class Camera: public Product {
public:
    Camera(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[10]){}
    Camera(): Product(productCategories[10]){}
};

// Subclass
class Shoes: public Product {
public:
    Shoes(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[11]){}
    Shoes(): Product(productCategories[11]){}
};

// Subclass
class Watch: public Product {
public:
    Watch(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[12]){}
    Watch(): Product(productCategories[12]){}
};

// Subclass
class Sport: public Product {
public:
    Sport(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[13]){}
    Sport(): Product(productCategories[13]){}
};

// Subclass
class MusicalInstrument: public Product {
public:
    MusicalInstrument(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[14]){}
    MusicalInstrument(): Product(productCategories[14]){}
};

// Subclass
class Furniture: public Product {
public:
    Furniture(int Id, string Name, float Price, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[15]){}
    Furniture(): Product(productCategories[15]){}
};

// class ProductManagement มีหน้าที่จัดการเกี่ยวกับสินค้าต่างๆ
class ProductManagement {
public:

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

    // method (override) เฉพาะสำหรับตรวจสอบเลข id
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
        for(string c : productCategories){
            if(c == category){
                return true;
            }
        }
        return false;
    }

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

    // method แสดงสินค้าเฉพาะสินค้าหมวดหมู่นั้น
    static void showProductCategories(){
        string category;
        cout << "Enter category:";
        cin >> category;

        // เช็คว่าอยู่ในหมวดหมู่สินค้านั้นหรือไม่
        if(isCategory(category)){
            int number = 1;
            // ตรวจสอบว่ามีสินค้านั้นอยู่ในคลังหรือไม่
            bool inStock = false;
            // loop ข้อมูลสินค้า
            for(Product item : data){
                // แสดงสินค้าเฉพาะหมวดหมู่สินค้าที่เลือก
                if(item.getCategory() == category){
                    cout << "No: " << number << "\tID: " << item.id << "\tName: " << item.name << "\tPrice: " << item.price << "\tStock: "<< item.stock << "\tCategory: " << item.category << endl;
                    inStock = true;
                    number++;
                }
            }
            // ไม่มีสินค้าหมวดนี้อยู่ในคลังสินค้า
            if(!inStock){
                cout << "No product category " <<  "\"" << category << "\"" << " in stock" << endl;
            }

        } else {
            cout << "Error: " << "\"" << category << "\"" << " is not in categories of products" << endl;
        }
    }

    // method เพิ่มสินค้า
    static void addProduct(){
        string selectCategory;

        cout << "Product categories ";
        char comma = ',';
        int count = 0;
        // แสดงหมวดหมู่ของสินค้าที่สามารถเพิ่มได้
        for(string category : productCategories){
            cout << "\"" << category << "\"";
            if(count != NUMBER_CATEGORIES - 1) cout << comma << ' ';
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

            // สร้าง array ชื่อ products ทำหน้าที่เก็บหมวดหมู่สินค้าทั้งหมด
            Product products[NUMBER_CATEGORIES] = {
                    Phone(), Tablet(), Laptop(), Computer(), Car(), HealthAndBeauty(),
                    Game(), Bag(), ElectricalAppliance(), Pet(),
                    Camera(), Shoes(), Watch(), Sport(), MusicalInstrument(),
                    Furniture()
            };

            for(int i = 0; i < NUMBER_CATEGORIES; i++){
                // เช็คหมวดหมู่สินค้าว่าตรงกันไหม
                if(selectCategory == products[i].getCategory()){
                    // แก้ไขค่า สมาชิกใน array (แก้ไข ชื่อสินค้า รหัสสินค้า และ ราคา)
                    products[i].setId(p.id);
                    products[i].setName(p.name);
                    products[i].setPrice(p.price);
                    // นำ newProduct เป็นค่า element ตัวนั้น
                    newProduct = products[i];
                    // หยุด loop
                    break;
                }
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
                            // แก้ไขชื่อสินค้า
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
                            // แก้ไขรหัสสินค้า
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
                            // แก้ไขราคาสินค้า
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
                            return;
                        } else {
                            // แก้ไขหมวดหมู่สินค้า
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
            cout << "Error: " << "\"" << input << "\"" << " is not in data!" << endl;
        }
    }

    // method ในการขายสินค้า
    static void sellProducts(){
        string input;
        bool isRunning = true; // ตัวแปรควบคุมการทำงาน while loop ถ้ามีค่า true แปลยังสามารถสั่งสินค้าต่อได้เรื่อยๆ ถ้า false หยุดดำเนินการสั่งซื้อ
        char e; // ตัวแปร อักษร e(end) เมื่อผู้ใช้งานพิมพ์ตัวอักษร e คือจบการสั่งซื้อสินค้า
        vector<product> orders = {}; // รายการ orders สินค้าที่สั่งซื้อทั้งหมด
        product order; // order สินค้า 1 ที่สั่ง 1 รายการ

        cout << "Enter \"e\" to exit the sale." << endl;

        // loop ไปเรื่อยๆจนกว่าผู้ใช้จะพิมพ์ตัว e
        while(isRunning){
            cout << "Enter product name of product id:";
            cin >> input;

            // เอา substring ตัวแรกของตัวแปร input
            e = input.at(0);
            // เช็คว่าอักตรตัว e หรือไม่ ถ้าใช้ ให้ออกจากการขายสินค้า
            if(tolower(e) == 'e'){
                int total = 0; // จำนวนเงินทั้งหมด
                int quantity = 0; // จำนวนสินค้าทั้งหมด
                int i = 1; // ลำดับสินค้าที่สั่ง
                // ออกจากการขายสินค้าและคำนวณราคาสินค้าทั้งหมด
                isRunning = false;
                // ถ้ายังไม่มีการสั่งสินค้าไม่ต้องแสดงรายละเอียดการสั่งซื้อ
                if(orders.size() != 0){
                    cout << endl << "\t\tYou order products." << endl;
                    // คำนวณจำนวนเงินทั้งหมดที่สั่งสินค้า และ แสดงรายการสินค้าที่สั่งซื้อ
                    for(product item : orders){
                        // คำนวณยอดเงินสินค้าต่อ 1 รายการ
                        item.sum = item.quantity * item.price;
                        cout << i << ". " << "Product: "<< item.name << "\tPrice: " << item.price << "\tQuantity: " << item.quantity << "\t Total price: " << item.sum << endl;
                        // คำนวณเงินที่ต้องจ่ายทั้งหมดที่สั่งสินค้ามา
                        total += item.sum;
                        // เพิ่มจำนวนสินค้า
                        quantity += item.quantity;
                        i++;
                    }
                    // แสดงจำนวนเงินทั้งหมดที่ต้องจ่าย
                    cout << endl << "Total number of products = " << quantity << endl;
                    cout << "Total amount = " << total << endl;
                    // เขียนข้อมูลลงในไฟล์ orders.txt
                    File::write(orders, quantity, total);
                    // ลบรายการสินค้าทั้งหมดที่สั่ง
                    orders.clear();
                    // อัปเดตข้อมูล
                    File::update();
                }
            }
            // ดำเนินการสั่งสินค้าต่อ
            else {
                // เช็คว่า ชื่อ หรือ id ที่พิมพ์มาอยู่ใน data หรือไม่
                if(findProduct(input)){
                    int j = 0; // ตัวระบุเลข index ของ data
                    // loop ข้อมูลในตัวแปร data
                    for(Product item : data){
                        // เช็ค ชื่อ หรือ id ว่าตรงกับสินค้าที่เลือก
                        if(to_string(item.getId()) == input || item.getName() == input){
                            // เก็บ order สินค้าที่สั่ง
                            order.name = item.getName();
                            order.id = item.getId();
                            order.price = item.getPrice();
                            order.category = item.getCategory();
                            order.sum = 0; // ยอดรวมสินค้านั้นมีค่าเริ่มต้นเป็น 0

                            // รับค้าจำนวนสินค้าที่สั่ง
                            cout << "Quantity:";
                            cin >> order.quantity;

                            // จำนวนสินค้าต้องเป็นเลขจำนวนเต็มบวก
                            if(order.quantity <= 0) {
                                cout << "Error: invalid quantity!";
                                isRunning = false;
                                return;
                            }
                            // สินค้าในคลังหมดไม่สามารถสั่งได้
                            else if(item.getStock() == 0){
                                cout << "This product " << "\"" << item.getName() << "\"" << " is out of stock." << endl;
                            }
                            /* เงื่อนไข
                             * จำนวนที่สั่งต้องน้อยกวาหรือเท่ากับสินค้าในคลัง (จำนวนที่สั่งต้องไม่มากเกินจำนวนสินค้าในคลัง)
                             * สินค้าในคลังต้องไม่หมด (ถ้าสินค้าในคลังหมดไม่สามารถสั่งได้)
                             * ประมาณจำนวนสินค้านั้นในคลังก่อนเมื่อลองหักลบแล้วจำนวนสินค้าในคลังต้องไม่ติดลบ (ไม่สามารถสั่งเกินจำนวนสินค้าในคลังได้)
                             */
                            else if((order.quantity <= item.getStock()) && (item.getStock() != 0) && ((item.getStock() - order.quantity) >= 0)){
                                // จำนวนที่เหลือของสินค้าในคลัง โดยหักลบกับจำนวนสินค้าที่สั่ง
                                int remain = item.getStock() - order.quantity;
                                // เปลี่ยนค่าใน stock มีจำนวนสินค้าที่เหลือตาม remain
                                data.at(j).setStock(remain);
                                // เพิ่มสินค้าเข้าใน orders ที่สั่ง
                                orders.push_back(order);
                                // เขียนไฟลืข้อมูล
                                File::write();
                            }
                            // สั่งสินค้าเกินจำนวนในคลัง
                            else {
                                cout << "Error: The quantity of products ordered is greater than the quantity of products in stock.";
                                isRunning = false;
                                return;
                            }
                        }
                        j++;
                    }
                } else {
                    cout << "Error: " << "\"" << input << "\"" << " is not in data!" << endl;
                }
            }
        }
    }
};

// function แสดงตัวเลือกการทำงานของโปรแกรม
void showOptions(){
    cout << endl << "Program" << endl;
    cout << "1.) Show list of all products" << endl;
    cout << "2.) Show list of category" << endl;
    cout << "3.) Sell proudcts" << endl;
    cout << "4.) Add product" << endl;
    cout << "5.) Delete product" << endl;
    cout << "6.) Edit product" << endl;
    cout << "7.) Add product to stock" << endl;
    cout << "8.) Clear console screen" << endl;
    cout << "9.) Exit program" << endl;
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
        // แสดงเฉพาะหมวดหมู่สินค้าที่เลือก
        else if(select == 2){
            ProductManagement::showProductCategories();
        }
        // สั่งซื้อสินค้า
        else if(select == 3){
            ProductManagement::sellProducts();
        }
        // เพิ่มสินค้า
        else if(select == 4){
            ProductManagement::addProduct();
        }
        // ลบสินค้า
        else if(select == 5){
            ProductManagement::deleteProduct();
        }
        // แก้ไขสินค้า
        else if(select == 6){
            ProductManagement::editProduct();
        }
        // เพิ่มจำนวนสินค้าในคลัง
        else if(select == 7){
            ProductManagement::addStockProduct();
        }
        // ล้างหน้าจอ
        else if(select == 8){
            system("cls");
        }
        // ออกจากโปรแกรม
        else if(select == 9){
            cout << endl << "Exit The Program." << endl;
            break;
        }
        // ไม่มีในตัวเลือก
        else {
            cout << endl << select << " is not available. Please select a number between 1 - 6" << endl;
        }
    };

    return 0;
}