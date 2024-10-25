/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld.o -> r_lld_channel_assess
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_channel_assess(uint param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = _p_lld_env;
  if (0x24 < param_1) {
                    /* WARNING: Could not recover jumptable at 0x00011af2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x4f3);
    return;
  }
  cVar1 = *(char *)(_p_lld_env + param_1 + 0x94);
  if (param_2 == 0) {
    if (cVar1 <= DAT_0001402d) goto _L394;
    cVar2 = -1;
  }
  else {
    if (DAT_0001402a <= cVar1) goto _L394;
    cVar2 = '\x01';
  }
  *(char *)(_p_lld_env + param_1 + 0x94) = cVar1 + cVar2;
_L394:
  *(undefined4 *)(param_1 * 4 + iVar3) = param_3;
  return;
}

