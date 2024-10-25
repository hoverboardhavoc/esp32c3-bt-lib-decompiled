/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld.o -> lld_le_pkt_err_en
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_le_pkt_err_en(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  _LANCHOR1 = (undefined1)param_1;
  _DAT_60031000 = (param_1 ^ 1) << 9 | _DAT_60031000 & 0xfffffdff;
  for (uVar1 = 0; iVar2 = r_sdk_config_get_opts(), uVar1 < *(byte *)(iVar2 + 0xd);
      uVar1 = uVar1 + 1 & 0xff) {
    (&lld_le_pkt_env)[uVar1] = 0;
  }
  return 0;
}

