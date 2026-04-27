/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  uint uVar4;
  
  iVar1 = *(int *)(&lld_con_env + param_1 * 4);
  r_lld_con_evt_time_update();
  iVar2 = r_sdk_config_get_opts();
  if (*(char *)(iVar2 + 0x15) == '\0') {
    uVar4 = (uint)*(byte *)(iVar1 + 0x93);
    if (uVar4 == 3) {
      uVar4 = 2;
    }
    uVar3 = (uint)*(ushort *)(iVar1 + 0x88);
    if ((uint)*(ushort *)(iVar1 + 0x88) < (uint)*(ushort *)(iVar1 + 0x8a)) {
      uVar3 = (uint)*(ushort *)(iVar1 + 0x8a);
    }
    uVar4 = (uVar3 + 0x96 + (uint)*(ushort *)(&fixed_tx_time + uVar4 * 2)) * 2 +
            (uint)_sdk_cfg_priv_opts;
    if (uVar4 < 0x9c4) {
      uVar4 = 0x9c4;
    }
    *(uint *)(iVar1 + 0x5c) = uVar4;
    *(uint *)(iVar1 + 0x10) = uVar4;
    r_sch_slice_per_add(4,*(undefined1 *)(iVar1 + 0x8e),*(undefined4 *)(iVar1 + 100),uVar4 & 0xffff,
                        0);
  }
  r_ble_log_internal_x2(0x400300fa,*(undefined4 *)(iVar1 + 0x5c),param_1);
  return;
}

