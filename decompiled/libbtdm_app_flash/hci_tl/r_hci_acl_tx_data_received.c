/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_acl_tx_data_received
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_acl_tx_data_received(uint param_1,int param_2,undefined2 param_3)

{
  byte *pbVar1;
  undefined2 *puVar2;
  
  r_ble_log_internal_x1(0x20270223,param_2 << 0x10 | param_1);
  if (DAT_0001201f != '\0') {
    DAT_0001201f = 0;
    return;
  }
  pbVar1 = (byte *)r_sdk_config_get_hl_derived_opts();
  if ((param_1 & 0xfff) < (uint)*pbVar1) {
    puVar2 = (undefined2 *)r_ke_msg_alloc(0x1106,(param_1 & 0xff) << 8 | 1,0,0xc);
    *puVar2 = (short)param_1;
    puVar2[1] = (short)param_2;
    if (param_2 == 0) {
      param_3 = 0;
    }
    puVar2[2] = param_3;
    r_ke_msg_send();
    return;
  }
  r_assert_param(param_2,param_1,"hci_tl.c",0x777);
  return;
}

