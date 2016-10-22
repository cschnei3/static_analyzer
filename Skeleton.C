/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"



void Skeleton::visitProgram(Program* t) {} //abstract class
void Skeleton::visitExternal_declaration(External_declaration* t) {} //abstract class
void Skeleton::visitFunction_def(Function_def* t) {} //abstract class
void Skeleton::visitDec(Dec* t) {} //abstract class
void Skeleton::visitDeclaration_specifier(Declaration_specifier* t) {} //abstract class
void Skeleton::visitInit_declarator(Init_declarator* t) {} //abstract class
void Skeleton::visitType_specifier(Type_specifier* t) {} //abstract class
void Skeleton::visitStorage_class_specifier(Storage_class_specifier* t) {} //abstract class
void Skeleton::visitType_qualifier(Type_qualifier* t) {} //abstract class
void Skeleton::visitStruct_or_union_spec(Struct_or_union_spec* t) {} //abstract class
void Skeleton::visitStruct_or_union(Struct_or_union* t) {} //abstract class
void Skeleton::visitStruct_dec(Struct_dec* t) {} //abstract class
void Skeleton::visitSpec_qual(Spec_qual* t) {} //abstract class
void Skeleton::visitStruct_declarator(Struct_declarator* t) {} //abstract class
void Skeleton::visitEnum_specifier(Enum_specifier* t) {} //abstract class
void Skeleton::visitEnumerator(Enumerator* t) {} //abstract class
void Skeleton::visitDeclarator(Declarator* t) {} //abstract class
void Skeleton::visitDirect_declarator(Direct_declarator* t) {} //abstract class
void Skeleton::visitPointer(Pointer* t) {} //abstract class
void Skeleton::visitParameter_type(Parameter_type* t) {} //abstract class
void Skeleton::visitParameter_declarations(Parameter_declarations* t) {} //abstract class
void Skeleton::visitParameter_declaration(Parameter_declaration* t) {} //abstract class
void Skeleton::visitInitializer(Initializer* t) {} //abstract class
void Skeleton::visitInitializers(Initializers* t) {} //abstract class
void Skeleton::visitType_name(Type_name* t) {} //abstract class
void Skeleton::visitAbstract_declarator(Abstract_declarator* t) {} //abstract class
void Skeleton::visitDir_abs_dec(Dir_abs_dec* t) {} //abstract class
void Skeleton::visitStm(Stm* t) {} //abstract class
void Skeleton::visitLabeled_stm(Labeled_stm* t) {} //abstract class
void Skeleton::visitCompound_stm(Compound_stm* t) {} //abstract class
void Skeleton::visitExpression_stm(Expression_stm* t) {} //abstract class
void Skeleton::visitSelection_stm(Selection_stm* t) {} //abstract class
void Skeleton::visitIter_stm(Iter_stm* t) {} //abstract class
void Skeleton::visitJump_stm(Jump_stm* t) {} //abstract class
void Skeleton::visitExp(Exp* t) {} //abstract class
void Skeleton::visitConstant(Constant* t) {} //abstract class
void Skeleton::visitConstant_expression(Constant_expression* t) {} //abstract class
void Skeleton::visitUnary_operator(Unary_operator* t) {} //abstract class
void Skeleton::visitAssignment_op(Assignment_op* t) {} //abstract class

void Skeleton::visitProgr(Progr *progr)
{
  /* Code For Progr Goes Here */

  progr->listexternal_declaration_->accept(this);

}

void Skeleton::visitAfunc(Afunc *afunc)
{
  /* Code For Afunc Goes Here */

  afunc->function_def_->accept(this);

}

void Skeleton::visitGlobal(Global *global)
{
  /* Code For Global Goes Here */

  global->dec_->accept(this);

}

void Skeleton::visitOldFunc(OldFunc *oldfunc)
{
  /* Code For OldFunc Goes Here */

  oldfunc->listdeclaration_specifier_->accept(this);
  oldfunc->declarator_->accept(this);
  oldfunc->listdec_->accept(this);
  oldfunc->compound_stm_->accept(this);

}

void Skeleton::visitNewFunc(NewFunc *newfunc)
{
  /* Code For NewFunc Goes Here */

  newfunc->listdeclaration_specifier_->accept(this);
  newfunc->declarator_->accept(this);
  newfunc->compound_stm_->accept(this);

}

void Skeleton::visitOldFuncInt(OldFuncInt *oldfuncint)
{
  /* Code For OldFuncInt Goes Here */

  oldfuncint->declarator_->accept(this);
  oldfuncint->listdec_->accept(this);
  oldfuncint->compound_stm_->accept(this);

}

void Skeleton::visitNewFuncInt(NewFuncInt *newfuncint)
{
  /* Code For NewFuncInt Goes Here */

  newfuncint->declarator_->accept(this);
  newfuncint->compound_stm_->accept(this);

}

void Skeleton::visitNoDeclarator(NoDeclarator *nodeclarator)
{
  /* Code For NoDeclarator Goes Here */

  nodeclarator->listdeclaration_specifier_->accept(this);

}

void Skeleton::visitDeclarators(Declarators *declarators)
{
  /* Code For Declarators Goes Here */

  declarators->listdeclaration_specifier_->accept(this);
  declarators->listinit_declarator_->accept(this);

}

void Skeleton::visitType(Type *type)
{
  /* Code For Type Goes Here */

  type->type_specifier_->accept(this);

}

void Skeleton::visitStorage(Storage *storage)
{
  /* Code For Storage Goes Here */

  storage->storage_class_specifier_->accept(this);

}

void Skeleton::visitSpecProp(SpecProp *specprop)
{
  /* Code For SpecProp Goes Here */

  specprop->type_qualifier_->accept(this);

}

void Skeleton::visitOnlyDecl(OnlyDecl *onlydecl)
{
  /* Code For OnlyDecl Goes Here */

  onlydecl->declarator_->accept(this);

}

void Skeleton::visitInitDecl(InitDecl *initdecl)
{
  /* Code For InitDecl Goes Here */

  initdecl->declarator_->accept(this);
  initdecl->initializer_->accept(this);

}

void Skeleton::visitTvoid(Tvoid *tvoid)
{
  /* Code For Tvoid Goes Here */


}

void Skeleton::visitTchar(Tchar *tchar)
{
  /* Code For Tchar Goes Here */


}

void Skeleton::visitTshort(Tshort *tshort)
{
  /* Code For Tshort Goes Here */


}

void Skeleton::visitTint(Tint *tint)
{
  /* Code For Tint Goes Here */


}

void Skeleton::visitTlong(Tlong *tlong)
{
  /* Code For Tlong Goes Here */


}

void Skeleton::visitTfloat(Tfloat *tfloat)
{
  /* Code For Tfloat Goes Here */


}

void Skeleton::visitTdouble(Tdouble *tdouble)
{
  /* Code For Tdouble Goes Here */


}

void Skeleton::visitTsigned(Tsigned *tsigned)
{
  /* Code For Tsigned Goes Here */


}

void Skeleton::visitTunsigned(Tunsigned *tunsigned)
{
  /* Code For Tunsigned Goes Here */


}

void Skeleton::visitTstruct(Tstruct *tstruct)
{
  /* Code For Tstruct Goes Here */

  tstruct->struct_or_union_spec_->accept(this);

}

void Skeleton::visitTenum(Tenum *tenum)
{
  /* Code For Tenum Goes Here */

  tenum->enum_specifier_->accept(this);

}

void Skeleton::visitTname(Tname *tname)
{
  /* Code For Tname Goes Here */


}

void Skeleton::visitMyType(MyType *mytype)
{
  /* Code For MyType Goes Here */


}

void Skeleton::visitGlobalPrograms(GlobalPrograms *globalprograms)
{
  /* Code For GlobalPrograms Goes Here */


}

void Skeleton::visitLocalProgram(LocalProgram *localprogram)
{
  /* Code For LocalProgram Goes Here */


}

void Skeleton::visitLocalBlock(LocalBlock *localblock)
{
  /* Code For LocalBlock Goes Here */


}

void Skeleton::visitLocalReg(LocalReg *localreg)
{
  /* Code For LocalReg Goes Here */


}

void Skeleton::visitConst(Const *const)
{
  /* Code For Const Goes Here */


}

void Skeleton::visitNoOptim(NoOptim *nooptim)
{
  /* Code For NoOptim Goes Here */


}

void Skeleton::visitTag(Tag *tag)
{
  /* Code For Tag Goes Here */

  tag->struct_or_union_->accept(this);
  visitIdent(tag->ident_);
  tag->liststruct_dec_->accept(this);

}

void Skeleton::visitUnique(Unique *unique)
{
  /* Code For Unique Goes Here */

  unique->struct_or_union_->accept(this);
  unique->liststruct_dec_->accept(this);

}

void Skeleton::visitTagType(TagType *tagtype)
{
  /* Code For TagType Goes Here */

  tagtype->struct_or_union_->accept(this);
  visitIdent(tagtype->ident_);

}

void Skeleton::visitStruct(Struct *struct)
{
  /* Code For Struct Goes Here */


}

void Skeleton::visitUnion(Union *union)
{
  /* Code For Union Goes Here */


}

void Skeleton::visitStructen(Structen *structen)
{
  /* Code For Structen Goes Here */

  structen->listspec_qual_->accept(this);
  structen->liststruct_declarator_->accept(this);

}

void Skeleton::visitTypeSpec(TypeSpec *typespec)
{
  /* Code For TypeSpec Goes Here */

  typespec->type_specifier_->accept(this);

}

void Skeleton::visitQualSpec(QualSpec *qualspec)
{
  /* Code For QualSpec Goes Here */

  qualspec->type_qualifier_->accept(this);

}

void Skeleton::visitDecl(Decl *decl)
{
  /* Code For Decl Goes Here */

  decl->declarator_->accept(this);

}

void Skeleton::visitField(Field *field)
{
  /* Code For Field Goes Here */

  field->constant_expression_->accept(this);

}

void Skeleton::visitDecField(DecField *decfield)
{
  /* Code For DecField Goes Here */

  decfield->declarator_->accept(this);
  decfield->constant_expression_->accept(this);

}

void Skeleton::visitEnumDec(EnumDec *enumdec)
{
  /* Code For EnumDec Goes Here */

  enumdec->listenumerator_->accept(this);

}

void Skeleton::visitEnumName(EnumName *enumname)
{
  /* Code For EnumName Goes Here */

  visitIdent(enumname->ident_);
  enumname->listenumerator_->accept(this);

}

void Skeleton::visitEnumVar(EnumVar *enumvar)
{
  /* Code For EnumVar Goes Here */

  visitIdent(enumvar->ident_);

}

void Skeleton::visitPlain(Plain *plain)
{
  /* Code For Plain Goes Here */

  visitIdent(plain->ident_);

}

void Skeleton::visitEnumInit(EnumInit *enuminit)
{
  /* Code For EnumInit Goes Here */

  visitIdent(enuminit->ident_);
  enuminit->constant_expression_->accept(this);

}

void Skeleton::visitBeginPointer(BeginPointer *beginpointer)
{
  /* Code For BeginPointer Goes Here */

  beginpointer->pointer_->accept(this);
  beginpointer->direct_declarator_->accept(this);

}

void Skeleton::visitNoPointer(NoPointer *nopointer)
{
  /* Code For NoPointer Goes Here */

  nopointer->direct_declarator_->accept(this);

}

void Skeleton::visitName(Name *name)
{
  /* Code For Name Goes Here */

  visitIdent(name->ident_);

}

void Skeleton::visitParenDecl(ParenDecl *parendecl)
{
  /* Code For ParenDecl Goes Here */

  parendecl->declarator_->accept(this);

}

void Skeleton::visitInnitArray(InnitArray *innitarray)
{
  /* Code For InnitArray Goes Here */

  innitarray->direct_declarator_->accept(this);
  innitarray->constant_expression_->accept(this);

}

void Skeleton::visitIncomplete(Incomplete *incomplete)
{
  /* Code For Incomplete Goes Here */

  incomplete->direct_declarator_->accept(this);

}

void Skeleton::visitNewFuncDec(NewFuncDec *newfuncdec)
{
  /* Code For NewFuncDec Goes Here */

  newfuncdec->direct_declarator_->accept(this);
  newfuncdec->parameter_type_->accept(this);

}

void Skeleton::visitOldFuncDef(OldFuncDef *oldfuncdef)
{
  /* Code For OldFuncDef Goes Here */

  oldfuncdef->direct_declarator_->accept(this);
  oldfuncdef->listident_->accept(this);

}

void Skeleton::visitOldFuncDec(OldFuncDec *oldfuncdec)
{
  /* Code For OldFuncDec Goes Here */

  oldfuncdec->direct_declarator_->accept(this);

}

void Skeleton::visitPoint(Point *point)
{
  /* Code For Point Goes Here */


}

void Skeleton::visitPointQual(PointQual *pointqual)
{
  /* Code For PointQual Goes Here */

  pointqual->listtype_qualifier_->accept(this);

}

void Skeleton::visitPointPoint(PointPoint *pointpoint)
{
  /* Code For PointPoint Goes Here */

  pointpoint->pointer_->accept(this);

}

void Skeleton::visitPointQualPoint(PointQualPoint *pointqualpoint)
{
  /* Code For PointQualPoint Goes Here */

  pointqualpoint->listtype_qualifier_->accept(this);
  pointqualpoint->pointer_->accept(this);

}

void Skeleton::visitAllSpec(AllSpec *allspec)
{
  /* Code For AllSpec Goes Here */

  allspec->parameter_declarations_->accept(this);

}

void Skeleton::visitMore(More *more)
{
  /* Code For More Goes Here */

  more->parameter_declarations_->accept(this);

}

void Skeleton::visitParamDec(ParamDec *paramdec)
{
  /* Code For ParamDec Goes Here */

  paramdec->parameter_declaration_->accept(this);

}

void Skeleton::visitMoreParamDec(MoreParamDec *moreparamdec)
{
  /* Code For MoreParamDec Goes Here */

  moreparamdec->parameter_declarations_->accept(this);
  moreparamdec->parameter_declaration_->accept(this);

}

void Skeleton::visitOnlyType(OnlyType *onlytype)
{
  /* Code For OnlyType Goes Here */

  onlytype->listdeclaration_specifier_->accept(this);

}

void Skeleton::visitTypeAndParam(TypeAndParam *typeandparam)
{
  /* Code For TypeAndParam Goes Here */

  typeandparam->listdeclaration_specifier_->accept(this);
  typeandparam->declarator_->accept(this);

}

void Skeleton::visitAbstract(Abstract *abstract)
{
  /* Code For Abstract Goes Here */

  abstract->listdeclaration_specifier_->accept(this);
  abstract->abstract_declarator_->accept(this);

}

void Skeleton::visitInitExpr(InitExpr *initexpr)
{
  /* Code For InitExpr Goes Here */

  initexpr->exp_->accept(this);

}

void Skeleton::visitInitListOne(InitListOne *initlistone)
{
  /* Code For InitListOne Goes Here */

  initlistone->initializers_->accept(this);

}

void Skeleton::visitInitListTwo(InitListTwo *initlisttwo)
{
  /* Code For InitListTwo Goes Here */

  initlisttwo->initializers_->accept(this);

}

void Skeleton::visitAnInit(AnInit *aninit)
{
  /* Code For AnInit Goes Here */

  aninit->initializer_->accept(this);

}

void Skeleton::visitMoreInit(MoreInit *moreinit)
{
  /* Code For MoreInit Goes Here */

  moreinit->initializers_->accept(this);
  moreinit->initializer_->accept(this);

}

void Skeleton::visitPlainType(PlainType *plaintype)
{
  /* Code For PlainType Goes Here */

  plaintype->listspec_qual_->accept(this);

}

void Skeleton::visitExtendedType(ExtendedType *extendedtype)
{
  /* Code For ExtendedType Goes Here */

  extendedtype->listspec_qual_->accept(this);
  extendedtype->abstract_declarator_->accept(this);

}

void Skeleton::visitPointerStart(PointerStart *pointerstart)
{
  /* Code For PointerStart Goes Here */

  pointerstart->pointer_->accept(this);

}

void Skeleton::visitAdvanced(Advanced *advanced)
{
  /* Code For Advanced Goes Here */

  advanced->dir_abs_dec_->accept(this);

}

void Skeleton::visitPointAdvanced(PointAdvanced *pointadvanced)
{
  /* Code For PointAdvanced Goes Here */

  pointadvanced->pointer_->accept(this);
  pointadvanced->dir_abs_dec_->accept(this);

}

void Skeleton::visitWithinParentes(WithinParentes *withinparentes)
{
  /* Code For WithinParentes Goes Here */

  withinparentes->abstract_declarator_->accept(this);

}

void Skeleton::visitArray(Array *array)
{
  /* Code For Array Goes Here */


}

void Skeleton::visitInitiatedArray(InitiatedArray *initiatedarray)
{
  /* Code For InitiatedArray Goes Here */

  initiatedarray->constant_expression_->accept(this);

}

void Skeleton::visitUnInitiated(UnInitiated *uninitiated)
{
  /* Code For UnInitiated Goes Here */

  uninitiated->dir_abs_dec_->accept(this);

}

void Skeleton::visitInitiated(Initiated *initiated)
{
  /* Code For Initiated Goes Here */

  initiated->dir_abs_dec_->accept(this);
  initiated->constant_expression_->accept(this);

}

void Skeleton::visitOldFunction(OldFunction *oldfunction)
{
  /* Code For OldFunction Goes Here */


}

void Skeleton::visitNewFunction(NewFunction *newfunction)
{
  /* Code For NewFunction Goes Here */

  newfunction->parameter_type_->accept(this);

}

void Skeleton::visitOldFuncExpr(OldFuncExpr *oldfuncexpr)
{
  /* Code For OldFuncExpr Goes Here */

  oldfuncexpr->dir_abs_dec_->accept(this);

}

void Skeleton::visitNewFuncExpr(NewFuncExpr *newfuncexpr)
{
  /* Code For NewFuncExpr Goes Here */

  newfuncexpr->dir_abs_dec_->accept(this);
  newfuncexpr->parameter_type_->accept(this);

}

void Skeleton::visitLabelS(LabelS *labels)
{
  /* Code For LabelS Goes Here */

  labels->labeled_stm_->accept(this);

}

void Skeleton::visitCompS(CompS *comps)
{
  /* Code For CompS Goes Here */

  comps->compound_stm_->accept(this);

}

void Skeleton::visitExprS(ExprS *exprs)
{
  /* Code For ExprS Goes Here */

  exprs->expression_stm_->accept(this);

}

void Skeleton::visitSelS(SelS *sels)
{
  /* Code For SelS Goes Here */

  sels->selection_stm_->accept(this);

}

void Skeleton::visitIterS(IterS *iters)
{
  /* Code For IterS Goes Here */

  iters->iter_stm_->accept(this);

}

void Skeleton::visitJumpS(JumpS *jumps)
{
  /* Code For JumpS Goes Here */

  jumps->jump_stm_->accept(this);

}

void Skeleton::visitSlabelOne(SlabelOne *slabelone)
{
  /* Code For SlabelOne Goes Here */

  visitIdent(slabelone->ident_);
  slabelone->stm_->accept(this);

}

void Skeleton::visitSlabelTwo(SlabelTwo *slabeltwo)
{
  /* Code For SlabelTwo Goes Here */

  slabeltwo->constant_expression_->accept(this);
  slabeltwo->stm_->accept(this);

}

void Skeleton::visitSlabelThree(SlabelThree *slabelthree)
{
  /* Code For SlabelThree Goes Here */

  slabelthree->stm_->accept(this);

}

void Skeleton::visitScompOne(ScompOne *scompone)
{
  /* Code For ScompOne Goes Here */


}

void Skeleton::visitScompTwo(ScompTwo *scomptwo)
{
  /* Code For ScompTwo Goes Here */

  scomptwo->liststm_->accept(this);

}

void Skeleton::visitScompThree(ScompThree *scompthree)
{
  /* Code For ScompThree Goes Here */

  scompthree->listdec_->accept(this);

}

void Skeleton::visitScompFour(ScompFour *scompfour)
{
  /* Code For ScompFour Goes Here */

  scompfour->listdec_->accept(this);
  scompfour->liststm_->accept(this);

}

void Skeleton::visitSexprOne(SexprOne *sexprone)
{
  /* Code For SexprOne Goes Here */


}

void Skeleton::visitSexprTwo(SexprTwo *sexprtwo)
{
  /* Code For SexprTwo Goes Here */

  sexprtwo->exp_->accept(this);

}

void Skeleton::visitSselOne(SselOne *sselone)
{
  /* Code For SselOne Goes Here */

  sselone->exp_->accept(this);
  sselone->stm_->accept(this);

}

void Skeleton::visitSselTwo(SselTwo *sseltwo)
{
  /* Code For SselTwo Goes Here */

  sseltwo->exp_->accept(this);
  sseltwo->stm_1->accept(this);
  sseltwo->stm_2->accept(this);

}

void Skeleton::visitSselThree(SselThree *sselthree)
{
  /* Code For SselThree Goes Here */

  sselthree->exp_->accept(this);
  sselthree->stm_->accept(this);

}

void Skeleton::visitSiterOne(SiterOne *siterone)
{
  /* Code For SiterOne Goes Here */

  siterone->exp_->accept(this);
  siterone->stm_->accept(this);

}

void Skeleton::visitSiterTwo(SiterTwo *sitertwo)
{
  /* Code For SiterTwo Goes Here */

  sitertwo->stm_->accept(this);
  sitertwo->exp_->accept(this);

}

void Skeleton::visitSiterThree(SiterThree *siterthree)
{
  /* Code For SiterThree Goes Here */

  siterthree->expression_stm_1->accept(this);
  siterthree->expression_stm_2->accept(this);
  siterthree->stm_->accept(this);

}

void Skeleton::visitSiterFour(SiterFour *siterfour)
{
  /* Code For SiterFour Goes Here */

  siterfour->expression_stm_1->accept(this);
  siterfour->expression_stm_2->accept(this);
  siterfour->exp_->accept(this);
  siterfour->stm_->accept(this);

}

void Skeleton::visitSjumpOne(SjumpOne *sjumpone)
{
  /* Code For SjumpOne Goes Here */

  visitIdent(sjumpone->ident_);

}

void Skeleton::visitSjumpTwo(SjumpTwo *sjumptwo)
{
  /* Code For SjumpTwo Goes Here */


}

void Skeleton::visitSjumpThree(SjumpThree *sjumpthree)
{
  /* Code For SjumpThree Goes Here */


}

void Skeleton::visitSjumpFour(SjumpFour *sjumpfour)
{
  /* Code For SjumpFour Goes Here */


}

void Skeleton::visitSjumpFive(SjumpFive *sjumpfive)
{
  /* Code For SjumpFive Goes Here */

  sjumpfive->exp_->accept(this);

}

void Skeleton::visitEcomma(Ecomma *ecomma)
{
  /* Code For Ecomma Goes Here */

  ecomma->exp_1->accept(this);
  ecomma->exp_2->accept(this);

}

void Skeleton::visitEassign(Eassign *eassign)
{
  /* Code For Eassign Goes Here */

  eassign->exp_1->accept(this);
  eassign->assignment_op_->accept(this);
  eassign->exp_2->accept(this);

}

void Skeleton::visitEcondition(Econdition *econdition)
{
  /* Code For Econdition Goes Here */

  econdition->exp_1->accept(this);
  econdition->exp_2->accept(this);
  econdition->exp_3->accept(this);

}

void Skeleton::visitElor(Elor *elor)
{
  /* Code For Elor Goes Here */

  elor->exp_1->accept(this);
  elor->exp_2->accept(this);

}

void Skeleton::visitEland(Eland *eland)
{
  /* Code For Eland Goes Here */

  eland->exp_1->accept(this);
  eland->exp_2->accept(this);

}

void Skeleton::visitEbitor(Ebitor *ebitor)
{
  /* Code For Ebitor Goes Here */

  ebitor->exp_1->accept(this);
  ebitor->exp_2->accept(this);

}

void Skeleton::visitEbitexor(Ebitexor *ebitexor)
{
  /* Code For Ebitexor Goes Here */

  ebitexor->exp_1->accept(this);
  ebitexor->exp_2->accept(this);

}

void Skeleton::visitEbitand(Ebitand *ebitand)
{
  /* Code For Ebitand Goes Here */

  ebitand->exp_1->accept(this);
  ebitand->exp_2->accept(this);

}

void Skeleton::visitEeq(Eeq *eeq)
{
  /* Code For Eeq Goes Here */

  eeq->exp_1->accept(this);
  eeq->exp_2->accept(this);

}

void Skeleton::visitEneq(Eneq *eneq)
{
  /* Code For Eneq Goes Here */

  eneq->exp_1->accept(this);
  eneq->exp_2->accept(this);

}

void Skeleton::visitElthen(Elthen *elthen)
{
  /* Code For Elthen Goes Here */

  elthen->exp_1->accept(this);
  elthen->exp_2->accept(this);

}

void Skeleton::visitEgrthen(Egrthen *egrthen)
{
  /* Code For Egrthen Goes Here */

  egrthen->exp_1->accept(this);
  egrthen->exp_2->accept(this);

}

void Skeleton::visitEle(Ele *ele)
{
  /* Code For Ele Goes Here */

  ele->exp_1->accept(this);
  ele->exp_2->accept(this);

}

void Skeleton::visitEge(Ege *ege)
{
  /* Code For Ege Goes Here */

  ege->exp_1->accept(this);
  ege->exp_2->accept(this);

}

void Skeleton::visitEleft(Eleft *eleft)
{
  /* Code For Eleft Goes Here */

  eleft->exp_1->accept(this);
  eleft->exp_2->accept(this);

}

void Skeleton::visitEright(Eright *eright)
{
  /* Code For Eright Goes Here */

  eright->exp_1->accept(this);
  eright->exp_2->accept(this);

}

void Skeleton::visitEplus(Eplus *eplus)
{
  /* Code For Eplus Goes Here */

  eplus->exp_1->accept(this);
  eplus->exp_2->accept(this);

}

void Skeleton::visitEminus(Eminus *eminus)
{
  /* Code For Eminus Goes Here */

  eminus->exp_1->accept(this);
  eminus->exp_2->accept(this);

}

void Skeleton::visitEtimes(Etimes *etimes)
{
  /* Code For Etimes Goes Here */

  etimes->exp_1->accept(this);
  etimes->exp_2->accept(this);

}

void Skeleton::visitEdiv(Ediv *ediv)
{
  /* Code For Ediv Goes Here */

  ediv->exp_1->accept(this);
  ediv->exp_2->accept(this);

}

void Skeleton::visitEmod(Emod *emod)
{
  /* Code For Emod Goes Here */

  emod->exp_1->accept(this);
  emod->exp_2->accept(this);

}

void Skeleton::visitEtypeconv(Etypeconv *etypeconv)
{
  /* Code For Etypeconv Goes Here */

  etypeconv->type_name_->accept(this);
  etypeconv->exp_->accept(this);

}

void Skeleton::visitEpreinc(Epreinc *epreinc)
{
  /* Code For Epreinc Goes Here */

  epreinc->exp_->accept(this);

}

void Skeleton::visitEpredec(Epredec *epredec)
{
  /* Code For Epredec Goes Here */

  epredec->exp_->accept(this);

}

void Skeleton::visitEpreop(Epreop *epreop)
{
  /* Code For Epreop Goes Here */

  epreop->unary_operator_->accept(this);
  epreop->exp_->accept(this);

}

void Skeleton::visitEbytesexpr(Ebytesexpr *ebytesexpr)
{
  /* Code For Ebytesexpr Goes Here */

  ebytesexpr->exp_->accept(this);

}

void Skeleton::visitEbytestype(Ebytestype *ebytestype)
{
  /* Code For Ebytestype Goes Here */

  ebytestype->type_name_->accept(this);

}

void Skeleton::visitEarray(Earray *earray)
{
  /* Code For Earray Goes Here */

  earray->exp_1->accept(this);
  earray->exp_2->accept(this);

}

void Skeleton::visitEfunk(Efunk *efunk)
{
  /* Code For Efunk Goes Here */

  efunk->exp_->accept(this);

}

void Skeleton::visitEfunkpar(Efunkpar *efunkpar)
{
  /* Code For Efunkpar Goes Here */

  efunkpar->exp_->accept(this);
  efunkpar->listexp_->accept(this);

}

void Skeleton::visitEselect(Eselect *eselect)
{
  /* Code For Eselect Goes Here */

  eselect->exp_->accept(this);
  visitIdent(eselect->ident_);

}

void Skeleton::visitEpoint(Epoint *epoint)
{
  /* Code For Epoint Goes Here */

  epoint->exp_->accept(this);
  visitIdent(epoint->ident_);

}

void Skeleton::visitEpostinc(Epostinc *epostinc)
{
  /* Code For Epostinc Goes Here */

  epostinc->exp_->accept(this);

}

void Skeleton::visitEpostdec(Epostdec *epostdec)
{
  /* Code For Epostdec Goes Here */

  epostdec->exp_->accept(this);

}

void Skeleton::visitEvar(Evar *evar)
{
  /* Code For Evar Goes Here */

  visitIdent(evar->ident_);

}

void Skeleton::visitEconst(Econst *econst)
{
  /* Code For Econst Goes Here */

  econst->constant_->accept(this);

}

void Skeleton::visitEstring(Estring *estring)
{
  /* Code For Estring Goes Here */

  visitString(estring->string_);

}

void Skeleton::visitEfloat(Efloat *efloat)
{
  /* Code For Efloat Goes Here */

  visitDouble(efloat->double_);

}

void Skeleton::visitEchar(Echar *echar)
{
  /* Code For Echar Goes Here */

  visitChar(echar->char_);

}

void Skeleton::visitEunsigned(Eunsigned *eunsigned)
{
  /* Code For Eunsigned Goes Here */

  visitUnsigned(eunsigned->unsigned_);

}

void Skeleton::visitElong(Elong *elong)
{
  /* Code For Elong Goes Here */

  visitLong(elong->long_);

}

void Skeleton::visitEunsignlong(Eunsignlong *eunsignlong)
{
  /* Code For Eunsignlong Goes Here */

  visitUnsignedLong(eunsignlong->unsignedlong_);

}

void Skeleton::visitEhexadec(Ehexadec *ehexadec)
{
  /* Code For Ehexadec Goes Here */

  visitHexadecimal(ehexadec->hexadecimal_);

}

void Skeleton::visitEhexaunsign(Ehexaunsign *ehexaunsign)
{
  /* Code For Ehexaunsign Goes Here */

  visitHexUnsigned(ehexaunsign->hexunsigned_);

}

void Skeleton::visitEhexalong(Ehexalong *ehexalong)
{
  /* Code For Ehexalong Goes Here */

  visitHexLong(ehexalong->hexlong_);

}

void Skeleton::visitEhexaunslong(Ehexaunslong *ehexaunslong)
{
  /* Code For Ehexaunslong Goes Here */

  visitHexUnsLong(ehexaunslong->hexunslong_);

}

void Skeleton::visitEoctal(Eoctal *eoctal)
{
  /* Code For Eoctal Goes Here */

  visitOctal(eoctal->octal_);

}

void Skeleton::visitEoctalunsign(Eoctalunsign *eoctalunsign)
{
  /* Code For Eoctalunsign Goes Here */

  visitOctalUnsigned(eoctalunsign->octalunsigned_);

}

void Skeleton::visitEoctallong(Eoctallong *eoctallong)
{
  /* Code For Eoctallong Goes Here */

  visitOctalLong(eoctallong->octallong_);

}

void Skeleton::visitEoctalunslong(Eoctalunslong *eoctalunslong)
{
  /* Code For Eoctalunslong Goes Here */

  visitOctalUnsLong(eoctalunslong->octalunslong_);

}

void Skeleton::visitEcdouble(Ecdouble *ecdouble)
{
  /* Code For Ecdouble Goes Here */

  visitCDouble(ecdouble->cdouble_);

}

void Skeleton::visitEcfloat(Ecfloat *ecfloat)
{
  /* Code For Ecfloat Goes Here */

  visitCFloat(ecfloat->cfloat_);

}

void Skeleton::visitEclongdouble(Eclongdouble *eclongdouble)
{
  /* Code For Eclongdouble Goes Here */

  visitCLongDouble(eclongdouble->clongdouble_);

}

void Skeleton::visitEint(Eint *eint)
{
  /* Code For Eint Goes Here */

  visitInteger(eint->integer_);

}

void Skeleton::visitElonger(Elonger *elonger)
{
  /* Code For Elonger Goes Here */

  visitInteger(elonger->integer_);

}

void Skeleton::visitEdouble(Edouble *edouble)
{
  /* Code For Edouble Goes Here */

  visitDouble(edouble->double_);

}

void Skeleton::visitEspecial(Especial *especial)
{
  /* Code For Especial Goes Here */

  especial->exp_->accept(this);

}

void Skeleton::visitAddress(Address *address)
{
  /* Code For Address Goes Here */


}

void Skeleton::visitIndirection(Indirection *indirection)
{
  /* Code For Indirection Goes Here */


}

void Skeleton::visitPlus(Plus *plus)
{
  /* Code For Plus Goes Here */


}

void Skeleton::visitNegative(Negative *negative)
{
  /* Code For Negative Goes Here */


}

void Skeleton::visitComplement(Complement *complement)
{
  /* Code For Complement Goes Here */


}

void Skeleton::visitLogicalneg(Logicalneg *logicalneg)
{
  /* Code For Logicalneg Goes Here */


}

void Skeleton::visitAssign(Assign *assign)
{
  /* Code For Assign Goes Here */


}

void Skeleton::visitAssignMul(AssignMul *assignmul)
{
  /* Code For AssignMul Goes Here */


}

void Skeleton::visitAssignDiv(AssignDiv *assigndiv)
{
  /* Code For AssignDiv Goes Here */


}

void Skeleton::visitAssignMod(AssignMod *assignmod)
{
  /* Code For AssignMod Goes Here */


}

void Skeleton::visitAssignAdd(AssignAdd *assignadd)
{
  /* Code For AssignAdd Goes Here */


}

void Skeleton::visitAssignSub(AssignSub *assignsub)
{
  /* Code For AssignSub Goes Here */


}

void Skeleton::visitAssignLeft(AssignLeft *assignleft)
{
  /* Code For AssignLeft Goes Here */


}

void Skeleton::visitAssignRight(AssignRight *assignright)
{
  /* Code For AssignRight Goes Here */


}

void Skeleton::visitAssignAnd(AssignAnd *assignand)
{
  /* Code For AssignAnd Goes Here */


}

void Skeleton::visitAssignXor(AssignXor *assignxor)
{
  /* Code For AssignXor Goes Here */


}

void Skeleton::visitAssignOr(AssignOr *assignor)
{
  /* Code For AssignOr Goes Here */


}


void Skeleton::visitListExternal_declaration(ListExternal_declaration* listexternal_declaration)
{
  for (ListExternal_declaration::iterator i = listexternal_declaration->begin() ; i != listexternal_declaration->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListDec(ListDec* listdec)
{
  for (ListDec::iterator i = listdec->begin() ; i != listdec->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListDeclaration_specifier(ListDeclaration_specifier* listdeclaration_specifier)
{
  for (ListDeclaration_specifier::iterator i = listdeclaration_specifier->begin() ; i != listdeclaration_specifier->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListInit_declarator(ListInit_declarator* listinit_declarator)
{
  for (ListInit_declarator::iterator i = listinit_declarator->begin() ; i != listinit_declarator->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStruct_dec(ListStruct_dec* liststruct_dec)
{
  for (ListStruct_dec::iterator i = liststruct_dec->begin() ; i != liststruct_dec->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListSpec_qual(ListSpec_qual* listspec_qual)
{
  for (ListSpec_qual::iterator i = listspec_qual->begin() ; i != listspec_qual->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStruct_declarator(ListStruct_declarator* liststruct_declarator)
{
  for (ListStruct_declarator::iterator i = liststruct_declarator->begin() ; i != liststruct_declarator->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListEnumerator(ListEnumerator* listenumerator)
{
  for (ListEnumerator::iterator i = listenumerator->begin() ; i != listenumerator->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListType_qualifier(ListType_qualifier* listtype_qualifier)
{
  for (ListType_qualifier::iterator i = listtype_qualifier->begin() ; i != listtype_qualifier->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListIdent(ListIdent* listident)
{
  for (ListIdent::iterator i = listident->begin() ; i != listident->end() ; ++i)
  {
    visitIdent(*i) ;
  }
}

void Skeleton::visitListStm(ListStm* liststm)
{
  for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListExp(ListExp* listexp)
{
  for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void Skeleton::visitUnsigned(Unsigned x)
{
  /* Code for Unsigned Goes Here */
}

void Skeleton::visitLong(Long x)
{
  /* Code for Long Goes Here */
}

void Skeleton::visitUnsignedLong(UnsignedLong x)
{
  /* Code for UnsignedLong Goes Here */
}

void Skeleton::visitHexadecimal(Hexadecimal x)
{
  /* Code for Hexadecimal Goes Here */
}

void Skeleton::visitHexUnsigned(HexUnsigned x)
{
  /* Code for HexUnsigned Goes Here */
}

void Skeleton::visitHexLong(HexLong x)
{
  /* Code for HexLong Goes Here */
}

void Skeleton::visitHexUnsLong(HexUnsLong x)
{
  /* Code for HexUnsLong Goes Here */
}

void Skeleton::visitOctal(Octal x)
{
  /* Code for Octal Goes Here */
}

void Skeleton::visitOctalUnsigned(OctalUnsigned x)
{
  /* Code for OctalUnsigned Goes Here */
}

void Skeleton::visitOctalLong(OctalLong x)
{
  /* Code for OctalLong Goes Here */
}

void Skeleton::visitOctalUnsLong(OctalUnsLong x)
{
  /* Code for OctalUnsLong Goes Here */
}

void Skeleton::visitCDouble(CDouble x)
{
  /* Code for CDouble Goes Here */
}

void Skeleton::visitCFloat(CFloat x)
{
  /* Code for CFloat Goes Here */
}

void Skeleton::visitCLongDouble(CLongDouble x)
{
  /* Code for CLongDouble Goes Here */
}

void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}



