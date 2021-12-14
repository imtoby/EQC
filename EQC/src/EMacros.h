#pragma once
#ifndef EMACROS_H_A1575C0A_69E8_464F_A49D_248235DC6580
#define EMACROS_H_A1575C0A_69E8_464F_A49D_248235DC6580

#define freePointer(p) \
    if (p) {             \
        delete p;        \
        p = nullptr;     \
    }

#endif // EMACROS_H_A1575C0A_69E8_464F_A49D_248235DC6580
