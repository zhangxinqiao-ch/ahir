
#ifndef HANDLE_OP
#define HANDLE_OP(name)
#endif

#ifndef FIRST_CONTROL
#define FIRST_CONTROL(name)
#endif

#ifndef HANDLE_CONTROL
#define HANDLE_CONTROL(name) HANDLE_OP(name)
#endif

#ifndef LAST_CONTROL
#define LAST_CONTROL(name)
#endif

#ifndef FIRST_DATA
#define FIRST_DATA(name)
#endif

#ifndef HANDLE_DATA
#define HANDLE_DATA(name) HANDLE_OP(name)
#endif

#ifndef LAST_DATA
#define LAST_DATA(name)
#endif

#ifndef FIRST_BINARY
#define FIRST_BINARY(name)
#endif

#ifndef HANDLE_BINARY
#define HANDLE_BINARY(name) HANDLE_DATA(name)
#endif

#ifndef LAST_BINARY
#define LAST_BINARY(name)
#endif

#ifndef FIRST_REL
#define FIRST_REL(name)
#endif

#ifndef HANDLE_REL
#define HANDLE_REL(name) HANDLE_BINARY(name)
#endif

#ifndef LAST_REL
#define LAST_REL(name)
#endif

#ifndef FIRST_FCMP
#define FIRST_FCMP(name)
#endif

#ifndef HANDLE_FCMP
#define HANDLE_FCMP(name) HANDLE_REL(name)
#endif

#ifndef LAST_FCMP
#define LAST_FCMP(name)
#endif

#ifndef FIRST_ICMP
#define FIRST_ICMP(name)
#endif

#ifndef HANDLE_ICMP
#define HANDLE_ICMP(name) HANDLE_REL(name)
#endif

#ifndef LAST_ICMP
#define LAST_ICMP(name)
#endif

#ifndef FIRST_CAST
#define FIRST_CAST(name)
#endif

#ifndef HANDLE_CAST
#define HANDLE_CAST(name) HANDLE_DATA(name)
#endif

#ifndef LAST_CAST
#define LAST_CAST(name)
#endif

#ifndef FIRST_SHIFT
#define FIRST_SHIFT(name)
#endif

#ifndef HANDLE_SHIFT
#define HANDLE_SHIFT(name) HANDLE_BINARY(name)
#endif

#ifndef LAST_SHIFT
#define LAST_SHIFT(name)
#endif

#ifndef FIRST_MISC
#define FIRST_MISC(name)
#endif

#ifndef HANDLE_MISC
#define HANDLE_MISC(name) HANDLE_DATA(name)
#endif

#ifndef LAST_MISC
#define LAST_MISC(name)
#endif


HANDLE_CONTROL(Fork)
FIRST_CONTROL(Fork)
HANDLE_CONTROL(Join)
HANDLE_CONTROL(Branch)
HANDLE_CONTROL(Merge)
HANDLE_CONTROL(Start)
HANDLE_CONTROL(Stop)
LAST_CONTROL(Stop)

HANDLE_BINARY(Add)
FIRST_BINARY(Add)
FIRST_DATA(Add)
HANDLE_BINARY(FAdd)
HANDLE_BINARY(Sub)
HANDLE_BINARY(FSub)
HANDLE_BINARY(Mul)
HANDLE_BINARY(FMul)
HANDLE_BINARY(SDiv)
HANDLE_BINARY(UDiv)
HANDLE_BINARY(FDiv)
HANDLE_BINARY(SRem)
HANDLE_BINARY(URem)
HANDLE_BINARY(FRem)
HANDLE_BINARY(And)
HANDLE_BINARY(Or)
HANDLE_BINARY(Xor)

HANDLE_FCMP(FCMP_FALSE)
FIRST_FCMP(FCMP_FALSE)
FIRST_REL(FCMP_FALSE)
HANDLE_FCMP(FCMP_OEQ)
HANDLE_FCMP(FCMP_OGT)
HANDLE_FCMP(FCMP_OGE)
HANDLE_FCMP(FCMP_OLT)
HANDLE_FCMP(FCMP_OLE)
HANDLE_FCMP(FCMP_ONE)
HANDLE_FCMP(FCMP_ORD)
HANDLE_FCMP(FCMP_UNO)
HANDLE_FCMP(FCMP_UEQ)
HANDLE_FCMP(FCMP_UGT)
HANDLE_FCMP(FCMP_UGE)
HANDLE_FCMP(FCMP_ULT)
HANDLE_FCMP(FCMP_ULE)
HANDLE_FCMP(FCMP_UNE)
HANDLE_FCMP(FCMP_TRUE)
LAST_FCMP(FCMP_TRUE)
HANDLE_ICMP(ICMP_EQ)
FIRST_ICMP(ICMP_EQ)
HANDLE_ICMP(ICMP_NE)
HANDLE_ICMP(ICMP_UGT)
HANDLE_ICMP(ICMP_UGE)
HANDLE_ICMP(ICMP_ULT)
HANDLE_ICMP(ICMP_ULE)
HANDLE_ICMP(ICMP_SGT)
HANDLE_ICMP(ICMP_SGE)
HANDLE_ICMP(ICMP_SLT)
HANDLE_ICMP(ICMP_SLE)
LAST_ICMP(ICMP_SLE)
LAST_REL(ICMP_SLE)

HANDLE_SHIFT(Shl)
FIRST_SHIFT(Shl)
HANDLE_SHIFT(LShr)
HANDLE_SHIFT(AShr)
LAST_SHIFT(AShr)
LAST_BINARY(AShr)

HANDLE_CAST(Trunc)
FIRST_CAST(Trunc)
HANDLE_CAST(ZExt)
HANDLE_CAST(SExt)
HANDLE_CAST(FPTrunc)
HANDLE_CAST(FPExt)
HANDLE_CAST(FPToUI)
HANDLE_CAST(FPToSI)
HANDLE_CAST(UIToFP)
HANDLE_CAST(SIToFP)
HANDLE_CAST(PtrToInt)
HANDLE_CAST(IntToPtr)
LAST_CAST(IntToPtr)

HANDLE_MISC(Multiplexer)
FIRST_MISC(Multiplexer)
HANDLE_MISC(Select)
HANDLE_MISC(LoadRequest)
HANDLE_MISC(LoadComplete)
HANDLE_MISC(Store)
HANDLE_MISC(Call)
HANDLE_MISC(Response)
HANDLE_MISC(Accept)
HANDLE_MISC(Return)
HANDLE_MISC(Input)
HANDLE_MISC(Output)
HANDLE_MISC(Address)
HANDLE_MISC(Constant)
LAST_MISC(Constant)
LAST_DATA(Constant)

#undef HANDLE_OP
#undef FIRST_CONTROL
#undef HANDLE_CONTROL
#undef LAST_CONTROL
#undef FIRST_DATA
#undef HANDLE_DATA
#undef LAST_DATA
#undef FIRST_BINARY
#undef HANDLE_BINARY
#undef LAST_BINARY
#undef FIRST_REL
#undef HANDLE_REL
#undef LAST_REL
#undef FIRST_ICMP
#undef HANDLE_ICMP
#undef LAST_ICMP
#undef FIRST_FCMP
#undef HANDLE_FCMP
#undef LAST_FCMP
#undef FIRST_CAST
#undef HANDLE_CAST
#undef LAST_CAST
#undef FIRST_SHIFT
#undef HANDLE_SHIFT
#undef LAST_SHIFT
#undef FIRST_MISC
#undef HANDLE_MISC
#undef LAST_MISC