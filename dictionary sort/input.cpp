#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <set>
using namespace std;

// 生成随机的升序字符序列
string generateAscendingString() {
    
    int length = rand() % 6 + 1;//1~6
    set<char> characters; // 使用集合来确保唯一性
    while (characters.size() <= length) {
        char randomChar = 'a' + rand() % 26; // 随机生成 a-z 的字符
        characters.insert(randomChar);
    }

    string result(characters.begin(), characters.end()); // 转换为字符串
    return result;
}
int main() {
    srand(time(0)); // 使用当前时间作为随机种子

    int k; // 行数
    cout << "请输入要生成的行数: ";
    cin >> k;

    ofstream outputFile("input.txt");
/*ofstream 是 C++ 中的类，用于写入文件。它来自 <fstream> 头文件。
 outputFile 是创建的文件流对象，用来操作文件。
"input.txt" 是要打开或创建的文件的名称。文件会被保存在当前程序的工作目录下。*/
    
    if (!outputFile) {
        cerr << "无法创建文件!" << endl;
        return 1;
    }

    // 写入行数k
    outputFile << k << endl;

    // 生成k个升序字符序列
    for (int i = 0; i < k; ++i) {
    	string str = generateAscendingString();
        outputFile <<str<< endl;
    }

    outputFile.close();
    cout << "生成的input.txt文件成功！" << endl;

    return 0;
}
