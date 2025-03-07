// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple loongarch32 -emit-llvm %s -o - \
// RUN:     | FileCheck %s -check-prefix=LA32
// RUN: %clang_cc1 -triple loongarch64 -emit-llvm %s -o - \
// RUN:     | FileCheck %s -check-prefix=LA64

#include <larchintrin.h>

// LA32-LABEL: @dbar(
// LA32-NEXT:  entry:
// LA32-NEXT:    call void @llvm.loongarch.dbar(i32 0)
// LA32-NEXT:    ret void
//
// LA64-LABEL: @dbar(
// LA64-NEXT:  entry:
// LA64-NEXT:    call void @llvm.loongarch.dbar(i32 0)
// LA64-NEXT:    ret void
//
void dbar() {
  return __builtin_loongarch_dbar(0);
}

