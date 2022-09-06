arr = ["01000000", "00555555", "00333333", "00249249", "001C71C7", "001745D1", "0013B13B", "00111111", "000F0F0F",
       "000D7943", "000C30C3", "000B2164", "000A3D70", "00097B42", "0008D3DC", "00084210", "0007C1F0", "00075075",
       "0006EB3E", "00069069",
       "00063E70", "0005F417", "0005B05B", "00057262", "00053978", "00050505", "0004D487", "0004A790", "00047DC1",
       "000456C7"]

# for i in arr[::-1]:
#     print(f"""
# IMUL	ECX
# MOV		EAX, EDX
# SAL		EAX, 2
# ADD		EAX, {i}H""")


def double(n):
    qwe = "2 "
    for i in range(n-1):
        qwe += "* 2 "
    return qwe


for i in range(12, -1, -1):
    # print(f'{double(2 * i - 1)} * ({double(2*i)}- 1) * BERN{i}')
    # print(f'#define KOEF{i} (float)(TWO_SQUARE{i} * (TWO_SQUARE{i} * 2 - 1) * BERN{i} / ({i} * FACT{2*i}))')
    # print(f"#define DOUBLE_SQUARE{i} (float)({double(2 * i - 1)})")
    # print(f"KOEF{i}FP, ", end="")
    # print(f"#define FACT{i*2} ({'*'.join(str(a) for a in range(2,i*2+1))})")
    # print(f"#define KOEF{i}FP (FixPoint)FLOAT2FIX(KOEF{i})")
    print(f"sum = FIXMUL(sum, x2) - KOEF{i}FP;")
