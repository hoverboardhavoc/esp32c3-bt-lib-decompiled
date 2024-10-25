/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm.o -> r_llm_dev_list_search
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_dev_list_search(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = _p_llm_env + uVar1 * 10;
    if ((((*(byte *)(iVar2 + 0x2d) & 1) != 0) && (*(byte *)(iVar2 + 0x2c) == param_2)) &&
       (iVar2 = (*(code *)*_r_modules_funcs_p)
                          (_p_llm_env + uVar1 * 10 + 0x24,param_1,(code *)*_r_modules_funcs_p),
       iVar2 != 0)) break;
    uVar1 = uVar1 + 1;
    if (uVar1 == 0xc) {
      return 0xc;
    }
  }
  return uVar1 & 0xff;
}

