/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
                    /* WARNING: Could not recover jumptable at 0x00011b18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld.c",0x501,*(code **)(_r_plf_funcs_p + 8));
    return;
  }
  cVar1 = *(char *)(_p_lld_env + param_1 + 0x94);
  if (param_2 == 0) {
    if (cVar1 <= DAT_0001402d) goto _L391;
    cVar2 = -1;
  }
  else {
    if (DAT_0001402a <= cVar1) goto _L391;
    cVar2 = '\x01';
  }
  *(char *)(_p_lld_env + param_1 + 0x94) = cVar1 + cVar2;
_L391:
  *(undefined4 *)(iVar3 + param_1 * 4) = param_3;
  return;
}

