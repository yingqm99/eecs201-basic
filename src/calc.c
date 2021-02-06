#include "calc.h"

const char *op_to_string(enum op op)
{
#define _(x) case(OP_##x): return #x;
    switch (op) {
    _(ADD)
    _(SUB)
    _(MUL)
    _(DIV)
    default: return "(unknown op)";
    }
#undef _
}

enum status calculate(int arg1, int arg2, enum op op, int *result)
{
    switch(op) {
    case OP_ADD:
        *result = arg1 + arg2;
        return STATUS_OKAY;
    case OP_SUB:
        *result = arg1 - arg2;
        return STATUS_OKAY;
    // Issue #149: add support for mult
    case OP_DIV:
        // Issue #221: handle div by 0
        *result = arg1 / arg2;
        return STATUS_OKAY;
    }
    return STATUS_UNSUPPORTED;
}
