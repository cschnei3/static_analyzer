#ifndef PRINTER_HEADER
#define PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Certain applications may improve performance by changing the buffer size */
#define BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define _L_PAREN '('
#define _R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
  void indent(void);
  void backup(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char* print(Visitable* v);

  void visitProgram(Program *p); /* abstract class */
  void visitProgr(Progr *p);
  void visitListExternal_declaration(ListExternal_declaration* p);
  void visitExternal_declaration(External_declaration *p); /* abstract class */
  void visitAfunc(Afunc *p);
  void visitGlobal(Global *p);
  void visitFunction_def(Function_def *p); /* abstract class */
  void visitOldFunc(OldFunc *p);
  void visitNewFunc(NewFunc *p);
  void visitOldFuncInt(OldFuncInt *p);
  void visitNewFuncInt(NewFuncInt *p);
  void visitDec(Dec *p); /* abstract class */
  void visitNoDeclarator(NoDeclarator *p);
  void visitDeclarators(Declarators *p);
  void visitListDec(ListDec* p);
  void visitListDeclaration_specifier(ListDeclaration_specifier* p);
  void visitDeclaration_specifier(Declaration_specifier *p); /* abstract class */
  void visitType(Type *p);
  void visitStorage(Storage *p);
  void visitSpecProp(SpecProp *p);
  void visitListInit_declarator(ListInit_declarator* p);
  void visitInit_declarator(Init_declarator *p); /* abstract class */
  void visitOnlyDecl(OnlyDecl *p);
  void visitInitDecl(InitDecl *p);
  void visitType_specifier(Type_specifier *p); /* abstract class */
  void visitTvoid(Tvoid *p);
  void visitTchar(Tchar *p);
  void visitTshort(Tshort *p);
  void visitTint(Tint *p);
  void visitTlong(Tlong *p);
  void visitTfloat(Tfloat *p);
  void visitTdouble(Tdouble *p);
  void visitTsigned(Tsigned *p);
  void visitTunsigned(Tunsigned *p);
  void visitTstruct(Tstruct *p);
  void visitTenum(Tenum *p);
  void visitTname(Tname *p);
  void visitStorage_class_specifier(Storage_class_specifier *p); /* abstract class */
  void visitMyType(MyType *p);
  void visitGlobalPrograms(GlobalPrograms *p);
  void visitLocalProgram(LocalProgram *p);
  void visitLocalBlock(LocalBlock *p);
  void visitLocalReg(LocalReg *p);
  void visitType_qualifier(Type_qualifier *p); /* abstract class */
  void visitConst(Const *p);
  void visitNoOptim(NoOptim *p);
  void visitStruct_or_union_spec(Struct_or_union_spec *p); /* abstract class */
  void visitTag(Tag *p);
  void visitUnique(Unique *p);
  void visitTagType(TagType *p);
  void visitStruct_or_union(Struct_or_union *p); /* abstract class */
  void visitStruct(Struct *p);
  void visitUnion(Union *p);
  void visitListStruct_dec(ListStruct_dec* p);
  void visitStruct_dec(Struct_dec *p); /* abstract class */
  void visitStructen(Structen *p);
  void visitListSpec_qual(ListSpec_qual* p);
  void visitSpec_qual(Spec_qual *p); /* abstract class */
  void visitTypeSpec(TypeSpec *p);
  void visitQualSpec(QualSpec *p);
  void visitListStruct_declarator(ListStruct_declarator* p);
  void visitStruct_declarator(Struct_declarator *p); /* abstract class */
  void visitDecl(Decl *p);
  void visitField(Field *p);
  void visitDecField(DecField *p);
  void visitEnum_specifier(Enum_specifier *p); /* abstract class */
  void visitEnumDec(EnumDec *p);
  void visitEnumName(EnumName *p);
  void visitEnumVar(EnumVar *p);
  void visitListEnumerator(ListEnumerator* p);
  void visitEnumerator(Enumerator *p); /* abstract class */
  void visitPlain(Plain *p);
  void visitEnumInit(EnumInit *p);
  void visitDeclarator(Declarator *p); /* abstract class */
  void visitBeginPointer(BeginPointer *p);
  void visitNoPointer(NoPointer *p);
  void visitDirect_declarator(Direct_declarator *p); /* abstract class */
  void visitName(Name *p);
  void visitParenDecl(ParenDecl *p);
  void visitInnitArray(InnitArray *p);
  void visitIncomplete(Incomplete *p);
  void visitNewFuncDec(NewFuncDec *p);
  void visitOldFuncDef(OldFuncDef *p);
  void visitOldFuncDec(OldFuncDec *p);
  void visitPointer(Pointer *p); /* abstract class */
  void visitPoint(Point *p);
  void visitPointQual(PointQual *p);
  void visitPointPoint(PointPoint *p);
  void visitPointQualPoint(PointQualPoint *p);
  void visitListType_qualifier(ListType_qualifier* p);
  void visitParameter_type(Parameter_type *p); /* abstract class */
  void visitAllSpec(AllSpec *p);
  void visitMore(More *p);
  void visitParameter_declarations(Parameter_declarations *p); /* abstract class */
  void visitParamDec(ParamDec *p);
  void visitMoreParamDec(MoreParamDec *p);
  void visitParameter_declaration(Parameter_declaration *p); /* abstract class */
  void visitOnlyType(OnlyType *p);
  void visitTypeAndParam(TypeAndParam *p);
  void visitAbstract(Abstract *p);
  void visitListIdent(ListIdent* p);
  void visitInitializer(Initializer *p); /* abstract class */
  void visitInitExpr(InitExpr *p);
  void visitInitListOne(InitListOne *p);
  void visitInitListTwo(InitListTwo *p);
  void visitInitializers(Initializers *p); /* abstract class */
  void visitAnInit(AnInit *p);
  void visitMoreInit(MoreInit *p);
  void visitType_name(Type_name *p); /* abstract class */
  void visitPlainType(PlainType *p);
  void visitExtendedType(ExtendedType *p);
  void visitAbstract_declarator(Abstract_declarator *p); /* abstract class */
  void visitPointerStart(PointerStart *p);
  void visitAdvanced(Advanced *p);
  void visitPointAdvanced(PointAdvanced *p);
  void visitDir_abs_dec(Dir_abs_dec *p); /* abstract class */
  void visitWithinParentes(WithinParentes *p);
  void visitArray(Array *p);
  void visitInitiatedArray(InitiatedArray *p);
  void visitUnInitiated(UnInitiated *p);
  void visitInitiated(Initiated *p);
  void visitOldFunction(OldFunction *p);
  void visitNewFunction(NewFunction *p);
  void visitOldFuncExpr(OldFuncExpr *p);
  void visitNewFuncExpr(NewFuncExpr *p);
  void visitStm(Stm *p); /* abstract class */
  void visitLabelS(LabelS *p);
  void visitCompS(CompS *p);
  void visitExprS(ExprS *p);
  void visitSelS(SelS *p);
  void visitIterS(IterS *p);
  void visitJumpS(JumpS *p);
  void visitLabeled_stm(Labeled_stm *p); /* abstract class */
  void visitSlabelOne(SlabelOne *p);
  void visitSlabelTwo(SlabelTwo *p);
  void visitSlabelThree(SlabelThree *p);
  void visitCompound_stm(Compound_stm *p); /* abstract class */
  void visitScompOne(ScompOne *p);
  void visitScompTwo(ScompTwo *p);
  void visitScompThree(ScompThree *p);
  void visitScompFour(ScompFour *p);
  void visitExpression_stm(Expression_stm *p); /* abstract class */
  void visitSexprOne(SexprOne *p);
  void visitSexprTwo(SexprTwo *p);
  void visitSelection_stm(Selection_stm *p); /* abstract class */
  void visitSselOne(SselOne *p);
  void visitSselTwo(SselTwo *p);
  void visitSselThree(SselThree *p);
  void visitIter_stm(Iter_stm *p); /* abstract class */
  void visitSiterOne(SiterOne *p);
  void visitSiterTwo(SiterTwo *p);
  void visitSiterThree(SiterThree *p);
  void visitSiterFour(SiterFour *p);
  void visitJump_stm(Jump_stm *p); /* abstract class */
  void visitSjumpOne(SjumpOne *p);
  void visitSjumpTwo(SjumpTwo *p);
  void visitSjumpThree(SjumpThree *p);
  void visitSjumpFour(SjumpFour *p);
  void visitSjumpFive(SjumpFive *p);
  void visitListStm(ListStm* p);
  void visitExp(Exp *p); /* abstract class */
  void visitEcomma(Ecomma *p);
  void visitEassign(Eassign *p);
  void visitEcondition(Econdition *p);
  void visitElor(Elor *p);
  void visitEland(Eland *p);
  void visitEbitor(Ebitor *p);
  void visitEbitexor(Ebitexor *p);
  void visitEbitand(Ebitand *p);
  void visitEeq(Eeq *p);
  void visitEneq(Eneq *p);
  void visitElthen(Elthen *p);
  void visitEgrthen(Egrthen *p);
  void visitEle(Ele *p);
  void visitEge(Ege *p);
  void visitEleft(Eleft *p);
  void visitEright(Eright *p);
  void visitEplus(Eplus *p);
  void visitEminus(Eminus *p);
  void visitEtimes(Etimes *p);
  void visitEdiv(Ediv *p);
  void visitEmod(Emod *p);
  void visitEtypeconv(Etypeconv *p);
  void visitEpreinc(Epreinc *p);
  void visitEpredec(Epredec *p);
  void visitEpreop(Epreop *p);
  void visitEbytesexpr(Ebytesexpr *p);
  void visitEbytestype(Ebytestype *p);
  void visitEarray(Earray *p);
  void visitEfunk(Efunk *p);
  void visitEfunkpar(Efunkpar *p);
  void visitEselect(Eselect *p);
  void visitEpoint(Epoint *p);
  void visitEpostinc(Epostinc *p);
  void visitEpostdec(Epostdec *p);
  void visitEvar(Evar *p);
  void visitEconst(Econst *p);
  void visitEstring(Estring *p);
  void visitConstant(Constant *p); /* abstract class */
  void visitEfloat(Efloat *p);
  void visitEchar(Echar *p);
  void visitEunsigned(Eunsigned *p);
  void visitElong(Elong *p);
  void visitEunsignlong(Eunsignlong *p);
  void visitEhexadec(Ehexadec *p);
  void visitEhexaunsign(Ehexaunsign *p);
  void visitEhexalong(Ehexalong *p);
  void visitEhexaunslong(Ehexaunslong *p);
  void visitEoctal(Eoctal *p);
  void visitEoctalunsign(Eoctalunsign *p);
  void visitEoctallong(Eoctallong *p);
  void visitEoctalunslong(Eoctalunslong *p);
  void visitEcdouble(Ecdouble *p);
  void visitEcfloat(Ecfloat *p);
  void visitEclongdouble(Eclongdouble *p);
  void visitEint(Eint *p);
  void visitElonger(Elonger *p);
  void visitEdouble(Edouble *p);
  void visitConstant_expression(Constant_expression *p); /* abstract class */
  void visitEspecial(Especial *p);
  void visitUnary_operator(Unary_operator *p); /* abstract class */
  void visitAddress(Address *p);
  void visitIndirection(Indirection *p);
  void visitPlus(Plus *p);
  void visitNegative(Negative *p);
  void visitComplement(Complement *p);
  void visitLogicalneg(Logicalneg *p);
  void visitListExp(ListExp* p);
  void visitAssignment_op(Assignment_op *p); /* abstract class */
  void visitAssign(Assign *p);
  void visitAssignMul(AssignMul *p);
  void visitAssignDiv(AssignDiv *p);
  void visitAssignMod(AssignMod *p);
  void visitAssignAdd(AssignAdd *p);
  void visitAssignSub(AssignSub *p);
  void visitAssignLeft(AssignLeft *p);
  void visitAssignRight(AssignRight *p);
  void visitAssignAnd(AssignAnd *p);
  void visitAssignXor(AssignXor *p);
  void visitAssignOr(AssignOr *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
  void visitUnsigned(String s);
  void visitLong(String s);
  void visitUnsignedLong(String s);
  void visitHexadecimal(String s);
  void visitHexUnsigned(String s);
  void visitHexLong(String s);
  void visitHexUnsLong(String s);
  void visitOctal(String s);
  void visitOctalUnsigned(String s);
  void visitOctalLong(String s);
  void visitOctalUnsLong(String s);
  void visitCDouble(String s);
  void visitCFloat(String s);
  void visitCLongDouble(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char* show(Visitable* v);

  void visitProgram(Program *p); /* abstract class */
  void visitProgr(Progr *p);
  void visitListExternal_declaration(ListExternal_declaration* p);
  void visitExternal_declaration(External_declaration *p); /* abstract class */
  void visitAfunc(Afunc *p);
  void visitGlobal(Global *p);
  void visitFunction_def(Function_def *p); /* abstract class */
  void visitOldFunc(OldFunc *p);
  void visitNewFunc(NewFunc *p);
  void visitOldFuncInt(OldFuncInt *p);
  void visitNewFuncInt(NewFuncInt *p);
  void visitDec(Dec *p); /* abstract class */
  void visitNoDeclarator(NoDeclarator *p);
  void visitDeclarators(Declarators *p);
  void visitListDec(ListDec* p);
  void visitListDeclaration_specifier(ListDeclaration_specifier* p);
  void visitDeclaration_specifier(Declaration_specifier *p); /* abstract class */
  void visitType(Type *p);
  void visitStorage(Storage *p);
  void visitSpecProp(SpecProp *p);
  void visitListInit_declarator(ListInit_declarator* p);
  void visitInit_declarator(Init_declarator *p); /* abstract class */
  void visitOnlyDecl(OnlyDecl *p);
  void visitInitDecl(InitDecl *p);
  void visitType_specifier(Type_specifier *p); /* abstract class */
  void visitTvoid(Tvoid *p);
  void visitTchar(Tchar *p);
  void visitTshort(Tshort *p);
  void visitTint(Tint *p);
  void visitTlong(Tlong *p);
  void visitTfloat(Tfloat *p);
  void visitTdouble(Tdouble *p);
  void visitTsigned(Tsigned *p);
  void visitTunsigned(Tunsigned *p);
  void visitTstruct(Tstruct *p);
  void visitTenum(Tenum *p);
  void visitTname(Tname *p);
  void visitStorage_class_specifier(Storage_class_specifier *p); /* abstract class */
  void visitMyType(MyType *p);
  void visitGlobalPrograms(GlobalPrograms *p);
  void visitLocalProgram(LocalProgram *p);
  void visitLocalBlock(LocalBlock *p);
  void visitLocalReg(LocalReg *p);
  void visitType_qualifier(Type_qualifier *p); /* abstract class */
  void visitConst(Const *p);
  void visitNoOptim(NoOptim *p);
  void visitStruct_or_union_spec(Struct_or_union_spec *p); /* abstract class */
  void visitTag(Tag *p);
  void visitUnique(Unique *p);
  void visitTagType(TagType *p);
  void visitStruct_or_union(Struct_or_union *p); /* abstract class */
  void visitStruct(Struct *p);
  void visitUnion(Union *p);
  void visitListStruct_dec(ListStruct_dec* p);
  void visitStruct_dec(Struct_dec *p); /* abstract class */
  void visitStructen(Structen *p);
  void visitListSpec_qual(ListSpec_qual* p);
  void visitSpec_qual(Spec_qual *p); /* abstract class */
  void visitTypeSpec(TypeSpec *p);
  void visitQualSpec(QualSpec *p);
  void visitListStruct_declarator(ListStruct_declarator* p);
  void visitStruct_declarator(Struct_declarator *p); /* abstract class */
  void visitDecl(Decl *p);
  void visitField(Field *p);
  void visitDecField(DecField *p);
  void visitEnum_specifier(Enum_specifier *p); /* abstract class */
  void visitEnumDec(EnumDec *p);
  void visitEnumName(EnumName *p);
  void visitEnumVar(EnumVar *p);
  void visitListEnumerator(ListEnumerator* p);
  void visitEnumerator(Enumerator *p); /* abstract class */
  void visitPlain(Plain *p);
  void visitEnumInit(EnumInit *p);
  void visitDeclarator(Declarator *p); /* abstract class */
  void visitBeginPointer(BeginPointer *p);
  void visitNoPointer(NoPointer *p);
  void visitDirect_declarator(Direct_declarator *p); /* abstract class */
  void visitName(Name *p);
  void visitParenDecl(ParenDecl *p);
  void visitInnitArray(InnitArray *p);
  void visitIncomplete(Incomplete *p);
  void visitNewFuncDec(NewFuncDec *p);
  void visitOldFuncDef(OldFuncDef *p);
  void visitOldFuncDec(OldFuncDec *p);
  void visitPointer(Pointer *p); /* abstract class */
  void visitPoint(Point *p);
  void visitPointQual(PointQual *p);
  void visitPointPoint(PointPoint *p);
  void visitPointQualPoint(PointQualPoint *p);
  void visitListType_qualifier(ListType_qualifier* p);
  void visitParameter_type(Parameter_type *p); /* abstract class */
  void visitAllSpec(AllSpec *p);
  void visitMore(More *p);
  void visitParameter_declarations(Parameter_declarations *p); /* abstract class */
  void visitParamDec(ParamDec *p);
  void visitMoreParamDec(MoreParamDec *p);
  void visitParameter_declaration(Parameter_declaration *p); /* abstract class */
  void visitOnlyType(OnlyType *p);
  void visitTypeAndParam(TypeAndParam *p);
  void visitAbstract(Abstract *p);
  void visitListIdent(ListIdent* p);
  void visitInitializer(Initializer *p); /* abstract class */
  void visitInitExpr(InitExpr *p);
  void visitInitListOne(InitListOne *p);
  void visitInitListTwo(InitListTwo *p);
  void visitInitializers(Initializers *p); /* abstract class */
  void visitAnInit(AnInit *p);
  void visitMoreInit(MoreInit *p);
  void visitType_name(Type_name *p); /* abstract class */
  void visitPlainType(PlainType *p);
  void visitExtendedType(ExtendedType *p);
  void visitAbstract_declarator(Abstract_declarator *p); /* abstract class */
  void visitPointerStart(PointerStart *p);
  void visitAdvanced(Advanced *p);
  void visitPointAdvanced(PointAdvanced *p);
  void visitDir_abs_dec(Dir_abs_dec *p); /* abstract class */
  void visitWithinParentes(WithinParentes *p);
  void visitArray(Array *p);
  void visitInitiatedArray(InitiatedArray *p);
  void visitUnInitiated(UnInitiated *p);
  void visitInitiated(Initiated *p);
  void visitOldFunction(OldFunction *p);
  void visitNewFunction(NewFunction *p);
  void visitOldFuncExpr(OldFuncExpr *p);
  void visitNewFuncExpr(NewFuncExpr *p);
  void visitStm(Stm *p); /* abstract class */
  void visitLabelS(LabelS *p);
  void visitCompS(CompS *p);
  void visitExprS(ExprS *p);
  void visitSelS(SelS *p);
  void visitIterS(IterS *p);
  void visitJumpS(JumpS *p);
  void visitLabeled_stm(Labeled_stm *p); /* abstract class */
  void visitSlabelOne(SlabelOne *p);
  void visitSlabelTwo(SlabelTwo *p);
  void visitSlabelThree(SlabelThree *p);
  void visitCompound_stm(Compound_stm *p); /* abstract class */
  void visitScompOne(ScompOne *p);
  void visitScompTwo(ScompTwo *p);
  void visitScompThree(ScompThree *p);
  void visitScompFour(ScompFour *p);
  void visitExpression_stm(Expression_stm *p); /* abstract class */
  void visitSexprOne(SexprOne *p);
  void visitSexprTwo(SexprTwo *p);
  void visitSelection_stm(Selection_stm *p); /* abstract class */
  void visitSselOne(SselOne *p);
  void visitSselTwo(SselTwo *p);
  void visitSselThree(SselThree *p);
  void visitIter_stm(Iter_stm *p); /* abstract class */
  void visitSiterOne(SiterOne *p);
  void visitSiterTwo(SiterTwo *p);
  void visitSiterThree(SiterThree *p);
  void visitSiterFour(SiterFour *p);
  void visitJump_stm(Jump_stm *p); /* abstract class */
  void visitSjumpOne(SjumpOne *p);
  void visitSjumpTwo(SjumpTwo *p);
  void visitSjumpThree(SjumpThree *p);
  void visitSjumpFour(SjumpFour *p);
  void visitSjumpFive(SjumpFive *p);
  void visitListStm(ListStm* p);
  void visitExp(Exp *p); /* abstract class */
  void visitEcomma(Ecomma *p);
  void visitEassign(Eassign *p);
  void visitEcondition(Econdition *p);
  void visitElor(Elor *p);
  void visitEland(Eland *p);
  void visitEbitor(Ebitor *p);
  void visitEbitexor(Ebitexor *p);
  void visitEbitand(Ebitand *p);
  void visitEeq(Eeq *p);
  void visitEneq(Eneq *p);
  void visitElthen(Elthen *p);
  void visitEgrthen(Egrthen *p);
  void visitEle(Ele *p);
  void visitEge(Ege *p);
  void visitEleft(Eleft *p);
  void visitEright(Eright *p);
  void visitEplus(Eplus *p);
  void visitEminus(Eminus *p);
  void visitEtimes(Etimes *p);
  void visitEdiv(Ediv *p);
  void visitEmod(Emod *p);
  void visitEtypeconv(Etypeconv *p);
  void visitEpreinc(Epreinc *p);
  void visitEpredec(Epredec *p);
  void visitEpreop(Epreop *p);
  void visitEbytesexpr(Ebytesexpr *p);
  void visitEbytestype(Ebytestype *p);
  void visitEarray(Earray *p);
  void visitEfunk(Efunk *p);
  void visitEfunkpar(Efunkpar *p);
  void visitEselect(Eselect *p);
  void visitEpoint(Epoint *p);
  void visitEpostinc(Epostinc *p);
  void visitEpostdec(Epostdec *p);
  void visitEvar(Evar *p);
  void visitEconst(Econst *p);
  void visitEstring(Estring *p);
  void visitConstant(Constant *p); /* abstract class */
  void visitEfloat(Efloat *p);
  void visitEchar(Echar *p);
  void visitEunsigned(Eunsigned *p);
  void visitElong(Elong *p);
  void visitEunsignlong(Eunsignlong *p);
  void visitEhexadec(Ehexadec *p);
  void visitEhexaunsign(Ehexaunsign *p);
  void visitEhexalong(Ehexalong *p);
  void visitEhexaunslong(Ehexaunslong *p);
  void visitEoctal(Eoctal *p);
  void visitEoctalunsign(Eoctalunsign *p);
  void visitEoctallong(Eoctallong *p);
  void visitEoctalunslong(Eoctalunslong *p);
  void visitEcdouble(Ecdouble *p);
  void visitEcfloat(Ecfloat *p);
  void visitEclongdouble(Eclongdouble *p);
  void visitEint(Eint *p);
  void visitElonger(Elonger *p);
  void visitEdouble(Edouble *p);
  void visitConstant_expression(Constant_expression *p); /* abstract class */
  void visitEspecial(Especial *p);
  void visitUnary_operator(Unary_operator *p); /* abstract class */
  void visitAddress(Address *p);
  void visitIndirection(Indirection *p);
  void visitPlus(Plus *p);
  void visitNegative(Negative *p);
  void visitComplement(Complement *p);
  void visitLogicalneg(Logicalneg *p);
  void visitListExp(ListExp* p);
  void visitAssignment_op(Assignment_op *p); /* abstract class */
  void visitAssign(Assign *p);
  void visitAssignMul(AssignMul *p);
  void visitAssignDiv(AssignDiv *p);
  void visitAssignMod(AssignMod *p);
  void visitAssignAdd(AssignAdd *p);
  void visitAssignSub(AssignSub *p);
  void visitAssignLeft(AssignLeft *p);
  void visitAssignRight(AssignRight *p);
  void visitAssignAnd(AssignAnd *p);
  void visitAssignXor(AssignXor *p);
  void visitAssignOr(AssignOr *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
  void visitUnsigned(String s);
  void visitLong(String s);
  void visitUnsignedLong(String s);
  void visitHexadecimal(String s);
  void visitHexUnsigned(String s);
  void visitHexLong(String s);
  void visitHexUnsLong(String s);
  void visitOctal(String s);
  void visitOctalUnsigned(String s);
  void visitOctalLong(String s);
  void visitOctalUnsLong(String s);
  void visitCDouble(String s);
  void visitCFloat(String s);
  void visitCLongDouble(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};




#endif

