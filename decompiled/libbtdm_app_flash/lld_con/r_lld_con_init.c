/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_init(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != 1) {
    if (param_1 != 2) {
      return;
    }
    iVar2 = r_sdk_config_get_opts();
    for (uVar1 = (int)((*(byte *)(iVar2 + 0xd) - 1) * 0x1000000) >> 0x18; -1 < (char)uVar1;
        uVar1 = uVar1 - 1) {
      if (*(int *)(&lld_con_env + uVar1 * 4) != 0) {
        r_lld_con_cleanup(uVar1 & 0xff,0,0x16);
      }
    }
  }
  memset(&lld_con_env,0,0x28);
  return;
}

