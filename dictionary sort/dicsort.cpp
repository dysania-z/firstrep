#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> dictionary;
// 生成所有升序字符串（递归枚举）
void generateAscendingStrings(string current, char start) {
    if (current.length() > 6) return;
    // 非空字符串加入字典
    if (!current.empty()) {
        dictionary.push_back(current);
    }
    // 从当前起始字符 `start` 开始，依次添加下一个字符，并递归生成更长字符串
    for (char c = start; c <= 'z'; ++c) {
        generateAscendingStrings(current + c, c + 1);
    }
}//a,ab,abc,abcd,abcde,abcdef,(return)...,abcdf,abcdfg,(return)....
//即先递归到abcde，再进入递归把abcdef~abcdez全部加入；返回abcede，c+1，开始abcdf....;返回abcd，返回abc，返回ab，返回a，再进入b，进入c，，，，进入z
bool customCompare(const string& a, const string& b) {
    // 首先按长度比较
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    // 如果长度相同，则按字典序比较
    return a < b;
}
int main() {
    generateAscendingStrings("", 'a');
    sort(dictionary.begin(), dictionary.end(),customCompare);
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile || !outputFile) {
        cerr << "无法打开输入或输出文件！" << endl;
        return 1;
    }
    int k; // 读取字符串个数
    inputFile >> k;
    inputFile.ignore(); // 忽略行尾换行符
    // 4. 处理每个字符串，找到其在字典中的位置
    for (int i = 0; i < k; ++i) {
        string str;
        getline(inputFile, str);
        // 查找字符串在字典中的位置（字典序编码）
        auto it = find(dictionary.begin(), dictionary.end(), str);
        int index = distance(dictionary.begin(), it);
        outputFile << index+1<< endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
