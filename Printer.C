/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include <string>
#include "Printer.H"


//You may wish to change render
void PrintAbsyn::render(Char c)
{
  if (c == '{')
  {
     bufAppend('\n');
     indent();
     bufAppend(c);
     _n_ = _n_ + 2;
     bufAppend('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppend(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == '}')
  {
     _n_ = _n_ - 2;
     backup();
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppend(c);
     bufAppend(' ');
  }
}
void PrintAbsyn::render(String s_)
{
  const char *s = s_.c_str() ;
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::indent()
{
  int n = _n_;
  while (n > 0)
  {
    bufAppend(' ');
    n--;
  }
}
void PrintAbsyn::backup()
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
PrintAbsyn::PrintAbsyn(void)
{
  _i_ = 0; _n_ = 0;
  buf_ = 0;
  bufReset();
}

PrintAbsyn::~PrintAbsyn(void)
{
}

char* PrintAbsyn::print(Visitable *v)
{
  _i_ = 0; _n_ = 0;
  bufReset();
  v->accept(this);
  return buf_;
}
void PrintAbsyn::visitProgram(Program*p) {} //abstract class

void PrintAbsyn::visitProgr(Progr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listexternal_declaration_) {_i_ = 0; p->listexternal_declaration_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListExternal_declaration(ListExternal_declaration *listexternal_declaration)
{
  for (ListExternal_declaration::const_iterator i = listexternal_declaration->begin() ; i != listexternal_declaration->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexternal_declaration->end() - 1) render("");
  }
}

void PrintAbsyn::visitExternal_declaration(External_declaration*p) {} //abstract class

void PrintAbsyn::visitAfunc(Afunc* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->function_def_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitGlobal(Global* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->dec_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitFunction_def(Function_def*p) {} //abstract class

void PrintAbsyn::visitOldFunc(OldFunc* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listdeclaration_specifier_) {_i_ = 0; p->listdeclaration_specifier_->accept(this);}  _i_ = 0; p->declarator_->accept(this);
  if(p->listdec_) {_i_ = 0; p->listdec_->accept(this);}  _i_ = 0; p->compound_stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNewFunc(NewFunc* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listdeclaration_specifier_) {_i_ = 0; p->listdeclaration_specifier_->accept(this);}  _i_ = 0; p->declarator_->accept(this);
  _i_ = 0; p->compound_stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOldFuncInt(OldFuncInt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->declarator_->accept(this);
  if(p->listdec_) {_i_ = 0; p->listdec_->accept(this);}  _i_ = 0; p->compound_stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNewFuncInt(NewFuncInt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->declarator_->accept(this);
  _i_ = 0; p->compound_stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDec(Dec*p) {} //abstract class

void PrintAbsyn::visitNoDeclarator(NoDeclarator* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listdeclaration_specifier_) {_i_ = 0; p->listdeclaration_specifier_->accept(this);}  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDeclarators(Declarators* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listdeclaration_specifier_) {_i_ = 0; p->listdeclaration_specifier_->accept(this);}  if(p->listinit_declarator_) {_i_ = 0; p->listinit_declarator_->accept(this);}  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListDec(ListDec *listdec)
{
  for (ListDec::const_iterator i = listdec->begin() ; i != listdec->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdec->end() - 1) render("");
  }
}

void PrintAbsyn::visitListDeclaration_specifier(ListDeclaration_specifier *listdeclaration_specifier)
{
  for (ListDeclaration_specifier::const_iterator i = listdeclaration_specifier->begin() ; i != listdeclaration_specifier->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdeclaration_specifier->end() - 1) render("");
  }
}

void PrintAbsyn::visitDeclaration_specifier(Declaration_specifier*p) {} //abstract class

void PrintAbsyn::visitType(Type* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_specifier_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStorage(Storage* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->storage_class_specifier_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSpecProp(SpecProp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_qualifier_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListInit_declarator(ListInit_declarator *listinit_declarator)
{
  for (ListInit_declarator::const_iterator i = listinit_declarator->begin() ; i != listinit_declarator->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listinit_declarator->end() - 1) render(',');
  }
}

void PrintAbsyn::visitInit_declarator(Init_declarator*p) {} //abstract class

void PrintAbsyn::visitOnlyDecl(OnlyDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->declarator_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInitDecl(InitDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->declarator_->accept(this);
  render('=');
  _i_ = 0; p->initializer_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitType_specifier(Type_specifier*p) {} //abstract class

void PrintAbsyn::visitTvoid(Tvoid* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("void");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTchar(Tchar* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("char");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTshort(Tshort* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("short");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTint(Tint* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("int");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTlong(Tlong* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("long");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTfloat(Tfloat* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("float");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTdouble(Tdouble* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("double");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTsigned(Tsigned* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("signed");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTunsigned(Tunsigned* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("unsigned");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTstruct(Tstruct* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->struct_or_union_spec_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTenum(Tenum* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->enum_specifier_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTname(Tname* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Typedef_name");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStorage_class_specifier(Storage_class_specifier*p) {} //abstract class

void PrintAbsyn::visitMyType(MyType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("typedef");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitGlobalPrograms(GlobalPrograms* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("extern");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLocalProgram(LocalProgram* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("static");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLocalBlock(LocalBlock* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("auto");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLocalReg(LocalReg* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("register");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitType_qualifier(Type_qualifier*p) {} //abstract class

void PrintAbsyn::visitConst(Const* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("const");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNoOptim(NoOptim* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("volatile");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStruct_or_union_spec(Struct_or_union_spec*p) {} //abstract class

void PrintAbsyn::visitTag(Tag* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->struct_or_union_->accept(this);
  visitIdent(p->ident_);
  render('{');
  if(p->liststruct_dec_) {_i_ = 0; p->liststruct_dec_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitUnique(Unique* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->struct_or_union_->accept(this);
  render('{');
  if(p->liststruct_dec_) {_i_ = 0; p->liststruct_dec_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTagType(TagType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->struct_or_union_->accept(this);
  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStruct_or_union(Struct_or_union*p) {} //abstract class

void PrintAbsyn::visitStruct(Struct* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("struct");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitUnion(Union* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("union");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListStruct_dec(ListStruct_dec *liststruct_dec)
{
  for (ListStruct_dec::const_iterator i = liststruct_dec->begin() ; i != liststruct_dec->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststruct_dec->end() - 1) render("");
  }
}

void PrintAbsyn::visitStruct_dec(Struct_dec*p) {} //abstract class

void PrintAbsyn::visitStructen(Structen* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listspec_qual_) {_i_ = 0; p->listspec_qual_->accept(this);}  if(p->liststruct_declarator_) {_i_ = 0; p->liststruct_declarator_->accept(this);}  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListSpec_qual(ListSpec_qual *listspec_qual)
{
  for (ListSpec_qual::const_iterator i = listspec_qual->begin() ; i != listspec_qual->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listspec_qual->end() - 1) render("");
  }
}

void PrintAbsyn::visitSpec_qual(Spec_qual*p) {} //abstract class

void PrintAbsyn::visitTypeSpec(TypeSpec* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_specifier_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitQualSpec(QualSpec* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_qualifier_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListStruct_declarator(ListStruct_declarator *liststruct_declarator)
{
  for (ListStruct_declarator::const_iterator i = liststruct_declarator->begin() ; i != liststruct_declarator->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststruct_declarator->end() - 1) render(',');
  }
}

void PrintAbsyn::visitStruct_declarator(Struct_declarator*p) {} //abstract class

void PrintAbsyn::visitDecl(Decl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->declarator_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitField(Field* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render(':');
  _i_ = 0; p->constant_expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDecField(DecField* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->declarator_->accept(this);
  render(':');
  _i_ = 0; p->constant_expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEnum_specifier(Enum_specifier*p) {} //abstract class

void PrintAbsyn::visitEnumDec(EnumDec* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("enum");
  render('{');
  if(p->listenumerator_) {_i_ = 0; p->listenumerator_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEnumName(EnumName* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("enum");
  visitIdent(p->ident_);
  render('{');
  if(p->listenumerator_) {_i_ = 0; p->listenumerator_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEnumVar(EnumVar* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("enum");
  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListEnumerator(ListEnumerator *listenumerator)
{
  for (ListEnumerator::const_iterator i = listenumerator->begin() ; i != listenumerator->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listenumerator->end() - 1) render(',');
  }
}

void PrintAbsyn::visitEnumerator(Enumerator*p) {} //abstract class

void PrintAbsyn::visitPlain(Plain* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEnumInit(EnumInit* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render('=');
  _i_ = 0; p->constant_expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDeclarator(Declarator*p) {} //abstract class

void PrintAbsyn::visitBeginPointer(BeginPointer* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->pointer_->accept(this);
  _i_ = 0; p->direct_declarator_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNoPointer(NoPointer* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->direct_declarator_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDirect_declarator(Direct_declarator*p) {} //abstract class

void PrintAbsyn::visitName(Name* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitParenDecl(ParenDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('(');
  _i_ = 0; p->declarator_->accept(this);
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInnitArray(InnitArray* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->direct_declarator_->accept(this);
  render('[');
  _i_ = 0; p->constant_expression_->accept(this);
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitIncomplete(Incomplete* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->direct_declarator_->accept(this);
  render('[');
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNewFuncDec(NewFuncDec* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->direct_declarator_->accept(this);
  render('(');
  _i_ = 0; p->parameter_type_->accept(this);
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOldFuncDef(OldFuncDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->direct_declarator_->accept(this);
  render('(');
  if(p->listident_) {_i_ = 0; p->listident_->accept(this);}  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOldFuncDec(OldFuncDec* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->direct_declarator_->accept(this);
  render('(');
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPointer(Pointer*p) {} //abstract class

void PrintAbsyn::visitPoint(Point* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('*');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPointQual(PointQual* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('*');
  if(p->listtype_qualifier_) {_i_ = 0; p->listtype_qualifier_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPointPoint(PointPoint* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('*');
  _i_ = 0; p->pointer_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPointQualPoint(PointQualPoint* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('*');
  if(p->listtype_qualifier_) {_i_ = 0; p->listtype_qualifier_->accept(this);}  _i_ = 0; p->pointer_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListType_qualifier(ListType_qualifier *listtype_qualifier)
{
  for (ListType_qualifier::const_iterator i = listtype_qualifier->begin() ; i != listtype_qualifier->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listtype_qualifier->end() - 1) render("");
  }
}

void PrintAbsyn::visitParameter_type(Parameter_type*p) {} //abstract class

void PrintAbsyn::visitAllSpec(AllSpec* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->parameter_declarations_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitMore(More* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->parameter_declarations_->accept(this);
  render(',');
  render("...");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitParameter_declarations(Parameter_declarations*p) {} //abstract class

void PrintAbsyn::visitParamDec(ParamDec* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->parameter_declaration_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitMoreParamDec(MoreParamDec* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->parameter_declarations_->accept(this);
  render(',');
  _i_ = 0; p->parameter_declaration_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitParameter_declaration(Parameter_declaration*p) {} //abstract class

void PrintAbsyn::visitOnlyType(OnlyType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listdeclaration_specifier_) {_i_ = 0; p->listdeclaration_specifier_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTypeAndParam(TypeAndParam* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listdeclaration_specifier_) {_i_ = 0; p->listdeclaration_specifier_->accept(this);}  _i_ = 0; p->declarator_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAbstract(Abstract* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listdeclaration_specifier_) {_i_ = 0; p->listdeclaration_specifier_->accept(this);}  _i_ = 0; p->abstract_declarator_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListIdent(ListIdent *listident)
{
  for (ListIdent::const_iterator i = listident->begin() ; i != listident->end() ; ++i)
  {
    visitIdent(*i) ;
    if (i != listident->end() - 1) render(',');
  }
}

void PrintAbsyn::visitInitializer(Initializer*p) {} //abstract class

void PrintAbsyn::visitInitExpr(InitExpr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 2; p->exp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInitListOne(InitListOne* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  _i_ = 0; p->initializers_->accept(this);
  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInitListTwo(InitListTwo* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  _i_ = 0; p->initializers_->accept(this);
  render(',');
  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInitializers(Initializers*p) {} //abstract class

void PrintAbsyn::visitAnInit(AnInit* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->initializer_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitMoreInit(MoreInit* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->initializers_->accept(this);
  render(',');
  _i_ = 0; p->initializer_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitType_name(Type_name*p) {} //abstract class

void PrintAbsyn::visitPlainType(PlainType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listspec_qual_) {_i_ = 0; p->listspec_qual_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExtendedType(ExtendedType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listspec_qual_) {_i_ = 0; p->listspec_qual_->accept(this);}  _i_ = 0; p->abstract_declarator_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAbstract_declarator(Abstract_declarator*p) {} //abstract class

void PrintAbsyn::visitPointerStart(PointerStart* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->pointer_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAdvanced(Advanced* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->dir_abs_dec_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPointAdvanced(PointAdvanced* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->pointer_->accept(this);
  _i_ = 0; p->dir_abs_dec_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDir_abs_dec(Dir_abs_dec*p) {} //abstract class

void PrintAbsyn::visitWithinParentes(WithinParentes* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('(');
  _i_ = 0; p->abstract_declarator_->accept(this);
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitArray(Array* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('[');
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInitiatedArray(InitiatedArray* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('[');
  _i_ = 0; p->constant_expression_->accept(this);
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitUnInitiated(UnInitiated* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->dir_abs_dec_->accept(this);
  render('[');
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInitiated(Initiated* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->dir_abs_dec_->accept(this);
  render('[');
  _i_ = 0; p->constant_expression_->accept(this);
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOldFunction(OldFunction* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('(');
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNewFunction(NewFunction* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('(');
  _i_ = 0; p->parameter_type_->accept(this);
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOldFuncExpr(OldFuncExpr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->dir_abs_dec_->accept(this);
  render('(');
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNewFuncExpr(NewFuncExpr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->dir_abs_dec_->accept(this);
  render('(');
  _i_ = 0; p->parameter_type_->accept(this);
  render(')');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitStm(Stm*p) {} //abstract class

void PrintAbsyn::visitLabelS(LabelS* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->labeled_stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitCompS(CompS* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->compound_stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExprS(ExprS* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->expression_stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSelS(SelS* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->selection_stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitIterS(IterS* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->iter_stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitJumpS(JumpS* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->jump_stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLabeled_stm(Labeled_stm*p) {} //abstract class

void PrintAbsyn::visitSlabelOne(SlabelOne* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render(':');
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSlabelTwo(SlabelTwo* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("case");
  _i_ = 0; p->constant_expression_->accept(this);
  render(':');
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSlabelThree(SlabelThree* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("default");
  render(':');
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitCompound_stm(Compound_stm*p) {} //abstract class

void PrintAbsyn::visitScompOne(ScompOne* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitScompTwo(ScompTwo* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  if(p->liststm_) {_i_ = 0; p->liststm_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitScompThree(ScompThree* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  if(p->listdec_) {_i_ = 0; p->listdec_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitScompFour(ScompFour* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  if(p->listdec_) {_i_ = 0; p->listdec_->accept(this);}  if(p->liststm_) {_i_ = 0; p->liststm_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExpression_stm(Expression_stm*p) {} //abstract class

void PrintAbsyn::visitSexprOne(SexprOne* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSexprTwo(SexprTwo* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->exp_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSelection_stm(Selection_stm*p) {} //abstract class

void PrintAbsyn::visitSselOne(SselOne* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSselTwo(SselTwo* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->stm_1->accept(this);
  render("else");
  _i_ = 0; p->stm_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSselThree(SselThree* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("switch");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitIter_stm(Iter_stm*p) {} //abstract class

void PrintAbsyn::visitSiterOne(SiterOne* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("while");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSiterTwo(SiterTwo* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("do");
  _i_ = 0; p->stm_->accept(this);
  render("while");
  render('(');
  _i_ = 0; p->exp_->accept(this);
  render(')');
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSiterThree(SiterThree* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("for");
  render('(');
  _i_ = 0; p->expression_stm_1->accept(this);
  _i_ = 0; p->expression_stm_2->accept(this);
  render(')');
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSiterFour(SiterFour* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("for");
  render('(');
  _i_ = 0; p->expression_stm_1->accept(this);
  _i_ = 0; p->expression_stm_2->accept(this);
  _i_ = 0; p->exp_->accept(this);
  render(')');
  _i_ = 0; p->stm_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitJump_stm(Jump_stm*p) {} //abstract class

void PrintAbsyn::visitSjumpOne(SjumpOne* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("goto");
  visitIdent(p->ident_);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSjumpTwo(SjumpTwo* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("continue");
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSjumpThree(SjumpThree* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("break");
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSjumpFour(SjumpFour* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("return");
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSjumpFive(SjumpFive* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("return");
  _i_ = 0; p->exp_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListStm(ListStm *liststm)
{
  for (ListStm::const_iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststm->end() - 1) render("");
  }
}

void PrintAbsyn::visitExp(Exp*p) {} //abstract class

void PrintAbsyn::visitEcomma(Ecomma* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->exp_1->accept(this);
  render(',');
  _i_ = 2; p->exp_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEassign(Eassign* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 15; p->exp_1->accept(this);
  _i_ = 0; p->assignment_op_->accept(this);
  _i_ = 2; p->exp_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEcondition(Econdition* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 4; p->exp_1->accept(this);
  render('?');
  _i_ = 0; p->exp_2->accept(this);
  render(':');
  _i_ = 3; p->exp_3->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitElor(Elor* p)
{
  int oldi = _i_;
  if (oldi > 4) render(_L_PAREN);

  _i_ = 4; p->exp_1->accept(this);
  render("||");
  _i_ = 5; p->exp_2->accept(this);

  if (oldi > 4) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEland(Eland* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  _i_ = 5; p->exp_1->accept(this);
  render("&&");
  _i_ = 6; p->exp_2->accept(this);

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEbitor(Ebitor* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 6; p->exp_1->accept(this);
  render('|');
  _i_ = 7; p->exp_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEbitexor(Ebitexor* p)
{
  int oldi = _i_;
  if (oldi > 7) render(_L_PAREN);

  _i_ = 7; p->exp_1->accept(this);
  render('^');
  _i_ = 8; p->exp_2->accept(this);

  if (oldi > 7) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEbitand(Ebitand* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  _i_ = 8; p->exp_1->accept(this);
  render('&');
  _i_ = 9; p->exp_2->accept(this);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEeq(Eeq* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render("==");
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEneq(Eneq* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  _i_ = 9; p->exp_1->accept(this);
  render("!=");
  _i_ = 10; p->exp_2->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitElthen(Elthen* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  _i_ = 10; p->exp_1->accept(this);
  render('<');
  _i_ = 11; p->exp_2->accept(this);

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEgrthen(Egrthen* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  _i_ = 10; p->exp_1->accept(this);
  render('>');
  _i_ = 11; p->exp_2->accept(this);

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEle(Ele* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  _i_ = 10; p->exp_1->accept(this);
  render("<=");
  _i_ = 11; p->exp_2->accept(this);

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEge(Ege* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  _i_ = 10; p->exp_1->accept(this);
  render(">=");
  _i_ = 11; p->exp_2->accept(this);

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEleft(Eleft* p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  _i_ = 11; p->exp_1->accept(this);
  render("<<");
  _i_ = 12; p->exp_2->accept(this);

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEright(Eright* p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  _i_ = 11; p->exp_1->accept(this);
  render(">>");
  _i_ = 12; p->exp_2->accept(this);

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEplus(Eplus* p)
{
  int oldi = _i_;
  if (oldi > 12) render(_L_PAREN);

  _i_ = 12; p->exp_1->accept(this);
  render('+');
  _i_ = 13; p->exp_2->accept(this);

  if (oldi > 12) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEminus(Eminus* p)
{
  int oldi = _i_;
  if (oldi > 12) render(_L_PAREN);

  _i_ = 12; p->exp_1->accept(this);
  render('-');
  _i_ = 13; p->exp_2->accept(this);

  if (oldi > 12) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEtimes(Etimes* p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  _i_ = 13; p->exp_1->accept(this);
  render('*');
  _i_ = 14; p->exp_2->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEdiv(Ediv* p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  _i_ = 13; p->exp_1->accept(this);
  render('/');
  _i_ = 14; p->exp_2->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEmod(Emod* p)
{
  int oldi = _i_;
  if (oldi > 13) render(_L_PAREN);

  _i_ = 13; p->exp_1->accept(this);
  render('%');
  _i_ = 14; p->exp_2->accept(this);

  if (oldi > 13) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEtypeconv(Etypeconv* p)
{
  int oldi = _i_;
  if (oldi > 14) render(_L_PAREN);

  render('(');
  _i_ = 0; p->type_name_->accept(this);
  render(')');
  _i_ = 14; p->exp_->accept(this);

  if (oldi > 14) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEpreinc(Epreinc* p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  render("++");
  _i_ = 15; p->exp_->accept(this);

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEpredec(Epredec* p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  render("--");
  _i_ = 15; p->exp_->accept(this);

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEpreop(Epreop* p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  _i_ = 0; p->unary_operator_->accept(this);
  _i_ = 14; p->exp_->accept(this);

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEbytesexpr(Ebytesexpr* p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  render("sizeof");
  _i_ = 15; p->exp_->accept(this);

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEbytestype(Ebytestype* p)
{
  int oldi = _i_;
  if (oldi > 15) render(_L_PAREN);

  render("sizeof");
  render('(');
  _i_ = 0; p->type_name_->accept(this);
  render(')');

  if (oldi > 15) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEarray(Earray* p)
{
  int oldi = _i_;
  if (oldi > 16) render(_L_PAREN);

  _i_ = 16; p->exp_1->accept(this);
  render('[');
  _i_ = 0; p->exp_2->accept(this);
  render(']');

  if (oldi > 16) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEfunk(Efunk* p)
{
  int oldi = _i_;
  if (oldi > 16) render(_L_PAREN);

  _i_ = 16; p->exp_->accept(this);
  render('(');
  render(')');

  if (oldi > 16) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEfunkpar(Efunkpar* p)
{
  int oldi = _i_;
  if (oldi > 16) render(_L_PAREN);

  _i_ = 16; p->exp_->accept(this);
  render('(');
  if(p->listexp_) {_i_ = 2; p->listexp_->accept(this);}  render(')');

  if (oldi > 16) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEselect(Eselect* p)
{
  int oldi = _i_;
  if (oldi > 16) render(_L_PAREN);

  _i_ = 16; p->exp_->accept(this);
  render('.');
  visitIdent(p->ident_);

  if (oldi > 16) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEpoint(Epoint* p)
{
  int oldi = _i_;
  if (oldi > 16) render(_L_PAREN);

  _i_ = 16; p->exp_->accept(this);
  render("->");
  visitIdent(p->ident_);

  if (oldi > 16) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEpostinc(Epostinc* p)
{
  int oldi = _i_;
  if (oldi > 16) render(_L_PAREN);

  _i_ = 16; p->exp_->accept(this);
  render("++");

  if (oldi > 16) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEpostdec(Epostdec* p)
{
  int oldi = _i_;
  if (oldi > 16) render(_L_PAREN);

  _i_ = 16; p->exp_->accept(this);
  render("--");

  if (oldi > 16) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEvar(Evar* p)
{
  int oldi = _i_;
  if (oldi > 17) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 17) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEconst(Econst* p)
{
  int oldi = _i_;
  if (oldi > 17) render(_L_PAREN);

  _i_ = 0; p->constant_->accept(this);

  if (oldi > 17) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEstring(Estring* p)
{
  int oldi = _i_;
  if (oldi > 17) render(_L_PAREN);

  visitString(p->string_);

  if (oldi > 17) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitConstant(Constant*p) {} //abstract class

void PrintAbsyn::visitEfloat(Efloat* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitDouble(p->double_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEchar(Echar* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitChar(p->char_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEunsigned(Eunsigned* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->unsigned_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitElong(Elong* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->long_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEunsignlong(Eunsignlong* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->unsignedlong_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEhexadec(Ehexadec* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->hexadecimal_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEhexaunsign(Ehexaunsign* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->hexunsigned_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEhexalong(Ehexalong* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->hexlong_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEhexaunslong(Ehexaunslong* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->hexunslong_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEoctal(Eoctal* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->octal_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEoctalunsign(Eoctalunsign* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->octalunsigned_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEoctallong(Eoctallong* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->octallong_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEoctalunslong(Eoctalunslong* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->octalunslong_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEcdouble(Ecdouble* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->cdouble_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEcfloat(Ecfloat* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->cfloat_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEclongdouble(Eclongdouble* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->clongdouble_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEint(Eint* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitInteger(p->integer_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitElonger(Elonger* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  /* Internal Category */

  visitInteger(p->integer_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEdouble(Edouble* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  /* Internal Category */

  visitDouble(p->double_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitConstant_expression(Constant_expression*p) {} //abstract class

void PrintAbsyn::visitEspecial(Especial* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 3; p->exp_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitUnary_operator(Unary_operator*p) {} //abstract class

void PrintAbsyn::visitAddress(Address* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('&');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitIndirection(Indirection* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('*');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPlus(Plus* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('+');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNegative(Negative* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('-');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitComplement(Complement* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('~');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLogicalneg(Logicalneg* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('!');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListExp(ListExp *listexp)
{
  for (ListExp::const_iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexp->end() - 1) render(',');
  }
}

void PrintAbsyn::visitAssignment_op(Assignment_op*p) {} //abstract class

void PrintAbsyn::visitAssign(Assign* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('=');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignMul(AssignMul* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("*=");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignDiv(AssignDiv* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("/=");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignMod(AssignMod* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("%=");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignAdd(AssignAdd* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("+=");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignSub(AssignSub* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("-=");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignLeft(AssignLeft* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("<<=");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignRight(AssignRight* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render(">>=");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignAnd(AssignAnd* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("&=");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignXor(AssignXor* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("^=");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAssignOr(AssignOr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("|=");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void PrintAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void PrintAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void PrintAbsyn::visitString(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void PrintAbsyn::visitIdent(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}

void PrintAbsyn::visitUnsigned(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitLong(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitUnsignedLong(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitHexadecimal(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitHexUnsigned(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitHexLong(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitHexUnsLong(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitOctal(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitOctalUnsigned(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitOctalLong(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitOctalUnsLong(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitCDouble(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitCFloat(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


void PrintAbsyn::visitCLongDouble(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


ShowAbsyn::ShowAbsyn(void)
{
  buf_ = 0;
  bufReset();
}

ShowAbsyn::~ShowAbsyn(void)
{
}

char* ShowAbsyn::show(Visitable *v)
{
  bufReset();
  v->accept(this);
  return buf_;
}
void ShowAbsyn::visitProgram(Program* p) {} //abstract class

void ShowAbsyn::visitProgr(Progr* p)
{
  bufAppend('(');
  bufAppend("Progr");
  bufAppend(' ');
  bufAppend('[');
  if (p->listexternal_declaration_)  p->listexternal_declaration_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListExternal_declaration(ListExternal_declaration *listexternal_declaration)
{
  for (ListExternal_declaration::const_iterator i = listexternal_declaration->begin() ; i != listexternal_declaration->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexternal_declaration->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitExternal_declaration(External_declaration* p) {} //abstract class

void ShowAbsyn::visitAfunc(Afunc* p)
{
  bufAppend('(');
  bufAppend("Afunc");
  bufAppend(' ');
  bufAppend('[');
  if (p->function_def_)  p->function_def_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitGlobal(Global* p)
{
  bufAppend('(');
  bufAppend("Global");
  bufAppend(' ');
  bufAppend('[');
  if (p->dec_)  p->dec_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitFunction_def(Function_def* p) {} //abstract class

void ShowAbsyn::visitOldFunc(OldFunc* p)
{
  bufAppend('(');
  bufAppend("OldFunc");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdeclaration_specifier_)  p->listdeclaration_specifier_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->declarator_)  p->declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listdec_)  p->listdec_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->compound_stm_)  p->compound_stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitNewFunc(NewFunc* p)
{
  bufAppend('(');
  bufAppend("NewFunc");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdeclaration_specifier_)  p->listdeclaration_specifier_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->declarator_)  p->declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->compound_stm_)  p->compound_stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOldFuncInt(OldFuncInt* p)
{
  bufAppend('(');
  bufAppend("OldFuncInt");
  bufAppend(' ');
  bufAppend('[');
  if (p->declarator_)  p->declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listdec_)  p->listdec_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->compound_stm_)  p->compound_stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitNewFuncInt(NewFuncInt* p)
{
  bufAppend('(');
  bufAppend("NewFuncInt");
  bufAppend(' ');
  bufAppend('[');
  if (p->declarator_)  p->declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->compound_stm_)  p->compound_stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitDec(Dec* p) {} //abstract class

void ShowAbsyn::visitNoDeclarator(NoDeclarator* p)
{
  bufAppend('(');
  bufAppend("NoDeclarator");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdeclaration_specifier_)  p->listdeclaration_specifier_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDeclarators(Declarators* p)
{
  bufAppend('(');
  bufAppend("Declarators");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdeclaration_specifier_)  p->listdeclaration_specifier_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listinit_declarator_)  p->listinit_declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListDec(ListDec *listdec)
{
  for (ListDec::const_iterator i = listdec->begin() ; i != listdec->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdec->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitListDeclaration_specifier(ListDeclaration_specifier *listdeclaration_specifier)
{
  for (ListDeclaration_specifier::const_iterator i = listdeclaration_specifier->begin() ; i != listdeclaration_specifier->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdeclaration_specifier->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitDeclaration_specifier(Declaration_specifier* p) {} //abstract class

void ShowAbsyn::visitType(Type* p)
{
  bufAppend('(');
  bufAppend("Type");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_specifier_)  p->type_specifier_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitStorage(Storage* p)
{
  bufAppend('(');
  bufAppend("Storage");
  bufAppend(' ');
  bufAppend('[');
  if (p->storage_class_specifier_)  p->storage_class_specifier_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSpecProp(SpecProp* p)
{
  bufAppend('(');
  bufAppend("SpecProp");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_qualifier_)  p->type_qualifier_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListInit_declarator(ListInit_declarator *listinit_declarator)
{
  for (ListInit_declarator::const_iterator i = listinit_declarator->begin() ; i != listinit_declarator->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listinit_declarator->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitInit_declarator(Init_declarator* p) {} //abstract class

void ShowAbsyn::visitOnlyDecl(OnlyDecl* p)
{
  bufAppend('(');
  bufAppend("OnlyDecl");
  bufAppend(' ');
  bufAppend('[');
  if (p->declarator_)  p->declarator_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitInitDecl(InitDecl* p)
{
  bufAppend('(');
  bufAppend("InitDecl");
  bufAppend(' ');
  bufAppend('[');
  if (p->declarator_)  p->declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->initializer_)  p->initializer_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitType_specifier(Type_specifier* p) {} //abstract class

void ShowAbsyn::visitTvoid(Tvoid* p)
{
  bufAppend("Tvoid");
}
void ShowAbsyn::visitTchar(Tchar* p)
{
  bufAppend("Tchar");
}
void ShowAbsyn::visitTshort(Tshort* p)
{
  bufAppend("Tshort");
}
void ShowAbsyn::visitTint(Tint* p)
{
  bufAppend("Tint");
}
void ShowAbsyn::visitTlong(Tlong* p)
{
  bufAppend("Tlong");
}
void ShowAbsyn::visitTfloat(Tfloat* p)
{
  bufAppend("Tfloat");
}
void ShowAbsyn::visitTdouble(Tdouble* p)
{
  bufAppend("Tdouble");
}
void ShowAbsyn::visitTsigned(Tsigned* p)
{
  bufAppend("Tsigned");
}
void ShowAbsyn::visitTunsigned(Tunsigned* p)
{
  bufAppend("Tunsigned");
}
void ShowAbsyn::visitTstruct(Tstruct* p)
{
  bufAppend('(');
  bufAppend("Tstruct");
  bufAppend(' ');
  bufAppend('[');
  if (p->struct_or_union_spec_)  p->struct_or_union_spec_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitTenum(Tenum* p)
{
  bufAppend('(');
  bufAppend("Tenum");
  bufAppend(' ');
  bufAppend('[');
  if (p->enum_specifier_)  p->enum_specifier_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitTname(Tname* p)
{
  bufAppend("Tname");
}
void ShowAbsyn::visitStorage_class_specifier(Storage_class_specifier* p) {} //abstract class

void ShowAbsyn::visitMyType(MyType* p)
{
  bufAppend("MyType");
}
void ShowAbsyn::visitGlobalPrograms(GlobalPrograms* p)
{
  bufAppend("GlobalPrograms");
}
void ShowAbsyn::visitLocalProgram(LocalProgram* p)
{
  bufAppend("LocalProgram");
}
void ShowAbsyn::visitLocalBlock(LocalBlock* p)
{
  bufAppend("LocalBlock");
}
void ShowAbsyn::visitLocalReg(LocalReg* p)
{
  bufAppend("LocalReg");
}
void ShowAbsyn::visitType_qualifier(Type_qualifier* p) {} //abstract class

void ShowAbsyn::visitConst(Const* p)
{
  bufAppend("Const");
}
void ShowAbsyn::visitNoOptim(NoOptim* p)
{
  bufAppend("NoOptim");
}
void ShowAbsyn::visitStruct_or_union_spec(Struct_or_union_spec* p) {} //abstract class

void ShowAbsyn::visitTag(Tag* p)
{
  bufAppend('(');
  bufAppend("Tag");
  bufAppend(' ');
  bufAppend('[');
  if (p->struct_or_union_)  p->struct_or_union_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->liststruct_dec_)  p->liststruct_dec_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitUnique(Unique* p)
{
  bufAppend('(');
  bufAppend("Unique");
  bufAppend(' ');
  bufAppend('[');
  if (p->struct_or_union_)  p->struct_or_union_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->liststruct_dec_)  p->liststruct_dec_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitTagType(TagType* p)
{
  bufAppend('(');
  bufAppend("TagType");
  bufAppend(' ');
  bufAppend('[');
  if (p->struct_or_union_)  p->struct_or_union_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitStruct_or_union(Struct_or_union* p) {} //abstract class

void ShowAbsyn::visitStruct(Struct* p)
{
  bufAppend("Struct");
}
void ShowAbsyn::visitUnion(Union* p)
{
  bufAppend("Union");
}
void ShowAbsyn::visitListStruct_dec(ListStruct_dec *liststruct_dec)
{
  for (ListStruct_dec::const_iterator i = liststruct_dec->begin() ; i != liststruct_dec->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststruct_dec->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitStruct_dec(Struct_dec* p) {} //abstract class

void ShowAbsyn::visitStructen(Structen* p)
{
  bufAppend('(');
  bufAppend("Structen");
  bufAppend(' ');
  bufAppend('[');
  if (p->listspec_qual_)  p->listspec_qual_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->liststruct_declarator_)  p->liststruct_declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListSpec_qual(ListSpec_qual *listspec_qual)
{
  for (ListSpec_qual::const_iterator i = listspec_qual->begin() ; i != listspec_qual->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listspec_qual->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitSpec_qual(Spec_qual* p) {} //abstract class

void ShowAbsyn::visitTypeSpec(TypeSpec* p)
{
  bufAppend('(');
  bufAppend("TypeSpec");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_specifier_)  p->type_specifier_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitQualSpec(QualSpec* p)
{
  bufAppend('(');
  bufAppend("QualSpec");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_qualifier_)  p->type_qualifier_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListStruct_declarator(ListStruct_declarator *liststruct_declarator)
{
  for (ListStruct_declarator::const_iterator i = liststruct_declarator->begin() ; i != liststruct_declarator->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststruct_declarator->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitStruct_declarator(Struct_declarator* p) {} //abstract class

void ShowAbsyn::visitDecl(Decl* p)
{
  bufAppend('(');
  bufAppend("Decl");
  bufAppend(' ');
  bufAppend('[');
  if (p->declarator_)  p->declarator_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitField(Field* p)
{
  bufAppend('(');
  bufAppend("Field");
  bufAppend(' ');
  bufAppend('[');
  if (p->constant_expression_)  p->constant_expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitDecField(DecField* p)
{
  bufAppend('(');
  bufAppend("DecField");
  bufAppend(' ');
  bufAppend('[');
  if (p->declarator_)  p->declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->constant_expression_)  p->constant_expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEnum_specifier(Enum_specifier* p) {} //abstract class

void ShowAbsyn::visitEnumDec(EnumDec* p)
{
  bufAppend('(');
  bufAppend("EnumDec");
  bufAppend(' ');
  bufAppend('[');
  if (p->listenumerator_)  p->listenumerator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEnumName(EnumName* p)
{
  bufAppend('(');
  bufAppend("EnumName");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listenumerator_)  p->listenumerator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEnumVar(EnumVar* p)
{
  bufAppend('(');
  bufAppend("EnumVar");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitListEnumerator(ListEnumerator *listenumerator)
{
  for (ListEnumerator::const_iterator i = listenumerator->begin() ; i != listenumerator->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listenumerator->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitEnumerator(Enumerator* p) {} //abstract class

void ShowAbsyn::visitPlain(Plain* p)
{
  bufAppend('(');
  bufAppend("Plain");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitEnumInit(EnumInit* p)
{
  bufAppend('(');
  bufAppend("EnumInit");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->constant_expression_)  p->constant_expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitDeclarator(Declarator* p) {} //abstract class

void ShowAbsyn::visitBeginPointer(BeginPointer* p)
{
  bufAppend('(');
  bufAppend("BeginPointer");
  bufAppend(' ');
  bufAppend('[');
  if (p->pointer_)  p->pointer_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->direct_declarator_)  p->direct_declarator_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitNoPointer(NoPointer* p)
{
  bufAppend('(');
  bufAppend("NoPointer");
  bufAppend(' ');
  bufAppend('[');
  if (p->direct_declarator_)  p->direct_declarator_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitDirect_declarator(Direct_declarator* p) {} //abstract class

void ShowAbsyn::visitName(Name* p)
{
  bufAppend('(');
  bufAppend("Name");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitParenDecl(ParenDecl* p)
{
  bufAppend('(');
  bufAppend("ParenDecl");
  bufAppend(' ');
  bufAppend('[');
  if (p->declarator_)  p->declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitInnitArray(InnitArray* p)
{
  bufAppend('(');
  bufAppend("InnitArray");
  bufAppend(' ');
  bufAppend('[');
  if (p->direct_declarator_)  p->direct_declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->constant_expression_)  p->constant_expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitIncomplete(Incomplete* p)
{
  bufAppend('(');
  bufAppend("Incomplete");
  bufAppend(' ');
  bufAppend('[');
  if (p->direct_declarator_)  p->direct_declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitNewFuncDec(NewFuncDec* p)
{
  bufAppend('(');
  bufAppend("NewFuncDec");
  bufAppend(' ');
  bufAppend('[');
  if (p->direct_declarator_)  p->direct_declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->parameter_type_)  p->parameter_type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitOldFuncDef(OldFuncDef* p)
{
  bufAppend('(');
  bufAppend("OldFuncDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->direct_declarator_)  p->direct_declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listident_)  p->listident_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitOldFuncDec(OldFuncDec* p)
{
  bufAppend('(');
  bufAppend("OldFuncDec");
  bufAppend(' ');
  bufAppend('[');
  if (p->direct_declarator_)  p->direct_declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitPointer(Pointer* p) {} //abstract class

void ShowAbsyn::visitPoint(Point* p)
{
  bufAppend("Point");
}
void ShowAbsyn::visitPointQual(PointQual* p)
{
  bufAppend('(');
  bufAppend("PointQual");
  bufAppend(' ');
  bufAppend('[');
  if (p->listtype_qualifier_)  p->listtype_qualifier_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitPointPoint(PointPoint* p)
{
  bufAppend('(');
  bufAppend("PointPoint");
  bufAppend(' ');
  bufAppend('[');
  if (p->pointer_)  p->pointer_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitPointQualPoint(PointQualPoint* p)
{
  bufAppend('(');
  bufAppend("PointQualPoint");
  bufAppend(' ');
  bufAppend('[');
  if (p->listtype_qualifier_)  p->listtype_qualifier_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->pointer_)  p->pointer_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListType_qualifier(ListType_qualifier *listtype_qualifier)
{
  for (ListType_qualifier::const_iterator i = listtype_qualifier->begin() ; i != listtype_qualifier->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listtype_qualifier->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitParameter_type(Parameter_type* p) {} //abstract class

void ShowAbsyn::visitAllSpec(AllSpec* p)
{
  bufAppend('(');
  bufAppend("AllSpec");
  bufAppend(' ');
  bufAppend('[');
  if (p->parameter_declarations_)  p->parameter_declarations_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitMore(More* p)
{
  bufAppend('(');
  bufAppend("More");
  bufAppend(' ');
  bufAppend('[');
  if (p->parameter_declarations_)  p->parameter_declarations_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitParameter_declarations(Parameter_declarations* p) {} //abstract class

void ShowAbsyn::visitParamDec(ParamDec* p)
{
  bufAppend('(');
  bufAppend("ParamDec");
  bufAppend(' ');
  bufAppend('[');
  if (p->parameter_declaration_)  p->parameter_declaration_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitMoreParamDec(MoreParamDec* p)
{
  bufAppend('(');
  bufAppend("MoreParamDec");
  bufAppend(' ');
  bufAppend('[');
  if (p->parameter_declarations_)  p->parameter_declarations_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->parameter_declaration_)  p->parameter_declaration_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitParameter_declaration(Parameter_declaration* p) {} //abstract class

void ShowAbsyn::visitOnlyType(OnlyType* p)
{
  bufAppend('(');
  bufAppend("OnlyType");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdeclaration_specifier_)  p->listdeclaration_specifier_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitTypeAndParam(TypeAndParam* p)
{
  bufAppend('(');
  bufAppend("TypeAndParam");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdeclaration_specifier_)  p->listdeclaration_specifier_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->declarator_)  p->declarator_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitAbstract(Abstract* p)
{
  bufAppend('(');
  bufAppend("Abstract");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdeclaration_specifier_)  p->listdeclaration_specifier_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->abstract_declarator_)  p->abstract_declarator_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListIdent(ListIdent *listident)
{
  for (ListIdent::const_iterator i = listident->begin() ; i != listident->end() ; ++i)
  {
    visitIdent(*i) ;
    if (i != listident->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitInitializer(Initializer* p) {} //abstract class

void ShowAbsyn::visitInitExpr(InitExpr* p)
{
  bufAppend('(');
  bufAppend("InitExpr");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitInitListOne(InitListOne* p)
{
  bufAppend('(');
  bufAppend("InitListOne");
  bufAppend(' ');
  bufAppend('[');
  if (p->initializers_)  p->initializers_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitInitListTwo(InitListTwo* p)
{
  bufAppend('(');
  bufAppend("InitListTwo");
  bufAppend(' ');
  bufAppend('[');
  if (p->initializers_)  p->initializers_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitInitializers(Initializers* p) {} //abstract class

void ShowAbsyn::visitAnInit(AnInit* p)
{
  bufAppend('(');
  bufAppend("AnInit");
  bufAppend(' ');
  bufAppend('[');
  if (p->initializer_)  p->initializer_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitMoreInit(MoreInit* p)
{
  bufAppend('(');
  bufAppend("MoreInit");
  bufAppend(' ');
  bufAppend('[');
  if (p->initializers_)  p->initializers_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->initializer_)  p->initializer_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitType_name(Type_name* p) {} //abstract class

void ShowAbsyn::visitPlainType(PlainType* p)
{
  bufAppend('(');
  bufAppend("PlainType");
  bufAppend(' ');
  bufAppend('[');
  if (p->listspec_qual_)  p->listspec_qual_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitExtendedType(ExtendedType* p)
{
  bufAppend('(');
  bufAppend("ExtendedType");
  bufAppend(' ');
  bufAppend('[');
  if (p->listspec_qual_)  p->listspec_qual_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->abstract_declarator_)  p->abstract_declarator_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitAbstract_declarator(Abstract_declarator* p) {} //abstract class

void ShowAbsyn::visitPointerStart(PointerStart* p)
{
  bufAppend('(');
  bufAppend("PointerStart");
  bufAppend(' ');
  bufAppend('[');
  if (p->pointer_)  p->pointer_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitAdvanced(Advanced* p)
{
  bufAppend('(');
  bufAppend("Advanced");
  bufAppend(' ');
  bufAppend('[');
  if (p->dir_abs_dec_)  p->dir_abs_dec_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitPointAdvanced(PointAdvanced* p)
{
  bufAppend('(');
  bufAppend("PointAdvanced");
  bufAppend(' ');
  bufAppend('[');
  if (p->pointer_)  p->pointer_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->dir_abs_dec_)  p->dir_abs_dec_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitDir_abs_dec(Dir_abs_dec* p) {} //abstract class

void ShowAbsyn::visitWithinParentes(WithinParentes* p)
{
  bufAppend('(');
  bufAppend("WithinParentes");
  bufAppend(' ');
  bufAppend('[');
  if (p->abstract_declarator_)  p->abstract_declarator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitArray(Array* p)
{
  bufAppend("Array");
}
void ShowAbsyn::visitInitiatedArray(InitiatedArray* p)
{
  bufAppend('(');
  bufAppend("InitiatedArray");
  bufAppend(' ');
  bufAppend('[');
  if (p->constant_expression_)  p->constant_expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitUnInitiated(UnInitiated* p)
{
  bufAppend('(');
  bufAppend("UnInitiated");
  bufAppend(' ');
  bufAppend('[');
  if (p->dir_abs_dec_)  p->dir_abs_dec_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitInitiated(Initiated* p)
{
  bufAppend('(');
  bufAppend("Initiated");
  bufAppend(' ');
  bufAppend('[');
  if (p->dir_abs_dec_)  p->dir_abs_dec_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->constant_expression_)  p->constant_expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitOldFunction(OldFunction* p)
{
  bufAppend("OldFunction");
}
void ShowAbsyn::visitNewFunction(NewFunction* p)
{
  bufAppend('(');
  bufAppend("NewFunction");
  bufAppend(' ');
  bufAppend('[');
  if (p->parameter_type_)  p->parameter_type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitOldFuncExpr(OldFuncExpr* p)
{
  bufAppend('(');
  bufAppend("OldFuncExpr");
  bufAppend(' ');
  bufAppend('[');
  if (p->dir_abs_dec_)  p->dir_abs_dec_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitNewFuncExpr(NewFuncExpr* p)
{
  bufAppend('(');
  bufAppend("NewFuncExpr");
  bufAppend(' ');
  bufAppend('[');
  if (p->dir_abs_dec_)  p->dir_abs_dec_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->parameter_type_)  p->parameter_type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitStm(Stm* p) {} //abstract class

void ShowAbsyn::visitLabelS(LabelS* p)
{
  bufAppend('(');
  bufAppend("LabelS");
  bufAppend(' ');
  bufAppend('[');
  if (p->labeled_stm_)  p->labeled_stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitCompS(CompS* p)
{
  bufAppend('(');
  bufAppend("CompS");
  bufAppend(' ');
  bufAppend('[');
  if (p->compound_stm_)  p->compound_stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitExprS(ExprS* p)
{
  bufAppend('(');
  bufAppend("ExprS");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_stm_)  p->expression_stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSelS(SelS* p)
{
  bufAppend('(');
  bufAppend("SelS");
  bufAppend(' ');
  bufAppend('[');
  if (p->selection_stm_)  p->selection_stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitIterS(IterS* p)
{
  bufAppend('(');
  bufAppend("IterS");
  bufAppend(' ');
  bufAppend('[');
  if (p->iter_stm_)  p->iter_stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitJumpS(JumpS* p)
{
  bufAppend('(');
  bufAppend("JumpS");
  bufAppend(' ');
  bufAppend('[');
  if (p->jump_stm_)  p->jump_stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitLabeled_stm(Labeled_stm* p) {} //abstract class

void ShowAbsyn::visitSlabelOne(SlabelOne* p)
{
  bufAppend('(');
  bufAppend("SlabelOne");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSlabelTwo(SlabelTwo* p)
{
  bufAppend('(');
  bufAppend("SlabelTwo");
  bufAppend(' ');
  bufAppend('[');
  if (p->constant_expression_)  p->constant_expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSlabelThree(SlabelThree* p)
{
  bufAppend('(');
  bufAppend("SlabelThree");
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitCompound_stm(Compound_stm* p) {} //abstract class

void ShowAbsyn::visitScompOne(ScompOne* p)
{
  bufAppend("ScompOne");
}
void ShowAbsyn::visitScompTwo(ScompTwo* p)
{
  bufAppend('(');
  bufAppend("ScompTwo");
  bufAppend(' ');
  bufAppend('[');
  if (p->liststm_)  p->liststm_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitScompThree(ScompThree* p)
{
  bufAppend('(');
  bufAppend("ScompThree");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdec_)  p->listdec_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitScompFour(ScompFour* p)
{
  bufAppend('(');
  bufAppend("ScompFour");
  bufAppend(' ');
  bufAppend('[');
  if (p->listdec_)  p->listdec_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->liststm_)  p->liststm_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitExpression_stm(Expression_stm* p) {} //abstract class

void ShowAbsyn::visitSexprOne(SexprOne* p)
{
  bufAppend("SexprOne");
}
void ShowAbsyn::visitSexprTwo(SexprTwo* p)
{
  bufAppend('(');
  bufAppend("SexprTwo");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSelection_stm(Selection_stm* p) {} //abstract class

void ShowAbsyn::visitSselOne(SselOne* p)
{
  bufAppend('(');
  bufAppend("SselOne");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSselTwo(SselTwo* p)
{
  bufAppend('(');
  bufAppend("SselTwo");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->stm_1->accept(this);
  bufAppend(' ');
  p->stm_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitSselThree(SselThree* p)
{
  bufAppend('(');
  bufAppend("SselThree");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitIter_stm(Iter_stm* p) {} //abstract class

void ShowAbsyn::visitSiterOne(SiterOne* p)
{
  bufAppend('(');
  bufAppend("SiterOne");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSiterTwo(SiterTwo* p)
{
  bufAppend('(');
  bufAppend("SiterTwo");
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSiterThree(SiterThree* p)
{
  bufAppend('(');
  bufAppend("SiterThree");
  bufAppend(' ');
  p->expression_stm_1->accept(this);
  bufAppend(' ');
  p->expression_stm_2->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSiterFour(SiterFour* p)
{
  bufAppend('(');
  bufAppend("SiterFour");
  bufAppend(' ');
  p->expression_stm_1->accept(this);
  bufAppend(' ');
  p->expression_stm_2->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->stm_)  p->stm_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitJump_stm(Jump_stm* p) {} //abstract class

void ShowAbsyn::visitSjumpOne(SjumpOne* p)
{
  bufAppend('(');
  bufAppend("SjumpOne");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSjumpTwo(SjumpTwo* p)
{
  bufAppend("SjumpTwo");
}
void ShowAbsyn::visitSjumpThree(SjumpThree* p)
{
  bufAppend("SjumpThree");
}
void ShowAbsyn::visitSjumpFour(SjumpFour* p)
{
  bufAppend("SjumpFour");
}
void ShowAbsyn::visitSjumpFive(SjumpFive* p)
{
  bufAppend('(');
  bufAppend("SjumpFive");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListStm(ListStm *liststm)
{
  for (ListStm::const_iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststm->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitExp(Exp* p) {} //abstract class

void ShowAbsyn::visitEcomma(Ecomma* p)
{
  bufAppend('(');
  bufAppend("Ecomma");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEassign(Eassign* p)
{
  bufAppend('(');
  bufAppend("Eassign");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->assignment_op_)  p->assignment_op_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEcondition(Econdition* p)
{
  bufAppend('(');
  bufAppend("Econdition");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(' ');
  p->exp_3->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitElor(Elor* p)
{
  bufAppend('(');
  bufAppend("Elor");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEland(Eland* p)
{
  bufAppend('(');
  bufAppend("Eland");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEbitor(Ebitor* p)
{
  bufAppend('(');
  bufAppend("Ebitor");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEbitexor(Ebitexor* p)
{
  bufAppend('(');
  bufAppend("Ebitexor");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEbitand(Ebitand* p)
{
  bufAppend('(');
  bufAppend("Ebitand");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEeq(Eeq* p)
{
  bufAppend('(');
  bufAppend("Eeq");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEneq(Eneq* p)
{
  bufAppend('(');
  bufAppend("Eneq");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitElthen(Elthen* p)
{
  bufAppend('(');
  bufAppend("Elthen");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEgrthen(Egrthen* p)
{
  bufAppend('(');
  bufAppend("Egrthen");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEle(Ele* p)
{
  bufAppend('(');
  bufAppend("Ele");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEge(Ege* p)
{
  bufAppend('(');
  bufAppend("Ege");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEleft(Eleft* p)
{
  bufAppend('(');
  bufAppend("Eleft");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEright(Eright* p)
{
  bufAppend('(');
  bufAppend("Eright");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEplus(Eplus* p)
{
  bufAppend('(');
  bufAppend("Eplus");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEminus(Eminus* p)
{
  bufAppend('(');
  bufAppend("Eminus");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEtimes(Etimes* p)
{
  bufAppend('(');
  bufAppend("Etimes");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEdiv(Ediv* p)
{
  bufAppend('(');
  bufAppend("Ediv");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEmod(Emod* p)
{
  bufAppend('(');
  bufAppend("Emod");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEtypeconv(Etypeconv* p)
{
  bufAppend('(');
  bufAppend("Etypeconv");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_name_)  p->type_name_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEpreinc(Epreinc* p)
{
  bufAppend('(');
  bufAppend("Epreinc");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEpredec(Epredec* p)
{
  bufAppend('(');
  bufAppend("Epredec");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEpreop(Epreop* p)
{
  bufAppend('(');
  bufAppend("Epreop");
  bufAppend(' ');
  bufAppend('[');
  if (p->unary_operator_)  p->unary_operator_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEbytesexpr(Ebytesexpr* p)
{
  bufAppend('(');
  bufAppend("Ebytesexpr");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEbytestype(Ebytestype* p)
{
  bufAppend('(');
  bufAppend("Ebytestype");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_name_)  p->type_name_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEarray(Earray* p)
{
  bufAppend('(');
  bufAppend("Earray");
  bufAppend(' ');
  p->exp_1->accept(this);
  bufAppend(' ');
  p->exp_2->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEfunk(Efunk* p)
{
  bufAppend('(');
  bufAppend("Efunk");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEfunkpar(Efunkpar* p)
{
  bufAppend('(');
  bufAppend("Efunkpar");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listexp_)  p->listexp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEselect(Eselect* p)
{
  bufAppend('(');
  bufAppend("Eselect");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitEpoint(Epoint* p)
{
  bufAppend('(');
  bufAppend("Epoint");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitEpostinc(Epostinc* p)
{
  bufAppend('(');
  bufAppend("Epostinc");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEpostdec(Epostdec* p)
{
  bufAppend('(');
  bufAppend("Epostdec");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEvar(Evar* p)
{
  bufAppend('(');
  bufAppend("Evar");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitEconst(Econst* p)
{
  bufAppend('(');
  bufAppend("Econst");
  bufAppend(' ');
  bufAppend('[');
  if (p->constant_)  p->constant_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEstring(Estring* p)
{
  bufAppend('(');
  bufAppend("Estring");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
void ShowAbsyn::visitConstant(Constant* p) {} //abstract class

void ShowAbsyn::visitEfloat(Efloat* p)
{
  bufAppend('(');
  bufAppend("Efloat");
  bufAppend(' ');
  visitDouble(p->double_);
  bufAppend(')');
}
void ShowAbsyn::visitEchar(Echar* p)
{
  bufAppend('(');
  bufAppend("Echar");
  bufAppend(' ');
  visitChar(p->char_);
  bufAppend(')');
}
void ShowAbsyn::visitEunsigned(Eunsigned* p)
{
  bufAppend('(');
  bufAppend("Eunsigned");
  bufAppend(' ');
  visitIdent(p->unsigned_);
  bufAppend(')');
}
void ShowAbsyn::visitElong(Elong* p)
{
  bufAppend('(');
  bufAppend("Elong");
  bufAppend(' ');
  visitIdent(p->long_);
  bufAppend(')');
}
void ShowAbsyn::visitEunsignlong(Eunsignlong* p)
{
  bufAppend('(');
  bufAppend("Eunsignlong");
  bufAppend(' ');
  visitIdent(p->unsignedlong_);
  bufAppend(')');
}
void ShowAbsyn::visitEhexadec(Ehexadec* p)
{
  bufAppend('(');
  bufAppend("Ehexadec");
  bufAppend(' ');
  visitIdent(p->hexadecimal_);
  bufAppend(')');
}
void ShowAbsyn::visitEhexaunsign(Ehexaunsign* p)
{
  bufAppend('(');
  bufAppend("Ehexaunsign");
  bufAppend(' ');
  visitIdent(p->hexunsigned_);
  bufAppend(')');
}
void ShowAbsyn::visitEhexalong(Ehexalong* p)
{
  bufAppend('(');
  bufAppend("Ehexalong");
  bufAppend(' ');
  visitIdent(p->hexlong_);
  bufAppend(')');
}
void ShowAbsyn::visitEhexaunslong(Ehexaunslong* p)
{
  bufAppend('(');
  bufAppend("Ehexaunslong");
  bufAppend(' ');
  visitIdent(p->hexunslong_);
  bufAppend(')');
}
void ShowAbsyn::visitEoctal(Eoctal* p)
{
  bufAppend('(');
  bufAppend("Eoctal");
  bufAppend(' ');
  visitIdent(p->octal_);
  bufAppend(')');
}
void ShowAbsyn::visitEoctalunsign(Eoctalunsign* p)
{
  bufAppend('(');
  bufAppend("Eoctalunsign");
  bufAppend(' ');
  visitIdent(p->octalunsigned_);
  bufAppend(')');
}
void ShowAbsyn::visitEoctallong(Eoctallong* p)
{
  bufAppend('(');
  bufAppend("Eoctallong");
  bufAppend(' ');
  visitIdent(p->octallong_);
  bufAppend(')');
}
void ShowAbsyn::visitEoctalunslong(Eoctalunslong* p)
{
  bufAppend('(');
  bufAppend("Eoctalunslong");
  bufAppend(' ');
  visitIdent(p->octalunslong_);
  bufAppend(')');
}
void ShowAbsyn::visitEcdouble(Ecdouble* p)
{
  bufAppend('(');
  bufAppend("Ecdouble");
  bufAppend(' ');
  visitIdent(p->cdouble_);
  bufAppend(')');
}
void ShowAbsyn::visitEcfloat(Ecfloat* p)
{
  bufAppend('(');
  bufAppend("Ecfloat");
  bufAppend(' ');
  visitIdent(p->cfloat_);
  bufAppend(')');
}
void ShowAbsyn::visitEclongdouble(Eclongdouble* p)
{
  bufAppend('(');
  bufAppend("Eclongdouble");
  bufAppend(' ');
  visitIdent(p->clongdouble_);
  bufAppend(')');
}
void ShowAbsyn::visitEint(Eint* p)
{
  bufAppend('(');
  bufAppend("Eint");
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitElonger(Elonger* p)
{
  bufAppend('(');
  bufAppend("Elonger");
  bufAppend(' ');
/* Internal Category */
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitEdouble(Edouble* p)
{
  bufAppend('(');
  bufAppend("Edouble");
  bufAppend(' ');
/* Internal Category */
  bufAppend(' ');
  visitDouble(p->double_);
  bufAppend(')');
}
void ShowAbsyn::visitConstant_expression(Constant_expression* p) {} //abstract class

void ShowAbsyn::visitEspecial(Especial* p)
{
  bufAppend('(');
  bufAppend("Especial");
  bufAppend(' ');
  bufAppend('[');
  if (p->exp_)  p->exp_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitUnary_operator(Unary_operator* p) {} //abstract class

void ShowAbsyn::visitAddress(Address* p)
{
  bufAppend("Address");
}
void ShowAbsyn::visitIndirection(Indirection* p)
{
  bufAppend("Indirection");
}
void ShowAbsyn::visitPlus(Plus* p)
{
  bufAppend("Plus");
}
void ShowAbsyn::visitNegative(Negative* p)
{
  bufAppend("Negative");
}
void ShowAbsyn::visitComplement(Complement* p)
{
  bufAppend("Complement");
}
void ShowAbsyn::visitLogicalneg(Logicalneg* p)
{
  bufAppend("Logicalneg");
}
void ShowAbsyn::visitListExp(ListExp *listexp)
{
  for (ListExp::const_iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexp->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitAssignment_op(Assignment_op* p) {} //abstract class

void ShowAbsyn::visitAssign(Assign* p)
{
  bufAppend("Assign");
}
void ShowAbsyn::visitAssignMul(AssignMul* p)
{
  bufAppend("AssignMul");
}
void ShowAbsyn::visitAssignDiv(AssignDiv* p)
{
  bufAppend("AssignDiv");
}
void ShowAbsyn::visitAssignMod(AssignMod* p)
{
  bufAppend("AssignMod");
}
void ShowAbsyn::visitAssignAdd(AssignAdd* p)
{
  bufAppend("AssignAdd");
}
void ShowAbsyn::visitAssignSub(AssignSub* p)
{
  bufAppend("AssignSub");
}
void ShowAbsyn::visitAssignLeft(AssignLeft* p)
{
  bufAppend("AssignLeft");
}
void ShowAbsyn::visitAssignRight(AssignRight* p)
{
  bufAppend("AssignRight");
}
void ShowAbsyn::visitAssignAnd(AssignAnd* p)
{
  bufAppend("AssignAnd");
}
void ShowAbsyn::visitAssignXor(AssignXor* p)
{
  bufAppend("AssignXor");
}
void ShowAbsyn::visitAssignOr(AssignOr* p)
{
  bufAppend("AssignOr");
}
void ShowAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void ShowAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void ShowAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void ShowAbsyn::visitString(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void ShowAbsyn::visitIdent(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}

void ShowAbsyn::visitUnsigned(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitLong(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitUnsignedLong(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitHexadecimal(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitHexUnsigned(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitHexLong(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitHexUnsLong(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitOctal(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitOctalUnsigned(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitOctalLong(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitOctalUnsLong(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitCDouble(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitCFloat(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


void ShowAbsyn::visitCLongDouble(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}



