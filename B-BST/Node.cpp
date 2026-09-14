#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// ====================== STUDENT ======================
struct Student {
    string mssv;
    string hoTen;
    string lop;
    string khoa;

    double gpa;
    double drl;
    double ctxh;
    int soHoatDong;

    bool duDieuKien;
    vector<double> diemMon;
    bool daNopMinhChung;
    string ghiChu;

    Student(string ma = "", string ten = "", string l = "", string k = "") {
        mssv = ma;
        hoTen = ten;
        lop = l;
        khoa = k;
        gpa = drl = ctxh = 0;
        soHoatDong = 0;
        duDieuKien = false;
        daNopMinhChung = false;
    }

    // So sánh đa tiêu chí (quan trọng)
    bool operator<(const Student& other) const {
        if (gpa != other.gpa) return gpa > other.gpa;
        if (drl != other.drl) return drl > other.drl;
        if (ctxh != other.ctxh) return ctxh > other.ctxh;
        if (soHoatDong != other.soHoatDong) return soHoatDong > other.soHoatDong;
        return mssv < other.mssv;
    }
};

// ====================== NODE ======================
struct Node {
    Student data;
    Node* left;
    Node* right;
    int height;

    Node(Student s) {
        data = s;
        left = right = nullptr;
        height = 1;
    }
};