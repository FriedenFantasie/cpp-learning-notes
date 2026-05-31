#include <iostream>

using namespace std;

int main()
{
    const int studentCount = 3;
    const int subjectCount = 3;

    int scores[studentCount][subjectCount] = {
        {100, 100, 100},
        {90, 50, 100},
        {60, 70, 80}
    };

    cout << "学生考试成绩统计：" << endl;

    for (int i = 0; i < studentCount; i++) {
        int total = 0;

        cout << "第 " << i + 1 << " 名学生成绩：";

        for (int j = 0; j < subjectCount; j++) {
            cout << scores[i][j] << " ";
            total += scores[i][j];
        }

        cout << "总分：" << total << endl;
    }

    cout << endl;
    cout << "每门课程平均分：" << endl;

    for (int j = 0; j < subjectCount; j++) {
        int subjectTotal = 0;

        for (int i = 0; i < studentCount; i++) {
            subjectTotal += scores[i][j];
        }

        double average = static_cast<double>(subjectTotal) / studentCount;
        cout << "第 " << j + 1 << " 门课程平均分：" << average << endl;
    }

    return 0;
}
