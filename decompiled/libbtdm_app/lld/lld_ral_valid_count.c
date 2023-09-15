/*
 * Last changed at upstream commit e9ad3d704f1034310de8f747d503ea5443df6b67
 * https://github.com/espressif/esp32c3-bt-lib/commit/e9ad3d704f1034310de8f747d503ea5443df6b67
 * Upstream date: 2023-09-15 17:47:18 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(29996e0)
 * Source: libbtdm_app -> lld.o -> lld_ral_valid_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char lld_ral_valid_count(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  cVar1 = '\0';
  do {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    if (*(short *)(iVar3 + iVar2) < 0) {
      cVar1 = cVar1 + '\x01';
    }
    iVar2 = iVar2 + 0x34;
  } while (iVar2 != 0x208);
  return cVar1;
}

