/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
    r_assert_param(param_3,0,"llc_phy_upd.c",0x36a);
  }
  if (2 < (param_4 - 1U & 0xff)) {
    r_assert_param(param_4,0,"llc_phy_upd.c",0x36b);
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

