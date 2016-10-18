# 问题 A: 时钟模拟(继承）

## 题目描述
+ 定义计数器类，包含保护数据成员value,公有函数increment计数加1。
+ 定义循环计算器继承计数器类，增加私有数据成员：最小值min_value，max_value,
+ 重写公有函数increment，使得value在min_value~max_value区间内循环+1。
+ 定义时钟类，数据成员是私有循环计数器对象小时hour、分钟minute、秒second，公有函数time(int s)计算当前时间经过s秒之后的时间，即hour,minute,second的新value值。
+ 定义时钟类对象，输入当前时间和经过的秒数,调用time函数计算新时间。
+ 根据题目要求，增加必要的构造函数、析构函数和其他所需函数。

## 输入
+ 第一行测试次数n
+ 2行一组，第一行为当前时间（小时 分钟 秒），第二行为经过的秒数。

## 输出
+ 输出n行
+ 每行对应每组当前时间和经过秒数后计算得到的新时间（小时：分钟：秒）。

## 样例输入
+ 2
+ 8 19 20
+ 20
+ 23 30 0
+ 1801

## 样例输出
+ 8:19:40
+ 0:0:1

# 问题 B: 商旅信用卡(多重继承)

## 题目描述
+ 某旅游网站（假设旅程网）和某银行推出旅游综合服务联名卡—旅程信用卡，兼具旅程会员卡和银行信用卡功能。
+ 旅程会员卡，有会员卡号（int）、旅程积分（int），通过会员卡下订单，按订单金额累计旅程积分。
+ 信用卡，有卡号（int）、姓名（string)、额度（int)、账单金额（float)、信用卡积分（int）。------请注意数据类型
+ 信用卡消费金额m，若超额度，则不做操作；否则，账单金额+m，信用卡积分按消费金额累加。
+ 信用卡退款m，账单金额-m，信用卡积分减去退款金额。
+ 通过旅程信用卡在旅程网下单，旅程积分和信用卡积分双重积分（即旅程积分和信用卡积分同时增加）。
+ 旅程信用卡可以按      旅程积分：信用卡积分= 1：2    的比例将信用卡积分兑换为旅程积分。
+ 初始假设信用卡积分、旅程积分、账单金额为0。
+ 根据上述内容，定义旅程会员卡类、信用卡类，从两者派生出旅程信用卡类并定义三个类的构造函数和其它所需函数。
+ 生成旅程信用卡对象，输入卡信息，调用对象成员函数完成旅程网下单、信用卡刷卡、信用卡退款、信用卡积分兑换为旅程积分等操作。

## 输入
+ 第一行：输入旅程会员卡号 信用卡号 姓名 额度
+ 第二行：测试次数n
+ 第三行到第n+2行，每行：操作 金额或积分
+ o   m（旅程网下订单，订单金额m）
+ c   m（信用卡消费，消费金额m）
+ q   m (信用卡退款，退款金额m）
+ t   m（积分兑换，m信用卡积分兑换为旅程积分）

## 输出
+ 输出所有操作后旅程信用卡的信息：
+ 旅程号   旅程积分
+ 信用卡号  姓名   账单金额   信用卡积分

## 样例输入
+ 1000 2002  lili  3000
+ 4
+ o 212.5
+ c 300
+ q 117.4
+ t 200

## 样例输出
+ 1000 312
+ 2002 lili 395.1 195

# 问题 C: 交通工具（多重继承）

## 题目描述
+ 建立如下的类继承结构：
  1. 一个车类CVehicle作为基类，具有max_speed、speed、weight等数据成员，display()等成员函数
  2. 从CVehicle类派生出自行车类CBicycle，添加属性：高度height
  3. 从CVehicle类派生出汽车类CMotocar，添加属性：座位数seat_num
  4. 从CBicycle和CMotocar派生出摩托车类CMotocycle
+ 分别定义以上类的构造函数、输出函数display及其他函数（如需要）。
+ 在主函数中定义各种类的对象，并测试之，通过对象调用display函数产生输出。

## 输入
+ 第一行：最高速度 速度 重量 第二行：高度 第三行：座位数

## 输出
+ 第一行：Vehicle: 第二行及以后各行：格式见Sample

## 样例输入
+ 100 60 20
+ 28
+ 2

## 样例输出
+ Vehicle:
+ max_speed:100
+ speed:60
+ weight:20
<p></p>
+ Bicycle:
+ max_speed:100
+ speed:60
+ weight:20
+ height:28
<p></p>
+ Motocar:
+ max_speed:100
+ speed:60
+ weight:20
+ seat_num:2
<p></p>
+ Motocycle:
+ max_speed:100
+ speed:60
+ weight:20
+ height:28
+ seat_num:2

# 问题 D: 在职研究生（多重继承）

## 题目描述
+ 建立如下的类继承结构：
  1. 定义一个人员类CPeople，其属性（保护类型）有：姓名、性别、年龄；
  2. 从CPeople类派生出学生类CStudent，添加属性：学号和入学成绩；
  3. 从CPeople类再派生出教师类CTeacher，添加属性：职务、部门；
  4.从CStudent和CTeacher类共同派生出在职研究生类CGradOnWork，添加属性：研究方向、导师；
+ 分别定义以上类的构造函数、输出函数print及其他函数（如需要）。
+ 在主函数中定义各种类的对象，并测试之。

## 输入
+ 第一行：姓名性别年龄
+ 第二行：学号成绩
+ 第三行：职务部门
+ 第四行：研究方向导师

## 输出
+ 第一行：People:
+ 第二行及以后各行：格式见Sample

## 样例输入
+ wang-li m 23
+ 2012100365 92.5
+ assistant computer
+ robot zhao-jun

## 样例输出
+ People:
+ Name: wang-li
+ Sex: m
+ Age: 23
<p></p>
+ Student:
+ Name: wang-li
+ Sex: m
+ Age: 23
+ No.: 2012100365
+ Score: 92.5
<p></p>
+ Teacher:
+ Name: wang-li
+ Sex: m
+ Age: 23
+ Position: assistant
+ Department: computer
<p></p>
+ GradOnWork:
+ Name: wang-li
+ Sex: m
+ Age: 23
+ No.: 2012100365
+ Score: 92.5
+ Position: assistant
+ Department: computer
+ Direction: robot
+ Tutor: zhao-jun
