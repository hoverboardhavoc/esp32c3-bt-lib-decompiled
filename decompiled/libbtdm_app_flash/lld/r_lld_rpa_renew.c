/*
 * Last changed at upstream commit bc9fd38197fb6a50e1b09791498782a1797e4757
 * https://github.com/espressif/esp32c3-bt-lib/commit/bc9fd38197fb6a50e1b09791498782a1797e4757
 * Upstream date: 2025-03-14 10:49:41 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(99e9a8dd)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_rpa_renew
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rpa_renew(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar2 + 0x28) & 0x100) != 0) {
    iVar2 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar2 + 0x2c) < 3) {
      r_ble_log_internal_x1(0x400d0000,_lld_rpa_renew_env);
    }
  }
  if (_lld_rpa_renew_env == 0) {
    iVar2 = r_ke_malloc(0x30,0);
    _lld_rpa_renew_env = iVar2;
    if (iVar2 != 0) {
      *(code **)(iVar2 + 0x20) = r_lld_rpa_renew_evt_canceled_cbk;
      *(code **)(iVar2 + 0x18) = r_lld_rpa_renew_evt_start_cbk;
      uVar1 = rwip_priority;
      *(undefined4 *)(iVar2 + 0x1c) = 0;
      *(undefined1 *)(iVar2 + 0x17) = 0;
      *(undefined1 *)(iVar2 + 0x16) = uVar1;
      *(undefined4 *)(iVar2 + 0x10) = 5000;
      *(undefined2 *)(iVar2 + 0x14) = 0x60a1;
      uVar3 = r_lld_read_clock();
      *(undefined4 *)(iVar2 + 4) = uVar3;
      *(undefined4 *)(iVar2 + 8) = 0;
      iVar2 = r_sch_arb_insert(iVar2);
      if (iVar2 != 0) {
        r_assert_err(0,"lld.c",0x556);
        return;
      }
    }
    return;
  }
  r_assert_warn(0,0,"lld.c",0x55c);
  return;
}

