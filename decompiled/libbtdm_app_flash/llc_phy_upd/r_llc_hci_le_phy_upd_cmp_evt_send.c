/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_llc_hci_le_phy_upd_cmp_evt_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_hci_le_phy_upd_cmp_evt_send
               (undefined2 param_1,undefined1 param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  
  if (2 < (param_3 - 1U & 0xff)) {
    r_assert_param(param_3,0,"llc_phy_upd.c",0x35d);
  }
  if (2 < (param_4 - 1U & 0xff)) {
    r_assert_param(param_4,0,"llc_phy_upd.c",0x35e);
  }
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1104,param_1,0x3e,6);
  *puVar1 = 0xc;
  puVar1[4] = (char)param_3;
  puVar1[5] = (char)param_4;
  puVar1[1] = param_2;
  *(undefined2 *)(puVar1 + 2) = param_1;
  r_hci_send_2_host();
  return;
}

