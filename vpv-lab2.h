//**************************************************************************************
// ������ ������������ ���������� ������� sin(x)/x = 1 - x^2/3! + x^4/5! - x^6/7! + ...
// vpv-lab2: ���� 2020:: nvnulstu@gmail.com 
//**************************************************************************************
#pragma once
#include "stdlib.h"
#include <string>
#include <algorithm>
#include <vector>
#include "bern.h"

using namespace std;

#define LEN_RES 19  // ����������� ���������� �������, � ������� ���� �������� ����� ���� ������
#define MAX_ERR (float)(1.0/(1 << LEN_RES)) // �������� ����������� ����� 2^(-LEN_RES)
#define LEN_POLINOM 13 // ���������� ����� 5 ������ ����
#define X_STEP ((float)1.0/(float)(1 << 24)) // 2^(-24) - ��� �������� ������� �������� float

// �������� ����������� 
#define FACT3 (float)(2 * 3)
#define FACT5 (float)(2 * 3 * 4 * 5)
#define FACT7 (float)(2 * 3 * 4 * 5 * 6 * 7)
#define FACT9 (float)(2 * 3 * 4 * 5 * 6 * 7 * 8 * 9)

// �������� �������� ������� ����������� (float)
#define DIV1_FACT3 (1./FACT3)
#define DIV1_FACT5 (1./FACT5)
#define DIV1_FACT7 (1./FACT7)
#define DIV1_FACT9 (1./FACT9)


// ��� ������
#define DOUBLE_FACT1 (float)(2 * 1)
#define DOUBLE_FACT2 (float)(2 * 1 * 2)
#define DOUBLE_FACT3 (float)(2 * 1 * 2 * 3)
#define DOUBLE_FACT4 (float)(2 * 1 * 2 * 3 * 4)
#define DOUBLE_FACT5 (float)(2 * 1 * 2 * 3 * 4 * 5)
#define DOUBLE_FACT6 (float)(2 * 1 * 2 * 3 * 4 * 5 * 6)
#define DOUBLE_FACT7 (float)(2 * 1 * 2 * 3 * 4 * 5 * 6 * 7)
#define DOUBLE_FACT8 (float)(2 * 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8)
#define DOUBLE_FACT9 (float)(2 * 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9)
#define DOUBLE_FACT10 (float)(2 * 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10)
#define DOUBLE_FACT11 (float)(2 * 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11)
#define DOUBLE_FACT12 (float)(2 * 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12)
#define DOUBLE_FACT13 (float)(2 * 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13)

#define BERN1 (float)(1 / 6)
#define BERN2 (float)(1 / 30)
#define BERN3 (float)(1 / 42)
#define BERN4 (float)(1 / 30)
#define BERN5 (float)(5 / 66)
#define BERN6 (float)(691 / 2730)
#define BERN7 (float)(7 / 6)
#define BERN8 (float)(3617 / 510)
#define BERN9 (float)(43867 / 798)
#define BERN10 (float)(174611 / 330)
#define BERN11 (float)(854513 / 138)
#define BERN12 (float)(236364091 / 2730)
#define BERN13 (float)(8553103 / 6)

typedef float(*FloatFunc)(float); // ��������� �� ������� ������������ ��������

typedef long FixPoint;

// � ������� ����� �������������� ����� 30 ���
#define FRACT_PART 30 
// 2^31 - ��������� ��� ��������� 31 ���� �������� � long, ����������� ����� � ������������� ������  
#define FACTOR (1 << FRACT_PART) 
#define FLOAT2FIX(x) (FixPoint)(x * FACTOR) // �������������� float � Fixed
#define FIX2FLOAT(x) ((float)x / FACTOR)   // �������������� Fixed �� float
#define FIXMUL(x,y) ((FixPoint)((__int64)x * (__int64)y >> FRACT_PART))     // ��������� ������������� � �++ ������� ������� ��������
// �������� �������� ������� ����������� (FixPointt)
#define DIV1_FACT1FP (FixPoint)FLOAT2FIX(1.0) // 1 � ������� FixPoint
#define DIV1_FACT3FP (FixPoint)FLOAT2FIX(DIV1_FACT3)
#define DIV1_FACT5FP (FixPoint)FLOAT2FIX(DIV1_FACT5)
#define DIV1_FACT7FP (FixPoint)FLOAT2FIX(DIV1_FACT7)
#define DIV1_FACT9FP (FixPoint)FLOAT2FIX(DIV1_FACT9)
#define TAB "\t"

// ��������� ������� � ������ �� ����� "������ - ������ TSC"
#define CPUID_RDTSC(t) \
	__asm xor eax, eax\
	__asm cpuid __asm rdtsc\
	__asm mov DWORD PTR[t], eax\
	__asm mov DWORD PTR[t + 4], edx

typedef FixPoint(*FixedFunc)(FixPoint); // ��������� �� ������� ������������ ����������

vector<float> arrX; // ������ ���������� ��� ����� ���������

float flMathFunc(float);
// ��������� ����� ��������� � ���������� �������������� �������
struct Result {
	string shortname;	// �������� ��� ������ ������ ������
	string name;		// ������������ ������ �������
	__int64 min, max;	// ������� � �������� ����� ������ ������ ������� (�� ����������)
	double avg, dev;	// ������� � ���
	double factor;		// ��������� avg ������� ������ � avg ������ �������� ������
	Result(string sn, string nm, __int64 minim, __int64 maxim, double average, double deviation) :
		shortname(sn), name(nm), min(minim), max(maxim), avg(average), dev(deviation) {};
};

class Report; // �����

struct Config {
	int count;			// ����� ������� � ����� �����
	int delMax, delMin;	// ����� ��������� ������������ � ����������� ��������� ��� ���������� ����������� ����� ���������
	int lenPrintLog;	// ����� ������ ����������� ����� ���������, ��������� �� �������
	int pass;			// ����� �������� ��� ������� �������������
	Report * rep;		// ��������� �� �����
	float maxErr;		// ����������� ���������� �����������
	float xStepVerify;	// ��� ������ �������� ��������� ��� ����������� float
	__int64 overhead;	// ������ ��������� �������� �� ��������� ������� � ������
	Config(int cnt, int maxd, int mind, int nPrint, int npass, Report * report, float err, float step, __int64 over)
		  :	count(cnt), delMax(maxd), delMin(mind), lenPrintLog(nPrint), pass(npass), rep(report), maxErr(err), 
			xStepVerify(step), overhead(over) {};
};