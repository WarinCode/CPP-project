<div align="center">
  <img src="./imgs/KU.png" width="300px" height="300px" > 
</div>

<h1 align="center">มหาวิทยาลัยเกษตรศาสตร์วิทยาเขตศรีราชา</h1>

> ส่งงาน project วิชา Computer Programming ปี 1 ภาคปลาย

<h1 align="center">โปรแกรมระบบจัดการสินค้า</h1>

โดยโปรเจคนี้มีทั้งหมด 2 branches ได้แก่
1. <code>main</code> เป็น branch ที่มีการใช้ library เกี่ยวกับตารางโดยจะต้องมีการติดตั้ง library ซึ่งค่อนข้างยุ่งยากถ้าหากไม่สามารถใช้งาน branch นี้ได้ให้ใช้อีก branch นึงคือ
2. <code>main2</code> เป็น branch ที่ไม่มีการใช้งาน library ใดๆสามารถ run โปรแกรมและใช้งานได้เลยโดยกดที่ลิ้งนี้ <a href="https://github.com/WarinCode/CPP-project/tree/main2">main2</a>

รายละเอียดโปรเจค : โปรเจคนี้ทำเกี่ยวกับ โปรเแกรมระบบจัดการสินค้าใน ร้านสินค้า , ร้านขายของ , ร้านสดวกซื้อ โดยการใช้งานเมื่อรันโปรแกรมผ่าน CLI ของโปรแกรมจะมีตัวเลือกคือตัวเลขให้ผู้ใช้งานป้อนตัวเลขใน
cmd , terminal หรือ powershell ก็จะแสดงข้อมูล หรือ การจัดการกับสินค้าต่างๆ ตามฟีเจอร์ที่ได้ระบุไว้ และ เมื่อมีการจัดการกับข้อมูลสินค้าโปรแกรมจะมีการเขียนไฟล์ข้อมูล <code>data.txt</code>
เพื่อจัดเก็บข้อมูลการเปลี่ยนแปลงต่างๆของสินค้า

เป็นโปรเจคแบบง่ายๆ โดยใช้ภาษา C++ ในการเขียนโปรแกรม

---

### เวลาที่ใช้ในการทำโปรเจค

[![wakatime](https://wakatime.com/badge/user/68e3e2dc-451c-45ef-bca8-9fc3ad60e2f9/project/018dad0f-df31-4661-aeef-7cab5890fdeb.svg)](https://wakatime.com/badge/user/68e3e2dc-451c-45ef-bca8-9fc3ad60e2f9/project/018dad0f-df31-4661-aeef-7cab5890fdeb)

วันที่เริ่มทำโปรแกรม : 13/2/2567

วันที่ทำโปรแกรมเสร็จ : 25/2/2567

### ฟีเจอร์ของโปรแกรม
- เพิ่มสินค้า
- ลบสินค้า
- แก้ไขสินค้า
- สั่งซื้อสินค้า
- เพิ่มสินค้าใน stock
- แสดงรายการสินค้า ทั้งหมด , หมวดหมู่สินค้า หรือ แบรนด์สินค้า ที่เลือก
- อ่านเขียนไฟล์ข้อมูลในไฟล์ <code>data.txt</code>
- เขียนไฟล์ข้อมูลสรุปการสั่งซื้อสินค้าในไฟล์ <code>orders.txt</code>
- บอกวันเวลา

### ขั้นตอนการติดตั้งและใช้งานโปรเจค

1. ดาวน์โหลด project ใน branch main2
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

5. ถ้าทำตามขั้นตอนที่ว่ามาทั้งหมดก็ถือว่าพร้อมใช้งานแต่ที่สำคัญในส่วนของการอ่านและเขียนไฟล์ข้อมูลให้ทำการเขียนทับ path ในส่วนของ method read และ write ของ class File
<code>string path = R"(C:\Users\ACER USER5949486\Desktop\CPP-project\txt\data.txt)"</code> โดยให้เปลี่ยนเป็นชื่อผู้ใช้งานแทน <code>string path = R"(C:\Users\user\Desktop\CPP-project\txt\data.txt)"</code>
ให้เปลี่ยนจาก <code>user</code> เป็นเครื่องชื่อผู้ใช้งานแทนหรือส่งค่า argument ด้วย path ของไฟล์ก็ได้
ตัวอย่างเมื่อมีการดรียกใช้ method read และ write

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
    .data=R"(C:\Users\user\Desktop\CPP-project\txt\data.txt)", 
    .orders=R"(C:\Users\user\Desktop\CPP-project\txt\data.txt)"
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
};

// ตัวอย่างแบบที่ 2 คือการส่งค่า argument เข้าไปแทนใน default parameter เมื่อมีการเรียกใช้ method ในแต่ละบรรทัด
File::read(path.data);
File::write(path.data);
// ถ้าเป็น method แบบ overloading ให้ส่งค่า args ตัวอื่นไปก่อนตามลำดับ
File::write(orders, quantity, total, path.orders);
```

ปล. สามารถนำโปรเจคนี้ไปใช้งานหรือพัฒนาต่อยอดได้ฟรี แต่ข้อห้ามคือห้าม copy code ไปส่งเป็นงานกลุ่มโปรเจคของตัวเองทั้งที่ไม่ได้ทำเอง หรือ นำโปรแกรมไปขาย

### รายชื่อสมาชิกในกลุ่ม
1. นาย วรินทร์ สายปัญญา รหัสนิสิต 6630250435 หมู่เรียน 881
