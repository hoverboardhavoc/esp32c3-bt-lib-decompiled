/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  r_lld_con_evt_time_update();
  iVar2 = r_sdk_config_get_opts();
  if (*(char *)(iVar2 + 0x15) == '\0') {
    uVar3 = (uint)*(ushort *)(iVar1 + 0x88);
    if ((uint)*(ushort *)(iVar1 + 0x88) < (uint)*(ushort *)(iVar1 + 0x8a)) {
      uVar3 = (uint)*(ushort *)(iVar1 + 0x8a);
    }
    uVar3 = (uVar3 + 0x96 + (uint)*(ushort *)(&fixed_tx_time + (uint)*(byte *)(iVar1 + 0x93) * 2)) *
            2 + (uint)_sdk_cfg_priv_opts;
    if (uVar3 < 0x9c4) {
      uVar3 = 0x9c4;
    }
    *(uint *)(iVar1 + 0x5c) = uVar3;
    *(uint *)(iVar1 + 0x10) = uVar3;
    r_sch_slice_per_add(4,*(undefined1 *)(iVar1 + 0x8e),*(undefined4 *)(iVar1 + 100),uVar3 & 0xffff,
                        0);
  }
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 0x20) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 3) {
      r_ble_log_internal_x2(0x40030008,param_1,*(undefined4 *)(iVar1 + 0x5c));
      return;
    }
  }
  return;
}

