#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
    double lengthFromCenter;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
        lengthFromCenter = sqrt(pow(x, 2) * pow(y, 2));
    }

    void print() {
        cout << "X: " << x << ", Y: " << y << ", length from center: " << lengthFromCenter << endl;
    }
};

/*double getLengthFromCenter(int x, int y) {

}*/

int main() {
    Point p = Point(3, 5);
    p.print();
    return 0;
}