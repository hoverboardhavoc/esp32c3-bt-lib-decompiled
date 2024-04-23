/*
 * Last changed at upstream commit 9780fd66d97866977d972fb63319830f47f12785
 * https://github.com/espressif/esp32c3-bt-lib/commit/9780fd66d97866977d972fb63319830f47f12785
 * Upstream date: 2024-04-23 11:19:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a771b7c)
 * Source: libbtdm_app -> lld.o -> lld_ral_valid_count
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char lld_ral_valid_count(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = 0;
  cVar2 = '\0';
  do {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((*(short *)(iVar3 + iVar1) < 0) &&
       ((iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
        (*(ushort *)(iVar3 + iVar1) & 0x20) != 0 ||
        (iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
        (*(ushort *)(iVar3 + iVar1) & 2) != 0)))) {
      cVar2 = cVar2 + '\x01';
    }
    iVar1 = iVar1 + 0x34;
  } while (iVar1 != 0x208);
  return cVar2;
}

