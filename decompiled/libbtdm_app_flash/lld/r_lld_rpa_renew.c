/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  
  if (_lld_rpa_renew_env != 0) {
    r_assert_warn(0,0,"lld.c",0x547);
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
      r_assert_err(0,"lld.c",0x541);
      return;
    }
  }
  return;
}

