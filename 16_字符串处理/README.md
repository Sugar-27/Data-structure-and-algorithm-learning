## C++中的字符串分割
众所周知，C++没有提供函数直接进行字符串的分割，因此可以使用一些小trick来进行分割
### 分割以空格作为分割符的字符串
```C++
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string str = "apple banana cherry";
    std::stringstream ss(str);
    std::string s;
    int cnt = 0;
    while (ss >> s) {
        std::cout << cnt++ << ' ' << s << std::endl;
    }

    return 0;
}
```

执行结果：
```shell
0 apple
1 banana
2 cherry
```

### 分割特殊字符作为分割符的字符串
```C++
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string str = "apple@banana@cherry";
    std::stringstream ss(str);
    std::string s;

    int cnt = 0;
    while (std::getline(ss, s, '@')) {
        std::cout << cnt++ << ' ' << s << std::endl;
    }

    return 0;
}
```
执行结果：
```shell
0 apple
1 banana
2 cherry
```