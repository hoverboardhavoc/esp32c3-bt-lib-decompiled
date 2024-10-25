/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_chm_update_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_chm_update_check(void)

{
  int iVar1;
  
  if (((*(ushort *)(p_lld_cca + 4) & 8) != 0) && (*(byte *)(p_lld_cca + 0x25) < 0x11)) {
    r_lld_cca_chm_restore();
  }
  if ((*(char *)(p_lld_cca + 0x26) == '\0') &&
     (iVar1 = memcmp((void *)(p_lld_cca + 0x20),*(void **)(p_lld_cca + 0x1c),5), iVar1 != 0)) {
    r_llm_ch_map_update_hack();
    return;
  }
  return;
}

