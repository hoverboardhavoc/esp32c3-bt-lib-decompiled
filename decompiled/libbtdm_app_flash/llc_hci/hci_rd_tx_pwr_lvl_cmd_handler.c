/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_hci.o -> hci_rd_tx_pwr_lvl_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_rd_tx_pwr_lvl_cmd_handler(uint param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,*param_2,0xc2d,6);
  iVar3 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    *puVar2 = 0;
    if (*(char *)(param_2 + 1) == '\0') {
      uVar1 = r_lld_con_current_tx_power_get(param_1,1);
    }
    else {
      if (*(char *)(param_2 + 1) != '\x01') {
        uVar1 = 0x12;
        goto _L13;
      }
      uVar1 = (*_r_ble_util_buf_rx_free)(DAT_00011045,1,_r_ble_util_buf_rx_free);
    }
    puVar2[4] = uVar1;
  }
  else {
    uVar1 = 0xc;
_L13:
    *puVar2 = uVar1;
    puVar2[4] = 0;
  }
  *(undefined2 *)(puVar2 + 2) = *param_2;
  r_hci_send_2_host(puVar2);
  return 0;
}

