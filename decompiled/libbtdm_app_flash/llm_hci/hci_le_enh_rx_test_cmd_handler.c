/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_enh_rx_test_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_le_enh_rx_test_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uStack_18;
  byte bStack_17;
  byte bStack_14;
  
  iVar1 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar1 + 0x1f) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  iVar1 = r_llm_no_activity();
  uVar2 = 0xc;
  if ((((iVar1 != 0) && (uVar2 = 0x12, *param_1 < 0x28)) && ((byte)(param_1[1] - 1) < 3)) &&
     (param_1[2] < 2)) {
    rw_rf_le_enter_test_mode(0x12);
    bStack_17 = *param_1;
    uStack_18 = 0;
    bStack_14 = param_1[1];
    uVar2 = r_lld_test_start(&uStack_18);
  }
  r_llm_cmd_cmp_send(param_2,uVar2);
  return 0;
}

