/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_scst_timeout_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_cca_scst_timeout_check(int param_1,int param_2)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(*(int *)(p_lld_cca + 0x28) + param_1 * 0xc);
  if ((char)*pbVar1 < '\0') {
    if ((*(ushort *)(p_lld_cca + 0xe) / 10 - (uint)*(ushort *)(p_lld_cca + 0x14)) * 2 <
        (param_2 - *(int *)(pbVar1 + 4) & 0xfffffffU)) {
      r_lld_cca_force_tx(1);
      *pbVar1 = *pbVar1 & 0x7f | 0x10;
    }
  }
  return;
}

