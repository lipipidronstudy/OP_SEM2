#pragma once
class ForTest {
public:
    int age;
    int grade;

    ForTest() {
        age = 0;
        grade = 0;
    }
    bool operator==(ForTest &other) const {
        return age == other.age && grade == other.grade;
    }
    bool operator!=(ForTest &other) const {
        return age != other.age || grade != other.grade;
    }
};

bool parents(ForTest &person1, ForTest &person2) {
    return person1.age >= 18 && person2.age >= 18;
}

template<typename Pointer, typename Predicate>
bool none_of(Pointer first, Pointer last, Predicate predicate) {
    for (; first != last; ++first) {
        if (predicate != *first) {
            return false;
        }
    }
    return true;
}

template<typename Pointer, typename Compare>
bool is_sorted(Pointer first, Pointer last, Compare compare) {
    --last;
    for (; first != last; ++first) {
        Pointer now = first;
        Pointer next = ++now;
        --now;
        if (!compare(*now, *next)) {
            return compare(*now, *next);
        }
    }
    return true;
}

template<typename Pointer, typename Predicate>
Predicate find_not(Pointer first, Pointer last, Predicate predicate) {
    for (; first != last; ++first) {
        if (predicate != *first) {
            return *first;
        }
    }
    std::cout << "Not found, returned: ";
    return *last;
}
