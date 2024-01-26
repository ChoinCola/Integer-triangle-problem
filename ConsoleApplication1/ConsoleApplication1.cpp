#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>>& triangle) {
    int answer = 0;
    for (int height = 0; height < triangle.size() - 1; height++)
    {
        vector<int> Nfloor = triangle[height+1];
        for (int width = 0; width <= height; width++)
        {
            int left = triangle[height][width] + Nfloor[width];
            int right = triangle[height][width] + Nfloor[width + 1];

            if (left > triangle[height + 1][width]) triangle[height + 1][width] = left;
            if (right > triangle[height + 1][width + 1]) triangle[height + 1][width + 1] = right;
        }
    }
    sort(triangle.rbegin()->begin(), triangle.rbegin()->end());
    return *triangle.rbegin()->rbegin();
}


int main() {
    // 테스트용 입력값 설정
    vector<vector<int>> triangle = {
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5}
    };

    // 주어진 함수 호출
    int result = solution(triangle);

    // 결과 출력
    cout << "The maximum total from top to bottom of the triangle is: " << result << endl;

    for (auto& def : triangle) {
        for (auto& def2 : def)
            cout << def2 << ", ";
        cout << endl;
    }

    return 0;
}