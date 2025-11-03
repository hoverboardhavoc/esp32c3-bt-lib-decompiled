/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_channel_assess
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
    r_assert_err(0,"lld.c",0x502);
    return;
  }
  cVar1 = *(char *)(_p_lld_env + param_1 + 0x94);
  if (param_2 == 0) {
    if (cVar1 <= DAT_00014059) goto _L327;
    cVar2 = -1;
  }
  else {
    if (DAT_00014056 <= cVar1) goto _L327;
    cVar2 = '\x01';
  }
  *(char *)(_p_lld_env + param_1 + 0x94) = cVar1 + cVar2;
_L327:
  *(undefined4 *)(iVar3 + param_1 * 4) = param_3;
  return;
}

