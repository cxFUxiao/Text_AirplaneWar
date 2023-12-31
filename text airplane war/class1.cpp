// class1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*#include <iostream>
 int a = 1, b = 2, c;

int add(int a,int b){
    c = a + b + b + a + +a + b + b + a + b + a + b + b + a + b;
    return c;
}

int main()
{
   std::cout << "Hello World!\n";
    add(1231414,12412414);
    printf( "c=%d", c);
}*/

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
/*#include <iostream>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j + 1]
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "排序前的数组为: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bubbleSort(arr, n);

    std::cout << "排序后的数组为: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}*/

/*#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameover;
const int width = 40;
const int height = 20;
int x, y, enemyX, enemyY, score;

// 调整速度参数
const int playerSpeed = 6;  // 提高主角移动速度
const int enemySpeed = 1;   // 进一步降低敌人移动速度
const int bulletSpeed = 2;  // 提高子弹移动速度

// 子弹结构体
struct Bullet {
    int x, y;
};

vector<Bullet> bullets;  // 存储所有子弹

void Setup() {
    gameover = false;
    x = width / 2;
    y = height - 1;
    enemyX = rand() % width;
    enemyY = 0;
    score = 0;
    bullets.clear();  // 清空子弹
}

void Draw() {
    system("cls");

    // 绘制游戏界面
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "P"; // Player
            else if (i == enemyY && j == enemyX)
                cout << "E"; // Enemy
            else {
                bool isBullet = false;
                for (const Bullet& bullet : bullets) {
                    if (i == bullet.y && j >= bullet.x && j < bullet.x + 15) {
                        cout << "|"; // Bullet (宽度为15)
                        isBullet = true;
                        break;
                    }
                }
                if (!isBullet)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "6";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score:" << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            x -= playerSpeed; // 左移
            break;
        case 'd':
            x += playerSpeed; // 右移
            break;
        case 'x':
            gameover = true; // 游戏结束
            break;
        }
    }
}

void Logic() {
    // 移动敌人
    enemyY += enemySpeed;

    // 主角通过边界，出现在画面另一端
    if (x >= width)
        x = 0;
    else if (x < 0)
        x = width - 1;

    // 生成新的子弹（每隔10毫秒生成一颗新的子弹）
    static int bulletCooldown = 0;
    bulletCooldown++;
    if (bulletCooldown >= 1) {
        bullets.push_back({ x, y - 1 });
        bulletCooldown = 0;
    }

    // 移动所有子弹
    for (auto it = bullets.begin(); it != bullets.end();) {
        it->y -= bulletSpeed;
        if (it->y < 0) {
            it = bullets.erase(it);  // 如果子弹越过屏幕上方，从容器中移除
        }
        else {
            ++it;
        }
    }

    // 子弹与敌人碰撞
    for (auto it = bullets.begin(); it != bullets.end();) {
        if (it->x <= enemyX && it->x + 15 >= enemyX && it->y == enemyY) {
            score++;
            enemyX = rand() % width;
            enemyY = 0;
            it = bullets.erase(it);
        }
        else {
            ++it;
        }
    }

    // 游戏结束条件
    if (y < 0 || y >= height || enemyY == height) {
        gameover = false;

        // 游戏结束时等待用户按键
        cout << "Game Over! Your Score: " << score << endl;
        cout << "Press 'r' to restart or any other key to exit...";

        // 检测用户输入
        char userInput = _getch();
        if (userInput == 'r' || userInput == 'R') {
            // 重新开始游戏
            Setup();
            gameover = false;
        }
    }
}

int main() {
    Setup();

    while (!gameover) {
        Draw();
        Input();
        Logic();
        Sleep(100); // 等待 10 毫秒
    }

    return 0;
}
*/

/*#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameover;
const int width = 40;
const int height = 20;
int x, y, enemyX, enemyY, score;

// 调整速度参数
const int playerSpeed = 6;  // 提高主角移动速度
const int enemySpeed = 1;   // 进一步降低敌人移动速度
const int bulletSpeed = 4;  // 提高子弹移动速度

// 子弹结构体
struct Bullet {
    int x, y;
};

vector<Bullet> bullets;  // 存储所有子弹

void Setup() {
    gameover = false;
    x = width / 2;
    y = height - 1;
    enemyX = rand() % width;
    enemyY = 0;
    score = 0;
    bullets.clear();  // 清空子弹
}

void Draw() {
    system("cls");

    // 绘制游戏界面
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "P"; // Player
            else if (i == enemyY && j == enemyX)
                cout << "E"; // Enemy
            else {
                bool isBullet = false;
                for (const Bullet& bullet : bullets) {
                    if (i == bullet.y && j >= bullet.x && j < bullet.x + 15) {
                        cout << "|"; // Bullet (宽度为15)
                        isBullet = true;
                        break;
                    }
                }
                if (!isBullet)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score:" << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            x -= playerSpeed; // 左移
            break;
        case 'd':
            x += playerSpeed; // 右移
            break;
        case 'x':
            gameover = true; // 游戏结束
            break;
        case ' ':
            bullets.push_back({ x, y - 1 });  // 按空格键生成新的子弹
            break;
        }
    }
}

void Logic() {
    // 移动敌人
    enemyY += enemySpeed;

    // 主角通过边界，出现在画面另一端
    if (x >= width)
        x = 0;
    else if (x < 0)
        x = width - 1;

    // 生成新的子弹（每隔10毫秒生成一颗新的子弹）
    static int bulletCooldown = 0;
    bulletCooldown++;
    if (bulletCooldown >= 1) {
        bullets.push_back({ x, y - 1 });
        bulletCooldown = 0;
    }

    // 移动所有子弹
    for (auto it = bullets.begin(); it != bullets.end();) {
        it->y -= bulletSpeed;
        if (it->y < 0) {
            it = bullets.erase(it);  // 如果子弹越过屏幕上方，从容器中移除
        }
        else {
            ++it;
        }
    }

    // 子弹与敌人碰撞
    for (auto it = bullets.begin(); it != bullets.end();) {
        if (it->x <= enemyX + 1 && it->x + 15 >= enemyX && it->y == enemyY) {
            score++;
            enemyX = rand() % (width - 1);  // 修正敌人出现在最左边的问题
            enemyY = 0;
            it = bullets.erase(it);
        }
        else {
            ++it;
        }
    }

    // 游戏结束条件
    if (y < 0 || y >= height || enemyY == height) {
        gameover = true;

        // 游戏结束时等待用户按键
        cout << "Game Over! Your Score: " << score << endl;
        cout << "Press 'r' to restart or any other key to exit...";


        // 检测用户输入
        char userInput = _getch();
        if (userInput == 'r' || userInput == 'R') {
            // 重新开始游戏
            Setup();
            gameover = false;
        }
    }
}

int main() {
    Setup();

    while (!gameover) {
        Draw();
        Input();
        Logic();
        Sleep(50); // 等待 10 毫秒
    }

    return 0;
}
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameover;
const int width = 40;
const int height = 20;
int x, y, enemyX, enemyY, score, highScore;

// 调整速度参数
const int playerSpeed = 6;         // 提高主角移动速度
const float enemySpeed = 1;        // 进一步降低敌人移动速度
const int bulletSpeed = 4;         // 提高子弹移动速度
const int bulletCooldownLimit = 2; // 每隔5毫秒生成一颗新的子弹
const int refreshRate = 25;        // 游戏刷新速度为50毫秒

// 子弹结构体
struct Bullet
{
    int x, y;
};

vector<Bullet> bullets; // 存储所有子弹

// 初始化游戏
void Setup()
{
    gameover = false;
    x = width / 2;
    y = height - 1;
    enemyX = rand() % (width - 1); // 修正敌人出现在最左边的问题
    enemyY = 0;
    score = 0;
    bullets.clear(); // 清空子弹

    // 读取最高分记录
    ifstream highScoreFile("highscore.txt");
    if (highScoreFile.is_open())
    {
        highScoreFile >> highScore;
        highScoreFile.close();
    }
    else
    {
        // 如果文件不存在，默认最高分为0
        highScore = 0;
    }
}

// 绘制游戏界面
void Draw()
{
    system("cls");

    // 绘制游戏界面
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "P"; // Player
            else if (i == enemyY && j == enemyX)
                cout << "E"; // Enemy
            else
            {
                bool isBullet = false;
                for (const Bullet &bullet : bullets)
                {
                    if (i == bullet.y && j >= bullet.x && j < bullet.x + 15)
                    {
                        cout << "|"; // Bullet (宽度为15)
                        isBullet = true;
                        break;
                    }
                }
                if (!isBullet)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score:" << score << "  High Score:" << highScore << endl;
}

// 处理用户输入
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            x -= playerSpeed; // 左移
            break;
        case 'd':
            x += playerSpeed; // 右移
            break;
        case 'x':
            gameover = true; // 游戏结束
            break;
        case ' ':
            // 按空格键生成新的子弹，但需要检查发射间隔
            static int bulletCooldown = 0;
            bulletCooldown++;
            if (bulletCooldown >= bulletCooldownLimit)
            {
                bullets.push_back({x, y - 1});
                bulletCooldown = 0;
            }
            break;
        }
    }
}

// 游戏逻辑处理
void Logic()
{
    // 移动敌人
    enemyY += enemySpeed;

    // 主角通过边界，出现在画面另一端
    if (x >= width)
        x = 0;
    else if (x < 0)
        x = width - 1;

    // 生成新的子弹（每隔5毫秒生成一颗新的子弹）
    static int bulletCooldown = 0;
    bulletCooldown++;
    if (bulletCooldown >= 1)
    {
        bullets.push_back({x, y - 1});
        bulletCooldown = 0;
    }

    // 移动所有子弹
    for (auto it = bullets.begin(); it != bullets.end();)
    {
        it->y -= bulletSpeed;
        if (it->y < 0)
        {
            it = bullets.erase(it); // 如果子弹越过屏幕上方，从容器中移除
        }
        else
        {
            ++it;
        }
    }

    // 子弹与敌人碰撞
    for (auto it = bullets.begin(); it != bullets.end();)
    {
        // 修正敌人出现在最左边时也能被子弹击中的问题
        if (it->x <= enemyX + 1 && it->x + 15 >= enemyX && it->y == enemyY)
        {
            score++;
            enemyX = rand() % (width - 1);
            enemyY = 0;
            it = bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // 更新最高分
    if (score > highScore)
    {
        highScore = score;

        // 将最高分记录写入文件
        ofstream highScoreFile("highscore.txt");
        if (highScoreFile.is_open())
        {
            highScoreFile << highScore;
            highScoreFile.close();
        }
    }

    // 游戏结束条件
    if (y < 0 || y >= height || enemyY == height)
    {
        gameover = true;

        // 游戏结束时等待用户按键
        cout << "Game Over! Your Score: " << score << endl;
        cout << "Press 'r' to restart or any other key to exit...";

        // 检测用户输入
        char userInput = _getch();
        if (userInput == 'r' || userInput == 'R')
        {
            // 重新开始游戏
            Setup();
            gameover = false;
        }
    }
}

int main()
{
    Setup();

    while (!gameover)
    {
        Draw();
        Input();
        Logic();
        Sleep(refreshRate); // 等待 50 毫秒
    }

    return 0;
}