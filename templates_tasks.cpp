// templates_tasks.cpp
#include <iostream>

using namespace std;

// =========================
// TASK 1
// Template min
// =========================
template<typename T>
T my_min(T a, T b) {

    if (a < b) {
        return a;
    }

    return b;
}

// =========================
// TASK 2
// Overloaded print_info
// =========================
void print_info(int x) {

    cout << "Number: " << x << endl;
}

void print_info(const char* text) {

    cout << "Text: " << text << endl;
}

void print_info(char c) {

    cout << "Character: " << c << endl;
}

// =========================
// TASK 3 + 4 + 8
// point with << and >>
// =========================
struct point {

    int x;
    int y;
    int z;
};

ostream& operator<<(ostream& out, const point& p) {

    out << "("
        << p.x << ", "
        << p.y << ", "
        << p.z << ")";

    return out;
}

istream& operator>>(istream& in, point& p) {

    in >> p.x >> p.y >> p.z;

    return in;
}

// =========================
// TASK 5
// student
// =========================
struct student {

    int id;
    int age;
    double grade;
};

ostream& operator<<(ostream& out, const student& s) {

    out << "Student #"
        << s.id
        << " (age: "
        << s.age
        << ", grade: "
        << s.grade
        << ")";

    return out;
}

// =========================
// TASK 6
// template pair
// =========================
template<typename T, typename U>
struct pair_template {

    T first;
    U second;

    pair_template(T a, U b) {

        first = a;
        second = b;
    }
};

// =========================
// TASK 7
// template vector
// =========================
template<typename T>
struct vector_template {

    T* data;
    int size;
    int capacity;

    // constructor
    vector_template() {

        size = 0;
        capacity = 2;

        data = new T[capacity];
    }

    // destructor
    ~vector_template() {

        delete[] data;
    }

    // push_back
    void push_back(T value) {

        if (size >= capacity) {

            capacity *= 2;

            T* new_data = new T[capacity];

            for (int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }

            delete[] data;

            data = new_data;
        }

        data[size] = value;

        size++;
    }

    // print
    void print() {

        cout << "[";

        for (int i = 0; i < size; i++) {

            cout << data[i];

            if (i != size - 1) {
                cout << ", ";
            }
        }

        cout << "]" << endl;
    }
};

// =========================
// TASK 10
// template swap
// =========================
template<typename T>
void my_swap(T& a, T& b) {

    T temp = a;

    a = b;

    b = temp;
}

// =========================
// MAIN
// =========================
int main() {

    // =====================
    // TASK 1
    // =====================
    cout << "TASK 1\n";

    cout << my_min(5, 3) << endl;
    cout << my_min(2.5, 8.1) << endl;
    cout << my_min('a', 'z') << endl;


    // =====================
    // TASK 2
    // =====================
    cout << "\nTASK 2\n";

    print_info(100);
    print_info("Hello");
    print_info('A');


    // =====================
    // TASK 3 + 4 + 8
    // =====================
    cout << "\nTASK 3 + 4 + 8\n";

    point p;

    cout << "Enter point (x y z): ";

    cin >> p;

    cout << p << endl;


    // =====================
    // TASK 5
    // =====================
    cout << "\nTASK 5\n";

    student s;

    s.id = 1;
    s.age = 18;
    s.grade = 95.5;

    cout << s << endl;


    // =====================
    // TASK 6
    // =====================
    cout << "\nTASK 6\n";

    pair_template<int, double> p1(5, 3.14);

    pair_template<char, int> p2('A', 42);

    cout << p1.first << " " << p1.second << endl;

    cout << p2.first << " " << p2.second << endl;


    // =====================
    // TASK 7
    // =====================
    cout << "\nTASK 7\n";

    vector_template<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    numbers.print();

    vector_template<point> points;

    points.push_back({0, 0, 0});
    points.push_back({1, 1, 1});

    points.print();


    // =====================
    // TASK 9
    // =====================
    cout << "\nTASK 9\n";

    vector_template<point> points2;

    points2.push_back({0, 0, 0});
    points2.push_back({1, 1, 1});
    points2.push_back({-5, 3, 2});

    cout << "Initial points:\n";

    points2.print();

    point new_point;

    cout << "Enter new point (x y z): ";

    cin >> new_point;

    points2.push_back(new_point);

    cout << "Updated points:\n";

    points2.print();


    // =====================
    // TASK 10
    // =====================
    cout << "\nTASK 10\n";

    int x = 5;
    int y = 10;

    cout << "Before swap: "
         << x << " "
         << y << endl;

    my_swap(x, y);

    cout << "After swap: "
         << x << " "
         << y << endl;

    double a = 3.14;
    double b = 2.71;

    cout << "Before swap: "
         << a << " "
         << b << endl;

    my_swap(a, b);

    cout << "After swap: "
         << a << " "
         << b << endl;

    return 0;
}
