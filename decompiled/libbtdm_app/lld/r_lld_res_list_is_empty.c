/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> lld.o -> r_lld_res_list_is_empty
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool r_lld_res_list_is_empty(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = 0;
  do {
    uVar2 = uVar1 & 0xff;
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    if (*(short *)(iVar3 + uVar1 * 0x34) < 0) goto _L498;
    uVar1 = uVar1 + 1;
  } while (uVar1 != 10);
  uVar2 = 10;
_L498:
  return uVar2 == 10;
}

