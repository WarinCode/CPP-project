### ขั้นตอนการติดตั้งและใช้งานโปรแกรม

1. ดาวน์โหลด์โปรเจค ใน main2
``` 
git clone https://github.com/WarinCode/CPP-project.git -b main2
```

2. เปิด terminal แล้วเข้าไปใน directory ของโปรเจค
``` 
cd CPP-project
```

3. compile ไฟล์ main.cpp จะได้โปรแกรมขึ้นมา
``` 
g++ main.cpp -o program.exe
```

4. เปิดโปรแกรม program.exe ขึ้นมาหรือใช้คำสั่งนี้จะเปิดโปรแกรมนี้ขึ้นมาใน terminal แทน
```
./program.exe
```
<div align="center">
<img src="imgs/preview2.jpg" alt="preview" height="100%" width="100%"/>
</div>

5. ถ้าทำตามขั้นตอนที่ว่ามาทั้งหมดก็ถือว่าเกือบพร้อมใช้งานแต่ที่สำคัญในส่วนของการอ่านและเขียนไฟล์ข้อมูลให้ทำการเขียนทับ path ในส่วนของ method read , write และ update ของ class File
   <code>string path = R"(C:\Users\ACER USER5949486\Desktop\CPP-project\txts\data.txt)"</code> โดยให้เปลี่ยนเป็น <code>string path = R"(C:\Users\user\Desktop\CPP-project\txts\data.txt)"</code>
   ให้เปลี่ยนจาก <code>user</code> เป็นเครื่องชื่อผู้ใช้งานแทนหรือส่งค่า argument ด้วย path ของไฟล์ก็ได้
   ตัวอย่างเมื่อมีการเรียกใช้ method read , write และ update
``` c++
// ตัวอย่าางการเปลี่ยนค่าใน path file เป็น path file ในเครื่องของผู้ใช้งาน
#include <iostream>
using std::string;

typedef struct {
    string data;
    string orders;
} textFiles;
// ให้แทนค่าตรงคำว่า user เป็นเครื่องผู้ใช้งานแทน
const textFiles path = { 
    .data=R"(C:\Users\user\Desktop\CPP-project\txts\data.txt)", 
    .orders=R"(C:\Users\user\Desktop\CPP-project\txts\orders.txt)"
};

// ตัวอย่างแบบที่ 1 คือการเข้าไปแก้ไขค่าใน default parameter ใน method read และ write
class File {
public:

    static void read(string path = path.data, bool showMessage = false){
        // code ข้างในการทำงานของ method ไม่ต้องแก้ไขใดๆ ...
    }

    static void write(string path = path.data, bool showMessage = false){
        // ...
    }

    static void write(vector<product> orders, int totalNumbers, float totalAmount, string path = path.orders, bool showMessage = false){
        // ...
    }
    
    static void update(string path = path.data){
        // ... 
    }
};

// ตัวอย่างแบบที่ 2 คือการส่งค่า argument เข้าไปแทนใน default parameter เมื่อมีการเรียกใช้ method ในแต่ละบรรทัด
File::read(path.data);
File::write(path.data);
// ถ้าเป็น method แบบ overloading ให้ส่งค่า args ตัวอื่นไปก่อนตามลำดับ
File::write(orders, quantity, total, path.orders);
File::update(path.data);
```
แก้ไขโค้ดเสร็จเรียบร้อยให้ทำขั้นตอนที่ 4 ใหม่จะได้โปรแกรมที่พร้อมใช้งานในเครื่องของผู้ใช้
