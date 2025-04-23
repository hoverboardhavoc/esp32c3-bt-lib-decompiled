/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_chm_update_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_chm_update_check(void)

{
  int iVar1;
  
  if (((*(ushort *)(p_lld_cca + 4) & 8) != 0) && (*(byte *)(p_lld_cca + 0x25) < 0x11)) {
    (**(code **)(_r_ip_funcs_p + 0x99c))(*(code **)(_r_ip_funcs_p + 0x99c));
  }
  if ((*(char *)(p_lld_cca + 0x26) == '\0') &&
     (iVar1 = memcmp((void *)(p_lld_cca + 0x20),*(void **)(p_lld_cca + 0x1c),5), iVar1 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x000106d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x4b4))(*(code **)(_r_ip_funcs_p + 0x4b4));
    return;
  }
  return;
}

