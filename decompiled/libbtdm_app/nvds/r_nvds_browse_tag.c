/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> nvds.o -> r_nvds_browse_tag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_nvds_browse_tag(uint param_1,byte *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 auStack_24 [2];
  
  auStack_24[0] = 4;
  do {
    uVar1 = auStack_24[0];
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x260))
                      (auStack_24[0],param_2,auStack_24,*(code **)(_r_modules_funcs_p + 0x260));
    if (iVar2 != 0) break;
  } while ((*param_2 != param_1) || ((param_2[1] & 5) != 4));
  *param_3 = uVar1;
  return;
}

