#include <stdio.h>
#include "MyString.h"

int main() {
    String s1 = createString("账号:Aliya,密码:123");
    String s2 = createString("密码:");

    printf("匹配结果:%d\n", call(s1).indexOf(s2));
    printf("比较结果:%d\n", call(s1).equals(s2));

    return 0;
} 
