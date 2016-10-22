#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include<vector>
#include<string>


class Program;
class ListExternal_declaration;
class External_declaration;
class Function_def;
class Dec;
class ListDec;
class ListDeclaration_specifier;
class Declaration_specifier;
class ListInit_declarator;
class Init_declarator;
class Type_specifier;
class Storage_class_specifier;
class Type_qualifier;
class Struct_or_union_spec;
class Struct_or_union;
class ListStruct_dec;
class Struct_dec;
class ListSpec_qual;
class Spec_qual;
class ListStruct_declarator;
class Struct_declarator;
class Enum_specifier;
class ListEnumerator;
class Enumerator;
class Declarator;
class Direct_declarator;
class Pointer;
class ListType_qualifier;
class Parameter_type;
class Parameter_declarations;
class Parameter_declaration;
class ListIdent;
class Initializer;
class Initializers;
class Type_name;
class Abstract_declarator;
class Dir_abs_dec;
class Stm;
class Labeled_stm;
class Compound_stm;
class Expression_stm;
class Selection_stm;
class Iter_stm;
class Jump_stm;
class ListStm;
class Exp;
class Constant;
class Constant_expression;
class Unary_operator;
class Assignment_op;

typedef union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Program* program_;
  ListExternal_declaration* listexternal_declaration_;
  External_declaration* external_declaration_;
  Function_def* function_def_;
  Dec* dec_;
  ListDec* listdec_;
  ListDeclaration_specifier* listdeclaration_specifier_;
  Declaration_specifier* declaration_specifier_;
  ListInit_declarator* listinit_declarator_;
  Init_declarator* init_declarator_;
  Type_specifier* type_specifier_;
  Storage_class_specifier* storage_class_specifier_;
  Type_qualifier* type_qualifier_;
  Struct_or_union_spec* struct_or_union_spec_;
  Struct_or_union* struct_or_union_;
  ListStruct_dec* liststruct_dec_;
  Struct_dec* struct_dec_;
  ListSpec_qual* listspec_qual_;
  Spec_qual* spec_qual_;
  ListStruct_declarator* liststruct_declarator_;
  Struct_declarator* struct_declarator_;
  Enum_specifier* enum_specifier_;
  ListEnumerator* listenumerator_;
  Enumerator* enumerator_;
  Declarator* declarator_;
  Direct_declarator* direct_declarator_;
  Pointer* pointer_;
  ListType_qualifier* listtype_qualifier_;
  Parameter_type* parameter_type_;
  Parameter_declarations* parameter_declarations_;
  Parameter_declaration* parameter_declaration_;
  ListIdent* listident_;
  Initializer* initializer_;
  Initializers* initializers_;
  Type_name* type_name_;
  Abstract_declarator* abstract_declarator_;
  Dir_abs_dec* dir_abs_dec_;
  Stm* stm_;
  Labeled_stm* labeled_stm_;
  Compound_stm* compound_stm_;
  Expression_stm* expression_stm_;
  Selection_stm* selection_stm_;
  Iter_stm* iter_stm_;
  Jump_stm* jump_stm_;
  ListStm* liststm_;
  Exp* exp_;
  Constant* constant_;
  Constant_expression* constant_expression_;
  Unary_operator* unary_operator_;
  Assignment_op* assignment_op_;
} YYSTYPE;

Program* pProgram(FILE *inp);
Program* pProgram(const char *str);
Stm* pStm(FILE *inp);
Stm* pStm(const char *str);
Exp* pExp(FILE *inp);
Exp* pExp(const char *str);



#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _SYMB_21 280
#define _SYMB_22 281
#define _SYMB_23 282
#define _SYMB_24 283
#define _SYMB_25 284
#define _SYMB_26 285
#define _SYMB_27 286
#define _SYMB_28 287
#define _SYMB_29 288
#define _SYMB_30 289
#define _SYMB_31 290
#define _SYMB_32 291
#define _SYMB_33 292
#define _SYMB_34 293
#define _SYMB_35 294
#define _SYMB_36 295
#define _SYMB_37 296
#define _SYMB_38 297
#define _SYMB_39 298
#define _SYMB_40 299
#define _SYMB_41 300
#define _SYMB_42 301
#define _SYMB_43 302
#define _SYMB_44 303
#define _SYMB_45 304
#define _SYMB_46 305
#define _SYMB_47 306
#define _SYMB_48 307
#define _SYMB_49 308
#define _SYMB_50 309
#define _SYMB_51 310
#define _SYMB_52 311
#define _SYMB_53 312
#define _SYMB_54 313
#define _SYMB_55 314
#define _SYMB_56 315
#define _SYMB_57 316
#define _SYMB_58 317
#define _SYMB_59 318
#define _SYMB_60 319
#define _SYMB_61 320
#define _SYMB_62 321
#define _SYMB_63 322
#define _SYMB_64 323
#define _SYMB_65 324
#define _SYMB_66 325
#define _SYMB_67 326
#define _SYMB_68 327
#define _SYMB_69 328
#define _SYMB_70 329
#define _SYMB_71 330
#define _SYMB_72 331
#define _SYMB_73 332
#define _SYMB_74 333
#define _SYMB_75 334
#define _SYMB_76 335
#define _SYMB_77 336
#define _SYMB_78 337
#define _SYMB_79 338
#define _SYMB_80 339
#define _SYMB_81 340
#define _SYMB_82 341
#define _SYMB_83 342
#define _SYMB_84 343
#define _SYMB_85 344
#define _SYMB_86 345
#define _SYMB_87 346
#define _SYMB_88 347
#define _SYMB_89 348
#define _SYMB_90 349
#define _SYMB_91 350
#define _SYMB_92 351
#define _STRING_ 352
#define _CHAR_ 353
#define _INTEGER_ 354
#define _DOUBLE_ 355
#define _IDENT_ 356

extern YYSTYPE yylval;

#endif
