/*
 * Last changed at upstream commit bc9fd38197fb6a50e1b09791498782a1797e4757
 * https://github.com/espressif/esp32c3-bt-lib/commit/bc9fd38197fb6a50e1b09791498782a1797e4757
 * Upstream date: 2025-03-14 10:49:41 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(99e9a8dd)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_rpa_renew_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rpa_renew_evt_start_cbk(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (_lld_rpa_renew_env != 0) {
    iVar1 = r_lld_read_clock();
    _DAT_60031000 = _DAT_60031000 & 0xfcffffff | 0x3000000;
    uVar2 = (uint)rwip_prog_delay;
    *(code **)(param_1 + 0x2c) = r_lld_rpa_renew_instant_cbk;
    *(uint *)(param_1 + 0x28) = iVar1 + uVar2 & 0xfffffff;
    iVar1 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar1 + 0x28) & 0x100) != 0) {
      iVar1 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar1 + 0x2c) < 3) {
        r_ble_log_internal_x1(0x400d0001,*(undefined4 *)(param_1 + 0x28));
      }
    }
    r_sch_alarm_set(param_1 + 0x24);
    return;
  }
  r_assert_err(0,"lld.c",0x489);
  return;
}

