/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_count_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char r_lld_con_count_get(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = '\0';
  for (iVar2 = 0; iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
      iVar2 < (int)(uint)*(byte *)(iVar3 + 0xd); iVar2 = iVar2 + 1) {
    if (*(int *)(&lld_con_env + iVar2 * 4) != 0) {
      cVar1 = cVar1 + '\x01';
    }
  }
  return cVar1;
}

