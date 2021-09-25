typedef int INTNUM;
//typedef 数据类型 类型别名
//typedef 关键字，使用它来为类型取一个新的名字

typedef enum tagDay{MON = 1} Day;

// enum tagDay{MON = 1} //定义了一个自定义的数据类型，和 int 一样是属于数据类型，只不过是自定义的，此处的 Day 和 INTNUM相同，属于为数据类型定义的别名
// 以后 可以直接用 Day 声明变量
Day day1;
day1 = MON;

//上述用法和下述用法效果一样
enum Day{MON = 1};
Day day1;
day1 = MON;


tagDay day2；
day2 = MON；
