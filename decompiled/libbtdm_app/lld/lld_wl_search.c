/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  int iVar1;
  void *__src;
  uint uVar2;
  int iVar3;
  undefined1 auStack_38 [12];
  
  uVar2 = 0;
  do {
    iVar3 = uVar2 * 8;
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
    if (*(short *)(iVar1 + iVar3) < 0) {
      __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                (iVar3 + 0xc02U & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
      memcpy(auStack_38,__src,6);
      iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc00,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((((param_2 ^ *(ushort *)(iVar3 + iVar1) >> 0xe) & 1) == 0) &&
         (iVar1 = (*(code *)*_r_modules_funcs_p)(auStack_38,param_1,(code *)*_r_modules_funcs_p),
         iVar1 != 0)) {
        return uVar2 & 0xff;
      }
    }
    uVar2 = uVar2 + 1;
    if (uVar2 == 0xc) {
      return 0xc;
    }
  } while( true );
}

