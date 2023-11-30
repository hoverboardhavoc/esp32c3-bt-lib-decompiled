/*
 * Last changed at upstream commit a075a8fde411bdd92973051edf2cd234601b259c
 * https://github.com/espressif/esp32c3-bt-lib/commit/a075a8fde411bdd92973051edf2cd234601b259c
 * Upstream date: 2023-11-30 21:15:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(70ab55f)
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
  int iVar3;
  void *__src;
  undefined1 auStack_38 [16];
  
  uVar1 = 0;
  do {
    iVar2 = uVar1 * 8;
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
    if (*(short *)(iVar3 + iVar2) < 0) {
      __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                (iVar2 + 0xc02U & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(auStack_38,__src,6);
      iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
      if (((param_2 & 1) == (*(ushort *)(iVar3 + iVar2) >> 0xe & 1)) &&
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

