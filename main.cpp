/*  Documents
 *  https://marcuscode.com/lang/cpp/files
 *  https://medium.com/@vachirachat.saw/%E0%B9%82%E0%B8%84%E0%B8%A3%E0%B8%87%E0%B8%AA%E0%B8%A3%E0%B9%89%E0%B8%B2%E0%B8%87%E0%B8%82%E0%B9%89%E0%B8%AD%E0%B8%A1%E0%B8%B9%E0%B8%A5%E0%B8%95%E0%B9%88%E0%B8%B2%E0%B8%87%E0%B9%86%E0%B9%83%E0%B8%99-c-1ccdb706c38e
 *  https://www.devdit.com/post/4200/c-plus-plus-vector-%E0%B8%84%E0%B8%B7%E0%B8%AD%E0%B8%AD%E0%B8%B0%E0%B9%84%E0%B8%A3-%E0%B8%97%E0%B8%B3%E0%B8%87%E0%B8%B2%E0%B8%99%E0%B8%A2%E0%B8%B1%E0%B8%87%E0%B9%84%E0%B8%87#gsc.tab=0
 *  https://medium.com/@marktbss/c-hackerrank-vector-erase-11c65b830a43
 *  https://www.geeksforgeeks.org/how-to-clear-console-in-cpp
 *  https://www.javatpoint.com/cpp-date-and-time
 *  https://github.com/seleznevae/libfort
 *  https://seleznevae.github.io/libfort/index.html
 *  https://cplusplus.com/reference/cstdlib/rand
 *  https://github.com/ikalnytskyi/termcolor
 *  https://termcolor.readthedocs.io/#
 *  https://www.geeksforgeeks.org/std-string-replace-in-cpp/
 */

/* รายชื่อสมาชิกในกลุ่มที่เขียนโปรแกรมนี้
 * 1. นาย วรินทร์ สายปัญญา รหัสนิสิต 6630250435 หมู่เรียน ภาคปฎิบัติ 881
*/

/* ข้อบังคับการใช้งานโปรแกรม
 * 1. การตั้งชื่อสินค้าต้องตั้งชื่อที่ติดกันไม้เว้นวรรคเพราะหากตั้งชื่อที่มีความยาวและก็เว้นวรรคชื่อจะทำให้การอ่านไฟล์ข้อมูลผิดพลาดหากจะจำเป็นต้องตั้งชื่อยาวให้ใช้ - หรือ _
 * ขั้นแต่ละคำไว้
 * 2. การแก้ไขไฟล์ data.txt มีผลโดยตรงต่อตัวโปรแกรมเพราะฉะนั้นห้ามแก้ไขไฟล์ data.txt เด็ดขาด
 * 3. ห้ามย้ายไฟล์ หรือ ลบโฟลเดอร์ txt เพราะจะมีผลกับการอ่านเขียนข้อมูลในตัวโปรแกรม หัามลบโฟลเดอร์ txt และ ไฟล์ data.txt เด็ดขาด
 * 4. หากมีผู้ใดสนใจจะนำโปรแกรมนี้ไปพัฒนาต่อยอดสามารถเชิญนำไปพัฒนาต่อได้เลย
 * 5. ห้าม คัดลอก (copy code) ไฟล์โปรเจค main.cpp ไปส่งเป็นงานโปรเจคคของกลุ่มตัวเองเป็นเด็ดขาด ถ้าหากจับว่าจับได้ จะไปฟ้องอาจารย์
 **/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fort.hpp>
#include <termcolor/termcolor.hpp>

using namespace std;
using namespace fort;
using namespace termcolor;

// กำหนดจำนวนสินค้าตอนเริ่มต้น มี 20 จำนวน ของแต่ละสินค้า
#define STOCK 20
#define NUMBER_CATEGORIES 17
// ประเภท หรือ หมวดหมู่สินค้า
const string productCategories[NUMBER_CATEGORIES] = { "phone", "tablet", "laptop", "computer", "car",
                                                      "health and beauty","game", "bag", "electrical appliance", "pet",
                                                      "camera", "shoes", "watch", "sport", "musical instrument",
                                                      "furniture", "food"
};
// สร้่าง struct ไว้จัดการเก็บข้อมูลเป็นกลุ่มเมื่อ loop ข้อมูลมาจากตัวแปร data ได้
typedef struct {
    string name;
    int id;
    float price;
    int stock;
    string category;
    string brand;
    int quantity;
    float sum;
} product;

//  namespace ของโปรแกรมไว้เก็บ function ที่ไว้ใช้งาน
namespace program{
    // ประกาศ function prototypes ไว้ล่วงหน้า
    void showOptions();
    void showErrorMessage(string message);
    void showErrorMessage();
    void showSuccessfulMessage(string message);
    int generateId(int from, int to);
    // ประกาศ vector เพื่อเก็บข้อความ error แล้วนำไปแสดงผ่าน function showErrorMessage ที่เป็น overloading
    vector<string> err = {};
}
using program::err;

// class Time สำหรับการใช้บอกวันเวลาปัจจุบัน
class Time{
public:
    time_t now; // เวลาปัจจุบัน
    string dt; // datetime
    tm* ltm; // localtime ต้องใช้เป็น pointer

    // attributes วันที่และเวลา
    int year;
    int month;
    int weekday;
    int day;
    int hours;
    int minutes;
    int seconds;

    // array วัน และ เดือน
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    string months[12] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    // constructor method
    Time(){
        // เวลาปัจจุบัน
        now = time(0);
        // ส่ง address now เข้าไปใน function ctime และ localtime
        dt = ctime(&now);
        ltm = localtime(&now);
        // เข้าถึงตัวแปรข้างในของ struct tm
        hours = ltm -> tm_hour;
        minutes = ltm -> tm_min;
        seconds = ltm -> tm_sec;
        year = ltm -> tm_year + 1900; // ต้องบวก 1900 ไปด้วยถึงจะเป็นปีล่าสุด
        // attribute month และ weekday ใช้คู่กับ array ได้เพราะสามารถใช้เลขเป็นเลข index ของ array
        month = ltm -> tm_mon; // เลขระหว่าง 0 - 11
        weekday = ltm -> tm_wday; // เลขระหว่าง 1 - 6
        day = ltm -> tm_mday; // วันที่ เลขระหว่าง
    }

    // getter methods
    string getDate(){
        return dt;
    }
    int getYear(){
        return year;
    }
    int getMonth(){
        // ต้องบวก 1 เพราะ tm_mon คืนเลขกลับมาเป็น 1 - 11
        return month + 1;
    }
    int getDay(){
        return day;
    }
    int getHours(){
        return hours;
    }
    int getMinutes(){
        return minutes;
    }
    int getSeconds(){
        return seconds;
    }
    // คืนกลับมาเป็นข้อความ สมาชิกใน array
    string getDays(){
        return days[weekday];
    }
    string getMonths(){
        // ลบเลขออกไป 1 ถึงจะใช้เลข index 1 - 11 ได้พอดี
        return months[getMonth() - 1];
    }
};

// Superclass class Product เป็น class ต้นแบบที่ให้ subclass สืบทอดคุถสมบัติและพฤติกรรมต่างๆของคลาสนี้
class Product {
public:
    // attributes
    int id; // รหัสสินค้า
    string name; // ชื่อสินค้า
    float price; // ราคาสินค้า
    int stock; // จำนวนสินค้าที่เก็บไว้ในคลัง
    string category; // ประเภทของสินค้า
    string brand; // แบรนด์ของสินค้า

    // constructor method
    Product(int Id, string Name, float Price, int Stock = STOCK, string Category = "any", string Brand = "no-brand-name"){
        // เมื่อสร้าง object ให้รับค่า arguments ที่ส่งมาจาก constructor แล้วมาเก็บไว้ใน attributes
        setId(Id);
        setName(Name);
        setPrice(Price);
        setStock(Stock);
        setCategory(Category);
        setBrand(Brand);
    }
    // constructor method (overloading) สำหรับการสร้าง object ให้มีค่าเริ่มต้น
    Product(string Category = "any", string Brand = "no-brand-name"){
        setId(0);
        setName("");
        setStock(STOCK);
        setCategory(Category);
        setBrand(Brand);
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
    }
    string getBrand(){
        return brand;
    }

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
    void setBrand(string Brand){
        brand = Brand;
    }
};
// จุดสำคัญของโปรแกรม
// สร้างตัวแปร data เก็บข้อมูลสินค้าทั้งหมดจากในไฟลื data.txt และ ข้อมูล ที่ เพิ่ม ลบ แก้ไขเข้ามา
vector<Product> data = {};

// class File ใช้ในการจัดการไฟล์ data.txt เพื่อเขียนและอ่านข้อมูล
class File {
public:
    // method อ่านข้อมูลในไฟล์ data.txt แล้วมาเก็บไว้ในตัวแปร data
    static void read(string path = R"(C:\Users\ACER USER5949486\Desktop\CPP-project\txts\data.txt)", bool showMessage = false){
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
                // ในไฟลื data.txt จะอ่านข้อมูลตามนี้ในแต่ละบรรทัด: id   name    price   stock   brand   category
                ss >> getProducts.id >> getProducts.name >> getProducts.price >> getProducts.stock >> getProducts.brand >>getProducts.category;
                // เก็บข้อมูลทีละ object
                data.push_back(getProducts);
            }
            if(showMessage) program::showSuccessfulMessage("Read file completed.");
        } else {
            if(showMessage) program::showErrorMessage("Cannot open file data.txt to read data!");
        }
        readFile.close();
    };

    // method เขียนข้อมูลลงในไฟล์ data.txt ด้วยข้อมูล vector Product
    static void write(string path = R"(C:\Users\ACER USER5949486\Desktop\CPP-project\txts\data.txt)", bool showMessage = false){
        // ตัวแปรสำหรับเขียนไฟล์ข้อมูล
        ofstream writeFile;
        // เปิดไฟล์เพื่อเขียนข้อมูล
        writeFile.open(path, ios::out);
        // เช็คว่าสามารถเเปิดไฟล์ได้หรือไม่
        if(writeFile.is_open()){
            // loop ข้อมูลตัวแปร data
            for(Product item : data){
                // เขียนข้อมูลทีละบรรทัด โดยข้อมูลสินค้าแต่ละส่วนจะเว้นระยะห่าง 1 tab
                writeFile << item.getId() << "\t" << item.getName() << "\t" << item.getPrice() << "\t" << item.getStock() << "\t" << item.getBrand() << "\t" << item.getCategory() << endl;
            }
            if(showMessage) program::showSuccessfulMessage("Write file completed.");
        } else {
            if(showMessage) program::showErrorMessage("Cannot open file data.txt to write data!");
        }
        writeFile.close();
    }

    // method (overloading) เขียนข้อมูลรายการสินค้าที่สั่งซื้อไปลงไฟล์ orders.txt โดยเอาข้อมูลจาก parameter orders มาเขียน
    static void write(vector<product> orders, int totalNumbers, float totalAmount, string path = R"(C:\Users\ACER USER5949486\Desktop\CPP-project\txts\orders.txt)", bool showMessage = false){
        // ตัวแปรสำหรับเขียนไฟล์ข้อมูล
        ofstream writeFile;
        // เปิดไฟล์เพื่อเขียนข้อมูล
        writeFile.open(path, ios::app);
        // เช็คว่าสามารถเเปิดไฟล์ได้หรือไม่
        if(writeFile.is_open()){
            int i = 1;
            // สร้าง object time
            Time time = Time();
            // เขียนเวลาล่าสุดที่เขียนในไฟล์ orders.txt
            writeFile << "DATE: " << time.getDate();
            writeFile << "LIST:" << endl;
            // loop ข้อมูลตัวแปร orders
            for(product order : orders){
                // เขียนข้อมูลสินค้าที่สั่งซื้อ
                writeFile << i << ".) " << "PRODUCT_NAME = " <<  order.name << ",\t\tID = " << order.id << ",\t\tPRICE = " << order.price << ",\t\t QUANTITY = " << order.quantity << ",\t\t SUM = " << order.sum << ",\t\t BRAND = " << order.brand << ",\t\t CATEGORY = " << order.category << endl;
                i++;
            }
            // เขียนสรุป จำนวนที่สั่งซื้อ และ ยอดจำนวนเงิน
            writeFile << "CONCLUSION:" << endl;
            writeFile << "Total number of products = " << totalNumbers << endl;
            writeFile << "Total amount = " << totalAmount << " dollar." << endl;
            // เขียนเส้นตัดบรรทัดจบ
            for(int j = 1; j <= 170; j++){
                writeFile <<  "-";
                j == 170 && writeFile << endl;
            }
            if(showMessage) program::showSuccessfulMessage("Write file completed.");
        } else {
            if(showMessage) program::showErrorMessage("Cannot open file orders.txt to write data!");
        }
        writeFile.close();
    }

    // method อัปเดตข้อมูลล่าสุดของไฟล์ data.txt และ ตัวแปรที่เก็บข้อมูลสินค้า data
    static void update(string path = R"(C:\Users\ACER USER5949486\Desktop\CPP-project\txts\data.txt)"){
        write(path);
        read(path);
    }
};

// สร้าง class หมวดหมู่สินค้า หรือ ประเภทสินค้าต่อไปนี้ โดยให้ subclass(หมวดหมู่สินค้า) สืบทอดคุณสมบัติทุกอย่าง ของ superclass(class สินค้า)
// Subclass
class Phone: public Product {
public:
    Phone(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[0], Brand){}
    Phone(): Product(productCategories[0]){}
};

// Subclass
class Tablet: public Product {
public:
    Tablet(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[1], Brand){}
    Tablet(): Product(productCategories[1]){}
};

// Subclass
class Laptop: public Product {
public:
    Laptop(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[2], Brand){}
    Laptop(): Product(productCategories[2]){}
};

// Subclass
class Computer: public Product {
public:
    Computer(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[3], Brand){}
    Computer(): Product(productCategories[3]){}
};

// Subclass
class Car: public Product {
public:
    Car(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[4], Brand){}
    Car(): Product(productCategories[4]){}
};

// Subclass
class HealthAndBeauty: public Product {
public:
    HealthAndBeauty(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[5], Brand){}
    HealthAndBeauty(): Product(productCategories[5]){}
};

// Subclass
class Game: public Product {
public:
    Game(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[6], Brand){}
    Game(): Product(productCategories[6]){}
};

// Subclass
class Bag: public Product {
public:
    Bag(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[7], Brand){}
    Bag(): Product(productCategories[7]){}
};

// Subclass
class ElectricalAppliance: public Product {
public:
    ElectricalAppliance(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[8], Brand){}
    ElectricalAppliance(): Product(productCategories[8]){}
};

// Subclass
class Pet: public Product {
public:
    Pet(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[9], Brand){}
    Pet(): Product(productCategories[9]){}
};

// Subclass
class Camera: public Product {
public:
    Camera(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[10], Brand){}
    Camera(): Product(productCategories[10]){}
};

// Subclass
class Shoes: public Product {
public:
    Shoes(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[11], Brand){}
    Shoes(): Product(productCategories[11]){}
};

// Subclass
class Watch: public Product {
public:
    Watch(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[12], Brand){}
    Watch(): Product(productCategories[12]){}
};

// Subclass
class Sport: public Product {
public:
    Sport(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[13], Brand){}
    Sport(): Product(productCategories[13]){}
};

// Subclass
class MusicalInstrument: public Product {
public:
    MusicalInstrument(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[14], Brand){}
    MusicalInstrument(): Product(productCategories[14]){}
};

// Subclass
class Furniture: public Product {
public:
    Furniture(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[15], Brand){}
    Furniture(): Product(productCategories[15]){}
};

// Subclass
class Food: public Product {
public:
    Food(int Id, string Name, float Price, string Brand, int Stock = STOCK): Product(Id, Name, Price, Stock, productCategories[16], Brand){}
    Food(): Product(productCategories[16]){}
};

// class สำหรับแสดงตารางสินค้าจากข้อมูลของตัวแปร data หรือ จากค่า argument ที่ส่งมา
class Table{
private:
    // ตารางสำหรับแสดงสินค้า
    char_table table;
    int number; // ตัวเลขอันดับสินค้าใน column No
public:
    // constructor method สำหรับตั้งค่าเริ่มต้นในการสร้างตาราง
    Table(){
        // ค่าเริ่มต้นของอันดับตัวเลขสินค้ามีค่าเป็น 1
        number = 1;
        // เปลี่ยนเส้นขอบของตาราง
        table.set_border_style(FT_BASIC2_STYLE);
        // จัดกึ่งกลางเนื้อหาของตาราง
        table.set_cell_text_align(text_align::center);
    }

    // method แสดงตารางสินค้า
    void showTable(){
        if(data.size() == 0){
            cout << on_magenta << grey <<  "Out of stock!" << reset << endl;
        } else {
            cout << endl << "\t\t\t" << on_bright_white << grey << "List of all products" << reset << endl;
            // สร้างส่วนหัวของตารางโดยมีแต่ละ columds ตามนี้
            table << header << "No" <<"Product" << "ID" << "$Price" << "Stock" << "Brand" << "Category" << endr;
            // loop เอาข้อมูลที่ได้มาแสดงผลทีละ row
            for(Product item : data){
                table << number << item.getName() << item.getId() << item.getPrice() << item.getStock() << item.getBrand() << item.getCategory() << endr;
                number++;
            }
            // แสดงตาราง
            cout << endl << table.to_string() << endl;
        }
    }

    // method (overloading) สำหรับเแสดงตารางสินค้า orders สินค้าที่สั่งไป
    void showTable(vector<product> list){
        if(list.size() == 0){
            cout << on_magenta << grey << "Out of stock!" << reset << endl;
        } else {
            // สร้างส่วนหัวของตารางโดยมีแต่ละ columds ตามนี้
            table << header << "No" << "Product" << "ID" << "$Price" << "Quantity" << "Sum" << "Brand" << "Category" << endr;
            // loop เอาข้อมูลที่ได้มาแสดงผลทีละ row
            for(product item : list){
                table << number << item.name << item.id << item.price << item.quantity << item.sum << item.brand << item.category << endr;
                number++;
            }
            // แสดงตาราง
            cout << endl << table.to_string() << endl;
        }
    }

    // method (overloading) สำหรับแสดงตารางสินค้าด้วยชื่อ Brand หรือ Category (ใช้คู่กับ method showProductCategory และ showProductBrand)
    void showTable(vector<Product> list){
        if(list.size() == 0){
            cout << on_magenta << grey <<  "Out of stock!" << reset << endl;
        } else {
            cout << endl << "\t\t\t" << on_bright_white << grey << "List of all products" << reset << endl;
            // สร้างหัว columns
            table << header << "No" << "Product" << "ID" << "$Price" << "Stock" << "Brand" << "Category" << endr;
            // loop ข้อมูลจาก parameter list โดยสร้างแต่ละ row
            for(Product item : list){
                table << number << item.getId() << item.getName() << item.getPrice() << item.getStock() << item.getBrand() << item.getCategory() << endr;
                number++;
            }
            // แสดงตาราง
            cout << endl << table.to_string() << endl;
        }
    }
};

// class ProductManagement มีหน้าที่จัดการเกี่ยวกับสินค้าต่างๆภายในโปรแกรม
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

    // method (overloading) เฉพาะสำหรับตรวจสอบเลข id
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

    // method ในการเช็คว่าข้อมูลตอนนี้ว่างเปล่าหรือไม่ (ไม่มีสินค้าอยู่ในไฟล์ data.txt) ถ้าว่างเปล่าคืน true ถ่าไม่ว่างเปล่าคืน false
    static bool isEmpty(){
        return data.size() == 0;
    }

    // method ในการตรวจสอบว่าค่า parameter ที่ส่งเข้ามานั้นเป็นเลขจำนวนเต็มบวกหรือไม่ ถ้าใช่คืน true ถ้าไม่คืน false
    static bool isPositiveNumber(int n){
        return n > 0;
    }

    // method แสดงรายการสินค้า
    static void showListProducts(){
        if(isEmpty()){
            cout << on_magenta << grey << "Out of stock!" << reset << endl;
        } else {
            int number = 1;
            // แสดงตารางสินค้าโดยส่ง argument list เข้าไป
            Table table = Table();
            table.showTable();
        }
    }

    // method แสดงสินค้าเฉพาะสินค้าหมวดหมู่นั้น
    static void showProductCategory(){
        string category;

        cout << yellow << "Enter category:" << reset;
        cin >> category;

        // เช็คว่ามีสินค้าหรือไม่
        if(isEmpty()){
            cout << magenta << "Out of stock!" << reset << endl;
        } else {
            vector<Product> list;
            // เช็คว่าอยู่ในหมวดหมู่สินค้านั้นหรือไม่
            if(isCategory(category)){
                int number = 1;
                // ตรวจสอบว่ามีหมวดหมู่สินค้านั้นอยู่ในคลัง
                bool inStock = false;
                // loop ข้อมูลสินค้า
                for(Product item : data){
                    // แสดงสินค้าเฉพาะหมวดหมู่สินค้าที่เลือก
                    if(item.getCategory() == category){
                        inStock = true;
                        list.push_back(item);
                    }
                }
                // ไม่มีสินค้าหมวดนี้อยู่ในคลังสินค้า
                if(!inStock){
                    err.push_back(" No product category ");
                    err.push_back(category);
                    err.push_back(" in stock.");
                    program::showErrorMessage();
                    return;
                } else {
                    // แสดงตารางสินค้าโดยส่ง argument list เข้าไป
                    Table table = Table();
                    table.showTable(list);
                    // ล้างข้อมูลใน list ใหม่
                    list.clear();
                }

            } else {
                err.push_back("\"");
                err.push_back(category);
                err.push_back("\"");
                err.push_back(" is not in categories of products.");
                program::showErrorMessage();
            }
        }
    }

    // method แสดงสินค้าเฉพาะสินค้าหมวดหมู่นั้น
    static void showProductBrand(){
        string brand;

        cout << yellow << "Enter brand name:" << reset;
        cin >> brand;

        if(isEmpty()){
            cout << on_magenta << grey << "Out of stock!" << reset << endl;
        } else {
            int number = 1;
            vector<Product> list;
            // ตรวจสอบว่าหาแบรนด์สินค้าเจอ
            bool inStock = false;
            // loop ข้อมูลสินค้า
            for(Product item : data) {
                // แสดงสินค้าเฉพาะหมวดหมู่สินค้าที่เลือก
                if (item.getBrand() == brand) {
                    inStock = true;
                    list.push_back(item);
                }
            }
            // ถ้าไม่พบแบรนด์สินค้านี้ ... ในคลัง
            if(!inStock){
                err.push_back("This product brand ");
                err.push_back(brand);
                err.push_back(" was not found in stock!");
                program::showErrorMessage();
                return;
            } else {
                // แสดงตารางสินค้าโดยส่ง argument list เข้าไป
                Table table = Table();
                table.showTable(list);
                // ล้างข้อมูลใน list ใหม่
                list.clear();
            }
        }
    }

    // method เพิ่มสินค้า
    static void addProduct(int id){
        string selectCategory;

        cout << "Product categories ";
        char comma = ',';
        int count = 0;
        // แสดงหมวดหมู่ของสินค้าที่สามารถเพิ่มได้
        for(string category : productCategories){
            cout << green << "\"" << category << "\"" << reset;
            if(count != NUMBER_CATEGORIES - 1) cout << comma << ' ';
            count++;
        }

        cout << endl << yellow <<  "Select product category:" << reset;
        cin >> selectCategory;

        // ถ้ามีหมวดหมู่สินค้านั้นอยู่ในรายการ
        if(isCategory(selectCategory)){
            product p; // สร้างตัวแปร p เพิ่อมารอรับข้อมูลสินค้าใหม่
            Product newProduct; // ตัวแปรที่เก็บ object ของสินค้าที่เพิ่มเข้ามาใหม่

            // รับข้อมูลสินค้าใหม่ที่จะเพิ่ม
            cout << yellow << "Product Name:" << reset;
            cin >> p.name;
            // ตรวจสอบว่า name ว่าซ้ำกันไหม
            if(findProduct(p.name)){
                program::showErrorMessage("The new product name must not be duplicated with the product that already has this name!");
                return;
            }
            // ห้ามตั้งชือสินค้าอักษรตัวแรกขึ้นต้นด้วยตัวเลข
            else if(isdigit(p.name.at(0))){
                program::showErrorMessage("Do not name the product beginning with a number!");
                return;
            }

            // รับค่า parameter มาโดย id จะมีค่าเริ่มต้นที่สุ่มเอาไว้ให้
            p.id = id;

            cout << yellow << "Pricing:" << reset;
            cin >> p.price;
            //  ราคาต้องเป็นเลขจำนวนเต็มบวก
            if(!isPositiveNumber(p.price)){
                program::showErrorMessage("Invalid price, Please enter only positive number.");
                return;
            }

            cout << yellow <<"If there is no product brand name, Enter -" << reset << endl;
            cout << yellow << "Product brand name:" << endl;
            cin >> p.brand;

            // สร้าง array ชื่อ products ทำหน้าที่เก็บหมวดหมู่สินค้าทั้งหมด
            Product products[NUMBER_CATEGORIES] = {
                    Phone(), Tablet(), Laptop(), Computer(), Car(), HealthAndBeauty(),
                    Game(), Bag(), ElectricalAppliance(), Pet(),
                    Camera(), Shoes(), Watch(), Sport(), MusicalInstrument(),
                    Furniture(), Food()
            };
            // loop ข้อมูลใน array เพื่อเช็คว่าอยู่หมวดหมู่สินค้าไหน
            for(int i = 0; i < NUMBER_CATEGORIES; i++){
                // เช็คหมวดหมู่สินค้าว่าตรงกันไหม
                if(selectCategory == products[i].getCategory()){
                    // แก้ไขค่า สมาชิกใน array (แก้ไข ชื่อสินค้า รหัสสินค้า ราคา และ ชื่อแบรนด์)
                    products[i].setId(p.id);
                    products[i].setName(p.name);
                    products[i].setPrice(p.price);
                    // ดึง substring ออกมาแล้วเช็คว่าเป็น - หรือไม่ ถ้าไม่มี brand พิมพ์ - แบรนด์จะมีค่า no-brand-name แต่ถ้าไม่ได้พิมพ์ - แบรนด์จะเป็นค่าที่ผู้ใช้งานป้อนมา
                    if(p.brand.at(0) != '-'){
                        products[i].setBrand(p.brand);
                    }
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
            program::showSuccessfulMessage("Added a new product.");
        } else {
            err.push_back(selectCategory);
            err.push_back(" is not in categories of products");
            program::showErrorMessage();
        }
    }

    // method สำหรับเพิ่มจำนวนสินค้าใน stock
    static void addStockProduct(){
        string input;
        cout << yellow << "Enter the product name or product id:" << reset;
        cin >> input;

        // ถ้ามีสินค้านั้นอย่ในข้อมูล
        if(findProduct(input)){
            int number;
            int index = 0;
            // รับข้อมูล
            cout << yellow <<"Amount:" << reset;
            cin >> number;

            // จำนวนสินค้าที่เพิ่มเข้ามาต้องเป็นเลขจำนวนเต็มบวก
            if(!isPositiveNumber(number)){
                program::showErrorMessage("Invalid number, Please enter a positive number!");
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
            program::showSuccessfulMessage("Added new product quantity to stock");
        } else {
            err.push_back(input);
            err.push_back(" is not in data!");
            program::showErrorMessage();
        }
    }

    // method ลบสินค้า
    static void deleteProduct() {
        string input;

        cout << yellow << "Enter the product name or product id:" << reset;
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
            cout << green << "Successfully deleted product" << reset << endl;
            // อัปเดตข้อมูล
            File::update();
        } else {
            err.push_back(input);
            err.push_back(" is not in data!");
            program::showErrorMessage();
        }
    }

    // method แก้ไขข้อมูลสินค้า
    static void editProduct() {
        string input;

        cout << yellow << "Enter the product name or product id:" << reset;
        cin >> input;

        // ถ้ามีสินค้านั้นอยู่ในข้อมูล
        if(findProduct(input)){
            int index = 0;
            // สร้างตัวแปรมารอรับข้อมูลที่ผู้ใช้งานป้อนเข้ามา
            product p;
            // คำตอบที่ผู้ใช้งานตอบมีแค่ y หรือ n เท่านั้น
            typedef struct {
                char yn1, yn2, yn3, yn4, yn5;
            } yesOrNo;
            yesOrNo yn;

            // loop ข้อมูลสินค้าทั้งหมด
            for (Product item : data) {
                // เช็คว่าเป็นสินค้าชิ้นนั้น
                if (to_string(item.getId()) == input || item.getName() == input) {
                    /*
                     * ถามว่าต้องการแก้ไขข้อมูลสินค้าในส่วนไหนบ้างโดยตอบ y และ n
                     * ถ้าตอบ y ให้ดำเนินการแก้ไขข้อมูลในส่วนนั้น ถ้าตอบ n หรืออื่นๆคือผ่าน
                     * ถามว่าต้องการแก้ไขชื่อสินค้าไหม
                    */
                    cout << cyan << "Do you want to edit the product name (y/n):" << reset;
                    cin >> yn.yn1;
                    if(tolower(yn.yn1) == 'y'){
                        cout << yellow << "New product name:" << reset;
                        cin >> p.name;
                        // ตรวจสอบว่า name ที่แก้ไขว่าซ้ำกันกับข้อมูลที่มีแล้วไหม
                        if(findProduct(p.name)){
                            err.push_back(" Cannot edit to name ");
                            err.push_back(p.name);
                            err.push_back(" because the name is the same as an existing product name.");
                            program::showErrorMessage();
                            return;
                        } else {
                            // แก้ไขชื่อสินค้า
                            data.at(index).setName(p.name);
                        }
                    }

                    // ถามว่าต้องการแก้ไขชื่อรหัสสินค้าไหม
                    cout << cyan << "Do you want to edit the product id (y/n):" << reset;
                    cin >> yn.yn2;
                    if(tolower(yn.yn2) == 'y'){
                        cout << yellow << "New product id:" << reset;
                        cin >> p.id;
                        getchar();
                        // ตรวจสอบว่า name ที่แก้ไขว่าซ้ำกันกับข้อมูลที่มีแล้วไหม
                        if(findProduct(p.id)){
                            err.push_back(" Cannot edit to id ");
                            err.push_back(to_string(p.id));
                            err.push_back(" because the id is the same as an existing product id.");
                            program::showErrorMessage();
                            return;
                        } else {
                            // แก้ไขรหัสสินค้า
                            data.at(index).setId(p.id);
                        }
                    }

                    // ถามว่าต้องการแก้ไขราคาสินค้าไหม
                    cout << cyan << "Do you want to edit the product price (y/n):" << reset;
                    cin >> yn.yn3;
                    if(tolower(yn.yn3) == 'y'){
                        cout << yellow << "New product price:" << reset;
                        cin >> p.price;
                        // ตรวจสอบว่าเป็นเลขจำนวนเต็มบวกหรือไม่
                        if(!isPositiveNumber(p.price)){
                            program::showErrorMessage("Invalid price, Please enter a positive number!");
                            return;
                        } else {
                            // แก้ไขราคาสินค้า
                            data.at(index).setPrice(p.price);
                        }
                    }

                    // ถามว่าต้องการแก้ไขหมวดหมู่สินค้าไหม
                    cout << cyan << "Do you want to edit the product category (y/n):" << reset;
                    cin >> yn.yn4;
                    if(tolower(yn.yn4) == 'y'){
                        cout << yellow << "New product category:" << reset;
                        cin >> p.category;
                        // ตรวจสอบว่าอยู่ในหมวดหมู่สินค้าที่ได้กำหนดไว้หรือไม่
                        if(!isCategory(p.category)){
                            err.push_back(p.category);
                            err.push_back(" is not in categories of products!");
                            program::showErrorMessage();
                            return;
                        } else {
                            // แก้ไขหมวดหมู่สินค้า
                            data.at(index).setCategory(p.category);
                        }
                    }

                    // ถามว่าต้องการแก้ไขหมวดหมู่สินค้าไหม
                    cout << cyan << "Do you want to edit the brand product (y/n):" << reset;
                    cin >> yn.yn5;
                    if(tolower(yn.yn5) == 'y'){
                        cout << yellow << "New brand product:" << reset;
                        cin >> p.brand;
                        // แก้ไขแบรนด์สินค้า
                        data.at(index).setBrand(p.brand);
                    }
                    // เมื่อเจอสินค้าที่ระบุแล้วให้หยุด loop
                    break;
                }
                index++;
            }
            // อัปเดตข้อมูล
            File::update();
            program::showSuccessfulMessage("Successfully edited product");
        } else {
            err.push_back(input);
            err.push_back(" is not in data!");
            program::showErrorMessage();
        }
    }

    // method ในการขายสินค้า
    static void sellProducts(){
        string input;
        bool isRunning = true; // ตัวแปรควบคุมการทำงาน while loop ถ้ามีค่า true แปลยังสามารถสั่งสินค้าต่อได้เรื่อยๆ ถ้า false หยุดดำเนินการสั่งซื้อ
        char e; // ตัวแปร อักษร e(end) เมื่อผู้ใช้งานพิมพ์ตัวอักษร e คือจบการสั่งซื้อสินค้า
        vector<product> orders = {}; // รายการ orders สินค้าที่สั่งซื้อทั้งหมด
        product order; // order สินค้า 1 ที่สั่ง 1 รายการ

        cout << "Enter " << cyan << "\"e\"" << reset << " to exit the sale." << endl;

        // loop ไปเรื่อยๆจนกว่าผู้ใช้จะพิมพ์ตัว e
        while(isRunning){
            cout << yellow << "Enter product name or product id:" << reset;
            cin >> input;

            // เอา substring ตัวแรกของตัวแปร input
            e = input.at(0);
            // เช็คว่าอักตรตัว e หรือไม่ ถ้าใช้ ให้ออกจากการขายสินค้า
            if(tolower(e) == 'e'){
                float total = 0; // จำนวนเงินทั้งหมด
                int quantity = 0; // จำนวนสินค้าทั้งหมด
                int i = 0; // ลำดับสินค้าที่สั่ง
                // ออกจากการขายสินค้าและคำนวณราคาสินค้าทั้งหมด
                isRunning = false;
                // ถ้ายังไม่มีการสั่งสินค้าไม่ต้องแสดงรายละเอียดการสั่งซื้อ
                if(orders.size() != 0){
                    // คำนวณจำนวนเงินทั้งหมดที่สั่งสินค้า และ แสดงรายการสินค้าที่สั่งซื้อ
                    for(product item : orders){
                        // คำนวณยอดเงินสินค้าต่อ 1 รายการ
                        item.sum = item.quantity * item.price;
                        // แก้ไขค่ายอดรวมของสินค้าของแต่ละสินค้า
                        orders.at(i).sum = item.sum;
                        // คำนวณเงินที่ต้องจ่ายทั้งหมดที่สั่งสินค้ามา
                        total += item.sum;
                        // เพิ่มจำนวนสินค้า
                        quantity += item.quantity;
                        i++;
                    }
                    cout << endl << "\t\t" << on_bright_white << grey <<  "The products you ordered." << reset << endl;
                    // สร้าง object table เพื่อจะแสดงตารางสินค้า
                    Table table = Table();
                    // แสดงตารางรายละเอียดสินค้าและสรุปการสั่งซื้อสินค้า
                    table.showTable(orders);
                    // แสดงจำนวนเงินทั้งหมดที่ต้องจ่าย
                    cout << endl << cyan << "Total number of products = " << quantity << reset << endl;
                    cout << cyan << "Total amount = " << total << " dollar." << reset << endl;
                    // เขียนข้อมูลลงในไฟล์ orders.txt
                    File::write(orders, quantity, total);
                    // ลบรายการสินค้าทั้งหมดที่สั่่ง
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
                            order.brand = item.getBrand();
                            order.sum = 0; // ยอดรวมสินค้านั้นมีค่าเริ่มต้นเป็น 0

                            // รับค้าจำวนสินค้าที่สั่ง
                            cout << yellow << "Quantity:" << reset;
                            cin >> order.quantity;

                            // จำนวนสินค้าต้องเป็นเลขจำนวนเต็มบวก
                            if(!isPositiveNumber(order.quantity)) {
                                program::showErrorMessage(" Invalid quantity, Please enter a positive number!");
                                isRunning = false;
                                return;
                            }
                            // สินค้าในคลังหมดไม่สามารถสั่งได้
                            else if(item.getStock() == 0){
                                cout << red << "This product " << "\"" << item.getName() << "\"" << " is out of stock." << reset << endl;
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

                                // ต้องการตรวจสอบข้อมูลสินค้าที่สั่ง (order) นั้นเป็นสินค้าชิ้นเดียวกับที่เราพึ่งสั่งไป(สำค้าอันเดียวกับใน orders)
                                // ให้เก็บข้อมูลนั้นเป็นข้อมูลเดียวกันโดยไม่ต้องเพิ่ม element ตัวใหม่เข้าไป
                                int k = 0; // เลข index
                                bool isDuplicate = false; // เป็นสินค้าซ้ำกันหรือไม่
                                // loop ข้อมูลเพื่อเช็คว่าซ้ำกันไหม
                                for(product o: orders){
                                    // ถ้าชื่อหรือ id ซ้ากับสินค้าที่สั่งอยู่ให้ isDuplicate เป็น true
                                    if(o.name == order.name || o.id == order.id){
                                        isDuplicate = true;
                                        break;
                                    }
                                    k++;
                                }
                                // ถ้าข้อมูลนั้นซ้ำกันให้เพิ่มจำนวนสินค้าที่สั่งอยู่
                                if(isDuplicate){
                                    orders.at(k).quantity += order.quantity;
                                }
                                // ถ้าข้อมูลไม่ซ้ำกัยให้ orders เพิ่ม element(สินค้า) ตัวใหม่เข้าไป
                                else {
                                    // เพิ่มสินค้าเข้าใน orders ที่สั่ง
                                    orders.push_back(order);
                                }
                                // เขียนไฟล์ข้อมูล
                                File::write();
                            }
                            // สั่งสินค้าเกินจำนวนในคลัง
                            else {
                                program::showErrorMessage(" The quantity of products ordered is greater than the quantity of products in stock!");
                                isRunning = false;
                                return;
                            }
                        }
                        j++;
                    }
                } else {
                    err.push_back(input);
                    err.push_back(" is not in data!");
                    program::showErrorMessage();
                }
            }
        }
    }
};

int main(){
    // เริ่มโปรแกรมให้อ่านข้อมูลจากไฟล์ data.txt แล้วมาเก็บไว้ในตัวแปร data
    File::read();
    // ตัวเลือกที่ผู้ใช้งานเลือกว่าจะใช้ง่านคำสั่งอะไร
    int select;
    // วน loop ไปเรื่อยๆเพื่อรอให้ผู้ใช้งานป้อนตัวเลขให้โปรแกรมทำงานตามหมายเลขนั้น
    while(true){
        // แสดงตัวเลือกที่ผู้ใช้จะเลือกใช้งานคำสั่งของโปรแกรม โดยผู้ใช้งานจะต้องป้อนตัวเลข 1 - 10 เข้ามา
        program::showOptions();
        cin >> select;

        // แสดงรายการสินค้าทั้งหมด
        if(select == 1){
            ProductManagement::showListProducts();
        }
        // แสดงเฉพาะหมวดหมู่สินค้าที่เลือก
        else if(select == 2){
            ProductManagement::showProductCategory();
        }
        // แสดงเฉพาะแบรนด์สินค้าที่เลือก
        else if(select == 3){
            ProductManagement::showProductBrand();
        }
        // สั่งซื้อสินค้า
        else if(select == 4){
            ProductManagement::sellProducts();
        }
        // เพิ่มสินค้า
        else if(select == 5){
            // เมื่อเพิ่มสินค้าใหม่เข้าไปจะ gen id ให้อัตโนมัติโดยที่ id ไม่ซ้ำกัน
            int id = program::generateId(1000,10000);
            ProductManagement::addProduct(id);
        }
        // ลบสินค้า
        else if(select == 6){
            ProductManagement::deleteProduct();
        }
        // แก้ไขสินค้า
        else if(select == 7){
            ProductManagement::editProduct();
        }
        // เพิ่มจำนวนสินค้าในคลัง
        else if(select == 8){
            ProductManagement::addStockProduct();
        }
        // ออกจากโปรแกรม
        else if(select == 9){
            cout << endl << on_bright_white << grey << "Exit program." << reset << endl;
            break;
        }
        // ไม่มีในตัวเลือก
        else {
            err.push_back(to_string(select));
            err.push_back(" is not available, Please select a number between 1 - 9.");
            program::showErrorMessage();
        }
    }
    return 0;
}

namespace program {
    // function แสดงตัวเลือกการทำงานของโปรแกรม
    void showOptions(){
        // สร้าง array ไว้เก็บชุดความหมายของคำสั่ง
        string meaningOfCommands[9] = { "Show list of all products", "Show list of product category", "Show list of product brand",
                                        "Sell proudcts", "Add product", "Delete product", "Edit product", "Add product to stock",
                                        "Exit program" };
        // สร้าง object time ไว้แสดงเวลาสุดทุกครั้งที่ใข้งาน
        Time time = Time();

        cout << endl << blue << "Product management program" << reset << endl;
        cout << "Current Time " << cyan;
        // ถ้าเวลายังอยู่ในเลขระหว่าง 1 - 9 ให้ใส่เลข 0 ติดนำหน้าเลขไปด้วย
        time.getHours() < 10 ? cout << "0" << time.getHours() << ":" : cout << time.getHours() << ":";
        time.getMinutes() < 10 ? cout << "0" << time.getMinutes() << ":" : cout << time.getMinutes() << ":";
        time.getSeconds() < 10 ? cout << "0" << time.getSeconds() : cout << time.getSeconds();
        cout << reset << endl << endl;

        for(int i = 0; i < 9; i++){
            cout << on_bright_white << grey << " " << i + 1 << ". " << reset << on_blue << grey << " " <<  meaningOfCommands[i];
            // เพิ่มข้อความเปล่าเพื่อช่องว่าให้สีพื้นหลังนั้นแสดงเท่ากัน
            for(int j = meaningOfCommands[i].length(); j <= 30; j++){
                cout << " ";
            }
            cout << reset << endl;
        }
        cout << on_yellow << grey << "Enter a number:" << reset;
    }

    // function ในการแสดงข้อความ Error
    void showErrorMessage(string message){
        // แสดงข้อความตามสีรูปแบบทีกำหนด
        cout << on_bright_grey << red << " Error: " << reset << on_red << grey << " " << message << " " << reset << endl;
    }

    // function (overloading) แสดงข้อความ error ที่ต้องการแนบตัวแปรเข้าไปด้วย
    void showErrorMessage(){
        cout << on_bright_grey << red << " Error: " << reset << on_red << grey << " " << on_red << grey;
        for(string element : err){
            cout << element;
        }
        cout << " " << reset << endl;
        err.clear();
    }

    // function ในการแสดงข้อความที่ทำสำเร็จ
    void showSuccessfulMessage(string message){
        // แสดงข้อความตามสีรูปแบบทีกำหนด
        cout << on_bright_grey << green << " Successfully: " << reset << on_green << grey << " " << message << " " << reset << endl;
    }

    // function ในการสร้างเลข id โดยที่เลข id จะสุ่มเลขอยู่ระหว่าง from ถึง to
    int generateId(int from, int to){
        // ตั้งค่าการสุ่ม
        srand(time(NULL));
        // ค่า id ที่ได้จากการสุ่ม มีเลข 4 หลัก
        int id;
        // สุ่มเลขระหว่าง from ถึง to จะได้ 4 หลัก
        id = rand() % to + from;
        // ตรวจสอบเลข id นั้นซ้ำกับเลข id สินค้าอื่นหรือไม่
        bool isDuplicate = ProductManagement::findProduct(id);

        // ถ้าเลข id นั้นซ้ำกับเลข id สินค้าอื่น
        if(isDuplicate){
            // loop ไปเรื่อยๆจนกว่าเลข id จะไม่ซ้ำ
            while(isDuplicate){
                int i = 1; // นับเลขว่าถึง loop รอบสุดท้ายหรือยัง
                id = rand() % to + from; // สุ่มเลขใหม่
                // ตรวจสอบเลข id
                for(Product item : data){
                    isDuplicate = ProductManagement::findProduct(id);
                    // เมื่อถึง loop รอบสุดท้ายของข้อมูล
                    if(i == data.size()){
                        // ถ้าเลข id นั้นไม่ซ้ำให้ออกจาก while loop แต่ถ้าเลข id นั้นยังซ้ำอยู่ก็ loop ไปเรื่อยๆจนกว่าจะไม่ซ้ำ
                        if(!isDuplicate) isDuplicate = false;
                    }
                    i++;
                }
            }
        }

        return id;
    }
}