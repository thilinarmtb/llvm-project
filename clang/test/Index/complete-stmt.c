// Note: the run lines follow their respective tests, since line/column
// matter in this test.

typedef int Integer;
void f(int x) {
  if (x) {
  } 
}

// RUN: env CINDEXTEST_CODE_COMPLETE_PATTERNS=1 c-index-test -code-completion-at=%s:7:4 %s | FileCheck -check-prefix=CHECK-IF-ELSE %s
// CHECK-IF-ELSE: Pattern:{TypedText else}{HorizontalSpace  }{LeftBrace {}{VerticalSpace  }{Placeholder statements}{VerticalSpace  }{RightBrace }} (40)
// CHECK-IF-ELSE: Pattern:{TypedText else if}{HorizontalSpace  }{LeftParen (}{Placeholder expression}{RightParen )}{HorizontalSpace  }{LeftBrace {}{VerticalSpace  }{Placeholder statements}{VerticalSpace  }{RightBrace }} (40)

// RUN: c-index-test -code-completion-at=%s:7:4 %s | FileCheck -check-prefix=CHECK-IF-ELSE-SIMPLE %s
// CHECK-IF-ELSE-SIMPLE: Pattern:{TypedText else} (40)
// CHECK-IF-ELSE-SIMPLE: Pattern:{TypedText else if}{HorizontalSpace  }{LeftParen (}{Placeholder expression}{RightParen )} (40)

// RUN: c-index-test -code-completion-at=%s:6:1 %s | FileCheck -check-prefix=CHECK-STMT %s
// CHECK-STMT: Keyword:{TypedText _Nonnull} (50)
// CHECK-STMT: Keyword:{TypedText _Nullable} (50)
// CHECK-STMT: Keyword:{TypedText char} (50)
// CHECK-STMT: Keyword:{TypedText const} (50)
// CHECK-STMT: Keyword:{TypedText double} (50)
// CHECK-STMT: Keyword:{TypedText enum} (50)
// CHECK-STMT: FunctionDecl:{ResultType void}{TypedText f}{LeftParen (}{Placeholder int x}{RightParen )} (50)
// CHECK-STMT: TypedefDecl:{TypedText Integer} (50)
// CHECK-STMT: ParmDecl:{ResultType int}{TypedText x} (34)
