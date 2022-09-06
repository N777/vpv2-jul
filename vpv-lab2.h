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
#define FACT3 (1 * 2 * 3)
#define FACT5 (1 * 2 * 3 * 4 * 5)
#define FACT7 (1 * 2 * 3 * 4 * 5 * 6 * 7)
#define FACT9 (1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9)
#define FACT2 (2.)
#define FACT4 (2.*3*4)
#define FACT6 (2.*3*4*5*6)
#define FACT8 (2.*3*4*5*6*7*8)
#define FACT10 (2.*3*4*5*6*7*8*9*10)
#define FACT12 (2.*3*4*5*6*7*8*9*10*11*12)
#define FACT14 (2.*3*4*5*6*7*8*9*10*11*12*13*14)
#define FACT16 (2.*3*4*5*6*7*8*9*10*11*12*13*14*15*16)
#define FACT18 (2.*3*4*5*6*7*8*9*10*11*12*13*14*15*16*17*18)
#define FACT20 (2.*3*4*5*6*7*8*9*10*11*12*13*14*15*16*17*18*19*20)
#define FACT22 (2.*3*4*5*6*7*8*9*10*11*12*13*14*15*16*17*18*19*20*21*22)
#define FACT24 (2.*3*4*5*6*7*8*9*10*11*12*13*14*15*16*17*18*19*20*21*22*23*24)
#define FACT26 (2.*3*4*5*6*7*8*9*10*11*12*13*14*15*16*17*18*19*20*21*22*23*24*25*26)


// �������� �������� ������� ����������� (float)
#define DIV1_FACT3 (1./FACT3)
#define DIV1_FACT5 (1./FACT5)
#define DIV1_FACT7 (1./FACT7)
#define DIV1_FACT9 (1./FACT9)


// ��� ������

#define BERN1 (1 / 6.)
#define BERN2 (1 / 30.)
#define BERN3 (1 / 42.)
#define BERN4 (1 / 30.)
#define BERN5 (5 / 66.)
#define BERN6 (691 / 2730.)
#define BERN7 (7 / 6.)
#define BERN8 (3617 / 510.)
#define BERN9 (43867 / 798.)
#define BERN10 (174611 / 330.)
#define BERN11 (854513 / 138.)
#define BERN12 (236364091 / 2730.)
#define BERN13 (8553103 / 6.)

#define TWO_SQUARE1 (2. )
#define TWO_SQUARE2 (2. * 2 * 2 )
#define TWO_SQUARE3 (2. * 2 * 2 * 2 * 2 )
#define TWO_SQUARE4 (2. * 2 * 2 * 2 * 2 * 2 * 2 )
#define TWO_SQUARE5 (2. * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 )
#define TWO_SQUARE6 (2. * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 )
#define TWO_SQUARE7 (2. * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 )
#define TWO_SQUARE8 (2. * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 )
#define TWO_SQUARE9 (2. * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 )
#define TWO_SQUARE10 (2. * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 )
#define TWO_SQUARE11 (2. * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 )
#define TWO_SQUARE12 (2. * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 )
#define TWO_SQUARE13 (2. * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 )

#define KOEF1 (float)(TWO_SQUARE1 * (TWO_SQUARE1 * 2 - 1) * BERN1 / (1 * FACT2))
#define KOEF2 (float)(TWO_SQUARE2 * (TWO_SQUARE2 * 2 - 1) * BERN2 / (2 * FACT4))
#define KOEF3 (float)(TWO_SQUARE3 * (TWO_SQUARE3 * 2 - 1) * BERN3 / (3 * FACT6))
#define KOEF4 (float)(TWO_SQUARE4 * (TWO_SQUARE4 * 2 - 1) * BERN4 / (4 * FACT8))
#define KOEF5 (float)(TWO_SQUARE5 * (TWO_SQUARE5 * 2 - 1) * BERN5 / (5 * FACT10))
#define KOEF6 (float)(TWO_SQUARE6 * (TWO_SQUARE6 * 2 - 1) * BERN6 / (6 * FACT12))
#define KOEF7 (float)(TWO_SQUARE7 * (TWO_SQUARE7 * 2 - 1) * BERN7 / (7 * FACT14))
#define KOEF8 (float)(TWO_SQUARE8 * (TWO_SQUARE8 * 2 - 1) * BERN8 / (8 * FACT16))
#define KOEF9 (float)(TWO_SQUARE9 * (TWO_SQUARE9 * 2 - 1) * BERN9 / (9 * FACT18))
#define KOEF10 (float)(TWO_SQUARE10 * (TWO_SQUARE10 * 2 - 1) * BERN10 / (10 * FACT20))
#define KOEF11 (float)(TWO_SQUARE11 * (TWO_SQUARE11 * 2 - 1) * BERN11 / (11 * FACT22))
#define KOEF12 (float)(TWO_SQUARE12 * (TWO_SQUARE12 * 2 - 1) * BERN12 / (12 * FACT24))
#define KOEF13 (float)(TWO_SQUARE13 * (TWO_SQUARE13 * 2 - 1) * BERN13 / (13 * FACT26))

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
#define KOEF1FP (FixPoint)FLOAT2FIX(KOEF1)
#define KOEF2FP (FixPoint)FLOAT2FIX(KOEF2)
#define KOEF3FP (FixPoint)FLOAT2FIX(KOEF3)
#define KOEF4FP (FixPoint)FLOAT2FIX(KOEF4)
#define KOEF5FP (FixPoint)FLOAT2FIX(KOEF5)
#define KOEF6FP (FixPoint)FLOAT2FIX(KOEF6)
#define KOEF7FP (FixPoint)FLOAT2FIX(KOEF7)
#define KOEF8FP (FixPoint)FLOAT2FIX(KOEF8)
#define KOEF9FP (FixPoint)FLOAT2FIX(KOEF9)
#define KOEF10FP (FixPoint)FLOAT2FIX(KOEF10)
#define KOEF11FP (FixPoint)FLOAT2FIX(KOEF11)
#define KOEF12FP (FixPoint)FLOAT2FIX(KOEF12)
#define KOEF13FP (FixPoint)FLOAT2FIX(KOEF13)

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