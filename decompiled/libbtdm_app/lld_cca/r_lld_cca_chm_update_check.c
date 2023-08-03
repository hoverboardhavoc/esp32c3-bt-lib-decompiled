/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
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
                    /* WARNING: Could not recover jumptable at 0x000106ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x4b4))();
    return;
  }
  return;
}

