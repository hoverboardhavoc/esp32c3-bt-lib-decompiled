/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_time_update_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_time_update_eco(int param_1)

{
  int iVar1;
  uint uVar2;
  
  r_lld_con_evt_time_update();
  iVar1 = r_sdk_config_get_opts();
  if (*(char *)(iVar1 + 0x15) == '\0') {
    iVar1 = *(int *)(&lld_con_env + param_1 * 4);
    uVar2 = (uint)*(ushort *)(iVar1 + 0x88);
    if ((uint)*(ushort *)(iVar1 + 0x88) < (uint)*(ushort *)(iVar1 + 0x8a)) {
      uVar2 = (uint)*(ushort *)(iVar1 + 0x8a);
    }
    uVar2 = (uVar2 + 0x96 + (uint)*(ushort *)(&fixed_tx_time + (uint)*(byte *)(iVar1 + 0x93) * 2)) *
            2 + (uint)_sdk_cfg_priv_opts;
    *(uint *)(iVar1 + 0x5c) = uVar2;
    *(uint *)(iVar1 + 0x10) = uVar2;
    r_sch_slice_per_add(4,*(undefined1 *)(iVar1 + 0x8e),*(undefined4 *)(iVar1 + 100),uVar2 & 0xffff,
                        0);
    return;
  }
  return;
}

