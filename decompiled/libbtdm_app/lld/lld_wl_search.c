/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld.o -> lld_wl_search
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint lld_wl_search(undefined4 param_1,ushort param_2)

{
  uint uVar1;
  int iVar2;
  void *__src;
  int iVar3;
  undefined1 auStack_38 [20];
  
  uVar1 = 0;
  do {
    iVar3 = uVar1 * 8;
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
    if (*(short *)(iVar2 + iVar3) < 0) {
      __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                (iVar3 + 0xc02U & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(auStack_38,__src,6);
      iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((((param_2 ^ *(ushort *)(iVar2 + iVar3) >> 0xe) & 1) == 0) &&
         (iVar2 = (*(code *)*_r_modules_funcs_p)(auStack_38,param_1,(code *)*_r_modules_funcs_p),
         iVar2 != 0)) {
        return uVar1 & 0xff;
      }
    }
    uVar1 = uVar1 + 1;
    if (uVar1 == 0xc) {
      return 0xc;
    }
  } while( true );
}

