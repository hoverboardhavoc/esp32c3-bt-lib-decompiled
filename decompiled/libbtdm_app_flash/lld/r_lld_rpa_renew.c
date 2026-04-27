/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  
  r_ble_log_internal_x1(0x202800ce,_lld_rpa_renew_env);
  if (_lld_rpa_renew_env != 0) {
    r_assert_warn(0,0,"lld.c",0x564);
    return;
  }
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
      r_assert_err(0,"lld.c",0x55e);
      return;
    }
  }
  return;
}

