class Person {
public:
    string name;
    int age;

    virtual void getdata() {
        cin >> name >> age;
    }

    virtual void putdata() {
        cout << name << " " << age << "\n";
    }
};

class Professor : public Person {
public:
    int publications;
    int cur_id;

    static int id;

    Professor() {
        cur_id = ++id;
    }

    void getdata() {
        cin >> name >> age >> publications;
    }

    void putdata() {
        cout << name << " " << age << " "
             << publications << " " << cur_id << "\n";
    }
};

int Professor::id = 0;


class Student : public Person {
public:
    int marks[6];
    int cur_id;

    static int id;

    Student() {
        cur_id = ++id;
    }

    void getdata() {
        cin >> name >> age;

        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }

    void putdata() {
        int sum = 0;

        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }

        cout << name << " " << age << " "
             << sum << " " << cur_id << "\n";
    }
};

int Student::id = 0;
